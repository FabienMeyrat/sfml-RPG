/*
 * TextureManager.h
 *
 *  Created on: 5 août 2019
 *      Author: fabien
 */

#ifndef SRC_TEXTUREMANAGER_H_
#define SRC_TEXTUREMANAGER_H_

#include <SFML/Graphics.hpp>

#include "ResourceManager.h"

class TextureManager : public ResourceManager<TextureManager, sf::Texture>
{

public:

	TextureManager() : ResourceManager("Resources/Config/textures.cfg") {}

	sf::Texture* load(const std::string& l_path)
	{
		sf::Texture* texture = new sf::Texture();

		if(!texture->loadFromFile(Utils::getWorkingDirectory() + l_path))
		{
			delete texture;
			texture = nullptr;
			std::cerr << "! Failed to load texture : " << l_path << std::endl;
		}

		return texture;
	}

};

#endif /* SRC_TEXTUREMANAGER_H_ */
