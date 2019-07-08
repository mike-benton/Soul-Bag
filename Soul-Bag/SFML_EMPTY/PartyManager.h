#pragma once
#include <SFML/Graphics.hpp> 
#include <vector>
using namespace std;

#include "PlayerCharacter.h"

class PartyManager
{
public:
	int partySize;
	PlayerCharacter* activePlayerCharacter;
	PlayerCharacter* backupPartyArr[3];

	bool activeInput[4];
	vector<bool[4]> inputVector;


	void SwapPlayerCharacter();
	void InitCharacters();
	void HandleEvents(sf::RenderWindow&);
	void ManageInput();

	PartyManager(int);
	PartyManager();
};

