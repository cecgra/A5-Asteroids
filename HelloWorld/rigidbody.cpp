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
	rotationalSpeed = Play::RandomRollRange(0, 5);

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

void Ship::HandleInput(float elapsedTime)
{
	
	int thrust = 10; //boost veriable
	if (Play::KeyDown(VK_UP))//north
	{		
		velocity.y -= acceleration * elapsedTime;

		if (Play::KeyDown(VK_SPACE))//boost up
		{
			velocity.y -= thrust;
		}
	}

	if (Play::KeyDown(VK_RIGHT))//east
	{
		velocity.x += acceleration * elapsedTime;

		if (Play::KeyDown(VK_SPACE))//boost right
		{
			velocity.x += thrust;
		}
	}

	if (Play::KeyDown(VK_DOWN))//south
	{
		velocity.y += acceleration * elapsedTime;

		if (Play::KeyDown(VK_SPACE))//boost down
		{
			velocity.y += thrust;
		}
	}

	if (Play::KeyDown(VK_LEFT))//west
	{
		velocity.x -= acceleration * elapsedTime;

		if (Play::KeyDown(VK_SPACE))//boost left
		{
			velocity.x -= thrust;
		}
	}
	
}

void Ship::ShipUpdate(float elapsedTime)
{
	//caps speed
	int speedCap = 500;
	if (velocity.x > speedCap)
	{
		velocity.x = speedCap;
	}
	if (velocity.x < -speedCap) 
	{
		velocity.x = -speedCap;
	}
	if (velocity.y > speedCap)
	{
		velocity.y = speedCap;
	}if (velocity.y < -speedCap)
	{
		velocity.y = -speedCap;
	}

	//updating position of ship
	
	position.x += velocity.x * elapsedTime;
	position.y += velocity.y * elapsedTime;

	if (position.x < 0)//left edge
	{
		position.x = DISPLAY_WIDTH;
	}

	if (position.x > DISPLAY_WIDTH)//right edge
	{
		position.x = 0;
	}

	if (position.y < 0)//top edge
	{
		position.y = DISPLAY_HEIGHT;
	}

	if (position.y > DISPLAY_HEIGHT)//bottom edge
	{
		position.y = 0;
	}
}
