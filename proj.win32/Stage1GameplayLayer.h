#pragma once
//#include "D:\cocos_workspace\KunpengDemo02\cocos2d\cocos\2d\CCLayer.h"
#include "cocos2d.h"
#include "HeroSprite.h"
USING_NS_CC;
class Stage1GameplayLayer :	public Layer
{
public:

	HeroSprite * kunpeng = nullptr;
	Sprite * background = nullptr;
	static Stage1GameplayLayer * create();

	void onEnter();


	void updateLayerPositionToMaintainHeroInCamera(float positionRatioLeft, float positionRatioRight, float screenScrollingSpeedRatio);
	void lockHeroWithinCamera();
	void lockHeroWithinLandscape();


	Stage1GameplayLayer();
	~Stage1GameplayLayer();
};

