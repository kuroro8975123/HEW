
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 Timer.cpp	[�^�C�}�[�v������]		//	�V��   //

 ���d�l��
 �E�b���ɕ����Ă�B
 �Eg_Time��60�������Ag_second��1������B
 �Eg_second��60�ȏ�ɂȂ�����Ag_minute��1������B

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <math.h>
#include "timer.h"
#include "main.h"
#include "game.h"
#include "number.h"

int g_Time;		//60FPS����p
int g_Time_s;
static int g_second;	//�b�v���p
static int g_minute;	//���v���p

//������
void Timer_Initialize(void)
{
	g_Time = 0;
	g_Time_s = 0;
	g_second = 0;
	g_minute = 0;
}

//�I��
void Timer_Uninit(void)
{

}

//�X�V
void Timer_Update(void)
{
	g_Time++;

	if (g_Time >= 60)
	{
		g_second += 1;
		g_Time = 0;

		if (g_second >= 60)
		{
			g_minute++;
			g_second = 0;
		}
	}
}

//�`��
void Second_Draw(float x, float y, int second, int fig, bool bZero)
{
	for (int i = 0; i < fig; i++) {

		int n = second % 10;
		second /= 10;

		Number_Draw(x + NUMBER_WIDTH * (fig - (i + 1)), y, n);
	}
}
//�ǉ����i�T�C�Y�g��p�j
void Second_Draw(float x, float y, int second, int fig, bool bZero,float sx,float sy)
{
	for (int i = 0; i < fig; i++) {

		int n = second % 10;
		second /= 10;

		Number_Draw(x + NUMBER_WIDTH * (fig - (i + 1)), y, n, sx, sy);
	}
}

void Minute_Draw(float x, float y, int minute, int fig, bool bZero)
{
	for (int i = 0; i < fig; i++) {

		int m = minute % 10;
		minute /= 10;

		Number_Draw(x + NUMBER_WIDTH * (fig - (i + 1)), y, m);
	}
}

//�ǉ����i�T�C�Y�g��p�j
void Minute_Draw(float x, float y, int minute, int fig, bool bZero,float sx,float sy)
{
	for (int i = 0; i < fig; i++) {

		int m = minute % 10;
		minute /= 10;

		Number_Draw(x + NUMBER_WIDTH * (fig - (i + 1)), y, m, sx, sy);
	}
}

//�擾
int Timer_GetMinute()
{
	return g_minute;
}

int Timer_GetSecond()
{
	return g_second;
}