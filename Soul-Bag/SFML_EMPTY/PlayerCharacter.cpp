#include "pch.h"
#include "PlayerCharacter.h"




PlayerCharacter::PlayerCharacter()
{

}

void PlayerCharacter::Move(bool inputArr[])
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
