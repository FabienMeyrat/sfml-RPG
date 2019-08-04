/*
 * State_MainMenu.h
 *
 *  Created on: 30 juil. 2019
 *      Author: fabien
 */

#ifndef SRC_STATE_MAINMENU_H_
#define SRC_STATE_MAINMENU_H_

#include <SFML/Graphics.hpp>

#include <iostream>

#include "BaseState.h"
#include "EventManager.h"

class State_MainMenu : public BaseState
{

public:

	State_MainMenu(StateManager* l_stateManager);
	~State_MainMenu();

	virtual void onCreate();
	virtual void onDestroy();

	virtual void activate();
	virtual void deactivate();

	virtual void update(const sf::Time& l_time);
	virtual void draw();

	void mouseClick(EventDetails* l_details);

private:

	sf::Font m_font;
	sf::Text m_text;

	sf::Vector2f m_buttonSize;
	sf::Vector2f m_buttonPos;
	unsigned int m_buttonPadding;

	sf::RectangleShape m_rects[3];
	sf::Text m_labels[3];

};

#endif /* SRC_STATE_MAINMENU_H_ */
