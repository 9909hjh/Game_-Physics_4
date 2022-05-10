#include "Walker.h"
#include <random>
#define WIDTH (600)
#define HEIGHT (400)
// 시드값을 얻기 위한 random_device 생성.
std::random_device rd;

// random_device 를 통해 난수 생성 엔진을 초기화 한다.
std::mt19937 gen(rd());

// 0 부터 3까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
std::uniform_int_distribution<int> dis(0, 3);

Walker::Walker() 
{
  m_Vehicle.push_back(new Vehicle(100, 100));
  //m_Vehicle.push_back(new Vehicle(50, 100));
 // m_target = new Target(WIDTH- 50, HEIGHT - 50);
  m_target.push_back(new Target(WIDTH - 50, HEIGHT - 50));
  steering = new Vector2D(0, 0);
}

void Walker::update() 
{
  for(int i = 0; i != m_Vehicle.size(); i++)
    {
      m_Vehicle[i]->update();
      //m_Vehicle[i]->pursue(m_target); // 문제 부분.
      *steering = m_Vehicle[i]->pursue(m_target[i]);
      m_Vehicle[i]->applyForce(steering);

      m_target[i]->applyForce(steering);
      m_target[i]->update();
      //m_target[i]->update();
    }
}

void Walker::draw(SDL_Renderer* renderer)
{
  
  for(int i = 0; i != m_Vehicle.size(); i++)
    {
      m_Vehicle[i]->draw(renderer);
      //m_Vehicle[i]->draw2(renderer);
      //m_Vehicle[i]->seek(target); // 문제 부분.
      m_target[i]->draw(renderer);
    }
}
