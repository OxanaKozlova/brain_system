#include "BrainRingMode.h"
BrainRingMode::BrainRingMode(){
	 setPushes = 0;


}

BrainRingMode::~BrainRingMode(){
	
	
}

void BrainRingMode::Set(){
	seconedTimer = SECOND_TIMER;
	firstTimer = FIRST_TIMER;
	setPushes++;
	//пищалка
	
}

void BrainRingMode::SetTimer(){

	if (setPushes == 1) {
		CheckTimeLeft(firstTimer);
	}
	else if (setPushes == 2) {
		CheckTimeLeft(seconedTimer);
	}

}

void BrainRingMode:: CheckTimeLeft(int timeLeft) {
	timeLeft--;
	if (timeLeft == 0) {
		//пищалка
	}
}

void BrainRingMode::Reset(){

}
