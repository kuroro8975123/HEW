#include "Kajiki.h"
#include "main.h"
#include "input.h"
#include "timer.h"
#include "sprite.h"
#include "sound.h"

#define NOMAL_SCR		(100)	//コースの長さ
#define END_SCR			(NOMAL_SCR + 1)
#define ANIME_PATTERN_MAX	7


int Count_1P_Kajiki;
int Count_2P_Kajiki;
bool Goal_1P_Kajiki;
bool Goal_2P_Kajiki;
float Move_BG1_Kajiki; 
float Move_BG1_1P_Kajiki;
float Move_BG1_1P_Kajiki_;
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

void Kajiki_Initialize_1P(float x, float y)
{

	kajiki.pos.x = x;
	kajiki.pos.y = y;
	kajiki.speed = 0;
	kajiki.button = 0;
	kajiki.button_flag = false;
	kajiki.end_flag = false;
	g_animCount = 0;
}
void Kajiki_Initialize_2P(float x, float y)
{

	kajiki_2P.pos.x = x;
	kajiki_2P.pos.y = y;
	kajiki_2P.speed = 0;
	kajiki_2P.button = 0;
	kajiki_2P.button_flag = false;
	kajiki_2P.end_flag = false;

}
void Kajiki_Finalize(void)
{

}
void Kajiki_Update_1P(void)
{
	//プレイヤー
	if (Count_1P_Kajiki <= NOMAL_SCR)
	{
		Move_BG1_Kajiki += 1.0;
		Move_BG1_1P_Kajiki_ += GetSpeed_1P_Kajiki();
		Move_BG1_1P_Kajiki = (Move_BG1_Kajiki + Move_BG1_1P_Kajiki_);

		if (Move_BG1_Kajiki + Move_BG1_1P_Kajiki_ > (SCREEN_HEIGHT + 150))
		{
			Move_BG1_Kajiki = 150;
			Move_BG1_1P_Kajiki_ = 150;
			Count_1P_Kajiki++;
		}
		if (Move_BG1_1P_Kajiki > (SCREEN_HEIGHT * 2) + 300)
		{
			Move_BG1_1P_Kajiki = 300;

		}
	}
	else if (Count_1P_Kajiki >= END_SCR)
	{
		if (Move_BG1_1P_Kajiki_ + Move_BG1_Kajiki < (SCREEN_HEIGHT * 2 - 310))
		{
			Move_BG1_1P_Kajiki_ += GetSpeed_1P_Kajiki();
			Move_BG1_Kajiki += 0.1;
		}
		if (Move_BG1_1P_Kajiki < (SCREEN_HEIGHT * 2 - 310))
		{
			Move_BG1_1P_Kajiki = (Move_BG1_1P_Kajiki_ + Move_BG1_Kajiki);
		}
		else if (Move_BG1_1P_Kajiki > (SCREEN_HEIGHT * 2 - 310))
		{
			if (Goal_1P_Kajiki == false) {
				Time_Minute_1P_Kajiki = Timer_GetMinute();
				Time_Second_1P_Kajiki = Timer_GetSecond();
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
void Kajiki_Update_2P(void)
{
	//プレイヤー
	if (Count_2P_Kajiki <= NOMAL_SCR)
	{
		Move_BG2_Kajiki += 1.0;
		Move_BG_2P_Kajiki_ += GetSpeed_2P_Kajiki();
		Move_BG_2P_Kajiki = (Move_BG2_Kajiki + Move_BG_2P_Kajiki_);

		if (Move_BG2_Kajiki + Move_BG_2P_Kajiki_ > (SCREEN_HEIGHT + 150))
		{
			Move_BG2_Kajiki = 150;
			Move_BG_2P_Kajiki_ = 150;
			Count_2P_Kajiki++;
		}
		if (Move_BG_2P_Kajiki > (SCREEN_HEIGHT * 2) + 300)
		{
			Move_BG_2P_Kajiki = 300;

		}
	}
	else if (Count_2P_Kajiki >= END_SCR)
	{
		if (Move_BG_2P_Kajiki_ + Move_BG2_Kajiki < (SCREEN_HEIGHT * 2 - 310))
		{
			Move_BG_2P_Kajiki_ += GetSpeed_2P_Kajiki();
			Move_BG2_Kajiki += 0.1;
		}
		if (Move_BG_2P_Kajiki < (SCREEN_HEIGHT * 2 - 310))
		{
			Move_BG_2P_Kajiki = (Move_BG_2P_Kajiki_ + Move_BG2_Kajiki);
		}
		else if (Move_BG_2P_Kajiki > (SCREEN_HEIGHT * 2 - 310))
		{
			if (Goal_2P_Kajiki == false) {
				//PlaySound(SOUND_LABEL_SE_GOAL);
				Time_Minute_2P_Kajiki = Timer_GetMinute();
				Time_Second_2P_Kajiki = Timer_GetSecond();
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
void Kajiki_Draw_1P(void)
{
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 4), Move_BG1_1P_Kajiki_ + Move_BG1_Kajiki, (SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT);
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 4), (-SCREEN_HEIGHT + 150) + Move_BG1_1P_Kajiki_ + Move_BG1_Kajiki, (SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT - 50);
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 4), ((-SCREEN_HEIGHT * 2) + 300) + Move_BG1_1P_Kajiki_, (SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT - 50);

	Sprite_Draw(TEXTURE_INDEX_KAZIKI_ANIMATION, kajiki.pos.x, kajiki.pos.y, g_animCount * 100, 0, 100, 300);

	if (kajiki.button == 1 && kajiki.button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_A_BUTTON, 650, 50);
	}
	if (kajiki.button == 2 && kajiki.button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_B_BUTTON, 650, 50);
	}
	if (kajiki.button == 3 && kajiki.button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_X_BUTTON, 650, 50);
	}
	if (kajiki.button == 4 && kajiki.button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_Y_BUTTON, 650, 50);
	}

}
void Kajiki_Draw_2P(void)
{
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 2), Move_BG_2P_Kajiki_ + Move_BG2_Kajiki, (SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT);
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 2), (-SCREEN_HEIGHT + 150) + Move_BG_2P_Kajiki_ + Move_BG2_Kajiki, (SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT - 50);
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 2), ((-SCREEN_HEIGHT * 2) + 300) + Move_BG_2P_Kajiki_, (SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT - 50);

	Sprite_Draw(TEXTURE_INDEX_KAZIKI_ANIMATION, kajiki_2P.pos.x, kajiki_2P.pos.y, g_animCount * 100, 0, 100, 300);

	if (kajiki_2P.button == 1 && kajiki_2P.button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_A_BUTTON, 1175, 50);
	}
	if (kajiki_2P.button == 2 && kajiki_2P.button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_B_BUTTON, 1175, 50);
	}
	if (kajiki_2P.button == 3 && kajiki_2P.button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_X_BUTTON, 1175, 50);
	}
	if (kajiki_2P.button == 4 && kajiki_2P.button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_Y_BUTTON, 1175, 50);
	}

}

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
			kajiki.speed += 0.08;
			kajiki.button_flag = false;
		}
	}
	if (kajiki.button == 2 && kajiki.button_flag)
	{
		if (Keyboard_IsPress(DIK_RIGHT) || GamePad_IsPress(2, BUTTON_B))
		{
			kajiki.speed += 0.05;
			kajiki.button_flag = false;
		}
	}
	if (kajiki.button == 3 && kajiki.button_flag)
	{
		if (Keyboard_IsPress(DIK_DOWN) || GamePad_IsPress(2, BUTTON_X))
		{
			kajiki.speed += 0.03;
			kajiki.button_flag = false;
		}
	}
	if (kajiki.button == 4 && kajiki.button_flag)
	{
		if (Keyboard_IsPress(DIK_LEFT) || GamePad_IsPress(2, BUTTON_Y))
		{
			kajiki.speed += 0.01;
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
		if (Keyboard_IsPress(DIK_UP) || GamePad_IsPress(0, BUTTON_A))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			kajiki_2P.speed += 0.08;
			kajiki_2P.button_flag = false;
		}
	}
	if (kajiki_2P.button == 2 && kajiki_2P.button_flag)
	{
		if (Keyboard_IsPress(DIK_RIGHT) || GamePad_IsPress(0, BUTTON_B))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			kajiki_2P.speed += 0.05;
			kajiki_2P.button_flag = false;
		}
	}
	if (kajiki.button == 3 && kajiki.button_flag)
	{
		if (Keyboard_IsPress(DIK_DOWN) || GamePad_IsPress(0, BUTTON_X))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			kajiki_2P.speed += 0.03;
			kajiki_2P.button_flag = false;
		}
	}
	if (kajiki_2P.button == 4 && kajiki_2P.button_flag)
	{
		if (Keyboard_IsPress(DIK_LEFT) || GamePad_IsPress(0, BUTTON_Y))
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

bool Goal_Flag_1P_Kajiki()
{
	return Goal_1P_Kajiki;
}
bool Goal_Flag_2P_Kajiki()
{
	return Goal_2P_Kajiki;
}

float GetSpeed_1P_Kajiki()
{
	return kajiki.speed;
}
float GetSpeed_2P_Kajiki()
{
	return kajiki_2P.speed;
}

bool End_1P_Kajiki()
{
	return kajiki.end_flag;
}
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
