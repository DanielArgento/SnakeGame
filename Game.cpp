#include "Game.h"

#include <conio.h>
#include <thread>
#include <chrono>


Game::Game()
{
	GMap = new GameMap();
	snake = new Snake(GMap);
	snake->game = this;
}


Game::~Game()
{
	delete GMap;
	delete snake;
}

void Game::Run()
{
	snake->InitMap();
	running = true;

	while (running){
		Update();
		ClearScreen();
		PrintMap();

		//pause for 0.5 seconds before executing the loop again
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

	}

	//prints game over text
	Score();

	// Stop console from closing instantly
	std::cin.ignore();

}

void Game::ClearScreen()
{
	//Clear the screen
	char a = 30;
	for (int i = 0; i < a; i++)
	{
		std::cout << "\n";
	}
}

void Game::Update()
{
	// If a key is pressed
	if (_kbhit()) {
		// Change to direction determined by key pressed
		snake->ChangeDirection(_getch());
	}
	//Move in Direction indicated
	switch (snake->direction) {

	case 0: snake->Move(-1, 0);
		break;
	case 1: snake->Move(0, 1);
		break;
	case 2: snake->Move(1, 0);
		break;
	case 3: snake->Move(0, -1);
		break;

	}

	//Reduce snake values on map by 1
	for (int i = 0; i < GameMap::size; i++)
	{
		if (GMap->map[i] > 0)  GMap->map[i]--;
	}
}

void Game::PrintMap(){

	GMap->PrintMap();
}

void Game::Score(){

	// Print out game over text
	std::cout << "\t\tGame over!" << std::endl << "\t\tYour score is: " << snake->food;
}