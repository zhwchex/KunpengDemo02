#include "Bird_zwc.h"
#include "Stage1GameplayLayer.h"
#include "HeroSprite.h"
#include <iostream>
using namespace std;
# define alertThreshold 300

Bird_zwc::Bird_zwc()
{
	this->wanderAboutAnimation = Animation::create();
	this->wanderAboutAnimation->addSpriteFrameWithFileName("characters/monster/monsterAir_1.jpg");
	this->wanderAboutAnimation->addSpriteFrameWithFileName("characters/monster/monsterAir_3.jpg");
	this->wanderAboutAnimation->addSpriteFrameWithFileName("characters/monster/monsterAir_5.jpg");
	this->wanderAboutAnimation->addSpriteFrameWithFileName("characters/monster/monsterAir_7.jpg");
	this->wanderAboutAnimation->setDelayPerUnit(0.5f);
	this->wanderAboutAnimation->setRestoreOriginalFrame(true);
	this->wanderAboutAnimation->retain();

	this->runAction(RepeatForever::create(Animate::create(this->wanderAboutAnimation)));


	//this->schedule(schedule_selector(Bird_zwc::update));
}


Bird_zwc::~Bird_zwc()
{
}

void Bird_zwc::update(float dt){
	/*
	auto temp = (Stage1GameplayLayer*)this->getParent();
	Point hero = temp->kunpeng->getPosition();
	pauseflagBirdWithinLandscape();
	if ((this->getPositionX() - hero.x) < alertThreshold || (this->getPositionX() - hero.x) > -alertThreshold){//进入警戒范围内开始攻击

		float Duration = 1.0f;//实际飞行的时间
		auto actionMove = MoveTo::create(Duration, hero);

		//小怪开始靠近
		Sequence* sequence = Sequence::create(actionMove, NULL);
		this->runAction(sequence);
	}
	*/


		auto temp = (Stage1GameplayLayer*)this->getParent();
		Point hero = temp->kunpeng->getPosition();
		Point bird = this->getPosition();
		float distance = sqrt(pow(hero.x - bird.x, 2) + pow(hero.y - bird.y, 2));
		//cout << distance << endl;
		float battledistance = 300;
		//float x = cos(asin(0.5));
		//cout << x << endl;
		int x_scope, y_scope;
		float x_dis = hero.x - bird.x;
		float y_dis = hero.y - bird.y;

		float x_scala = (rand() % 201 - 100) / 100.0;
		float y_scala = (rand() % 201 - 100) / 100.0;  //先获得（-1,1）的百分位的随机小数
		int change = 10;

		if (distance <= battledistance){
			int bird_step = 5;
			float x_change = bird_step*(cos(atan(x_dis / y_dis)));
			float y_change = bird_step*(sin(atan(x_dis / y_dis)));
			if (x_dis >= 0)
				x_scope = 1;
			else
				x_scope = -1;
			if (y_dis >= 0)
				y_scope = 1;
			else
				y_scope = -1;


			if (x_dis == 0)
				this->runAction(MoveBy::create(1.0f, Vec2(0, y_scope * bird_step)));
			else if (y_dis == 0)
				this->runAction(MoveBy::create(1.0f, Vec2(x_scope * bird_step, 0)));
			else
				this->runAction(MoveBy::create(1.0f, Vec2(x_scope * abs(x_change), y_scope * abs(y_change))));
			pauseflagBirdWithinLandscape();


		}
		if (distance > battledistance){
			this->runAction(MoveBy::create(1.0f, Vec2(x_scala*change, y_scala*change)));
			pauseflagBirdWithinLandscape();

		}

}




//这三个接口是需要暴露出来的
void Bird_zwc::wanderAbout(){//AI由你们写。我每帧都调用这个方法
	scheduleUpdate();


}


void Bird_zwc::getHurtByWind(int damage){//由我来调用
	
}

void Bird_zwc::getHurtByPaw(int damage){//由我来调用

}

void Bird_zwc::die(){//由我来调用

}


Bird_zwc * Bird_zwc::create(const std::string &filename){
	Bird_zwc *mySprite = new Bird_zwc();
	if (mySprite &&mySprite->initWithFile(filename)){
		mySprite->autorelease();
		return mySprite;
	}
	CC_SAFE_DELETE(mySprite);
	return nullptr;
}

void Bird_zwc::pauseflagBirdWithinLandscape(){

	int BirdPositionInLayerX = this->getPositionX();
	int BirdPositionInLayerY = this->getPositionY();
	auto temp = (Stage1GameplayLayer*)this->getParent();
	int backgroundPositionInLayerX = temp->background->getPositionX();
	int backgroundPositionInLayerY = temp->background->getPositionY();

	int backgroundWidth = temp->background->getContentSize().width;
	int backgroundHeight = temp->background->getContentSize().height;

	Vec2 backgroundAnchor = temp->background->getAnchorPoint();
	float backgroundAnchorX = backgroundAnchor.x;
	float backgroundAnchorY = backgroundAnchor.y;

	int backgroundLeftBoundary = backgroundPositionInLayerX - backgroundWidth * backgroundAnchorX + 10;
	int backgroundRightBoundary = backgroundPositionInLayerX + backgroundWidth *(1 - backgroundAnchorX) - 10;
	int backgroundUpBoundary = backgroundPositionInLayerY + backgroundHeight * (1 - backgroundAnchorY) - 10;
	int backgroundDownBoundary = backgroundPositionInLayerY + 10;

	if (BirdPositionInLayerX > backgroundRightBoundary){
		int difference = BirdPositionInLayerX - backgroundRightBoundary;
		this->setPositionX(this->getPositionX() - difference);
	}
	if (BirdPositionInLayerX < backgroundLeftBoundary){
		int difference = BirdPositionInLayerX - backgroundLeftBoundary;
		this->setPositionX(this->getPositionX() - difference);
	}
	if (BirdPositionInLayerY > backgroundUpBoundary){
		int difference = BirdPositionInLayerY - backgroundUpBoundary;
		this->setPositionY(this->getPositionY() - difference);
	}
	if (BirdPositionInLayerY < backgroundDownBoundary){
		int difference = BirdPositionInLayerY - backgroundDownBoundary;
		this->setPositionY(this->getPositionY() - difference);
	}
}
