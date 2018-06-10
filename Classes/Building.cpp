#include "Building.h"


void Building::setAttackArea(const int attackArea)
{
	this->attackArea = attackArea;
}

int Building::getAttackArea() const
{
	return attackArea;
}

int Building::getSizeX() const
{
	return sizeX;
}

int Building::getSizeY() const
{
	return sizeY;
}

Building::Building(const int sizeX, const int sizeY): sizeX(sizeX),
                                                      sizeY(sizeY)
{
}

Building::Building()
{
}


Building::~Building()
{
}
