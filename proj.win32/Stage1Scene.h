#pragma once
#include "D:\cocos_workspace\KunpengDemo02\cocos2d\cocos\2d\CCScene.h"
#include "cocos2d.h"
#include "HeroSprite.h"
USING_NS_CC;
class Stage1Scene :	public Scene
{
public:
	

	bool key_A_down = false;
	bool key_D_down = false;
	bool key_W_down = false;
	bool key_S_down = false;

	bool key_J_down = false;
	bool key_K_down = false;
	bool key_L_down = false;

	static Stage1Scene * create();
	static Stage1Scene * createScene();
	void updateHeroDirectionAndSetHimMoving();
	bool init();

	void myUpdate(float dt);
	Stage1Scene();
	~Stage1Scene();
};

