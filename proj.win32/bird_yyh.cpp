#include "bird_yyh.h"
#include<iostream>
#include<math.h>
#include "Stage1GameplayLayer.h"
#include "Bullet.h"
using namespace std;
Bird_yyh::Bird_yyh()
{
	//auto sprite = cocos2d::Sprite::create();
	//sprite->setAnchorPoint(cocos2d::Vec2(0, 0));
	//sprite->setPosition(300, 200);
	this->hoveringAnimation = Animation::create();
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/bird1.jpg");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/bird2.jpg");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/bird3.jpg");

	
	this->hoveringAnimation->setDelayPerUnit(0.5f);  // 设置动画帧率
	this->hoveringAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->hoveringAnimation->retain();
	auto action = Animate::create(hoveringAnimation);
	this->runAction(RepeatForever::create(action));
	//this->runAction(cocos2d::RepeatForever::create(action));
	
	
	//addChild(sprite);
	//this->addChild(sprite);
	//this->runAction(Animate::create(hoveringAnimation));x	
}

Bird_yyh * Bird_yyh::create(const std::string &filename){
	Bird_yyh *myEnemy = new Bird_yyh();
	if (myEnemy &&myEnemy->initWithFile(filename)){
		myEnemy->autorelease();
		return myEnemy;
	}
	CC_SAFE_DELETE(myEnemy);
	
	return nullptr;
}

void Bird_yyh::update(float dt){
	AllocConsole();                                          // 开辟控制台
	freopen("CONOUT$", "w", stdout);
	/*Point p = this->getPosition();
	p.x = p.x + 1;
	p.y = p.y + 1;
	this->setPosition(p);*/
	auto temp = (Stage1GameplayLayer*)this->getParent();
	Point hero = temp->kunpeng->getPosition();
	Point bird = this->getPosition();
	float distance = sqrt(pow(hero.x - bird.x, 2) + pow(hero.y - bird.y, 2));
	//cout << distance << endl;
	auto temp_bullet = (Bullet*)temp->getChildByName("bu");
	float battledistance = 300;
	//float x = cos(asin(0.5));
	//cout << x << endl;
	int x_scope, y_scope;
	float x_dis = hero.x - bird.x ;
	float y_dis = hero.y - bird.y;
	
	float x_scala = (rand() % 201 - 100) / 100.0;
	float y_scala = (rand() % 201 - 100) / 100.0;  //先获得（-1,1）的百分位的随机小数
	int change = 10;
	/*
	this->runAction(MoveBy::create(1.0f, Vec2(x_scala*change, y_scala*change)));
	lockBirdWithinLandscape();
	//temp_bullet->schedule(schedule_selector(Bullet::ShootBullet), 0.1f);
	if (distance <= battledistance && flag == 0){
		cout << "come in" << endl;
		
		temp_bullet->schedule(schedule_selector(Bullet::ShootBullet), 0.1f);
		flag = 1;

	}
	if (distance > battledistance && flag == 1){
		cout << "stop" << endl;
		temp_bullet->unschedule(schedule_selector(Bullet::ShootBullet));
		flag = 0;
	}
	*/
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
			this->runAction(MoveBy::create(1.0f, Vec2(x_scope * bird_step,0)));
		else 
			this->runAction(MoveBy::create(1.0f, Vec2(x_scope * abs(x_change),y_scope * abs(y_change))));
		lockBirdWithinLandscape();
		if (flag == 0){
			cout << "come in" << endl;
			temp_bullet->schedule(schedule_selector(Bullet::ShootBullet), 0.1f);
			flag = 1;

		}

	}
	if (distance > battledistance){
		this->runAction(MoveBy::create(1.0f, Vec2(x_scala*change, y_scala*change)));
		lockBirdWithinLandscape();
		if (flag == 1){
			cout << "stop" << endl;
			temp_bullet->unschedule(schedule_selector(Bullet::ShootBullet));
			flag = 0;
		}

	}

	
}
void Bird_yyh::wanderAbout(){
	scheduleUpdate();
	/*
	auto temp = (Stage1GameplayLayer*)this->getParent();
	
	
	Point hero = temp->kunpeng->getPosition();
	Point bird = this->getPosition();
	float distance = sqrt(pow(hero.x - bird.x, 2) + pow(hero.y - bird.y, 2));*/
	
	
	
}
void Bird_yyh::lockBirdWithinLandscape(){

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
	if (BirdPositionInLayerY > backgroundUpBoundary ){
		int difference = BirdPositionInLayerY - backgroundUpBoundary;
		this->setPositionY(this->getPositionY() - difference);
	}
	if (BirdPositionInLayerY < backgroundDownBoundary ){
		int difference = BirdPositionInLayerY - backgroundDownBoundary;
		this->setPositionY(this->getPositionY() - difference);
	}
}
void Bird_yyh::getHurt(){
	/*
	CCRect cr1 = sp1->boundingBox();
	CCRect cr2 = sp2->boundingBox();

	if (cr1.intersectsRect(cr2))	//是否存在交集
	{
		CCLOG("Is Conllision...");
	}
	else
		CCLOG("Is't Conllision...");
	*/

}
Bird_yyh::~Bird_yyh()
{
}
