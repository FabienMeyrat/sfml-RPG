/*
 * State_Paused.h
 *
 *  Created on: 4 août 2019
 *      Author: fabien
 */

#ifndef SRC_STATE_PAUSED_H_
#define SRC_STATE_PAUSED_H_

#include "BaseState.h"
#include "EventManager.h"

class State_Paused : public BaseState
{

public:

	State_Paused(StateManager* l_stateManager);
	~State_Paused();

	virtual void onCreate();
	virtual void onDestroy();

	virtual void activate();
	virtual void deactivate();

	virtual void update(const sf::Time& l_time);
	virtual void draw();

	void unPauseGame(EventDetails* l_details);
	void returnMainMenu(EventDetails* l_details);

private:

	sf::RectangleShape m_background;
	sf::Font m_font;
	sf::Text m_text;

};

#endif /* SRC_STATE_PAUSED_H_ */
