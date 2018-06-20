#include "Stage1UILayer.h"


Stage1UILayer::Stage1UILayer()
{
}


Stage1UILayer::~Stage1UILayer()
{
}

Stage1UILayer* Stage1UILayer::create(){
	Stage1UILayer *ret = new (std::nothrow) Stage1UILayer();
	if (ret && ret->init())
	{
		ret->autorelease();
		return ret;
	}
	else
	{
		CC_SAFE_DELETE(ret);
		return nullptr;
	}
}