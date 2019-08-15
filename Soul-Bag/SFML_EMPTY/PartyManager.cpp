#include "pch.h"
#include "PartyManager.h"
#include <iostream>



PartyManager::PartyManager(int partySize)
{
	inputDelay = -1;
	this->partySize = partySize;
	InitCharacters();
}

PartyManager::PartyManager()
{
	inputDelay = -1;
	partySize = 1;
	InitCharacters();
}

void PartyManager::InitCharacters()
{
	activePlayerCharacter = new PlayerCharacter();
	activePlayerCharacter->pMemberRect.setPosition(600, 800);

	for (int i = 0; i < partySize - 1; i++) {
		backupPartyArr[i] = new PlayerCharacter();
		backupPartyArr[i]->pMemberRect.setPosition(700 + 100 * i, 800);
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
					//backupPartyArr[i]->pMemberRect.setPosition(400, 400); CHANGE THIS BACK TO STARTING POSITION
				}
			}

			if (event.key.code == sf::Keyboard::Num1) {
				SwapPlayerCharacter(0);
				frameCount = 0;
				//consider removing the last inputframe from the vector as it's likely going to be still and so is the first frame anyway
				continue;
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

void PartyManager::SwapPlayerCharacter(int playerIndex)
{
	PlayerCharacter* tempCharacter = activePlayerCharacter;
	activePlayerCharacter = backupPartyArr[playerIndex];
	backupPartyArr[playerIndex] = tempCharacter;
}

void PartyManager::Update()
{

}

void PartyManager::ManageInput(bool *activeInput)
{
	activePlayerCharacter->pushMovementArray(activeInput);
	activePlayerCharacter->Move(activeInput);
	//backupPartyArr[0]->pushMovementArray(activeInput);
	//std::cout << frameCount << std::endl;
	if (frameCount > inputDelay) { //right now inputdelay is -1 because i don't know if i want to use it
		for (int i = 0; i < partySize - 1; i++) {
			backupPartyArr[i]->Move(backupPartyArr[i]->getMovementArray(frameCount - inputDelay));
		}
	}

	frameCount++;
}
