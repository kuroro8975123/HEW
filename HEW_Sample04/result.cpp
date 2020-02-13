
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	順位決定仕様
	・各プレイヤー毎のタイム分け( game.cppにて )
	・順位決定( result.cppにて )

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "input.h"
#include "scene.h"
#include "sprite.h"
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
#include "scene_playerselect.h"
#include "sound.h"

static float y;

int tmpS;
int tmpM;

typedef struct
{
	int Second;
	int Minute;
	int Rank;
}RANKING;

typedef struct
{
	int Second;
	int Minute;
	int Rank;
	bool win;
}PLAYER;

RANKING Ranking[6];
PLAYER  Player[2];

static int Player_1P;

static int Player_2P;


void Result_Initialize(void)
{
	Fade_Start(false, 90, D3DCOLOR_RGBA(0, 0, 0, 0));

	//プレイヤーが何のキャラを選択したか
	Player_1P = Get_Select_1P();
	Player_2P = Get_Select_2P();

	//プレイヤーの勝利フラグをoff
	Player[0].win = false;
	Player[1].win = false;

	if (Player_1P == 1)
	{
		Player[0].Minute = Minute_1P_Kajiki();
		Player[0].Second = Second_1P_Kajiki();
	}
	if (Player_1P == 2)
	{
		Player[0].Minute = Minute_1P_Kujira();
		Player[0].Second = Second_1P_Kujira();
	}
	if (Player_1P == 3)
	{
		Player[0].Minute = Minute_1P_Iruka();
		Player[0].Second = Second_1P_Iruka();
	}
	if (Player_1P == 4)
	{
		Player[0].Minute = Minute_1P_Uma();
		Player[0].Second = Second_1P_Uma();
	}

	if (Player_2P == 1)
	{
		Player[1].Minute = Minute_2P_Kajiki();
		Player[1].Second = Second_2P_Kajiki();
	}
	if (Player_2P == 2)
	{
		Player[1].Minute = Minute_2P_Kujira();
		Player[1].Second = Second_2P_Kujira();
	}
	if (Player_2P == 3)
	{
		Player[1].Minute = Minute_2P_Iruka();
		Player[1].Second = Second_2P_Iruka();
	}
	if (Player_2P == 4)
	{
		Player[1].Minute = Minute_2P_Uma();
		Player[1].Second = Second_2P_Uma();
	}


}

void Result_Finalize(void)
{
}

void Result_Update(void)
{
<<<<<<< HEAD

		if (Keyboard_IsTrigger(DIK_SPACE) || GamePad_IsTrigger(0, BUTTON_A)) {
			Scene_Change(SCENE_INDEX_WORLDRECORD);
			PlaySound(SOUND_LABEL_SE_AWA);
			//Scene_Change(SCENE_INDEX_TITLE);
		}
=======
>>>>>>> c5227bc3d10325d40158aa2f99a8d01be121f8a7
	if (Keyboard_IsTrigger(DIK_SPACE) || GamePad_IsTrigger(0, BUTTON_A)) {
		Scene_Change(SCENE_INDEX_WORLDRECORD);
		PlaySound(SOUND_LABEL_SE_AWA);
	}
<<<<<<< HEAD
=======
	//勝者決定処理
	if (Player[0].Second < Player[1].Second) {
		if (Player[0].Minute <= Player[1].Minute) {
			Player[0].win = true;
		}
	}
	/*else if (Player[1].Second < Player[0].Second) {
		if (Player[1].Minute <= Player[0].Minute) {
			Player[1].win = true;
		}
	}*/
>>>>>>> c5227bc3d10325d40158aa2f99a8d01be121f8a7
}

void Result_Draw()
{
	Sprite_Draw(TEXTURE_INDEX_RESULT, 0.0f, 0.0f);
	Sprite_Draw(TEXTURE_INDEX_WINNER, 250.0f, 350.0f);
	Sprite_Draw(TEXTURE_INDEX_LOSER, 400.0f, 720.0f);


	if (Player[0].win) {
		//1Pが1位
		Minute_Draw( 940, 500, Player[0].Minute, 2, true, 1.5, 1.5);	//1位分数
		Second_Draw(1100, 500, Player[0].Second, 2, true, 1.5, 1.5);	//1位秒数

		Sprite_Draw(TEXTURE_INDEX_1P, 650, 450, 0, 0, 175, 175, 16, 16, 1.5f, 1.5f, 0);

		//1Pがカジキ選択
		if (Get_Select_1P() == 1)
			Sprite_Draw(TEXTURE_INDEX_KAZIKI_ANIMATION, 1400.0f, 350.0f, 1, 0, 100, 300, 0, 0, 1.5f, 1.0f, 0);			
		//1Pがくじら選択
		if (Get_Select_1P() == 2)
			Sprite_Draw(TEXTURE_INDEX_KUZIRA_ANIMATION, 1400.0f, 350.0f, 1, 0, 100, 300, 0, 0, 1.5f, 1.0f, 0);
		//1Pがイルカ選択
		if (Get_Select_1P() == 3)
			Sprite_Draw(TEXTURE_INDEX_IRUKA_ANIMATION, 1400.0f, 350.0f, 1, 0, 100, 300, 0, 0, 1.5f, 1.0f, 0);
		//1Pがうま選択
		if (Get_Select_1P() == 4)
			Sprite_Draw(TEXTURE_INDEX_UMA_ANIMATION, 1400.0f, 350.0f, 1, 0, 100, 300, 0, 0, 1.5f, 1.0f, 0);


			//2Pが2位
		Minute_Draw( 954, 800, Player[1].Minute, 2, true);	//2位分数
		Second_Draw(1114, 800, Player[1].Second, 2, true);	//2位秒数

		Sprite_Draw(TEXTURE_INDEX_2P, 750, 750);

		//2Pがカジキ選択
		if (Get_Select_2P() == 1)
			Sprite_Draw(TEXTURE_INDEX_KAZIKI_ANIMATION, 1420.0f, 700.0f, 1, 0, 100, 300, 0, 0, 1.5f*0.75f, 1.0f*0.75f, 0);
		//2Pがくじら選択
		if (Get_Select_2P() == 2)
			Sprite_Draw(TEXTURE_INDEX_KUZIRA_ANIMATION, 1420.0f, 700.0f, 1, 0, 100, 300, 0, 0, 1.5f*0.75f, 1.0f*0.75f, 0);
		//2Pがイルカ選択
		if (Get_Select_2P() == 3)
			Sprite_Draw(TEXTURE_INDEX_IRUKA_ANIMATION, 1420.0f, 700.0f, 1, 0, 100, 300, 0, 0, 1.5f*0.75f, 1.0f*0.75f, 0);
		//1Pがうま選択
		if (Get_Select_2P() == 4)
			Sprite_Draw(TEXTURE_INDEX_UMA_ANIMATION, 1420.0f, 700.0f, 1, 0, 100, 300, 0, 0, 1.5f*0.75f, 1.0f*0.75f, 0);
	}
	else if (!Player[0].win) {
		//2Pが1位
		Minute_Draw( 940, 500, Player[1].Minute, 2, true, 1.5, 1.5);	//1位分数
		Second_Draw(1100, 500, Player[1].Second, 2, true, 1.5, 1.5);	//1位秒数

		Sprite_Draw(TEXTURE_INDEX_2P, 650, 450, 0, 0, 175, 175, 16, 16, 1.5f, 1.5f, 0);

		//2Pがカジキ選択
		if (Get_Select_2P() == 1) 
			Sprite_Draw(TEXTURE_INDEX_KAZIKI_ANIMATION, 1400.0f, 350.0f, 1, 0, 100, 300, 0, 0, 1.5f, 1.0f, 0);
		//2Pがくじら選択
		if (Get_Select_2P() == 2)
			Sprite_Draw(TEXTURE_INDEX_KUZIRA_ANIMATION, 1400.0f, 350.0f, 1, 0, 100, 300, 0, 0, 1.5f, 1.0f, 0);
		//2Pがイルカ選択
		if (Get_Select_2P() == 3)
			Sprite_Draw(TEXTURE_INDEX_IRUKA_ANIMATION, 1400.0f, 350.0f, 1, 0, 100, 300, 0, 0, 1.5f, 1.0f, 0);
		//2Pがうま選択
		if (Get_Select_2P() == 4)
			Sprite_Draw(TEXTURE_INDEX_UMA_ANIMATION, 1400.0f, 350.0f, 1, 0, 100, 300, 0, 0, 1.5f, 1.0f, 0);

		//1Pが2位
		Minute_Draw( 954, 800, Player[0].Minute, 2, true);	//2位分数
		Second_Draw(1114, 800, Player[0].Second, 2, true);	//2位秒数

		Sprite_Draw(TEXTURE_INDEX_1P, 750, 750);

		//2Pがカジキ選択
		if (Get_Select_1P() == 1)
			Sprite_Draw(TEXTURE_INDEX_KAZIKI_ANIMATION, 1420.0f, 700.0f, 1, 0, 100, 300, 0, 0, 1.5f*0.75f, 1.0f*0.75f, 0);
		//2Pがくじら選択
		if (Get_Select_1P() == 2)
			Sprite_Draw(TEXTURE_INDEX_KUZIRA_ANIMATION, 1420.0f, 700.0f, 1, 0, 100, 300, 0, 0, 1.5f*0.75f, 1.0f*0.75f, 0);
		//2Pがイルカ選択
		if (Get_Select_1P() == 3)
			Sprite_Draw(TEXTURE_INDEX_IRUKA_ANIMATION, 1420.0f, 700.0f, 1, 0, 100, 300, 0, 0, 1.5f*0.75f, 1.0f*0.75f, 0);
		//2Pがうま選択
		if (Get_Select_1P() == 4)
			Sprite_Draw(TEXTURE_INDEX_UMA_ANIMATION, 1420.0f, 700.0f, 1, 0, 100, 300, 0, 0, 1.5f*0.75f, 1.0f*0.75f, 0);
	}
	//if (Player[0].Minute == Player[1].Minute)
	//{
	//	if (Player[0].Second < Player[1].Second)
	//	{
	//		//1Pが1位
	//		Minute_Draw( 940, 500, Player[0].Minute, 2, true, 1.5, 1.5);	//1位分数
	//		Second_Draw(1100, 500, Player[0].Second, 2, true, 1.5, 1.5);	//1位秒数

	//		Sprite_Draw(TEXTURE_INDEX_1P, 650, 450, 0, 0, 175, 175, 16, 16, 1.5f, 1.5f, 0);

	//		//1Pがカジキ選択
	//		if (Get_Select_1P() == 1)
	//			Sprite_Draw(TEXTURE_INDEX_KAZIKI_ANIMATION, 1400.0f, 350.0f, 1, 0, 100, 300, 0, 0, 1.5f, 1.0f, 0);			
	//		//1Pがくじら選択
	//		if (Get_Select_1P() == 2)
	//			Sprite_Draw(TEXTURE_INDEX_KUZIRA_ANIMATION, 1400.0f, 350.0f, 1, 0, 100, 300, 0, 0, 1.5f, 1.0f, 0);
	//		//1Pがイルカ選択
	//		if (Get_Select_1P() == 3)
	//			Sprite_Draw(TEXTURE_INDEX_IRUKA_ANIMATION, 1400.0f, 350.0f, 1, 0, 100, 300, 0, 0, 1.5f, 1.0f, 0);
	//		//1Pがうま選択
	//		if (Get_Select_1P() == 4)
	//			Sprite_Draw(TEXTURE_INDEX_UMA_ANIMATION, 1400.0f, 350.0f, 1, 0, 100, 300, 0, 0, 1.5f, 1.0f, 0);

	//		//2Pが2位
	//		Minute_Draw( 954, 800, Player[1].Minute, 2, true);	//2位分数
	//		Second_Draw(1114, 800, Player[1].Second, 2, true);	//2位秒数

	//		Sprite_Draw(TEXTURE_INDEX_2P, 750, 750);

	//		//2Pがカジキ選択
	//		if (Get_Select_2P() == 1)
	//			Sprite_Draw(TEXTURE_INDEX_KAZIKI_ANIMATION, 1420.0f, 700.0f, 1, 0, 100, 300, 0, 0, 1.5f*0.75f, 1.0f*0.75f, 0);
	//		//2Pがくじら選択
	//		if (Get_Select_2P() == 2)
	//			Sprite_Draw(TEXTURE_INDEX_KUZIRA_ANIMATION, 1420.0f, 700.0f, 1, 0, 100, 300, 0, 0, 1.5f*0.75f, 1.0f*0.75f, 0);
	//		//2Pがイルカ選択
	//		if (Get_Select_2P() == 3)
	//			Sprite_Draw(TEXTURE_INDEX_IRUKA_ANIMATION, 1420.0f, 700.0f, 1, 0, 100, 300, 0, 0, 1.5f*0.75f, 1.0f*0.75f, 0);
	//		//1Pがうま選択
	//		if (Get_Select_2P() == 4)
	//			Sprite_Draw(TEXTURE_INDEX_UMA_ANIMATION, 1420.0f, 700.0f, 1, 0, 100, 300, 0, 0, 1.5f*0.75f, 1.0f*0.75f, 0);

	//	}
	//	else
	//	{
	//		//2Pが1位
	//		Minute_Draw( 940, 500, Player[1].Minute, 2, true, 1.5, 1.5);	//1位分数
	//		Second_Draw(1100, 500, Player[1].Second, 2, true, 1.5, 1.5);	//1位秒数

	//		Sprite_Draw(TEXTURE_INDEX_2P, 650, 450, 0, 0, 175, 175, 16, 16, 1.5f, 1.5f, 0);

	//		//2Pがカジキ選択
	//		if (Get_Select_2P() == 1) 
	//			Sprite_Draw(TEXTURE_INDEX_KAZIKI_ANIMATION, 1400.0f, 350.0f, 1, 0, 100, 300, 0, 0, 1.5f, 1.0f, 0);
	//		//2Pがくじら選択
	//		if (Get_Select_2P() == 2)
	//			Sprite_Draw(TEXTURE_INDEX_KUZIRA_ANIMATION, 1400.0f, 350.0f, 1, 0, 100, 300, 0, 0, 1.5f, 1.0f, 0);
	//		//2Pがイルカ選択
	//		if (Get_Select_2P() == 3)
	//			Sprite_Draw(TEXTURE_INDEX_IRUKA_ANIMATION, 1400.0f, 350.0f, 1, 0, 100, 300, 0, 0, 1.5f, 1.0f, 0);
	//		//2Pがうま選択
	//		if (Get_Select_2P() == 4)
	//			Sprite_Draw(TEXTURE_INDEX_UMA_ANIMATION, 1400.0f, 350.0f, 1, 0, 100, 300, 0, 0, 1.5f, 1.0f, 0);

	//		//1Pが2位
	//		Minute_Draw( 954, 800, Player[0].Minute, 2, true);	//2位分数
	//		Second_Draw(1114, 800, Player[0].Second, 2, true);	//2位秒数

	//		Sprite_Draw(TEXTURE_INDEX_1P, 750, 750);

	//		//2Pがカジキ選択
	//		if (Get_Select_1P() == 1)
	//			Sprite_Draw(TEXTURE_INDEX_KAZIKI_ANIMATION, 1420.0f, 700.0f, 1, 0, 100, 300, 0, 0, 1.5f*0.75f, 1.0f*0.75f, 0);
	//		//2Pがくじら選択
	//		if (Get_Select_1P() == 2)
	//			Sprite_Draw(TEXTURE_INDEX_KUZIRA_ANIMATION, 1420.0f, 700.0f, 1, 0, 100, 300, 0, 0, 1.5f*0.75f, 1.0f*0.75f, 0);
	//		//2Pがイルカ選択
	//		if (Get_Select_1P() == 3)
	//			Sprite_Draw(TEXTURE_INDEX_IRUKA_ANIMATION, 1420.0f, 700.0f, 1, 0, 100, 300, 0, 0, 1.5f*0.75f, 1.0f*0.75f, 0);
	//		//2Pがうま選択
	//		if (Get_Select_1P() == 4)
	//			Sprite_Draw(TEXTURE_INDEX_UMA_ANIMATION, 1420.0f, 700.0f, 1, 0, 100, 300, 0, 0, 1.5f*0.75f, 1.0f*0.75f, 0);
	//	}
	//}
	//else if (Player[0].Minute < Player[1].Minute)
	//{
	//	//1Pが1位 
	//	Minute_Draw( 940, 500, Player[0].Minute, 2, true, 1.5, 1.5);	//1位分数
	//	Second_Draw(1100, 500, Player[0].Second, 2, true, 1.5, 1.5);	//1位秒数

	//	Sprite_Draw(TEXTURE_INDEX_1P, 650, 450, 0, 0, 175, 175, 16, 16, 1.5f, 1.5f, 0);
	//														//1Pがカジキ選択
	//	if (Get_Select_1P() == 1)
	//		Sprite_Draw(TEXTURE_INDEX_KAZIKI_ANIMATION, 1400.0f, 350.0f, 1, 0, 100, 300, 0, 0, 1.5f, 1.0f, 0);
	//	//1Pがくじら選択
	//	if (Get_Select_1P() == 2)
	//		Sprite_Draw(TEXTURE_INDEX_KUZIRA_ANIMATION, 1400.0f, 350.0f, 1, 0, 100, 300, 0, 0, 1.5f, 1.0f, 0);
	//	//1Pがイルカ選択
	//	if (Get_Select_1P() == 3)
	//		Sprite_Draw(TEXTURE_INDEX_IRUKA_ANIMATION, 1400.0f, 350.0f, 1, 0, 100, 300, 0, 0, 1.5f, 1.0f, 0);
	//	//1Pがうま選択
	//	if (Get_Select_1P() == 4)
	//		Sprite_Draw(TEXTURE_INDEX_UMA_ANIMATION, 1400.0f, 350.0f, 1, 0, 100, 300, 0, 0, 1.5f, 1.0f, 0);

	//	//2Pが2位
	//	Minute_Draw( 954, 800, Player[1].Minute, 2, true);	//2位分数
	//	Second_Draw(1114, 800, Player[1].Second, 2, true);	//2位秒数

	//	Sprite_Draw(TEXTURE_INDEX_2P, 750, 750);
	//	
	//	//2Pがカジキ選択
	//	if (Get_Select_2P() == 1)
	//		Sprite_Draw(TEXTURE_INDEX_KAZIKI_ANIMATION, 1420.0f, 700.0f, 1, 0, 100, 300, 0, 0, 1.5f*0.75f, 1.0f*0.75f, 0);
	//	//2Pがくじら選択
	//	if (Get_Select_2P() == 2)
	//		Sprite_Draw(TEXTURE_INDEX_KUZIRA_ANIMATION, 1420.0f, 700.0f, 1, 0, 100, 300, 0, 0, 1.5f*0.75f, 1.0f*0.75f, 0);
	//	//2Pがイルカ選択
	//	if (Get_Select_2P() == 3)
	//		Sprite_Draw(TEXTURE_INDEX_IRUKA_ANIMATION, 1420.0f, 700.0f, 1, 0, 100, 300, 0, 0, 1.5f*0.75f, 1.0f*0.75f, 0);
	//	//2Pがうま選択
	//	if (Get_Select_2P() == 4)
	//		Sprite_Draw(TEXTURE_INDEX_UMA_ANIMATION, 1420.0f, 700.0f, 1, 0, 100, 300, 0, 0, 1.5f*0.75f, 1.0f*0.75f, 0);
	//}
	//else if (Player[0].Minute > Player[1].Minute)
	//{
	//	//2Pが1位
	//	Minute_Draw( 940, 500, Player[0].Minute, 2, true, 1.5, 1.5);	//1位分数
	//	Second_Draw(1100, 500, Player[0].Second, 2, true, 1.5, 1.5);	//1位秒数

	//	Sprite_Draw(TEXTURE_INDEX_2P, 650, 450, 0, 0, 175, 175, 16, 16, 1.5f, 1.5f, 0);
	//	
	//	//2Pがカジキ選択
	//	if (Get_Select_2P() == 1)
	//		Sprite_Draw(TEXTURE_INDEX_KAZIKI_ANIMATION, 1400.0f, 350.0f, 1, 0, 100, 300, 0, 0, 1.5f, 1.0f, 0);
	//	//2Pがくじら選択
	//	if (Get_Select_2P() == 2)
	//		Sprite_Draw(TEXTURE_INDEX_KUZIRA_ANIMATION, 1400.0f, 350.0f, 1, 0, 100, 300, 0, 0, 1.5f, 1.0f, 0);
	//	//2Pがイルカ選択
	//	if (Get_Select_2P() == 3)
	//		Sprite_Draw(TEXTURE_INDEX_IRUKA_ANIMATION, 1400.0f, 350.0f, 1, 0, 100, 300, 0, 0, 1.5f, 1.0f, 0);
	//	//1Pがうま選択
	//	if (Get_Select_2P() == 4)
	//		Sprite_Draw(TEXTURE_INDEX_UMA_ANIMATION, 1400.0f, 350.0f, 1, 0, 100, 300, 0, 0, 1.5f, 1.0f, 0);

	//	//1Pが2位
	//	Minute_Draw( 954, 800, Player[1].Minute, 2, true);	//2位分数
	//	Second_Draw(1114, 800, Player[1].Second, 2, true);	//2位秒数

	//	Sprite_Draw(TEXTURE_INDEX_1P, 750, 750);

	//	//2Pがカジキ選択
	//	if (Get_Select_1P() == 1)
	//		Sprite_Draw(TEXTURE_INDEX_KAZIKI_ANIMATION, 1420.0f, 700.0f, 1, 0, 100, 300, 0, 0, 1.5f*0.75f, 1.0f*0.75f, 0);
	//	//2Pがくじら選択
	//	if (Get_Select_1P() == 2)
	//		Sprite_Draw(TEXTURE_INDEX_KUZIRA_ANIMATION, 1420.0f, 700.0f, 1, 0, 100, 300, 0, 0, 1.5f*0.75f, 1.0f*0.75f, 0);
	//	//2Pがイルカ選択
	//	if (Get_Select_1P() == 3)
	//		Sprite_Draw(TEXTURE_INDEX_IRUKA_ANIMATION, 1420.0f, 700.0f, 1, 0, 100, 300, 0, 0, 1.5f*0.75f, 1.0f*0.75f, 0);
	//	//2Pがうま選択
	//	if (Get_Select_1P() == 4)
	//		Sprite_Draw(TEXTURE_INDEX_UMA_ANIMATION, 1420.0f, 700.0f, 1, 0, 100, 300, 0, 0, 1.5f*0.75f, 1.0f*0.75f, 0);
	//}


	//int x = 0;

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
	////1位描画
	//Minute_Draw(440, 120, Player[0].Minute, 2, true);	//1位分数
	//Second_Draw(520, 120, Player[0].Second, 2, true);	//1位秒数

	//if (Player[0].Second == Second_1P_Iruka())
	//{
	//	Sprite_Draw(TEXTURE_INDEX_KAZIKI, SCREEN_WIDTH / 2 - 70.0f , 150.0f);
	//}
	//if (Player[0].Second == Second_1P_Iruka())
	//{
	//	Sprite_Draw(TEXTURE_INDEX_IRUKA, SCREEN_WIDTH / 2 - 70.0f, 150.0f);
	//}
	////2位描画
	//Minute_Draw(100, 200, Player[1].Minute, 2, true);	//2位分数
	//Second_Draw(180, 200, Player[1].Second, 2, true);	//2位秒数

	//if (Player[1].Second == Second_1P_Iruka())
	//{
	//	Sprite_Draw(TEXTURE_INDEX_KAZIKI, 150.0f, 250.0f);
	//}
	//if (Player[1].Second == Second_1P_Iruka())
	//{
	//	Sprite_Draw(TEXTURE_INDEX_IRUKA, 150.0f, 250.0f);
	//}
}


int Get_Player_Min(int n)
{
	return Player[n].Minute;
}

int Get_Player_Sec(int n)
{
	return Player[n].Second;
}