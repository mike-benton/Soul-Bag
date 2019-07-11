#pragma once
#include <SFML/Graphics.hpp>

class PlayerCharacter
{
public:
	std::vector<std::array<bool, 4>> inputVector;
	std::string name;
	int HP;
	sf::RectangleShape pMemberRect;

	void pushMovementArray(bool*);
	bool* getMovementArray(int);

	void Move(bool*);
	PlayerCharacter();
	~PlayerCharacter();
};

