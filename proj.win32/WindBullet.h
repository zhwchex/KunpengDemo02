#pragma once
#include "cocos2d.h"
USING_NS_CC;
class WindBullet :public Sprite
{
public:

	int magazineX = -100;
	int magazineY = -100;


	static WindBullet * create(const std::string & filename);

	WindBullet();
	~WindBullet();
};

