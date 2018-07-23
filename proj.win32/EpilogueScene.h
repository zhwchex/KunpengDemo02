#pragma once
#include "cocos2d.h"
#include "AudioManager.h"
USING_NS_CC;
class EpilogueScene :public Scene
{
public:
	void restartGameCallBack(Ref* pSender);

	Sprite * thankU;
	Sprite * gonggongNotDoneYet;

	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);


	void goToStage2SceneCallback(Ref * pSender);
	// implement the "static create()" method manually
	CREATE_FUNC(EpilogueScene);

	EpilogueScene();
	~EpilogueScene();
};

