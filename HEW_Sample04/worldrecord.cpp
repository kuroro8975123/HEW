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
#include "scene_playerselect.h"

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

typedef struct {
	int Min;
	int Sec;
}RECORD;

RECORD g_Wrecord[7];				//�@�v���C���[���R�[�h�i���l���j
static int WinnerMin, WinnerSec;	//�@���҂̃^�C���i�[�ϐ�
static int tempMin, tempSec;		//�@�^�C���ꎞ�i�[�ϐ�
static int SelectPlayer[2];			//�@0�c1P�@,�@1�c2P

//
static bool	_1st, _2nd, _3rd, _4th, _5th, Drow;


void WorldRecord_Initialize(void)
{
	Fade_Start(false, 90, D3DCOLOR_RGBA(0, 0, 0, 0));

	//�t���O�����ׂ�"false"��
	_1st = false;
	_2nd = false;
	_3rd = false;
	_4th = false;
	_5th = false;
	Drow = false;

	//1P,2P�̔z��ɃL�����N�^�[�ԍ����i�[
	SelectPlayer[0] = Get_Select_1P();
	SelectPlayer[1] = Get_Select_2P();

	//1P�̃^�C���i�[����
	if (SelectPlayer[0] == 1){	//1P���J�W�L��I�񂾂Ƃ�
		g_Wrecord[5].Min = Minute_1P_Kajiki(); 
		g_Wrecord[5].Sec = Second_1P_Kajiki();
	}
	if (SelectPlayer[0] == 2) {	//1P���N�W����I�񂾂Ƃ�
		g_Wrecord[5].Min = Minute_1P_Kujira();
		g_Wrecord[5].Sec = Second_1P_Kujira();
	}
	if (SelectPlayer[0] == 3) {	//1P���C���J��I�񂾂Ƃ�
		g_Wrecord[5].Min = Minute_1P_Iruka();
		g_Wrecord[5].Sec = Second_1P_Iruka();
	}
	if (SelectPlayer[0] == 4) { //1P�����܂�I�񂾂Ƃ�
		g_Wrecord[5].Min = Minute_1P_Uma();
		g_Wrecord[5].Sec = Second_1P_Uma();
	}

	//2P�̃^�C���i�[����
	if (SelectPlayer[1] == 1) {	//2P���J�W�L��I�񂾂Ƃ�
		g_Wrecord[6].Min = Minute_2P_Kajiki();
		g_Wrecord[6].Sec = Second_2P_Kajiki();
	}
	if (SelectPlayer[1] == 2) {	//2P���N�W����I�񂾂Ƃ�
		g_Wrecord[6].Min = Minute_2P_Kujira();
		g_Wrecord[6].Sec = Second_2P_Kujira();
	}
	if (SelectPlayer[1] == 3) {	//2P���C���J��I�񂾂Ƃ�
		g_Wrecord[6].Min = Minute_2P_Iruka();
		g_Wrecord[6].Sec = Second_2P_Iruka();
	}
	if (SelectPlayer[1] == 4) { //2P�����܂�I�񂾂Ƃ�
		g_Wrecord[6].Min = Minute_2P_Uma();
		g_Wrecord[6].Sec = Second_2P_Uma();
	}
}

void WorldRecord_Finalize(void)
{

}

void WorldRecord_Update(void)
{
	if (Keyboard_IsTrigger(DIK_SPACE) || GamePad_IsTrigger(0, BUTTON_A)) {
		Scene_Change(SCENE_INDEX_TITLE);
	}

	//�����L���O�v�Z����

	//�v���C���[�̃^�C���ő����ق����Ƃ肾��

	//1P��2P�̕����������Ƃ�
	if (g_Wrecord[5].Min == g_Wrecord[6].Min){
		//�b�����r����
		if (g_Wrecord[5].Sec < g_Wrecord[6].Sec){			//1P�̕��������ꍇ
			//1P�̃^�C�����i�[
			WinnerMin = g_Wrecord[5].Min;
			WinnerSec = g_Wrecord[5].Sec;
		}
		else if (g_Wrecord[5].Sec > g_Wrecord[6].Sec) {		//2P�̕��������ꍇ
			//2P�̃^�C�����i�[
			WinnerMin = g_Wrecord[6].Min;
			WinnerSec = g_Wrecord[6].Sec;
		}
		else if (g_Wrecord[5].Sec == g_Wrecord[6].Sec) {	//�����̏ꍇ
			//1P�̃^�C�����i�[
			WinnerMin = g_Wrecord[5].Min;
			WinnerSec = g_Wrecord[5].Sec;
			//Drow�t���O��"true"��
			Drow == true;
		}

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

int Get_WorldMin(int n)
{
	return g_Wrecord[n].Min;
}

int Get_WorldSec(int n)
{
	return g_Wrecord[n].Sec;
}