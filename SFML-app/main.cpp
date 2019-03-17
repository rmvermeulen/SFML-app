#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <chrono>
#include <ratio>

#include "./Game.h"
#include "./FrameCounter.h"

const unsigned target_fps = 60;

int main()
{
	sf::Font font;
	if (!font.loadFromFile("./fonts/calibri.ttf")) {
		throw new std::exception("Cannot find font");
	}

	sf::RenderWindow window(sf::VideoMode(400, 300), "Dusting off the ol' cpp");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	


	Game game;
	game.load();
	
	unsigned total_elapsed_frames = 0;
	FrameCounter frames(target_fps);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}



		if (!frames.next_frame()) {
			continue;
		}

		game.update(frames.frame_duration());

		window.clear();
		game.draw();

		window.draw(shape);

		window.display();

		++total_elapsed_frames;
	}

	return 0;
}