#pragma once

#include <d3d9.h>

typedef enum TextureIndex
{
	TEXTURE_INDEX_TITLE1,			//01.タイトル画面
	TEXTURE_INDEX_TITLE2,			//02.タイトル画面
	TEXTURE_INDEX_TUTORIAL,		//03.チュートリアル画面
	TEXTURE_INDEX_GAME,				//04.ゲーム画面	
	TEXTURE_INDEX_RESULT,			//05.リザルト画面
	TEXTURE_INDEX_PLAYER,			//06.プレイヤー
	TEXTURE_INDEX_ENEMY,			//07.敵？
	TEXTURE_INDEX_NUMBER,		//08.数字
	TEXTURE_INDEX_3,					//09.カウントダウン
	TEXTURE_INDEX_2,					//10.カウントダウン
	TEXTURE_INDEX_1,					//11.カウントダウン
	TEXTURE_INDEX_START,			//12.カウントダウン
	TEXTURE_INDEX_BUTTON,			//13.ボタン
	TEXTURE_INDEX_PRESS,			//14.pressanykey
	TEXTURE_INDEX_CHARASELE,	//15.キャラクター選択
	TEXTURE_INDEX_POOL,				//16.プール
	TEXTURE_INDEX_CHARASEN,		//17.キャラクターを選択してください
	TEXTURE_INDEX_BUTTON2,		//18.ボタン2
	TEXTURE_INDEX_BLOCK,			//19.ブロックサンプル
	TEXTURE_INDEX_A_BUTTON,		//20.Aボタン
	TEXTURE_INDEX_B_BUTTON,		//21.Bボタン		
	TEXTURE_INDEX_X_BUTTON,		//22.Xボタン
	TEXTURE_INDEX_Y_BUTTON,		//23.Yボタン
	TEXTURE_INDEX_KAZIKI,			//24.カジキ
	TEXTURE_INDEX_KUZIRA,			//25.クジラ
	TEXTURE_INDEX_IRUKA,			//26.イルカ
	TEXTURE_INDEX_UMA,				//27.馬

	TEXTURE_INDEX_MAX
};


int Texture_Load(void); //初期化
void Texture_Release(void); //終了処理
LPDIRECT3DTEXTURE9 Texture_GetTexture(TextureIndex index);
int Texture_GetWidth(TextureIndex index);
int Texture_GetHeight(TextureIndex index);