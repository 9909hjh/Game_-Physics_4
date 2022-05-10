#pragma once

#include "Vector2D.h"
#include "Game.h"
#include "InputHandler.h"
#include <main.h>

class Vehicle 
{
public:
	//Vehicle() {}
  Vehicle(int x, int y);
  void draw(SDL_Renderer* renderer);
  void update();
  
  Vector2D seek(Vector2D* target);
  void applyForce(Vector2D* force);
  Vector2D goradian(float x, float y, float radian);
  
  // pursue, Evade 조정행동 과제.
  Vector2D pursue(Vehicle* m_vehicle);


  void edges();


protected:
  Vector2D* m_pos;
  Vector2D* m_vel;
  Vector2D* m_acc;
  Vector2D* m_force;

  float radian = 0;
  Vector2D* rdi1;
  Vector2D* rdi2;
  Vector2D* rdi3;

  Vector2D* m_target;
  Vector2D* veh;
  Vector2D* m_prediction;
  //Vehicle* vehicle;
  //Vector2D p_target;
  //Vector2D* v3;
  float v3;
  float m_v3;
  //Vehicle* m_vehicle;

  int maxSpeed;
  float maxForce;
  int r;

  float m_rotate = 0;
  const float PI = 3.14f;
};