#pragma once
#include <main.h>

#include "Vector2D.h"
#include "Game.h"
#include "InputHandler.h"

//#include "usr/include/SDL2/SDL2_gfxPrimitives.h"
//#include "usr/include/SDL2/SDL.h"


class Vehicle
{
public:
	Vehicle(int x, int y);
	void draw(SDL_Renderer* renderer);
	void update();

	void seek(Vector2D* target);
	void applyForce(Vector2D* force);
	Vector2D goradian(float x, float y, float radian);
	//void mousemove();

	void edges();


private:
	Vector2D* m_pos;
	Vector2D* m_vel;
	Vector2D* m_acc;
	Vector2D* m_force;

	float radian = 0;
	Vector2D* rdi1;
	Vector2D* rdi2;
	Vector2D* rdi3;
	//Vector2D* m_mousePos;

	int maxSpeed;
	float maxForce;
	int r;

	//float angle;
	float m_rotate = 0;
	const float PI = 3.14f;
};