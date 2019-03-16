#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <chrono>
#include <ratio>

#include "./Game.h"

const unsigned target_fps = 60;
const double target_frame_duration = 1.0 / target_fps;


int main()
{
	sf::Font font;
	if (!font.loadFromFile("./fonts/calibri.ttf")) {
		throw new std::exception("Cannot find font");
	}

	sf::RenderWindow window(sf::VideoMode(400, 300), "Dusting off the ol' cpp");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	
	sf::Text fps_label;
	fps_label.setFillColor(sf::Color::Red);
	fps_label.setString("This is a label");
	fps_label.setFont(font);
	fps_label.setPosition(100, 100);

	Game game();

	
	unsigned total_elapsed_frames = 0;
	auto lastTime = std::chrono::high_resolution_clock::now();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		const auto now = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> delta = now - lastTime;

		const double seconds = delta.count();
		if (seconds < target_frame_duration) {
			continue;
		}

		lastTime = now;
		const auto fps = static_cast<unsigned>(std::round(1 / seconds));
		
		std::stringstream strFps;
		strFps << total_elapsed_frames << ": " << fps;
		fps_label.setString(strFps.str());

		game.update(seconds);

		window.clear();
		game.draw();

		window.draw(shape);
		window.draw(fps_label);

		window.display();

		++total_elapsed_frames;
	}

	return 0;
}