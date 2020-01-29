//=============================================================================
//
// サウンド処理 [sound.h]
//
//=============================================================================
#pragma once


#include <windows.h>
#include "xaudio2.h"						// サウンド処理で必要


//*****************************************************************************
// サウンドファイル
//*****************************************************************************
typedef enum
{
	SOUND_LABEL_BGM000,		    // BGM0
	SOUND_LABEL_BGM001,		    // BGM1
	SOUND_LABEL_BGM002,		    // BGM2
	SOUND_LABEL_SE_SHOT,		// 弾発射音
	SOUND_LABEL_SE_HIT,			// ヒット音
	SOUND_LABEL_SE_EXPLOSION,	// 爆発音
	SOUND_LABEL_SE_SWIM,
	SOUND_LABEL_SE_KETTEI,
	SOUND_LABEL_SE_ATARI,
	SOUND_LABEL_SE_COUNT,
	SOUND_LABEL_SE_START,
	SOUND_LABEL_SE_TIMEOUT,
	SOUND_LABEL_SE_AWA,
	SOUND_LABEL_SE_HAKUSHU,
	SOUND_LABEL_MAX,

} SOUND_LABEL;

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
bool InitSound(HWND hWnd);
void UninitSound(void);
void PlaySound(SOUND_LABEL label);
void StopSound(SOUND_LABEL label);
void StopSound(void);
