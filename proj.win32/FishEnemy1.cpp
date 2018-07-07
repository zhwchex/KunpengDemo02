// ==================================================
//
// Author: GIFTED-BOY
// Email: 120138380@qq.com
// Create Time: 2018.07.02
// Version: v1.0
//
// ==================================================

#include "FishEnemy1.h"
#include "Stage1GameplayLayer.h"

FishEnemy1::FishEnemy1()
{
	state = STATE_DEFAULT; // 当前状态
	health = 100; // 血量
	camp = 2; // 阵营
	speed = 10; // 速度
	hurt = 10; // 伤害
	lockDist = 500; // 锁敌距离（离敌人这么远的时候才可能发现敌人）
	attackDist = 100; // 攻击距离（离敌人这么远的时候才可能发动攻击）
	discoverProb = 0.5; // 发现敌人的概率
	attackProb = 0.3; // 发动攻击的概率
	runProb = 0.7; // 走动的概率（有可能停在原地不走）

	defaultAnimation = Animation::create();
	defaultAnimation->addSpriteFrameWithFileName("enemyfish/enemyfish_hovering_facing_left_00.png");
	defaultAnimation->addSpriteFrameWithFileName("enemyfish/enemyfish_hovering_facing_left_01.png");
	defaultAnimation->addSpriteFrameWithFileName("enemyfish/enemyfish_hovering_facing_left_02.png");
	defaultAnimation->addSpriteFrameWithFileName("enemyfish/enemyfish_hovering_facing_left_03.png");
	defaultAnimation->setDelayPerUnit(FRAME_RATE);
	defaultAnimation->setRestoreOriginalFrame(true);
	defaultAnimation->retain();

	attackAnimation = Animation::create();
	attackAnimation->addSpriteFrameWithFileName("enemyfish/enemyfish_attack_00.png");
	attackAnimation->addSpriteFrameWithFileName("enemyfish/enemyfish_attack_01.png");
	attackAnimation->addSpriteFrameWithFileName("enemyfish/enemyfish_attack_02.png");
	attackAnimation->addSpriteFrameWithFileName("enemyfish/enemyfish_attack_03.png");
	attackAnimation->setDelayPerUnit(FRAME_RATE);
	attackAnimation->setRestoreOriginalFrame(true);
	attackAnimation->retain();
	ValueMap attackEndInfo;
	attackEndInfo["1"] = Value(120);
	attackAnimation->getFrames().at(3)->setUserInfo(attackEndInfo);

	beAttackedAnimation = Animation::create();
	beAttackedAnimation->addSpriteFrameWithFileName("enemyfish/enemyfish_get_hurt_00.png");
	beAttackedAnimation->addSpriteFrameWithFileName("enemyfish/enemyfish_get_hurt_01.png");
	beAttackedAnimation->addSpriteFrameWithFileName("enemyfish/enemyfish_get_hurt_02.png");
	beAttackedAnimation->addSpriteFrameWithFileName("enemyfish/enemyfish_get_hurt_03.png");
	beAttackedAnimation->setDelayPerUnit(FRAME_RATE);
	beAttackedAnimation->setRestoreOriginalFrame(true);
	beAttackedAnimation->retain();
	ValueMap beAttackedInfo;
	beAttackedInfo["1"] = Value(121);
	beAttackedAnimation->getFrames().at(3)->setUserInfo(beAttackedInfo);

	deadAnimation = Animation::create();
	deadAnimation->addSpriteFrameWithFileName("enemyfish/enemyfish_die_00.png");
	deadAnimation->addSpriteFrameWithFileName("enemyfish/enemyfish_die_01.png");
	deadAnimation->addSpriteFrameWithFileName("enemyfish/enemyfish_die_02.png");
	deadAnimation->addSpriteFrameWithFileName("enemyfish/enemyfish_die_03.png");
	deadAnimation->setDelayPerUnit(FRAME_RATE);
	deadAnimation->setRestoreOriginalFrame(true);
	deadAnimation->retain();
	ValueMap deadInfo;
	deadInfo["1"] = Value(122);
	deadAnimation->getFrames().at(3)->setUserInfo(deadInfo);

	EventListenerCustom *animationListener = EventListenerCustom::create(AnimationFrameDisplayedNotification,
		[this, attackEndInfo, beAttackedInfo, deadInfo](EventCustom *event) {
		auto userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == attackEndInfo || *userData->userInfo == beAttackedInfo) // 如果播放完攻击动画或者被攻击动画
		{
			this->state = STATE_DEFAULT; // 状态置为默认
			this->stopAllActions();
			this->runAction(RepeatForever::create(Animate::create(this->defaultAnimation)));
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(animationListener, -1);

	runAction(RepeatForever::create(Animate::create(defaultAnimation)));
}

FishEnemy1::~FishEnemy1() {}

GeneralUnit * FishEnemy1::create(const std::string & filename)
{
	GeneralUnit *myUnit = new FishEnemy1();
	if (myUnit && myUnit->initWithFile(filename)) {
		myUnit->autorelease();
		return myUnit;
	}
	CC_SAFE_DELETE(myUnit);
	return nullptr;
}

void FishEnemy1::wanderAbout()
{
	if (state != STATE_DEFAULT) return;

	Stage1GameplayLayer *gamePlayer = (Stage1GameplayLayer *) getParent();
	Sprite *hero = gamePlayer->kunpeng;

	Vec2 heroPos = hero->getPosition();
	float dist = heroPos.distance(getPosition());
	//log("dist -----> %f", dist);
	srand((unsigned int)time(0));
	if (dist < lockDist) // 如果敌人进入了锁敌距离
	{
		if (dist < attackDist && rand() % 12 / 11.0 < attackProb) // 如果敌人进入了攻击距离且满足攻击概率
		{
			attack(heroPos);
			return;
		}
		if (rand() % 12 / 11.0 < discoverProb) // 如果满足发现敌人的概率
		{
			float angle = asin((heroPos.y - getPositionY()) / dist); // 计算与敌人之间的角度
			//log("angle -----> %f", CC_RADIANS_TO_DEGREES(angle));
			state = STATE_ROTATE; // 状态置为正在旋转
			runAction(Sequence::create(
				RotateTo::create(ANIMATION_DURATION, // 先转到面朝敌人
					CC_RADIANS_TO_DEGREES(heroPos.x > getPositionX() ? M_PI - angle : angle)),
				MoveTo::create(ANIMATION_DURATION, // 然后朝敌人移动
					Point(getPositionX() + (heroPos.x > getPositionX() ? 1 : -1) * speed * cos(angle),
					getPositionY() + speed * sin(angle))),
				CallFunc::create([this]() { this->state = STATE_DEFAULT; }), // 最后状态置为默认
				NULL));
			return;
		}
	}
	wander(); // 随机行动
}

void FishEnemy1::getHurt(int h)
{
	if (STATE_DEAD == state) return;

	state = STATE_BE_ATTACKED;
	health -= h;
	if (health <= 0) die();
	else
	{
		stopAllActions();
		runAction(Animate::create(beAttackedAnimation));
	}
}

void FishEnemy1::die()
{
	state = STATE_DEAD;
	stopAllActions();
	runAction(Animate::create(deadAnimation));
}

void FishEnemy1::wander()
{
	if (rand() % 12 / 11.0 < runProb) // 如果满足走动的概率
	{
		float angle = (rand() % 361) * M_PI / 180; // 随机获取一个角度
		state = STATE_ROTATE;
		runAction(Sequence::create(
			RotateTo::create(ANIMATION_DURATION, CC_RADIANS_TO_DEGREES(angle)), // 转
			MoveTo::create(ANIMATION_DURATION, // 走
				Point(getPositionX() - speed * cos(angle), getPositionY() + speed * sin(angle))),
			CallFunc::create([this]() { this->state = STATE_DEFAULT; }), // 状态置为默认
			NULL));
	}
}

void FishEnemy1::attack(Vec2 pos)
{
	if (state != STATE_DEFAULT) return;

	state = STATE_ATTACK;
	stopAllActions();
	runAction(Animate::create(attackAnimation));
}
