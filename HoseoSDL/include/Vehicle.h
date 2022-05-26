#pragma once
#include <main.h>

#include "Vector2D.h"
#include "Game.h"
#include "InputHandler.h"

//#include "usr/include/SDL2/SDL2_gfxPrimitives.h"
//#include "usr/include/SDL2/SDL.h"

//enum Deceleration { slow = 3, normal = 2, fast = 1 };

class Vehicle
{
public:
	Vehicle(int x, int y);
	void draw(SDL_Renderer* renderer);
	void update();

	Vector2D seek(Vector2D* target, bool arrival);
	//Vector2D pursue(Vehicle* m_vehicle);
	void applyForce(Vector2D* force);
	Vector2D goradian(float x, float y, float radian);
	Vector2D arrive(Vector2D* target);
	
	//void mousemove();
	void edges();

	Vector2D getPos() { return *m_pos; }
	float getR() { return r; }

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
	Vector2D* m_target;
	Vector2D* m_prediction;
	Vector2D* DesiredVelocity;
	Vector2D* steer;


	int maxSpeed;
	float maxForce;
	int r;
	float desiredSpeed;
};