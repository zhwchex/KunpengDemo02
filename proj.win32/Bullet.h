
#include "cocos2d.h"
#include "Bird_yyh.h"
USING_NS_CC;
const float BULLETVElOCITY =200;//运行速度，可以自己控制，每秒所走的像素
class Bullet :  public cocos2d::Sprite
{
public:
	Bullet(Bird_yyh* b);
	~Bullet();
	virtual bool init();

	//根据英雄飞机创建子弹
	static Bullet* create(Bird_yyh* b);

	//移除超出屏幕可视范围的子弹或者碰撞后的子弹清除
	void removeBullet(Node* bu);

	//发射子弹，在其中进行子弹的渲染和子弹的飞行动作，默认为单子弹
	void ShootBullet(float dt);
	//void ShootBullet();
	//返回子弹列表
	Vector <Sprite *>& GetBullet();
public:
	Vector <Sprite *>vecBullet;//子弹容器
	SpriteBatchNode* bulletBatchNode;//批次渲染节点
	Bird_yyh* b;//传入的英雄飞机
};