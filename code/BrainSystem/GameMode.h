#pragma once
class GameMode {
private:
	int pin;

public:	
	virtual void Set();
	virtual void Reset();
	virtual void SetTimer();
	void SetPin(int pin);
	int GetPin();	
};