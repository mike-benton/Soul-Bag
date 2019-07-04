#pragma once
#include <SFML/Graphics.hpp> 
#include <vector>
#include "PartyMember.h"
using namespace std;
class InputManager
{
public:
	bool isActive;
	vector<bool[4]> inputVector;

	void ManageInput(PartyMember&, bool[4]);
	InputManager();
	~InputManager();
};

