#pragma once
#include <SFML/Graphics.hpp> 
#include <vector>
using namespace std;

#include "PlayerCharacter.h"

class PartyManager
{
public:
	int partySize;
	int frameCount;
	PlayerCharacter* activePlayerCharacter;
	PlayerCharacter* backupPartyArr[3];



	void SwapPlayerCharacter(int);
	void Update();
	void InitCharacters();
	void HandleEvents(sf::RenderWindow&);
	void ManageInput(bool*);

	PartyManager(int);
	PartyManager();
};

