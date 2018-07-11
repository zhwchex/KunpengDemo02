#include "Zhurong.h"
#include "Stage1GameplayLayer.h"


Zhurong::Zhurong()
{
	//祝融移动动画，开始播放到播放完毕前，外面对wanderAbout的调用没有效果。
	this->walkingLeftWhileFacingLeftAnimation = Animation::create();
	this->walkingLeftWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/walking_left_while_facing_left_00.png");
	this->walkingLeftWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/walking_left_while_facing_left_01.png");
	this->walkingLeftWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/walking_left_while_facing_left_02.png");
	this->walkingLeftWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/walking_left_while_facing_left_03.png");
	this->walkingLeftWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/walking_left_while_facing_left_04.png");
	this->walkingLeftWhileFacingLeftAnimation->setDelayPerUnit(this->ANIMATION_FRAME_INTERVAL);
	this->walkingLeftWhileFacingLeftAnimation->setRestoreOriginalFrame(true);
	this->walkingLeftWhileFacingLeftAnimation->retain();

	ValueMap walkingAnimationStartInfo;
	ValueMap walkingAnimationEndInfo;

	walkingAnimationStartInfo["zhurong0"] = Value("zhurong0");
	walkingAnimationEndInfo["zhurong1"] = Value("zhurong1");

	this->walkingLeftWhileFacingLeftAnimation->getFrames().at(0)->setUserInfo(walkingAnimationStartInfo);//动画的第0帧携带“开始动画”的信息
	this->walkingLeftWhileFacingLeftAnimation->getFrames().at(4)->setUserInfo(walkingAnimationEndInfo);//动画的最后一帧携带“结束动画”的信息

	EventListenerCustom * walkingFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, walkingAnimationStartInfo, walkingAnimationEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == walkingAnimationStartInfo){
			this->acceptCall = false;//在动画开始的第一帧禁止外面调用wanderAbout()
		}
		if (*userData->userInfo == walkingAnimationEndInfo){
			this->acceptCall = true;//动画结束时，允许祝融接受外面调用wanderAbout()
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(walkingFrameEventListener, -1);





	this->shootingFireBallWhileFacingLeftAnimation = Animation::create();
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_00.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_01.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_02.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_03.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_04.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_05.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_06.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_07.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_08.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_09.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_10.png");
	this->shootingFireBallWhileFacingLeftAnimation->setDelayPerUnit(this->ANIMATION_FRAME_INTERVAL);
	this->shootingFireBallWhileFacingLeftAnimation->setRestoreOriginalFrame(true);
	this->shootingFireBallWhileFacingLeftAnimation->retain();

	ValueMap shootingFireBallStartAnimation;
	ValueMap shootingFireBallLaunchingAnimation;
	ValueMap shootingFireBallEndAnimation;

	shootingFireBallStartAnimation["zhurong2"] = Value("zhurong2");
	shootingFireBallLaunchingAnimation["zhurong3"] = Value("zhurong3");
	shootingFireBallEndAnimation["zhurong4"] = Value("zhurong4");


	this->shootingFireBallWhileFacingLeftAnimation->getFrames().at(0)->setUserInfo(shootingFireBallStartAnimation);//动画的第0帧携带“开始动画”的信息
	this->shootingFireBallWhileFacingLeftAnimation->getFrames().at(8)->setUserInfo(shootingFireBallLaunchingAnimation);//动画的第8帧携带“火球脱手”的信息
	this->shootingFireBallWhileFacingLeftAnimation->getFrames().at(10)->setUserInfo(shootingFireBallEndAnimation);//动画的最后一帧携带“结束动画”的信息

	EventListenerCustom * shootingFireBallFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, shootingFireBallStartAnimation, shootingFireBallLaunchingAnimation, shootingFireBallEndAnimation](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == shootingFireBallStartAnimation){
			this->acceptCall = false;//在动画开始的第0帧开始禁止外面调用wanderAbout()
		}
		
		if (*userData->userInfo == shootingFireBallLaunchingAnimation){
			//创造一个火球，脱手飞向主角。 不妨令火球的飞行速度为200像素/秒。
			Sprite * fireball = Sprite::create("characters/zhurong/fire_ball_00.png");
			Sprite * hero = ((Stage1GameplayLayer *)this->getParent())->kunpeng;
			fireball->setPosition(this->getPosition());
			this->getParent()->addChild(fireball);
			int deltax = hero->getPositionX() - fireball->getPositionX();
			int deltay = hero->getPositionY() - fireball->getPositionY();

			double distance = sqrt(pow(deltax, 2) + pow(deltax, 2));
			fireball->runAction(RepeatForever::create(MoveBy::create(distance / 200, Vec2(deltax, deltay))));
			fireball->runAction(RepeatForever::create(Animate::create(this->fireballSpinningAnimation)));

		}
		
		if (*userData->userInfo == shootingFireBallEndAnimation){
			this->acceptCall = true;//动画结束时，允许祝融接受外面调用wanderAbout()
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(shootingFireBallFrameEventListener, -1);


	//火球旋转动画。每个动画帧都判断一下是否撞到主角或掉进水里。
	this->fireballSpinningAnimation = Animation::create();
	this->fireballSpinningAnimation->addSpriteFrameWithFileName("characters/zhurong/fire_ball_00.png");
	this->fireballSpinningAnimation->addSpriteFrameWithFileName("characters/zhurong/fire_ball_01.png");
	this->fireballSpinningAnimation->addSpriteFrameWithFileName("characters/zhurong/fire_ball_02.png");
	this->fireballSpinningAnimation->addSpriteFrameWithFileName("characters/zhurong/fire_ball_03.png");
	this->fireballSpinningAnimation->setDelayPerUnit(this->ANIMATION_FRAME_INTERVAL);
	this->fireballSpinningAnimation->setRestoreOriginalFrame(true);
	this->fireballSpinningAnimation->retain();


	ValueMap fireballCheckIfHitHeroOrHitWaterInfo;

	fireballCheckIfHitHeroOrHitWaterInfo["zhurong5"] = Value("zhurong5");

	this->fireballSpinningAnimation->getFrames().at(0)->setUserInfo(fireballCheckIfHitHeroOrHitWaterInfo);
	this->fireballSpinningAnimation->getFrames().at(1)->setUserInfo(fireballCheckIfHitHeroOrHitWaterInfo);
	this->fireballSpinningAnimation->getFrames().at(2)->setUserInfo(fireballCheckIfHitHeroOrHitWaterInfo);
	this->fireballSpinningAnimation->getFrames().at(3)->setUserInfo(fireballCheckIfHitHeroOrHitWaterInfo);

	EventListenerCustom * fireBallSpinningFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, fireballCheckIfHitHeroOrHitWaterInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == fireballCheckIfHitHeroOrHitWaterInfo){
			//计算火球与主角的距离来判断是否击中。如果击中，调用主角的受伤方法并将火球从父节点上移除
			Sprite * fireBall = (Sprite *)userData->target; //userData是一个结构体，里面有个叫target的Node，该Node即为播放到这一帧的事主
			Sprite * hero = ((Stage1GameplayLayer *)this->getParent())->kunpeng;
			int deltax = fireBall->getPositionX() - hero->getPositionX();
			int deltay = fireBall->getPositionY() - hero->getPositionY();;

			double distance = sqrt(pow(deltax,2)+pow(deltax,2));
			if (distance < (fireBall->getContentSize().width + (hero->getContentSize().width)) * 50 / 100){
				((HeroSprite*)hero)->getHurtGeneral(10);
				fireBall->stopAllActions();
				fireBall->removeFromParent();
			}
		}
		
	});
	_eventDispatcher->addEventListenerWithFixedPriority(fireBallSpinningFrameEventListener, -1);


}


Zhurong::~Zhurong()
{
}

Zhurong * Zhurong::create(const std::string & filename){
	Zhurong * myUnit = new Zhurong();
	if (myUnit && myUnit->initWithFile(filename)){
		myUnit->autorelease();
		return myUnit;
	}
	CC_SAFE_DELETE(myUnit);
	return nullptr;
}




void Zhurong::walkLeftWhileFacingLeft(){
	this->stopAllActions();
	this->runAction(MoveBy::create(this->ANIMATION_FRAME_INTERVAL*100, Vec2(-100,0)));
	this->runAction(Animate::create(this->walkingLeftWhileFacingLeftAnimation));
}

void Zhurong::prepareAndLaunchAFireballWhileFacingLeft(){
	this->stopAllActions();
	this->runAction(Animate::create(this->shootingFireBallWhileFacingLeftAnimation));
}


void Zhurong::idle(){

}

/**
 * 不接受别人调用时，这个对象不做事，直接返回
 * 接受别人调用时，该对象按一定规则进行一个动作
 */
void Zhurong::wanderAbout(){
	if (this->acceptCall){
		//do something like randomly calling some method here if this object accepts calls.
		srand((unsigned)time(NULL));
		int nextMovement = rand() % 11;

		if (nextMovement == 1){
			this->walkLeftWhileFacingLeft();
		}
		else if (nextMovement == 0){
			this->prepareAndLaunchAFireballWhileFacingLeft(); 
		}

	}
	else{
		return;
	}
}

void Zhurong::getHurt(int damage){

}
void Zhurong::getHurtByWind(int damage){

}
void Zhurong::getHurtByPaw(int damage){

}
void Zhurong::getHurtByCrush(int damage){

}

void Zhurong::getHurtByWater(int damage){

}
void Zhurong::getHurtByFin(int damage){

}

void Zhurong::die(){

}
