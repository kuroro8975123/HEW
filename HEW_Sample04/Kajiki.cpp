/*-----------------------------------------------------------------------------
カジキ.cpp

カジキの処理全般の処理
------------------------------------------------------------------------------*/
#include "Kajiki.h"
#include "main.h"
#include "input.h"
#include "timer.h"
#include "sprite.h"
#include "sound.h"

/*------------------------------------------------------------------------------
マクロ定義
------------------------------------------------------------------------------*/
#define NOMAL_SCR		(30)	//コースの長さ
#define END_SCR			(NOMAL_SCR + 1)
#define MAX_SPEED       (10000)
#define ANIME_PATTERN_MAX	7

/*------------------------------------------------------------------------------
グローバル変数
------------------------------------------------------------------------------*/
int Count_1P_Kajiki;
int Count_2P_Kajiki;
bool Goal_1P_Kajiki;
bool Goal_2P_Kajiki;
bool map_flag;

float Move_BG1_Kajiki; 
float Move_BG1_1P_Kajiki;
float Move_BG1_1P_Kajiki_;

static float Speed_Button;
static float Speed;
static float END;

static float Speed_Button_2P;
static float Speed_2P;
static float END_2P;

static float Start;

float Move_BG2_Kajiki;
float Move_BG_2P_Kajiki;
float Move_BG_2P_Kajiki_;

int Time_Minute_1P_Kajiki;
int Time_Second_1P_Kajiki;
int Time_Minute_2P_Kajiki;
int Time_Second_2P_Kajiki;
static int g_animCount;

Kajiki kajiki;
Kajiki_2P kajiki_2P;

/*------------------------------------------------------------------------------
カジキ1Pの初期化
------------------------------------------------------------------------------*/
void Kajiki_Initialize_1P(float x, float y)
{

	kajiki.pos.x = x;
	kajiki.pos.y = y;
	kajiki.speed = 0;
	kajiki.button = 0;
	kajiki.button_flag = false;
	kajiki.end_flag = false;
	g_animCount = 0;
	Count_1P_Kajiki = 0;
	Move_BG1_Kajiki = 0;
	Move_BG1_1P_Kajiki_ = 0;
	Move_BG1_1P_Kajiki = 0;
	Goal_1P_Kajiki = false;
	Speed = 0;
	Speed_Button = 0;
	END = 0;
	Start = 0;
}
/*------------------------------------------------------------------------------
カジキ2Pの初期化
------------------------------------------------------------------------------*/
void Kajiki_Initialize_2P(float x, float y)
{

	kajiki_2P.pos.x = x;
	kajiki_2P.pos.y = y;
	kajiki_2P.speed = 0;
	kajiki_2P.button = 0;
	kajiki_2P.button_flag = false;
	kajiki_2P.end_flag = false;
	Count_2P_Kajiki = 0;
	Move_BG2_Kajiki = 0;
	Move_BG_2P_Kajiki_ = 0;
	Move_BG_2P_Kajiki = 0;
	Goal_2P_Kajiki = false;
	Speed_2P = 0;
	Speed_Button_2P = 0;
	END_2P = 0;

}
/*------------------------------------------------------------------------------
カジキの終了処理
------------------------------------------------------------------------------*/
void Kajiki_Finalize(void)
{

}
/*------------------------------------------------------------------------------
カジキ1Pの更新処理
------------------------------------------------------------------------------*/
void Kajiki_Update_1P(void)
{
	//プレイヤー
	if ((Speed_Button + Speed) <= MAX_SPEED)
	{
		Speed += 1.0;
		Speed_Button += GetSpeed_1P_Kajiki();
		END = (Speed + Speed_Button);

		Move_BG1_Kajiki += 1.0;
		Move_BG1_1P_Kajiki_ += GetSpeed_1P_Kajiki();
		Move_BG1_1P_Kajiki = (Move_BG1_Kajiki + Move_BG1_1P_Kajiki_);
		
		if (Move_BG1_Kajiki + Move_BG1_1P_Kajiki_ > (SCREEN_HEIGHT + 250))
		{
			Move_BG1_Kajiki = 250;
			Move_BG1_1P_Kajiki_ = 250;
		}
		if (Move_BG1_1P_Kajiki > (SCREEN_HEIGHT * 2) + 500)
		{
			Move_BG1_1P_Kajiki = 500;

		}
	}
	else
	{
		Speed += 1.0;
		Speed_Button += GetSpeed_1P_Kajiki();
		END = (Speed + Speed_Button);

		if (Move_BG1_1P_Kajiki_ + Move_BG1_Kajiki < (SCREEN_HEIGHT * 2 - 510))
		{
			Move_BG1_1P_Kajiki_ += GetSpeed_1P_Kajiki();
			Move_BG1_Kajiki += 1.1;
		}
		if (Move_BG1_1P_Kajiki < (SCREEN_HEIGHT * 2 - 510))
		{
			Move_BG1_1P_Kajiki = (Move_BG1_1P_Kajiki_ + Move_BG1_Kajiki);
		}
		else if (Move_BG1_1P_Kajiki > (SCREEN_HEIGHT * 2 - 510))
		{
			if (Goal_1P_Kajiki == false) {
				Time_Minute_1P_Kajiki = Timer_GetMinute();
				Time_Second_1P_Kajiki = Timer_GetSecond();
				PlaySound(SOUND_LABEL_SE_TIMEOUT);
			}
			Goal_1P_Kajiki = true;
			
		}
	}
	Kajiki_Button_1P();


	g_animCount += 1;

	if (g_animCount > ANIME_PATTERN_MAX)
	{
		g_animCount = 0;
	}

}
/*------------------------------------------------------------------------------
カジキ2Pの更新処理
------------------------------------------------------------------------------*/
void Kajiki_Update_2P(void)
{
	//プレイヤー
	if ((Speed_Button_2P + Speed_2P) <= MAX_SPEED)
	{
		Speed_2P += 1.0;
		Speed_Button_2P += GetSpeed_2P_Kajiki();
		END_2P = (Speed_2P + Speed_Button_2P);


		Move_BG2_Kajiki += 1.0;
		Move_BG_2P_Kajiki_ += GetSpeed_2P_Kajiki();
		Move_BG_2P_Kajiki = (Move_BG2_Kajiki + Move_BG_2P_Kajiki_);

		if (Move_BG2_Kajiki + Move_BG_2P_Kajiki_ > (SCREEN_HEIGHT + 250))
		{
			Move_BG2_Kajiki = 250;
			Move_BG_2P_Kajiki_ = 250;
			Count_2P_Kajiki++;
		}
		if (Move_BG_2P_Kajiki > (SCREEN_HEIGHT * 2) + 500)
		{
			Move_BG_2P_Kajiki = 500;

		}
	}
	else 
	{
		Speed_2P += 1.0;
		Speed_Button_2P += GetSpeed_2P_Kajiki();
		END_2P = (Speed_2P + Speed_Button_2P);

		if (Move_BG_2P_Kajiki_ + Move_BG2_Kajiki < (SCREEN_HEIGHT * 2 - 510))
		{
			Move_BG_2P_Kajiki_ += GetSpeed_2P_Kajiki();
			Move_BG2_Kajiki += 1.1;
		}
		if (Move_BG_2P_Kajiki < (SCREEN_HEIGHT * 2 - 510))
		{
			Move_BG_2P_Kajiki = (Move_BG_2P_Kajiki_ + Move_BG2_Kajiki);
		}
		else if (Move_BG_2P_Kajiki > (SCREEN_HEIGHT * 2 - 510))
		{
			if (Goal_2P_Kajiki == false) {
				Time_Minute_2P_Kajiki = Timer_GetMinute();
				Time_Second_2P_Kajiki = Timer_GetSecond();
				PlaySound(SOUND_LABEL_SE_TIMEOUT);
			}
			Goal_2P_Kajiki = true;
		}
	}
	Kajiki_Button_2P();
	
	g_animCount += 1;

	if (g_animCount > ANIME_PATTERN_MAX)
	{
		g_animCount = 0;
	}

}
/*------------------------------------------------------------------------------
カジキ1Pの描画処理
------------------------------------------------------------------------------*/
void Kajiki_Draw_1P(void)
{
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 4),
		                            Move_BG1_1P_Kajiki_ + Move_BG1_Kajiki,
		                            (SCREEN_WIDTH / 2),0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT);

	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 4),
		                            (-SCREEN_HEIGHT + 250) + Move_BG1_1P_Kajiki_ + Move_BG1_Kajiki,
		                            (SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT -50);
	
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 4), 
		                            ((-SCREEN_HEIGHT * 2) + 500) + Move_BG1_1P_Kajiki_ + Move_BG1_Kajiki,
		                            (SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT -50);

	if (END < SCREEN_HEIGHT)
	{
		Sprite_Draw(TEXTURE_INDEX_START_GOAL, 0, END + 500);
	}
	Sprite_Draw(TEXTURE_INDEX_1P, kajiki.pos.x - 15, kajiki.pos.y + 250);

	if (!Goal_1P_Kajiki)
	{
		Sprite_Draw(TEXTURE_INDEX_KAZIKI_ANIMATION, kajiki.pos.x, kajiki.pos.y, g_animCount * 100, 0, 100, 300);

		//1pボタンの位置x=680
		if (kajiki.button == 1 && kajiki.button_flag)
		{
			Sprite_Draw(TEXTURE_INDEX_A_BUTTON, 660, 890);
		}
		if (kajiki.button == 2 && kajiki.button_flag)
		{
			Sprite_Draw(TEXTURE_INDEX_B_BUTTON, 660, 890);
		}
		if (kajiki.button == 3 && kajiki.button_flag)
		{
			Sprite_Draw(TEXTURE_INDEX_X_BUTTON, 660, 890);
		}
		if (kajiki.button == 4 && kajiki.button_flag)
		{
			Sprite_Draw(TEXTURE_INDEX_Y_BUTTON, 660, 890);
		}
	}
	else
	{
		Sprite_Draw(TEXTURE_INDEX_KAZIKI_ANIMATION, kajiki.pos.x, kajiki.pos.y,0, 0, 100, 300);

	}
}
/*------------------------------------------------------------------------------
カジキ2Pの描画
------------------------------------------------------------------------------*/
void Kajiki_Draw_2P(void)
{
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 2), 
									 Move_BG_2P_Kajiki_ + Move_BG2_Kajiki,
									(SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT);
	
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 2),
									(-SCREEN_HEIGHT + 250) + Move_BG_2P_Kajiki_ + Move_BG2_Kajiki,
									(SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT - 50);
	
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 2),
									((-SCREEN_HEIGHT * 2) + 500) + Move_BG_2P_Kajiki_ + Move_BG2_Kajiki,
									(SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT - 50);
	if (END_2P < SCREEN_HEIGHT)
	{
		Sprite_Draw(TEXTURE_INDEX_START_GOAL, SCREEN_WIDTH / 2, END_2P + 500);
	}

	Sprite_Draw(TEXTURE_INDEX_2P, kajiki_2P.pos.x -10, kajiki_2P.pos.y + 250);

	if (!Goal_2P_Kajiki)
	{
		Sprite_Draw(TEXTURE_INDEX_KAZIKI_ANIMATION, kajiki_2P.pos.x, kajiki_2P.pos.y, g_animCount * 100, 0, 100, 300);

		if (kajiki_2P.button == 1 && kajiki_2P.button_flag)
		{
			Sprite_Draw(TEXTURE_INDEX_A_BUTTON, 1140, 890);
		}
		if (kajiki_2P.button == 2 && kajiki_2P.button_flag)
		{
			Sprite_Draw(TEXTURE_INDEX_B_BUTTON, 1140, 890);
		}
		if (kajiki_2P.button == 3 && kajiki_2P.button_flag)
		{
			Sprite_Draw(TEXTURE_INDEX_X_BUTTON, 1140, 890);
		}
		if (kajiki_2P.button == 4 && kajiki_2P.button_flag)
		{
			Sprite_Draw(TEXTURE_INDEX_Y_BUTTON, 1140, 890);
		}
	}
	else
	{
		Sprite_Draw(TEXTURE_INDEX_KAZIKI_ANIMATION, kajiki_2P.pos.x, kajiki_2P.pos.y, 0, 0, 100, 300);

	}
}

/*------------------------------------------------------------------------------
カジキ1Pのボタン入力処理
------------------------------------------------------------------------------*/
void Kajiki_Button_1P(void)
{
	D3DXVECTOR2 dir = D3DXVECTOR2(0.0f, 0.0f);

	if (kajiki.button_flag == false)
	{
		kajiki.button = rand() % 4 + 1;
		kajiki.button_flag = true;
	}
	if (kajiki.button == 1 && kajiki.button_flag)
	{
		if (Keyboard_IsPress(DIK_UP) || GamePad_IsPress(2, BUTTON_A))
		{
			map_flag = true;
			PlaySound(SOUND_LABEL_SE_ATARI);
			kajiki.speed += 1.08;
			kajiki.button_flag = false;
		}
	}
	if (kajiki.button == 2 && kajiki.button_flag)
	{
		if (Keyboard_IsPress(DIK_RIGHT) || GamePad_IsPress(2, BUTTON_B))
		{
			map_flag = true;
			PlaySound(SOUND_LABEL_SE_ATARI);
			kajiki.speed += 1.05;
			kajiki.button_flag = false;
		}
	}
	if (kajiki.button == 3 && kajiki.button_flag)
	{
		if (Keyboard_IsPress(DIK_DOWN) || GamePad_IsPress(2, BUTTON_X))
		{
			map_flag = true;
			PlaySound(SOUND_LABEL_SE_ATARI);
			kajiki.speed += 1.03;
			kajiki.button_flag = false;
		}
	}
	if (kajiki.button == 4 && kajiki.button_flag)
	{
		if (Keyboard_IsPress(DIK_LEFT) || GamePad_IsPress(2, BUTTON_Y))
		{
			map_flag = true;
			PlaySound(SOUND_LABEL_SE_ATARI);
			kajiki.speed += 1.01;
			kajiki.button_flag = false;
		}
	}
	if (Goal_Flag_1P_Kajiki())
	{
		if (kajiki.pos.y > 20)
		{
			kajiki.pos.y -= kajiki.speed;
		}
	}
	if (Goal_Flag_1P_Kajiki())
	{
		if (kajiki.pos.y > 25)
		{
			kajiki.pos.y -= 1.0;
		}
		else
		{
			kajiki.end_flag = true;
		}
	}

	// 座標の更新処理
	kajiki.pos += dir;

}
/*------------------------------------------------------------------------------
カジキ2Pのボタン入力処理
------------------------------------------------------------------------------*/
void Kajiki_Button_2P(void)
{
	D3DXVECTOR2 dir = D3DXVECTOR2(0.0f, 0.0f);

	if (kajiki_2P.button_flag == false)
	{
		kajiki_2P.button = rand() % 4 + 1;
		kajiki_2P.button_flag = true;
	}
	if (kajiki_2P.button == 1 && kajiki_2P.button_flag)
	{
		if (Keyboard_IsPress(DIK_UP) || GamePad_IsPress(3, BUTTON_A))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			kajiki_2P.speed += 0.08;
			kajiki_2P.button_flag = false;
		}
	}
	if (kajiki_2P.button == 2 && kajiki_2P.button_flag)
	{
		if (Keyboard_IsPress(DIK_RIGHT) || GamePad_IsPress(3, BUTTON_B))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			kajiki_2P.speed += 0.05;
			kajiki_2P.button_flag = false;
		}
	}
	if (kajiki_2P.button == 3 && kajiki_2P.button_flag)
	{
		if (Keyboard_IsPress(DIK_DOWN) || GamePad_IsPress(3, BUTTON_X))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			kajiki_2P.speed += 0.03;
			kajiki_2P.button_flag = false;
		}
	}
	if (kajiki_2P.button == 4 && kajiki_2P.button_flag)
	{
		if (Keyboard_IsPress(DIK_LEFT) || GamePad_IsPress(3, BUTTON_Y))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			kajiki_2P.speed += 0.01;
			kajiki_2P.button_flag = false;
		}
	}
	if (Goal_Flag_2P_Kajiki())
	{
		if (kajiki_2P.pos.y > 20)
		{
			kajiki_2P.pos.y -= kajiki_2P.speed;
		}
	}
	if (Goal_Flag_2P_Kajiki())
	{
		if (kajiki_2P.pos.y > 25)
		{
			kajiki_2P.pos.y -= 1.0;
		}
		else
		{
			kajiki_2P.end_flag = true;
		}
	}

	// 座標の更新処理
	kajiki_2P.pos += dir;

}
/*------------------------------------------------------------------------------
カジキ1Pのゴール処理
------------------------------------------------------------------------------*/
bool Goal_Flag_1P_Kajiki()
{
	return Goal_1P_Kajiki;
}
/*------------------------------------------------------------------------------
カジキ2Pのゴール処理
------------------------------------------------------------------------------*/
bool Goal_Flag_2P_Kajiki()
{
	return Goal_2P_Kajiki;
}

/*------------------------------------------------------------------------------
カジキ1Pのスピードのゲッター
------------------------------------------------------------------------------*/
float GetSpeed_1P_Kajiki()
{
	return kajiki.speed;
}
/*------------------------------------------------------------------------------
カジキ2Pのスピードのゲッター
------------------------------------------------------------------------------*/
float GetSpeed_2P_Kajiki()
{
	return kajiki_2P.speed;
}
/*------------------------------------------------------------------------------
カジキ1Pのエンドフラグのゲッター
------------------------------------------------------------------------------*/
bool End_1P_Kajiki()
{
	return kajiki.end_flag;
}
/*------------------------------------------------------------------------------
カジキ1Pのエンドフラグのゲッター
------------------------------------------------------------------------------*/
bool End_2P_Kajiki()
{
	return kajiki_2P.end_flag;
}

int	Minute_1P_Kajiki()
{
	return Time_Minute_1P_Kajiki;
}
int	Minute_2P_Kajiki()
{
	return Time_Minute_2P_Kajiki;
}

int Second_1P_Kajiki()
{
	return Time_Second_1P_Kajiki;
}
int Second_2P_Kajiki()
{
	return Time_Second_2P_Kajiki;
}

float Kajiki_Speed_1P()
{
	return END;
}
float Kajiki_Speed_2P()
{
	return END_2P;
}

