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

GameMode *gameMode;
int flag;
bool isPushed;

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
	pinMode(SOUND_PIN, OUTPUT);
	pciSetup(ADMIN_BUTTON_RESET);
	pciSetup(ADMIN_BUTTON_SET);

	gameMode = new BrainRingMode();

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

ISR(PCINT1_vect){
	noInterrupts();
	if (isPushed == false) {
		for (int i = 0; i < ARRAY_SIZE(ARRAY_USER_BUTTON); i++){
			if (digitalRead(ARRAY_USER_BUTTON[i]) == HIGH){
				UserButtonPushed(ARRAY_LED[i]);
				flag = 0;
				break;
			}
		}
	}

	if (digitalRead(ADMIN_BUTTON_SET) == HIGH && flag == 0) {
		isPushed = false;
		gameMode->Set();
		Timer1.attachInterrupt(TimerInterrupt);		
		flag = 1;
	}

	if (digitalRead(ADMIN_BUTTON_RESET) == HIGH) {
		Timer1.stop();
		gameMode->Reset();
		flag = 0;
	}

	interrupts();
}

void UserButtonPushed(int pin) {
	digitalWrite(pin, HIGH);
	isPushed = true;
	Timer1.stop();
	gameMode->SetPin(pin);
}


void TimerInterrupt() {
	gameMode->SetTimer();
}