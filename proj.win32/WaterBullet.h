#pragma once
#include "cocos2d.h"
USING_NS_CC;
class WaterBullet :public Sprite
{
public:

	int magazineX = -100;
	int magazineY = -100;

	static WaterBullet * create(const std::string & filename);

	WaterBullet();
	~WaterBullet();
};

