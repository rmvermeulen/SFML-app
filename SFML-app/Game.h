#pragma once
#include <iostream>


enum PostUpdateCondition {
	Continue,
	Terminate
};

class Game
{

	std::map<std::string, sf::Texture> m_textures;
public:
	Game();
	~Game();

	void load();
	PostUpdateCondition update(double delta);
	void draw();
	
};

