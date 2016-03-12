#include "BrainRingMode.h"
#include "Arduino.h"
BrainRingMode::BrainRingMode(){
	 setPushes = 0;


}

BrainRingMode::~BrainRingMode(){
	
	
}

void BrainRingMode::Set(){
	
	
	if (setPushes == 0){
		digitalWrite(SOUND, HIGH);
		timer = FIRST_TIMER;

	}	
	else if (setPushes > 0){
		//digitalWrite(SOUND, LOW);
		digitalWrite(GetPin(), LOW);
		timer = SECOND_TIMER;
	}
	setPushes++;
	
		
}

void BrainRingMode::SetTimer(){

	/*if (setPushes == 0) {
		CheckTimeLeft(firstTimer);
	}
	else if (setPushes > 0) {
		CheckTimeLeft(seconedTimer);
	}*/

	timer--;
	if (timer == 0) {
		digitalWrite(SOUND, LOW);
	}


}

void BrainRingMode:: CheckTimeLeft(int timeLeft) {
	timeLeft--;
	if (timeLeft == 0) {
		digitalWrite(SOUND, LOW);
	}
}

void BrainRingMode::Reset(){
	setPushes = 0;
	digitalWrite(GetPin(), LOW);


}



