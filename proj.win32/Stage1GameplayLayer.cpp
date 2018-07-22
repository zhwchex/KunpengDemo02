#pragma once
#include "Stage1GameplayLayer.h"
#include "HeroSprite.h"
#include "Stage1Scene.h"
#include "EnemyFish.h"
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

	this->kunpeng->setTag(2);
	this->kunpeng->setPosition(400, 200);
	this->addChild(this->kunpeng);
	this->addChild(waterSurface, 1);


	Sprite * tutorial_motion = Sprite::create("tutorial/tutorial_motion.png");
	tutorial_motion->setPosition(700, 300);
	this->addChild(tutorial_motion);

	Sprite * tutorial_jk = Sprite::create("tutorial/tutorial_jk.png");
	tutorial_jk->setPosition(700, -300);
	this->addChild(tutorial_jk);

	Sprite * tutorial_trans_btf = Sprite::create("tutorial/tutorial_trans_btf.png");
	tutorial_trans_btf->setPosition(1400, 100);
	this->addChild(tutorial_trans_btf);

	Sprite * tutorial_trans_ftb = Sprite::create("tutorial/tutorial_trans_ftb.png");
	tutorial_trans_ftb->setPosition(2400, -200);
	this->addChild(tutorial_trans_ftb);

	Sprite * tutorial_delegate_explore = Sprite::create("tutorial/tutorial_delegate_explore.png");
	tutorial_delegate_explore->setPosition(3800, 0);
	this->addChild(tutorial_delegate_explore);

	/*
	Sprite * kunzhidabuzhiqijiqianliye = Sprite::create("tutorial/kunzhidabuzhiqijiqianliye.png");
	kunzhidabuzhiqijiqianliye->setPosition(2200,-250);
	this->addChild(kunzhidabuzhiqijiqianliye);

	Sprite * huaerwei = Sprite::create("tutorial/huaerwei.png");
	huaerwei->setPosition(2600,-50);
	this->addChild(huaerwei);

	Sprite * ftb_transform_t = Sprite::create("tutorial/transform_ftb_tutorial.png");
	ftb_transform_t->setPosition(3200,100);
	this->addChild(ftb_transform_t);


	Sprite * niao = Sprite::create("tutorial/niao.png");
	niao->setPosition(3800,200);
	this->addChild(niao);

	Sprite * qimingweipeng = Sprite::create("tutorial/qimingweipeng.png");
	qimingweipeng->setPosition(4000,200);
	this->addChild(qimingweipeng);

	Sprite * penzhibeibuzhiqijiqianliye = Sprite::create("tutorial/pengzhibeibuzhiqijiqianliye.png");
	penzhibeibuzhiqijiqianliye->setPosition(4400,300);
	this->addChild(penzhibeibuzhiqijiqianliye);

	Sprite * nuerfei = Sprite::create("tutorial/pengzhibeibuzhiqijiqianliye.png");
	nuerfei->setPosition(4800, 300);
	this->addChild(nuerfei);
	*/



	//Sprite * backgroundSprite = Sprite::create("backgrounds/sky_and_water_small.jpg");
	this->addChild(this->background,-1);
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

	/**/
	GeneralUnit *fishljj = EnemyFish::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishljj->setPosition(Vec2(500, -200));
	this->addChild(fishljj);
	enemyList.pushBack(fishljj);

	GeneralUnit *fishcw = FishEnemy1::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishcw->setPosition(Vec2(600, 0));
	this->addChild(fishcw);
	enemyList.pushBack(fishcw);


	
	Bird_yyh* bird1 = Bird_yyh::create("characters/Bird_yyh/left1.png");
	bird1->setPosition(300, 200);
	this->addChild(bird1);
	Bird_yyh* bird2 = Bird_yyh::create("characters/Bird_yyh/left1.png");
	bird2->setPosition(800, 200);
	this->addChild(bird2);

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
	
	
	this->zhurong = Zhurong::create("characters/zhurong/walking_left_while_facing_left_00.png");
	zhurong->setPosition(11500, 100);
	this->addChild(zhurong);
	enemyList.pushBack(zhurong);
	

	
	
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

	int backgroundPositionInLayerX = background->getPositionX();
	int backgroundPositionInLayerY = background->getPositionY();

	int backgroundWidth = background->getContentSize().width;
	int backgroundHeight = background->getContentSize().height;

	Vec2 backgroundAnchor = background->getAnchorPoint();
	float backgroundAnchorX = backgroundAnchor.x;
	float backgroundAnchorY = backgroundAnchor.y;

	int backgroundLeftBoundaryInLayer = backgroundPositionInLayerX - backgroundWidth * backgroundAnchorX;
	int backgroundRightBoundaryInLayer = backgroundPositionInLayerX + backgroundWidth *(1 - backgroundAnchorX);
	int backgroundUpBoundaryInLayer = backgroundPositionInLayerY + backgroundHeight * (1 - backgroundAnchorY);
	int backgroundDownBoundaryInLayer = backgroundPositionInLayerY - backgroundHeight *  backgroundAnchorY;


	int backgroundLeftBoundaryInCamera = backgroundLeftBoundaryInLayer + this->getPositionX();
	int backgroundRightBoundaryInCamera = backgroundRightBoundaryInLayer + this->getPositionX();
	int backgroundUpBoundaryInCamera = backgroundUpBoundaryInLayer + this->getPositionY();
	int backgroundDownBoundaryInCamera = backgroundDownBoundaryInLayer + this->getPositionY();

	


	if (backgroundLeftBoundaryInCamera > -20){
		int difference = backgroundLeftBoundaryInCamera + 20;
		this->setPositionX(this->getPositionX() - difference);
	}
	else if (backgroundRightBoundaryInCamera < visibleSize.width+20){
		int difference = backgroundRightBoundaryInCamera - visibleSize.width - 20;
		this->setPositionX(this->getPositionX()  - difference);
	}
	
	
	if (backgroundUpBoundaryInCamera < visibleSize.height +20){
		int difference = backgroundUpBoundaryInCamera - visibleSize.height - 20;
		this->setPositionY(this->getPositionY() - difference) ;
	}
	else if (backgroundDownBoundaryInCamera > - 20){
		int difference = backgroundDownBoundaryInCamera + 20;
		this->setPositionY(this->getPositionY() - difference);
	}
	
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

