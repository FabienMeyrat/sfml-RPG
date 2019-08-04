/*
 * State_Game.h
 *
 *  Created on: 4 août 2019
 *      Author: fabien
 */

#ifndef SRC_STATE_GAME_H_
#define SRC_STATE_GAME_H_

#include <iostream>

#include "BaseState.h"
#include "EventManager.h"

class State_Game : public BaseState
{

public:

	State_Game(StateManager* l_stateManager);
	~State_Game();

	virtual void onCreate();
	virtual void onDestroy();

	virtual void activate();
	virtual void deactivate();

	virtual void update(const sf::Time& l_time);
	virtual void draw();

	void returnMainMenu(EventDetails* l_details);
	void pauseGame(EventDetails* l_details);

private:

	sf::Font m_font;
	sf::Text m_text;

};

#endif /* SRC_STATE_GAME_H_ */
