#pragma once
#include <list>
#include "Skill.h"
#include "Buff.h"
#include <memory>
#include <string>
#include "cocos2d.h"
/// <summary>
/// 单位类
/// </summary>
class Unit
{
protected:
	int id;
	std::string name;
	int baseHP, effectiveHP;
	cocos2d::Sprite* sprite = nullptr;

	/**
	 * \brief 阵营：1为P1，2为P2
	 */
	int side;
public:
	virtual int getSide() const;
	virtual void setSide(const int side);
	virtual cocos2d::Sprite* getSprite() const;
	virtual void setSprite(cocos2d::Sprite* const sprite);
protected:
	/**
	 * \brief 此单位拥有的技能
	 */
	std::list<std::shared_ptr<Skill>> skills;

	/**
	 * \brief 此单位拥有的Buff
	 */
	std::list<std::shared_ptr<Buff>> buffs;
	int baseAttack, effectiveAttack;
public:
	virtual cocos2d::Point getPosition();
	virtual void addBuff(const Buff * const buff);
	virtual void addSkill(const std::shared_ptr<Skill>& skill);
	virtual void setId(const int id);
	virtual void setName(const std::string& name);
	virtual void setBaseHp(const int baseHp);
	virtual void setEffectiveHp(const int effectiveHp);
	virtual void setBaseAttack(const int baseAttack);
	virtual void setEffectiveAttack(const int effectiveAttack);
	virtual int getId() const;
	virtual const std::string& getName() const;
	virtual int getBaseHp() const;
	virtual int getEffectiveHp() const;
	virtual std::list<std::shared_ptr<Skill>>& getSkills();
	virtual std::list<std::shared_ptr<Buff>>& getBuffs();
	virtual int getBaseAttack() const;
	virtual int getEffectiveAttack() const;
	Unit();
	virtual ~Unit();
};

