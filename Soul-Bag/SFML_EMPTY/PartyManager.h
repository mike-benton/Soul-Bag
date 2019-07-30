#pragma once
#include <SFML/Graphics.hpp> 
#include <vector>
#include "PlayerCharacter.h"
using namespace std;



class PartyManager
{
public:
	int partySize;
	int frameCount;
	PlayerCharacter* activePlayerCharacter;
	PlayerCharacter* backupPartyArr[3];

	int inputDelay;
	bool activeInput[4];


	void SwapPlayerCharacter(int);
	void Update();
	void InitCharacters();
	void HandleEvents(sf::RenderWindow&);
	void ManageInput(bool*);

	PartyManager(int);
	PartyManager();
};

