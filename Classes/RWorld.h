#pragma once
#include "Hero.h"
#include "Buff.h"
#include "Unit.h"
#include "Skill.h"
#include <list>
using namespace std;
class RWorld
{
protected:
	list<shared_ptr<Unit>> unitRegistry;
	static RWorld* instance;
	list<shared_ptr<Buff>> buffRegistry;
	float time = 0;

public:
	virtual float getTime() const;
	virtual void setTime(const float time);
	static RWorld* getInstance();
	static RWorld* create();
	static void destory();
	virtual list<shared_ptr<Unit>>& getUnitRegistry();
	virtual list<shared_ptr<Buff>>& getBuffRegistry();
};