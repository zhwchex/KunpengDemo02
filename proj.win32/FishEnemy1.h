#ifndef _FISH_ENEMY1_H_
#define _FISH_ENEMY1_H_

#include "GeneralUnit.h"

const static int STATE_DEFAULT = 0;
const static int STATE_ROTATE = 1;
const static int STATE_ATTACK = 2;
const static int STATE_BE_ATTACKED = 3;
const static int STATE_DEAD = 4;
const static float FRAME_RATE = 0.2;
const static float ANIMATION_DURATION = 0.3;

class FishEnemy1 : GeneralUnit
{
public:
	FishEnemy1();
	~FishEnemy1();
	static GeneralUnit *create(const std::string & filename);
	void wanderAbout();
	void getHurt(int h);
	void die();
	void wander();
	void attack(Vec2 pos);


	int speed;
	int hurt;
	int pauseflagDist;
	int attackDist;
	float discoverProb; 
	float attackProb;
	float runProb;
	int state;

	Animation *defaultAnimation;
	Animation *attackAnimation;
	Animation *beAttackedAnimation;
	Animation *deadAnimation;
};

#endif