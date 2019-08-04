/*
 * Game.cpp
 *
 *  Created on: 29 juil. 2019
 *      Author: fabien
 */

#include "Game.h"

// Constructors - Destructors
Game::Game()
	: m_window("SFML RPG", sf::Vector2u(800, 600))
	, m_stateManager(&m_context)
{
	m_context.m_wind = &m_window;
	m_context.m_eventManager = m_window.getEventManager();
	m_stateManager.switchTo(StateType::Intro);
}

Game::~Game() {}

// Public Methods
void Game::update()
{
	m_window.update();
	m_stateManager.update(m_elapsed);
}

void Game::render()
{
	m_window.beginDraw();
	m_stateManager.draw();
	m_window.endDraw();
}

void Game::lateUpdate()
{
	m_stateManager.processRequests();
	restartClock();
}

void Game::restartClock() { m_elapsed = m_clock.restart(); }

// Getters
Window* Game::getWindow() { return &m_window; }
sf::Time Game::getElapsed() { return m_elapsed; }
