#pragma once


class Unit;
/// <summary>
/// 技能类
/// </summary>
class Skill
{
protected:
	Unit * host;
	int CD;
public:
	virtual Unit* getHost() const;
	virtual int getCd() const;
	virtual int getLastCast() const;
protected:
	int lastCast;
public:
	Skill(Unit* ht);
	virtual int cast()=0;
	virtual bool isCastable()=0;
	virtual ~Skill();
};
/**
 * \brief "试探"技能类
 * 技能类型：伤害
 * 范围：3格
 * 作用对象：小兵
 * 伤害：300
 */
class Probe :public Skill 
{
public:
	Probe(Unit* ht);
	virtual int cast();
	virtual bool isCastable();
};
/**
 * \brief "惩戒"技能类
 * 技能类型：伤害
 * 范围：3格
 * 作用对象：小兵
 * 伤害：650
 */
class Punishment :public Skill
{
public:
	Punishment(Unit* ht);
	virtual int cast();
	virtual bool isCastable();
};
/**
 * \brief "斩杀"技能类
 * 技能类型：伤害
 * 范围：5格
 * 作用对象：小兵与英雄
 * 伤害：已损失生命值12%
 */
class Execute :public Skill
{
public:
	Execute(Unit* ht);
	virtual int cast();
	virtual bool isCastable();
};
/**
 * \brief "狂暴"技能类
 * 技能类型：buff
 * 范围：单体
 * 作用对象：自身
 * 效果：增加攻击力30%，攻击速度60%持续5秒
 */
class Rage :public Skill
{
public:
	Rage(Unit* ht);
	virtual int cast();
	virtual bool isCastable();
};
/**
 * \brief "幽灵疾步"技能类
 * 技能类型：buff
 * 范围：单体
 * 作用对象：自身
 * 效果：增加移动速度30%持续5秒
 */
class Haste :public Skill
{
public:
	Haste(Unit* ht);
	virtual int cast();
	virtual bool isCastable();
};
/**
 * \brief "治疗术"技能类
 * 技能类型：治疗
 * 范围：5格
 * 作用对象：英雄与小兵
 * 效果：恢复自己与5格范围内所有我方人员已损失生命值的40%
 */
class Cure :public Skill
{
public:
	Cure(Unit* ht);
	virtual int cast();
	virtual bool isCastable();
};
