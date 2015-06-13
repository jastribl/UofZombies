#include "stdafx.h"
#include "BaseClass.h"

#include "Point.h"

BaseClass::BaseClass(Point grid, const sf::Texture& texture)
	:gridLocation(grid), gridDestination(grid), sprite(texture) {}

BaseClass::~BaseClass() {}

void BaseClass::move(int x, int y){}
void BaseClass::applyMove() {}
void BaseClass::stop() {}

void BaseClass::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}