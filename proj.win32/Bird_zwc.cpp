#include "Bird_zwc.h"
#include<iostream>
#include<math.h>
#include "Stage1GameplayLayer.h"
#include "Bullet.h"
#include "Stage1Scene.h"
using namespace std;
# define hitThreshold 150 //发起冲刺的距离阈值
# define hurtThreshold 40 //受伤的距离阈值
# define hitSpeed 20 //冲刺的速度
# define moveOutside 200 //允许出镜头的阈值

Bird_zwc::Bird_zwc()
{
	//auto sprite = cocos2d::Sprite::create();
	//sprite->setAnchorPoint(cocos2d::Vec2(0, 0));
	//sprite->setPosition(300, 200);
	this->hoveringAnimation = Animation::create();
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/monster/fly-0left.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/monster/fly-1left.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/monster/fly-2left.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/monster/fly-3left.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/monster/fly-4left.png");
	this->hoveringAnimation->setDelayPerUnit(0.5f);  // 设置动画帧率
	this->hoveringAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->hoveringAnimation->retain();

	this->leftAnimation = Animation::create();
	this->leftAnimation->addSpriteFrameWithFileName("characters/monster/fly-0left.png");
	this->leftAnimation->addSpriteFrameWithFileName("characters/monster/fly-1left.png");
	this->leftAnimation->addSpriteFrameWithFileName("characters/monster/fly-2left.png");
	this->leftAnimation->addSpriteFrameWithFileName("characters/monster/fly-3left.png");
	this->leftAnimation->addSpriteFrameWithFileName("characters/monster/fly-4left.png");
	this->leftAnimation->setDelayPerUnit(0.5f);  // 设置动画帧率
	this->leftAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->leftAnimation->retain();

	this->rightAnimation = Animation::create();
	this->rightAnimation->addSpriteFrameWithFileName("characters/monster/fly-0.png");
	this->rightAnimation->addSpriteFrameWithFileName("characters/monster/fly-1.png");
	this->rightAnimation->addSpriteFrameWithFileName("characters/monster/fly-2.png");
	this->rightAnimation->addSpriteFrameWithFileName("characters/monster/fly-3.png");
	this->rightAnimation->addSpriteFrameWithFileName("characters/monster/fly-4.png");
	this->rightAnimation->setDelayPerUnit(0.5f);  // 设置动画帧率
	this->rightAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->rightAnimation->retain();

	this->leftturnAnimation = Animation::create();
	this->leftturnAnimation->addSpriteFrameWithFileName("characters/monster/fly-2.png");
	this->leftturnAnimation->addSpriteFrameWithFileName("characters/monster/fly-2left.png");
	//this->leftturnAnimation->addSpriteFrameWithFileName("characters/monster/leftturn3.png");
	this->leftturnAnimation->setDelayPerUnit(0.5f);  // 设置动画帧率
	this->leftturnAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->leftturnAnimation->retain();

	this->rightturnAnimation = Animation::create();
	this->rightturnAnimation->addSpriteFrameWithFileName("characters/monster/fly-2left.png");
	this->rightturnAnimation->addSpriteFrameWithFileName("characters/monster/fly-2.png");
	//this->rightturnAnimation->addSpriteFrameWithFileName("characters/monster/rightturn3.png");
	this->rightturnAnimation->setDelayPerUnit(0.5f);  // 设置动画帧率
	this->rightturnAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->rightturnAnimation->retain();

	this->lefthurtAnimation = Animation::create();
	//this->lefthurtAnimation->addSpriteFrameWithFileName("characters/monster/hurt-0left.png");
	this->lefthurtAnimation->addSpriteFrameWithFileName("characters/monster/hurt-1left.png");
	this->lefthurtAnimation->addSpriteFrameWithFileName("characters/monster/hurt-2left.png");
	this->lefthurtAnimation->addSpriteFrameWithFileName("characters/monster/hurt-3left.png");
	this->lefthurtAnimation->setDelayPerUnit(0.2f);  // 设置动画帧率
	this->lefthurtAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->lefthurtAnimation->retain();




	this->righthurtAnimation = Animation::create();
	//this->righthurtAnimation->addSpriteFrameWithFileName("characters/monster/hurt-0.png");
	this->righthurtAnimation->addSpriteFrameWithFileName("characters/monster/hurt-1.png");
	this->righthurtAnimation->addSpriteFrameWithFileName("characters/monster/hurt-2.png");
	this->righthurtAnimation->addSpriteFrameWithFileName("characters/monster/hurt-3.png");
	this->righthurtAnimation->setDelayPerUnit(0.2f);  // 设置动画帧率
	this->righthurtAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->righthurtAnimation->retain();

	this->leftdieAnimation = Animation::create();
	this->leftdieAnimation->addSpriteFrameWithFileName("characters/monster/die-0left.png");
	this->leftdieAnimation->addSpriteFrameWithFileName("characters/monster/die-1left.png");
	this->leftdieAnimation->addSpriteFrameWithFileName("characters/monster/die-2left.png");
	this->leftdieAnimation->addSpriteFrameWithFileName("characters/monster/die-3left.png");
	this->leftdieAnimation->setDelayPerUnit(0.2f);  // 设置动画帧率
	this->leftdieAnimation->setRestoreOriginalFrame(false);// 设置动画播放完毕后是否回到第一帧
	this->leftdieAnimation->retain();

	this->rightdieAnimation = Animation::create();
	this->rightdieAnimation->addSpriteFrameWithFileName("characters/monster/die-0.png");
	this->rightdieAnimation->addSpriteFrameWithFileName("characters/monster/die-1.png");
	this->rightdieAnimation->addSpriteFrameWithFileName("characters/monster/die-2.png");
	this->rightdieAnimation->addSpriteFrameWithFileName("characters/monster/die-3.png");
	this->rightdieAnimation->setDelayPerUnit(0.2f);  // 设置动画帧率
	this->rightdieAnimation->setRestoreOriginalFrame(false);// 设置动画播放完毕后是否回到第一帧
	this->rightdieAnimation->retain();

	this->leftfightAnimation = Animation::create();
	//this->leftfightAnimation->addSpriteFrameWithFileName("characters/monster/hit-0left.png");
	this->leftfightAnimation->addSpriteFrameWithFileName("characters/monster/hit-1left.png");
	this->leftfightAnimation->addSpriteFrameWithFileName("characters/monster/hit-2left.png");
	this->leftfightAnimation->addSpriteFrameWithFileName("characters/monster/hit-3left.png");
	this->leftfightAnimation->setDelayPerUnit(0.5f);  // 设置动画帧率
	this->leftfightAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->leftfightAnimation->retain();

	this->rightfightAnimation = Animation::create();
	//this->rightfightAnimation->addSpriteFrameWithFileName("characters/monster/hit-0.png");
	this->rightfightAnimation->addSpriteFrameWithFileName("characters/monster/hit-1.png");
	this->rightfightAnimation->addSpriteFrameWithFileName("characters/monster/hit-2.png");
	this->rightfightAnimation->addSpriteFrameWithFileName("characters/monster/hit-3.png");
	this->rightfightAnimation->setDelayPerUnit(0.5f);  // 设置动画帧率
	this->rightfightAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->rightfightAnimation->retain();

	//auto action = Animate::create(hoveringAnimation);
	//this->runAction(RepeatForever::create(action));
	this->runAction(Animate::create(this->hoveringAnimation));
	//this->runAction(cocos2d::RepeatForever::create(action));
	
	
	//addChild(sprite);
	//this->addChild(sprite);
	//this->runAction(Animate::create(hoveringAnimation));
}

Bird_zwc * Bird_zwc::create(const std::string &filename){
	Bird_zwc *myEnemy = new Bird_zwc();
	if (myEnemy &&myEnemy->initWithFile(filename)){
		myEnemy->autorelease();
		return myEnemy;
	}
	CC_SAFE_DELETE(myEnemy);
	
	return nullptr;
}

void Bird_zwc::update(float dt){
	
}

void Bird_zwc::wanderAbout(){
	auto temp = (Stage1GameplayLayer*)this->getParent();
		Point hero = temp->kunpeng->getPosition();
		Point bird = this->getPosition();
		float distance = sqrt(pow(hero.x - bird.x, 2) + pow(hero.y - bird.y, 2));

		float x_dis = hero.x - bird.x;
		float y_dis = hero.y - bird.y;

		x_change = bird_step*(cos(atan(x_dis / y_dis)));
		y_change = bird_step*(sin(atan(x_dis / y_dis)));

		if (pauseflag == 0 && distance < Director::getInstance()->getVisibleSize().width ){

	

		if (x_dis >= 0)//小怪在主角的左方
		{
			x_scope = 1;
			Lockright();
		}
		else
		{
			x_scope = -1;
			Lockleft();

		}

		if (y_dis >= 0)
			y_scope = 1;
		else
			y_scope = -1;

		this->runAction(MoveBy::create(2.0f, Vec2(x_scope * abs(x_change), y_scope * abs(y_change))));
	
		
		if (distance < hitThreshold){


			if (((int)rand_0_1() * 7) == 0){//7分之一的概率进行冲刺攻击
				this->runAction(MoveBy::create(distance / hitSpeed, Vec2(x_dis, y_dis)));
			}

			if (distance < hurtThreshold){
				temp->kunpeng->getHurtGeneral(10);
			}

		}

	}

		lockBirdWithinLandscape();

}




void Bird_zwc::f(){
	lock = 0;
}
void Bird_zwc::Lockright(){
	if (lock == 0){
		lock = 1;
		this->runAction(Animate::create(this->rightAnimation));
		auto delayTime = DelayTime::create(2.0f);
		auto func = CallFunc::create([this](){ lock = 0; });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this -> runAction(seq);
	}
	
}

void Bird_zwc::Lockhurt(Animation* ani){
	if (lock == 0){
		lock = 1;
		this->runAction(Animate::create(ani));
		auto delayTime = DelayTime::create(1.5f);
		auto func = CallFunc::create([this](){ lock = 0; });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);
	}

}

void Bird_zwc::Lockleft(){
	if (lock == 0){
		lock = 1;
		this->runAction(Animate::create(this->leftAnimation));
		auto delayTime = DelayTime::create(2.0f);
		auto func = CallFunc::create([this](){ lock = 0; });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);
	}
}





void Bird_zwc::lockBirdWithinLandscape(){

	Stage1Scene * scene = (Stage1Scene *)this->getParent()->getParent();
		Size visibleSize = Director::getInstance()->getVisibleSize();

		int heroPositionInCameraX = this->getParent()->getPositionX() + this->getPositionX();
		int heroPositionInCameraY = this->getParent()->getPositionY() + this->getPositionY();

		/*
		if (heroPositionInCameraX > visibleSize.width + moveOutside){
			int difference = heroPositionInCameraX - visibleSize.width - moveOutside;
			this->setPositionX(this->getPositionX() - difference);
		}
		if (heroPositionInCameraX < 0 - moveOutside){
			int difference = heroPositionInCameraX + moveOutside;
			this->setPositionX(this->getPositionX() - difference);
		}
		*/

		if (heroPositionInCameraY > visibleSize.height + moveOutside){
			int difference = heroPositionInCameraY - visibleSize.height - moveOutside;
			this->setPositionY(this->getPositionY() - difference);
		}
		if (heroPositionInCameraY < 0 - moveOutside){
			int difference = heroPositionInCameraY + moveOutside;
			this->setPositionY(this->getPositionY() - difference);
		}

		//防止鸟入水
		int backgroundDownBoundary = ((Stage1GameplayLayer*)this->getParent())->background->getPositionY() + 10;	
		if (this->getPositionY() < backgroundDownBoundary){
			this->setPositionY(backgroundDownBoundary);
		}
		
}


void Bird_zwc::getHurtByWind(int damage){

	this->stopAllActions();
	pauseflag = 1;//1代表因伤暂停

	auto temp = (Stage1GameplayLayer*)this->getParent();
	Point hero = temp->kunpeng->getPosition();
	Point bird = this->getPosition();

	float x_dis = hero.x - bird.x;
	float y_dis = hero.y - bird.y;

	health = health - damage;
	if (health > 0)
	{
		if (x_dis < 0) {
		     this->runAction(Animate::create(lefthurtAnimation));
			 //Lockhurt(this->lefthurtAnimation);
		}
		else{
			 this->runAction(Animate::create(righthurtAnimation));
			//Lockhurt(this->righthurtAnimation);
		}

		auto delayTime = DelayTime::create(1.f);
		auto func = CallFunc::create([this](){pauseflag = 0; f(); wanderAbout(); });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);
		
	}
	else{
		this->stopAllActions();
		dieflag = 1;

		if (x_dis < 0){
			this->runAction(Animate::create(leftdieAnimation));
		}
		else
		{
			this->runAction(Animate::create(rightdieAnimation));
		}
		
		auto delayTime = DelayTime::create(2.0f);
		auto func = CallFunc::create([this](){
			auto temp = (Stage1GameplayLayer*)this->getParent();
			temp->removeChild(this);
			temp->enemyList.eraseObject(this); });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);
	}
	
}



void Bird_zwc::getHurtByPaw(int damage){      //yyhyyh
	//unscheduleUpdate();
	pauseflag = 1;
	this->stopAllActions();

	health = health - damage;
	auto temp = (Stage1GameplayLayer*)this->getParent();
	auto temp_bullet = (Bullet*)temp->getChildByName("bu");
	temp_bullet->unschedule(schedule_selector(Bullet::ShootBullet));
	

	if (health > 0)
	{
		if (dir == -1 || dir == 0)                            //徘徊的时候会不会受伤？？？
			this->runAction(Animate::create(lefthurtAnimation));
		if (dir == 1)
			this->runAction(Animate::create(righthurtAnimation));
		auto delayTime = DelayTime::create(2.0f);
		auto func = CallFunc::create([this](){ pauseflag = 0; lock = 0; flag = 0; });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);

	}
	else{
		if (dir == -1 || dir == 0)
			this->runAction(Animate::create(leftdieAnimation));
		if (dir == 1)
			this->runAction(Animate::create(rightdieAnimation));

		auto delayTime = DelayTime::create(2.0f);
		auto func = CallFunc::create([this](){
			auto temp = (Stage1GameplayLayer*)this->getParent();
			temp->removeChild(this);

			temp->removeChildByName("bu");

			//temp->removeChildByName("bu");

			temp->enemyList.eraseObject(this); });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);


	}

}

void Bird_zwc::getHurtByCrush(int damage){
	unscheduleUpdate();
	health = health - damage;
	if (health > 0)
	{
		if (dir == -1 || dir == 0)                            //徘徊的时候会不会受伤？？？
			this->runAction(Animate::create(lefthurtAnimation));
		if (dir == 1)
			this->runAction(Animate::create(righthurtAnimation));
		auto delayTime = DelayTime::create(2.0f);
		auto func = CallFunc::create([this](){ scheduleUpdate(); });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);

	}
	else{
		if (dir == -1 || dir == 0)
			this->runAction(Animate::create(leftdieAnimation));
		if (dir == 1)
			this->runAction(Animate::create(rightdieAnimation));

		auto delayTime = DelayTime::create(2.0f);
		auto func = CallFunc::create([this](){
			auto temp = (Stage1GameplayLayer*)this->getParent();
			temp->removeChild(this);
			temp->removeChildByName("bu");
			temp->enemyList.eraseObject(this); });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);


	}

}

void Bird_zwc::getHurtByWater(int damage){
	unscheduleUpdate();
	health = health - damage;
	if (health > 0)
	{
		if (dir == -1 || dir == 0)                            //徘徊的时候会不会受伤？？？
			this->runAction(Animate::create(lefthurtAnimation));
		if (dir == 1)
			this->runAction(Animate::create(righthurtAnimation));
		auto delayTime = DelayTime::create(2.0f);
		auto func = CallFunc::create([this](){ scheduleUpdate(); });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);

	}
	else{
		if (dir == -1 || dir == 0)
			this->runAction(Animate::create(leftdieAnimation));
		if (dir == 1)
			this->runAction(Animate::create(rightdieAnimation));

		auto delayTime = DelayTime::create(2.0f);
		auto func = CallFunc::create([this](){
			auto temp = (Stage1GameplayLayer*)this->getParent();
			temp->removeChild(this);
			temp->removeChildByName("bu");
			temp->enemyList.eraseObject(this); });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);


	}

}

void Bird_zwc::getHurtByFin(int damage){
	unscheduleUpdate();
	health = health - damage;
	if (health > 0)
	{
		if (dir == -1 || dir == 0)                            //徘徊的时候会不会受伤？？？
			this->runAction(Animate::create(lefthurtAnimation));
		if (dir == 1)
			this->runAction(Animate::create(righthurtAnimation));
		auto delayTime = DelayTime::create(2.0f);
		auto func = CallFunc::create([this](){ scheduleUpdate(); });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);

	}
	else{
		if (dir == -1 || dir == 0)
			this->runAction(Animate::create(leftdieAnimation));
		if (dir == 1)
			this->runAction(Animate::create(rightdieAnimation));

		auto delayTime = DelayTime::create(2.0f);
		auto func = CallFunc::create([this](){
			auto temp = (Stage1GameplayLayer*)this->getParent();
			temp->removeChild(this);
			temp->removeChildByName("bu");
			temp->enemyList.eraseObject(this); });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);


	}

}
Bird_zwc::~Bird_zwc()
{
}
