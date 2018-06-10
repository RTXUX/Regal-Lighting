#pragma once

class Unit;



/// <summary>
/// ����Ч����
/// </summary>
class Buff
{
protected:
	Unit * host;
public:
	Buff(Unit* host);
	virtual bool shouldRemove()=0;
	virtual int remove()=0;
	virtual int enEffect()=0;
	virtual bool isEffective()=0;
	virtual bool disEffect()=0;
	virtual ~Buff();
};

