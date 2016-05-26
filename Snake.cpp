#include "Snake.h"



Snake::Snake(GameMap* _GMap)
{
	GMap = _GMap;
}


Snake::~Snake()
{
}

void Snake::InitMap()
{
	//Place initial head location in middle of map
	headPosX = GameMap::mapWidth / 2;
	headPosY = GameMap::mapHeight / 2;
	GMap->map[headPosX + headPosY * GameMap::mapWidth] = 1;

	//Top and botom walls
	for (int x = 0; x < GameMap::mapWidth; x++) {
		GMap->map[x] = -1;
		GMap->map[x + (GameMap::mapHeight - 1) * GameMap::mapWidth] = -1;
	}

	//left and right walls
	for (int y = 0; y < GameMap::mapHeight; y++) {
		GMap->map[0 + y * GameMap::mapWidth] = -1;
		GMap->map[(GameMap::mapWidth - 1) + y * GameMap::mapWidth] = -1;
	}

	//spawn first food
	GMap->GenerateFood();
}


//Move snake head to new location
void Snake::Move(short dx, short dy)
{
	//Determine new head position
	short newX = headPosX + dx;
	short newY = headPosY + dy;

	//Check if there's food at current location
	if (GMap->map[newX + newY *  GameMap::mapWidth] == -2)
	{
		//increase body length
		food++;

		//Generate a new piece of food on the map
		GMap->GenerateFood();
	}

	else if (GMap->map[newX + newY * GameMap::mapWidth] != 0)
	{
		game->running = false;
	}

	//Finally, Move Head To New Location
	headPosX = newX;
	headPosY = newY;
	GMap->map[headPosX + headPosY * GameMap::mapWidth] = food + 1;
}