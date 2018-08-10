#pragma once
#include "cocos2d.h"
#include "Stage1GameplayLayer.h"

USING_NS_CC;
class Rock : public GeneralUnit
{
public:
	static Rock* create(const std::string & filename);

	void onEnter();

	void myUpdate(float dt);
	void wanderAbout();//for test

	void setPlace(int X, bool inTheSky);//…Ë÷√’œ∞≠¿‡–Õ£¨£®£©

	void Lockhoving();

	int lock = 0;

	Rock();
	~Rock();

	Animation * hoveringAnimation;

};


