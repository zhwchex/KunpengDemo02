#include "Bullet.h"
#include "Stage1GameplayLayer.h"
#include "bird_yyh.h"
#include <iostream>
using namespace std;
Bullet::Bullet(Bird_yyh* b) {
	this->b = b;
}
Bullet::~Bullet() {
}

Bullet* Bullet::create(Bird_yyh* b){
	Bullet* bu = new Bullet(b);
	if (bu&&bu->init()){
		bu->autorelease();
		return bu;
	}
	else{
		delete bu;
		bu = NULL;
		return NULL;
	}

}
bool Bullet::init() {
	bool bRet = false;	
	do {
		//AllocConsole();                                          // 开辟控制台
		//freopen("CONOUT$", "w", stdout);
		//Point birdPos = b->getPosition();
		//cout << birdPos.x << ' ' << birdPos.y << endl;

		//创建BatchNode节点

		bulletBatchNode = SpriteBatchNode::create("characters/Bird_yyh/bullet.png",50);
		this->addChild(bulletBatchNode);
		//Bullet::ShootBullet();
		//每隔0.2S调用一次发射子弹函数
		//this->schedule(schedule_selector(Bullet::ShootBullet), 0.1f);
		bRet = true;
	} while (0);
	return bRet;
}
/**
*用缓存的方法创建子弹，并初始化子弹的运动和运动后的事件
*/
void Bullet::ShootBullet(float dt) {
	//AllocConsole();                                          // 开辟控制台
	//freopen("CONOUT$", "w", stdout);
	Size winSize = Director::getInstance()->getWinSize();
	Point birdPos = b->getPosition();
	//cout << birdPos.x << ' ' << birdPos.y << endl;
	//从缓存中创建子弹
	auto spritebullet = Sprite::createWithTexture(bulletBatchNode->getTexture());
	//将创建好的子弹添加到BatchNode中进行批次渲染
	bulletBatchNode->addChild(spritebullet);
	//将创建好的子弹添加到容器
	vecBullet.pushBack(spritebullet);
	
	Point bulletPos = birdPos;
	spritebullet->setPosition(bulletPos);
	spritebullet->setScale(0.8f);


	float Duration =0.5f;//实际飞行的时间
	//auto b_temp = (Bird_yyh*)this->getParent();
	auto temp = (Stage1GameplayLayer*)b->getParent();
	Point hero = temp->kunpeng->getPosition();
	//cout << hero.x << ' ' << hero.y << endl;
	
	auto actionMove = MoveTo::create(Duration, hero);
	//auto actionMove = BezierTo::create(Duration, hero);

	//子弹执行完动作后进行函数回调，调用移除子弹函数
	auto actionDone = CallFuncN::create(CC_CALLBACK_1(Bullet::removeBullet, this));

	//子弹开始跑动
	Sequence* sequence = Sequence::create(actionMove, actionDone, NULL);
	spritebullet->runAction(sequence);


}

/**
* 移除子弹，将子弹从容器中移除，同时也从SpriteBatchNode中移除
*/
void Bullet::removeBullet(Node* bu) {
	if (NULL == bu) {
		return;
	}
	Sprite* bullet = (Sprite*)bu;
	this->bulletBatchNode->removeChild(bullet, true);
	vecBullet.eraseObject(bullet);
}
/**
*返回子弹列表
*/
Vector <Sprite *>& Bullet::GetBullet(){
	return vecBullet;
}