#include "Stage1UILayer.h"


Stage1UILayer::Stage1UILayer()
{
	this->heroHPBar = Sprite::create("ui/hp_bar_hero.png");
	this->heroHPBarShell = Sprite::create("ui/hp_bar_shell_hero.png");
	this->bossHPBar = Sprite::create("ui/hp_bar_boss.png");
	this->bossHPBarShell = Sprite::create("ui/hp_bar_shell_boss.png");
	this->bossName = Sprite::create("ui/bossName_zhurong.png");

	this->head_kun = Sprite::create("ui/head_kun.png");
	this->head_peng = Sprite::create("ui/head_peng.png");

	this->blackCurtain = Sprite::create("ui/black_curtain.png");
	this->missionComplete = Sprite::create("ui/mission_complete.png");
	this->invincibleHint = Sprite::create("ui/invincible_hint.png");
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

void Stage1UILayer::onEnter(){
	Size visibleSize = Director::getInstance()->getVisibleSize();

	this->head_kun->setPosition(-visibleSize.width / 2 + 50, visibleSize.height * 40 / 100);
	this->head_peng->setPosition(-visibleSize.width / 2 + 50, visibleSize.height * 40 / 100);


	this->heroHPBarShell->setPosition(-visibleSize.width / 2 + heroHPBar->getContentSize().width / 2 + 110, visibleSize.height * 40 / 100);
	this->heroHPBar->setAnchorPoint(Vec2(0,0.5));
	this->heroHPBar->setPosition(-visibleSize.width / 2  + 110 , visibleSize.height * 40 / 100);

	this->bossHPBarShell->setPosition(0, -visibleSize.height *40 / 100);
	this->bossHPBarShell->setOpacity(0);
	this->bossHPBar->setAnchorPoint(Vec2(0, 0.5));
	this->bossHPBar->setPosition(0 - bossHPBar->getContentSize().width / 2, -visibleSize.height * 40 / 100);
	this->bossHPBar->setOpacity(0);

	this->bossName->setAnchorPoint(Vec2(0, 0.5));
	this->bossName->setPosition(0 - bossHPBar->getContentSize().width / 2, -visibleSize.height * 34 / 100);
	this->bossName->setOpacity(0);

	this->invincibleHint->setOpacity(0);
	this->invincibleHint->setPosition(-visibleSize.width / 2 + heroHPBar->getContentSize().width / 2 + 110, visibleSize.height * 30 / 100);

	this->blackCurtain->setOpacity(255);
	this->missionComplete->setOpacity(0);
	


	this->addChild(head_kun);
	this->addChild(head_peng);
	this->addChild(this->heroHPBar);
	this->addChild(this->heroHPBarShell);
	this->addChild(this->bossHPBar);
	this->addChild(this->bossHPBarShell);
	this->addChild(this->bossName);
	this->addChild(this->invincibleHint);
	this->addChild(this->missionComplete);
	this->addChild(this->blackCurtain);


	this->blackCurtain->runAction(FadeOut::create(1));

	AudioManager::getInstance()->stop("audios/bgm.mp3");
	AudioManager::getInstance()->play("audios/ccb_cut.mp3", true);
	AudioManager::getInstance()->release();

	Layer::onEnter();
}