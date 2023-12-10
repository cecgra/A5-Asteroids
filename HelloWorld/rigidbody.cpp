#include "rigidbody.h"

void Rigidbody::Draw()
{
	Play::DrawSpriteRotated(id, position, 1, rotation, 1.0f, 1.0f);
	
}

Asteroid::Asteroid()
{
	velocity = { Play::RandomRollRange(5,50), Play::RandomRollRange(5,50) };
	position = { 0,0 };

	scale = Play::RandomRollRange(0, 3);
	rotationalSpeed = Play::RandomRollRange(0, 10);

}

void Asteroid::Draw()
{
	Play::DrawSpriteRotated(idA, position, 1, rotation, scale, 1.0f);

}

void Asteroid::UpdateAsteroid(float elapsedTime)
{
	rotation += rotationalSpeed * elapsedTime;
	position.x += velocity.x * elapsedTime;
	position.y += velocity.y * elapsedTime;

}

Ship::Ship()
{
	position = { DISPLAY_HEIGHT / 2, DISPLAY_WIDTH / 2 };
}

void Ship::Draw()
{
	Play::DrawSpriteRotated(idS, position, 1, rotation, 1.0f, 1.0f);

}

void Ship::UpdateShip(float elapsedTime)
{
	if (KeyDown(VK_UP))
	{

	}



	if (Play::KeyDown(VK_SPACE))
	{
		thrust = thrust * elapsedTime;
	}
	position.x += thrust;
}