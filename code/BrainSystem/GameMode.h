#pragma once
class GameMode {
private:
	int pin;
	bool isFalseStart = true;

public:	
	virtual void Set();
	virtual void Reset();
	virtual void SetTimer();
	virtual void FalseStart();
	void SetPin(int pin);
	virtual bool UserButtonPushed(int pin);
	int GetPin();	
	bool GetFalseStart();
	void SetFalseStart(bool value);
};