/*
 * StateIntro.h
 *
 *  Created on: 30 juil. 2019
 *      Author: fabien
 */

#ifndef SRC_STATE_INTRO_H_
#define SRC_STATE_INTRO_H_

#include <SFML/Graphics.hpp>

#include "BaseState.h"
#include "EventManager.h"

class State_Intro : public BaseState
{
public:

	State_Intro(StateManager* l_stateManager);
	~State_Intro();

	virtual void onCreate();
	virtual void onDestroy();

	virtual void activate();
	virtual void deactivate();

	virtual void update(const sf::Time& l_time);
	virtual void draw();

	void continueMainMenu(EventDetails* l_details);

private:

	sf::Texture m_introTexture;
	sf::Sprite m_introSprite;
	sf::Font m_font;
	sf::Text m_text;
	float m_timePassed;

};

#endif /* SRC_STATE_INTRO_H_ */
