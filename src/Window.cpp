/*
 * Window.cpp
 *
 *  Created on: 29 juil. 2019
 *      Author: fabien
 */

#include "Window.h"

// Constructors - Destructors
Window::Window() { setup("SFML Window", sf::Vector2u(640, 480)); }

Window::Window(const std::string& l_title, const sf::Vector2u& l_size)
{
	setup(l_title, l_size);
}

Window::~Window() { destroy(); }

// Private Methods
void Window::setup(const std::string& l_title, const sf::Vector2u& l_size)
{
	m_title = l_title;
	m_size = l_size;
	m_isDone = false;
	m_isFullscreen = false;
	m_isFocused = true;
	m_eventManager.addCallback(StateType(0), "Fullscreen_toggle", &Window::toggleFullscreen, this);
	m_eventManager.addCallback(StateType(0), "Window_close", &Window::close, this);
	create();
}

void Window::create()
{
	auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	m_window.create({ m_size.x, m_size.y, 32}, m_title, style);
}

void Window::destroy() { m_window.close(); }

// Public Methods
void Window::update()
{
	sf::Event event;
	while(m_window.pollEvent(event))
	{
		if(event.type == sf::Event::LostFocus)
		{
			m_isFocused = false;
			m_eventManager.setFocus(false);
		}
		else if(event.type == sf::Event::GainedFocus)
		{
			m_isFocused = true;
			m_eventManager.setFocus(true);
		}
		m_eventManager.handleEvent(event);
	}
	m_eventManager.update();
}

void Window::toggleFullscreen(EventDetails* l_details)
{
	m_isFullscreen = !m_isFullscreen;
	destroy();
	create();
}
void Window::close(EventDetails* l_details) { m_isDone = true; }

void Window::beginDraw() { m_window.clear(sf::Color::Black); }
void Window::endDraw() { m_window.display(); }

void Window::draw(sf::Drawable& l_drawable) { m_window.draw(l_drawable); }

// Getters
bool Window::isDone() { return m_isDone; }
bool Window::isFullscreen() { return m_isFullscreen; }
sf::Vector2u Window::getSize() { return m_size; }
bool Window::isFocused() { return m_isFocused; }
EventManager* Window::getEventManager() { return &m_eventManager; }
sf::RenderWindow* Window::getRenderWindow() { return &m_window; }
