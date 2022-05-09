#define WIDTH (600)
#define HEIGHT (400)

#include "Vehicle.h"
#include <math.h>

Vehicle::Vehicle(int x, int y) : maxSpeed(4), maxForce(0.25f), r(16)
{
  m_pos = new Vector2D(x, y);
  m_vel = new Vector2D(0, 0);
  m_acc = new Vector2D(0, 0);
  m_force = new Vector2D(0, 0);
  //radian = new Vector2D(0, 0);
  rdi1 = new Vector2D(0, 0);
  rdi2 = new Vector2D(0, 0);
  rdi3 = new Vector2D(0, 0);
  //m_mousePos = new Vector2D(0, 0);
}

void Vehicle::update() 
{
  //mousemove();
  edges();
  
  *m_vel += *m_acc;
  m_vel->limit(maxSpeed);
  *m_pos += *m_vel;
  *m_acc *= 0;
  
  radian = atan2(m_vel->getY(), m_vel->getX());
  *rdi1 = goradian(-r, -r/2, radian);
  *rdi2 = goradian(-r, r/2, radian);
  *rdi3 = goradian(r, 0, radian);
}

Vector2D Vehicle::goradian(float x, float y, float radian)
{
  // Vector2D* rota = new Vector2D(0, 0);
  
  // rota->setX(cos(radian) * x - sin(radian) * y);
  // rota->setY(sin(radian) * x + cos(radian) * y);

  // return *rota;

  Vector2D rota(0, 0);
  
  rota.setX(cos(radian) * x - sin(radian) * y);
  rota.setY(sin(radian) * x + cos(radian) * y);

  return rota;
}

// void Vehicle::mousemove()
// {
//   m_mousePos = TheInputHandler::Instance()->getMousePosition();

//   *m_pos = *m_mousePos;
// }

void Vehicle::draw(SDL_Renderer* renderer)
{
 filledTrigonRGBA(renderer,  rdi1->getX() + m_pos->getX(), rdi1->getY() + m_pos->getY(), rdi2->getX() + m_pos->getX(), rdi2->getY() + m_pos->getY(),rdi3->getX() + m_pos->getX(), rdi3->getY() + m_pos->getY(), 255, 255, 255, 255);
}

void Vehicle::seek(Vector2D* target)
{
  *m_force = *target - *m_pos;
  m_force->normalize();
  *m_force *= maxSpeed;

  m_force->limit(maxForce);
  applyForce(m_force);
}

void Vehicle::applyForce(Vector2D* force)
{
  *m_acc += *force;
}

void Vehicle::edges()
{
  if(m_pos->getX() > WIDTH + r)
  {
    m_pos->setX(-r);
  }
  else if(m_pos->getX() < -r )
  {
    m_pos->setX(WIDTH + r);
  }

  if(m_pos->getY() > HEIGHT + r)
  {
    m_pos->setY(-r);
  }
  else if(m_pos->getY() < -r )
  {
    m_pos->setY(HEIGHT + r);
  }
}