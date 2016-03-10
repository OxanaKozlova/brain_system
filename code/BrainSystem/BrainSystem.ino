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
bool isPushed = false;
void setup() {
	for (int i = 0; i < ARRAY_SIZE(ARRAY_USER_BUTTON); i++){
		pinMode(ARRAY_USER_BUTTON[i], INPUT);
		pciSetup(ARRAY_USER_BUTTON[i]);
	}
	for (int i = 0; i < ARRAY_SIZE(ARRAY_LED); i++){
		pinMode(ARRAY_LED[i], OUTPUT);
	}

	pinMode(ADMIN_BUTTON_RESET, INPUT);
	pinMode(ADMIN_BUTTON_SET, INPUT);	
	pciSetup(ADMIN_BUTTON_RESET);
	pciSetup(ADMIN_BUTTON_SET);
	gameMode = new BrainRingMode();

	Timer1.initialize(1000000);
	


}

void loop() {
	digitalWrite(13, HIGH);

}

void pciSetup(byte pin)
{
	*digitalPinToPCMSK(pin) |= bit(digitalPinToPCMSKbit(pin)); // enable pin 
	PCIFR |= bit(digitalPinToPCICRbit(pin)); // clear any outstanding interrupt 
	PCICR |= bit(digitalPinToPCICRbit(pin)); // enable interrupt for the group 
}

// the loop function runs over and over again until power down or reset


ISR(PCINT0_vect){
	noInterrupts();
	if (digitalRead(ADMIN_BUTTON_SET) == HIGH){
		isPushed = false;
		gameMode->Set();	
		Timer1.attachInterrupt(TimerInterrupt);
	}
	if (digitalRead(ADMIN_BUTTON_RESET) == HIGH){
		gameMode->Reset();
	}
	interrupts();

}


ISR(PCINT1_vect){
	noInterrupts();
	if (isPushed == false){
		for (int i = 0; i < ARRAY_SIZE(ARRAY_USER_BUTTON); i++){
			if (digitalRead(ARRAY_USER_BUTTON[i]) == HIGH){
				UserButtonPushed(ARRAY_LED[i]);
				break;
			}
		}
	}
	interrupts();
}

void UserButtonPushed(int pin){
	digitalWrite(pin, HIGH);
	isPushed = true;
	Timer1.stop();
}


void TimerInterrupt(){
	gameMode->SetTimer();
}