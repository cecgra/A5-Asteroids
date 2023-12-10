#pragma once
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
	int acceleration;
	float rotation;
	int radius;//in radians
	char* id;

	void Draw();
	void Update(float elapsedTime);

};

class Asteroid :private  Rigidbody
{
public:
	int scale;
	int rotationalSpeed;


	Asteroid();
	void Draw();
	void UpdateAsteroid(float elapsedTime);


};

class Ship : private Rigidbody
{
public:
	Ship();
	void Draw();
};