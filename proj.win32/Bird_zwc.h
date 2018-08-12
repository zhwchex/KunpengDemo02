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
	Animation * leftturnAnimation; //左转右
	Animation * rightturnAnimation;//右转左
	Animation * lefthurtAnimation;
	Animation * righthurtAnimation;
	Animation * leftdieAnimation;
	Animation * rightdieAnimation;
	Animation * leftfightAnimation;
	Animation * rightfightAnimation;

	float TIME_FOR_ANIMATION_FRAME_INTERVAL = 0.01f;
	float battledistance = 450;//战斗范围
	int change = 10;//徘徊范围

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

	//锁
	void Lockright();
	void Lockleft();
	void Lockturnright(int type);
	void Lockturnleft(int type);
	void Lockhurt(Animation* ani);
	void f();

	void getHurt(int damage);
	void getHurtByWind(int damage);
	void getHurtByPaw(int damage);
	void getHurtByCrush(int damage);
	void getHurtByWater(int damage);
	void getHurtByFin(int damage);

	void setPlace(int x, int y);

	//new

	void getHeld();						//被鹏抓住提在爪子上，像兔子被老鹰抓住一样，呆滞，循环播放
	void getThrown();					//被鹏往地上扔的动画，位于半空中，震惊和失控，循环播放
	void getSlamDunkOnGround(int damage);	//砸在地面的动画，最好有个小弹跳的动作，瘫痪几秒爬起来进入正常行动状态。播放一次，播放完进入正常活动状态或直接死掉，调一下die或dieOnSlamDunk
	void getSlamDunkOnWater(int damage);	//砸在水面的动画，最好有个小弹跳的动作，瘫痪几秒爬起来进入正常行动状态，记得在落水的地方添加一个水花。播放一次，播放完进入正常活动状态或直接死掉，调一下die或dieOnSlamDunk
	void getCollided(int damage);		//被鲲冲撞到的动画，需要有一个小位移，鲲如果在左边就往右边位移一下，鲲如果在右边就往左边位移一下（更高级的做法是沿着远离鲲的方向位移一下）。播放一次，播放完进入正常活动状态或直接死掉，调一下die或dieOnCollision

	void die(bool facingLeft);		//普通死法
	void dieOnSlamDunk();			//精良死法，可做可不做，如果做了请做成软趴趴死在地上的样子。如果被投技直接砸死，调用它会更流畅一点，这是增加流畅性的小trick
	void dieOnCollision();			//史诗死法，可做可不做，如果做了请做成被撞死的样子。如果被冲撞直接撞死，调用它会更流畅一点，这是增加流畅性的小trick

};
#endif
