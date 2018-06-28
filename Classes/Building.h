#pragma once
#include "Unit.h"
/// <summary>
/// ½¨ÖþÀà
/// </summary>
/// <seealso cref="Unit" />
class Building :
	public Unit
{
protected:
	int sizeX, sizeY;
	int attackArea;
public:
	virtual void setAttackArea(const int attackArea);
	virtual int getAttackArea() const;
	virtual int getSizeX() const;
	virtual int getSizeY() const;
	virtual void destruct()=0;

	Building(const int sizeX, const int sizeY);

	Building();
	virtual ~Building();
};