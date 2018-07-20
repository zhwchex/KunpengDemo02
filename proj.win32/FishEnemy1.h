#ifndef _FISH_ENEMY1_H_
#define _FISH_ENEMY1_H_

#include "GeneralUnit.h"

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