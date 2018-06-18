#include "RWorld.h"

RWorld *RWorld::instance = nullptr;

float RWorld::getTime() const
{
	return time;
}

void RWorld::setTime(const float time)
{
	this->time = time;
}

RWorld* RWorld::getInstance()
{
	return instance;
}

RWorld* RWorld::create()
{
	instance = new RWorld();
	return instance;
}

void RWorld::destory()
{
	delete instance;
	instance = nullptr;
}

list<shared_ptr<Unit>>& RWorld::getUnitRegistry()
{
	return unitRegistry;
}

list<shared_ptr<Buff>>& RWorld::getBuffRegistry()
{
	return buffRegistry;
}
