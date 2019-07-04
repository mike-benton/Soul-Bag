// SFML_EMPTY.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp> 
#include "PartyMember.h"

void init();
void update();

enum GameState {
	title, mainGame, pause, gameOver
};

int main() {
	PartyMember pMember;
	
	sf::RenderWindow window(sf::VideoMode(1600, 1000), "Soul Bag");
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}



		window.clear();
		//window.draw();
		window.display();
	}



	
	
}

void init() {

}

void update() {

}

/// MISC CODE
/*
int gameState = mainGame;
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

