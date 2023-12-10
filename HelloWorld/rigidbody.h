#pragma once
#define PLAY_USING_GAMEOBJECT_MANAGER
#define PLAY_IMPLEMENTATION
#include "play.h"
#include <string>
using namespace std;

const int DISPLAY_WIDTH = 640;
const int DISPLAY_HEIGHT = 640;
const int DISPLAY_SCALE = 1;

enum direction
{
	North,
	NorthEast,
	East,
	SouthEast,
	South,
	SouthWest,
	West,
	NorthWest
};

class Rigidbody //base logic for asteroids and ship
{
public:
	Point2D position;
	Vector2D velocity;
	int acceleration;
	float rotation;
	int radius;//in radians
	char* id;

	void Draw();

};

class Asteroid :private Rigidbody
{
public:
	int scale;
	int rotationalSpeed;
	const char* idA = "asteroid";

	Asteroid();
	void Draw();
	void UpdateAsteroid(float elapsedTime);

};

class Ship : private Rigidbody
{
public:
	int thrust;
	const char* idS = "ship";
	direction D;
	int PlayerDirection;

	Ship();
	void Draw();
	void HandleInput(float elapsedTime);
	void HandleMovement(float elapsedTime);

};