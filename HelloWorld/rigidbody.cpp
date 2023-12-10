#include "rigidbody.h"



void Rigidbody::Draw()
{
	Play::DrawSpriteRotated(id, position, 1, rotation, 1.0f, 1.0f);
}


Asteroid::Asteroid()
{
	//asteroid constructor

	velocity = { Play::RandomRollRange(1,20), Play::RandomRollRange(1,20) };
	position = { 0,0 };

	scale = Play::RandomRollRange(0,3);
	rotationalSpeed = Play::RandomRollRange(0, 10);	
}

void Asteroid::Draw()
{
	Play::DrawSpriteRotated("asteroid", position, 1, rotation, scale, 1.0f);
}

void Asteroid::UpdateAsteroid(float elapsedTime)
{
	rotation += rotationalSpeed * elapsedTime;
	position.x += velocity.x * elapsedTime;
	position.y += velocity.y * elapsedTime;
}
