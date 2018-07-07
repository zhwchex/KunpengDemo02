#ifndef __Bird_yyh_H__
#define __Bird_yyh_H__
#include "GeneralUnit.h"
class Bird_yyh :
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

    
	Bird_yyh();
	~Bird_yyh();
	int health = 100;
	int flag = 0;
	int dir = 0;
	int lock = 0;

	int dieflag = 0;
	int pauseflag = 0;

	int x_scope, y_scope;
	float x_change, y_change;
	int bird_step = 50;
	static Bird_yyh * create(const std::string & filename);
	void update(float dt);
	void wanderAbout();
	void lockBirdWithinLandscape();
	//void getHurt();
	//Ëø
	void Lockright();
	void Lockleft();
	void Lockturnright(int type);
	void Lockturnleft(int type);
	void Lockhoving();
	void f();
	void getHurtByWind(int damage);
	void getHurtByPaw(int damage);
	void getHurtByCrush(int damage);

	void getHurtByWater(int damage);
	void getHurtByFin(int damage);
	

};
#endif
