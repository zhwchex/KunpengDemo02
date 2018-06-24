#pragma once
//#include "D:\cocos_workspace\KunpengDemo02\cocos2d\cocos\2d\CCSprite.h"
#include "cocos2d.h"
USING_NS_CC;
class GeneralEnemy :public Sprite
{
public:

	int health;

	void wanderAbout();
	void getHurt();
	void die();

	static GeneralEnemy * create(const std::string & filename);

	GeneralEnemy();
	~GeneralEnemy();
};

