#include "pch.h"
#include "PlayerCharacter.h"

#include <iostream>
using namespace std;



PlayerCharacter::PlayerCharacter()
{
	pMemberRect.setSize(sf::Vector2f(100, 100));
	pMemberRect.setPosition(400, 400);
}

void PlayerCharacter::Move(bool *inputArr)
{
	if (inputArr[0])
		pMemberRect.setPosition(pMemberRect.getPosition().x, pMemberRect.getPosition().y - 1);
	if (inputArr[1])
		pMemberRect.setPosition(pMemberRect.getPosition().x - 1, pMemberRect.getPosition().y);
	if (inputArr[2])
		pMemberRect.setPosition(pMemberRect.getPosition().x, pMemberRect.getPosition().y + 1);
	if (inputArr[3])
		pMemberRect.setPosition(pMemberRect.getPosition().x + 1, pMemberRect.getPosition().y);
}

PlayerCharacter::~PlayerCharacter()
{

}
