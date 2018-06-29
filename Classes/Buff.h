#pragma once
#include "Unit.h"
#include "RWorld.h"
class Unit;

namespace Buffs {
	class Buff;
	class AttackPowerBuff;
	class AttackSpeedBuff;
	class MovingSpeedBuff;
}

/// <summary>
/// 增益效果类
/// </summary>
class Buff
{
protected:
	bool effective;
	Unit * host;
	float effectiveTime;
	int duration;
	int effectiveValue;
public:
	Buff(Unit* host, int duration);
	virtual bool shouldRemove()=0;
	virtual int remove()=0;
	virtual int enEffect()=0;
	virtual bool isEffective()=0;
	virtual bool disEffect()=0;
	int getTimeLeft() const;
	float getEffectiveTime() const;
	virtual ~Buff();
};

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
};

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
};

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
};
