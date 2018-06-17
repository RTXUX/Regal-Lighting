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

public:
	RWorld* getInstance();
	RWorld* create();
	void destory();
	virtual list<shared_ptr<Unit>>& getUnitRegistry();
	virtual list<shared_ptr<Buff>>& getBuffRegistry();
};