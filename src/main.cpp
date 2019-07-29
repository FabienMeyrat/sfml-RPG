/*
 * main.cpp
 *
 *  Created on: 29 juil. 2019
 *      Author: fabien
 */

#include "Game.h"

int main()
{
	Game game;
	while(!game.getWindow()->isDone())
	{
		game.handleInputs();
		game.update();
		game.render();
	}

	return 0;
}


