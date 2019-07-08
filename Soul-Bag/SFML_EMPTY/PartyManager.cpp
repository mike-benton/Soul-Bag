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
			else
				activeInput[0] = false;
			
			if (event.key.code == sf::Keyboard::A)
				activeInput[1] = true;
			else
				activeInput[1] = false;
			
			if (event.key.code == sf::Keyboard::S)
				activeInput[2] = true;
			else
				activeInput[2] = false;
			
			if (event.key.code == sf::Keyboard::D)
				activeInput[3] = true;
			else
				activeInput[3] = false;
		}
	}
}

void PartyManager::ManageInput()
{

}
