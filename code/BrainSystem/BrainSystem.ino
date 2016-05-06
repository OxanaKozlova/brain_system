/*
 Name:		BrainSystem.ino
 Created:	03.03.2016 11:01:24
 Author:	Oxana
*/

// the setup function runs once when you press reset or power the board


#include "Constants.h"
#include "BrainRingMode.h"
#include "GameMode.h"
#include "TimerOne.h"
#include "WwwMode.h"
#include "QuartetMode.h"

GameMode *gameMode;

bool isPushed = false;

void setup() {
	for (int i = 0; i < ARRAY_SIZE(ARRAY_USER_BUTTON); i++) {
		pinMode(ARRAY_USER_BUTTON[i], INPUT);
		pciSetup(ARRAY_USER_BUTTON[i]);
	}
	for (int i = 0; i < ARRAY_SIZE(ARRAY_LED); i++) {
		pinMode(ARRAY_LED[i], OUTPUT);
	}

	pinMode(ADMIN_BUTTON_RESET, INPUT);
	pinMode(ADMIN_BUTTON_SET, INPUT);
	pinMode(BRAIN_RING_MODE, INPUT);
	pinMode(WWW_MODE, INPUT);
	pinMode(QUARTET_MODE, INPUT);
	pinMode(SOUND_PIN, OUTPUT);
	pciSetup(ADMIN_BUTTON_RESET);
	pciSetup(ADMIN_BUTTON_SET);

	if (BRAIN_RING_MODE == HIGH) {
		gameMode = new BrainRingMode();
	}
	else if (WWW_MODE == HIGH) {
		gameMode = new WwwMode();
	}
	else if (QUARTET_MODE == HIGH) {
		gameMode = new QuartetMode();
	}
	else {
		gameMode = new BrainRingMode();
	}
	//gameMode = new WwwMode();
	//gameMode = new QuartetMode();

	Timer1.initialize(1000000);
	Timer1.stop();
}

void loop() {

}

void pciSetup(byte pin) {
	*digitalPinToPCMSK(pin) |= bit(digitalPinToPCMSKbit(pin)); // enable pin 
	PCIFR |= bit(digitalPinToPCICRbit(pin)); // clear any outstanding interrupt 
	PCICR |= bit(digitalPinToPCICRbit(pin)); // enable interrupt for the group 
}

// the loop function runs over and over again until power down or reset

ISR(PCINT0_vect) {
	noInterrupts();
	isPushed = false;
	if (digitalRead(ADMIN_BUTTON_SET) == HIGH ) {	
		gameMode->Set();
		Timer1.attachInterrupt(TimerInterrupt);
		gameMode->SetFalseStart(false);
	}
	if (digitalRead(ADMIN_BUTTON_RESET) == HIGH) {
		Timer1.stop();
		gameMode->Reset();
		gameMode->SetFalseStart(true);
	}
	interrupts();
}

ISR(PCINT1_vect){
	noInterrupts();	
	if (isPushed == false){
		for (int i = 0; i < ARRAY_SIZE(ARRAY_USER_BUTTON); i++){
			if (digitalRead(ARRAY_USER_BUTTON[i]) == HIGH){
				isPushed = gameMode->UserButtonPushed(ARRAY_LED[i]);
			}
		}		
	}	
	interrupts();
}

void TimerInterrupt() {
	gameMode->SetTimer();
}