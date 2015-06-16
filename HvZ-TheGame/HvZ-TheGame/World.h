#pragma once
class BaseClass;
#include "Constants.h"
#include <string>

class World {

private:
	std::multimap<sf::Vector3i, BaseClass*, ByLocation> world;
	std::vector<BaseClass*> deletedItems;

public:
	std::string name;

	World();
	~World();

	bool itemsExistAt(const sf::Vector3i& point) const;
	std::pair <std::multimap<sf::Vector3i, BaseClass*, ByLocation>::iterator, std::multimap<sf::Vector3i, BaseClass*, ByLocation>::iterator> getItemsAt(const sf::Vector3i& point);
	void add(BaseClass* object);
	void removeFromMap(const sf::Vector3i& grid, const sf::Vector3i& point);
	void deleteItem(const sf::Vector3i& grid, const sf::Vector3i& point);
	void clearDeletedItems();
	void draw(sf::RenderWindow& window);
	int size() const;
};