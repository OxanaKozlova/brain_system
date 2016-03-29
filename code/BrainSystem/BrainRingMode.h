#pragma once
#include "GameMode.h"
#include "Constants.h"

#define FIRST_TIMER 20
#define SECOND_TIMER 10
class BrainRingMode : public GameMode {
private: 
	int setPushes;
	int firstTimer;
	int seconedTimer;
	int timer;
	
	
public:
	BrainRingMode();
	~BrainRingMode();

	virtual void Set();
	virtual void Reset();
	virtual void SetTimer();
	virtual void FalseStart();
	void CheckTimeLeft(int timeLeft);
	virtual bool UserButtonPushed(int pin);
};