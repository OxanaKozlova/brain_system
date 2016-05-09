#include "BrainRingMode.h"
#include "Arduino.h"
#include "TimerOne.h"

BrainRingMode::BrainRingMode() {
	 setPushes = 0;
}

BrainRingMode::~BrainRingMode() {	
	
}

void BrainRingMode::Set() {
	if (setPushes == 0) {
		tone(SOUND_PIN, FREQUENCY, TIME);
		timer = FIRST_TIMER;
		digitalWrite(GetPin(), LOW);
	}	
	else if (setPushes == 1) {
		tone(SOUND_PIN, FREQUENCY, TIME);
		digitalWrite(GetPin(), LOW);
		//digitalWrite(4, HIGH);
		timer = SECOND_TIMER;
	}

	setPushes++;		
}

void BrainRingMode::SetTimer() {
	timer--;
	if (timer == 0) {
		tone(SOUND_PIN, FREQUENCY, TIME);
		this->SetFalseStart(true);

	}
}

void BrainRingMode::Reset(){
	setPushes = 0;
	for (int i = 0; i < ARRAY_SIZE(ARRAY_LED); i++){
		digitalWrite(ARRAY_LED[i], LOW);
	}
	digitalWrite(13, LOW);
}

void BrainRingMode::FalseStart() {
	tone(SOUND_PIN, FREQUENCY_FALSESTART, TIME);
}

bool BrainRingMode::UserButtonPushed(int pin){
	digitalWrite(pin, HIGH);
	this->SetPin(pin);
	if (this->GetFalseStart()){
		this->FalseStart();
		return false;		
	}
	else{
		tone(SOUND_PIN, FREQUENCY_USER, TIME);
		Timer1.stop();
		return true;		
	}

}



