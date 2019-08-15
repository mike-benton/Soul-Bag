#include "pch.h"
#include "PartyManager.h"
#include <iostream>



PartyManager::PartyManager(int partySize)
{
	inputDelay = 500;
	this->partySize = partySize;
	InitCharacters();
}

PartyManager::PartyManager()
{
	inputDelay = 500;
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

			if (event.key.code == sf::Keyboard::Tab) {
				frameCount = 0;
				for (int i = 0; i < partySize - 1; i++) {
					backupPartyArr[i]->pMemberRect.setPosition(400, 400);
				}
			}
		}
		if (event.type == sf::Event::KeyReleased) {
			if (event.key.code == sf::Keyboard::W)
				activeInput[0] = false;

			if (event.key.code == sf::Keyboard::A)
				activeInput[1] = false;

			if (event.key.code == sf::Keyboard::S)
				activeInput[2] = false;

			if (event.key.code == sf::Keyboard::D)
				activeInput[3] = false;
		}
	}

	ManageInput(activeInput);
}

void PartyManager::SwapPlayerCharacter(int)
{

}

void PartyManager::Update()
{

}

void PartyManager::ManageInput(bool *activeInput)
{
	activePlayerCharacter->pushMovementArray(activeInput);
	activePlayerCharacter->Move(activeInput);
	backupPartyArr[0]->pushMovementArray(activeInput);
	//std::cout << frameCount << std::endl;
	if (frameCount > inputDelay) {
		for (int i = 0; i < partySize - 1; i++) {
			backupPartyArr[i]->Move(backupPartyArr[i]->getMovementArray(frameCount - inputDelay));
		}
	}

	frameCount++;
}
