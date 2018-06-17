#include "Character.h"



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
