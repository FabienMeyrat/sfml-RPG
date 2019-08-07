/*
 * Window.h
 *
 *  Created on: 29 juil. 2019
 *      Author: fabien
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <string>

#include <SFML/Graphics.hpp>

#include "EventManager.h"

class Window
{

public:

	// Constructors - Destructors
	Window();
	Window(const std::string& l_title, const sf::Vector2u& l_size);
	~Window();

	void beginDraw();
	void endDraw();

	void update();
	void draw(sf::Drawable& l_drawable);

	void toggleFullscreen(EventDetails* l_details);
	void close(EventDetails* l_details = nullptr);

	// Getters
	bool isDone();
	bool isFocused();
	bool isFullscreen();
	sf::Vector2u getSize();
	EventManager* getEventManager();
	sf::RenderWindow* getRenderWindow();
	sf::FloatRect getViewSpace();

private:

	// Private Methods
	void setup(const std::string& l_title, const sf::Vector2u& l_size);
	void destroy();
	void create();

	sf::RenderWindow m_window;
	EventManager m_eventManager;
	sf::Vector2u m_size;
	std::string m_title;
	bool m_isDone;
	bool m_isFullscreen;
	bool m_isFocused;

};

#endif /* WINDOW_H_ */
