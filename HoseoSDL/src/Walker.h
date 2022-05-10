#pragma once

#include "InputHandler.h"
#include "Vector2D.h"
#include "Game.h"

#include "Vehicle.h"
#include <vector>
#include "Target.h"
#include <main.h>

class Walker 
{
public:
  Walker();
  void draw(SDL_Renderer* renderer);
  void update();
  //void mousemove();

private:
  std::vector<Vehicle*> m_Vehicle;
  std::vector<Target*> m_target;
  //Target* m_target;

  //Vector2D* m_mousePos;
  //Vector2D* target;

  Vector2D* steering;
};