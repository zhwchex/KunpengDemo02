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
		//AllocConsole();                                          // ���ٿ���̨
		//freopen("CONOUT$", "w", stdout);
		//Point birdPos = b->getPosition();
		//cout << birdPos.x << ' ' << birdPos.y << endl;

		//����BatchNode�ڵ�

		bulletBatchNode = SpriteBatchNode::create("characters/Bird_yyh/bullet.png",50);
		this->addChild(bulletBatchNode);
		//Bullet::ShootBullet();
		//ÿ��0.2S����һ�η����ӵ�����
		//this->schedule(schedule_selector(Bullet::ShootBullet), 0.1f);
		bRet = true;
	} while (0);
	return bRet;
}
/**
*�û���ķ��������ӵ�������ʼ���ӵ����˶����˶�����¼�
*/
void Bullet::ShootBullet(float dt) {
	//AllocConsole();                                          // ���ٿ���̨
	//freopen("CONOUT$", "w", stdout);
	Size winSize = Director::getInstance()->getWinSize();
	Point birdPos = b->getPosition();
	//cout << birdPos.x << ' ' << birdPos.y << endl;
	//�ӻ����д����ӵ�
	auto spritebullet = Sprite::createWithTexture(bulletBatchNode->getTexture());
	//�������õ��ӵ����ӵ�BatchNode�н���������Ⱦ
	bulletBatchNode->addChild(spritebullet);
	//�������õ��ӵ����ӵ�����
	vecBullet.pushBack(spritebullet);
	
	Point bulletPos = birdPos;
	spritebullet->setPosition(bulletPos);
	spritebullet->setScale(0.8f);


	float Duration =0.5f;//ʵ�ʷ��е�ʱ��
	//auto b_temp = (Bird_yyh*)this->getParent();
	auto temp = (Stage1GameplayLayer*)b->getParent();
	Point hero = temp->kunpeng->getPosition();
	//cout << hero.x << ' ' << hero.y << endl;
	
	auto actionMove = MoveTo::create(Duration,hero);

	//�ӵ�ִ���궯������к����ص��������Ƴ��ӵ�����
	auto actionDone = CallFuncN::create(CC_CALLBACK_1(Bullet::removeBullet, this));

	//�ӵ���ʼ�ܶ�
	Sequence* sequence = Sequence::create(actionMove, actionDone, NULL);
	spritebullet->runAction(sequence);


}

/**
* �Ƴ��ӵ������ӵ����������Ƴ���ͬʱҲ��SpriteBatchNode���Ƴ�
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
*�����ӵ��б�
*/
Vector <Sprite *>& Bullet::GetBullet(){
	return vecBullet;
}