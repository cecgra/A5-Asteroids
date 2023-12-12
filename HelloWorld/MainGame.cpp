#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "rigidbody.h"

Asteroid asteroid;
Ship ship;

// The entry point for a PlayBuffer program
void MainGameEntry(PLAY_IGNORE_COMMAND_LINE)
{
	Play::CreateManager(DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE);
	Play::CentreAllSpriteOrigins();

	asteroid.CreateAsteroids(15);
	ship.Draw();
	
}

// Called by PlayBuffer every frame (60 times a second!)
bool MainGameUpdate(float elapsedTime)
{
	Play::ClearDrawingBuffer(Play::cBlack);

	for (auto& asteroid : Asteroid::asteroids)
	{
		asteroid.UpdateAsteroid(elapsedTime);
		asteroid.Draw();
	}
	

	ship.HandleInput(elapsedTime);
	ship.ShipUpdate(elapsedTime);
	ship.Draw();

	Play::PresentDrawingBuffer();
	return Play::KeyDown(VK_ESCAPE);
}

// Gets called once when the player quits the game 
int MainGameExit(void)
{
	Play::DestroyManager();
	return PLAY_OK;
}
