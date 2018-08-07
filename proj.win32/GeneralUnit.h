#pragma once
#include "cocos2d.h"
USING_NS_CC;
class GeneralUnit :public Sprite
{
public:

	//血量
	int health;

	//Boss专用。小怪不必理会这个旗子
	bool isBoss = false;
	//Boss专用，如果strong扣到非正值就进入虚弱状态，进入虚弱状态后一段时间离开虚弱状态，离开虚弱状态时strong值回满。小怪不用管这个值
	int strong = 0;
	//Boss专用。小怪始终是weak的，Boss绝大部分时间不是weak的
	bool isWeak = true;

	Vec2 guardPoint = Vec2().ZERO;

	//阵营。同一个阵营的单位攻击不到彼此，不同阵营的单位彼此为敌。暂定主角阵营是1，小怪阵营是2。
	int camp;


	//这4个接口是需要暴露出来的
	virtual void wanderAbout() {}//AI由你们写。我每帧都调用这个方法
	
	virtual void getHurt(int damage) {}
	virtual void getHurtByWind(int damage){}
	virtual void getHurtByPaw(int damage){}
	virtual void getHurtByCrush(int damage){}

	virtual void getHurtByWater(int damage){}
	virtual void getHurtByFin(int damage){}
		
	virtual void getHeld(){}						//被鹏抓住提在爪子上，像兔子被老鹰抓住一样，呆滞，循环播放
	virtual void getThrown(){}						//被鹏往地上扔的动画，位于半空中，震惊和失控，循环播放
	virtual void getSlamDunkOnGround(int damage){}	//砸在地面的动画，最好有个小弹跳的动作，瘫痪几秒爬起来进入正常行动状态。播放一次，播放完进入正常活动状态或直接死掉，调一下die或dieOnSlamDunk
	virtual void getSlamDunkOnWater(int damage){}	//砸在水面的动画，最好有个小弹跳的动作，瘫痪几秒爬起来进入正常行动状态，记得在落水的地方添加一个水花。播放一次，播放完进入正常活动状态或直接死掉，调一下die或dieOnSlamDunk
	virtual void getCollided(int damage){}			//被鲲冲撞到的动画，需要有一个小位移，鲲如果在左边就往右边位移一下，鲲如果在右边就往左边位移一下（更高级的做法是沿着远离鲲的方向位移一下）。播放一次，播放完进入正常活动状态或直接死掉，调一下die或dieOnCollision


	virtual void die() {}							//普通死法
	virtual void dieOnSlamDunk() {}					//精良死法，可做可不做，如果做了请做成软趴趴死在地上的样子。如果被投技直接砸死，调用它会更流畅一点，这是增加流畅性的小trick
	virtual void dieOnCollision(){}					//史诗死法，可做可不做，如果做了请做成被撞死的样子。如果被冲撞直接撞死，调用它会更流畅一点，这是增加流畅性的小trick

	static GeneralUnit * create(const std::string & filename);

	GeneralUnit();
	~GeneralUnit();
};

