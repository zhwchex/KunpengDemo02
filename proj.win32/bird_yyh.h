#ifndef __Bird_yyh_H__
#define __Bird_yyh_H__
#include "GeneralUnit.h"
class Bird_yyh :
	public GeneralUnit
{
public:
	Animation * hoveringAnimation;

    
	Bird_yyh();
	~Bird_yyh();
	int flag = 0;
	static Bird_yyh * create(const std::string & filename);
	void update(float dt);
	void wanderAbout();
	void lockBirdWithinLandscape();
	void getHurt();
};
#endif
