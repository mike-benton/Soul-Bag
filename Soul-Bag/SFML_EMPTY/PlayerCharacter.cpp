#include "pch.h"
#include "PlayerCharacter.h"
#include <array>
#include <iostream>
using namespace std;



PlayerCharacter::PlayerCharacter()
{
	pMemberRect.setSize(sf::Vector2f(100, 100));
	pMemberRect.setPosition(400, 400);
}

void PlayerCharacter::pushMovementArray(bool * inputArr)
{
	if (inputVector.size() > 0) {
		//cout << "inputVector Size: " << inputVector.size() << " | Frames of last input: " << inputVector[inputVector.size() - 1].frames << endl;

		if (inputVector[inputVector.size() - 1] == inputArr) {
			inputVector[inputVector.size() - 1].frames++;
		}
		else {
			inputFrame currentInputFrame;
			currentInputFrame[0] = inputArr[0];
			currentInputFrame[1] = inputArr[1];
			currentInputFrame[2] = inputArr[2];
			currentInputFrame[3] = inputArr[3];
			inputVector.push_back(currentInputFrame);
		}
	}
	else {
		inputFrame currentInputFrame;
		currentInputFrame[0] = inputArr[0];
		currentInputFrame[1] = inputArr[1];
		currentInputFrame[2] = inputArr[2];
		currentInputFrame[3] = inputArr[3];
		inputVector.push_back(currentInputFrame);
	}
	//std::array<bool, 4> currentInputArr = { inputArr[0], inputArr[1], inputArr[2], inputArr[3] };
	//inputVector.push_back(currentInputArr);
}

bool * PlayerCharacter::getMovementArray(int currentFrame)
{
	int elapsedFrames = 0;
	for (int i = 0; i < inputVector.size(); i++) {
		if (currentFrame > inputVector[i].frames + elapsedFrames) {
			elapsedFrames += inputVector[i].frames;
		}
		else {
			return inputVector[i].inputArr;
		}
	}
	
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
