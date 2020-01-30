
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	���ʌ���d�l
	�E�e�v���C���[���̃^�C������( game.cpp�ɂ� )
	�E���ʌ���( result.cpp�ɂ� )

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

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
}PLAYER;

RANKING Ranking[6];
PLAYER  Player[2];

static int Player_1P;

static int Player_2P;


void Result_Initialize(void)
{
	Fade_Start(false, 90, D3DCOLOR_RGBA(0, 0, 0, 0));

	Player_1P = Get_Select_1P();
	Player_2P = Get_Select_2P();


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
		Player[1].Minute = Minute_1P_Uma();
		Player[1].Second = Second_1P_Uma();
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
	if( Keyboard_IsTrigger(DIK_SPACE) || GamePad_IsTrigger(0, BUTTON_A)) {

=======
	if (Keyboard_IsTrigger(DIK_SPACE) || GamePad_IsTrigger(0, BUTTON_A)) {
>>>>>>> d59f43ab6cdc254a145301f671e2538b95d8edf4
		Scene_Change(SCENE_INDEX_WORLDRECORD);
		PlaySound(SOUND_LABEL_SE_AWA);
		Scene_Change(SCENE_INDEX_TITLE);
	}


}

void Result_Draw()
{
	Sprite_Draw(TEXTURE_INDEX_RESULT, 0.0f, 0.0f);
	Sprite_Draw(TEXTURE_INDEX_WINNER, 250.0f, 350.0f);
	Sprite_Draw(TEXTURE_INDEX_LOSER, 400.0f, 720.0f);

	if (Player[0].Minute == Player[1].Minute)
	{
		if (Player[0].Second < Player[1].Second)
		{
			//1P��1��
			Minute_Draw(440, 450, Player[0].Minute, 2, true);	//1�ʕ���
			Second_Draw(600, 450, Player[0].Second, 2, true);	//1�ʕb��

			//1P���J�W�L�I��
			if (Get_Select_1P() == 1)
				Sprite_Draw(TEXTURE_INDEX_KAZIKI_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

			//1P��������I��
			if (Get_Select_1P() == 2)
				Sprite_Draw(TEXTURE_INDEX_KUZIRA_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

			//1P���C���J�I��
			if (Get_Select_1P() == 3)
				Sprite_Draw(TEXTURE_INDEX_IRUKA_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

			//1P�����ܑI��
			if (Get_Select_1P() == 4)
				Sprite_Draw(TEXTURE_INDEX_UMA_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

			//2P��2��
			Minute_Draw(1440, 450, Player[1].Minute, 2, true);	//2�ʕ���
			Second_Draw(1600, 450, Player[1].Second, 2, true);	//2�ʕb��

			//2P���J�W�L�I��
			if (Get_Select_2P() == 1)
				Sprite_Draw(TEXTURE_INDEX_KAZIKI_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

			//2P��������I��
			if (Get_Select_2P() == 2)
				Sprite_Draw(TEXTURE_INDEX_KUZIRA_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

			//2P���C���J�I��
			if (Get_Select_2P() == 3)
				Sprite_Draw(TEXTURE_INDEX_IRUKA_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

			//1P�����ܑI��
			if (Get_Select_2P() == 4)
				Sprite_Draw(TEXTURE_INDEX_UMA_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);
		}
		else
		{
			//2P��1��
			Minute_Draw(440, 450, Player[1].Minute, 2, true);	//1�ʕ���
			Second_Draw(600, 450, Player[1].Second, 2, true);	//1�ʕb��

			//2P���J�W�L�I��
			if (Get_Select_2P() == 1)
				Sprite_Draw(TEXTURE_INDEX_KAZIKI_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

			//2P��������I��
			if (Get_Select_2P() == 2)
				Sprite_Draw(TEXTURE_INDEX_KUZIRA_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

			//2P���C���J�I��
			if (Get_Select_2P() == 3)
				Sprite_Draw(TEXTURE_INDEX_IRUKA_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

			//2P�����ܑI��
			if (Get_Select_2P() == 4)
				Sprite_Draw(TEXTURE_INDEX_UMA_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

			//1P��2��
			Minute_Draw(1440, 450, Player[0].Minute, 2, true);	//2�ʕ���
			Second_Draw(1600, 450, Player[0].Second, 2, true);	//2�ʕb��

			//2P���J�W�L�I��
			if (Get_Select_1P() == 1)
				Sprite_Draw(TEXTURE_INDEX_KAZIKI_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

			//2P��������I��
			if (Get_Select_1P() == 2)
				Sprite_Draw(TEXTURE_INDEX_KUZIRA_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

			//2P���C���J�I��
			if (Get_Select_1P() == 3)
				Sprite_Draw(TEXTURE_INDEX_IRUKA_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

			//2P�����ܑI��
			if (Get_Select_1P() == 4)
				Sprite_Draw(TEXTURE_INDEX_UMA_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);
		}
	}
	else if (Player[0].Minute < Player[1].Minute)
	{
		//1P��1��
		Minute_Draw(440, 450, Player[0].Minute, 2, true);	//1�ʕ���
		Second_Draw(600, 450, Player[0].Second, 2, true);	//1�ʕb��

															//1P���J�W�L�I��
		if (Get_Select_1P() == 1)
			Sprite_Draw(TEXTURE_INDEX_KAZIKI_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

		//1P��������I��
		if (Get_Select_1P() == 2)
			Sprite_Draw(TEXTURE_INDEX_KUZIRA_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

		//1P���C���J�I��
		if (Get_Select_1P() == 3)
			Sprite_Draw(TEXTURE_INDEX_IRUKA_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

		//1P�����ܑI��
		if (Get_Select_1P() == 4)
			Sprite_Draw(TEXTURE_INDEX_UMA_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

		//2P��2��
		Minute_Draw(1440, 450, Player[1].Minute, 2, true);	//2�ʕ���
		Second_Draw(1600, 450, Player[1].Second, 2, true);	//2�ʕb��

															//2P���J�W�L�I��
		if (Get_Select_2P() == 1)
			Sprite_Draw(TEXTURE_INDEX_KAZIKI_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

		//2P��������I��
		if (Get_Select_2P() == 2)
			Sprite_Draw(TEXTURE_INDEX_KUZIRA_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

		//2P���C���J�I��
		if (Get_Select_2P() == 3)
			Sprite_Draw(TEXTURE_INDEX_IRUKA_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

		//2P�����ܑI��
		if (Get_Select_2P() == 4)
			Sprite_Draw(TEXTURE_INDEX_UMA_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);
	}
	else if (Player[0].Minute > Player[1].Minute)
	{
		//2P��1��
		Minute_Draw(440, 450, Player[1].Minute, 2, true);	//1�ʕ���
		Second_Draw(600, 450, Player[1].Second, 2, true);	//1�ʕb��

															//2P���J�W�L�I��
		if (Get_Select_2P() == 1)
			Sprite_Draw(TEXTURE_INDEX_KAZIKI_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

		//2P��������I��
		if (Get_Select_2P() == 2)
			Sprite_Draw(TEXTURE_INDEX_KUZIRA_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

		//2P���C���J�I��
		if (Get_Select_2P() == 3)
			Sprite_Draw(TEXTURE_INDEX_IRUKA_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

		//1P�����ܑI��
		if (Get_Select_2P() == 4)
			Sprite_Draw(TEXTURE_INDEX_UMA_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

		//1P��2��
		Minute_Draw(1440, 450, Player[0].Minute, 2, true);	//2�ʕ���
		Second_Draw(1600, 450, Player[0].Second, 2, true);	//2�ʕb��

		//2P���J�W�L�I��
		if (Get_Select_1P() == 1)
			Sprite_Draw(TEXTURE_INDEX_KAZIKI_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

		//2P��������I��
		if (Get_Select_1P() == 2)
			Sprite_Draw(TEXTURE_INDEX_KUZIRA_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

		//2P���C���J�I��
		if (Get_Select_1P() == 3)
			Sprite_Draw(TEXTURE_INDEX_IRUKA_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);

		//2P�����ܑI��
		if (Get_Select_1P() == 4)
			Sprite_Draw(TEXTURE_INDEX_UMA_ANIMATION, 100.0f, 100.0f, 1, 0, 100, 300);
	}


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
	////1�ʕ`��
	//Minute_Draw(440, 120, Player[0].Minute, 2, true);	//1�ʕ���
	//Second_Draw(520, 120, Player[0].Second, 2, true);	//1�ʕb��

	//if (Player[0].Second == Second_1P_Iruka())
	//{
	//	Sprite_Draw(TEXTURE_INDEX_KAZIKI, SCREEN_WIDTH / 2 - 70.0f , 150.0f);
	//}
	//if (Player[0].Second == Second_1P_Iruka())
	//{
	//	Sprite_Draw(TEXTURE_INDEX_IRUKA, SCREEN_WIDTH / 2 - 70.0f, 150.0f);
	//}
	////2�ʕ`��
	//Minute_Draw(100, 200, Player[1].Minute, 2, true);	//2�ʕ���
	//Second_Draw(180, 200, Player[1].Second, 2, true);	//2�ʕb��

	//if (Player[1].Second == Second_1P_Iruka())
	//{
	//	Sprite_Draw(TEXTURE_INDEX_KAZIKI, 150.0f, 250.0f);
	//}
	//if (Player[1].Second == Second_1P_Iruka())
	//{
	//	Sprite_Draw(TEXTURE_INDEX_IRUKA, 150.0f, 250.0f);
	//}
}
