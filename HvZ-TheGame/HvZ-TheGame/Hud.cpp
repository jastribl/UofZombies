#include "Hud.h"
#include "Constants.h"
#include <iostream>
#include "stdafx.h"
Hud::Hud()
{
	if (!create(SCREEN_SIZE_X, SCREEN_SIZE_Y))
	{
		std::cerr << "Error" << std::endl;
	}
	drawingSprite = new sf::Sprite(getTexture());
	shape = sf::CircleShape(50);
	// set the shape color to green
	shape.setFillColor(sf::Color(100, 250, 50));
}
Hud::~Hud()
{
	delete drawingSprite;
}
const sf::Sprite* Hud::drawHud()
{
	shape.move(0.5, 0);
	clear();
	draw(shape);
	display();
	return drawingSprite;
}