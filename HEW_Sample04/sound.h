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
	SOUND_LABEL_SE_SWIM,		// 水泳音
	SOUND_LABEL_SE_KETTEI,		// 決定音
	SOUND_LABEL_SE_ATARI,		// ボタン成功音
	SOUND_LABEL_SE_COUNT,		// カウントダウン
	SOUND_LABEL_SE_START,		// スタート
	SOUND_LABEL_SE_TIMEOUT,		// ゴール
	SOUND_LABEL_SE_AWA,			// 泡　
	SOUND_LABEL_SE_HAKUSHU,		// 拍手
	SOUND_LABEL_SE_KASORU,		// カーソル移動音
	SOUND_LABEL_SE_MIZUBASYA,
	SOUND_LABEL_SE_BASSYA,
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
