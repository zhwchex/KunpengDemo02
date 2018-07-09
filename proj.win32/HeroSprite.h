//由于本角色过于庞大，开发旷日持久，昨天的思维和今天的思维不在一条线上，因此出现了这里用鸟那里用鹏的措辞不一致的现象，和这里用鱼那里用鲲的措辞不一致的情况。事实上我口中的鸟=鹏，鱼=鲲，bird=peng，fish=kun。
//郑重声明：#define 鸟 鹏
//郑重声明：#define 鱼 鲲
//郑重声明：#define bird peng
//郑重声明：#define fish kun

#pragma once
#include "cocos2d.h"
#include "GeneralUnit.h"
#include "WindBullet.h"
#include "WaterBullet.h"

USING_NS_CC;
class HeroSprite :	public Sprite
{

public:


	//十个风弹和对应的爆炸效果
	const int NUM_OF_WIND_BULLETS = 10;
	(WindBullet *) windBullets[10];
	int launchedWindBulletCount = 0;

	const int NUM_OF_WIND_BULLET_EXPLOSIONS = 10;
	(Sprite *) windBulletExplosions[10];
	int windBulletExplosionCount = 0;

	//十个水弹和对应的爆炸效果
	const int NUM_OF_WATER_BULLETS = 10;
	(WaterBullet *)waterBullets[10];
	int launchedWaterBulletCount = 0;

	const int NUM_OF_WATER_BULLET_EXPLOSIONS = 10;
	(Sprite *) waterBulletExplosions[10];
	int waterBulletExplosionCount = 0;


	int health = 100;

	int camp = 1;


	int DAMAGE_WIND = 15;

	int DAMAGE_SCRATCH = 50;

	int DAMAGE_VORTEX = 20;

	int DAMAGE_FIN = 40;

	int DAMAGE_CRUSH = 100;

	float TIME_FOR_ANIMATION_FRAME_INTERVAL = 0.1f;

	int SPEED_FLYING_PIXEL_PER_SECOND = 266;
	int SPEED_SWIMMING_PIXEL_PER_SECOND = 166;

	int SPEED_DURING_ATTACKING_FLYING = 133;

	int DISTANCE_DURING_SCRATCHING = 20;

	int DISTANCE_AIR_DASHING = 200;
	int DISTANCE_AIR_DASHING_BRAKING = 20;
	int DISTANCE_WATER_DASHING = 120;
	int DISTANCE_WATER_DASHING_BRAKING = 60;

	float TIME_FOR_AIR_DASHING = 0.3f;
	float TIME_FOR_AIR_DASHING_BRAKING = 0.2f;
	float TIME_FOR_WATER_DASHING = 0.2f;
	float TIME_FOR_WATER_DASHING_BRAKING = 0.3f;

	int scratchingType = 1;
	int finAttackingType = 1;

	//鸟悬停动画
	Animation * hoveringRightAnimation;
	Animation * hoveringLeftAnimation;

	//鸟普通移动的动画
	Animation * movingUpAnimation;
	Animation * movingUpRightAnimation;
	Animation * movingRightAnimation;
	Animation * movingDownRightAnimation;
	Animation * movingDownAnimation;
	Animation * movingDownLeftAnimation;
	Animation * movingLeftAnimation;
	Animation * movingUpLeftAnimation;

	//鱼悬停的动画
	Animation * hoveringRightAnimation_kun;
	Animation * hoveringLeftAnimation_kun;

	//鱼普通移动的动画
	Animation * movingUpRightAnimation_kun;
	Animation * movingRightAnimation_kun;
	Animation * movingDownRightAnimation_kun;
	Animation * movingDownLeftAnimation_kun;
	Animation * movingLeftAnimation_kun;
	Animation * movingUpLeftAnimation_kun;


	//鸟冲刺动画
	Animation * dashingUpAnimation;
	Animation * dashingUpRightAnimation;
	Animation * dashingRightAnimation;
	Animation * dashingDownRightAnimation;
	Animation * dashingDownAnimation;
	Animation * dashingDownLeftAnimation;
	Animation * dashingLeftAnimation;
	Animation * dashingUpLeftAnimation;

	//鱼冲刺动画
	Animation * dashingUpAnimation_kun;
	Animation * dashingUpRightAnimation_kun;
	Animation * dashingRightAnimation_kun;
	Animation * dashingDownRightAnimation_kun;
	Animation * dashingDownAnimation_kun;
	Animation * dashingDownLeftAnimation_kun;
	Animation * dashingLeftAnimation_kun;
	Animation * dashingUpLeftAnimation_kun;

	//鸟技能动画
	Animation * blowingWindRightAnimation;
	Animation * blowingWindLeftAnimation;
	Animation * scratchingRightAnimation;
	Animation * scratchingRightAnimation2;
	Animation * scratchingLeftAnimation;
	Animation * scratchingLeftAnimation2;

	Animation * tryCatchAnimation;//试图使用一下投技
	Animation * holdingObjectAnimation;//抓住物品不放的动画
	Animation * holdingEnemyAnimation;//抓住敌人不放的动画
	Animation * throwingObjectAnimation;//扔出物品的动画
	Animation * throwingEnemyAnimationi;//对小兵使用投技的动画

	Animation * throwingBossAnimation;//对Boss使用投技的动画

	//鱼技能动画
	Animation * blowingVortexRightAnimation;
	Animation * blowingVortexLeftAnimation;
	Animation * finAttackRightAnimation;
	Animation * finAttackRightAnimation2;
	Animation * finAttackLeftAnimation;
	Animation * finAttackLeftAnimation2;

	Animation * fallingFromSkyRightAnimation;//从空中掉入水中的过程动画。当自己是在空中的鱼时触发。掉落时每时每刻都要判断是否入水，因此需要做成无限循环动作，每帧都判断是否入水。掉落时只能变身为鸟或吐水泡。
	Animation * fallingFromSkyLeftAnimation;//从空中掉入水中的过程动画。当自己是在空中的鱼时触发。掉落时每时每刻都要判断是否入水，因此需要做成无限循环动作，每帧都判断是否入水。掉落时只能变身为鸟或吐水泡。
	Animation * enteringIntoWaterRightAnimation;//入水动画。第一帧开始禁掉全能力，播放到一半enable全能力并且如果有方向键就move_kun，最后一帧转入hover_kun。
	Animation * enteringIntoWaterLeftAnimation;//入水动画。第一帧开始禁掉全能力，播放到一半enable全能力并且如果有方向键就move_kun，最后一帧转入hover_kun。

	//主角的招式特效
	Animation * windBulletFlyingAnimation;
	Animation * waterBulletMarchingAnimation;
	
	Animation * windBulletExplosionAnimation;
	Animation * waterBulletExplosionAnimation;


	Animation * TransformingFromBirdToFishAnimation;
	Animation * TransformingFromFishToBirdAnimation;

	Animation * waterSplashingAnimation_big;
	Animation * waterSplashingAnimation_small;

	Animation * gettingHurtGeneralAnimation;

	RepeatForever * moveRightWithoutAnimationAction;
	RepeatForever * moveLeftWithoutAnimationAction;
	RepeatForever * moveUpWithoutAnimationAction;
	RepeatForever * moveDownWithoutAnimationAction;
	RepeatForever * moveUpRightWithoutAnimationAction;
	RepeatForever * moveDownRightWithoutAnimationAction;
	RepeatForever * moveUpLeftWithoutAnimationAction;
	RepeatForever * moveDownLeftWithoutAnimationAction;


	//主角不是鸟就是鱼，没有第三个可能性
	bool isBird = true;
	bool isFish = false;

	

	//主角的运动状态，这些状态与技能施放有关。例如，只有在飞行时才能施放风弹
	bool facingRight = true;
	bool facingLeft = false;

	bool inTheAir = true;
	//bool walking = false;//放弃主角降落在地面并欢快奔跑的构想
	bool inTheWater = false;

	//主角正在干嘛。
	bool hovering = true;
	bool moving = false;
	bool dashing = false;
	bool windAttacking = false;
	bool scratching = false;
	bool pawTryingCatch = false;
	bool pawHolding = false;
	bool pawThrowing = false;
	bool pawThrowingBoss = false;

	//主角当前能干嘛的状态。
	bool moveableWithoutAnimation = false;
	bool moveable = true;//能自由移动
	bool windAttackable = true;//翅膀未被占用，能发射风弹
	bool scratchable = true;//爪子未被占用，能撕扯。例：当使用爪子提起物品或敌人时该项设为false，该项为false时即使敌人近身也无法触发近战爪子攻击
	bool dashable = true;//能否冲刺。
	bool catchable = true;//爪子能否抓东西。例：剧情安排或正在撕扯时该项为false。
	bool throwable = true;//能否将爪子上的东西扔出。例：主角不能一心二用。如果当前正在使用翅膀发射风弹，则该项为false，该项为false时调用throw方法将不会触发敌人被扔下的动画，将触发敌人从爪下生还顺毛重新发动攻击的动画。
	bool spittable = false;//能否吐口水（
	bool vortexAttackable = true;

	//逻辑上讲，这两者不能同时为真。
	bool transformable_BirdToFish = true;
	bool transformable_FishToBird = true;//为方便测试，暂时将两者均设为真。


	bool invincible = false;//是否无敌。为了让玩家有清场能力，将新的生命设置三秒无敌；为了让玩家爽到，将投boss时的主角设置为无敌。



	bool directionToMoveRight = false;
	bool directionToMoveLeft = false;
	bool directionToMoveUp = false;
	bool directionToMoveDown = false;
	bool directionToMoveUpRight = false;
	bool directionToMoveUpLeft = false;
	bool directionToMoveDownRight = false;
	bool directionToMoveDownLeft = false;

	bool directionToHoldSomething = false;

	int lastDirection = 0;//0↑，1↗，2→，3↘，4↓，5↙，6←，7↖

	bool DirectionToPawhold = false;

	static HeroSprite * create(const std::string & filename);


	//关于技能，对外暴露这六个接口即可，别的通通设private就行
	void button1Hit();
	void button2Hit();
	void button3Hit();

	void button1Release();
	void button2Release();
	void button3Release();
	




	void disableAllAbilities();
	void enableAllAbilities();


	void hover();
	void hover_kun();

	void transformFromBirdToFish();
	void transformFromFishToBird();


	void move_forBothShapes();
	void move();
	void move_kun();

	void moveWithoutAnimationBrake();

	void moveBrake();
	void moveBrake_kun();

	void moveRight();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveUpRight();
	void moveUpLeft();
	void moveDownRight();
	void moveDownLeft();

	void moveRight_kun();
	void moveUp_kun();
	void moveDown_kun();
	void moveLeft_kun();
	void moveUpRight_kun();
	void moveUpLeft_kun();
	void moveDownRight_kun();
	void moveDownLeft_kun();

	void moveRightWithoutAnimation();
	void moveUpWithoutAnimation();
	void moveDownWithoutAnimation();
	void moveLeftWithoutAnimation();
	void moveUpRightWithoutAnimation();
	void moveUpLeftWithoutAnimation();
	void moveDownRightWithoutAnimation();
	void moveDownLeftWithoutAnimation();


	void moveRightBrake();
	void moveUpBrake();
	void moveDownBrake();
	void moveLeftBrake();
	void moveUpRightBrake();
	void moveUpLeftBrake();
	void moveDownRightBrake();
	void moveDownLeftBrake();

	


	void dash_forBothShapes();

	void dash();
	void dashRight();
	void dashUp();
	void dashDown();
	void dashLeft();
	void dashUpRight();
	void dashUpLeft();
	void dashDownRight();
	void dashDownLeft();

	void dash_kun();
	void dashRight_kun();
	void dashUp_kun();
	void dashDown_kun();
	void dashLeft_kun();
	void dashUpRight_kun();
	void dashUpLeft_kun();
	void dashDownRight_kun();
	void dashDownLeft_kun();


	void scratch();
	void scratchRight();
	void scratchRight2();
	void scratchLeft();
	void scratchLeft2();

	void finAttack();
	void finAttackRight();
	void finAttackRight2();
	void finAttackLeft();
	void finAttackLeft2();



	void windAttack();//多个重载
	void pawAttack();
	void pawHold();//！！**这是一个延时动作**！！
	void pawThrowObject();
	void pawThrowEnemy();
	void pawThrowBoss();//多个重载

	void vortexAttack();

	void fallFromSky_kun();
	void enterWater_kun();


	void getHurt();//多个重载
	void getHurtGeneral();
	void getHurtByThunder();//被雷电击中，骨架闪烁+原地震颤
	void getHurtByFire();//被火球击中，羽毛烧焦闪烁+后退
	void getHurtByWater();//被水流击中，变落汤鸡+下落
	void getHurtByHammer();//被锤，被吹飞，扑闪翅膀挣扎一番恢复稳定
	void getHurtByHammer(double direction);//吹飞方向为direction。0代表往上吹飞，90代表往右吹飞，180代表往下吹飞，270代表往左吹飞。
	void getHurtByWind();//被吹风击中，羽毛变凌乱

	HeroSprite();
	~HeroSprite();
};

