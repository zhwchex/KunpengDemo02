#pragma once
#include <stdlib.h> 
#include <time.h> 
#include "GeneralUnit.h"

//author：李佳杰
//小怪：鱼

#define FISHHEALTHY1 200
#define ALARMDISTANCE1 2000

class EnemyFish : public GeneralUnit
{
public:
	float TIME_FOR_ANIMATION_FRAME_INTERVAL = 0.2f;
	float speed_flying_pixel_per_second = 150;
	
	bool acceptCall = true;
	//小怪状态
	bool facingRight = true;
	bool facingLeft = false;
	bool moving = false;

	//悬停动画
	Animation * hoveringRightAnimation;
	Animation * hoveringLeftAnimation;

	//普通移动的动画
	Animation * movingUpAnimation;
	Animation * movingUpRightAnimation;
	Animation * movingRightAnimation;
	Animation * movingDownRightAnimation;
	Animation * movingDownAnimation;
	Animation * movingDownLeftAnimation;
	Animation * movingLeftAnimation;
	Animation * movingUpLeftAnimation;

	//攻击动画
	Animation * attackAnimation;

	//受伤动画
	Animation *getHurtAnimation;

	//死亡动画
	Animation *dieAnimation;

	EnemyFish();
	~EnemyFish();

	static EnemyFish * create(const std::string & filename);

	void wanderAbout();
	void getHurt();
	void getHurt(int damage);
	void die();
};

