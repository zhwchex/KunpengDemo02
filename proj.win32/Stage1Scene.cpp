#include "Stage1Scene.h"
#include "Stage1GameplayLayer.h"
#include "HeroSprite.h"
#include <iostream>

Stage1Scene::Stage1Scene()
{
}


Stage1Scene::~Stage1Scene()
{
}

Stage1Scene * Stage1Scene::create(){
	Stage1Scene * myScene = new Stage1Scene();
	if (myScene && myScene->init())
	{
		myScene->autorelease();
		return myScene;
	}
	else
	{
		CC_SAFE_DELETE(myScene);
		return nullptr;
	}
}

Stage1Scene * Stage1Scene::createScene(){
	return Stage1Scene::create();
}

bool Stage1Scene::init(){


	Size visibleSize = Director::getInstance()->getVisibleSize();
	Stage1GameplayLayer * gameplayLayer = Stage1GameplayLayer::create();
	gameplayLayer->setPosition(visibleSize.width/2,visibleSize.height/2);
	gameplayLayer->setTag(1);
	this->addChild(gameplayLayer);

	HeroSprite * kp = (HeroSprite*)gameplayLayer->getChildByTag(2);

	//keyboard listener
	EventListenerKeyboard* kbListener1 = EventListenerKeyboard::create();
	kbListener1->onKeyPressed = [this, gameplayLayer,kp](EventKeyboard::KeyCode keyCode, Event * event){
		if (keyCode == EventKeyboard::KeyCode::KEY_A) {
			this->key_A_down = true;
			this->updateHeroDirectionAndSetHimMoving();
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_S) { 
			this->key_S_down = true; 
			this->updateHeroDirectionAndSetHimMoving();
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_D) {
			this->key_D_down = true;
			this->updateHeroDirectionAndSetHimMoving();
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_W) {
			this->key_W_down = true;
			this->updateHeroDirectionAndSetHimMoving();
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_J) {
			this->key_J_down = true;
			HeroSprite * kp = (HeroSprite*)gameplayLayer->getChildByTag(2);
			kp->button1Hit();
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_K) {
			this->key_K_down = true;
			HeroSprite * kp = (HeroSprite*)gameplayLayer->getChildByTag(2);
			kp->button2Hit();
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_L) {
			this->key_L_down = true;
			HeroSprite * kp = (HeroSprite*)gameplayLayer->getChildByTag(2);
			kp->button3Hit();
		}
	};
	kbListener1->onKeyReleased = [this,gameplayLayer](EventKeyboard::KeyCode keyCode, Event * event){
		if (keyCode == EventKeyboard::KeyCode::KEY_A) {
			this->key_A_down = false;
			this->updateHeroDirectionAndSetHimMoving();
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_S) {
			this->key_S_down = false;
			this->updateHeroDirectionAndSetHimMoving();
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_D) {
			this->key_D_down = false;
			this->updateHeroDirectionAndSetHimMoving();
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_W) {
			this->key_W_down = false;
			this->updateHeroDirectionAndSetHimMoving();
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_J) {
			this->key_J_down = false;
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_K) {
			this->key_K_down = false;
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_L) {
			this->key_L_down = false;
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(kbListener1, this);


	this->schedule(schedule_selector(Stage1Scene::myUpdate));


	return true;
}

void Stage1Scene::updateHeroDirectionAndSetHimMoving(){
	Stage1GameplayLayer* gameplayLayer = (Stage1GameplayLayer*)this->getChildByTag(1);
	HeroSprite * kp = (HeroSprite*)gameplayLayer->getChildByTag(2);

	if (!this->key_W_down && !this->key_S_down && !this->key_A_down && this->key_D_down){
		kp->directionToMoveRight = true;
		kp->directionToMoveLeft = false;
		kp->directionToMoveUp = false;
		kp->directionToMoveDown = false;
		kp->directionToMoveUpRight = false;
		kp->directionToMoveUpLeft = false;
		kp->directionToMoveDownRight = false;
		kp->directionToMoveDownLeft = false;
	}
	if (!this->key_W_down && !this->key_S_down && this->key_A_down && !this->key_D_down){
		kp->directionToMoveRight = false;
		kp->directionToMoveLeft = true;
		kp->directionToMoveUp = false;
		kp->directionToMoveDown = false;
		kp->directionToMoveUpRight = false;
		kp->directionToMoveUpLeft = false;
		kp->directionToMoveDownRight = false;
		kp->directionToMoveDownLeft = false;
	}
	if (!this->key_W_down && this->key_S_down && !this->key_A_down && !this->key_D_down){
		kp->directionToMoveRight = false;
		kp->directionToMoveLeft = false;
		kp->directionToMoveUp = false;
		kp->directionToMoveDown = true;
		kp->directionToMoveUpRight = false;
		kp->directionToMoveUpLeft = false;
		kp->directionToMoveDownRight = false;
		kp->directionToMoveDownLeft = false;
	}
	if (this->key_W_down && !this->key_S_down && !this->key_A_down && !this->key_D_down){
		kp->directionToMoveRight = false;
		kp->directionToMoveLeft = false;
		kp->directionToMoveUp = true;
		kp->directionToMoveDown = false;
		kp->directionToMoveUpRight = false;
		kp->directionToMoveUpLeft = false;
		kp->directionToMoveDownRight = false;
		kp->directionToMoveDownLeft = false;
	}

	if (this->key_W_down && !this->key_S_down && !this->key_A_down && this->key_D_down){
		kp->directionToMoveRight = false;
		kp->directionToMoveLeft = false;
		kp->directionToMoveUp = false;
		kp->directionToMoveDown = false;
		kp->directionToMoveUpRight = true;
		kp->directionToMoveUpLeft = false;
		kp->directionToMoveDownRight = false;
		kp->directionToMoveDownLeft = false;
	}
	if (this->key_W_down && !this->key_S_down && this->key_A_down && !this->key_D_down){
		kp->directionToMoveRight = false;
		kp->directionToMoveLeft = false;
		kp->directionToMoveUp = false;
		kp->directionToMoveDown = false;
		kp->directionToMoveUpRight = false;
		kp->directionToMoveUpLeft = true;
		kp->directionToMoveDownRight = false;
		kp->directionToMoveDownLeft = false;
	}
	if (!this->key_W_down && this->key_S_down && this->key_A_down && !this->key_D_down){
		kp->directionToMoveRight = false;
		kp->directionToMoveLeft = false;
		kp->directionToMoveUp = false;
		kp->directionToMoveDown = false;
		kp->directionToMoveUpRight = false;
		kp->directionToMoveUpLeft = false;
		kp->directionToMoveDownRight = false;
		kp->directionToMoveDownLeft = true;
	}
	if (!this->key_W_down && this->key_S_down && !this->key_A_down && this->key_D_down){
		kp->directionToMoveRight = false;
		kp->directionToMoveLeft = false;
		kp->directionToMoveUp = false;
		kp->directionToMoveDown = false;
		kp->directionToMoveUpRight = false;
		kp->directionToMoveUpLeft = false;
		kp->directionToMoveDownRight = true;
		kp->directionToMoveDownLeft = false;
	}
	if (!this->key_W_down && !this->key_S_down && !this->key_A_down && !this->key_D_down){
		kp->directionToMoveRight = false;
		kp->directionToMoveLeft = false;
		kp->directionToMoveUp = false;
		kp->directionToMoveDown = false;
		kp->directionToMoveUpRight = false;
		kp->directionToMoveUpLeft = false;
		kp->directionToMoveDownRight = false;
		kp->directionToMoveDownLeft = false;
	}
	kp->move();
}

void Stage1Scene::myUpdate(float dt){
	Stage1GameplayLayer * gameplayLayer = (Stage1GameplayLayer*)this->getChildByTag(1);
	gameplayLayer->updateLayerPositionToMaintainHeroInCamera(0.1f,0.3f,0.1f);
	gameplayLayer->lockHeroWithinCamera();
	gameplayLayer->lockHeroWithinLandscape();
}
