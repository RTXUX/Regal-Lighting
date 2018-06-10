#pragma once


class Unit;
/// <summary>
/// ººƒ‹¿‡
/// </summary>
class Skill
{
protected:
	Unit * host;
	int CD;
public:

	virtual Unit* getHost() const;

	virtual int getCd() const = 0;

	virtual int getLastCast() const = 0;

protected:
	int lastCast;
public:
	Skill();
	virtual int cast()=0;
	virtual bool isCastable()=0;
	virtual ~Skill();
};

