#include <stdio.h>
#include <stdbool.h>
#include "stdlib.h"
#include <string.h>
#include "rbuf.h"

typedef struct {
	int		bEnable;		// 音频开/关
	int		nInpVolume;		// 输入音量(1最小 - 10最大)
}MRCONFC_AUDIO_CFG;


typedef struct {

	MRCONFC_AUDIO_CFG stAudio;

}SYSENV_CFG;

MRCONFC_AUDIO_CFG asda = { 1,10 };
typedef struct {
	MRCONFC_AUDIO_CFG* (*GetAudio)(void);
	MRCONFC_AUDIO_CFG* (*SetAudio)(void);
}mdu_syseenv;

static SYSENV_CFG s_stSysEnvCfg ;



static MRCONFC_AUDIO_CFG* GetAudio(void)
{ 
	printf("5555");
	return &s_stSysEnvCfg.stAudio;
}

MRCONFC_AUDIO_CFG* SetAudio(void)
{
	s_stSysEnvCfg.stAudio.bEnable=1;
	s_stSysEnvCfg.stAudio.nInpVolume = 10;
	return &s_stSysEnvCfg.stAudio;
}

mdu_syseenv mdu_sysenv_arg={
	GetAudio,
	SetAudio,
};

#define ENVCFG_AUDIOENC()	mdu_sysenv_arg.GetAudio()

int main(void)
{
	mdu_sysenv_arg.SetAudio();
	int test;
	test = ENVCFG_AUDIOENC()->bEnable;

	return 0;
}




















