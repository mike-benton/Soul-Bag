// SFML_EMPTY.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp> 
#include "PlayerCharacter.h"
#include "PartyManager.h"

void init();
void update();

enum GameState {
	title, mainGame, pause, gameOver
};

int main() {
	PartyManager partyManager(2);
	partyManager.activePlayerCharacter->pMemberRect.setFillColor(sf::Color::Green);
	
	sf::RenderWindow window(sf::VideoMode(1600, 1000), "Soul Bag");
	window.setFramerateLimit(144);

	while (window.isOpen()) {
		partyManager.HandleEvents(window);
		
		window.clear();
		window.draw(partyManager.backupPartyArr[0]->pMemberRect);
		window.draw(partyManager.activePlayerCharacter->pMemberRect);
		window.display();
	}

	delete partyManager.activePlayerCharacter;
	for (int i = 0; i < partyManager.partySize; i++) {
		delete partyManager.backupPartyArr[i];
	}
}

void init() {

}

void update() {

}

/// MISC CODE
/*
GameState gameState = mainGame;
while (window.isOpen()) {
	switch (gameState) {
	case title:

		break;
	case mainGame:

		break;
	case pause:

		break;
	case gameOver:

		break;
	}*/

