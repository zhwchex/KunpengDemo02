// ==================================================
//
// Author: GIFTED-BOY
// Email: 120138380@qq.com
// Create Time: 2018.07.22
// Version: v1.0
//
// ==================================================

#include "AudioManager.h"

static AudioManager *am = NULL;

AudioManager * AudioManager::getInstance()
{
	if (NULL == am)
	{
		am = new (nothrow) AudioManager();
		am->init();
	}
	return am;
}

bool AudioManager::init()
{
	sae = SimpleAudioEngine::getInstance();

	sae->preloadEffect(BGM_FILE_NAME.c_str());

	return true;
}

void AudioManager::play(const string &audioFileName, bool isLoop) { idMap[audioFileName] = sae->playEffect(audioFileName.c_str(), isLoop); }

void AudioManager::pause(const string &audioFileName) { sae->pauseEffect(idMap[audioFileName]); }

void AudioManager::resume(const string &audioFileName) { sae->resumeEffect(idMap[audioFileName]); }

void AudioManager::stop(const string &audioFileName) { sae->stopEffect(idMap[audioFileName]); }

void AudioManager::release()
{
	sae->unloadEffect(BGM_FILE_NAME.c_str());
}