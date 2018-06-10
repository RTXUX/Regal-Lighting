#include "Character.h"


void Character::move(const int deltaX, const int deltaY)
{
	X += deltaX;
	Y += deltaY;
}

int Character::getBaseMoveSpeed() const
{
	return baseMoveSpeed;
}

void Character::setBaseMoveSpeed(const int baseMoveSpeed)
{
	this->baseMoveSpeed = baseMoveSpeed;
}

int Character::getEffectiveMoveSpeed() const
{
	return effectiveMoveSpeed;
}

void Character::setEffectiveMoveSpeed(const int effectiveMoveSpeed)
{
	this->effectiveMoveSpeed = effectiveMoveSpeed;
}

Character::Character()
{
}


Character::~Character()
{
}
