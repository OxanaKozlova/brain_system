#include "Arduino.h"
#include "WwwMode.h"
#include "TimerOne.h"


void WwwMode::Set(){
	tone(SOUND_PIN, FREQUENCY, TIME);
	timer = WWW_TIMER;


}

void WwwMode::Reset(){
	digitalWrite(GetPin(), LOW);

}
void WwwMode::SetTimer(){
	timer--;
	if (timer == 0) {
		tone(SOUND_PIN, FREQUENCY, TIME);
	}
	if (timer == 9){
		tone(SOUND_PIN, FREQUENCY, TIME);
	}

}

bool WwwMode::UserButtonPushed(int pin, bool isPushed){
	if (timer < 59 ){
		return false;
	}
	else{
		digitalWrite(pin, HIGH);
		tone(SOUND_PIN, FREQUENCY_USER, TIME);
		isPushed = true;
		Timer1.stop();
		this->SetPin(pin);
		return isPushed;
	}	
}

void WwwMode::FalseStart(){

}

WwwMode::WwwMode(){

}

WwwMode::~WwwMode(){

}

