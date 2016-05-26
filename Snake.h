#pragma once

#include "Game.h"

class GameMap;
class Game;

class Snake
{
	GameMap* GMap;
	

public:
	Snake(GameMap* _GMap);
	~Snake();
	Game* game;

	//Snake head variables
	 short headPosX = 0;
	 short headPosY = 0;

	 short direction;

	//How Long the Snake's body is
	short food = 3;

	void ChangeDirection(char key)
	{
		/* Reference of how movement will work
		W
	  A	+ S
		D

		1
	  4	+ 2
		3
		*/

		switch (key)
		{
		case 'w':
			if (direction != 2) 
				direction = 0;
			break;
		case 'd':
			if (direction != 3)
				direction = 1;
			break;
		case 's':
			if (direction != 4)
				direction = 2;
			break;
		case 'a':
			if (direction != 5)
				direction = 3;
		}
	}

	void Move(short dx, short dy);
	void InitMap();
};

