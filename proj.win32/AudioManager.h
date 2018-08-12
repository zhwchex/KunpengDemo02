// ==================================================
//
// Author: GIFTED-BOY
// Email: 120138380@qq.com
// Create Time: 2018.07.22
// Version: v1.0
//
// ==================================================

#ifndef _AUDIO_MANAGER_H_
#define _AUDIO_MANAGER_H_

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;
using namespace std;

static const string BGM_FILE_NAME = "audios/bgm.mp3";

static const string boss_sea = "audios/bosssea.mp3";
static const string boss_fire = "audios/bossfire.mp3";
static const string boss_rain = "audios/bossattack_1.mp3";
static const string boss_close = "audios/bossattack_2.mp3";
static const string boss_hurt = "audios/bosshurt.mp3";
static const string boss_die = "audios/bossdie.mp3";

static const string CRAB_ATTACK_FILE_NAME = "audios/crab_attack.mp3";
static const string MONSTER_HURT_FILE_NAME = "audios/monster_hurt.mp3";


class AudioManager
{
public:
	static AudioManager * getInstance();
	bool init();

	void play(const string &audioFileName, bool isLoop);
	void pause(const string &audioFileName);
	void resume(const string &audioFileName);
	void stop(const string &audioFileName);


	void release();

private:
	SimpleAudioEngine *sae;
	unordered_map<string, unsigned int> idMap;
};

#endif