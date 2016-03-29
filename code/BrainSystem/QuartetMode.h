#pragma once
#include "GameMode.h"
#include "Constants.h"

class QuartetMode : public GameMode{
private:
	int timer;
public:
	QuartetMode();
	~QuartetMode();

	virtual void Set();
	virtual void Reset();
	virtual void SetTimer();
	virtual void FalseStart();
	virtual bool UserButtonPushed(int pin, bool isPushed);

};