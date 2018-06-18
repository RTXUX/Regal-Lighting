#include "Unit.h"
#include "RWorld.h"


cocos2d::Sprite* Unit::getSprite() const
{
	sprite->retain();
	return sprite;
}

cocos2d::Point Unit::getPosition()
{
	return this->sprite->getPosition();
}

void Unit::setSprite(cocos2d::Sprite* const sprite)
{
	if (this->sprite!=nullptr)
	{
		this->sprite->release();
	}
	sprite->retain();
	this->sprite = sprite;
}

/**
 * \brief 为单位添加一个Buff
 * \param buff 要添加的Buff的指针
 */
void Unit::addBuff(const Buff* const buff)
{
	
}

/**
 * \brief 为单位添加一个技能
 * \param skill 要添加的技能的指针
 */
void Unit::addSkill(const Skill* const skill)
{
	
}

void Unit::setId(const int id)
{
	this->id = id;
}

void Unit::setName(const std::string& name)
{
	this->name = name;
}

void Unit::setBaseHp(const int baseHp)
{
	baseHP = baseHp;
}

void Unit::setEffectiveHp(const int effectiveHp)
{
	effectiveHP = effectiveHp;
}

void Unit::setBaseAttack(const int baseAttack)
{
	this->baseAttack = baseAttack;
}

void Unit::setEffectiveAttack(const int effectiveAttack)
{
	this->effectiveAttack = effectiveAttack;
}

int Unit::getId() const
{
	return id;
}

const std::string& Unit::getName() const
{
	return name;
}

int Unit::getBaseHp() const
{
	return baseHP;
}

int Unit::getEffectiveHp() const
{
	return effectiveHP;
}


std::list<std::shared_ptr<Skill>>& Unit::getSkills()
{
	return skills;
}

std::list<std::shared_ptr<Buff>>& Unit::getBuffs()
{
	return buffs;
}

int Unit::getBaseAttack() const
{
	return baseAttack;
}

int Unit::getEffectiveAttack() const
{
	return effectiveAttack;
}

Unit::Unit()
{
	RWorld::getInstance()->getUnitRegistry().emplace_back(this);
}


Unit::~Unit()
{
}
