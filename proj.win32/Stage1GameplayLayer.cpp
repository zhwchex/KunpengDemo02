#pragma once
#include "Stage1GameplayLayer.h"
#include "HeroSprite.h"
#include "Stage1Scene.h"

#include "Bullet.h"


Stage1GameplayLayer::Stage1GameplayLayer()
{
	this->kunpeng = HeroSprite::create("characters/kunpeng/kunpeng.jpg");
	this->background = Sprite::create("backgrounds/background_wufan1.png");
	this->background->setAnchorPoint(Vec2(0,0.5));

	this->waterSurface = WaterSurface::create("landscapes/water_surface.png");
	
}


Stage1GameplayLayer::~Stage1GameplayLayer()
{
}

Stage1GameplayLayer * Stage1GameplayLayer::create(){
	Stage1GameplayLayer *ret = new (std::nothrow) Stage1GameplayLayer();
	if (ret && ret->init())
	{
		ret->autorelease();
		return ret;
	}
	else
	{
		CC_SAFE_DELETE(ret);
		return nullptr;
	}
}

void Stage1GameplayLayer::onEnter(){
	
	//Sprite * backgroundSprite = Sprite::create("backgrounds/sky_and_water_small.jpg");
	this->addChild(this->background);
	//HeroSprite * kp = HeroSprite::create("characters/kunpeng/peng.jpg");
	/*
	GeneralUnit * enemy1ForTest = GeneralUnit::create("characters/general_unit/general_unit.jpg");
	enemy1ForTest->camp = 2;
	enemy1ForTest->setPosition(300, 0);
	enemyList.pushBack(enemy1ForTest);
	this->addChild(enemy1ForTest);
	*/

	/*
	Bird_zwc * enemyZWC = Bird_zwc::create("characters/monster/peng_hovering_00.jpg");
	enemyZWC->camp = 2;
	enemyZWC->setPosition(600, 0);
	enemyList.pushBack(enemyZWC);
	enemyZWC->wanderAbout();
	this->addChild(enemyZWC);

	*/
	/*
	Bird_yyh * enemyYYH = Bird_yyh::create("characters/monster/peng_hovering_00.jpg");
	enemyYYH->camp = 2;
	enemyYYH->setPosition(600, 0);
	enemyList.pushBack(enemyYYH);
	enemyYYH->wanderAbout();
	this->addChild(enemyYYH);
	*/

	/*
	GeneralUnit *fish = FishEnemy1::create("enemyfish/enemyfish.png");
	fish->setPosition(Vec2(500, 0));
	this->addChild(fish);
	enemyList.pushBack(fish);
	*/
	
	
	Bird_yyh* bird1 = Bird_yyh::create("characters/Bird_yyh/left1.png");
	bird1->setPosition(300, 200);
	this->addChild(bird1);
	Bird_yyh* bird2 = Bird_yyh::create("characters/Bird_yyh/left1.png");
	bird2->setPosition(800, 200);
	this->addChild(bird2);
	//Bullet* bullet1 = Bullet::create(bird1);
	//this->addChild(bullet1, 1, "bu");
	//bird1->wanderAbout();
	enemyList.pushBack(bird1);
	enemyList.pushBack(bird2);
	/*
	Bird_yyh* bird2 = Bird_yyh::create("characters/Bird_yyh/bird1.jpg");
	bird2->setPosition(700, 200);
	this->addChild(bird2);
	Bullet* bullet2 = Bullet::create(bird2);
	this->addChild(bullet2, 1, "bu");
	//bird1->wanderAbout();
	enemyList.pushBack(bird2);

	Bird_yyh* bird3 = Bird_yyh::create("characters/Bird_yyh/bird1.jpg");
	bird3->setPosition(1100, 200);
	this->addChild(bird3);
	Bullet* bullet3 = Bullet::create(bird3);
	this->addChild(bullet3, 1, "bu");
	//bird1->wanderAbout();
	enemyList.pushBack(bird3);
	
	Bird_yyh* bird4 = Bird_yyh::create("characters/Bird_yyh/bird1.jpg");
	bird4->setPosition(1400, 200);
	this->addChild(bird4);
	Bullet* bullet4 = Bullet::create(bird3);
	this->addChild(bullet4, 1, "bu");
	//bird1->wanderAbout();
	enemyList.pushBack(bird4);
	*/
	
	Zhurong * zhurong = Zhurong::create("characters/zhurong/walking_left_while_facing_left_00.png");
	zhurong->setPosition(1800, 100);
	this->addChild(zhurong);
	enemyList.pushBack(zhurong);
	

	this->kunpeng->setTag(2);
	this->kunpeng->setPosition(Vec2(kunpeng->getContentSize().width ,kunpeng->getContentSize().height ));
	this->addChild(this->kunpeng);
	this->addChild(waterSurface, 1);
	Layer::onEnter();
}

//当地图增加纵向面积时，这里需要更改
void Stage1GameplayLayer::updateLayerPositionToMaintainHeroInCamera(float positionRatioLeft,  float positionRatioRight, float screenScrollingSpeedRatio){
	//Stage1Scene * scene = (Stage1Scene *)this->getParent();
	Size visibleSize = Director::getInstance()->getVisibleSize();
	int heroPositionInCameraX = this->getPositionX() + this->kunpeng->getPositionX();
	if (heroPositionInCameraX > visibleSize.width * positionRatioRight){
		int difference = heroPositionInCameraX - visibleSize.width * positionRatioRight;
		this->setPositionX(this->getPositionX() - screenScrollingSpeedRatio * difference);
	}

	if (heroPositionInCameraX < visibleSize.width * positionRatioLeft){
		int difference = heroPositionInCameraX - visibleSize.width * positionRatioLeft;
		this->setPositionX(this->getPositionX() - screenScrollingSpeedRatio * difference);
	}

}

void Stage1GameplayLayer::updateLayerPositionToMaintainHeroInCamera(){
	//Stage1Scene * scene = (Stage1Scene *)this->getParent();
	Size visibleSize = Director::getInstance()->getVisibleSize();
	int heroPositionInCameraX = this->getPositionX() + this->kunpeng->getPositionX();
	if (heroPositionInCameraX > visibleSize.width * this->positionRatioRight){
		int difference = heroPositionInCameraX - visibleSize.width * this->positionRatioRight;
		this->setPositionX(this->getPositionX() - this->screenScrollingSpeedRatio * difference);
	}

	if (heroPositionInCameraX < visibleSize.width * this->positionRatioLeft){
		int difference = heroPositionInCameraX - visibleSize.width * this->positionRatioLeft;
		this->setPositionX(this->getPositionX() - this->screenScrollingSpeedRatio * difference);
	}


	int heroPositionInCameraY = this->getPositionY() + this->kunpeng->getPositionY();

	if (heroPositionInCameraY > visibleSize.height * this->positionRatioUp){
		int heightDifference = heroPositionInCameraY - visibleSize.height * this->positionRatioUp;
		this->setPositionY(this->getPositionY() - this->screenScrollingSpeedRatio * heightDifference);
	}

	if (heroPositionInCameraY < visibleSize.height * this->positionRatioDown){
		int heightDifference = heroPositionInCameraY - visibleSize.height * this->positionRatioDown;
		this->setPositionY(this->getPositionY() - this->screenScrollingSpeedRatio * heightDifference);
	}



	/*
	if (this->getPositionX() > -20){
		this->setPositionX(0);
	}
	else if (this->getPositionX() < visibleSize.width - this->getContentSize().width){
		this->setPositionX(visibleSize.width - this->getContentSize().width);
	}
	
	if (this->getPositionY() > this->getContentSize().height * 0.5){
		this->setPositionY(this->getContentSize().height * 0.5);
	}
	else if (this->getPositionY() < visibleSize.height - 0.5 * this->getContentSize().height){
		this->setPositionY(visibleSize.height - 0.5 * this->getContentSize().height);
	}
	*/
}


//需要主角不超出镜头范围的时候，调用它。如果主角在视野外，则将主角挪到镜头内。
void Stage1GameplayLayer::pauseflagHeroWithinCamera(){
	Stage1Scene * scene = (Stage1Scene *)this->getParent();
	Size visibleSize = Director::getInstance()->getVisibleSize();

	int heroPositionInCameraX = this->getPositionX() + this->kunpeng->getPositionX();
	int heroPositionInCameraY = this->getPositionY() + this->kunpeng->getPositionY();

	if (heroPositionInCameraX > visibleSize.width){
		int difference = heroPositionInCameraX - visibleSize.width;
		this->kunpeng->setPositionX(this->kunpeng->getPositionX() - difference);
	}
	if (heroPositionInCameraX < 0){
		int difference = heroPositionInCameraX ;
		this->kunpeng->setPositionX(this->kunpeng->getPositionX() - difference);
	}
	if (heroPositionInCameraY > visibleSize.height){
		int difference = heroPositionInCameraY - visibleSize.height;
		this->kunpeng->setPositionY(this->kunpeng->getPositionY() - difference);
	}
	if (heroPositionInCameraY < 0){
		int difference = heroPositionInCameraY ;
		this->kunpeng->setPositionY(this->kunpeng->getPositionY() - difference);
	}
}

//当且仅当背景是长方形时，调用它可以让主角被限制在背景里
void Stage1GameplayLayer::pauseflagHeroWithinLandscape(){
	int heroPositionInLayerX = kunpeng->getPositionX();
	int heroPositionInLayerY = kunpeng->getPositionY();

	int backgroundPositionInLayerX = background->getPositionX();
	int backgroundPositionInLayerY = background->getPositionY();

	int backgroundWidth = background->getContentSize().width;
	int backgroundHeight = background->getContentSize().height;

	Vec2 backgroundAnchor = background->getAnchorPoint();
	float backgroundAnchorX = backgroundAnchor.x;
	float backgroundAnchorY = backgroundAnchor.y;

	int backgroundLeftBoundary = backgroundPositionInLayerX - backgroundWidth * backgroundAnchorX;
	int backgroundRightBoundary = backgroundPositionInLayerX + backgroundWidth *(1 - backgroundAnchorX);
	int backgroundUpBoundary = backgroundPositionInLayerY + backgroundHeight * (1 - backgroundAnchorY);
	int backgroundDownBoundary = backgroundPositionInLayerY - backgroundHeight *  backgroundAnchorY;

	if (heroPositionInLayerX > backgroundRightBoundary){
		int difference = heroPositionInLayerX - backgroundRightBoundary;
		kunpeng->setPositionX(kunpeng->getPositionX() - difference);
	}
	if (heroPositionInLayerX < backgroundLeftBoundary){
		int difference = heroPositionInLayerX - backgroundLeftBoundary;
		kunpeng->setPositionX(kunpeng->getPositionX() - difference);
	}
	if (heroPositionInLayerY > backgroundUpBoundary){
		int difference = heroPositionInLayerY - backgroundUpBoundary;
		kunpeng->setPositionY(kunpeng->getPositionY() - difference);
	}
	if (heroPositionInLayerY < backgroundDownBoundary){
		int difference = heroPositionInLayerY - backgroundDownBoundary;
		kunpeng->setPositionY(kunpeng->getPositionY() - difference);
	}
}

