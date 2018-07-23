#pragma once
//#include "D:\cocos_workspace\KunpengDemo02\cocos2d\cocos\2d\CCLayer.h"
#include "cocos2d.h"
#include "AudioManager.h"

USING_NS_CC;
class Stage1UILayer :	public Layer
{
public:
	int score = 0;

	void onEnter();

	Sprite * heroHPBar = nullptr;
	Sprite * heroHPBarShell = nullptr;
	Sprite * bossHPBar = nullptr;
	Sprite * bossHPBarShell = nullptr;
	Sprite * bossName = nullptr;

	Sprite * head_kun = nullptr;
	Sprite * head_peng = nullptr;


	Sprite * invincibleHint = nullptr;
	Sprite * blackCurtain = nullptr;
	Sprite * missionComplete = nullptr;

	bool invincibleHintHasBeenDisplayed = false;
	bool blackCurtainHasBeenDisplayed = false;
	bool missionCompleteHasBeenDiaplayed = false;

	static Stage1UILayer * create();
	Stage1UILayer();
	~Stage1UILayer();
};

