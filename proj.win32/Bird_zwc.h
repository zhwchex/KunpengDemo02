#ifndef __Bird_zwc_H__
#define __Bird_zwc_H__
#include "GeneralUnit.h"
class Bird_zwc :
	public GeneralUnit
{
public:
	Animation * hoveringAnimation;
	Animation * leftAnimation;
	Animation * rightAnimation;
	Animation * leftturnAnimation; //×ó×ªÓÒ
	Animation * rightturnAnimation;//ÓÒ×ª×ó
	Animation * lefthurtAnimation;
	Animation * righthurtAnimation;
	Animation * leftdieAnimation;
	Animation * rightdieAnimation;
	Animation * leftfightAnimation;
	Animation * rightfightAnimation;

    
	Bird_zwc();
	~Bird_zwc();
	int health = 100;
	int flag = 0;
	int dir = 0;
	int lock = 0;

	int dieflag = 0;
	int pauseflag = 0;

	int x_scope, y_scope;
	float x_change, y_change;
	int bird_step = 8;
	static Bird_zwc * create(const std::string & filename);
	void update(float dt);
	void wanderAbout();
	void lockBirdWithinLandscape();
	//void getHurt();
	//Ëø
	void Lockright();
	void Lockleft();
	void Lockturnright(int type);
	void Lockturnleft(int type);
	void Lockhurt(Animation* ani);
	void f();
	void getHurtByWind(int damage);
	void getHurtByPaw(int damage);
	void getHurtByCrush(int damage);

	void getHurtByWater(int damage);
	void getHurtByFin(int damage);
	

};
#endif
