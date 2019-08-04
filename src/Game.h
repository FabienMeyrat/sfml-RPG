/*
 * Game.h
 *
 *  Created on: 29 juil. 2019
 *      Author: fabien
 */

#ifndef SRC_GAME_H_
#define SRC_GAME_H_

#include "Window.h"
#include "StateManager.h"
#include "SharedContext.h"

class Game
{

public:

	// Constructor - Destructor
	Game();
	~Game();

	void update();
	void render();
	void lateUpdate();

	void restartClock();

	// Getters
	Window* getWindow();
	sf::Time getElapsed();

private:

	Window m_window;

	sf::Clock m_clock;
	sf::Time m_elapsed;
	SharedContext m_context;
	StateManager m_stateManager;

};

#endif /* SRC_GAME_H_ */
