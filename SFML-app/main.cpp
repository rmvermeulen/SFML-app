#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <ratio>

int update(double delta) {
	// std::cout << delta << '\n';
	return 0;
}

void draw() {

}

int main()
{
	sf::Font font;
	if (!font.loadFromFile("./fonts/calibri.ttf")) {
		throw new std::exception("Font did not load I say");
	}

	sf::RenderWindow window(sf::VideoMode(400, 300), "Dusting off the ol' cpp");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	
	sf::Text fps_label;
	fps_label.setFillColor(sf::Color::Red);
	fps_label.setString("This is a label");
	fps_label.setFont(font);
	fps_label.setPosition(100, 100);

	
	unsigned frame_count = 0;
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
		lastTime = now;

		const unsigned fps = static_cast<unsigned int>(1/delta.count());
		
		fps_label.setString(std::to_string(frame_count) + ": " + std::to_string(fps));

		update(delta.count());

		window.clear();
		draw();

		window.draw(shape);
		window.draw(fps_label);

		window.display();

		++frame_count;
	}

	return 0;
}