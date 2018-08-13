#pragma once
#include "cocos2d.h"
#include "Stage1GameplayLayer.h"
#include "AudioManager.h"

USING_NS_CC;
using namespace std;
static const string ROCK_FILE_NAME = "landscapes/jiaoshi_5.png";

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


