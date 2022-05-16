#pragma once

#include "InputHandler.h"
#include "Vector2D.h"
#include "Game.h"

#include "Vehicle.h"
#include <vector>
#include "Target.h"
#include <main.h>
#include <iostream>

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
  //Target* T_target;
  //Vehicle* V_vehicle;
  //Vector2D* m_mousePos;
  //Vector2D* target;
  float f_Veh;
  float f_Tar;
  float d;
  float f;
  Vector2D* steering;
  Target* T;
};