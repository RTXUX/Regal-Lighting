#pragma once
#include "Buff.h"
class AttackPowerBuff :
	public Buff
{
public:
	AttackPowerBuff();
	~AttackPowerBuff();
	bool shouldRemove();
	int remove();
	int enEffect();
	bool isEffective();
	bool disEffect();
	int getDuration() const;
	void decreaseDuration(int sec);
private:
	int effectiveAttackPower;
	int duration;
};

