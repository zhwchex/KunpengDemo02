#pragma once
#include "GeneralUnit.h"
//#include <math.h>


class Zhurong :public GeneralUnit
{
public:

	int health = 10000;

	int awake = 5000;

	int camp = 2;

	int alertRange = 800;

	float ANIMATION_FRAME_INTERVAL = 0.1f;


	bool acceptCall = true;///
	bool facingRight = false;

	//动画。只是动画，没有位移
	Animation * walkingLeftWhileFacingLeftAnimation;//面向左边前进
	Animation * walkingRightWhileFacingLeftAnimation;//面向左边后退

	Animation * walkingRightWhileFacingRightAnimation;//面向右边前进
	Animation * walkingLeftWhileFacingRightAnimation;//面向右边后退

	//技能动画
	Animation * shootingFireBallWhileFacingLeftAnimation;


	//技能效果和技能道具动画
	Animation * fireballSpinningAnimation;//火球旋转动画。注意只是旋转动画，飞行位移放在函数里。在火球旋转的每一Animation帧判断它是否与主角相撞
	Animation * fireballExplosionAnimation;//火焰爆炸动画

	//挨打动画

	//死亡动画



	//动作，既包含动画又包含位移。
	void walkLeftWhileFacingLeft();
	void prepareAndLaunchAFireballWhileFacingLeft();




	void wanderAbout();

	void getHurt(int damage);
	void getHurtByWind(int damage);
	void getHurtByPaw(int damage);
	void getHurtByCrush(int damage);

	void getHurtByWater(int damage);
	void getHurtByFin(int damage);

	void die();

	void idle();//呆站着，什么也不做

	static Zhurong * create(const std::string & filename);



	Zhurong();
	~Zhurong();
};

