#pragma once

#include <iostream>
#include "Snake.h"
#include "GameMap.h"

class Snake;
class GameMap;

class Game
{
	Snake* snake;
	GameMap* GMap;

public:
	Game();
	~Game();

	void Run();
	void ClearScreen();
	void Update();
	void PrintMap();
	void Score();

	//IsGameRunning
	bool running = true;



};



