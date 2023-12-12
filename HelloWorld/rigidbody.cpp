#include "rigidbody.h"
using namespace std;

void Rigidbody::Draw()
{
	Play::DrawSpriteRotated(id, position, 1, rotation, 1.0f, 1.0f);
	
}

Asteroid::Asteroid()
{
	int velocityDirection = Play::RandomRollRange(0, 3);
	if (velocityDirection==0) //x pos y pos
	{
		velocity = { Play::RandomRollRange(10,100), Play::RandomRollRange(10,100) };
	}
	else if(velocityDirection == 1)//x pos y neg
	{
		velocity = { Play::RandomRollRange(10,100), Play::RandomRollRange(-10,-100) };
	}
	else if(velocityDirection == 2)//x neg y pos
	{
		velocity = { Play::RandomRollRange(-10,-100), Play::RandomRollRange(10,100) };

	}
	else if(velocityDirection == 3)//x neg y neg
	{ 
		velocity = { Play::RandomRollRange(-10,-100), Play::RandomRollRange(-10,-100) };
	
	}
	
		


	scale = Play::RandomRollRange(1, 3);
	rotationalSpeed = Play::RandomRollRange(1, 500);
	UpdateAsteroidPosition();
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
	radius = 20*scale;
	//if asteroid has left the screen, respawn it at a new location
	if (position.x<0-radius || position.x >DISPLAY_WIDTH+radius 
	|| position.y<0-radius || position.y>DISPLAY_HEIGHT+radius)
	{
		UpdateAsteroidPosition();
		
	}
}

void Asteroid::UpdateAsteroidPosition() {
	//spawn edge
	int edge = Play::RandomRollRange(0, 3);
	if (edge == 0)//top edge
	{
		position = { Play::RandomRollRange(0, DISPLAY_WIDTH), 0-radius };
	}
	else if (edge == 1)//right edge
	{
		position = { DISPLAY_WIDTH + radius, Play::RandomRollRange(0, DISPLAY_HEIGHT) };
	}
	else if (edge == 2)//bottom edge
	{
		position = { Play::RandomRollRange(0, DISPLAY_WIDTH), DISPLAY_HEIGHT+radius };
	}
	else if (edge == 3)//left edge
	{
		position = { 0 - radius, Play::RandomRollRange(0, DISPLAY_HEIGHT) };
	}
}

std::vector<Asteroid> Asteroid::asteroids;

void Asteroid::CreateAsteroids(int numAsteroids)
{
	asteroids.clear();
	asteroids.reserve(numAsteroids);

	for (int i = 0; i < numAsteroids; i++)
	{
		asteroids.emplace_back();
	}
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
