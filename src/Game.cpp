/*
 * Game.cpp
 *
 *  Created on: 29 juil. 2019
 *      Author: fabien
 */

#include "Game.h"

// Constructors - Destructors
Game::Game() : m_window("SFML RPG", sf::Vector2u(800, 600))
{}

Game::~Game() {}

// Public Methods
void Game::update()
{
	m_window.update();
}

void Game::handleInputs() {}

void Game::render()
{
	m_window.beginDraw();
	m_window.endDraw();
}

// Getters
Window* Game::getWindow() { return &m_window; }
