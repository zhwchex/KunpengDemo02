#pragma once
#include "cocos2d.h"

USING_NS_CC;
class WaterSurface :public Sprite
{
public:

	//int magazineX = -100;
	//int magazineY = -100;

	static WaterSurface * create(const std::string & filename);

	void onEnter();

	void myUpdate(float dt);
	WaterSurface();
	~WaterSurface();
};

