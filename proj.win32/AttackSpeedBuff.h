#pragma once
#include "Buff.h"
class AttackSpeedBuff :
	public Buff
{
public:
	AttackSpeedBuff();
	~AttackSpeedBuff();
	bool shouldRemove();
	int remove();
	int enEffect();
	bool isEffective();
	bool disEffect();
	int getDuration() const;
	void decreaseDuration(int sec);
private:
	int effectiveAttackSpeed;
	int duration;
};

