/*
 * State_MainMenu.cpp
 *
 *  Created on: 30 juil. 2019
 *      Author: fabien
 */

#include "State_MainMenu.h"
#include "StateManager.h"

State_MainMenu::State_MainMenu(StateManager* l_stateManager)
	: BaseState(l_stateManager)
{}

State_MainMenu::~State_MainMenu() {}

void State_MainMenu::onCreate()
{
	m_font.loadFromFile("Resources/Media/Fonts/arial.ttf");
	m_text.setFont(m_font);
	m_text.setString(sf::String("MAIN MENU"));
	m_text.setCharacterSize(18);

	sf::FloatRect textRect = m_text.getGlobalBounds();
	m_text.setOrigin(textRect.left + textRect.width / 2.0f,
					textRect.top + textRect.height / 2.0f);
	m_text.setPosition(400, 100);

	m_buttonSize = sf::Vector2f(300.0f, 32.0f);
	m_buttonPos = sf::Vector2f(400, 200);
	m_buttonPadding = 4;

	std::string str[3];
	str[0] = "PLAY";
	str[1] = "CREDITS";
	str[2] = "EXIT";

	for(int i = 0; i < 3; ++i)
	{
		sf::Vector2f buttonPosition(m_buttonPos.x, m_buttonPos.y +
						(i * (m_buttonSize.y + m_buttonPadding)));
		m_rects[i].setSize(m_buttonSize);
		m_rects[i].setFillColor(sf::Color::Red);

		m_rects[i].setOrigin(m_buttonSize.x / 2.0f, m_buttonSize.y / 2.0f);
		m_rects[i].setPosition(buttonPosition);

		m_labels[i].setFont(m_font);
		m_labels[i].setString(sf::String(str[i]));
		m_labels[i].setCharacterSize(12);

		sf::FloatRect rect = m_labels[i].getLocalBounds();
		m_labels[i].setOrigin(rect.left + rect.width / 2.0f,
							rect.top + rect.height / 2.0f);

		m_labels[i].setPosition(buttonPosition);
	}

	EventManager* evMgr = m_stateMgr->getContext()->m_eventManager;
	evMgr->addCallback(StateType::MainMenu, "Mouse_Left",
						&State_MainMenu::mouseClick, this);
}

void State_MainMenu::onDestroy()
{
	EventManager* evMgr = m_stateMgr->getContext()->m_eventManager;
	evMgr->removeCallback(StateType::MainMenu, "Mouse_Left");
}

void State_MainMenu::activate()
{
	if(m_stateMgr->hasState(StateType::Game) && m_labels[0].getString() == "PLAY")
	{
		m_labels[0].setString(sf::String("RESUME"));
		sf::FloatRect rect = m_labels[0].getLocalBounds();
		m_labels[0].setOrigin(rect.left + rect.width / 2.0f,
							rect.top + rect.height / 2.0f);
	}
}

void State_MainMenu::mouseClick(EventDetails* l_details){
	sf::Vector2i mousePos = l_details->m_mouse;

	float halfX = m_buttonSize.x / 2.0f;
	float halfY = m_buttonSize.y / 2.0f;

	for(int i = 0; i < 3; ++i)
	{
		if(mousePos.x >= m_rects[i].getPosition().x - halfX &&
			mousePos.x <= m_rects[i].getPosition().x + halfX &&
			mousePos.y >= m_rects[i].getPosition().y - halfY &&
			mousePos.y <= m_rects[i].getPosition().y + halfY)
		{
			if(i == 0)
			{
				m_stateMgr->switchTo(StateType::Game);
			} else if(i == 1)
			{
				// Credits state.
			} else if(i == 2)
			{
				m_stateMgr->getContext()->m_wind->close();
			}
		}
	}
}

void State_MainMenu::draw()
{
	sf::RenderWindow* window = m_stateMgr->getContext()->m_wind->getRenderWindow();
	window->draw(m_text);
	for(int i = 0; i < 3; ++i)
	{
		window->draw(m_rects[i]);
		window->draw(m_labels[i]);
	}
}

void State_MainMenu::deactivate() {}
void State_MainMenu::update(const sf::Time& l_time) {}
