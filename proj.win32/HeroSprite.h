#pragma once
#include "cocos2d.h"
USING_NS_CC;
class HeroSprite :	public Sprite
{

public:

	int speed_flying_pixel_per_second = 266;
	int speed_swimming_pixel_per_second = 200;

	//悬停动画
	Animation * hoveringAnimation;

	//普通移动的动画
	Animation * movingUpAnimation;	
	Animation * movingUpRightAnimation;
	Animation * movingRightAnimation;
	Animation * movingDownRightAnimation;
	Animation * movingDownAnimation;
	Animation * movingDownLeftAnimation;
	Animation * movingLeftAnimation;
	Animation * movingUpLeftAnimation;




	//冲刺动画
	Animation * dashingUpAnimation;
	Animation * dashingUpRightAnimation;
	Animation * dashingRightAnimation;
	Animation * dashingDownRightAnimation;
	Animation * dashingDownAnimation;
	Animation * dashingDownLeftAnimation;
	Animation * dashingLeftAnimation;
	Animation * dashingUpLeftAnimation;

	//技能动画
	Animation * blowingWindAnimation;
	Animation * scratchingAnimation;

	Animation * tryCatchAnimation;//试图使用一下投技
	Animation * holdingObjectAnimation;//抓住物品不放的动画
	Animation * holdingEnemyAnimation;//抓住敌人不放的动画
	Animation * throwingObjectAnimation;//扔出物品的动画
	Animation * throwingEnemyAnimationi;//对小兵使用投技的动画

	Animation * throwingBossAnimation;//对Boss使用投技的动画

	Animation * windBulletFlyingAnimation;


	//主角不是鸟就是鱼，没有第三个可能性
	bool isBird = true;
	bool isFish = false;

	//主角的运动状态，这些状态与技能施放有关。例如，只有在飞行时才能施放风弹
	bool facingRight = true;
	bool facingLeft = false;
	bool flying = true;
	//bool walking = false;//放弃主角降落在地面并欢快奔跑的构想
	bool swimming = false;

	//主角正在干嘛。
	bool moving = false;
	bool windAttacking = false;
	bool pawAttacking = false;
	bool pawTryingCatch = false;
	bool pawHolding = false;
	bool pawThrowing = false;
	bool pawThrowingBoss = false;

	//主角当前能干嘛的状态。
	bool moveable = true;//能自由移动
	bool longRangeAttackable = true;//翅膀未被占用，能发射风弹
	bool pawAttackable = true;//爪子未被占用，能撕扯。例：当使用爪子提起物品或敌人时该项设为false，该项为false时即使敌人近身也无法触发近战爪子攻击
	bool dashable = true;//能否冲刺。
	bool catchable = true;//爪子能否抓东西。例：剧情安排或正在撕扯时该项为false。
	bool throwable = true;//能否将爪子上的东西扔出。例：主角不能一心二用。如果当前正在使用翅膀发射风弹，则该项为false，该项为false时调用throw方法将不会触发敌人被扔下的动画，将触发敌人从爪下生还顺毛重新发动攻击的动画。

	bool invincible = false;//是否无敌。为了让玩家有清场能力，将新的生命设置三秒无敌；为了让玩家爽到，将投boss时的主角设置为无敌。



	bool directionToMoveRight = false;
	bool directionToMoveLeft = false;
	bool directionToMoveUp = false;
	bool directionToMoveDown = false;
	bool directionToMoveUpRight = false;
	bool directionToMoveUpLeft = false;
	bool directionToMoveDownRight = false;
	bool directionToMoveDownLeft = false;

	int lastDirection = 0;//0↑，1↗，2→，3↘，4↓，5↙，6←，7↖

	bool DirectionToPawhold = false;

	static HeroSprite * create(const std::string & filename);

	void move();//多个重载。！！**这是一个延时动作**！！
	void move(double direction);
	void moveBrake();


	void moveRight();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveUpRight();
	void moveUpLeft();
	void moveDownRight();
	void moveDownLeft();


	void moveRightBrake();
	void moveUpBrake();
	void moveDownBrake();
	void moveLeftBrake();
	void moveUpRightBrake();
	void moveUpLeftBrake();
	void moveDownRightBrake();
	void moveDownLeftBrake();

	


	void windAttack();//多个重载
	void pawAttack();
	void pawHold();//！！**这是一个延时动作**！！
	void pawThrowObject();
	void pawThrowEnemy();
	void pawThrowBoss();//多个重载

	void getHurt();//多个重载
	void getHurtByThunder();
	void getHurtByFire();
	void getHurtByWater();
	void getHurtByHammer();//被锤，被吹飞
	void getHurtByHammer(double direction);//吹飞方向为direction。0代表往上吹飞，90代表往右吹飞，180代表往下吹飞，270代表往左吹飞。
	void getHurtByWind();

	HeroSprite();
	~HeroSprite();
};

