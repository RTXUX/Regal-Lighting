#pragma once
#include "Character.h"
/// <summary>
/// Ӣ����
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
	 * \brief ֪ͨ����ֵ���ģ���Ҫ��������
	 */
	virtual void alterExperience();

	virtual int getExperience() const;
	virtual void setExperience(const int experience);
	/**
	 * \brief ����
	 * \return ����������ĵȼ�
	 */
	virtual int levelUp();
	virtual int getLevel() const;
	virtual void setLevel(const int level);
	Hero();
	Hero(int HP, int attack, int moveSpeed);
	virtual ~Hero();
};

