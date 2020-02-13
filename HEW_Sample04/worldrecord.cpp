/*================================================
			     worldrecord.cpp
--------------------------------------------------
	過去を含むTOP5のタイムをソートし、
	順位付けして、出力する。
	また、各順位のタイムを返す。

	ソート方法はバブルソート
================================================*/

#include "input.h"
#include "scene.h"
#include "sprite.h"
#include "fade.h"
#include "main.h"
#include "timer.h"
#include "worldrecord.h"
#include "result.h"

#define RECORD_SIZE		7

typedef struct {
	int Min;
	int Sec;
}RECORD;
typedef struct {
	int Min;
	int Sec;
}PLAYER;

RECORD g_Wrecord[RECORD_SIZE];				//　プレイヤーレコード（七人分）
PLAYER g_Player[2];							//　プレイヤーレコード（仮置き）

static bool FirstTime = true;				//二回目以降のInitializeでランキングを初期化して上書きしないように飛ばすためのフラグ


void Swap(int *x, int *y);					//Swap関数プロトタイプ宣言(ここでしか使わない予定なので.hには書かない)

void WorldRecord_Initialize(void)
{
	Fade_Start(false, 90, D3DCOLOR_RGBA(0, 0, 0, 0));

	//すべてのMin,Secをともに99で初期化
	if (FirstTime) {	
		for (int i = 0; i < RECORD_SIZE - 1; i++)
		{
			g_Wrecord[i].Min = 99;
			g_Wrecord[i].Sec = 99;
		}
	}
	/*
	予備処理
	---内容---
	HEW当日にゲームを終了してしまい、
	ランキングのデータが消えてしまった時
	ここで直接記述する。
	if(FIrstTime){
		//1位
		g_Wrecord[0].Min = ;
		g_Wrecord[0].Sec = ;

		//2位
		g_Wrecord[1].Min = ;
		g_Wrecord[1].Sec = ;

		//3位
		g_Wrecord[2].Min = ;
		g_Wrecord[2].Sec = ;

		//4位
		g_Wrecord[3].Min = ;
		g_Wrecord[3].Sec = ;

		//5位
		g_Wrecord[4].Min = ;
		g_Wrecord[4].Sec = ;
	}
	*/

	for (int i = 0; i < 2; i++)
	{
		//プレイヤーごとのタイムをg_Wrecordの[6][7]番目に格納
		g_Wrecord[i + 5].Min = Get_Player_Min(i);
		g_Wrecord[i + 5].Sec = Get_Player_Sec(i);

		//タイムに"Min"があった場合は"Min * 60"の値を"Sec"に加算
		if (g_Wrecord[i + 5].Min != 0 && g_Wrecord[i + 5].Min != 99) {
			g_Wrecord[i + 5].Sec += 60 * g_Wrecord[i + 5].Min;
			g_Wrecord[i + 5].Min  = 0;
		}
		//プレイヤーごとのタイムをそれぞれの変数に格納
		//※g_Wrecordに入れたままだとソートする際に入れ替えられてしまうため、別変数に保管
		g_Player[i].Min = Get_Player_Min(i);
		g_Player[i].Sec = Get_Player_Sec(i);
	}

	//ここで"FirstTime"フラグを切っておくことで、2回目以降初期化されない
	FirstTime = false;

}

void WorldRecord_Finalize(void)
{

}

void WorldRecord_Update(void)
{
	if (Keyboard_IsTrigger(DIK_SPACE) || GamePad_IsTrigger(0, BUTTON_A)) {
		Scene_Change(SCENE_INDEX_TITLE);
	}

	//タイムソート処理
	for (int i = 0; i < RECORD_SIZE - 1; i++) {
		for (int j = 0; j < RECORD_SIZE - 1; j++) {
			if (g_Wrecord[j + 1].Sec < g_Wrecord[j].Sec) {				//秒数が一つ先より大きければ"真"
				if (g_Wrecord[j + 1].Min <= g_Wrecord[j].Min) {			//分数が一つ先より大きければ"真"
					Swap(&g_Wrecord[j + 1].Sec, &g_Wrecord[j].Sec);		//秒数入れ替え
					Swap(&g_Wrecord[j + 1].Min, &g_Wrecord[j].Min);		//分数入れ替え
				}
			}
		}
	}
}

void WorldRecord_Draw()
{
	Sprite_Draw(TEXTURE_INDEX_WORLDRECORD, 0.0f, 0.0f);
	Sprite_Draw(TEXTURE_INDEX_1ST, 450.0f, 150.0f);
	Sprite_Draw(TEXTURE_INDEX_2ND, 250.0f, 350.0f);
	Sprite_Draw(TEXTURE_INDEX_3RD, 1050.0f, 350.0f);
	Sprite_Draw(TEXTURE_INDEX_4TH, 250.0f, 550.0f);
	Sprite_Draw(TEXTURE_INDEX_5TH, 1050.0f, 550.0f);
	Sprite_Draw(TEXTURE_INDEX_1P, 250.0f, 750.0f);
	Sprite_Draw(TEXTURE_INDEX_2P, 1050.0f, 750.0f);

	//Sec -> Minに変換
	for (int i = 0; i < 5; i++)
	{
		if (g_Wrecord[i].Min == 99)
			continue;

		if (g_Wrecord[i].Sec / 60 >= 1) {
			g_Wrecord[i].Min = g_Wrecord[i].Sec / 60;
			g_Wrecord[i].Sec = g_Wrecord[i].Sec % 60;
		}
	}

	Minute_Draw( 750, 250, g_Wrecord[0].Min, 2, true, 1.5f, 1.5f);	//1位分数
	Second_Draw( 950, 250, g_Wrecord[0].Sec, 2, true, 1.5f, 1.5f);	//1位秒数

	Minute_Draw( 440, 425, g_Wrecord[1].Min, 2, true);				//2位分数
	Second_Draw( 600, 425, g_Wrecord[1].Sec, 2, true);				//2位秒数

	Minute_Draw(1240, 425, g_Wrecord[2].Min, 2, true);				//3位分数
	Second_Draw(1400, 425, g_Wrecord[2].Sec, 2, true);				//3位秒数

	Minute_Draw( 440, 625, g_Wrecord[3].Min, 2, true);				//4位分数
	Second_Draw( 600, 625, g_Wrecord[3].Sec, 2, true);				//4位秒数

	Minute_Draw(1240, 625, g_Wrecord[4].Min, 2, true);				//5位分数
	Second_Draw(1400, 625, g_Wrecord[4].Sec, 2, true);				//5位秒数

	Minute_Draw( 440, 815, g_Player[0].Min, 2, true);				//1P分数
	Second_Draw( 600, 815, g_Player[0].Sec, 2, true);				//1P秒数

	Minute_Draw(1240, 815, g_Player[1].Min, 2, true);				//2P分数
	Second_Draw(1400, 815, g_Player[1].Sec, 2, true);				//2P秒数

}

//g_Wrecordに格納されている"分数"を返す。(引数は構造体の番号)
int Get_WorldMin(int n)
{
	return g_Wrecord[n].Min;
}
//g_Wrecordに格納されている"秒数"を返す。(引数は構造体の番号)
int Get_WorldSec(int n)
{
	return g_Wrecord[n].Sec;
}
//Swap関数。引数に入れた数字を入れ替える。
void Swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}