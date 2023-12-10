#pragma once
#include "play.h"
#include <string>
using namespace std;

const int DISPLAY_WIDTH = 640;
const int DISPLAY_HEIGHT = 640;
const int DISPLAY_SCALE = 1;



class Rigidbody //base logic for asteroids and ship
{
public:
	Point2D position;
	Vector2D velocity;
	const float acceleration=150.0f;
	float rotation;
	int radius;//in radians
	char* id;

	void Draw();

};

class Asteroid :protected Rigidbody
{
public:
	float scale;
	int rotationalSpeed;
	const char* idA = "asteroid";

	Asteroid();
	void Draw();
	void UpdateAsteroid(float elapsedTime);

};

class Ship : protected Rigidbody
{
public:
	int thrust;
	const char* idS = "ship";
	

	Ship();
	void Draw();
	void HandleInput(float elapsedTime);
	void ShipUpdate(float elapsedTime);
	void WallCollision();
};