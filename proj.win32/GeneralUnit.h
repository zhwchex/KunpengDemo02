#pragma once
#include "cocos2d.h"
USING_NS_CC;
class GeneralUnit :public Sprite
{
public:

	//血量
	int health;


	//阵营。同一个阵营的单位攻击不到彼此，不同阵营的单位彼此为敌。暂定主角阵营是1，小怪阵营是2。
	int camp;


	//这4个接口是需要暴露出来的
	virtual void wanderAbout() {}//AI由你们写。我每帧都调用这个方法
	
	virtual void getHurt(int damage) {}
	void getHurtByWind(int damage);//由我来调用
	virtual void getHurtByPaw(int damage){}
	void getHurtByCrush(int damage);

	void getHurtByWater(int damage);
	void getHurtByFin(int damage);

	virtual void die() {}

	static GeneralUnit * create(const std::string & filename);

	GeneralUnit();
	~GeneralUnit();
};

