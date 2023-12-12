#pragma once
#include "play.h"
#include <string>
#include <vector>

const int DISPLAY_WIDTH = 640;
const int DISPLAY_HEIGHT = 640;
const int DISPLAY_SCALE = 1;


class Rigidbody //base logic for asteroids and ship
{
public:
	Point2D position;
	Vector2D velocity;
	const float acceleration=200.0f;
	float rotation;
	int radius;
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

	static std::vector<Asteroid> asteroids;
	static void CreateAsteroids(int numAsteroids);
	void UpdateAsteroidPosition();

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
	
};

