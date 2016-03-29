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
bool GameMode::UserButtonPushed(int pin, bool isPushed){
	digitalWrite(pin, HIGH);
	tone(SOUND_PIN, FREQUENCY_USER, TIME);
	isPushed = true;
	Timer1.stop();
	this->SetPin(pin);
	return isPushed;
}

