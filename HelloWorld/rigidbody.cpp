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
	int playerDirection = North;
}

void Ship::Draw()
{
	Play::DrawSpriteRotated(idS, position, 1, rotation, 1.0f, 1.0f);

}

void Ship::HandleInput(float elapsedTime)
{
	//every direction
	//if (Play::KeyDown(VK_UP) && Play::KeyDown(VK_RIGHT)&& Play::KeyDown(VK_DOWN)&&Play::KeyDown(VK_LEFT)) {
	//	//set velocity to 0

	//}
	//three directions
	
	//two directions
	if (Play::KeyDown(VK_UP) && Play::KeyDown(VK_RIGHT)) {
		playerDirection = NorthEast;
	}

	//one direction
	if (Play::KeyDown(VK_UP))
	{
		playerDirection = North;
	}



	if (Play::KeyDown(VK_SPACE))//thrust
	{
		//thrust = thrust * elapsedTime;
	}
	
}

void Ship::HandleMovement(float elapsedTime)
{
	if (playerDirection == North)
	{
		position = { position.x - 1, position.y };

	}
}