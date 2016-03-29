#include "Arduino.h"
#include "QuartetMode.h"
#include "TimerOne.h"


void QuartetMode::Set(){
	
}

void QuartetMode::Reset(){
	digitalWrite(GetPin(), LOW);

}
void QuartetMode::SetTimer(){
	
}

void QuartetMode::FalseStart(){
	

}

QuartetMode::QuartetMode(){

}

QuartetMode::~QuartetMode(){

}

bool QuartetMode::UserButtonPushed(int pin, bool isPushed){
	digitalWrite(pin, HIGH);
	tone(SOUND_PIN, FREQUENCY_USER, TIME);
	isPushed = false;
	Timer1.stop();
	this->SetPin(pin);
	return isPushed;
}

