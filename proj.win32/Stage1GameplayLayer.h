#pragma once
#include "cocos2d.h"
#include "HeroSprite.h"
#include "GeneralUnit.h"
//#include "Bird_zwc.h"
#include "bird_yyh.h"
#include "Bullet.h"
#include "FishEnemy1.h"
#include "WaterSurface.h"
#include "WindBullet.h"
#include "Zhurong.h"

USING_NS_CC;
class Stage1GameplayLayer :	public Layer
{
public:

	WaterSurface * waterSurface = nullptr;

	HeroSprite * kunpeng = nullptr;
	Zhurong * zhurong = nullptr;

	const int detectBossX = 10500;
	bool heroHasTriggeredDetectBoss = false;

	Sprite * background = nullptr;
	static Stage1GameplayLayer * create();


	Vector<GeneralUnit * > enemyList = Vector<GeneralUnit *>();

	void onEnter();
	
	float positionRatioLeft = 0.4f;
	float positionRatioRight = 0.4f;
	float positionRatioUp = 0.5f;
	float positionRatioDown = 0.5f;
	float screenScrollingSpeedRatio = 0.1f;

	void updateLayerPositionToMaintainHeroInCamera(float positionRatioLeft, float positionRatioRight, float screenScrollingSpeedRatio);
	void updateLayerPositionToMaintainHeroInCamera();
	void pauseflagHeroWithinCamera();
	void pauseflagHeroWithinLandscape();


	Stage1GameplayLayer();
	~Stage1GameplayLayer();
};

