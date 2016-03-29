#include "GameMode.h"
#include "Arduino.h"
#include "TimerOne.h"
#include "Constants.h"
int GameMode::GetPin(){
	return pin;
}

void GameMode::SetPin(int pin){
	this->pin = pin;
}


bool GameMode::GetFalseStart(){
	return this->isFalseStart;
}

void GameMode::SetFalseStart(bool value){
	this->isFalseStart = value;
}

