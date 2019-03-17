#include <SFML/Graphics.hpp>

#include "Game.h"
#include <vector>


Game::Game() {
}


Game::~Game()
{
}

void Game::load()
{

	std::map <std::string, std::string> assets {
		{ "spaceship", "./assets/spaceship.png" },
		// { "player", "./assets/player.png" },
	};


	for (const std::pair<std::string, std::string>& info : assets) {

		const auto name = info.first;
		const auto path = info.second;
		sf::Texture texture;
		m_textures.emplace(name, texture);

		if (!texture.loadFromFile(path))
		{
			std::cerr << "Failed to load texture: " << path << std::endl;
			std::exit(1);
		}
	}
}

PostUpdateCondition Game::update(double delta) {

	return Continue;
}

void Game::draw()
{

}
