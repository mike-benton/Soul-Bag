#pragma once
#include <SFML/Graphics.hpp>

class PlayerCharacter
{
public:
	std::vector<bool*> inputVector;
	std::string name;
	int HP;
	sf::RectangleShape pMemberRect;


	void Move(bool*);
	PlayerCharacter();
	~PlayerCharacter();
};

