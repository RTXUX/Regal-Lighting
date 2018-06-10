#include "Hero.h"


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
