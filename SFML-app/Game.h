#pragma once
#include <iostream>


enum PostUpdateCondition {
	Continue,
	Terminate
};

class Game
{
public:
	Game();
	~Game();

	void load();
	PostUpdateCondition update(double delta);
	void draw();
	
};

