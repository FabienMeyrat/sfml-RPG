/*
 * State_Paused.cpp
 *
 *  Created on: 4 août 2019
 *      Author: fabien
 */

#include "State_Paused.h"
#include "StateManager.h"

State_Paused::State_Paused(StateManager* l_stateManager)
	: BaseState(l_stateManager)
{}

State_Paused::~State_Paused() {}

void State_Paused::onCreate()
{
	setTransparent(true);

	m_font.loadFromFile("Resources/Media/Fonts/arial.ttf");
	m_text.setFont(m_font);
	m_text.setCharacterSize(25);
	m_text.setString("Pause");
	sf::FloatRect rect = m_text.getLocalBounds();
	m_text.setOrigin(rect.left + rect.width / 2.0f,
					rect.top + rect.height / 2.0f);
	sf::Vector2u windowSize = m_stateMgr->getContext()->m_wind->getSize();
	m_text.setPosition(windowSize.x / 2, windowSize.y / 4);

	m_background = sf::RectangleShape(sf::Vector2f(windowSize));
	m_background.setPosition(0.0f, 0.0f);
	m_background.setFillColor(sf::Color(0, 0, 0, 150));

	EventManager* evMgr = m_stateMgr->getContext()->m_eventManager;
	evMgr->addCallback(StateType::Paused, "Key_P", &State_Paused::unPauseGame, this);
	evMgr->addCallback(StateType::Paused, "Key_Escape", &State_Paused::returnMainMenu, this);
}

void State_Paused::onDestroy()
{
	EventManager* evMgr = m_stateMgr->getContext()->m_eventManager;
	evMgr->removeCallback(StateType::Paused, "Key_P");
	evMgr->removeCallback(StateType::Paused, "Key_Escape");
}

void State_Paused::activate() {}
void State_Paused::deactivate() {}
void State_Paused::update(const sf::Time& l_time) {}

void State_Paused::draw()
{
	Window* wind = m_stateMgr->getContext()->m_wind;
	wind->draw(m_background);
	wind->draw(m_text);
}

void State_Paused::unPauseGame(EventDetails* l_details)
{
	m_stateMgr->switchTo(StateType::Game);
}

void State_Paused::returnMainMenu(EventDetails* l_details)
{
	m_stateMgr->switchTo(StateType::MainMenu);
}
