#pragma once
#include "cocos2d.h"
#include "HeroSprite.h"
#include "GeneralUnit.h"
//#include "Bird_zwc.h"
#include "bird_yyh.h"
#include "Bullet.h"
#include "FishEnemy1.h"

USING_NS_CC;
class Stage1GameplayLayer :	public Layer
{
public:

	Sprite * waterSurface = nullptr;

	HeroSprite * kunpeng = nullptr;
	Sprite * background = nullptr;
	static Stage1GameplayLayer * create();


	Vector<GeneralUnit * > enemyList = Vector<GeneralUnit *>();

	void onEnter();
	
	float positionRatioLeft = 0.1f;
	float positionRatioRight = 0.3f;
	float positionRatioUp = 0.1f;
	float positionRatioDown = 0.3f;
	float screenScrollingSpeedRatio = 0.1f;

	void updateLayerPositionToMaintainHeroInCamera(float positionRatioLeft, float positionRatioRight, float screenScrollingSpeedRatio);
	void updateLayerPositionToMaintainHeroInCamera();
	void lockHeroWithinCamera();
	void lockHeroWithinLandscape();


	Stage1GameplayLayer();
	~Stage1GameplayLayer();
};

