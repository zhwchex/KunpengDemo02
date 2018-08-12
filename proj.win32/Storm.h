#pragma once
#include "cocos2d.h"
#include "Stage1GameplayLayer.h"
#include "AudioManager.h"

USING_NS_CC;
using namespace std;
static const string STROM_FILE_NAME = "audios/monster_hurt.mp3";

class Storm : public GeneralUnit
{
public:
	static Storm* create(const std::string & filename);

	void onEnter();

	void myUpdate(float dt);
	void wanderAbout();//for test

	void setPlace(int X, bool inTheSky);//…Ë÷√’œ∞≠¿‡–Õ£¨£®£©

	void Lockhoving();

	int lock = 0;

	Storm();
	~Storm();

	Animation * hoveringAnimation;

};



