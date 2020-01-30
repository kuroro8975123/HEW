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
	TEXTURE_INDEX_MAP,				//28.マップ
	TEXTURE_INDEX_BG,				//29.背景
	TEXTURE_INDEX_KAZIKI_ANIMATION, //カジキ
	TEXTURE_INDEX_UMA_ANIMATION,    //馬
	TEXTURE_INDEX_IRUKA_ANIMATION,  //イルカ
	TEXTURE_INDEX_KUZIRA_ANIMATION, //クジラ
	TEXTURE_INDEX_KAZIKI_SELECT, //カジキ
	TEXTURE_INDEX_KUJIRA_SELECT, //クジラ
	TEXTURE_INDEX_IRUKA_SELECT, //イルカ
	TEXTURE_INDEX_UMA_SELECT,   //馬
	TEXTURE_INDEX_LEFT,        //左
	TEXTURE_INDEX_RIGHT,       //右
	TEXTURE_INDEX_WINNER,      //勝利
	TEXTURE_INDEX_LOSER,       //敗北
	TEXTURE_INDEX_WORLDRECORD, //世界記録
	TEXTURE_INDEX_1P,          //1P
	TEXTURE_INDEX_2P,          //2P
	TEXTURE_INDEX_1ST,          //1st
	TEXTURE_INDEX_2ND,          //2nd
	TEXTURE_INDEX_3RD,          //3rd
	TEXTURE_INDEX_4TH,          //4th
	TEXTURE_INDEX_5TH,          //5th
<<<<<<< HEAD
	TEXTURE_INDEX_1P_MAP,          //1P
	TEXTURE_INDEX_2P_MAP,          //1P

=======
	TEXTURE_INDEX_START_GOAL,		//スタートとゴール
>>>>>>> 30c7be4363dd7eb0345bf129664dd2c93b975c90
	TEXTURE_INDEX_MAX
};


int Texture_Load(void); //初期化
void Texture_Release(void); //終了処理
LPDIRECT3DTEXTURE9 Texture_GetTexture(TextureIndex index);
int Texture_GetWidth(TextureIndex index);
int Texture_GetHeight(TextureIndex index);