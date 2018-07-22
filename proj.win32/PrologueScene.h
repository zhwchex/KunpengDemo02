#pragma once
#include "cocos2d.h"

USING_NS_CC;

class PrologueScene : public cocos2d::Scene
{
public:

	void restartGameCallBack(Ref* pSender);

	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);


	void goToStage1SceneCallback(Ref * pSender);
	// implement the "static create()" method manually
	CREATE_FUNC(PrologueScene);
};