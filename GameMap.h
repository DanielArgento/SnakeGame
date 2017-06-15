#pragma once

#include <iostream>
#include "Snake.h"

class Snake;

class GameMap	
{
	//instance of snake to acess methods
	Snake* snake;

public:
	GameMap();
	~GameMap();

	//Dimentions of Game World
	static const char mapWidth = 20;
	static const char mapHeight = 20;

	//Size of the map
	static const short size = mapWidth * mapHeight;

	//Tile values for the map
	 short map[size];

	//Method Declarations
	 void GenerateFood();
	 void PrintMap();
	 char getMapValue(char value);
	




	
};

