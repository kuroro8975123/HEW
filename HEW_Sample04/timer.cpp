
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 Timer.cpp	[タイマー計測処理]		//	齋藤   //

 ＜仕様＞
 ・秒分に分けてる。
 ・g_Timeが60回ったら、g_secondが1増える。
 ・g_secondが60以上になったら、g_minuteが1増える。

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <math.h>
#include "timer.h"
#include "main.h"
#include "game.h"
#include "number.h"

int g_Time;		//60FPS測定用
int g_Time_s;
static int g_second;	//秒計測用
static int g_minute;	//分計測用

//初期化
void Timer_Initialize(void)
{
	g_Time = 0;
	g_Time_s = 0;
	g_second = 0;
	g_minute = 0;
}

//終了
void Timer_Uninit(void)
{

}

//更新
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

//描画
void Second_Draw(float x, float y, int second, int fig, bool bZero)
{
	for (int i = 0; i < fig; i++) {

		int n = second % 10;
		second /= 10;

		Number_Draw(x + NUMBER_WIDTH * (fig - (i + 1)), y, n);
	}
}
//追加分（サイズ拡大用）
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

//追加分（サイズ拡大用）
void Minute_Draw(float x, float y, int minute, int fig, bool bZero,float sx,float sy)
{
	for (int i = 0; i < fig; i++) {

		int m = minute % 10;
		minute /= 10;

		Number_Draw(x + NUMBER_WIDTH * (fig - (i + 1)), y, m, sx, sy);
	}
}

//取得
int Timer_GetMinute()
{
	return g_minute;
}

int Timer_GetSecond()
{
	return g_second;
}