#include "Bird_zwc.h"
#include<iostream>
#include<math.h>
#include "Stage1GameplayLayer.h"
#include "Bullet.h"
#include "Stage1Scene.h"
#include "AudioManager.h"
using namespace std;
# define hitThreshold 150 //发起冲刺的距离阈值
# define hurtThreshold 50 //受伤的距离阈值
# define hitSpeed 20 //冲刺的速度
# define moveOutside 20 //允许出镜头的阈值

Bird_zwc::Bird_zwc()
{
	/*
	//auto sprite = cocos2d::Sprite::create();
	//sprite->setAnchorPoint(cocos2d::Vec2(0, 0));
	//sprite->setPosition(300, 200);
	this->hoveringAnimation = Animation::create();
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/monster/fly-0left.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/monster/fly-1left.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/monster/fly-2left.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/monster/fly-3.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/monster/fly-4.png");
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
	*/
	this->hoveringAnimation = Animation::create();
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/bat/fly-0.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/bat/fly-1.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/bat/fly-2.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/bat/fly-3.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/bat/fly-4.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/bat/fly-5.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/bat/fly-6.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/bat/fly-7.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/bat/fly-8.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/bat/fly-9.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/bat/fly-10.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/bat/fly-11.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/bat/fly-12.png");
	this->hoveringAnimation->setDelayPerUnit(0.2f);  // 设置动画帧率
	this->hoveringAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->hoveringAnimation->retain();



	this->leftAnimation = Animation::create();
	this->leftAnimation->addSpriteFrameWithFileName("characters/bat/fly-0.png");
	this->leftAnimation->addSpriteFrameWithFileName("characters/bat/fly-1.png");
	this->leftAnimation->addSpriteFrameWithFileName("characters/bat/fly-2.png");
	this->leftAnimation->addSpriteFrameWithFileName("characters/bat/fly-3.png");
	this->leftAnimation->addSpriteFrameWithFileName("characters/bat/fly-4.png");
	this->leftAnimation->addSpriteFrameWithFileName("characters/bat/fly-5.png");
	this->leftAnimation->addSpriteFrameWithFileName("characters/bat/fly-6.png");
	this->leftAnimation->addSpriteFrameWithFileName("characters/bat/fly-7.png");
	this->leftAnimation->addSpriteFrameWithFileName("characters/bat/fly-8.png");
	this->leftAnimation->addSpriteFrameWithFileName("characters/bat/fly-9.png");
	this->leftAnimation->addSpriteFrameWithFileName("characters/bat/fly-10.png");
	this->leftAnimation->addSpriteFrameWithFileName("characters/bat/fly-11.png");
	this->leftAnimation->addSpriteFrameWithFileName("characters/bat/fly-12.png");
	this->leftAnimation->setDelayPerUnit(0.2f);  // 设置动画帧率
	this->leftAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->leftAnimation->retain();

	this->rightAnimation = Animation::create();
	this->rightAnimation->addSpriteFrameWithFileName("characters/bat/flyRight-0.png");
	this->rightAnimation->addSpriteFrameWithFileName("characters/bat/flyRight-1.png");
	this->rightAnimation->addSpriteFrameWithFileName("characters/bat/flyRight-2.png");
	this->rightAnimation->addSpriteFrameWithFileName("characters/bat/flyRight-3.png");
	this->rightAnimation->addSpriteFrameWithFileName("characters/bat/flyRight-4.png");
	this->rightAnimation->addSpriteFrameWithFileName("characters/bat/flyRight-5.png");
	this->rightAnimation->addSpriteFrameWithFileName("characters/bat/flyRight-6.png");
	this->rightAnimation->addSpriteFrameWithFileName("characters/bat/flyRight-7.png");
	this->rightAnimation->addSpriteFrameWithFileName("characters/bat/flyRight-8.png");
	this->rightAnimation->addSpriteFrameWithFileName("characters/bat/flyRight-9.png");
	this->rightAnimation->addSpriteFrameWithFileName("characters/bat/flyRight-10.png");
	this->rightAnimation->addSpriteFrameWithFileName("characters/bat/flyRight-11.png");
	this->rightAnimation->addSpriteFrameWithFileName("characters/bat/flyRight-12.png");
	this->rightAnimation->setDelayPerUnit(0.2f);  // 设置动画帧率
	this->rightAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->rightAnimation->retain();


	this->lefthurtAnimation = Animation::create();
	this->lefthurtAnimation->addSpriteFrameWithFileName("characters/bat/hurt-0.png");
	this->lefthurtAnimation->addSpriteFrameWithFileName("characters/bat/hurt-1.png");
	this->lefthurtAnimation->addSpriteFrameWithFileName("characters/bat/hurt-2.png");
	this->lefthurtAnimation->addSpriteFrameWithFileName("characters/bat/hurt-3.png");
	this->lefthurtAnimation->addSpriteFrameWithFileName("characters/bat/hurt-4.png");
	this->lefthurtAnimation->addSpriteFrameWithFileName("characters/bat/hurt-5.png");
	this->lefthurtAnimation->addSpriteFrameWithFileName("characters/bat/hurt-6.png");
	this->lefthurtAnimation->addSpriteFrameWithFileName("characters/bat/hurt-7.png");
	this->lefthurtAnimation->addSpriteFrameWithFileName("characters/bat/hurt-8.png");
	this->lefthurtAnimation->addSpriteFrameWithFileName("characters/bat/hurt-9.png");
	this->lefthurtAnimation->addSpriteFrameWithFileName("characters/bat/hurt-10.png");
	this->lefthurtAnimation->addSpriteFrameWithFileName("characters/bat/hurt-11.png");
	this->lefthurtAnimation->setDelayPerUnit(0.2f);  // 设置动画帧率
	this->lefthurtAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->lefthurtAnimation->retain();




	this->righthurtAnimation = Animation::create();
	this->righthurtAnimation->addSpriteFrameWithFileName("characters/bat/hurtRight-0.png");
	this->righthurtAnimation->addSpriteFrameWithFileName("characters/bat/hurtRight-1.png");
	this->righthurtAnimation->addSpriteFrameWithFileName("characters/bat/hurtRight-2.png");
	this->righthurtAnimation->addSpriteFrameWithFileName("characters/bat/hurtRight-3.png");
	this->righthurtAnimation->addSpriteFrameWithFileName("characters/bat/hurtRight-4.png");
	this->righthurtAnimation->addSpriteFrameWithFileName("characters/bat/hurtRight-5.png");
	this->righthurtAnimation->addSpriteFrameWithFileName("characters/bat/hurtRight-6.png");
	this->righthurtAnimation->addSpriteFrameWithFileName("characters/bat/hurtRight-7.png");
	this->righthurtAnimation->addSpriteFrameWithFileName("characters/bat/hurtRight-8.png");
	this->righthurtAnimation->addSpriteFrameWithFileName("characters/bat/hurtRight-9.png");
	this->righthurtAnimation->addSpriteFrameWithFileName("characters/bat/hurtRight-10.png");
	this->righthurtAnimation->addSpriteFrameWithFileName("characters/bat/hurtRight-11.png");
	this->righthurtAnimation->setDelayPerUnit(0.2f);  // 设置动画帧率
	this->righthurtAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->righthurtAnimation->retain();

	this->leftdieAnimation = Animation::create();
	this->leftdieAnimation->addSpriteFrameWithFileName("characters/bat/die-0.png");
	this->leftdieAnimation->addSpriteFrameWithFileName("characters/bat/die-1.png");
	this->leftdieAnimation->addSpriteFrameWithFileName("characters/bat/die-2.png");
	this->leftdieAnimation->addSpriteFrameWithFileName("characters/bat/die-3.png");
	this->leftdieAnimation->addSpriteFrameWithFileName("characters/bat/die-4.png");
	this->leftdieAnimation->addSpriteFrameWithFileName("characters/bat/die-5.png");
	this->leftdieAnimation->addSpriteFrameWithFileName("characters/bat/die-6.png");
	this->leftdieAnimation->addSpriteFrameWithFileName("characters/bat/die-7.png");
	this->leftdieAnimation->addSpriteFrameWithFileName("characters/bat/die-8.png");
	this->leftdieAnimation->addSpriteFrameWithFileName("characters/bat/die-9.png");
	this->leftdieAnimation->addSpriteFrameWithFileName("characters/bat/die-10.png");
	this->leftdieAnimation->setDelayPerUnit(0.1f);  // 设置动画帧率
	this->leftdieAnimation->setRestoreOriginalFrame(false);// 设置动画播放完毕后是否回到第一帧
	this->leftdieAnimation->retain();

	this->rightdieAnimation = Animation::create();
	this->rightdieAnimation->addSpriteFrameWithFileName("characters/bat/dieRight-0.png");
	this->rightdieAnimation->addSpriteFrameWithFileName("characters/bat/dieRight-1.png");
	this->rightdieAnimation->addSpriteFrameWithFileName("characters/bat/dieRight-2.png");
	this->rightdieAnimation->addSpriteFrameWithFileName("characters/bat/dieRight-3.png");
	this->rightdieAnimation->addSpriteFrameWithFileName("characters/bat/dieRight-4.png");
	this->rightdieAnimation->addSpriteFrameWithFileName("characters/bat/dieRight-5.png");
	this->rightdieAnimation->addSpriteFrameWithFileName("characters/bat/dieRight-6.png");
	this->rightdieAnimation->addSpriteFrameWithFileName("characters/bat/dieRight-7.png");
	this->rightdieAnimation->addSpriteFrameWithFileName("characters/bat/dieRight-8.png");
	this->rightdieAnimation->addSpriteFrameWithFileName("characters/bat/dieRight-9.png");
	this->rightdieAnimation->addSpriteFrameWithFileName("characters/bat/dieRight-10.png");
	this->rightdieAnimation->setDelayPerUnit(0.1f);  // 设置动画帧率
	this->rightdieAnimation->setRestoreOriginalFrame(false);// 设置动画播放完毕后是否回到第一帧
	this->rightdieAnimation->retain();

	this->leftfightAnimation = Animation::create();
	this->leftfightAnimation->addSpriteFrameWithFileName("characters/bat/hit-0.png");
	this->leftfightAnimation->addSpriteFrameWithFileName("characters/bat/hit-1.png");
	this->leftfightAnimation->addSpriteFrameWithFileName("characters/bat/hit-2.png");
	this->leftfightAnimation->addSpriteFrameWithFileName("characters/bat/hit-3.png");
	this->leftfightAnimation->addSpriteFrameWithFileName("characters/bat/hit-4.png");
	this->leftfightAnimation->addSpriteFrameWithFileName("characters/bat/hit-5.png");
	this->leftfightAnimation->addSpriteFrameWithFileName("characters/bat/hit-6.png");
	this->leftfightAnimation->addSpriteFrameWithFileName("characters/bat/hit-7.png");
	this->leftfightAnimation->addSpriteFrameWithFileName("characters/bat/hit-8.png");
	this->leftfightAnimation->addSpriteFrameWithFileName("characters/bat/hit-9.png");
	this->leftfightAnimation->addSpriteFrameWithFileName("characters/bat/hit-10.png");
	this->leftfightAnimation->addSpriteFrameWithFileName("characters/bat/hit-11.png");
	this->leftfightAnimation->setDelayPerUnit(0.2f);  // 设置动画帧率
	this->leftfightAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->leftfightAnimation->retain();

	this->rightfightAnimation = Animation::create();
	this->rightfightAnimation->addSpriteFrameWithFileName("characters/bat/hitRight-0.png");
	this->rightfightAnimation->addSpriteFrameWithFileName("characters/bat/hitRight-1.png");
	this->rightfightAnimation->addSpriteFrameWithFileName("characters/bat/hitRight-2.png");
	this->rightfightAnimation->addSpriteFrameWithFileName("characters/bat/hitRight-3.png");
	this->rightfightAnimation->addSpriteFrameWithFileName("characters/bat/hitRight-4.png");
	this->rightfightAnimation->addSpriteFrameWithFileName("characters/bat/hitRight-5.png");
	this->rightfightAnimation->addSpriteFrameWithFileName("characters/bat/hitRight-6.png");
	this->rightfightAnimation->addSpriteFrameWithFileName("characters/bat/hitRight-7.png");
	this->rightfightAnimation->addSpriteFrameWithFileName("characters/bat/hitRight-8.png");
	this->rightfightAnimation->addSpriteFrameWithFileName("characters/bat/hitRight-9.png");
	this->rightfightAnimation->addSpriteFrameWithFileName("characters/bat/hitRight-10.png");
	this->rightfightAnimation->addSpriteFrameWithFileName("characters/bat/hitRight-11.png");
	this->rightfightAnimation->setDelayPerUnit(0.2f);  // 设置动画帧率
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
	auto realHero = temp->kunpeng;

	Point hero = realHero->getPosition();
	Point bird = this->getPosition();

	float distance = sqrt(pow(hero.x - bird.x, 2) + pow(hero.y - bird.y, 2));
	float x_dis = hero.x - bird.x;
	float y_dis = hero.y - bird.y;

	if (pauseflag == 0 && distance < battledistance){ //展开攻击

		distance = sqrt(pow(hero.x - bird.x, 2) + pow(hero.y - bird.y, 2));

		x_dis = hero.x - bird.x;
		y_dis = hero.y - bird.y;

		x_change = bird_step*(cos(atan(x_dis / y_dis)));
		y_change = bird_step*(sin(atan(x_dis / y_dis)));
		float random_scala = (rand() % 201 - 100) / 100.0;  //先获得（-1,1）的百分位的随机小数

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

		if (realHero->isBird){
			this->runAction(MoveBy::create(2.0f, Vec2(x_scope * abs(x_change), y_scope * abs(y_change))));
		}
		else{
			this->runAction(MoveBy::create(2.0f, Vec2(x_scope * abs(x_change), random_scala * abs(y_change))));//如果主角入水，小怪在上空盘旋
		}

		if (distance < hitThreshold){

			//if (((int)rand_0_1() * 3) == 0){//3分之一的概率进行冲刺攻击
			//this->runAction(MoveBy::create(distance / hitSpeed, Vec2(x_scope * abs(x_change), y_scope * abs(y_change))));
			//this->runAction(MoveBy::create(distance / hitSpeed, Vec2(x_dis/2, y_dis/2)));
			this->runAction(MoveBy::create(1.0f, Vec2(x_scope * abs(x_change), y_scope * abs(y_change))));
			//}

			if (distance < hurtThreshold){
				temp->kunpeng->getHurtGeneral(10);
			}

		}

		//	AllocConsole();
	//	freopen("CONOUT$", "w", stdout);
	//	cout << "ATTACK!!!heroPointX:" << hero.x << "     heroPointY:" << hero.y << endl;
	//	cout << "ATTACK!!!birdPointX:" << bird.x << "     birdPointY:" << bird.y << endl;
	//	cout << "ATTACK!!!x_scope * abs(x_change):" << x_scope * abs(x_change) << "     y_scope * abs(y_change):" << y_scope * abs(y_change) << endl;
	}

	else if (pauseflag == 0 && distance >= battledistance){//超出攻击范围，保持在守卫点附近

		//auto temp = (Stage1GameplayLayer*)this->getParent();
		//Point hero = temp->kunpeng->getPosition();

		distance = sqrt(pow(hero.x - guardPoint.x, 2) + pow(hero.y - guardPoint.y, 2));

		x_dis = guardPoint.x - bird.x;
		y_dis = guardPoint.y - bird.y;

		x_change = 10 * (cos(atan(x_dis / y_dis)));
		y_change = 5 * (sin(atan(x_dis / y_dis)));


		if (x_dis >= 0)//小怪在守卫点的左方
		{
			x_scope = 1;
			Lockright();
		}
		else
		{
			x_scope = -1;
			Lockleft();

		}

		if (y_dis >= 0)//小怪在守卫点下方
			y_scope = 1;
		else
			y_scope = -1;

		if (x_dis != 0 && y_dis != 0)
			this->runAction(MoveBy::create(2.0f, Vec2(x_scope * abs(x_change), y_scope * abs(y_change))));

	}

//	cout << "KEEP!!!heroPointX:" << hero.x << "     heroPointY:" << hero.y << endl;
//	cout << "KEEP!!!birdPointX:" << bird.x << "     birdPointY:" << bird.y << endl;
//	cout << "KEEP!!!guardPointX:" << guardPoint.x << "       guardPointY:" << guardPoint.y << endl;
//	cout << "KEEP!!!x_scope * abs(x_change):" << x_scope * abs(x_change) << "     y_scope * abs(y_change):" << y_scope * abs(y_change) << endl;

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
		this->runAction(seq);
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
	this->getHurt(damage);
	//getHeld();//forTest
	//getThrown();//forTest
}

void Bird_zwc::getHurtByPaw(int damage){      //yyhyyh
	this->getHurt(damage);
}

void Bird_zwc::getHurtByCrush(int damage){
	this->getHurt(damage);
}

void Bird_zwc::getHurt(int damage){
	this->stopAllActions();
	pauseflag = 1;//1代表因伤暂停

	auto temp = (Stage1GameplayLayer*)this->getParent();
	Point hero = temp->kunpeng->getPosition();
	Point bird = this->getPosition();

	float x_dis = hero.x - bird.x;
	float y_dis = hero.y - bird.y;
	AudioManager::getInstance()->play(MONSTER_HURT_FILE_NAME, false);
	health = health - damage;
	if (health > 0)
	{
		if (x_dis < 0) {
			//小怪击退右移、受伤动画
			this->runAction(Sequence::create(MoveBy::create(0.1f, Vec2(this->getContentSize().width / 2, 0)), MoveBy::create(0.5f, Vec2(this->getContentSize().width / 4, 0)), nullptr));
			this->runAction(Animate::create(lefthurtAnimation));
		}
		else{
			//小怪击退左移、受伤动画
			this->runAction(Sequence::create(MoveBy::create(0.1f, Vec2(-this->getContentSize().width / 2, 0)), MoveBy::create(0.5f, Vec2(-this->getContentSize().width / 4, 0)), nullptr));
			this->runAction(Animate::create(righthurtAnimation));
		}

		auto delayTime = DelayTime::create(1.f);
		auto func = CallFunc::create([this](){ pauseflag = 0; f(); wanderAbout(); });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);

	}

	else{
		die(x_dis < 0 ? true : false);
	}
}


void Bird_zwc::getHurtByWater(int damage){
	this->getHurt(damage);
}

void Bird_zwc::getHurtByFin(int damage){
	this->getHurt(damage);
}

void Bird_zwc::setPlace(int x, int y){//设置出生点&守卫点
	this->setPosition(x, y >= 0 ? y : -y);//防止设置鸟出生在水下
	this->guardPoint = Vec2(x, y >= 0 ? y : -y);//守卫点
}

void Bird_zwc::die(bool facingLeft) {
	this->stopAllActions();
	dieflag = 1;

	if (facingLeft){
		this->runAction(Animate::create(leftdieAnimation));
	}
	else
	{
		this->runAction(Animate::create(rightdieAnimation));
	}

	auto fallingDown = MoveTo::create(0.5f, Vec2(this->getPosition().x, 0));//加上下落到水面的动画
	auto delayTime = DelayTime::create(0.5f);
	auto func = CallFunc::create([this](){
		auto temp = (Stage1GameplayLayer*)this->getParent();
		temp->removeChild(this);
		temp->enemyList.eraseObject(this); });
		auto seq = Sequence::create(fallingDown, delayTime,func, nullptr);
		this->runAction(seq);
}

void  Bird_zwc::getHeld(){//被鹏抓住提在爪子上，像兔子被老鹰抓住一样，呆滞，循环播放

	auto temp = (Stage1GameplayLayer*)this->getParent();
	auto realHero = temp->kunpeng;

	Point hero = realHero->getPosition();
	Point bird = this->getPosition();

	this->stopAllActions();
	pauseflag = 1;//1代表因伤暂停
	this->runAction((Animate::create(leftAnimation)));

	auto hurtAnimation = (hero.x <= bird.x) ? lefthurtAnimation->clone() : righthurtAnimation->clone();
	hurtAnimation->setDelayPerUnit(0.3f);
	hurtAnimation->setRestoreOriginalFrame(false);
	auto hurt = Animate::create(hurtAnimation);//受伤动画

	auto delayTime = DelayTime::create(1.f);
	auto func = CallFunc::create([this](){ pauseflag = 0; f(); wanderAbout(); });
	auto seq = Sequence::create(hurt, delayTime, func, nullptr);
	this->runAction(seq);
	//this->runAction(Animate::create(this->leftAnimation));
}

void Bird_zwc::getThrown(){//被鹏往地上扔的动画，位于半空中，震惊和失控，循环播放

	auto temp = (Stage1GameplayLayer*)this->getParent();
	auto realHero = temp->kunpeng;

	Point hero = realHero->getPosition();
	Point bird = this->getPosition();

	this->stopAllActions();
	pauseflag = 1;//1代表因伤暂停

	auto fallingDown = MoveTo::create(1.0f, Vec2(this->getPosition().x, -10));//下落到水面的动画

	auto hurtAnimation = (hero.x <= bird.x) ? lefthurtAnimation->clone() : righthurtAnimation->clone();
	hurtAnimation->setDelayPerUnit(0.1f);
	//lefthurtAnimation2->setLoops(5);
	hurtAnimation->setRestoreOriginalFrame(false);
	auto hurt = Animate::create(hurtAnimation);//震惊和失控动画

	auto s = Spawn::create(fallingDown, hurt, nullptr);
	auto delayTime = DelayTime::create(2.f);
	//auto func = CallFunc::create([this](){ pauseflag = 0; f(); wanderAbout(); });
	auto func = CallFunc::create([this](){ pauseflag = 0; f();  getSlamDunkOnWater(20); });
	auto seq = Sequence::create(s, func, nullptr);
	this->runAction(seq);
}

void Bird_zwc::getSlamDunkOnGround(int damage){//砸在地面的动画，最好有个小弹跳的动作，瘫痪几秒爬起来进入正常行动状态。播放一次，播放完进入正常活动状态或直接死掉，调一下die或dieOnSlamDunk
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
		auto delayTime = DelayTime::create(1.f);
		auto func = CallFunc::create([this](){ pauseflag = 0; f(); wanderAbout(); });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);
	}

	else{
		die(x_dis < 0 ? true : false);
	}
}

void Bird_zwc::getSlamDunkOnWater(int damage){//砸在水面的动画，最好有个小弹跳的动作，瘫痪几秒爬起来进入正常行动状态，记得在落水的地方添加一个水花。播放一次，播放完进入正常活动状态或直接死掉，调一下die或dieOnSlamDunk
	//this->stopAllActions();
	//pauseflag = 1;//1代表因伤暂停


	//waterSplashingAnimation_small->retain();

	//auto jump = MoveTo::create(0.1f, Vec2(this->getPosition().x, 50));//下落到水面的动画
	//auto fallingDown = MoveTo::create(0.1f, Vec2(this->getPosition().x, -10));//下落到水面的动画
	//auto func = CallFunc::create([this](){ wanderAbout(); });
	/*
	auto func2 = CallFunc::create([this](){ pauseflag = 0; f();  wanderAbout(); });
	auto func1 = CallFunc::create([this](){

	auto waterSplashingAnimation_small = Animation::create();
	waterSplashingAnimation_small->addSpriteFrameWithFileName("landscapes/splash_small_00.png");
	waterSplashingAnimation_small->addSpriteFrameWithFileName("landscapes/splash_small_01.png");
	waterSplashingAnimation_small->addSpriteFrameWithFileName("landscapes/splash_small_02.png");
	waterSplashingAnimation_small->addSpriteFrameWithFileName("landscapes/splash_small_03.png");
	waterSplashingAnimation_small->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	waterSplashingAnimation_small->setRestoreOriginalFrame(true);

	Sprite * smallSplash = Sprite::create("landscapes/splash_big_00.png");
	smallSplash->setPositionX(this->getPositionX());
	smallSplash->setPositionY(((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY());
	this->getParent()->addChild(smallSplash);
	auto waterSplashin = Animate::create(waterSplashingAnimation_small);
	auto delayTime = DelayTime::create(0.7f);
	auto seq = Sequence::create(waterSplashin, delayTime, nullptr);
	smallSplash->runAction(seq);
	auto func11 = CallFunc::create([this](){ pauseflag = 0; f();  wanderAbout(); });
	auto temp = (Stage1GameplayLayer*)this->getParent();
	temp->removeChild(smallSplash);
	});

	auto delayTime = DelayTime::create(0.5f);
	auto seq = Sequence::create(func1, delayTime,func2, nullptr);
	this->runAction(seq);
	*/
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
		auto delayTime = DelayTime::create(1.f);
		auto func = CallFunc::create([this](){ pauseflag = 0; f(); wanderAbout(); });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);
	}

	else{
		die(x_dis < 0 ? true : false);
	}
}

void Bird_zwc::getCollided(int damage){//被鲲冲撞到的动画，需要有一个小位移，鲲如果在左边就往右边位移一下，鲲如果在右边就往左边位移一下（更高级的做法是沿着远离鲲的方向位移一下）。播放一次，播放完进入正常活动状态或直接死掉，调一下die或dieOnCollision
	getHurt(damage);
}

void Bird_zwc::dieOnSlamDunk(){ 			//精良死法，可做可不做，如果做了请做成软趴趴死在地上的样子。如果被投技直接砸死，调用它会更流畅一点，这是增加流畅性的小trick
	getHurt(10000);
}
void Bird_zwc::dieOnCollision(){ 		//史诗死法，可做可不做，如果做了请做成被撞死的样子。如果被冲撞直接撞死，调用它会更流畅一点，这是增加流畅性的小trick
	getHurt(10000);
}

Bird_zwc::~Bird_zwc()
{
}
