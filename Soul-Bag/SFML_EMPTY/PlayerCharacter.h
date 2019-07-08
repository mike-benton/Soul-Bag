#pragma once
#include <SFML/Graphics.hpp>

class PlayerCharacter
{
public:
	std::vector<bool[4]> inputVector;
	std::string name;
	int HP;
	sf::RectangleShape pMemberRect;

	int inputDelay;

	PlayerCharacter();
	~PlayerCharacter();
};

