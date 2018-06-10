#include "Unit.h"


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
	buffs.emplace_back(buff);
}

/**
 * \brief 为单位添加一个技能
 * \param skill 要添加的技能的指针
 */
void Unit::addSkill(const Skill* const skill)
{
	skills.emplace_back(skill);
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


const std::list<std::shared_ptr<Skill>>& Unit::getSkills() const
{
	return skills;
}

const std::list<std::shared_ptr<Buff>>& Unit::getBuffs() const
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
}


Unit::~Unit()
{
}
