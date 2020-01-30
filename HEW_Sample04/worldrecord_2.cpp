#include "input.h"
#include "scene.h"
#include "sprite.h"
//#include "texture.h"
#include "fade.h"
#include "main.h"
//#include "game.h"
//#include "score_draw.h"
//#include "number.h"
#include "timer.h"
//#include "Kajiki.h"
//#include "Iruka.h"
//#include "Kujira.h"
//#include "Uma.h"
#include "worldrecord.h"
#include "worldrecord_2.h"

typedef struct {
	int Min;
	int Sec;
}RECORD;

static RECORD	g_Wrecod[5];			//プレイヤーレコード（七人分）
static int		tempMin, tempSec;		//タイム一時格納変数

void WorldRecord_2_Initialize(void)
{
	Fade_Start(false, 90, D3DCOLOR_RGBA(0, 0, 0, 0));

	for (int i = 0; i < 5; i++)
	{
		g_Wrecod[i].Min = Get_WorldMin(i);
		g_Wrecod[i].Sec = Get_WorldSec(i);
	}

}

void WorldRecord_2_Finalize(void)
{
}

void WorldRecord_2_Update(void)
{
	if (Keyboard_IsTrigger(DIK_SPACE) || GamePad_IsTrigger(0, BUTTON_A)) {
		Scene_Change(SCENE_INDEX_TITLE);
	}

	//1位タイム表示
	Minute_Draw(800, 300, g_Wrecod[0].Min, 2, true, 1.5f, 1.5f);	//1位分数
	Second_Draw(960, 300, g_Wrecod[0].Sec, 2, true, 1.5f, 1.5f);	//1位秒数

}

void WorldRecord_2_Draw()
{
	Sprite_Draw(TEXTURE_INDEX_WORLDRECORD, 0.0f, 0.0f);
	Sprite_Draw(TEXTURE_INDEX_1ST, 450.0f, 150.0f);
	Sprite_Draw(TEXTURE_INDEX_2ND, 250.0f, 350.0f);
	Sprite_Draw(TEXTURE_INDEX_3RD, 1050.0f, 350.0f);
	Sprite_Draw(TEXTURE_INDEX_4TH, 250.0f, 550.0f);
	Sprite_Draw(TEXTURE_INDEX_5TH, 1050.0f, 550.0f);

	int x = 0;

	//for (int i = 0; i < 4; i++)
	//{
	//	for (int j = 1+x; j < 4; j++)
	//	{
	//		if (Player[i].Second > Player[j].Second)
	//		{
	//			if (Player[i].Minute >= Player[j].Minute)
	//			{
	//				tmpS = Player[i].Second;
	//				Player[i].Second = Player[j].Second;
	//				Player[j].Second = tmpS;

	//				tmpM = Player[i].Minute;
	//				Player[i].Minute = Player[j].Minute;
	//				Player[j].Minute = tmpM;
	//			}
	//		}
	//	}
	//	x++;
	
}
