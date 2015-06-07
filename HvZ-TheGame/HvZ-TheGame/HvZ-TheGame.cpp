#include "stdafx.h"
#include "Constants.h"
#include "Hud.h"
#include "TextureManager.h"
#include "WorldManager.h"

void updateGame() {
}

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::RenderWindow(sf::VideoMode(SCREEN_SIZE_X, SCREEN_SIZE_Y), "HvZ - The Game", sf::Style::Default, settings));
	sf::View hudView(sf::FloatRect(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y));
	sf::View worldView(sf::FloatRect(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y));

	Hud hud = Hud();

	TextureManager textureManager = TextureManager();

	WorldManager worldManager = WorldManager(textureManager);

	window.setFramerateLimit(10);
	sf::Clock clock;
	float elapsedTime = 0.0f;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::KeyPressed:

				if (event.key.code == sf::Keyboard::Escape){
					window.close();
				}
				else if (event.key.code == sf::Keyboard::Up){
					worldView.move(0, -10);
				}
				else if (event.key.code == sf::Keyboard::Down){
					worldView.move(0, 10);
				}
				else if (event.key.code == sf::Keyboard::Left){
					worldView.move(-10., 0);
				}
				else if (event.key.code == sf::Keyboard::Right){
					worldView.move(10, 0);
				}
				else if (event.key.code == sf::Keyboard::W){
					worldManager.nextWorld();
				}
				break;

			case sf::Event::MouseButtonPressed: {
				Point point = screenToGrid(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
				if (worldManager.getCurrentWorld().getLevel(0).blockExitsAt(point))
				{
					worldManager.getCurrentWorld().getLevel(0).getBlockAt(point).toggleVisible();
				}
				break;
			}

			case sf::Event::Closed:
				window.close();
				break;

			default:
				break;
			}
		}
		for (; elapsedTime >= 0.025f; elapsedTime -= 0.025f) {
			updateGame();
		}
		window.clear(sf::Color(255, 255, 255));

		window.setView(worldView);
		worldManager.getCurrentWorld().draw(window);

		window.setView(hudView);
		hud.setHP(rand() % 101);
		hud.setMP(rand() % 101);
		hud.drawToWindow(window);

		window.setView(worldView); //view need to be set this way to ensure the hud doesn't move, and the blokcs can move
		window.display();
		elapsedTime += clock.restart().asSeconds();
	}
	return 0;
}