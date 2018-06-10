#pragma once
#include "Unit.h"



/// <summary>
/// ½ÇÉ«Àà
/// </summary>
/// <seealso cref="Unit" />
class Character :
	public Unit
{
protected:
	int baseMoveSpeed, effectiveMoveSpeed;

public:
	virtual void move(const int deltaX, const int deltaY);
	virtual int getBaseMoveSpeed() const;
	virtual void setBaseMoveSpeed(const int baseMoveSpeed);
	virtual int getEffectiveMoveSpeed() const;
	virtual void setEffectiveMoveSpeed(const int effectiveMoveSpeed);
	Character();
	virtual ~Character();
};

