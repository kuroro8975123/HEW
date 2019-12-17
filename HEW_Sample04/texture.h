#pragma once

#include <d3d9.h>

typedef enum
{
<<<<<<< HEAD
	TEXTURE_INDEX_TITLE,//01.タイトル画面
	TEXTURE_INDEX_TUTORIAL,//02.チュートリアル画面
	TEXTURE_INDEX_GAME,//03.ゲーム画面	
	TEXTURE_INDEX_RESULT,//04.リザルト画面
	TEXTURE_INDEX_PLAYER,//05.プレイヤー
	TEXTURE_INDEX_ENEMY,//06.敵？
	TEXTURE_INDEX_NUMBER,//07.数字
	TEXTURE_INDEX_3,//08.カウントダウン
	TEXTURE_INDEX_2,//09.カウントダウン
	TEXTURE_INDEX_1,//10.カウントダウン
	TEXTURE_INDEX_START,//11.カウントダウン
	TEXTURE_INDEX_BUTTON,//12.ボタン
	TEXTURE_INDEX_PRESS, //13.pressanykey
	TEXTURE_INDEX_CHARASELE,//14.キャラクター選択
	TEXTURE_INDEX_POOL,//15.プール
	TEXTURE_INDEX_CHARASEN,//キャラクターを選択してください
	TEXTURE_INDEX_BUTTON2,//12.ボタン2
	TEXTURE_INDEX_BLOCK,//ブロックサンプル
=======
	TEXTURE_INDEX_TITLE1,//01.タイトル文字
	TEXTURE_INDEX_TITLE2,//02.タイトル背景
	TEXTURE_INDEX_TUTORIAL,//03.チュートリアル画面
	TEXTURE_INDEX_GAME,//04.ゲーム画面	
	TEXTURE_INDEX_RESULT,//05.リザルト画面
	TEXTURE_INDEX_PLAYER,//06.プレイヤー
	TEXTURE_INDEX_ENEMY,//07.敵？
	TEXTURE_INDEX_NUMBER,//08.数字
	TEXTURE_INDEX_3,//09.カウントダウン
	TEXTURE_INDEX_2,//10.カウントダウン
	TEXTURE_INDEX_1,//11.カウントダウン
	TEXTURE_INDEX_START,//12.カウントダウン
	TEXTURE_INDEX_BUTTON,//13.ボタン
	TEXTURE_INDEX_PRESS, //14.pressanykey
	TEXTURE_INDEX_CHARASELE,//15.キャラクター選択
	TEXTURE_INDEX_POOL,//16.プール
	TEXTURE_INDEX_CHARASEN,//17.キャラクターを選択してください
	TEXTURE_INDEX_BUTTON2,//18.ボタン2
>>>>>>> e3308ad52851f4f28283949893dfad1a2a2ab960


	TEXTURE_INDEX_MAX
}TextureIndex;

int Texture_Load(void); //初期化
void Texture_Release(void); //終了処理
LPDIRECT3DTEXTURE9 Texture_GetTexture(TextureIndex index);
int Texture_GetWidth(TextureIndex index);
int Texture_GetHeight(TextureIndex index);
