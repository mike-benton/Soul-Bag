#pragma once
#include <SFML/Graphics.hpp>

struct inputFrame {
	bool inputArr[4];
	int frames = 0;

	bool operator[](int i) const { return inputArr[i]; }
	bool &operator[](int i) { return inputArr[i]; }

	bool operator== (const bool oArr[4]) const {
		return inputArr[0] == oArr[0] && inputArr[1] == oArr[1] && inputArr[2] == oArr[2] && inputArr[3] == oArr[3];
	}
};

class PlayerCharacter
{
public:
	std::vector<std::array<bool, 4>> inputVectorOld;
	std::vector<inputFrame> inputVector;
	std::string name;
	int HP;
	sf::RectangleShape pMemberRect;

	void pushMovementArray(bool*);
	bool* getMovementArray(int);

	void Move(bool*);
	PlayerCharacter();
	~PlayerCharacter();
};

