#include "EnemyFish.h"
#include "Stage1GameplayLayer.h"
#include <math.h>

EnemyFish::EnemyFish()
{
	this->health = FISHHEALTHY1;
	this->camp = 2;


	//左悬停
	this->hoveringLeftAnimation = Animation::create();
	this->hoveringLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	this->hoveringLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_hovering_facing_left_01.png");
	this->hoveringLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_hovering_facing_left_02.png");
	this->hoveringLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_hovering_facing_left_03.png");
	this->hoveringLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->hoveringLeftAnimation->setRestoreOriginalFrame(true);
	this->hoveringLeftAnimation->retain();

	ValueMap hoveringLeftAnimationReachesfirstFrameInfo;
	ValueMap hoveringLeftAnimationReachesLastFrameInfo;

	hoveringLeftAnimationReachesfirstFrameInfo["asd"] = Value(2);
	hoveringLeftAnimationReachesLastFrameInfo["0"] = Value(0);

	this->hoveringLeftAnimation->getFrames().at(0)->setUserInfo(hoveringLeftAnimationReachesfirstFrameInfo);

	this->hoveringLeftAnimation->getFrames().at(3)->setUserInfo(hoveringLeftAnimationReachesLastFrameInfo);

	EventListenerCustom * hoveringLeftAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, hoveringLeftAnimationReachesLastFrameInfo, hoveringLeftAnimationReachesfirstFrameInfo](EventCustom *event) {
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == hoveringLeftAnimationReachesLastFrameInfo) {
			log("Last frame of hoveringLeftAnimation reached.");
			this->acceptCall = true;
		}
		if (*userData->userInfo == hoveringLeftAnimationReachesfirstFrameInfo) {
			log("First frame of hoveringLeftAnimation reached.");
			this->acceptCall = false;
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(hoveringLeftAnimationFrameEventListener, -1);
	
	//右悬停
	this->hoveringRightAnimation = Animation::create();
	this->hoveringRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_hovering_facing_right_00.png");
	this->hoveringRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_hovering_facing_right_01.png");
	this->hoveringRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_hovering_facing_right_02.png");
	this->hoveringRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_hovering_facing_right_03.png");
	this->hoveringRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->hoveringRightAnimation->setRestoreOriginalFrame(true);
	this->hoveringRightAnimation->retain();

	ValueMap hoveringRightAnimationReachesfirstFrameInfo;
	ValueMap hoveringRightAnimationReachesLastFrameInfo;

	hoveringRightAnimationReachesfirstFrameInfo["asd"] = Value(2);
	hoveringRightAnimationReachesLastFrameInfo["0"] = Value(0);

	this->hoveringRightAnimation->getFrames().at(0)->setUserInfo(hoveringRightAnimationReachesfirstFrameInfo);

	this->hoveringRightAnimation->getFrames().at(3)->setUserInfo(hoveringRightAnimationReachesLastFrameInfo);

	EventListenerCustom * hoveringRightAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, hoveringRightAnimationReachesLastFrameInfo, hoveringRightAnimationReachesfirstFrameInfo](EventCustom *event) {
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == hoveringRightAnimationReachesLastFrameInfo) {
			log("Last frame of hoveringRightAnimation reached.");
			this->acceptCall = true;
		}
		if (*userData->userInfo == hoveringRightAnimationReachesfirstFrameInfo) {
			log("First frame of hoveringRightAnimation reached.");
			this->acceptCall = false;
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(hoveringRightAnimationFrameEventListener, -1);

	//上移动
	this->movingUpAnimation = Animation::create();
	this->movingUpAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_up_00.png");
	this->movingUpAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_up_01.png");
	this->movingUpAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_up_02.png");
	this->movingUpAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_up_03.png");
	this->movingUpAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingUpAnimation->setRestoreOriginalFrame(true);
	this->movingUpAnimation->retain();

	ValueMap movingUpAnimationReachesfirstFrameInfo;
	ValueMap movingUpAnimationReachesLastFrameInfo;

	movingUpAnimationReachesfirstFrameInfo["asd"] = Value(2);
	movingUpAnimationReachesLastFrameInfo["0"] = Value(0);

	this->movingUpAnimation->getFrames().at(0)->setUserInfo(movingUpAnimationReachesfirstFrameInfo);

	this->movingUpAnimation->getFrames().at(3)->setUserInfo(movingUpAnimationReachesLastFrameInfo);

	EventListenerCustom * movingUpAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, movingUpAnimationReachesLastFrameInfo, movingUpAnimationReachesfirstFrameInfo](EventCustom *event) {
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == movingUpAnimationReachesLastFrameInfo) {
			log("Last frame of movingUpAnimation reached.");
			this->acceptCall = true;
		}
		if (*userData->userInfo == movingUpAnimationReachesfirstFrameInfo) {
			log("First frame of movingUpAnimation reached.");
			this->acceptCall = false;
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(movingUpAnimationFrameEventListener, -1);
	
	//下移动
	this->movingDownAnimation = Animation::create();
	this->movingDownAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_down_00.png");
	this->movingDownAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_down_01.png");
	this->movingDownAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_down_02.png");
	this->movingDownAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_down_03.png");
	this->movingDownAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingDownAnimation->setRestoreOriginalFrame(true);
	this->movingDownAnimation->retain();

	ValueMap movingDownAnimationReachesfirstFrameInfo;
	ValueMap movingDownAnimationReachesLastFrameInfo;

	movingDownAnimationReachesfirstFrameInfo["asd"] = Value(2);
	movingDownAnimationReachesLastFrameInfo["0"] = Value(0);

	this->movingDownAnimation->getFrames().at(0)->setUserInfo(movingDownAnimationReachesfirstFrameInfo);

	this->movingDownAnimation->getFrames().at(3)->setUserInfo(movingDownAnimationReachesLastFrameInfo);

	EventListenerCustom * movingDownAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, movingDownAnimationReachesLastFrameInfo, movingDownAnimationReachesfirstFrameInfo](EventCustom *event) {
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == movingDownAnimationReachesLastFrameInfo) {
			log("Last frame of movingDownAnimation reached.");
			this->acceptCall = true;
		}
		if (*userData->userInfo == movingDownAnimationReachesfirstFrameInfo) {
			log("First frame of movingDownAnimation reached.");
			this->acceptCall = false;
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(movingDownAnimationFrameEventListener, -1);
	
	//左移动
	this->movingLeftAnimation = Animation::create();
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left_00.png");
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left_01.png");
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left_02.png");
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left_03.png");
	this->movingLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingLeftAnimation->setRestoreOriginalFrame(true);
	this->movingLeftAnimation->retain();

	ValueMap movingLeftAnimationReachesfirstFrameInfo;
	ValueMap movingLeftAnimationReachesLastFrameInfo;

	movingLeftAnimationReachesfirstFrameInfo["asd"] = Value(2);
	movingLeftAnimationReachesLastFrameInfo["0"] = Value(0);

	this->movingLeftAnimation->getFrames().at(0)->setUserInfo(movingLeftAnimationReachesfirstFrameInfo);

	this->movingLeftAnimation->getFrames().at(3)->setUserInfo(movingLeftAnimationReachesLastFrameInfo);

	EventListenerCustom * movingLeftAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, movingLeftAnimationReachesLastFrameInfo, movingLeftAnimationReachesfirstFrameInfo](EventCustom *event) {
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == movingLeftAnimationReachesLastFrameInfo) {
			log("Last frame of movingLeftAnimation reached.");
			this->acceptCall = true;
		}
		if (*userData->userInfo == movingLeftAnimationReachesfirstFrameInfo) {
			log("First frame of movingLeftAnimation reached.");
			this->acceptCall = false;
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(movingLeftAnimationFrameEventListener, -1);
	
	//右移动
	this->movingRightAnimation = Animation::create();
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right_00.png");
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right_01.png");
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right_02.png");
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right_03.png");
	this->movingRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingRightAnimation->setRestoreOriginalFrame(true);
	this->movingRightAnimation->retain();
	
	ValueMap movingRightAnimationReachesfirstFrameInfo;
	ValueMap movingRightAnimationReachesLastFrameInfo;

	movingRightAnimationReachesfirstFrameInfo["asd"] = Value(2);
	movingRightAnimationReachesLastFrameInfo["0"] = Value(0);

	this->movingRightAnimation->getFrames().at(0)->setUserInfo(movingRightAnimationReachesfirstFrameInfo);

	this->movingRightAnimation->getFrames().at(3)->setUserInfo(movingRightAnimationReachesLastFrameInfo);

	EventListenerCustom * movingRightAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, movingRightAnimationReachesLastFrameInfo, movingRightAnimationReachesfirstFrameInfo](EventCustom *event) {
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == movingRightAnimationReachesLastFrameInfo) {
			log("Last frame of movingRightAnimation reached.");
			this->acceptCall = true;
		}
		if (*userData->userInfo == movingRightAnimationReachesfirstFrameInfo) {
			log("First frame of movingRightAnimation reached.");
			this->acceptCall = false;
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(movingRightAnimationFrameEventListener, -1);

	//右上移动
	this->movingUpRightAnimation = Animation::create();
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right-up_00.png");
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right-up_01.png");
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right-up_02.png");
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right-up_03.png");
	this->movingUpRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingUpRightAnimation->setRestoreOriginalFrame(true);
	this->movingUpRightAnimation->retain();
	
	ValueMap movingUpRightAnimationReachesfirstFrameInfo;
	ValueMap movingUpRightAnimationReachesLastFrameInfo;

	movingUpRightAnimationReachesfirstFrameInfo["asd"] = Value(2);
	movingUpRightAnimationReachesLastFrameInfo["0"] = Value(0);

	this->movingUpRightAnimation->getFrames().at(0)->setUserInfo(movingUpRightAnimationReachesfirstFrameInfo);

	this->movingUpRightAnimation->getFrames().at(3)->setUserInfo(movingUpRightAnimationReachesLastFrameInfo);

	EventListenerCustom * movingUpRightAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, movingUpRightAnimationReachesLastFrameInfo, movingUpRightAnimationReachesfirstFrameInfo](EventCustom *event) {
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == movingUpRightAnimationReachesLastFrameInfo) {
			log("Last frame of movingUpRightAnimation reached.");
			this->acceptCall = true;
		}
		if (*userData->userInfo == movingUpRightAnimationReachesfirstFrameInfo) {
			log("First frame of movingUpRightAnimation reached.");
			this->acceptCall = false;
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(movingUpRightAnimationFrameEventListener, -1);

	//右下移动
	this->movingDownRightAnimation = Animation::create();
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right-down_00.png");
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right-down_01.png");
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right-down_02.png");
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right-down_03.png");
	this->movingDownRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingDownRightAnimation->setRestoreOriginalFrame(true);
	this->movingDownRightAnimation->retain();

	ValueMap movingDownRightAnimationReachesfirstFrameInfo;
	ValueMap movingDownRightAnimationReachesLastFrameInfo;

	movingDownRightAnimationReachesfirstFrameInfo["asd"] = Value(2);
	movingDownRightAnimationReachesLastFrameInfo["0"] = Value(0);

	this->movingDownRightAnimation->getFrames().at(0)->setUserInfo(movingDownRightAnimationReachesfirstFrameInfo);

	this->movingDownRightAnimation->getFrames().at(3)->setUserInfo(movingDownRightAnimationReachesLastFrameInfo);

	EventListenerCustom * movingDownRightAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, movingDownRightAnimationReachesLastFrameInfo, movingDownRightAnimationReachesfirstFrameInfo](EventCustom *event) {
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == movingDownRightAnimationReachesLastFrameInfo) {
			log("Last frame of movingDownRightAnimation reached.");
			this->acceptCall = true;
		}
		if (*userData->userInfo == movingDownRightAnimationReachesfirstFrameInfo) {
			log("First frame of movingDownRightAnimation reached.");
			this->acceptCall = false;
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(movingDownRightAnimationFrameEventListener, -1);
	
	//左上移动
	this->movingUpLeftAnimation = Animation::create();
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left-up_00.png");
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left-up_01.png");
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left-up_02.png");
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left-up_03.png");
	this->movingUpLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingUpLeftAnimation->setRestoreOriginalFrame(true);
	this->movingUpLeftAnimation->retain();

	ValueMap movingUpLeftAnimationReachesfirstFrameInfo;
	ValueMap movingUpLeftAnimationReachesLastFrameInfo;

	movingUpLeftAnimationReachesfirstFrameInfo["asd"] = Value(2);
	movingUpLeftAnimationReachesLastFrameInfo["0"] = Value(0);

	this->movingUpLeftAnimation->getFrames().at(0)->setUserInfo(movingUpLeftAnimationReachesfirstFrameInfo);

	this->movingUpLeftAnimation->getFrames().at(3)->setUserInfo(movingUpLeftAnimationReachesLastFrameInfo);

	EventListenerCustom * movingUpLeftAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, movingUpLeftAnimationReachesLastFrameInfo, movingUpLeftAnimationReachesfirstFrameInfo](EventCustom *event) {
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == movingUpLeftAnimationReachesLastFrameInfo) {
			log("Last frame of movingUpLeftAnimation reached.");
			this->acceptCall = true;
		}
		if (*userData->userInfo == movingUpLeftAnimationReachesfirstFrameInfo) {
			log("First frame of movingUpLeftAnimation reached.");
			this->acceptCall = false;
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(movingUpLeftAnimationFrameEventListener, -1);
	
	//左下移动
	this->movingDownLeftAnimation = Animation::create();
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left-down_00.png");
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left-down_01.png");
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left-down_02.png");
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left-down_03.png");
	this->movingDownLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingDownLeftAnimation->setRestoreOriginalFrame(true);
	this->movingDownLeftAnimation->retain();

	ValueMap movingDownLeftAnimationReachesfirstFrameInfo;
	ValueMap movingDownLeftAnimationReachesLastFrameInfo;

	movingDownLeftAnimationReachesfirstFrameInfo["asd"] = Value(2);
	movingDownLeftAnimationReachesLastFrameInfo["0"] = Value(0);

	this->movingDownLeftAnimation->getFrames().at(0)->setUserInfo(movingDownLeftAnimationReachesfirstFrameInfo);

	this->movingDownLeftAnimation->getFrames().at(3)->setUserInfo(movingDownLeftAnimationReachesLastFrameInfo);

	EventListenerCustom * movingDownLeftAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, movingDownLeftAnimationReachesLastFrameInfo, movingDownLeftAnimationReachesfirstFrameInfo](EventCustom *event) {
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == movingDownLeftAnimationReachesLastFrameInfo) {
			log("Last frame of movingDownLeftAnimation reached.");
			this->acceptCall = true;
		}
		if (*userData->userInfo == movingDownLeftAnimationReachesfirstFrameInfo) {
			log("First frame of movingDownLeftAnimation reached.");
			this->acceptCall = false;
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(movingDownLeftAnimationFrameEventListener, -1);

	//攻击
	this->attackAnimation = Animation::create();
	this->attackAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_attack_00.png");
	this->attackAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_attack_01.png");
	this->attackAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_attack_02.png");
	this->attackAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_attack_03.png");
	this->attackAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->attackAnimation->setRestoreOriginalFrame(true);
	this->attackAnimation->retain();

	ValueMap attackAnimationReachesfirstFrameInfo;
	ValueMap attackAnimationReachesLastFrameInfo;

	attackAnimationReachesfirstFrameInfo["asd"] = Value(2);
	attackAnimationReachesLastFrameInfo["0"] = Value(0);

	this->attackAnimation->getFrames().at(0)->setUserInfo(attackAnimationReachesfirstFrameInfo);

	this->attackAnimation->getFrames().at(3)->setUserInfo(attackAnimationReachesLastFrameInfo);

	EventListenerCustom * attackAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, attackAnimationReachesLastFrameInfo, attackAnimationReachesfirstFrameInfo](EventCustom *event) {
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == attackAnimationReachesLastFrameInfo) {
			log("Last frame of attackAnimation reached.");
			this->acceptCall = true;
		}
		if (*userData->userInfo == attackAnimationReachesfirstFrameInfo) {
			log("First frame of attackAnimation reached.");
			this->acceptCall = false;
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(attackAnimationFrameEventListener, -1);


	//受伤
	this->getHurtAnimation = Animation::create();
	this->getHurtAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_get_hurt_00.png");
	this->getHurtAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_get_hurt_01.png");
	this->getHurtAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_get_hurt_02.png");
	this->getHurtAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_get_hurt_03.png");
	this->getHurtAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->getHurtAnimation->setRestoreOriginalFrame(true);
	this->getHurtAnimation->retain();

	ValueMap getHurtAnimationReachesfirstFrameInfo;
	ValueMap  getHurtAnimationReachesLastFrameInfo;

	getHurtAnimationReachesfirstFrameInfo["asd"] = Value(2);
	getHurtAnimationReachesLastFrameInfo["0"] = Value(0);

	this->getHurtAnimation->getFrames().at(0)->setUserInfo(getHurtAnimationReachesfirstFrameInfo);

	this->getHurtAnimation->getFrames().at(3)->setUserInfo(getHurtAnimationReachesLastFrameInfo);

	EventListenerCustom * getHurtAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, getHurtAnimationReachesLastFrameInfo, getHurtAnimationReachesfirstFrameInfo](EventCustom *event) {
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == getHurtAnimationReachesLastFrameInfo) {
			log("Last frame of getHurtAnimation reached.");
			this->acceptCall = true;
		}
		if (*userData->userInfo == getHurtAnimationReachesfirstFrameInfo) {
			log("First frame of getHurtAnimation reached.");
			this->acceptCall = false;
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(getHurtAnimationFrameEventListener, -1);

	//死亡
	this->dieAnimation = Animation::create();
	this->dieAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_die_00.png");
	this->dieAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_die_01.png");
	this->dieAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_die_02.png");
	this->dieAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_die_03.png");
	this->dieAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->dieAnimation->setRestoreOriginalFrame(true);
	this->dieAnimation->retain();

	ValueMap dieAnimationReachesfirstFrameInfo;
	ValueMap  dieAnimationReachesLastFrameInfo;

	dieAnimationReachesfirstFrameInfo["asd"] = Value(2);
	dieAnimationReachesLastFrameInfo["0"] = Value(0);

	this->dieAnimation->getFrames().at(0)->setUserInfo(dieAnimationReachesfirstFrameInfo);

	this->dieAnimation->getFrames().at(3)->setUserInfo(dieAnimationReachesLastFrameInfo);

	EventListenerCustom * dieAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, dieAnimationReachesLastFrameInfo, dieAnimationReachesfirstFrameInfo](EventCustom *event) {
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == dieAnimationReachesLastFrameInfo) {
			log("Last frame of dieAnimation reached.");
			this->acceptCall = true;
		}
		if (*userData->userInfo == dieAnimationReachesfirstFrameInfo) {
			log("First frame of dieAnimation reached.");
			this->acceptCall = false;
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(dieAnimationFrameEventListener, -1);
}


EnemyFish::~EnemyFish()
{
}


EnemyFish* EnemyFish::create(const std::string & filename) {
	EnemyFish *mySprite = new EnemyFish();
	if (mySprite &&mySprite->initWithFile(filename)) {
		mySprite->autorelease();
		return mySprite;
	}
	CC_SAFE_DELETE(mySprite);
	return nullptr;
}


void EnemyFish::wanderAbout() {
	if (this->acceptCall) {
		this->acceptCall = false;
		this->getParent();

		float herox = ((Stage1GameplayLayer *)this->getParent())->kunpeng->getPositionX();
		float heroy = ((Stage1GameplayLayer *)this->getParent())->kunpeng->getPositionY();

		float fishx = this->getPositionX();
		float fishy = this->getPositionY();

		double distance = (herox - fishx)*(herox - fishx) + (heroy - fishy)*(herox - fishy);
		distance = sqrt(distance);

		if (distance < ALARMDISTANCE1) {
			//进入攻击距离 发起攻击
			this->stopAllActions();
			if ((herox - fishx) == 0 && (heroy - fishy) > 0) {
			//上
				this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(0, this->speed_flying_pixel_per_second))));
				this->runAction(RepeatForever::create(Animate::create(this->movingUpAnimation)));
			}
			else if ((herox - fishx) == 0 && (heroy - fishy) < 0) {
			//下
				this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(0, -this->speed_flying_pixel_per_second))));
				this->runAction(RepeatForever::create(Animate::create(this->movingDownAnimation)));
			}
			else if ((herox - fishx) < 0 && (heroy - fishy) == 0) {
			//左
				this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->speed_flying_pixel_per_second, 0))));
				this->runAction(RepeatForever::create(Animate::create(this->movingLeftAnimation)));
			}
			else if ((herox - fishx) > 0 && (heroy - fishy) == 0) {
			//右
				this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->speed_flying_pixel_per_second / 1.414, 0))));
				this->runAction(RepeatForever::create(Animate::create(this->movingRightAnimation)));
			}
			else if ((herox - fishx) < 0 && (heroy - fishy) > 0) {
			//左上
				this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->speed_flying_pixel_per_second / 1.414, this->speed_flying_pixel_per_second / 1.414))));
				this->runAction(RepeatForever::create(Animate::create(this->movingUpLeftAnimation)));
			}
			else if ((herox - fishx) < 0 && (heroy - fishy) < 0) {
			//左下
				this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->speed_flying_pixel_per_second / 1.414, -this->speed_flying_pixel_per_second / 1.414))));
				this->runAction(RepeatForever::create(Animate::create(this->movingDownLeftAnimation)));
			}
			else if ((herox - fishx) > 0 && (heroy - fishy) > 0) {
			//右上
				this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->speed_flying_pixel_per_second / 1.414, this->speed_flying_pixel_per_second / 1.414))));
				this->runAction(RepeatForever::create(Animate::create(this->movingUpRightAnimation)));
			}
			else{
			//右下
				this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->speed_flying_pixel_per_second / 1.414, -this->speed_flying_pixel_per_second / 1.414))));
				this->runAction(RepeatForever::create(Animate::create(this->movingDownRightAnimation)));
			}
			//this->runAction(RepeatForever::create(MoveTo::create(0.5f, Vec2(0.5*herox, 0.5*heroy))));
			this->runAction(RepeatForever::create(Animate::create(this->attackAnimation)));
		}
		else {
			//生成随机数 朝八个方向闲逛
			srand((unsigned)time(NULL));
			int direction = rand() % 8;
			//direction = 3;
			switch (direction)
			{
			case 0:
				//上
				this->stopAllActions();
				this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(0, this->speed_flying_pixel_per_second))));
				this->runAction(RepeatForever::create(Animate::create(this->movingUpAnimation)));
				break;
			case 1:
				//下
				this->stopAllActions();
				this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(0, -this->speed_flying_pixel_per_second))));
				this->runAction(RepeatForever::create(Animate::create(this->movingDownAnimation)));
				break;
			case 2:
				//左
				this->stopAllActions();
				this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->speed_flying_pixel_per_second, 0))));
				this->runAction(RepeatForever::create(Animate::create(this->movingLeftAnimation)));
				break;
			case 3:
				//右
				this->stopAllActions();
				this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->speed_flying_pixel_per_second / 1.414, 0))));
				this->runAction(RepeatForever::create(Animate::create(this->movingRightAnimation)));
				break;
			case 4:
				//左上
				this->stopAllActions();
				this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->speed_flying_pixel_per_second / 1.414, this->speed_flying_pixel_per_second / 1.414))));
				this->runAction(RepeatForever::create(Animate::create(this->movingUpLeftAnimation)));
				break;
			case 5:
				//左下
				this->stopAllActions();
				this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->speed_flying_pixel_per_second / 1.414, -this->speed_flying_pixel_per_second / 1.414))));
				this->runAction(RepeatForever::create(Animate::create(this->movingDownLeftAnimation)));
				break;
			case 6:
				//右上
				this->stopAllActions();
				this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->speed_flying_pixel_per_second / 1.414, this->speed_flying_pixel_per_second / 1.414))));
				this->runAction(RepeatForever::create(Animate::create(this->movingUpRightAnimation)));
				break;
			case 7:
				//右下
				this->stopAllActions();
				this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->speed_flying_pixel_per_second / 1.414, -this->speed_flying_pixel_per_second / 1.414))));
				this->runAction(RepeatForever::create(Animate::create(this->movingDownRightAnimation)));
				break;
			}

		}
	}
	else {
		return;
	}
}

void EnemyFish::getHurt() {


}

void EnemyFish::getHurt(int damage) {
	if (this->health <= 0) {

	}
	else {
		this->health -= damage;

		if (this->health < 0)	{
			die();
		}
		else {
			if (this->acceptCall) {
				this->acceptCall = false;
				this->runAction(Animate::create(this->getHurtAnimation));
			}
		}
	}
}

void EnemyFish::die() {
	if (this->acceptCall) {
		this->acceptCall = false;
		this->stopAllActions();
		this->runAction((Animate::create(this->dieAnimation)));
	}
}
