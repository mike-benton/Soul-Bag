#include "pch.h"
#include "PartyManager.h"


PartyManager::PartyManager(int partySize)
{
	this->partySize = partySize;
	InitCharacters();
}

PartyManager::PartyManager()
{
	partySize = 1;
	InitCharacters();
}

void PartyManager::InitCharacters()
{
	activePlayerCharacter = new PlayerCharacter();

	for (int i = 0; i < partySize - 1; i++) {
		backupPartyArr[i] = new PlayerCharacter();
	}
}

void PartyManager::HandleEvents(sf::RenderWindow & window)
{
	sf::Event event;
	bool activeInput[4];

	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::W)
				activeInput[0] = true;
			
			if (event.key.code == sf::Keyboard::A)
				activeInput[1] = true;
			
			if (event.key.code == sf::Keyboard::S)
				activeInput[2] = true;
			
			if (event.key.code == sf::Keyboard::D)
				activeInput[3] = true;
		}
	}
}

void PartyManager::SwapPlayerCharacter(int)
{

}

void PartyManager::Update()
{

}

void PartyManager::ManageInput(bool *activeInput)
{
	activePlayerCharacter->inputVector.push_back(activeInput);
	activePlayerCharacter->Move(activeInput);
}
