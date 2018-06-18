#include "Hero.h"


void Hero::alterExperience()
{
}

int Hero::levelUp()
{
	return 0; // just for mock.
}

int Hero::getExperience() const
{
	return experience;
}

void Hero::setExperience(const int experience)
{
	this->experience = experience;
}

int Hero::getLevel() const
{
	return level;
}


Hero::Hero(int HP, int attack, int moveSpeed)
{
	this->setBaseHp(HP);
	this->setBaseAttack(attack);
	this->setBaseMoveSpeed(moveSpeed);
}

void Hero::setLevel(const int level)
{
	this->level = level;
}

Hero::Hero()
{
}


Hero::~Hero()
{
}
