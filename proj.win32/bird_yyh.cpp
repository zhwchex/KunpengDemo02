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
	this->setAnchorPoint(Point(0.5f, 0.5f));
	Bullet* bullet = Bullet::create(this);
	this->addChild(bullet, 1, "bu");
	this->leftAnimation = Animation::create();
	this->leftAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/left1.png");
	this->leftAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/left2.png");
	this->leftAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/left3.png");
	this->leftAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/left4.png");
	this->leftAnimation->setDelayPerUnit(0.3f);  // 设置动画帧率
	this->leftAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->leftAnimation->retain();

	this->hoveringAnimation = Animation::create();
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/left1.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/right1.png");
	//this->hoveringAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/bird3.png");
	this->hoveringAnimation->setDelayPerUnit(0.5f);  // 设置动画帧率
	this->hoveringAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->hoveringAnimation->retain();

	

	this->rightAnimation = Animation::create();
	this->rightAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/right1.png");
	this->rightAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/right2.png");
	this->rightAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/right3.png");
	this->rightAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/right4.png");
	this->rightAnimation->setDelayPerUnit(0.3f);  // 设置动画帧率
	this->rightAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->rightAnimation->retain();

	this->leftturnAnimation = Animation::create();
	this->leftturnAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/leftturn1.png");
	this->leftturnAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/leftturn2.png");
	this->leftturnAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/leftturn3.png");
	this->leftturnAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/leftturn4.png");
	this->leftturnAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/leftturn5.png");
	this->leftturnAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/leftturn6.png");
	this->leftturnAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/leftturn7.png");
	this->leftturnAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/leftturn8.png");
	this->leftturnAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/leftturn9.png");
	this->leftturnAnimation->setDelayPerUnit(0.2f);  // 设置动画帧率
	this->leftturnAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->leftturnAnimation->retain();

	this->rightturnAnimation = Animation::create();
	this->rightturnAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/rightturn1.png");
	this->rightturnAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/rightturn2.png");
	this->rightturnAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/rightturn3.png");
	this->rightturnAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/rightturn4.png");
	this->rightturnAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/rightturn5.png");
	this->rightturnAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/rightturn6.png");
	this->rightturnAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/rightturn7.png");
	this->rightturnAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/rightturn8.png");
	this->rightturnAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/rightturn9.png");
	this->rightturnAnimation->setDelayPerUnit(0.2f);  // 设置动画帧率
	this->rightturnAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->rightturnAnimation->retain();

	this->lefthurtAnimation = Animation::create();
	this->lefthurtAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/hurtleft1.png");
	this->lefthurtAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/hurtleft2.png");
	this->lefthurtAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/hurtleft3.png");
	this->lefthurtAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/hurtleft4.png");
	this->lefthurtAnimation->setDelayPerUnit(0.5f);  // 设置动画帧率
	this->lefthurtAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->lefthurtAnimation->retain();

	this->righthurtAnimation = Animation::create();
	this->righthurtAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/hurtright1.png");
	this->righthurtAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/hurtright2.png");
	this->righthurtAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/hurtright3.png");
	this->righthurtAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/hurtright4.png");
	this->righthurtAnimation->setDelayPerUnit(0.5f);  // 设置动画帧率
	this->righthurtAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->righthurtAnimation->retain();

	this->leftdieAnimation = Animation::create();
	this->leftdieAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/bird2.png");
	this->leftdieAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/dieleft2.png");
	this->leftdieAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/dieleft3.png");
	this->leftdieAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/dieleft4.png");
	this->leftdieAnimation->setDelayPerUnit(0.5f);  // 设置动画帧率
	this->leftdieAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->leftdieAnimation->retain();

	this->rightdieAnimation = Animation::create();
	this->rightdieAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/bird3.png");
	this->rightdieAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/dieright2.png");
	this->rightdieAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/dieright3.png");
	this->rightdieAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/dieright4.png");
	this->rightdieAnimation->setDelayPerUnit(0.5f);  // 设置动画帧率
	this->rightdieAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->rightdieAnimation->retain();

	this->leftfightAnimation = Animation::create();
	this->leftfightAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/fightleft1.png");
	this->leftfightAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/fightleft2.png");
	this->leftfightAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/fightleft3.png");
	this->leftfightAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/fightleft4.png");
	this->leftfightAnimation->setDelayPerUnit(0.25f);  // 设置动画帧率
	this->leftfightAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->leftfightAnimation->retain();

	this->rightfightAnimation = Animation::create();
	this->rightfightAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/fightright1.png");
	this->rightfightAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/fightright2.png");
	this->rightfightAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/fightright3.png");
	this->rightfightAnimation->addSpriteFrameWithFileName("characters/Bird_yyh/fightright4.png");
	this->rightfightAnimation->setDelayPerUnit(0.25f);  // 设置动画帧率
	this->rightfightAnimation->setRestoreOriginalFrame(true);// 设置动画播放完毕后是否回到第一帧
	this->rightfightAnimation->retain();

	//auto action = Animate::create(hoveringAnimation);
	//this->runAction(RepeatForever::create(action));
	//this->runAction(Animate::create(this->hoveringAnimation));
	//this->runAction(cocos2d::RepeatForever::create(action));
	
	
	//addChild(sprite);
	//this->addChild(sprite);
	//this->runAction(Animate::create(hoveringAnimation));
	scheduleUpdate();

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
	auto temp_bullet =(Bullet*) this->getChildByName("bu");
	auto temp = (Stage1GameplayLayer*)this->getParent();
	auto hero = temp->kunpeng;
	Vector <Sprite *> birdBullet = temp_bullet->GetBullet();
	
	for (int i = 0; i<birdBullet.size(); i++){
		Point t = birdBullet.at(i)->getPosition() + this->getPosition() - Vec2(50,50);
		//cout << t.x << ' ' << t.y << endl;
		if (hero->boundingBox().containsPoint(t)){
			//temp_bullet->removeBullet(birdBullet.at(i));
			//cout << "bossshoushang" << endl;
			temp->kunpeng->getHurtGeneral(10);
		}
		
	}

	
}
void Bird_yyh::wanderAbout(){
	if (dieflag == 0 && pauseflag == 0){
	//scheduleUpdate();
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
	//auto temp_bullet = (Bullet*)temp->getChildByName("bu");
	auto temp_bullet = this->getChildByName("bu");
	float battledistance = 450;
	//float x = cos(asin(0.5));
	//cout << x << endl;
	//int x_scope, y_scope;
	float x_dis = hero.x - bird.x;
	float y_dis = hero.y - bird.y;

	float x_scala = (rand() % 201 - 100) / 100.0;
	float y_scala = (rand() % 201 - 100) / 100.0;  //先获得（-1,1）的百分位的随机小数
	int change = 1;
	/*
	this->runAction(MoveBy::create(1.0f, Vec2(x_scala*change, y_scala*change)));
	lockBirdWithinLandscape();
	//temp_bullet->schedule(schedule_selector(Bullet::ShootBullet), 2.0f);
	if (distance <= battledistance && flag == 0){
	cout << "come in" << endl;

	temp_bullet->schedule(schedule_selector(Bullet::ShootBullet), 2.0f);
	flag = 1;

	}
	if (distance > battledistance && flag == 1){
	cout << "stop" << endl;
	temp_bullet->unschedule(schedule_selector(Bullet::ShootBullet));
	flag = 0;
	}
	*/
	if (distance <= battledistance){

		x_change = bird_step*(cos(atan(x_dis / y_dis)));
		y_change = bird_step*(sin(atan(x_dis / y_dis)));
		if (x_dis >= 0)
			x_scope = 1;
		else
			x_scope = -1;
		if (y_dis >= 0)
			y_scope = 1;
		else
			y_scope = -1;


		if (x_dis == 0){
			if (dir < 0){
				Lockturnleft(1);
			}
			else{
				Lockturnright(1);
			}

		}
		else if (y_dis == 0){
			//this->stopAllActions();
			if (x_scope > 0){
				Lockturnright(2);
			}
			else{
				Lockturnleft(2);
			}



		}
		else{
			//this->stopAllActions();
			if (x_scope > 0)
				Lockturnright(3);
			else
				Lockturnleft(3);
			//this->runAction(MoveBy::create(1.0f, Vec2(x_scope * abs(x_change), y_scope * abs(y_change))));
		}

		lockBirdWithinLandscape();
		if (flag == 0 && dieflag == 0){
			temp_bullet->schedule(schedule_selector(Bullet::ShootBullet), 2.0f);
			//cout << "come in" << endl;
			//this->runAction(Animate::create(this->rightAnimation));
			/*
			if (dir = -1){
				auto fi = Animate::create(this->leftfightAnimation);
				auto func = CallFunc::create([this](){
				auto temp_bullet = this->getChildByName("bu");
				 });
				auto seq = Sequence::create(fi, func, nullptr);
				this->runAction(seq);
			}
				
			else{
				auto fi = Animate::create(this->rightfightAnimation);
				auto func = CallFunc::create([this](){
				auto temp_bullet = this->getChildByName("bu");
				temp_bullet->schedule(schedule_selector(Bullet::ShootBullet), 2.0f); });
				auto seq = Sequence::create(fi, func, nullptr);
				this->runAction(seq);

			}
				
			*/
			
			flag = 1;

		}

	}
	if (distance > battledistance){
		cout << this->getPosition().x << ' '<<this->getPosition().y << endl;
		Lockhoving();
		dir = 0;
		this->runAction(MoveBy::create(1.0f, Vec2(x_scala*change, y_scala*change)));
		lockBirdWithinLandscape();
		if (flag == 1 && dieflag == 0){
			//cout << "stop" << endl;
			temp_bullet->unschedule(schedule_selector(Bullet::ShootBullet));
			flag = 0;
		}

	}

  }
	
}

void Bird_yyh::f(){
	lock = 0;
}
void Bird_yyh::Lockright(){
	if (lock == 0){
		lock = 1;
		this->runAction(Animate::create(this->rightAnimation));
		auto delayTime = DelayTime::create(1.0f);
		auto func = CallFunc::create([this](){ lock = 0; });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this -> runAction(seq);
	}
	
}
void Bird_yyh::Lockfightleft(){
	if (lock == 0){
		lock = 1;
		this->runAction(Animate::create(this->leftfightAnimation));
		auto delayTime = DelayTime::create(1.0f);
		auto func = CallFunc::create([this](){ lock = 0; });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);
	}

}

void Bird_yyh::Lockfightright(){
	if (lock == 0){
		lock = 1;
		this->runAction(Animate::create(this->rightfightAnimation));
		auto delayTime = DelayTime::create(1.0f);
		auto func = CallFunc::create([this](){ lock = 0; });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);
	}

}

void Bird_yyh::Lockhoving(){
	if (lock == 0){
		//cout << "大于" << endl;
		lock = 1;
		//auto action = Animate::create(this->hoveringAnimation);
		auto an = Animate::create(this->hoveringAnimation);
		this->runAction(Sequence::create(an, an, nullptr));
		//this->runAction(action);
;		auto delayTime = DelayTime::create(1.0f);
		auto func = CallFunc::create([this](){ lock = 0; });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);
	}

}

void Bird_yyh::Lockleft(){
	if (lock == 0){
		lock = 1;
		this->runAction(Animate::create(this->leftAnimation));
		auto delayTime = DelayTime::create(1.0f);
		auto func = CallFunc::create([this](){ lock = 0; });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);
	}
}

void Bird_yyh::Lockturnleft(int type){
	if (lock == 0){
		lock = 1;
		if (dir == 1){
			dir = -1;
			this->stopAllActions();
			//auto temp_bullet = this->getChildByName("bu");
			//pauseflag = 1;
			//temp_bullet->unschedule(schedule_selector(Bullet::ShootBullet));
			//flag = 0;
			auto rightturn = Animate::create(this->rightturnAnimation);
			auto left = Animate::create(this->leftAnimation);
			//Sequence* sequence = Sequence::create(rightturn, left, NULL);
			//this->runAction(rightturn);
			auto delayTime = DelayTime::create(1.8f);
			auto func = CallFunc::create([this](){  lock = 0;  });
			auto seq = Sequence::create(rightturn,left, func, nullptr);
			
			this->runAction(seq);
		}
		else{
			
			//cout << "dir不等于1" << endl;
			auto an = Animate::create(this->leftAnimation);
			this->runAction(an);
			auto delayTime = DelayTime::create(1.2f);
			auto func = CallFunc::create([this](){ dir = -1; lock = 0; });
			auto seq = Sequence::create(delayTime, func, nullptr);
			this->runAction(seq);
			//cout << "dir:" << dir << ' ' << lock << endl;
			if (type == 1)
				this->runAction(MoveBy::create(1.0f, Vec2(0, y_scope * bird_step)));
			if (type == 2)
				this->runAction(MoveBy::create(1.0f, Vec2(x_scope * bird_step, 0)));
			if (type == 3)
				this->runAction(MoveBy::create(3.0f, 3 * Vec2(x_scope * abs(x_change), y_scope * abs(y_change))));
		}
		
		
	}

}

void Bird_yyh::Lockturnright(int type){
	if (lock == 0){
		lock = 1;
		if (dir == -1){
			dir = 1;
			//auto temp_bullet = this->getChildByName("bu");
			//pauseflag = 1;
			//temp_bullet->unschedule(schedule_selector(Bullet::ShootBullet));
			//flag = 0;
			this->stopAllActions();
			//cout << "turn right!" << endl;
			auto leftturn = Animate::create(this->leftturnAnimation);
			auto right = Animate::create(this->rightAnimation);
			//Sequence* sequence = Sequence::create(leftturn, right, NULL);
			//this->runAction(leftturn);
			auto delayTime = DelayTime::create(1.8f);
			auto func = CallFunc::create([this](){ lock = 0;  });
			auto seq = Sequence::create(leftturn,right, func, nullptr);
			this->runAction(seq);
		}
		else{
		
			auto an = Animate::create(this->rightAnimation);
			this->runAction(an);
			
			auto delayTime = DelayTime::create(1.1f);
			auto func = CallFunc::create([this](){ dir = 1; lock = 0; });
			auto seq = Sequence::create(delayTime, func, nullptr);
			this->runAction(seq);
			if (type == 1)
				this->runAction(MoveBy::create(1.0f, Vec2(0, y_scope * bird_step)));
			if (type == 2)
				this->runAction(MoveBy::create(1.0f, Vec2(x_scope * bird_step, 0)));
			if (type == 3)
				this->runAction(MoveBy::create(3.0f, 3 * Vec2(x_scope * abs(x_change), y_scope * abs(y_change))));
		}
	}
	
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


void Bird_yyh::getHurtByWind(int damage){
	//unscheduleUpdate(); 
	if (dieflag == 0){
		pauseflag = 1;
		this->stopAllActions();

		health = health - damage;
		auto temp = (Stage1GameplayLayer*)this->getParent();
		//auto temp_bullet = (Bullet*)temp->getChildByName("bu");
		auto temp_bullet = this->getChildByName("bu");
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
			dieflag = 1;
			if (dir == -1 || dir == 0)
				this->runAction(Animate::create(leftdieAnimation));
			if (dir == 1)
				this->runAction(Animate::create(rightdieAnimation));

			auto delayTime = DelayTime::create(2.0f);
			auto func = CallFunc::create([this](){
				auto temp = (Stage1GameplayLayer*)this->getParent();
				temp->removeChild(this);

				//temp->removeChildByName("bu");
				this->removeChildByName("bu");

				//temp->removeChildByName("bu");

				temp->enemyList.eraseObject(this); });
			auto seq = Sequence::create(delayTime, func, nullptr);
			this->runAction(seq);


		}
	}
}



void Bird_yyh::getHurtByPaw(int damage){      //yyhyyh
	//unscheduleUpdate(); 
	if (dieflag == 0){
	pauseflag = 1;
	this->stopAllActions();

	health = health - damage;
	auto temp = (Stage1GameplayLayer*)this->getParent();
	//auto temp_bullet = (Bullet*)temp->getChildByName("bu");
	auto temp_bullet = this->getChildByName("bu");
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
		dieflag = 1;
		if (dir == -1 || dir == 0)
			this->runAction(Animate::create(leftdieAnimation));
		if (dir == 1)
			this->runAction(Animate::create(rightdieAnimation));

		auto delayTime = DelayTime::create(2.0f);
		auto func = CallFunc::create([this](){
			auto temp = (Stage1GameplayLayer*)this->getParent();
			temp->removeChild(this);

			//temp->removeChildByName("bu");
			this->removeChildByName("bu");
			//temp->removeChildByName("bu");

			temp->enemyList.eraseObject(this); });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);


	}
  }
}

void Bird_yyh::getHurtByCrush(int damage){
	//unscheduleUpdate(); 
	if (dieflag == 0){
		pauseflag = 1;
		this->stopAllActions();

		health = health - damage;
		auto temp = (Stage1GameplayLayer*)this->getParent();
		//auto temp_bullet = (Bullet*)temp->getChildByName("bu");
		auto temp_bullet = this->getChildByName("bu");
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
			dieflag = 1;
			if (dir == -1 || dir == 0)
				this->runAction(Animate::create(leftdieAnimation));
			if (dir == 1)
				this->runAction(Animate::create(rightdieAnimation));

			auto delayTime = DelayTime::create(1.0f);
			auto func = CallFunc::create([this](){
				auto temp = (Stage1GameplayLayer*)this->getParent();
				temp->removeChild(this);

				//temp->removeChildByName("bu");
				this->removeChildByName("bu");
				//temp->removeChildByName("bu");

				temp->enemyList.eraseObject(this); });
			auto seq = Sequence::create(delayTime, func, nullptr);
			this->runAction(seq);


		}
	}

}

void Bird_yyh::getHurtByWater(int damage){
	//unscheduleUpdate(); 
	if (dieflag == 0){
		pauseflag = 1;
		this->stopAllActions();

		health = health - damage;
		auto temp = (Stage1GameplayLayer*)this->getParent();
		//auto temp_bullet = (Bullet*)temp->getChildByName("bu");
		auto temp_bullet = this->getChildByName("bu");
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
			dieflag = 1;
			if (dir == -1 || dir == 0){
				this->runAction(Animate::create(leftdieAnimation));
			}
				
			if (dir == 1){
				//this->runAction(Animate::create(rightdieAnimation));
				auto die = Animate::create(rightdieAnimation);
				auto tinkTo =Blink::create(2.0f,4);
				//auto se = Spawn::create(die,tinkTo);
				this->runAction(die);
				this->runAction(tinkTo);
			}
				
			
			
			auto delayTime = DelayTime::create(2.0f);
			auto func = CallFunc::create([this](){
				auto temp = (Stage1GameplayLayer*)this->getParent();
				this->removeChildByName("bu");
				temp->removeChild(this);

				//temp->removeChildByName("bu");

				

				temp->enemyList.eraseObject(this); });
			auto seq = Sequence::create(delayTime, func, nullptr);
			this->runAction(seq);


		}
	}

}

void Bird_yyh::getHurtByFin(int damage){
	//unscheduleUpdate(); 
	if (dieflag == 0){
		pauseflag = 1;
		this->stopAllActions();

		health = health - damage;
		auto temp = (Stage1GameplayLayer*)this->getParent();
		//auto temp_bullet = (Bullet*)temp->getChildByName("bu");
		auto temp_bullet = this->getChildByName("bu");
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
			dieflag = 1;
			if (dir == -1 || dir == 0)
				this->runAction(Animate::create(leftdieAnimation));
			if (dir == 1)
				this->runAction(Animate::create(rightdieAnimation));

			auto delayTime = DelayTime::create(2.0f);
			auto func = CallFunc::create([this](){
				auto temp = (Stage1GameplayLayer*)this->getParent();
				temp->removeChild(this);

				//temp->removeChildByName("bu");

				this->removeChildByName("bu");

				temp->enemyList.eraseObject(this); });
			auto seq = Sequence::create(delayTime, func, nullptr);
			this->runAction(seq);


		}
	}
}
Bird_yyh::~Bird_yyh()
{
}
