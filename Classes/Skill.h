#pragma once


class Unit;
/// <summary>
/// ������
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
 * \brief "��̽"������
 * �������ͣ��˺�
 * ��Χ��3��
 * ���ö���С��
 * �˺���300
 */
class Probe :public Skill 
{
public:
	Probe(Unit* ht);
	virtual int cast();
	virtual bool isCastable();
};
/**
 * \brief "�ͽ�"������
 * �������ͣ��˺�
 * ��Χ��3��
 * ���ö���С��
 * �˺���650
 */
class Punishment :public Skill
{
public:
	Punishment(Unit* ht);
	virtual int cast();
	virtual bool isCastable();
};
/**
 * \brief "նɱ"������
 * �������ͣ��˺�
 * ��Χ��5��
 * ���ö���С����Ӣ��
 * �˺�������ʧ����ֵ12%
 */
class Execute :public Skill
{
public:
	Execute(Unit* ht);
	virtual int cast();
	virtual bool isCastable();
};
/**
 * \brief "��"������
 * �������ͣ�buff
 * ��Χ������
 * ���ö�������
 * Ч�������ӹ�����30%�������ٶ�60%����5��
 */
class Rage :public Skill
{
public:
	Rage(Unit* ht);
	virtual int cast();
	virtual bool isCastable();
};
/**
 * \brief "���鼲��"������
 * �������ͣ�buff
 * ��Χ������
 * ���ö�������
 * Ч���������ƶ��ٶ�30%����5��
 */
class Haste :public Skill
{
public:
	Haste(Unit* ht);
	virtual int cast();
	virtual bool isCastable();
};
/**
 * \brief "������"������
 * �������ͣ�����
 * ��Χ��5��
 * ���ö���Ӣ����С��
 * Ч�����ָ��Լ���5��Χ�������ҷ���Ա����ʧ����ֵ��40%
 */
class Cure :public Skill
{
public:
	Cure(Unit* ht);
	virtual int cast();
	virtual bool isCastable();
};
