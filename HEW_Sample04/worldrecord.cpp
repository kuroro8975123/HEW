#include "input.h"
#include "scene.h"
#include "sprite.h"
//#include "texture.h"
#include "fade.h"
#include "main.h"
#include "game.h"
#include "score_draw.h"
#include "number.h"
#include "timer.h"
#include "Kajiki.h"
#include "Iruka.h"
#include "Kujira.h"
#include "Uma.h"
#include "worldrecord.h"

//
//int tmpS;
//int tmpM;
//
//typedef struct
//{
//	int Second;
//	int Minute;
//	int Rank;
//}RANKING;
//
//typedef struct
//{
//	int Second;
//	int Minute;
//	int Rank;
//}PLAYER;
//
//RANKING Ranking[6];
//PLAYER  Player[1];

void WorldRecord_Initialize(void)
{
	Fade_Start(false, 90, D3DCOLOR_RGBA(0, 0, 0, 0));

	//Player[0].Minute = Minute_1P_Kajiki();
	//Player[1].Minute = Minute_2P_Kajiki();

	//Player[0].Second = Second_1P_Kajiki();
	//Player[1].Second = Second_2P_Kajiki();

}

void WorldRecord_Finalize(void)
{
}

void WorldRecord_Update(void)
{
	if (Keyboard_IsTrigger(DIK_SPACE) || GamePad_IsTrigger(0, BUTTON_A)) {
		Scene_Change(SCENE_INDEX_TITLE);
	}


}

void WorldRecord_Draw()
{
	Sprite_Draw(TEXTURE_INDEX_WORLDRECORD, 0.0f, 0.0f);
	Sprite_Draw(TEXTURE_INDEX_1ST, 450.0f, 150.0f);
	Sprite_Draw(TEXTURE_INDEX_2ND, 250.0f, 350.0f);
	Sprite_Draw(TEXTURE_INDEX_3RD, 1050.0f,350.0f);
	Sprite_Draw(TEXTURE_INDEX_4TH, 250.0f, 550.0f);
	Sprite_Draw(TEXTURE_INDEX_5TH, 1050.0f,550.0f);
	Sprite_Draw(TEXTURE_INDEX_1P, 250.0f,750.0f);
	Sprite_Draw(TEXTURE_INDEX_2P, 1050.0f,750.0f);

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
	//}
	////1à ï`âÊ
	//Minute_Draw(440, 120, Player[0].Minute, 2, true);	//1à ï™êî
	//Second_Draw(520, 120, Player[0].Second, 2, true);	//1à ïbêî

	//if (Player[0].Second == Second_1P_Iruka())
	//{
	//	Sprite_Draw(TEXTURE_INDEX_KAZIKI, SCREEN_WIDTH / 2 - 70.0f , 150.0f);
	//}
	//if (Player[0].Second == Second_1P_Iruka())
	//{
	//	Sprite_Draw(TEXTURE_INDEX_IRUKA, SCREEN_WIDTH / 2 - 70.0f, 150.0f);
	//}
	////2à ï`âÊ
	//Minute_Draw(100, 200, Player[1].Minute, 2, true);	//2à ï™êî
	//Second_Draw(180, 200, Player[1].Second, 2, true);	//2à ïbêî

	//if (Player[1].Second == Second_1P_Iruka())
	//{
	//	Sprite_Draw(TEXTURE_INDEX_KAZIKI, 150.0f, 250.0f);
	//}
	//if (Player[1].Second == Second_1P_Iruka())
	//{
	//	Sprite_Draw(TEXTURE_INDEX_IRUKA, 150.0f, 250.0f);
	//}
}
