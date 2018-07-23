#include "Stage1Scene.h"
#include "Stage1GameplayLayer.h"
#include "Stage1UILayer.h"
#include "EpilogueScene.h"
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

	Stage1UILayer * uiLayer = Stage1UILayer::create();
	uiLayer->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	uiLayer->setTag(2);
	this->addChild(uiLayer);

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
	kp->move_forBothShapes();
}

void Stage1Scene::myUpdate(float dt){
	Stage1GameplayLayer * gameplayLayer = (Stage1GameplayLayer*)this->getChildByTag(1);
	HeroSprite * kp = gameplayLayer->kunpeng;
	Zhurong * zhurong = gameplayLayer->zhurong;

	Stage1UILayer * uiLayer = (Stage1UILayer*)this->getChildByTag(2);
	
	Vector <GeneralUnit*> enemyList = gameplayLayer->enemyList;
	for (GeneralUnit * enemy1 : enemyList){
		enemy1->wanderAbout();
	}


	gameplayLayer->updateLayerPositionToMaintainHeroInCamera();
	gameplayLayer->pauseflagHeroWithinCamera();
	gameplayLayer->pauseflagHeroWithinLandscape();

	double heroHPScale = 1.0 * kp->health / kp->FULL_HP;
	if (heroHPScale < 0) heroHPScale = 0;
	uiLayer->heroHPBar->setScaleX(heroHPScale);

	double bossHPScale = 1.0 * zhurong->health / 10000;//0.5;//TODO. Need modification.
	if (bossHPScale < 0) bossHPScale = 0;
	uiLayer->bossHPBar->setScaleX(bossHPScale);

	if (kp->isBird){
		uiLayer->head_kun->setVisible(false);
		uiLayer->head_peng->setVisible(true);
	}
	else{
		uiLayer->head_kun->setVisible(true);
		uiLayer->head_peng->setVisible(false);
	}



	if (!gameplayLayer->heroHasTriggeredDetectBoss && kp->getPositionX() > gameplayLayer->detectBossX){
		//uiLayer->bossName->setOpacity(128);
		//uiLayer->bossHPBarShell->setOpacity(128);
		//uiLayer->bossHPBar->setOpacity(128);

		uiLayer->bossName->runAction(FadeIn::create(1));
		uiLayer->bossHPBarShell->runAction(FadeIn::create(1));
		uiLayer->bossHPBar->runAction(FadeIn::create(1));
		gameplayLayer->heroHasTriggeredDetectBoss = true;
	}

	if ( !gameplayLayer->heroHasTriggeredHint1 && kp->getPositionX() > gameplayLayer->detectHint1){
		gameplayLayer->tutorial_trans_btf->runAction(FadeIn::create(1));
		gameplayLayer->heroHasTriggeredHint1 = true;
	}
	if (!gameplayLayer->heroHasTriggeredHint2 && kp->getPositionX() > gameplayLayer->detectHint2){
		gameplayLayer->tutorial_trans_ftb->runAction(FadeIn::create(1));
		gameplayLayer->heroHasTriggeredHint2 = true;
	}
	if (!gameplayLayer->heroHasTriggeredHint3 && kp->getPositionX() > gameplayLayer->detectHint3){
		gameplayLayer->tutorial_delegate_explore->runAction(FadeIn::create(1));
		gameplayLayer->heroHasTriggeredHint3 = true;
	}

	if (!uiLayer->invincibleHintHasBeenDisplayed && kp->health < kp->FULL_HP / 2){
		uiLayer->invincibleHint->runAction(Repeat::create(Sequence::create(FadeIn::create(0.5),DelayTime::create(1),FadeOut::create(0.5),nullptr),3));
		uiLayer->invincibleHintHasBeenDisplayed = true;
	}

	if (!uiLayer->missionCompleteHasBeenDiaplayed && zhurong->health <= 0){
		uiLayer->missionCompleteHasBeenDiaplayed = true;
		uiLayer->invincibleHint->setVisible(false);
		Action * curtainFadeIn = TargetedAction::create(uiLayer->blackCurtain, FadeIn::create(5));
		uiLayer->missionComplete->runAction(Sequence::create(DelayTime::create(1), FadeIn::create(1.5), curtainFadeIn, CallFunc::create([]{
			log("now jumping to next scene");
			Director::getInstance()->replaceScene(EpilogueScene::createScene());
		}), nullptr));
	}
}
