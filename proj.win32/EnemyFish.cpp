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
	this->hoveringLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_hovering_facing_left_04.png");
	this->hoveringLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_hovering_facing_left_05.png");
	this->hoveringLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_hovering_facing_left_06.png");
	this->hoveringLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_hovering_facing_left_07.png");
	this->hoveringLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->hoveringLeftAnimation->setRestoreOriginalFrame(true);
	this->hoveringLeftAnimation->retain();

	ValueMap hoveringLeftAnimationReachesfirstFrameInfo;
	ValueMap hoveringLeftAnimationReachesLastFrameInfo;

	hoveringLeftAnimationReachesfirstFrameInfo["ljjFish"] = Value(200);
	hoveringLeftAnimationReachesLastFrameInfo["0"] = Value(201);

	this->hoveringLeftAnimation->getFrames().at(0)->setUserInfo(hoveringLeftAnimationReachesfirstFrameInfo);

	this->hoveringLeftAnimation->getFrames().at(7)->setUserInfo(hoveringLeftAnimationReachesLastFrameInfo);

	EventListenerCustom * hoveringLeftAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, hoveringLeftAnimationReachesLastFrameInfo, hoveringLeftAnimationReachesfirstFrameInfo](EventCustom *event) {
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == hoveringLeftAnimationReachesLastFrameInfo) {
			log("Last ljjFrame of hoveringLeftAnimation reached.");
			this->acceptCall = true;
		}
		if (*userData->userInfo == hoveringLeftAnimationReachesfirstFrameInfo) {
			log("First ljjFrame of hoveringLeftAnimation reached.");
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
	this->hoveringRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_hovering_facing_right_04.png");
	this->hoveringRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_hovering_facing_right_05.png");
	this->hoveringRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_hovering_facing_right_06.png");
	this->hoveringRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_hovering_facing_right_07.png");
	this->hoveringRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->hoveringRightAnimation->setRestoreOriginalFrame(true);
	this->hoveringRightAnimation->retain();

	ValueMap hoveringRightAnimationReachesfirstFrameInfo;
	ValueMap hoveringRightAnimationReachesLastFrameInfo;

	hoveringRightAnimationReachesfirstFrameInfo["ljjFish"] = Value(202);
	hoveringRightAnimationReachesLastFrameInfo["0"] = Value(203);

	this->hoveringRightAnimation->getFrames().at(0)->setUserInfo(hoveringRightAnimationReachesfirstFrameInfo);

	this->hoveringRightAnimation->getFrames().at(7)->setUserInfo(hoveringRightAnimationReachesLastFrameInfo);

	EventListenerCustom * hoveringRightAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, hoveringRightAnimationReachesLastFrameInfo, hoveringRightAnimationReachesfirstFrameInfo](EventCustom *event) {
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == hoveringRightAnimationReachesLastFrameInfo) {
			log("Last ljjFrame of hoveringRightAnimation reached.");
			this->acceptCall = true;
		}
		if (*userData->userInfo == hoveringRightAnimationReachesfirstFrameInfo) {
			log("First ljjFrame of hoveringRightAnimation reached.");
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
	this->movingUpAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_up_04.png");
	this->movingUpAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_up_05.png");
	this->movingUpAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_up_06.png");
	this->movingUpAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_up_07.png");
	this->movingUpAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingUpAnimation->setRestoreOriginalFrame(true);
	this->movingUpAnimation->retain();

	ValueMap movingUpAnimationReachesfirstFrameInfo;
	ValueMap movingUpAnimationReachesLastFrameInfo;

	movingUpAnimationReachesfirstFrameInfo["ljjFish"] = Value(204);
	movingUpAnimationReachesLastFrameInfo["0"] = Value(205);

	this->movingUpAnimation->getFrames().at(0)->setUserInfo(movingUpAnimationReachesfirstFrameInfo);

	this->movingUpAnimation->getFrames().at(7)->setUserInfo(movingUpAnimationReachesLastFrameInfo);

	EventListenerCustom * movingUpAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, movingUpAnimationReachesLastFrameInfo, movingUpAnimationReachesfirstFrameInfo](EventCustom *event) {
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == movingUpAnimationReachesLastFrameInfo) {
			log("Last ljjFrame of movingUpAnimation reached.");
			this->acceptCall = true;
		}
		if (*userData->userInfo == movingUpAnimationReachesfirstFrameInfo) {
			log("First ljjFrame of movingUpAnimation reached.");
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
	this->movingDownAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_down_04.png");
	this->movingDownAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_down_05.png");
	this->movingDownAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_down_06.png");
	this->movingDownAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_down_07.png");
	this->movingDownAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingDownAnimation->setRestoreOriginalFrame(true);
	this->movingDownAnimation->retain();

	ValueMap movingDownAnimationReachesfirstFrameInfo;
	ValueMap movingDownAnimationReachesLastFrameInfo;

	movingDownAnimationReachesfirstFrameInfo["ljjFish"] = Value(206);
	movingDownAnimationReachesLastFrameInfo["0"] = Value(207);

	this->movingDownAnimation->getFrames().at(0)->setUserInfo(movingDownAnimationReachesfirstFrameInfo);

	this->movingDownAnimation->getFrames().at(7)->setUserInfo(movingDownAnimationReachesLastFrameInfo);

	EventListenerCustom * movingDownAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, movingDownAnimationReachesLastFrameInfo, movingDownAnimationReachesfirstFrameInfo](EventCustom *event) {
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == movingDownAnimationReachesLastFrameInfo) {
			log("Last ljjFrame of movingDownAnimation reached.");
			this->acceptCall = true;
		}
		if (*userData->userInfo == movingDownAnimationReachesfirstFrameInfo) {
			log("First ljjFrame of movingDownAnimation reached.");
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
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left_04.png");
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left_05.png");
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left_06.png");
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left_07.png");
	this->movingLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingLeftAnimation->setRestoreOriginalFrame(true);
	this->movingLeftAnimation->retain();

	ValueMap movingLeftAnimationReachesfirstFrameInfo;
	ValueMap movingLeftAnimationReachesLastFrameInfo;

	movingLeftAnimationReachesfirstFrameInfo["ljjFish"] = Value(208);
	movingLeftAnimationReachesLastFrameInfo["0"] = Value(209);

	this->movingLeftAnimation->getFrames().at(0)->setUserInfo(movingLeftAnimationReachesfirstFrameInfo);

	this->movingLeftAnimation->getFrames().at(7)->setUserInfo(movingLeftAnimationReachesLastFrameInfo);

	EventListenerCustom * movingLeftAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, movingLeftAnimationReachesLastFrameInfo, movingLeftAnimationReachesfirstFrameInfo](EventCustom *event) {
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == movingLeftAnimationReachesLastFrameInfo) {
			log("Last ljjFrame of movingLeftAnimation reached.");
			this->acceptCall = true;
		}
		if (*userData->userInfo == movingLeftAnimationReachesfirstFrameInfo) {
			log("First ljjFrame of movingLeftAnimation reached.");
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
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right_04.png");
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right_05.png");
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right_06.png");
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right_07.png");
	this->movingRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingRightAnimation->setRestoreOriginalFrame(true);
	this->movingRightAnimation->retain();

	ValueMap movingRightAnimationReachesfirstFrameInfo;
	ValueMap movingRightAnimationReachesLastFrameInfo;

	movingRightAnimationReachesfirstFrameInfo["ljjFish"] = Value(210);
	movingRightAnimationReachesLastFrameInfo["0"] = Value(211);

	this->movingRightAnimation->getFrames().at(0)->setUserInfo(movingRightAnimationReachesfirstFrameInfo);

	this->movingRightAnimation->getFrames().at(7)->setUserInfo(movingRightAnimationReachesLastFrameInfo);

	EventListenerCustom * movingRightAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, movingRightAnimationReachesLastFrameInfo, movingRightAnimationReachesfirstFrameInfo](EventCustom *event) {
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == movingRightAnimationReachesLastFrameInfo) {
			log("Last ljjFrame of movingRightAnimation reached.");
			this->acceptCall = true;
		}
		if (*userData->userInfo == movingRightAnimationReachesfirstFrameInfo) {
			log("First ljjFrame of movingRightAnimation reached.");
			this->acceptCall = false;
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(movingRightAnimationFrameEventListener, -1);

	//右上移动
	this->movingUpRightAnimation = Animation::create();
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right_00.png");
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right_01.png");
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right_02.png");
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right_03.png");
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right_04.png");
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right_05.png");
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right_06.png");
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right_07.png");
	this->movingUpRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingUpRightAnimation->setRestoreOriginalFrame(true);
	this->movingUpRightAnimation->retain();

	ValueMap movingUpRightAnimationReachesfirstFrameInfo;
	ValueMap movingUpRightAnimationReachesLastFrameInfo;

	movingUpRightAnimationReachesfirstFrameInfo["ljjFish"] = Value(212);
	movingUpRightAnimationReachesLastFrameInfo["0"] = Value(213);

	this->movingUpRightAnimation->getFrames().at(0)->setUserInfo(movingUpRightAnimationReachesfirstFrameInfo);

	this->movingUpRightAnimation->getFrames().at(7)->setUserInfo(movingUpRightAnimationReachesLastFrameInfo);

	EventListenerCustom * movingUpRightAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, movingUpRightAnimationReachesLastFrameInfo, movingUpRightAnimationReachesfirstFrameInfo](EventCustom *event) {
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == movingUpRightAnimationReachesLastFrameInfo) {
			log("Last ljjFrame of movingUpRightAnimation reached.");
			this->acceptCall = true;
		}
		if (*userData->userInfo == movingUpRightAnimationReachesfirstFrameInfo) {
			log("First ljjFrame of movingUpRightAnimation reached.");
			this->acceptCall = false;
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(movingUpRightAnimationFrameEventListener, -1);

	//右下移动
	this->movingDownRightAnimation = Animation::create();
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right_00.png");
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right_01.png");
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right_02.png");
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right_03.png");
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right_04.png");
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right_05.png");
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right_06.png");
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_right_07.png");
	this->movingDownRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingDownRightAnimation->setRestoreOriginalFrame(true);
	this->movingDownRightAnimation->retain();

	ValueMap movingDownRightAnimationReachesfirstFrameInfo;
	ValueMap movingDownRightAnimationReachesLastFrameInfo;

	movingDownRightAnimationReachesfirstFrameInfo["ljjFish"] = Value(214);
	movingDownRightAnimationReachesLastFrameInfo["0"] = Value(215);

	this->movingDownRightAnimation->getFrames().at(0)->setUserInfo(movingDownRightAnimationReachesfirstFrameInfo);

	this->movingDownRightAnimation->getFrames().at(7)->setUserInfo(movingDownRightAnimationReachesLastFrameInfo);

	EventListenerCustom * movingDownRightAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, movingDownRightAnimationReachesLastFrameInfo, movingDownRightAnimationReachesfirstFrameInfo](EventCustom *event) {
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == movingDownRightAnimationReachesLastFrameInfo) {
			log("Last ljjFrame of movingDownRightAnimation reached.");
			this->acceptCall = true;
		}
		if (*userData->userInfo == movingDownRightAnimationReachesfirstFrameInfo) {
			log("First ljjFrame of movingDownRightAnimation reached.");
			this->acceptCall = false;
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(movingDownRightAnimationFrameEventListener, -1);

	//左上移动
	this->movingUpLeftAnimation = Animation::create();
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left_00.png");
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left_01.png");
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left_02.png");
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left_03.png");
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left_04.png");
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left_05.png");
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left_06.png");
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left_07.png");
	this->movingUpLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingUpLeftAnimation->setRestoreOriginalFrame(true);
	this->movingUpLeftAnimation->retain();

	ValueMap movingUpLeftAnimationReachesfirstFrameInfo;
	ValueMap movingUpLeftAnimationReachesLastFrameInfo;

	movingUpLeftAnimationReachesfirstFrameInfo["ljjFish"] = Value(216);
	movingUpLeftAnimationReachesLastFrameInfo["0"] = Value(217);

	this->movingUpLeftAnimation->getFrames().at(0)->setUserInfo(movingUpLeftAnimationReachesfirstFrameInfo);

	this->movingUpLeftAnimation->getFrames().at(7)->setUserInfo(movingUpLeftAnimationReachesLastFrameInfo);

	EventListenerCustom * movingUpLeftAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, movingUpLeftAnimationReachesLastFrameInfo, movingUpLeftAnimationReachesfirstFrameInfo](EventCustom *event) {
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == movingUpLeftAnimationReachesLastFrameInfo) {
			log("Last ljjFrame of movingUpLeftAnimation reached.");
			this->acceptCall = true;
		}
		if (*userData->userInfo == movingUpLeftAnimationReachesfirstFrameInfo) {
			log("First ljjFrame of movingUpLeftAnimation reached.");
			this->acceptCall = false;
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(movingUpLeftAnimationFrameEventListener, -1);

	//左下移动
	this->movingDownLeftAnimation = Animation::create();
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left_00.png");
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left_01.png");
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left_02.png");
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left_03.png");
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left_04.png");
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left_05.png");
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left_06.png");
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_moving_facing_left_07.png");
	this->movingDownLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingDownLeftAnimation->setRestoreOriginalFrame(true);
	this->movingDownLeftAnimation->retain();

	ValueMap movingDownLeftAnimationReachesfirstFrameInfo;
	ValueMap movingDownLeftAnimationReachesLastFrameInfo;

	movingDownLeftAnimationReachesfirstFrameInfo["ljjFish"] = Value(218);
	movingDownLeftAnimationReachesLastFrameInfo["0"] = Value(219);

	this->movingDownLeftAnimation->getFrames().at(0)->setUserInfo(movingDownLeftAnimationReachesfirstFrameInfo);

	this->movingDownLeftAnimation->getFrames().at(7)->setUserInfo(movingDownLeftAnimationReachesLastFrameInfo);

	EventListenerCustom * movingDownLeftAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, movingDownLeftAnimationReachesLastFrameInfo, movingDownLeftAnimationReachesfirstFrameInfo](EventCustom *event) {
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == movingDownLeftAnimationReachesLastFrameInfo) {
			log("Last ljjFrame of movingDownLeftAnimation reached.");
			this->acceptCall = true;
		}
		if (*userData->userInfo == movingDownLeftAnimationReachesfirstFrameInfo) {
			log("First ljjFrame of movingDownLeftAnimation reached.");
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

	attackAnimationReachesfirstFrameInfo["ljjFish"] = Value(220);
	attackAnimationReachesLastFrameInfo["0"] = Value(221);

	this->attackAnimation->getFrames().at(0)->setUserInfo(attackAnimationReachesfirstFrameInfo);

	this->attackAnimation->getFrames().at(3)->setUserInfo(attackAnimationReachesLastFrameInfo);

	EventListenerCustom * attackAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, attackAnimationReachesLastFrameInfo, attackAnimationReachesfirstFrameInfo](EventCustom *event) {
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == attackAnimationReachesLastFrameInfo) {
			log("Last ljjFrame of attackAnimation reached.");
			this->acceptCall = true;
		}
		if (*userData->userInfo == attackAnimationReachesfirstFrameInfo) {
			log("First ljjFrame of attackAnimation reached.");
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
	this->getHurtAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_get_hurt_04.png");
	this->getHurtAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_get_hurt_05.png");
	this->getHurtAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->getHurtAnimation->setRestoreOriginalFrame(true);
	this->getHurtAnimation->retain();

	ValueMap getHurtAnimationReachesfirstFrameInfo;
	ValueMap  getHurtAnimationReachesLastFrameInfo;


	getHurtAnimationReachesfirstFrameInfo["ljjFish"] = Value(222);
	getHurtAnimationReachesLastFrameInfo["0"] = Value(223);


	this->getHurtAnimation->getFrames().at(0)->setUserInfo(getHurtAnimationReachesfirstFrameInfo);

	this->getHurtAnimation->getFrames().at(5)->setUserInfo(getHurtAnimationReachesLastFrameInfo);

	EventListenerCustom * getHurtAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, getHurtAnimationReachesLastFrameInfo, getHurtAnimationReachesfirstFrameInfo](EventCustom *event) {
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == getHurtAnimationReachesLastFrameInfo) {
			log("Last ljjFrame of getHurtAnimation reached.");
			this->acceptCall = true;
		}
		if (*userData->userInfo == getHurtAnimationReachesfirstFrameInfo) {
			log("First ljjFrame of getHurtAnimation reached.");
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
	this->dieAnimation->addSpriteFrameWithFileName("characters/enemyfish/enemyfish_die_04.png");
	this->dieAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->dieAnimation->setRestoreOriginalFrame(true);
	this->dieAnimation->retain();
	/*
	ValueMap dieAnimationReachesfirstFrameInfo;
	ValueMap  dieAnimationReachesLastFrameInfo;

	dieAnimationReachesfirstFrameInfo["ljjFish"] = Value(224);
	dieAnimationReachesLastFrameInfo["ljjFish1"] = Value("ljjFish1");

	this->dieAnimation->getFrames().at(0)->setUserInfo(dieAnimationReachesfirstFrameInfo);

	this->dieAnimation->getFrames().at(4)->setUserInfo(dieAnimationReachesLastFrameInfo);

	EventListenerCustom * dieAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, dieAnimationReachesLastFrameInfo, dieAnimationReachesfirstFrameInfo](EventCustom *event) {
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == dieAnimationReachesLastFrameInfo) {
			log("Last ljjFrame of dieAnimation reached.");
			//this->acceptCall = true;
			this->setPosition(-1111, -1111);
			//this->removeFromParent();
		}
		if (*userData->userInfo == dieAnimationReachesfirstFrameInfo) {
			log("First ljjFrame of dieAnimation reached.");
			this->acceptCall = false;
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(dieAnimationFrameEventListener, -1);
	*/
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
	if (this->acceptCall && this->health > 0) {
		this->acceptCall = false;
		this->getParent();

		int herox = ((Stage1GameplayLayer *)this->getParent())->kunpeng->getPositionX();
		int heroy = ((Stage1GameplayLayer *)this->getParent())->kunpeng->getPositionY();

		float waterfacey = ((Stage1GameplayLayer*)this->getParent())->waterSurface->getPositionY();

		float fishx = this->getPositionX();
		float fishy = this->getPositionY();

		double distance = (herox - fishx)*(herox - fishx) + (heroy - fishy)*(herox - fishy);
		distance = sqrt(distance);

		if (distance < ALARMDISTANCE1 && heroy < waterfacey) {
			srand((unsigned)time(NULL));
			int attckOrNot = rand() % (ATTACK_PROB);
			//进入攻击距离 按概率发起攻击
			if (attckOrNot == 0) {
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
				else {
					//右下
					this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->speed_flying_pixel_per_second / 1.414, -this->speed_flying_pixel_per_second / 1.414))));
					this->runAction(RepeatForever::create(Animate::create(this->movingDownRightAnimation)));
				}
				//this->runAction(RepeatForever::create(MoveTo::create(0.5f, Vec2(0.5*herox, 0.5*heroy))));
				int damage = 10;
				((Stage1GameplayLayer *)this->getParent())->kunpeng->getHurtGeneral(damage);
				this->runAction(RepeatForever::create(Animate::create(this->attackAnimation)));
			}
		}
		else {
			//生成随机数 朝八个方向闲逛
			srand((unsigned)time(NULL));
			int direction = rand() % 12;
			//direction = 0;
			switch (direction)
			{
			case 0:
				//上
				this->stopAllActions();
				if (this->getPositionY() + this->speed_flying_pixel_per_second > waterfacey)
					this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(0, waterfacey))));
				else
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
				if (this->getPositionY() + this->speed_flying_pixel_per_second > waterfacey)
					this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-waterfacey / 1.414, waterfacey / 1.414))));
				else
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
				if (this->getPositionY() + this->speed_flying_pixel_per_second > waterfacey)
					this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(waterfacey / 1.414, waterfacey / 1.414))));
				else
					this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->speed_flying_pixel_per_second / 1.414, this->speed_flying_pixel_per_second / 1.414))));
				this->runAction(RepeatForever::create(Animate::create(this->movingUpRightAnimation)));
				break;
			case 7:
				//右下
				this->stopAllActions();
				this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->speed_flying_pixel_per_second / 1.414, -this->speed_flying_pixel_per_second / 1.414))));
				this->runAction(RepeatForever::create(Animate::create(this->movingDownRightAnimation)));
				break;
			default:
				this->stopAllActions();
				this->runAction(RepeatForever::create(Animate::create(this->hoveringLeftAnimation)));
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

		if (this->health < 0) {
			die();
		}
		else {
			stopAllActions();
			log("%d",this->health);
			this->runAction(Animate::create(this->getHurtAnimation));
			//this->acceptCall = true;
		}
	}
}

void EnemyFish::getHurtByWind(int damage) {
	this->getHurt(damage);
}

void EnemyFish::die() {
	this->stopAllActions();
	//this->runAction(Animate::create(this->dieAnimation));
	//this->removeFromParent();
	this->acceptCall = false;
	this->runAction(Sequence::create(Repeat::create(Animate::create(dieAnimation), 1), CallFunc::create([this] {
		this->removeFromParent();
	}), nullptr));


}