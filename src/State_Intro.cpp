/*
 * StateIntro.cpp
 *
 *  Created on: 30 juil. 2019
 *      Author: fabien
 */

#include "State_Intro.h"

#include "StateManager.h"

State_Intro::State_Intro(StateManager* l_stateManager)
	: BaseState(l_stateManager)
{}

State_Intro::~State_Intro() {}

void State_Intro::onCreate()
{
	m_timePassed = 0.0f;
	sf::Vector2u windowSize = m_stateMgr->getContext()->
			m_wind->getRenderWindow()->getSize();
	m_introTexture.loadFromFile("Resources/Media/Textures/intro.png");
	m_introSprite.setTexture(m_introTexture);
	m_introSprite.setOrigin(m_introTexture.getSize().x / 2.0f,
							m_introTexture.getSize().y / 2.0f);
	m_introSprite.setPosition(windowSize.x / 2.0f, 0);

	m_font.loadFromFile("Resources/Media/Fonts/arial.ttf");
	m_text.setFont(m_font);
	m_text.setString("Press SPACE to continue");
	m_text.setCharacterSize(15);
	sf::FloatRect textRect = m_text.getLocalBounds();
	m_text.setOrigin(textRect.left + textRect.width / 2.0f,
					textRect.top + textRect.height / 2.0f);
	m_text.setPosition(windowSize.x / 2.0f, windowSize.y / 2.0f);

	EventManager* evMgr = m_stateMgr->getContext()->m_eventManager;
	evMgr->addCallback(StateType::Intro, "Intro_Continue",
						&State_Intro::continueMainMenu, this);
}

void State_Intro::onDestroy()
{
	EventManager* evMgr = m_stateMgr->getContext()->m_eventManager;
	evMgr->removeCallback(StateType::Intro, "Intro_Continue");
}

void State_Intro::update(const sf::Time& l_time)
{
	if(m_timePassed < 5.0f)
	{
		m_timePassed += l_time.asSeconds();
		m_introSprite.setPosition(m_introSprite.getPosition().x,
				m_introSprite.getPosition().y + (48 * l_time.asSeconds()));
	}
}

void State_Intro::draw()
{
	sf::RenderWindow* window = m_stateMgr->getContext()->m_wind->getRenderWindow();
	window->draw(m_introSprite);
	if(m_timePassed >= 5.0f)
	{
		window->draw(m_text);
	}
}

void State_Intro::continueMainMenu(EventDetails* l_details)
{
	if(m_timePassed >= 5.0f)
	{
		m_stateMgr->switchTo(StateType::MainMenu);
		m_stateMgr->remove(StateType::Intro);
	}
}

void State_Intro::activate() {}
void State_Intro::deactivate() {}
