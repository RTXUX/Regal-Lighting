#pragma once
#include "Character.h"
/// <summary>
/// 英雄类
/// </summary>
/// <seealso cref="Character" />
class Hero :
	public Character
{
protected:
	int level;
	int experience;
public:
	/**
	 * \brief 通知经验值更改，主要处理升级
	 */
	virtual void alterExperience();

	virtual int getExperience() const;
	virtual void setExperience(const int experience);
	/**
	 * \brief 升级
	 * \return 返回升级后的等级
	 */
	virtual int levelUp();
	virtual int getLevel() const;
	virtual void setLevel(const int level);
	Hero();
	Hero(int HP, int attack, int moveSpeed);
	virtual ~Hero();
};

