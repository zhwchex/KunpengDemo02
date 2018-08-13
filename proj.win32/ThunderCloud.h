#pragma once
#include "cocos2d.h"
#include "Stage1GameplayLayer.h"
#include "AudioManager.h"

USING_NS_CC;
using namespace std;
static const string THUNDERCLOUD_FILE_NAME = "audios/monster_hurt.mp3";

class ThunderCloud : public GeneralUnit
{
public:
	static ThunderCloud* create(const std::string & filename);

	void onEnter();

	void myUpdate(float dt);
	void wanderAbout();//for test

	void setPlace(int X, bool inTheSky);//…Ë÷√’œ∞≠¿‡–Õ£¨£®£©

	void Lockhoving();

	int lock = 0;
	
	ThunderCloud();
	~ThunderCloud();

	Animation * hoveringAnimation;

};




