/*================================================
			     worldrecord.cpp
--------------------------------------------------
	�ߋ����܂�TOP5�̃^�C�����\�[�g���A
	���ʕt�����āA�o�͂���B
	�܂��A�e���ʂ̃^�C����Ԃ��B

	�\�[�g���@�̓o�u���\�[�g
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

RECORD g_Wrecord[RECORD_SIZE];				//�@�v���C���[���R�[�h�i���l���j
PLAYER g_Player[2];							//�@�v���C���[���R�[�h�i���u���j

static bool FirstTime = true;				//���ڈȍ~��Initialize�Ń����L���O�����������ď㏑�����Ȃ��悤�ɔ�΂����߂̃t���O


void Swap(int *x, int *y);					//Swap�֐��v���g�^�C�v�錾(�����ł����g��Ȃ��\��Ȃ̂�.h�ɂ͏����Ȃ�)

void WorldRecord_Initialize(void)
{
	Fade_Start(false, 90, D3DCOLOR_RGBA(0, 0, 0, 0));

	//���ׂĂ�Min,Sec���Ƃ���99�ŏ�����
	if (FirstTime) {	
		for (int i = 0; i < RECORD_SIZE - 1; i++)
		{
			g_Wrecord[i].Min = 99;
			g_Wrecord[i].Sec = 99;
		}
	}
	/*
	�\������
	---���e---
	HEW�����ɃQ�[�����I�����Ă��܂��A
	�����L���O�̃f�[�^�������Ă��܂�����
	�����Œ��ڋL�q����B
	if(FIrstTime){
		//1��
		g_Wrecord[0].Min = ;
		g_Wrecord[0].Sec = ;

		//2��
		g_Wrecord[1].Min = ;
		g_Wrecord[1].Sec = ;

		//3��
		g_Wrecord[2].Min = ;
		g_Wrecord[2].Sec = ;

		//4��
		g_Wrecord[3].Min = ;
		g_Wrecord[3].Sec = ;

		//5��
		g_Wrecord[4].Min = ;
		g_Wrecord[4].Sec = ;
	}
	*/

	for (int i = 0; i < 2; i++)
	{
		//�v���C���[���Ƃ̃^�C����g_Wrecord��[6][7]�ԖڂɊi�[
		g_Wrecord[i + 5].Min = Get_Player_Min(i);
		g_Wrecord[i + 5].Sec = Get_Player_Sec(i);

		//�^�C����"Min"���������ꍇ��"Min * 60"�̒l��"Sec"�ɉ��Z
		if (g_Wrecord[i + 5].Min != 0 && g_Wrecord[i + 5].Min != 99) {
			g_Wrecord[i + 5].Sec += 60 * g_Wrecord[i + 5].Min;
			g_Wrecord[i + 5].Min  = 0;
		}
		//�v���C���[���Ƃ̃^�C�������ꂼ��̕ϐ��Ɋi�[
		//��g_Wrecord�ɓ��ꂽ�܂܂��ƃ\�[�g����ۂɓ���ւ����Ă��܂����߁A�ʕϐ��ɕۊ�
		g_Player[i].Min = Get_Player_Min(i);
		g_Player[i].Sec = Get_Player_Sec(i);
	}

	//������"FirstTime"�t���O��؂��Ă������ƂŁA2��ڈȍ~����������Ȃ�
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

	//�^�C���\�[�g����
	for (int i = 0; i < RECORD_SIZE - 1; i++) {
		for (int j = 0; j < RECORD_SIZE - 1; j++) {
			if (g_Wrecord[j + 1].Sec < g_Wrecord[j].Sec) {				//�b���������傫�����"�^"
				if (g_Wrecord[j + 1].Min <= g_Wrecord[j].Min) {			//�����������傫�����"�^"
					Swap(&g_Wrecord[j + 1].Sec, &g_Wrecord[j].Sec);		//�b������ւ�
					Swap(&g_Wrecord[j + 1].Min, &g_Wrecord[j].Min);		//��������ւ�
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

	//Sec -> Min�ɕϊ�
	for (int i = 0; i < 5; i++)
	{
		if (g_Wrecord[i].Min == 99)
			continue;

		if (g_Wrecord[i].Sec / 60 >= 1) {
			g_Wrecord[i].Min = g_Wrecord[i].Sec / 60;
			g_Wrecord[i].Sec = g_Wrecord[i].Sec % 60;
		}
	}

	Minute_Draw( 750, 250, g_Wrecord[0].Min, 2, true, 1.5f, 1.5f);	//1�ʕ���
	Second_Draw( 950, 250, g_Wrecord[0].Sec, 2, true, 1.5f, 1.5f);	//1�ʕb��

	Minute_Draw( 440, 425, g_Wrecord[1].Min, 2, true);				//2�ʕ���
	Second_Draw( 600, 425, g_Wrecord[1].Sec, 2, true);				//2�ʕb��

	Minute_Draw(1240, 425, g_Wrecord[2].Min, 2, true);				//3�ʕ���
	Second_Draw(1400, 425, g_Wrecord[2].Sec, 2, true);				//3�ʕb��

	Minute_Draw( 440, 625, g_Wrecord[3].Min, 2, true);				//4�ʕ���
	Second_Draw( 600, 625, g_Wrecord[3].Sec, 2, true);				//4�ʕb��

	Minute_Draw(1240, 625, g_Wrecord[4].Min, 2, true);				//5�ʕ���
	Second_Draw(1400, 625, g_Wrecord[4].Sec, 2, true);				//5�ʕb��

	Minute_Draw( 440, 815, g_Player[0].Min, 2, true);				//1P����
	Second_Draw( 600, 815, g_Player[0].Sec, 2, true);				//1P�b��

	Minute_Draw(1240, 815, g_Player[1].Min, 2, true);				//2P����
	Second_Draw(1400, 815, g_Player[1].Sec, 2, true);				//2P�b��

}

//g_Wrecord�Ɋi�[����Ă���"����"��Ԃ��B(�����͍\���̂̔ԍ�)
int Get_WorldMin(int n)
{
	return g_Wrecord[n].Min;
}
//g_Wrecord�Ɋi�[����Ă���"�b��"��Ԃ��B(�����͍\���̂̔ԍ�)
int Get_WorldSec(int n)
{
	return g_Wrecord[n].Sec;
}
//Swap�֐��B�����ɓ��ꂽ���������ւ���B
void Swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}