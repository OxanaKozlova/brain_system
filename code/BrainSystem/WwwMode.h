#pragma once
#include "GameMode.h"
#include "Constants.h"

#define WWW_TIMER 60

 class WwwMode : public GameMode{
 private:
	 int timer;
 public:
	 WwwMode();
	 ~WwwMode();

	 virtual void Set();
	 virtual void Reset();
	 virtual void SetTimer();
	 virtual void FalseStart();
	 virtual bool UserButtonPushed(int pin);

	
 };