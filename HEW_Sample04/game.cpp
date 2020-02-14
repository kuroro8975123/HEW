#include "main.h"
#include "texture.h"
#include "enemy.h"
#include "fade.h"
#include "scene.h"
#include "sprite.h"
#include "score_draw.h"
#include "timer.h"
#include "Iruka.h"
#include "Kajiki.h"
#include "Kujira.h"
#include "Uma.h"
#include "scene_playerselect.h"
#include "sound.h"

#define NOMAL_SCR		(1)	//コースの長さ
#define END_SCR			(NOMAL_SCR + 1)
#define MAP             (515)

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

static int Player_1P;

static int Player_2P;

int swimCount;

float map_1P;
float map_1P_;
float map_1P_count;
float map_2P;
float map_2P_;
float map_2P_count;



void Game_Initialize(void)
{
	Player_1P = Get_Select_1P();
	Player_2P = Get_Select_2P();
	if (Player_1P == 1)
	{
		Kajiki_Initialize_1P(675, 550);
	}
	if (Player_1P == 2)
	{
		Kujira_Initialize_1P(675, 550);
	}
	if (Player_1P == 3)
	{
		Iruka_Initialize_1P(675, 550);
	}
	if (Player_1P == 4)
	{
		Uma_Initialize_1P(675, 550);
	}
	if (Player_2P == 1)
	{
		Kajiki_Initialize_2P(1150, 550);
	}
	if (Player_2P == 2)
	{
		Kujira_Initialize_2P(1150, 550);
	}
	if (Player_2P == 3)
	{
		Iruka_Initialize_2P(1150, 550);
	}
	if (Player_2P == 4)
	{
		Uma_Initialize_2P(1150, 550);
	}


	Timer_Initialize();

	g_Phase = PHASE_INDEX_FADE;
	g_GameFrameCount = 0;
	g_Score = 0;
	g_KillCount = 0;
	Fade_Start(false, 30, D3DCOLOR_RGBA(0, 0, 0, 0));
	CountDown = 0;
	map_1P = 800;
	map_1P_ = 0;
	map_1P_count = 0;
	map_2P = 800;
	map_2P_ = 0;
	map_2P_count = 0;
	swimCount = 90;

}

void Game_Finalize(void)
{

	Kajiki_Finalize();
	Kujira_Finalize();
	Iruka_Finalize();
	Uma_Finalize();
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
				//PlaySound(SOUND_LABEL_BGM_GAME01);
			}
			break;
		case PHASE_INDEX_PLAYER_IN:
		case PHASE_INDEX_PLAYER_MUTEKI:
		case PHASE_INDEX_PLAYER_NORMAL:

			// 泳いでる音のSE（うるさいので今コメントアウトしてます。）
			swimCount++;

			if (swimCount > 90)
			{
				PlaySound(SOUND_LABEL_SE_SWIM);
				swimCount = 0;
			}

			//Enemy_Update();
			Timer_Update();

			//ゲームの終了チェック
			if (Game_EndCheck())
			{
				StopSound(SOUND_LABEL_SE_SWIM);
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
		if (Player_1P == 1)
		{
			Kajiki_Update_1P();
			if (map_1P > 220)
			{
				map_1P_ = Kajiki_Speed_1P();
				map_1P_count = map_1P_ / 19.7;
				map_1P = 800 - map_1P_count;

				if (map_1P < 220)
				{
					map_1P = 220;
				}
			}

		}
		if (Player_1P == 2)
		{
			Kujira_Update_1P();
			if (map_1P > 220)
			{
				map_1P_ = Kujira_Speed_1P();
				map_1P_count = map_1P_ / 19.7;
				map_1P = 800 - map_1P_count;

				if (map_1P < 220)
				{
					map_1P = 220;
				}
			}

		}
		if (Player_1P == 3)
		{
			Iruka_Update_1P();
			if (map_1P > 220)
			{
				map_1P_ = Iruka_Speed_1P();
				map_1P_count = map_1P_ / 19.7;
				map_1P = 800 - map_1P_count;

				if (map_1P < 220)
				{
					map_1P = 220;
				}
			}

		}
		if (Player_1P == 4)
		{
			Uma_Update_1P();
			if (map_1P > 220)
			{
				map_1P_ = Uma_Speed_1P();
				map_1P_count = map_1P_ / 19.7;
				map_1P = 800 - map_1P_count;

				if (map_1P < 220)
				{
					map_1P = 220;
				}
			}

		}
		if (Player_2P == 1)
		{
			Kajiki_Update_2P();
			if (map_2P > 220)
			{
				map_2P_ = Kajiki_Speed_2P();
				map_2P_count = map_2P_ / 19.7;
				map_2P = 800 - map_2P_count;

				if (map_2P < 220)
				{
					map_2P = 220;
				}
			}

		}
		if (Player_2P == 2)
		{
			Kujira_Update_2P();
			if (map_2P > 220)
			{
				map_2P_ = Kujira_Speed_2P();
				map_2P_count = map_2P_ / 19.7;
				map_2P = 800 - map_2P_count;

				if (map_2P < 220)
				{
					map_2P = 220;
				}
			}

		}
		if (Player_2P == 3)
		{
			Iruka_Update_2P();
			if (map_2P > 220)
			{
				map_2P_ = Iruka_Speed_2P();
				map_2P_count = map_2P_ / 19.7;
				map_2P = 800 - map_2P_count;

				if (map_2P < 220)
				{
					map_2P = 220;
				}
			}

		}
		if (Player_2P == 4)
		{
			Uma_Update_2P();
			if (map_2P > 220)
			{
				map_2P_ = Uma_Speed_2P();
				map_2P_count = map_2P_ / 19.7;
				map_2P = 800 - map_2P_count;

				if (map_2P < 220)
				{
					map_2P = 220;
				}
			}

		}

	}
	if (CountDown < 300)
		CountDown++;

}


void Game_Draw(void)
{

	if (Player_1P == 1)
	{
		Kajiki_Draw_1P();
	}
	if (Player_1P == 2)
	{
		Kujira_Draw_1P();
	}
	if (Player_1P == 3)
	{
		Iruka_Draw_1P();
	}
	if (Player_1P == 4)
	{
		Uma_Draw_1P();
	}
	if (Player_2P == 1)
	{
		Kajiki_Draw_2P();
	}
	if (Player_2P == 2)
	{
		Kujira_Draw_2P();
	}
	if (Player_2P == 3)
	{
		Iruka_Draw_2P();
	}
	if (Player_2P == 4)
	{
		Uma_Draw_2P();
	}


	Sprite_Draw(TEXTURE_INDEX_BG, 0, 0);

	Sprite_Draw(TEXTURE_INDEX_1P_MAP, 1590, map_1P);// 800 220 105
	Sprite_Draw(TEXTURE_INDEX_2P_MAP, 1695, map_2P);// 800 220

	//Enemy_Draw();
	Minute_Draw(850, 20, Timer_GetMinute(), 2, true);
	Second_Draw(980, 20, Timer_GetSecond(), 2, true);

	if (CountDown < 60)
	{
		PlaySound(SOUND_LABEL_SE_COUNT);
		Sprite_Draw(TEXTURE_INDEX_3, 600.0f, 320.0f);
	}
	if (CountDown > 60 && CountDown < 120)
	{
		PlaySound(SOUND_LABEL_SE_COUNT);
		Sprite_Draw(TEXTURE_INDEX_2, 600.0f, 320.0f);
	}
	if (CountDown > 120 && CountDown < 180)
	{
		PlaySound(SOUND_LABEL_SE_COUNT);
		Sprite_Draw(TEXTURE_INDEX_1, 600.0f, 320.0f);
	}
	if (CountDown > 180 && CountDown < 240)
	{
		PlaySound(SOUND_LABEL_SE_START);
		Sprite_Draw(TEXTURE_INDEX_START, -10.0f, 30.0f);
	}

}

bool Game_EndCheck(void)
{
	if (Player_1P == 1 && Player_2P == 1)
	{
		if (End_1P_Kajiki() == true && End_2P_Kajiki() == true)
		{
			return true;
		}
	}
	if (Player_1P == 1 && Player_2P == 2)
	{
		if (End_1P_Kajiki() && End_2P_Kujira())
		{
			return true;
		}
	}
	if (Player_1P == 1 && Player_2P == 3)
	{
		if (End_1P_Kajiki() && End_2P_Iruka())
		{
			return true;
		}
	}
	if (Player_1P == 1 && Player_2P == 4)
	{
		if (End_1P_Kajiki() && End_2P_Uma())
		{
			return true;
		}
	}
	if (Player_1P == 2 && Player_2P == 1)
	{
		if (End_1P_Kujira() && End_2P_Kajiki())
		{
			return true;
		}
	}
	if (Player_1P == 2 && Player_2P == 2)
	{
		if (End_1P_Kujira() && End_2P_Kujira())
		{
			return true;
		}
	}
	if (Player_1P == 2 && Player_2P == 3)
	{
		if (End_1P_Kujira() && End_2P_Iruka())
		{
			return true;
		}
	}
	if (Player_1P == 2 && Player_2P == 4)
	{
		if (End_1P_Kujira() && End_2P_Uma())
		{
			return true;
		}
	}
	if (Player_1P == 3 && Player_2P == 1)
	{
		if (End_1P_Iruka() && End_2P_Kajiki())
		{
			return true;
		}
	}
	if (Player_1P == 3 && Player_2P == 2)
	{
		if (End_1P_Iruka() && End_2P_Kujira())
		{
			return true;
		}
	}
	if (Player_1P == 3 && Player_2P == 3)
	{
		if (End_1P_Iruka() && End_2P_Iruka())
		{
			return true;
		}
	}
	if (Player_1P == 3 && Player_2P == 4)
	{
		if (End_1P_Iruka() && End_2P_Uma())
		{
			return true;
		}
	}
	if (Player_1P == 4 && Player_2P == 1)
	{
		if (End_1P_Uma() && End_2P_Kajiki())
		{
			return true;
		}
	}
	if (Player_1P == 4 && Player_2P == 2)
	{
		if (End_1P_Uma() && End_2P_Kujira())
		{
			return true;
		}
	}
	if (Player_1P == 4 && Player_2P == 3)
	{
		if (End_1P_Uma() && End_2P_Iruka())
		{
			return true;
		}
	}
	if (Player_1P == 4 && Player_2P == 4)
	{
		if (End_1P_Uma() && End_2P_Uma())
		{
			return true;
		}
	}
	return false;
}

