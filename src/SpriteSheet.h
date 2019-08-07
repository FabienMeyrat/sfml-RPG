/*
 * SpriteSheet.h
 *
 *  Created on: 7 août 2019
 *      Author: fabien
 */

#ifndef SRC_SPRITESHEET_H_
#define SRC_SPRITESHEET_H_

#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <unordered_map>

#include "TextureManager.h"
#include "Direction.h"
#include "Anim_Directional.h"
#include "Utilities.h"

using Animations = std::unordered_map<std::string, Anim_Base*>;

class SpriteSheet
{

public:

	SpriteSheet(TextureManager* l_textMgr);
	~SpriteSheet();

	void cropSprite(const sf::IntRect& l_rect);

	bool loadSheet(const std::string& l_file);
	void releaseSheet();

	Anim_Base* getCurrentAnim();
	sf::Vector2i getSpriteSize();
	sf::Vector2f getSpritePosition();
	Direction getDirection();

	bool setAnimation(const std::string& l_name, const bool& l_play = false,
												const bool& l_loop = false);
	void setSpriteSize(const sf::Vector2i& l_size);
	void setSpritePosition(const sf::Vector2f& l_pos);
	void setDirection(const Direction& l_dir);

	void update(const float& l_dT);
	void draw(sf::RenderWindow* l_wind);

private:

	std::string m_texture;
	sf::Sprite m_sprite;
	sf::Vector2i m_spriteSize;
	sf::Vector2f m_spriteScale;
	Direction m_direction;
	std::string m_animType;
	Animations m_animations;
	Anim_Base* m_animationCurrent;
	TextureManager* m_textureManager;

};

#endif /* SRC_SPRITESHEET_H_ */
