/*
 * State_Game.cpp
 *
 *  Created on: 4 août 2019
 *      Author: fabien
 */

#include "State_Game.h"
#include "StateManager.h"

State_Game::State_Game(StateManager* l_stateManager) : BaseState(l_stateManager){}

State_Game::~State_Game(){}

void State_Game::onCreate()
{
	m_font.loadFromFile("Resources/Media/Fonts/arial.ttf");
	m_text.setFont(m_font);
	m_text.setString("Game State");
	m_text.setCharacterSize(25);
	sf::FloatRect rect = m_text.getLocalBounds();
	m_text.setOrigin(rect.left + rect.width / 2.0f,
					rect.top + rect.height / 2.0f);
	sf::Vector2u windSize = m_stateMgr->getContext()->m_wind->getSize();
	m_text.setPosition(windSize.x / 2, windSize.y / 2);

	EventManager* evMgr = m_stateMgr->getContext()->m_eventManager;
	evMgr->addCallback(StateType::Game, "Key_Escape", &State_Game::returnMainMenu, this);
	evMgr->addCallback(StateType::Game, "Key_P", &State_Game::pauseGame, this);
}

void State_Game::onDestroy()
{
	EventManager* evMgr = m_stateMgr->getContext()->m_eventManager;
	evMgr->removeCallback(StateType::Game, "Key_Escape");
	evMgr->removeCallback(StateType::Game, "Key_P");
}

void State_Game::activate()
{
}

void State_Game::deactivate()
{
}

void State_Game::update(const sf::Time& l_time)
{
}

void State_Game::draw()
{
	m_stateMgr->getContext()->m_wind->draw(m_text);
}

void State_Game::returnMainMenu(EventDetails* l_details)
{
	m_stateMgr->switchTo(StateType::MainMenu);
}

void State_Game::pauseGame(EventDetails* l_details)
{
	m_stateMgr->switchTo(StateType::Paused);
}
