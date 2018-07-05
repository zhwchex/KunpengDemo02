#ifndef __Bird_zwc_H__
#define __Bird_zwc_H__
#include "GeneralUnit.h"
class Bird_zwc :
	public GeneralUnit
{
public:

	//散步动画
	Animation * wanderAboutAnimation;

	Bird_zwc();
	~Bird_zwc();
	static Bird_zwc * create(const std::string & filename);

	void wanderAbout();//AI由你们写。我每帧都调用这个方法
	void update(float dt);
	void lockBirdWithinLandscape();

	void getHurtByWind(int damage);//由我来调用
	void getHurtByPaw(int damage);
	void getHurtByCrush(int damage);

	void getHurtByWater(int damage);
	void getHurtByFin(int damage);

	void die();
};
#endif
