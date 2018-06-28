#pragma once
#include "Buff.h"
class MovingSpeedBuff :
	public Buff
{
public:
	MovingSpeedBuff();
	~MovingSpeedBuff();
	bool shouldRemove();
	int remove();
	int enEffect();
	bool isEffective();
	bool disEffect();
	int getDuration() const;
	void decreaseDuration(int sec);
private:
	int effectiveMovingSpeed;
	int duration;
};

