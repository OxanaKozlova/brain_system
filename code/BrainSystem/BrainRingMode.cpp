#include "BrainRingMode.h"
#include "Arduino.h"
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
		timer = SECOND_TIMER;
	}

	setPushes++;		
}

void BrainRingMode::SetTimer() {
	timer--;
	if (timer == 0) {
		tone(SOUND_PIN, FREQUENCY, TIME);
	}
}

void BrainRingMode::Reset(){
	setPushes = 0;
	digitalWrite(GetPin(), LOW);
}

void BrainRingMode::FalseStart() {
	tone(SOUND_PIN, FREQUENCY_FALSESTART, TIME);
}



