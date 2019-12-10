#include "main.h"
#include "texture.h"
#include "player.h"
#include "enemy.h"
#include "fade.h"
#include "scene.h"
#include "sprite.h"
#include "score_draw.h"
#include "timer.h"

#define NOMAL_SCR		(10)	//コースの長さ
#define END_SCR			(NOMAL_SCR + 1)

typedef enum PHASE_INDEX
{
	PHASE_INDEX_FADE,
	PHASE_INDEX_PLAYER_IN,
	PHASE_INDEX_PLAYER_MUTEKI,
	PHASE_INDEX_PLAYER_NORMAL,
	PHASE_INDEX_STAGE_CLEAR,
	PHASE_INDEX_END,

	PHASE_INDEX_MAX
};

static PHASE_INDEX g_Phase;
static int g_GameFrameCount;

static int g_Score = 0;// 点数
static int g_KillCount = 0;

static bool Game_EndCheck(void);

int Score;

int CountDown;

int Count_P;
int Count_E01;
int Count_E02;
int Count_E03;

bool Goal_P;
bool Goal_E01;
bool Goal_E02;
bool Goal_E03;


float Move_BG;
float Move_BG_01;
float Move_BG_Player;

float Move_BG_Enemy0;
float Move_BG_Enemy0_01;
float Move_BG_Enemy0_02;

float Move_BG_Enemy1;
float Move_BG_Enemy1_01;
float Move_BG_Enemy1_02;

float Move_BG_Enemy2;
float Move_BG_Enemy2_01;
float Move_BG_Enemy2_02;

// 各プレイヤー毎のタイム格納用
// 分数
int Time_Minute_Player01;
int Time_Minute_Enemy01;
int Time_Minute_Enemy02;
int Time_Minute_Enemy03;

// 秒数
int Time_Second_Player01;
int Time_Second_Enemy01;
int Time_Second_Enemy02;
int Time_Second_Enemy03;

Character_main *pC[1];

void Game_Initialize(void)
{
	pC[0] = new Character_main(100, 500);
	

	Enemy_Initialize();
	Timer_Initialize();

	Count_P = 0;
	Count_E01 = 0;
	Count_E02 = 0;
	Count_E03 = 0;

	Move_BG = 0;
	Move_BG_01 = 0;
	Move_BG_Player = 0;

	Move_BG_Enemy0 = 0;
	Move_BG_Enemy0_01 = 0;
	Move_BG_Enemy0_02 = 0;

	Move_BG_Enemy1 = 0;
	Move_BG_Enemy1_01 = 0;
	Move_BG_Enemy1_02 = 0;

	Move_BG_Enemy2 = 0;
	Move_BG_Enemy2_01 = 0;
	Move_BG_Enemy2_02 = 0;

	Goal_P = false;
	Goal_E01 = false;
	Goal_E02 = false;
	Goal_E03 = false;

	g_Phase = PHASE_INDEX_FADE;
	g_GameFrameCount = 0;
	g_Score = 0;
	g_KillCount = 0;
	Fade_Start(false, 30, D3DCOLOR_RGBA(0, 0, 0, 0));
}

void Game_Finalize(void)
{
	
	delete pC[0];
	
	Enemy_Finalize();
	Timer_Uninit();
}

void Game_Update(void)
{
	if (CountDown > 240)
	{
		switch (g_Phase)
		{
		case PHASE_INDEX_FADE:
			if (!Fade_IsFade()) {
				g_Phase = PHASE_INDEX_PLAYER_NORMAL;
				// PlaySound(SOUND_LABEL_BGM000);
			}
			break;
		case PHASE_INDEX_PLAYER_IN:
		case PHASE_INDEX_PLAYER_MUTEKI:
		case PHASE_INDEX_PLAYER_NORMAL:
			pC[0]->Update();
			Enemy_Update();
			Timer_Update();


			//ゲームの終了チェック
			if (Game_EndCheck())
			{
				Fade_Start(true, 90, D3DCOLOR_RGBA(0, 0, 0, 0));
				g_Phase = PHASE_INDEX_STAGE_CLEAR;
			}
			break;
		case PHASE_INDEX_STAGE_CLEAR:
			if (!Fade_IsFade()) {
				Scene_Change(SCENE_INDEX_RESULT);
				g_Phase = PHASE_INDEX_END;
			}
			break;
		case PHASE_INDEX_END:
			break;
		}

		
		//プレイヤー
		if (Count_P <= NOMAL_SCR)
		{
			Move_BG += 1.0;
			Move_BG_Player +=  pC[0]->Player_GetSpeed();
			Move_BG_01 = (Move_BG + Move_BG_Player);

			if (Move_BG + Move_BG_Player > (SCREEN_HEIGHT  + 150))
			{
				Move_BG = 150;
				Move_BG_Player = 150;
				Count_P++;
			}
			if (Move_BG_01 > (SCREEN_HEIGHT * 2) + 300)
			{
				Move_BG_01 = 300;

			}
		}
		else if (Count_P >= END_SCR)
		{
			if (Move_BG_Player + Move_BG < (SCREEN_HEIGHT * 2 - 310))
			{
				Move_BG_Player += pC[0]->Player_GetSpeed();
				Move_BG += 0.1;
			}
			if (Move_BG_01 < (SCREEN_HEIGHT * 2 - 310))
			{
				Move_BG_01 = (Move_BG_Player + Move_BG);
			}
			else if (Move_BG_01 > (SCREEN_HEIGHT * 2 - 310))
			{
				if (Goal_P == false) {
					Time_Minute_Player01 = Timer_GetMinute();
					Time_Second_Player01 = Timer_GetSecond();
				}
				Goal_P = true;
			}
		}

		//敵01
		if (Count_E01 <= NOMAL_SCR)
		{
			Move_BG_Enemy0 += Enemy_GetSpeed(0);
			Move_BG_Enemy0_01 += 1.7;
			Move_BG_Enemy0_02 = (Move_BG_Enemy0 + Move_BG_Enemy0_01);


			if (Move_BG_Enemy0 + Move_BG_Enemy0_01 > (SCREEN_HEIGHT + 150))
			{
				Move_BG_Enemy0 = 150;
				Move_BG_Enemy0_01 = 150;
				Count_E01++;

			}
			if (Move_BG_Enemy0_02 > (SCREEN_HEIGHT * 2 + 300))
			{
				Move_BG_Enemy0_02 = 300;
			}

		}
		else if (Count_E01 >= END_SCR)
		{
			if (Move_BG_Enemy0 + Move_BG_Enemy0_01 < (SCREEN_HEIGHT * 2 - 310))
			{
				Move_BG_Enemy0 += Enemy_GetSpeed(0);
				Move_BG_Enemy0_01 += 1.7;

			}
			if (Move_BG_Enemy0_02 < (SCREEN_HEIGHT * 2 - 310))
			{
				Move_BG_Enemy0_02 = (Move_BG_Enemy0 + Move_BG_Enemy0_01);
			}
			else if (Move_BG_Enemy0_02 > (SCREEN_HEIGHT * 2 - 310) && Count_E01 > 2)
			{
				if (Goal_P == false) {
					Time_Minute_Enemy01 = Timer_GetMinute();
					Time_Second_Enemy01 = Timer_GetSecond();
				}
				Goal_E01 = true;
				
			}
		}

		//敵02
		if (Count_E02 <= NOMAL_SCR)
		{
			Move_BG_Enemy1 += Enemy_GetSpeed(0);
			Move_BG_Enemy1_01 += 1.7;
			Move_BG_Enemy1_02 = (Move_BG_Enemy0 + Move_BG_Enemy0_01);

			if (Move_BG_Enemy1 + Move_BG_Enemy1_01 > (SCREEN_HEIGHT) + 150)
			{
				Move_BG_Enemy1 = 150;
				Move_BG_Enemy1_01 = 150;
				Count_E02++;
			}
			if (Move_BG_Enemy1_02 > (SCREEN_HEIGHT * 2) + 300)
			{
				Move_BG_Enemy1_02 = 300;
			}

		}
		else if (Count_E02 >= END_SCR)
		{
			if (Move_BG_Enemy1 + Move_BG_Enemy1_01 < (SCREEN_HEIGHT * 2 - 310))
			{
				Move_BG_Enemy1 += Enemy_GetSpeed(1);
				Move_BG_Enemy1_01 += 1.7;
			}
			if (Move_BG_Enemy1_02 < (SCREEN_HEIGHT * 2 - 310))
			{
				Move_BG_Enemy1_02 = (Move_BG_Enemy1 + Move_BG_Enemy1_01);
			}
			else if (Move_BG_Enemy1_02 > (SCREEN_HEIGHT * 2 - 310))
			{
				if (Goal_P == false) {
					Time_Minute_Enemy02 = Timer_GetMinute();
					Time_Second_Enemy02 = Timer_GetSecond();
				}
				Goal_E02 = true;
			}
		}
		//敵03
		if (Count_E03 <= NOMAL_SCR)
		{
			Move_BG_Enemy2 += Enemy_GetSpeed(0);
			Move_BG_Enemy2_01 += 1.7;
			Move_BG_Enemy2_02 = (Move_BG_Enemy0 + Move_BG_Enemy0_01);

			if (Move_BG_Enemy2 + Move_BG_Enemy2_01 > (SCREEN_HEIGHT  + 150))
			{
				Move_BG_Enemy2 = 150;
				Move_BG_Enemy2_01 = 150;
				Count_E03++;
			}
			if (Move_BG_Enemy2_02 > (SCREEN_HEIGHT * 2) + 300)
			{
				Move_BG_Enemy2_02 = 300;
			}
		}
		else if (Count_E03 >= END_SCR)
		{
			if (Move_BG_Enemy2 + Move_BG_Enemy2_01 < (SCREEN_HEIGHT * 2 - 310))
			{
				Move_BG_Enemy2 += Enemy_GetSpeed(2);
				Move_BG_Enemy2_01 += 1.4;
			}
			if (Move_BG_Enemy2_02 < (SCREEN_HEIGHT * 2 - 310))
			{
				Move_BG_Enemy2_02 = (Move_BG_Enemy2 + Move_BG_Enemy2_01);
			}
			else if (Move_BG_Enemy2_02 > (SCREEN_HEIGHT * 2 - 310))
			{
				if (Goal_P == false) {
					Time_Minute_Enemy03 = Timer_GetMinute();
					Time_Second_Enemy03 = Timer_GetSecond();
				}
				Goal_E03 = true;
			}
		}
	}
	if (CountDown < 300)
		CountDown++;

}

void Game_Draw(void)
{
	Sprite_Draw(TEXTURE_INDEX_GAME, 0 * (SCREEN_WIDTH / 4), Move_BG_Player + Move_BG, 0 * (SCREEN_WIDTH / 4), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT);
	Sprite_Draw(TEXTURE_INDEX_GAME, 0 * (SCREEN_WIDTH / 4), (-SCREEN_HEIGHT + 150) + Move_BG_Player + Move_BG, 0 * (SCREEN_WIDTH / 4), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT - 50);
	Sprite_Draw(TEXTURE_INDEX_GAME, 0 * (SCREEN_WIDTH / 4), ((-SCREEN_HEIGHT * 2) + 300) + Move_BG_01, 0 * (SCREEN_WIDTH / 4), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT - 50);

	Sprite_Draw(TEXTURE_INDEX_GAME, 1 * (SCREEN_WIDTH / 4), Move_BG_Enemy0 + Move_BG_Enemy0_01, 1 * (SCREEN_WIDTH / 4), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT);
	Sprite_Draw(TEXTURE_INDEX_GAME, 1 * (SCREEN_WIDTH / 4), (-SCREEN_HEIGHT + 150) + Move_BG_Enemy0 + Move_BG_Enemy0_01, 1 * (SCREEN_WIDTH / 4), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT - 50);
	Sprite_Draw(TEXTURE_INDEX_GAME, 1 * (SCREEN_WIDTH / 4), ((-SCREEN_HEIGHT * 2) + 300) + Move_BG_Enemy0_02, 1 * (SCREEN_WIDTH / 4), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT - 50);

	Sprite_Draw(TEXTURE_INDEX_GAME, 2 * (SCREEN_WIDTH / 4), Move_BG_Enemy1 + Move_BG_Enemy1_01, 2 * (SCREEN_WIDTH / 4), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT);
	Sprite_Draw(TEXTURE_INDEX_GAME, 2 * (SCREEN_WIDTH / 4), (-SCREEN_HEIGHT + 150) + Move_BG_Enemy1 + Move_BG_Enemy1_01, 2 * (SCREEN_WIDTH / 4), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT - 50);
	Sprite_Draw(TEXTURE_INDEX_GAME, 2 * (SCREEN_WIDTH / 4), ((-SCREEN_HEIGHT * 2) + 300) + Move_BG_Enemy1_02, 2 * (SCREEN_WIDTH / 4), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT - 50);

	Sprite_Draw(TEXTURE_INDEX_GAME, 3 * (SCREEN_WIDTH / 4), Move_BG_Enemy2 + Move_BG_Enemy2_01, 3 * (SCREEN_WIDTH / 4), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT);
	Sprite_Draw(TEXTURE_INDEX_GAME, 3 * (SCREEN_WIDTH / 4), (-SCREEN_HEIGHT + 150) + Move_BG_Enemy2 + Move_BG_Enemy2_01, 3 * (SCREEN_WIDTH / 4), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT - 50);
	Sprite_Draw(TEXTURE_INDEX_GAME, 3 * (SCREEN_WIDTH / 4), ((-SCREEN_HEIGHT * 2) + 300) + Move_BG_Enemy2_02, 3 * (SCREEN_WIDTH / 4), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT - 50);

	//	for (int i = 0; i < 4; i++)
	//	{
	//		float Move_BG = 0;
	//		Move_BG += 0.001;
	//		if (Move_BG + Player_GetSpeed() > SCREEN_HEIGHT - 100)
	//		{
	//			Move_BG = 0;
	//		}
	//		if (i = 0)
	//		{
	//			Sprite_Draw(TEXTURE_INDEX_GAME, i * (SCREEN_WIDTH / 4), -100.0f + (Move_BG + Player_GetSpeed()), i * (SCREEN_WIDTH / 4), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT);
	//			Sprite_Draw(TEXTURE_INDEX_GAME, i * (SCREEN_WIDTH / 4), -SCREEN_HEIGHT + (Move_BG + Player_GetSpeed()), i * (SCREEN_WIDTH / 4), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT);
	//		}
	//		Sprite_Draw(TEXTURE_INDEX_GAME, i * (SCREEN_WIDTH / 4), -100.0f + Move_BG, i * (SCREEN_WIDTH / 4), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT);
	//        Sprite_Draw(TEXTURE_INDEX_GAME, i * (SCREEN_WIDTH / 4), -SCREEN_HEIGHT + Move_BG, i * (SCREEN_WIDTH / 4), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT);
	//	}

	pC[0]->Draw();
	Enemy_Draw();
	Minute_Draw(440, 0, Timer_GetMinute(), 2, true);
	Second_Draw(520, 0, Timer_GetSecond(), 2, true);
	if (CountDown < 60)
	{
		Sprite_Draw(TEXTURE_INDEX_3, 256.0f, 144.0f);
	}
	if (CountDown > 60 && CountDown < 120)
	{
		Sprite_Draw(TEXTURE_INDEX_2, 256.0f, 144.0f);
	}
	if (CountDown > 120 && CountDown < 180)
	{
		Sprite_Draw(TEXTURE_INDEX_1, 256.0f, 144.0f);
	}
	if (CountDown > 180 && CountDown < 240)
	{
		Sprite_Draw(TEXTURE_INDEX_START, 256.0f, 144.0f);
	}

}

bool Game_EndCheck(void)
{
	if (pC[0]->Player_End() && Enemy_End(0) && Enemy_End(1) && Enemy_End(2))
	{
		return true;
	}
	return false;
}

void Game_AddScore(int score)
{
	g_Score += score;
}

void Game_AddKillCount()
{
	g_KillCount += 1;
}

bool Goal_Flag_P()
{
	return Goal_P;
}
bool Goal_Flag_E01()
{
	return Goal_E01;
}
bool Goal_Flag_E02()
{
	return Goal_E02;
}
bool Goal_Flag_E03()
{
	return Goal_E03;
}

int	Minute_Player01()
{
	return Time_Minute_Player01;
}

int Second_Player01()
{
	return Time_Second_Player01;
}

int Minute_Enemy01()
{
	return Time_Minute_Enemy01;
}

int Second_Enemy01()
{
	return Time_Second_Enemy01;
}

int Minute_Enemy02()
{
	return Time_Minute_Enemy02;
}

int Second_Enemy02()
{
	return Time_Second_Enemy02;
}

int Minute_Enemy03()
{
	return Time_Minute_Enemy03;
}

int Second_Enemy03()
{
	return Time_Second_Enemy03;
}