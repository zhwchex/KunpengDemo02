#include "HeroSprite.h"
#include "Stage1GameplayLayer.h"//Nastiest design ever!

HeroSprite::HeroSprite()
{
	this->moveRightWithoutAnimationAction = RepeatForever::create(MoveBy::create(1, Vec2(this->SPEED_DURING_ATTACKING_FLYING, 0)));
	this->moveLeftWithoutAnimationAction = RepeatForever::create(MoveBy::create(1, Vec2(-this->SPEED_DURING_ATTACKING_FLYING, 0)));
	this->moveUpWithoutAnimationAction = RepeatForever::create(MoveBy::create(1, Vec2(0,this->SPEED_DURING_ATTACKING_FLYING)));
	this->moveDownWithoutAnimationAction = RepeatForever::create(MoveBy::create(1, Vec2(0,-this->SPEED_DURING_ATTACKING_FLYING)));
	this->moveUpRightWithoutAnimationAction = RepeatForever::create(MoveBy::create(1, Vec2(this->SPEED_DURING_ATTACKING_FLYING/1.414, this->SPEED_DURING_ATTACKING_FLYING/1.414)));
	this->moveDownRightWithoutAnimationAction = RepeatForever::create(MoveBy::create(1, Vec2(this->SPEED_DURING_ATTACKING_FLYING / 1.414, -this->SPEED_DURING_ATTACKING_FLYING / 1.414)));
	this->moveUpLeftWithoutAnimationAction = RepeatForever::create(MoveBy::create(1, Vec2(-this->SPEED_DURING_ATTACKING_FLYING / 1.414, this->SPEED_DURING_ATTACKING_FLYING / 1.414)));
	this->moveDownLeftWithoutAnimationAction = RepeatForever::create(MoveBy::create(1, Vec2(-this->SPEED_DURING_ATTACKING_FLYING / 1.414, -this->SPEED_DURING_ATTACKING_FLYING / 1.414)));
	
	this->moveRightWithoutAnimationAction->retain();


	this->hoveringRightAnimation = Animation::create();
	this->hoveringRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_right_00.png");
	this->hoveringRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_right_01.png");
	this->hoveringRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_right_02.png");
	this->hoveringRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_right_03.png");
	this->hoveringRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->hoveringRightAnimation->setRestoreOriginalFrame(true);
	this->hoveringRightAnimation->retain();

	this->hoveringLeftAnimation = Animation::create();
	this->hoveringLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_left_00.png");
	this->hoveringLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_left_01.png");
	this->hoveringLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_left_02.png");
	this->hoveringLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_left_03.png");
	this->hoveringLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->hoveringLeftAnimation->setRestoreOriginalFrame(true);
	this->hoveringLeftAnimation->retain();



	//以下是在第1帧和第3帧上加事件的例子，其中回调函数以lambda函数的形式给出
	ValueMap hoveringAnimationFrame01info;
	ValueMap hoveringAnimationFrame03info;
	hoveringAnimationFrame01info["1"] = Value(1);//除了让该info指向一个新地址外没有别的用处
	hoveringAnimationFrame03info["2"] = Value(2);//除了让该info指向一个新地址外没有别的用处
	//log("here three = %s,", hoveringAnimationFrame04info["FrameId"].asString());//不知为什么不能输出string，string会变成？？，只能正确输出数字。

	hoveringRightAnimation->getFrames().at(1)->setUserInfo(hoveringAnimationFrame01info);
	hoveringRightAnimation->getFrames().at(3)->setUserInfo(hoveringAnimationFrame03info);

	hoveringLeftAnimation->getFrames().at(1)->setUserInfo(hoveringAnimationFrame01info);
	hoveringLeftAnimation->getFrames().at(3)->setUserInfo(hoveringAnimationFrame03info);



	EventListenerCustom * hoveringAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, hoveringAnimationFrame03info, hoveringAnimationFrame01info](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		//log("Target %p with data %s , if this frame added 03 = %d. ", userData->target, Value(userData->userInfo).getDescription().c_str(), *userData->userInfo == hoveringAnimationFrame03info);
		//log("Value(userData->userInfo).asString = %s",Value(userData->userInfo).asString());
		if (*userData->userInfo == hoveringAnimationFrame03info){
			this->setPositionY(this->getPositionY() + 3);
		}
		if (*userData->userInfo == hoveringAnimationFrame01info){
			this->setPositionY(this->getPositionY() - 3);
		}
	
	});

	//将该事件添加到事件分发器
	_eventDispatcher->addEventListenerWithFixedPriority(hoveringAnimationFrameEventListener, -1);
	//帧事件例子结束。

	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(this->hoveringRightAnimation)));
	
	

	


	//Moving events won't need frame events. However, slight up-down swings during horizontal flights would be welcome.
	this->movingUpAnimation = Animation::create();
	this->movingUpAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_00.jpg");
	this->movingUpAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingUpAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingUpAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingUpAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingUpAnimation->setRestoreOriginalFrame(true);
	this->movingUpAnimation->retain();

	this->movingDownAnimation = Animation::create();
	this->movingDownAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_00.jpg");
	this->movingDownAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingDownAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingDownAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingDownAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingDownAnimation->setRestoreOriginalFrame(true);
	this->movingDownAnimation->retain();

	this->movingRightAnimation = Animation::create();
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_00.jpg");
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingRightAnimation->setRestoreOriginalFrame(true);
	this->movingRightAnimation->retain();

	this->movingUpRightAnimation = Animation::create();
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_00.jpg");
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingUpRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingUpRightAnimation->setRestoreOriginalFrame(true);
	this->movingUpRightAnimation->retain();

	this->movingDownRightAnimation = Animation::create();
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_00.jpg");
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingDownRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingDownRightAnimation->setRestoreOriginalFrame(true);
	this->movingDownRightAnimation->retain();

	this->movingLeftAnimation = Animation::create();
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_00.jpg");
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingLeftAnimation->setRestoreOriginalFrame(true);
	this->movingLeftAnimation->retain();

	this->movingDownLeftAnimation = Animation::create();
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_00.jpg");
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingDownLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingDownLeftAnimation->setRestoreOriginalFrame(true);
	this->movingDownLeftAnimation->retain();

	this->movingUpLeftAnimation = Animation::create();
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_00.jpg");
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_01.jpg");
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_02.jpg");
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_03.jpg");
	this->movingUpLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingUpLeftAnimation->setRestoreOriginalFrame(true);
	this->movingUpLeftAnimation->retain();

	this->blowingWindRightAnimation = Animation::create();
	this->blowingWindRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_right_00.jpg");
	this->blowingWindRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_right_01.jpg");
	this->blowingWindRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_right_02.jpg");
	this->blowingWindRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_right_03.jpg");
	this->blowingWindRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_right_03.jpg");
	this->blowingWindRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->blowingWindRightAnimation->setRestoreOriginalFrame(true);
	this->blowingWindRightAnimation->retain();

	ValueMap blowingStartInfo;
	ValueMap blowingLaunchingWindBulletInfo;
	ValueMap blowingRecoverAllAbilitiesInfo;
	ValueMap blowingEndInfo;

	blowingStartInfo["10"] = Value(10);
	blowingLaunchingWindBulletInfo["11"] = Value(11);
	blowingRecoverAllAbilitiesInfo["12"] = Value(12);
	blowingEndInfo["13"] = Value(13);

	this->blowingWindRightAnimation->getFrames().at(0)->setUserInfo(blowingStartInfo);
	this->blowingWindRightAnimation->getFrames().at(1)->setUserInfo(blowingLaunchingWindBulletInfo);
	this->blowingWindRightAnimation->getFrames().at(3)->setUserInfo(blowingRecoverAllAbilitiesInfo);
	this->blowingWindRightAnimation->getFrames().at(4)->setUserInfo(blowingEndInfo);

	EventListenerCustom * blowingWindAnimationFrameEventListener = EventListenerCustom::create(AnimationFrameDisplayedNotification, [this, blowingStartInfo, blowingLaunchingWindBulletInfo, blowingRecoverAllAbilitiesInfo, blowingEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == blowingStartInfo){
			log("Hitting first frame of blowing. ");
			this->disableAllAbilities();
		}
		if (*userData->userInfo == blowingLaunchingWindBulletInfo){
			if (this->facingRight){
				//this->setPositionX(this->getPositionX() - 30);
				this->runAction(Sequence::create(MoveBy::create(0.1f, Vec2(-10, 0)), MoveBy::create(0.2f, Vec2(-10, 0)), nullptr));
				Sprite * windBullet = Sprite::create();
				windBullet->setPosition(this->getPosition());
				this->getParent()->addChild(windBullet);
				windBullet->runAction(Spawn::create(MoveBy::create(0.4f, Vec2(300, 0)), Repeat::create(Animate::create(this->windBulletFlyingAnimation), 2), nullptr));
			}
			else if (this->facingLeft){
				//this->setPositionX(this->getPositionX()+ 30);
				this->runAction(Sequence::create(MoveBy::create(0.1f, Vec2(10, 0)), MoveBy::create(0.2f, Vec2(10, 0)), nullptr));
				Sprite * windBullet = Sprite::create();
				windBullet->setPosition(this->getPosition());
				this->getParent()->addChild(windBullet);
				windBullet->runAction(Spawn::create(MoveBy::create(0.4f, Vec2(-300, 0)), Repeat::create(Animate::create(this->windBulletFlyingAnimation), 2), nullptr));
			}
			this->windAttackable = true;
		}
		if (*userData->userInfo == blowingRecoverAllAbilitiesInfo){
			this->enableAllAbilities();
			if (this->directionToMoveUpRight ||
				this->directionToMoveRight ||
				this->directionToMoveDownRight ||
				this->directionToMoveDown ||
				this->directionToMoveDownLeft ||
				this->directionToMoveLeft ||
				this->directionToMoveUpLeft ||
				this->directionToMoveUp){
				this->move();
			}
		}
		if (*userData->userInfo == blowingEndInfo){
			log("Hitting last frame of blowing. Hovering.");
			this->hover();
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(blowingWindAnimationFrameEventListener, -1);

	this->blowingWindLeftAnimation = Animation::create();
	this->blowingWindLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_left_00.jpg");
	this->blowingWindLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_left_01.jpg");
	this->blowingWindLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_left_02.jpg");
	this->blowingWindLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_left_03.jpg");
	this->blowingWindLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_left_03.jpg");
	this->blowingWindLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->blowingWindLeftAnimation->setRestoreOriginalFrame(true);
	this->blowingWindLeftAnimation->retain();


	this->blowingWindLeftAnimation->getFrames().at(0)->setUserInfo(blowingStartInfo);
	this->blowingWindLeftAnimation->getFrames().at(1)->setUserInfo(blowingLaunchingWindBulletInfo);
	this->blowingWindLeftAnimation->getFrames().at(3)->setUserInfo(blowingRecoverAllAbilitiesInfo);
	this->blowingWindLeftAnimation->getFrames().at(4)->setUserInfo(blowingEndInfo);


	this->windBulletFlyingAnimation = Animation::create();
	this->windBulletFlyingAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_00.jpg");
	this->windBulletFlyingAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_01.jpg");
	this->windBulletFlyingAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_02.jpg");
	this->windBulletFlyingAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_03.jpg");
	this->windBulletFlyingAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->windBulletFlyingAnimation->setRestoreOriginalFrame(true);
	this->windBulletFlyingAnimation->retain();


	//dashing animations would need frame events.
	this->dashingRightAnimation = Animation::create();
	this->dashingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_right_00.jpg");
	this->dashingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_right_01.jpg");
	this->dashingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_right_02.jpg");
	this->dashingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_right_03.jpg");
	this->dashingRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->dashingRightAnimation->setRestoreOriginalFrame(true);
	this->dashingRightAnimation->retain();

	
	ValueMap dashingRightFrame00Info;
	ValueMap dashingRightFrame02Info;
	ValueMap dashingRightFrame03Info;

	dashingRightFrame00Info["3"] = Value(3);
	dashingRightFrame02Info["4"] = Value(4);
	dashingRightFrame03Info["333"] = Value(333);

	this->dashingRightAnimation->getFrames().at(0)->setUserInfo(dashingRightFrame00Info);
	this->dashingRightAnimation->getFrames().at(2)->setUserInfo(dashingRightFrame02Info);
	this->dashingRightAnimation->getFrames().at(3)->setUserInfo(dashingRightFrame03Info);

	EventListenerCustom * dashingRightAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, dashingRightFrame00Info, dashingRightFrame02Info, dashingRightFrame03Info](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == dashingRightFrame00Info){
			this->disableAllAbilities();
		}
		if (*userData->userInfo == dashingRightFrame02Info){
			this->enableAllAbilities();
			if (this->directionToMoveUpRight  ||
				this->directionToMoveRight ||
				this->directionToMoveDownRight ||
				this->directionToMoveDown ||
				this->directionToMoveDownLeft ||
				this->directionToMoveLeft ||
				this->directionToMoveUpLeft||
				this->directionToMoveUp){
				this->move();
			}
		}
		if (*userData->userInfo == dashingRightFrame03Info){
			log("Hitting last frame of dashing. Hovering.");
			this->hover();
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(dashingRightAnimationFrameEventListener, -1);
	
	this->dashingDownRightAnimation = Animation::create();
	this->dashingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downright_00.jpg");
	this->dashingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downright_01.jpg");
	this->dashingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downright_02.jpg");
	this->dashingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downright_03.jpg");
	this->dashingDownRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->dashingDownRightAnimation->setRestoreOriginalFrame(true);
	this->dashingDownRightAnimation->retain();

	this->dashingDownRightAnimation->getFrames().at(0)->setUserInfo(dashingRightFrame00Info);
	this->dashingDownRightAnimation->getFrames().at(2)->setUserInfo(dashingRightFrame02Info);
	this->dashingDownRightAnimation->getFrames().at(3)->setUserInfo(dashingRightFrame03Info);



	this->dashingUpRightAnimation = Animation::create();
	this->dashingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upright_00.jpg");
	this->dashingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upright_01.jpg");
	this->dashingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upright_02.jpg");
	this->dashingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upright_03.jpg");
	this->dashingUpRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->dashingUpRightAnimation->setRestoreOriginalFrame(true);
	this->dashingUpRightAnimation->retain();

	this->dashingUpRightAnimation->getFrames().at(0)->setUserInfo(dashingRightFrame00Info);
	this->dashingUpRightAnimation->getFrames().at(2)->setUserInfo(dashingRightFrame02Info);
	this->dashingUpRightAnimation->getFrames().at(3)->setUserInfo(dashingRightFrame03Info);




	this->dashingLeftAnimation = Animation::create();
	this->dashingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_left_00.jpg");
	this->dashingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_left_01.jpg");
	this->dashingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_left_02.jpg");
	this->dashingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_left_03.jpg");
	this->dashingLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->dashingLeftAnimation->setRestoreOriginalFrame(true);
	this->dashingLeftAnimation->retain();

	this->dashingLeftAnimation->getFrames().at(0)->setUserInfo(dashingRightFrame00Info);
	this->dashingLeftAnimation->getFrames().at(2)->setUserInfo(dashingRightFrame02Info);
	this->dashingLeftAnimation->getFrames().at(3)->setUserInfo(dashingRightFrame03Info);



	this->dashingUpLeftAnimation = Animation::create();
	this->dashingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upleft_00.jpg");
	this->dashingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upleft_01.jpg");
	this->dashingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upleft_02.jpg");
	this->dashingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upleft_03.jpg");
	this->dashingUpLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->dashingUpLeftAnimation->setRestoreOriginalFrame(true);
	this->dashingUpLeftAnimation->retain();

	this->dashingUpLeftAnimation->getFrames().at(0)->setUserInfo(dashingRightFrame00Info);
	this->dashingUpLeftAnimation->getFrames().at(2)->setUserInfo(dashingRightFrame02Info);
	this->dashingUpLeftAnimation->getFrames().at(3)->setUserInfo(dashingRightFrame03Info);


	this->dashingDownLeftAnimation = Animation::create();
	this->dashingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downleft_00.jpg");
	this->dashingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downleft_03.jpg");
	this->dashingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downleft_03.jpg");
	this->dashingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downleft_03.jpg");
	this->dashingDownLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->dashingDownLeftAnimation->setRestoreOriginalFrame(true);
	this->dashingDownLeftAnimation->retain();

	this->dashingDownLeftAnimation->getFrames().at(0)->setUserInfo(dashingRightFrame00Info);
	this->dashingDownLeftAnimation->getFrames().at(2)->setUserInfo(dashingRightFrame02Info);
	this->dashingDownLeftAnimation->getFrames().at(3)->setUserInfo(dashingRightFrame03Info);





	//paws scratching right will need 2 animations: horizontal scratching and vertical scratching
	//same for scratching left.
	this->scratchingRightAnimation = Animation::create();
	this->scratchingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching_right_00.jpg");
	this->scratchingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching_right_01.jpg");
	this->scratchingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching_right_02.jpg");
	this->scratchingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching_right_03.jpg");
	this->scratchingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching_right_04.jpg");
	this->scratchingRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->scratchingRightAnimation->setRestoreOriginalFrame(true);
	this->scratchingRightAnimation->retain();

	ValueMap scratchingStartInfo;
	ValueMap scratchingLoseAllAbilitiesInfo;
	ValueMap scratchingRecoverScratchabilityInfo;
	ValueMap scratchingRecoverAllAbilitiesInfo;
	ValueMap scratchingToHoveringInfo;

	scratchingStartInfo["5"] = Value(5);
	scratchingLoseAllAbilitiesInfo["6"] = Value(6);
	scratchingRecoverScratchabilityInfo["7"] = Value(7);
	scratchingRecoverAllAbilitiesInfo["8"] = Value(8);
	scratchingToHoveringInfo["9"] = Value(9);

	scratchingRightAnimation->getFrames().at(0)->setUserInfo(scratchingStartInfo);
	scratchingRightAnimation->getFrames().at(1)->setUserInfo(scratchingLoseAllAbilitiesInfo);
	scratchingRightAnimation->getFrames().at(2)->setUserInfo(scratchingRecoverScratchabilityInfo);
	scratchingRightAnimation->getFrames().at(3)->setUserInfo(scratchingRecoverAllAbilitiesInfo);
	scratchingRightAnimation->getFrames().at(4)->setUserInfo(scratchingToHoveringInfo);

	EventListenerCustom * scratchingFrameEventListener = EventListenerCustom::create(AnimationFrameDisplayedNotification, [this, scratchingStartInfo, scratchingLoseAllAbilitiesInfo, scratchingRecoverScratchabilityInfo, scratchingRecoverAllAbilitiesInfo, scratchingToHoveringInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == scratchingStartInfo){
			this->disableAllAbilities();
			if (this->directionToMoveRight ){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL*2, Vec2(this->DISTANCE_DURING_SCRATCHING, 0)));
			}
			else if (this->directionToMoveLeft){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(-this->DISTANCE_DURING_SCRATCHING, 0)));
			}
			else if (this->directionToMoveUp){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(0, this->DISTANCE_DURING_SCRATCHING)));
			}
			else if (this->directionToMoveDown){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(0, -this->DISTANCE_DURING_SCRATCHING)));
			}
			else if (this->directionToMoveUpRight){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(this->DISTANCE_DURING_SCRATCHING / 1.414, this->DISTANCE_DURING_SCRATCHING / 1.414)));
			}
			else if (this->directionToMoveUpLeft){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(-this->DISTANCE_DURING_SCRATCHING / 1.414, this->DISTANCE_DURING_SCRATCHING / 1.414)));
			}
			else if (this->directionToMoveDownRight){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(this->DISTANCE_DURING_SCRATCHING / 1.414, -this->DISTANCE_DURING_SCRATCHING / 1.414)));
			}
			else if (this->directionToMoveDownLeft){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(-this->DISTANCE_DURING_SCRATCHING / 1.414, -this->DISTANCE_DURING_SCRATCHING / 1.414)));
			}
		}
		if (*userData->userInfo == scratchingLoseAllAbilitiesInfo){
			log("attacking at frame2");
			if (this->scratchingType == 1){
				this->scratchingType = 2;
			}
			else if(this->scratchingType == 2){
				this->scratchingType = 1;
			}
		}
		if (*userData->userInfo == scratchingRecoverScratchabilityInfo){
			this->scratchable = true;
		}
		if (*userData->userInfo == scratchingRecoverAllAbilitiesInfo){
			this->enableAllAbilities();
			this->moveableWithoutAnimation = false;
			if (this->directionToMoveUpRight ||
				this->directionToMoveRight ||
				this->directionToMoveDownRight ||
				this->directionToMoveDown ||
				this->directionToMoveDownLeft ||
				this->directionToMoveLeft ||
				this->directionToMoveUpLeft ||
				this->directionToMoveUp){
				this->move();
			}
		
		}
		if (*userData->userInfo == scratchingToHoveringInfo){
			this->hover();
			this->scratchingType = 1;
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(scratchingFrameEventListener, -1);

	this->scratchingRightAnimation2 = Animation::create();
	this->scratchingRightAnimation2->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching2_right_00.png");
	this->scratchingRightAnimation2->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching2_right_01.png");
	this->scratchingRightAnimation2->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching2_right_02.png");
	this->scratchingRightAnimation2->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching2_right_03.png");
	this->scratchingRightAnimation2->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching2_right_04.png");
	this->scratchingRightAnimation2->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->scratchingRightAnimation2->setRestoreOriginalFrame(true);
	this->scratchingRightAnimation2->retain();

	scratchingRightAnimation2->getFrames().at(0)->setUserInfo(scratchingStartInfo);
	scratchingRightAnimation2->getFrames().at(1)->setUserInfo(scratchingLoseAllAbilitiesInfo);
	scratchingRightAnimation2->getFrames().at(2)->setUserInfo(scratchingRecoverScratchabilityInfo);
	scratchingRightAnimation2->getFrames().at(3)->setUserInfo(scratchingRecoverAllAbilitiesInfo);
	scratchingRightAnimation2->getFrames().at(4)->setUserInfo(scratchingToHoveringInfo);


	this->scratchingLeftAnimation = Animation::create();
	this->scratchingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching_left_00.png");
	this->scratchingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching_left_01.png");
	this->scratchingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching_left_02.png");
	this->scratchingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching_left_03.png");
	this->scratchingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching_left_04.png");
	this->scratchingLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->scratchingLeftAnimation->setRestoreOriginalFrame(true);
	this->scratchingLeftAnimation->retain();

	scratchingLeftAnimation->getFrames().at(0)->setUserInfo(scratchingStartInfo);
	scratchingLeftAnimation->getFrames().at(1)->setUserInfo(scratchingLoseAllAbilitiesInfo);
	scratchingLeftAnimation->getFrames().at(2)->setUserInfo(scratchingRecoverScratchabilityInfo);
	scratchingLeftAnimation->getFrames().at(3)->setUserInfo(scratchingRecoverAllAbilitiesInfo);
	scratchingLeftAnimation->getFrames().at(4)->setUserInfo(scratchingToHoveringInfo);

	this->scratchingLeftAnimation2 = Animation::create();
	this->scratchingLeftAnimation2->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching2_left_00.png");
	this->scratchingLeftAnimation2->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching2_left_01.png");
	this->scratchingLeftAnimation2->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching2_left_02.png");
	this->scratchingLeftAnimation2->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching2_left_03.png");
	this->scratchingLeftAnimation2->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching2_left_04.png");
	this->scratchingLeftAnimation2->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->scratchingLeftAnimation2->setRestoreOriginalFrame(true);
	this->scratchingLeftAnimation2->retain();

	scratchingLeftAnimation2->getFrames().at(0)->setUserInfo(scratchingStartInfo);
	scratchingLeftAnimation2->getFrames().at(1)->setUserInfo(scratchingLoseAllAbilitiesInfo);
	scratchingLeftAnimation2->getFrames().at(2)->setUserInfo(scratchingRecoverScratchabilityInfo);
	scratchingLeftAnimation2->getFrames().at(3)->setUserInfo(scratchingRecoverAllAbilitiesInfo);
	scratchingLeftAnimation2->getFrames().at(4)->setUserInfo(scratchingToHoveringInfo);

	
	this->gettingHurtGeneralAnimation = Animation::create();
	this->gettingHurtGeneralAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_general_00.png");
	this->gettingHurtGeneralAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_general_01.png");
	this->gettingHurtGeneralAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_general_02.png");
	this->gettingHurtGeneralAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_general_03.png");
	this->gettingHurtGeneralAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->gettingHurtGeneralAnimation->setRestoreOriginalFrame(true);
	this->gettingHurtGeneralAnimation->retain();

	ValueMap gettingHurtGeneralStartInfo;
	ValueMap gettingHurtGeneralEndInfo;

	gettingHurtGeneralStartInfo["14"] = Value(10);
	gettingHurtGeneralEndInfo["15"] = Value(11);


	this->gettingHurtGeneralAnimation->getFrames().at(0)->setUserInfo(gettingHurtGeneralStartInfo);
	this->gettingHurtGeneralAnimation->getFrames().at(3)->setUserInfo(gettingHurtGeneralEndInfo);

	EventListenerCustom * gettingHurtGeneralFrameEventListener = EventListenerCustom::create(AnimationFrameDisplayedNotification, [this, gettingHurtGeneralStartInfo, gettingHurtGeneralEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == gettingHurtGeneralStartInfo){
			log("get hurt");
			this->disableAllAbilities();
		}
		if (*userData->userInfo == gettingHurtGeneralEndInfo){
			log("recovering from getting hurt");
			this->enableAllAbilities();
			this->hover();
			if (this->directionToMoveUpRight ||
				this->directionToMoveRight ||
				this->directionToMoveDownRight ||
				this->directionToMoveDown ||
				this->directionToMoveDownLeft ||
				this->directionToMoveLeft ||
				this->directionToMoveUpLeft ||
				this->directionToMoveUp){
				this->move();
			}
		}
	});

	_eventDispatcher->addEventListenerWithFixedPriority(gettingHurtGeneralFrameEventListener, -1);



}


HeroSprite::~HeroSprite()
{
}


void HeroSprite::button1Hit(){
	Vector<GeneralUnit *> enemyList1 = ((Stage1GameplayLayer *)this->getParent())->enemyList;
	bool enemyWithinScratch = false;
	for (GeneralUnit * enemy1 : enemyList1){
		int enemy_x = enemy1->getPositionX();
		int enemy_y = enemy1->getPositionY();
		if (enemy_y - this->getPositionY() < 50 && enemy_y - this->getPositionY() > -50){
			if (this->facingRight){
				if (enemy_x - this->getPositionX() < 100 && enemy_x - this->getPositionX() > 0){
					enemyWithinScratch = true;
					break;
				}
			}
			else if (this->facingLeft){
				if (enemy_x - this->getPositionX() > -100 && enemy_x - this->getPositionX() < 0){
					enemyWithinScratch = true;
					break;
				}
			}
			else{
				continue;
			}
		}
		else{
			continue;
		}


	}
	if (enemyWithinScratch){
		this->scratch();
	}
	else{
		this->windAttack();
	}
}
void HeroSprite::button1Release(){

}
void HeroSprite::button2Hit(){
	this->dash();
}
void HeroSprite::button2Release(){
	//do nothing
}

void HeroSprite::button3Hit(){
	
	this->getHurtGeneral();
}
void HeroSprite::button3Release(){

}

HeroSprite * HeroSprite::create(const std::string &filename){
	HeroSprite *mySprite = new HeroSprite();
	if (mySprite &&mySprite->initWithFile(filename)){
		mySprite->autorelease();
		return mySprite;
	}
	CC_SAFE_DELETE(mySprite);
	return nullptr;
}

void HeroSprite::getHurtGeneral(){
	this->stopAllActions();
	this->runAction(Animate::create(this->gettingHurtGeneralAnimation));
}

void HeroSprite::disableAllAbilities(){
	this->catchable = false;
	this->dashable = false;
	this->moveable = false;
	this->windAttackable = false;
	this->scratchable = false;
	this->throwable = false;
}
void HeroSprite::enableAllAbilities(){
	this->catchable = true;
	this->dashable = true;
	this->moveable = true;
	this->windAttackable = true;
	this->scratchable = true;
	this->throwable = true;
}

void HeroSprite::windAttack(){
	if (this->windAttackable){
		if (this->facingRight){
			this->stopAllActions();
			this->runAction(Animate::create(this->blowingWindRightAnimation));
		}
		else if (this->facingLeft){
			this->stopAllActions();
			this->runAction(Animate::create(this->blowingWindLeftAnimation));
		}
		/*
		Sprite * windBullet = Sprite::create();
		windBullet->setPosition(this->getPosition());
		this->getParent()->addChild(windBullet);
		windBullet->runAction(Spawn::create(MoveBy::create(0.4f, Vec2(300, 0)), Repeat::create(Animate::create(this->windBulletFlyingAnimation), 2), nullptr));
		*/
	}
}




void HeroSprite::scratch(){
	if (this->scratchable){
		if (this->scratchingType == 1){
			if (this->facingRight){
				this->scratchRight();
			}
			else if (this->facingLeft){
				this->scratchLeft();
			}
			//this->scratchingType = 2;
		}
		else{
			if (this->facingRight){
				this->scratchRight2();
			}
			else if (this->facingLeft){
				this->scratchLeft2();
			}
			//this->scratchingType = 1;
		}
	}
}

void HeroSprite::scratchRight(){
	this->stopAllActions();
	this->runAction(Animate::create(this->scratchingRightAnimation));
}
void HeroSprite::scratchRight2(){
	this->stopAllActions();
	this->runAction(Animate::create(this->scratchingRightAnimation2));
}
void HeroSprite::scratchLeft(){
	this->stopAllActions();
	this->runAction(Animate::create(this->scratchingLeftAnimation));
}
void HeroSprite::scratchLeft2(){
	this->stopAllActions();
	this->runAction(Animate::create(this->scratchingLeftAnimation2));
}


void HeroSprite::dash(){
	if (this->dashable){
		if (this->directionToMoveRight){
			dashRight();
		}
		else if (this->directionToMoveDown){
			dashDown();
		}
		else if (this->directionToMoveDownLeft){
			dashDownLeft();
		}
		else if (this->directionToMoveDownRight){
			dashDownRight();
		}
		else if (this->directionToMoveLeft){
			dashLeft();
		}
		else if(this->directionToMoveUp){
			dashUp();
		}
		else if (this->directionToMoveUpLeft){
			dashUpLeft();
		}
		else if (this->directionToMoveUpRight){
			dashUpRight();
		}
		if (this->directionToMoveDown == false &&
			this->directionToMoveUp == false &&
			this->directionToMoveRight == false &&
			this->directionToMoveLeft == false &&
			this->directionToMoveDownLeft == false &&
			this->directionToMoveDownRight == false &&
			this->directionToMoveUpLeft == false &&
			this->directionToMoveUpRight == false){

			if (this->facingRight){
				dashRight();
			}
			else if (this->facingLeft){
				dashLeft();
			}
		}

	}
}


//dashing in 8 directions.
void HeroSprite::dashUp(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_AIR_DASHING, Vec2(0, this->DISTANCE_AIR_DASHING)), MoveBy::create(this->TIME_FOR_AIR_DASHING_BRAKING, Vec2(0, this->DISTANCE_AIR_DASHING_BRAKING)), nullptr));
	if (this->facingRight){
		this->runAction(Animate::create(this->dashingUpRightAnimation));
	}
	else if(this->facingLeft){
		this->runAction(Animate::create(this->dashingUpLeftAnimation));
	}
}
void HeroSprite::dashDown(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_AIR_DASHING, Vec2(0, -this->DISTANCE_AIR_DASHING)), MoveBy::create(this->TIME_FOR_AIR_DASHING_BRAKING, Vec2(0, -this->DISTANCE_AIR_DASHING_BRAKING)), nullptr));
	if (this->facingRight){
		this->runAction(Animate::create(this->dashingDownRightAnimation));
	}
	else if(this->facingLeft){
		this->runAction(Animate::create(this->dashingDownLeftAnimation));
	}
}
void HeroSprite::dashLeft(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_AIR_DASHING, Vec2(-this->DISTANCE_AIR_DASHING, 0)), MoveBy::create(this->TIME_FOR_AIR_DASHING_BRAKING, Vec2(-this->DISTANCE_AIR_DASHING_BRAKING, 0)), nullptr));
	this->runAction(Animate::create(this->dashingLeftAnimation));
}
void HeroSprite::dashRight(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_AIR_DASHING, Vec2(this->DISTANCE_AIR_DASHING, 0)), MoveBy::create(this->TIME_FOR_AIR_DASHING_BRAKING, Vec2(this->DISTANCE_AIR_DASHING_BRAKING, 0)), nullptr));
	this->runAction(Animate::create(this->dashingRightAnimation));
	//FiniteTimeAction * moveAction = Sequence::create(MoveBy::create(this->TIME_FOR_AIR_DASHING, Vec2(this->DISTANCE_AIR_DASHING, 0)), MoveBy::create(this->TIME_FOR_AIR_DASHING_BRAKING, Vec2(this->DISTANCE_AIR_DASHING_BRAKING, 0)), nullptr);
	//FiniteTimeAction * animationAction = Animate::create(this->dashingRightAnimation);
	//this->runAction(Spawn::create(moveAction, animationAction));
}
void HeroSprite::dashUpRight(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_AIR_DASHING, Vec2(this->DISTANCE_AIR_DASHING / 1.414, this->DISTANCE_AIR_DASHING / 1.414)), MoveBy::create(this->TIME_FOR_AIR_DASHING_BRAKING, Vec2(this->DISTANCE_AIR_DASHING_BRAKING / 1.414, this->DISTANCE_AIR_DASHING_BRAKING / 1.414)), nullptr));
	this->runAction(Animate::create(this->dashingUpRightAnimation));
}
void HeroSprite::dashUpLeft(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_AIR_DASHING, Vec2(-this->DISTANCE_AIR_DASHING / 1.414, this->DISTANCE_AIR_DASHING / 1.414)), MoveBy::create(this->TIME_FOR_AIR_DASHING_BRAKING, Vec2(-this->DISTANCE_AIR_DASHING_BRAKING / 1.414, this->DISTANCE_AIR_DASHING_BRAKING / 1.414)), nullptr));
	this->runAction(Animate::create(this->dashingUpLeftAnimation));
}
void HeroSprite::dashDownRight(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_AIR_DASHING, Vec2(this->DISTANCE_AIR_DASHING / 1.414, -this->DISTANCE_AIR_DASHING / 1.414)), MoveBy::create(this->TIME_FOR_AIR_DASHING_BRAKING, Vec2(this->DISTANCE_AIR_DASHING_BRAKING / 1.414, -this->DISTANCE_AIR_DASHING_BRAKING / 1.414)), nullptr));
	this->runAction(Animate::create(this->dashingDownRightAnimation));
}
void HeroSprite::dashDownLeft(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_AIR_DASHING, Vec2(-this->DISTANCE_AIR_DASHING / 1.414, -this->DISTANCE_AIR_DASHING / 1.414)), MoveBy::create(this->TIME_FOR_AIR_DASHING_BRAKING, Vec2(-this->DISTANCE_AIR_DASHING_BRAKING / 1.414, -this->DISTANCE_AIR_DASHING_BRAKING / 1.414)), nullptr));
	this->runAction(Animate::create(this->dashingDownLeftAnimation));
}



//这个move对外开放，主角的普通移动只调用它。为了调试方便，所有细节目前都是public。八方向移动方法此时是public，今后应改为private。
//在此验证了主角在调用move方法时的可移动性。
//one more 废话：move是说方向按钮造成的位移，dash是说冲刺技能造成的位移。
void HeroSprite::move(){
	if (this->moveable){
		if (this->directionToMoveRight) {
			moveRight();
		}
		if (this->directionToMoveLeft){
			moveLeft();
		}
		if (this->directionToMoveUp){
			moveUp();
		}
		if (this->directionToMoveDown){
			moveDown();
		}

		if (this->directionToMoveUpRight){
			moveUpRight();
		}
		if (this->directionToMoveUpLeft){
			moveUpLeft();
		}
		if (this->directionToMoveDownRight){
			moveDownRight();
		}
		if (this->directionToMoveDownLeft){
			moveDownLeft();
		}
		if (this->directionToMoveUpRight == false &&
			this->directionToMoveRight == false &&
			this->directionToMoveDownRight == false &&
			this->directionToMoveDown == false &&
			this->directionToMoveDownLeft == false &&
			this->directionToMoveLeft == false &&
			this->directionToMoveUpLeft == false &&
			this->directionToMoveUp == false){
			moveBrake();
		}
	}
	/*
	else if (this->moveableWithoutAnimation){
		if (this->directionToMoveRight) {
			this->moveRightWithoutAnimation();
		}
		if (this->directionToMoveLeft){
			this->moveLeftWithoutAnimation();
		}
		if (this->directionToMoveUp){
			this->moveUpWithoutAnimation();
		}
		if (this->directionToMoveDown){
			this->moveDownWithoutAnimation();
		}
		if (this->directionToMoveUpRight){
			this->moveUpRightWithoutAnimation();
		}
		if (this->directionToMoveUpLeft){
			this->moveUpLeftWithoutAnimation();
		}
		if (this->directionToMoveDownRight){
			this->moveDownRightWithoutAnimation();
		}
		if (this->directionToMoveDownLeft){
			this->moveDownLeftWithoutAnimation();
		}
		if (this->directionToMoveUpRight == false &&
			this->directionToMoveRight == false &&
			this->directionToMoveDownRight == false &&
			this->directionToMoveDown == false &&
			this->directionToMoveDownLeft == false &&
			this->directionToMoveLeft == false &&
			this->directionToMoveUpLeft == false &&
			this->directionToMoveUp == false){
			moveBrake();
		}
	}
	*/
}


//moving in 8 directions
//仅仅将向右移动和播放移动动画一起run一下，没做是否可移动的验证。剩下的七个动画亦然。以后要加入扑打翅膀的声音
void HeroSprite::moveRight(){
	this->facingRight = true;
	this->facingLeft = false;
	this->stopAllActions();

	//this->runAction(Spawn::create(RepeatForever::create(MoveBy::create(2.0f,Vec2(33,0))),RepeatForever::create(Animate::create(this->movingRightAnimation)),nullptr));//不知为何，这行用不了，提示[Action update] override me
	/*
	Sequence和Spawn就是不能和RepeatForever一起用的。理由见源码，RepeatForever的interval = 0，不能做除数，跳入另一流程。
	*/
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->speed_flying_pixel_per_second, 0))));
	this->runAction(RepeatForever::create(Animate::create(this->movingRightAnimation)));
}
void HeroSprite::moveLeft(){
	this->facingRight = false;
	this->facingLeft = true;
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->speed_flying_pixel_per_second, 0))));
	this->runAction(RepeatForever::create(Animate::create(this->movingLeftAnimation)));
}
void HeroSprite::moveUp(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(0, this->speed_flying_pixel_per_second))));
	this->runAction(RepeatForever::create(Animate::create(this->movingUpAnimation)));
}
void HeroSprite::moveDown(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(0, -this->speed_flying_pixel_per_second))));
	this->runAction(RepeatForever::create(Animate::create(this->movingDownAnimation)));
}
void HeroSprite::moveUpRight(){
	this->facingRight = true;
	this->facingLeft = false;
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->speed_flying_pixel_per_second / 1.4142, this->speed_flying_pixel_per_second / 1.4142))));
	this->runAction(RepeatForever::create(Animate::create(this->movingUpRightAnimation)));
}
void HeroSprite::moveUpLeft(){
	this->facingRight = false;
	this->facingLeft = true;
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->speed_flying_pixel_per_second / 1.4142, this->speed_flying_pixel_per_second / 1.4142))));
	this->runAction(RepeatForever::create(Animate::create(this->movingUpLeftAnimation)));
}
void HeroSprite::moveDownRight(){
	this->facingRight = true;
	this->facingLeft = false;
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->speed_flying_pixel_per_second / 1.4142, -this->speed_flying_pixel_per_second / 1.4142))));
	this->runAction(RepeatForever::create(Animate::create(this->movingDownRightAnimation)));
}
void HeroSprite::moveDownLeft(){
	this->facingRight = false;
	this->facingLeft = true;
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->speed_flying_pixel_per_second / 1.4142, -this->speed_flying_pixel_per_second / 1.4142))));
	this->runAction(RepeatForever::create(Animate::create(this->movingDownLeftAnimation)));
}

void HeroSprite::moveRightWithoutAnimation(){
	this->moveWithoutAnimationBrake();
	//this->runAction(this->moveRightWithoutAnimation);
}
void HeroSprite::moveUpWithoutAnimation(){
	this->moveWithoutAnimationBrake();
	//this->runAction(this->moveUpWithoutAnimation);
	//this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(0, this->SPEED_DURING_ATTACKING_FLYING))));
}
void HeroSprite::moveDownWithoutAnimation(){
	this->moveWithoutAnimationBrake();
	//this->runAction(this->moveDownWithoutAnimation);
	//this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(0, -this->SPEED_DURING_ATTACKING_FLYING))));
}
void HeroSprite::moveLeftWithoutAnimation(){
	this->moveWithoutAnimationBrake();
	//this->runAction(this->moveLeftWithoutAnimation);
	//this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->SPEED_DURING_ATTACKING_FLYING, 0))));
}
void HeroSprite::moveUpRightWithoutAnimation(){
	this->moveWithoutAnimationBrake();
	//this->runAction(this->moveUpRightWithoutAnimation);
	//this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->SPEED_DURING_ATTACKING_FLYING / 1.4142, this->SPEED_DURING_ATTACKING_FLYING / 1.4142))));
}
void HeroSprite::moveUpLeftWithoutAnimation(){
	this->moveWithoutAnimationBrake();
	//this->runAction(this->moveUpLeftWithoutAnimation);
	//this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->SPEED_DURING_ATTACKING_FLYING / 1.4142, this->SPEED_DURING_ATTACKING_FLYING / 1.4142))));
}
void HeroSprite::moveDownRightWithoutAnimation(){
	this->moveWithoutAnimationBrake();
	//this->runAction(this->moveDownRightWithoutAnimation);
	//this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->SPEED_DURING_ATTACKING_FLYING / 1.4142, -this->SPEED_DURING_ATTACKING_FLYING / 1.4142))));
}
void HeroSprite::moveDownLeftWithoutAnimation(){
	this->moveWithoutAnimationBrake();
	//this->runAction(this->moveDownLeftWithoutAnimation);
	//this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->SPEED_DURING_ATTACKING_FLYING / 1.4142, -this->SPEED_DURING_ATTACKING_FLYING / 1.4142))));
}

void HeroSprite::moveWithoutAnimationBrake(){
	//this->stopAction(this->moveRightWithoutAnimation);
	//this->stopAction(this->moveLeftWithoutAnimation);
	//this->stopAction(this->moveUpWithoutAnimation);
	//this->stopAction(this->moveDownWithoutAnimation);
	//this->stopAction(this->moveUpRightWithoutAnimation);
	//this->stopAction(this->moveDownRightWithoutAnimation);
	//this->stopAction(this->moveUpLeftWithoutAnimation);
	//this->stopAction(this->moveDownLeftWithoutAnimation);
}



//brakes after moving。虽然暂时没做完，但是一定要做的。这关系到技能流畅度
void HeroSprite::moveRightBrake(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(this->hoveringRightAnimation)));
}
void HeroSprite::moveLeftBrake(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(this->hoveringLeftAnimation)));
}
void HeroSprite::moveDownBrake(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(this->hoveringRightAnimation)));
}
void HeroSprite::moveUpBrake(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(this->hoveringRightAnimation)));
}
void HeroSprite::moveBrake(){
	this->stopAllActions();
	if (this->facingRight){
		this->runAction(RepeatForever::create(Animate::create(this->hoveringRightAnimation)));
	}
	else if (this->facingLeft){
		this->runAction(RepeatForever::create(Animate::create(this->hoveringLeftAnimation)));

	}
}

void HeroSprite::hover(){
	this->stopAllActions();
	if (this->facingRight){
		this->runAction(RepeatForever::create(Animate::create(this->hoveringRightAnimation)));
	}
	else if (this->facingLeft){
		this->runAction(RepeatForever::create(Animate::create(this->hoveringLeftAnimation)));
	}
}