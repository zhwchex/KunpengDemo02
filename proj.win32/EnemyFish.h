#pragma once
#include <stdlib.h> 
#include <time.h> 
#include "GeneralUnit.h"

//author����ѽ�
//С�֣���

#define FISHHEALTHY1 100
#define ALARMDISTANCE1 300
#define ATTACK_PROB 8

class EnemyFish : public GeneralUnit
{
public:
	float TIME_FOR_ANIMATION_FRAME_INTERVAL = 0.2f;
	float speed_flying_pixel_per_second = 100;
	
	bool acceptCall = true;
	//С��״̬
	bool facingRight = true;
	bool facingLeft = false;
	bool moving = false;

	//��ͣ����
	Animation * hoveringRightAnimation;
	Animation * hoveringLeftAnimation;

	//��ͨ�ƶ��Ķ���
	Animation * movingUpAnimation;
	Animation * movingUpRightAnimation;
	Animation * movingRightAnimation;
	Animation * movingDownRightAnimation;
	Animation * movingDownAnimation;
	Animation * movingDownLeftAnimation;
	Animation * movingLeftAnimation;
	Animation * movingUpLeftAnimation;

	//��������
	Animation * attackAnimation;

	//���˶���
	Animation *getHurtAnimation;

	//��������
	Animation *dieAnimation;

	EnemyFish();
	~EnemyFish();

	static EnemyFish * create(const std::string & filename);

	void wanderAbout();
	void getHurt();
	void getHurt(int damage);
	void getHurtByWind(int damage);
	void die();
};

