#include "Kujira.h"
#include "main.h"
#include "input.h"
#include "timer.h"
#include "sprite.h"
#include "sound.h"

#define NOMAL_SCR		(1)	//コースの長さ
#define END_SCR			(NOMAL_SCR + 1)
#define ANIME_PATTERN_MAX	7

int Count_1P_Kujira;
int Count_2P_Kujira;
bool Goal_1P_Kujira;
bool Goal_2P_Kujira;
float Move_BG1_Kujira; 
float Move_BG_1P_Kujira;
float Move_BG_1P_Kujira_; 
float Move_BG2_Kujira;
float Move_BG2_2P_Kujira;
float Move_BG2_2P_Kujira_;
int Time_Minute_1P_Kujira;
int Time_Second_1P_Kujira;
int Time_Minute_2P_Kujira;
int Time_Second_2P_Kujira;
static int g_animCount;

Kujira kujira;
Kujira_2P kujira_2P;

void Kujira_Initialize_1P(float x, float y)
{

	kujira.pos.x = x;
	kujira.pos.y = y;
	kujira.speed = 0;
	kujira.button = 0;
	kujira.button_flag = false;
	kujira.end_flag = false;
	g_animCount = 0;

}
void Kujira_Initialize_2P(float x, float y)
{

	kujira_2P.pos.x = x;
	kujira_2P.pos.y = y;
	kujira_2P.speed = 0;
	kujira_2P.button = 0;
	kujira_2P.button_flag = false;
	kujira_2P.end_flag = false;
	g_animCount = 0;
}
void Kujira_Finalize(void)
{

}
void Kujira_Update_1P(void)
{
	//プレイヤー
	if (Count_1P_Kujira <= NOMAL_SCR)
	{
		Move_BG1_Kujira += 1.0;
		Move_BG_1P_Kujira_ += GetSpeed_1P_Kujira();
		Move_BG_1P_Kujira = (Move_BG1_Kujira + Move_BG_1P_Kujira_);

		if (Move_BG1_Kujira + Move_BG_1P_Kujira_ > (SCREEN_HEIGHT + 150))
		{
			Move_BG1_Kujira = 150;
			Move_BG_1P_Kujira_ = 150;
			Count_1P_Kujira++;
		}
		if (Move_BG_1P_Kujira > (SCREEN_HEIGHT * 2) + 300)
		{
			Move_BG_1P_Kujira = 300;

		}
	}
	else if (Count_1P_Kujira >= END_SCR)
	{
		if (Move_BG_1P_Kujira_ + Move_BG1_Kujira < (SCREEN_HEIGHT * 2 - 310))
		{
			Move_BG_1P_Kujira_ += GetSpeed_1P_Kujira();
			Move_BG1_Kujira += 0.1;
		}
		if (Move_BG_1P_Kujira < (SCREEN_HEIGHT * 2 - 310))
		{
			Move_BG_1P_Kujira = (Move_BG_1P_Kujira_ + Move_BG1_Kujira);
		}
		else if (Move_BG_1P_Kujira > (SCREEN_HEIGHT * 2 - 310))
		{
			if (Goal_1P_Kujira == false) {
				PlaySound(SOUND_LABEL_SE_TIMEOUT);
				Time_Minute_1P_Kujira = Timer_GetMinute();
				Time_Second_1P_Kujira = Timer_GetSecond();
			}
			Goal_1P_Kujira = true;
		}
	}
	Kujira_Button_1P();
	
	g_animCount += 1;

	if (g_animCount > ANIME_PATTERN_MAX)
	{
		g_animCount = 0;
	}

}
void Kujira_Update_2P(void)
{
	//プレイヤー
	if (Count_2P_Kujira <= NOMAL_SCR)
	{
		Move_BG2_Kujira += 2.0;
		Move_BG2_2P_Kujira_ += GetSpeed_2P_Kujira();
		Move_BG2_2P_Kujira = (Move_BG2_Kujira + Move_BG2_2P_Kujira_);

		if (Move_BG2_Kujira + Move_BG2_2P_Kujira_ > (SCREEN_HEIGHT + 150))
		{
			Move_BG2_Kujira = 150;
			Move_BG2_2P_Kujira_ = 150;
			Count_2P_Kujira++;
		}
		if (Move_BG2_2P_Kujira > (SCREEN_HEIGHT * 2) + 300)
		{
			Move_BG2_2P_Kujira = 300;

		}
	}
	else if (Count_2P_Kujira >= END_SCR)
	{
		if (Move_BG2_2P_Kujira_ + Move_BG2_Kujira < (SCREEN_HEIGHT * 2 - 310))
		{
			Move_BG2_2P_Kujira_ += GetSpeed_2P_Kujira();
			Move_BG2_Kujira += 0.1;
		}
		if (Move_BG2_2P_Kujira < (SCREEN_HEIGHT * 2 - 310))
		{
			Move_BG2_2P_Kujira = (Move_BG2_2P_Kujira_ + Move_BG2_Kujira);
		}
		else if (Move_BG2_2P_Kujira > (SCREEN_HEIGHT * 2 - 310))
		{
			if (Goal_2P_Kujira == false) {
				PlaySound(SOUND_LABEL_SE_TIMEOUT);
				Time_Minute_2P_Kujira = Timer_GetMinute();
				Time_Second_2P_Kujira = Timer_GetSecond();
			}
			Goal_2P_Kujira = true;
		}
	}
	Kujira_Button_2P();
	
	g_animCount += 1;

	if (g_animCount > ANIME_PATTERN_MAX)
	{
		g_animCount = 0;
	}

}
void Kujira_Draw_1P(void)
{
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 4), Move_BG_1P_Kujira_ + Move_BG1_Kujira, (SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT);
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 4), (-SCREEN_HEIGHT + 150) + Move_BG_1P_Kujira_ + Move_BG1_Kujira, (SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT - 50);
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 4), ((-SCREEN_HEIGHT * 2) + 300) + Move_BG_1P_Kujira_, (SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT - 50);
	
	Sprite_Draw(TEXTURE_INDEX_KUZIRA_ANIMATION, kujira.pos.x, kujira.pos.y, g_animCount * 100, 0, 100, 300);

	if (kujira.button == 1 && kujira.button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_A_BUTTON, 675, 50);
	}
	if (kujira.button == 2 && kujira.button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_B_BUTTON, 675, 50);
	}
	if (kujira.button == 3 && kujira.button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_X_BUTTON, 675, 50);
	}
	if (kujira.button == 4 && kujira.button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_Y_BUTTON, 675, 50);
	}

}
void Kujira_Draw_2P(void)
{
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 2), Move_BG2_2P_Kujira_ + Move_BG2_Kujira, (SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT);
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 2), (-SCREEN_HEIGHT + 150) + Move_BG2_2P_Kujira_ + Move_BG2_Kujira, (SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT - 50);
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 2), ((-SCREEN_HEIGHT * 2) + 300) + Move_BG2_2P_Kujira_, (SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT - 50);

	Sprite_Draw(TEXTURE_INDEX_KUZIRA_ANIMATION,kujira_2P.pos.x, kujira_2P.pos.y, g_animCount * 100, 0, 100, 300);

	if (kujira_2P.button == 1 && kujira.button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_A_BUTTON, 1175, 50);
	}
	if (kujira_2P.button == 2 && kujira.button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_B_BUTTON, 1175, 50);
	}
	if (kujira_2P.button == 3 && kujira.button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_X_BUTTON, 1175, 50);
	}
	if (kujira_2P.button == 4 && kujira.button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_Y_BUTTON, 1175, 50);
	}

}

void Kujira_Button_1P(void)
{
	D3DXVECTOR2 dir = D3DXVECTOR2(0.0f, 0.0f);

	if (kujira.button_flag == false)
	{
		kujira.button = rand() % 4 + 1;
		kujira.button_flag = true;
	}
	if (kujira.button == 1 && kujira.button_flag)
	{
		if (Keyboard_IsPress(DIK_UP) || GamePad_IsPress(0, BUTTON_A))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			kujira.speed += 0.08;
			kujira.button_flag = false;
		}
	}
	if (kujira.button == 2 && kujira.button_flag)
	{
		if (Keyboard_IsPress(DIK_RIGHT) || GamePad_IsPress(0, BUTTON_B))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			kujira.speed += 0.05;
			kujira.button_flag = false;
		}
	}
	if (kujira.button == 3 && kujira.button_flag)
	{
		if (Keyboard_IsPress(DIK_DOWN) || GamePad_IsPress(0, BUTTON_X))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			kujira.speed += 0.03;
			kujira.button_flag = false;
		}
	}
	if (kujira.button == 4 && kujira.button_flag)
	{
		if (Keyboard_IsPress(DIK_LEFT) || GamePad_IsPress(0, BUTTON_Y))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			kujira.speed += 0.01;
			kujira.button_flag = false;
		}
	}
	if (Goal_Flag_1P_Kujira())
	{
		if (kujira.pos.y > 20)
		{
			kujira.pos.y -= kujira.speed;
		}
	}
	if (Goal_Flag_1P_Kujira())
	{
		if (kujira.pos.y > 25)
		{
			kujira.pos.y -= 1.0;
		}
		else
		{
			kujira.end_flag = true;
		}
	}

	// 座標の更新処理
	kujira.pos += dir;

}
void Kujira_Button_2P(void)
{
	D3DXVECTOR2 dir = D3DXVECTOR2(0.0f, 0.0f);

	if (kujira_2P.button_flag == false)
	{
		kujira_2P.button = rand() % 4 + 1;
		kujira_2P.button_flag = true;
	}
	if (kujira_2P.button == 1 && kujira_2P.button_flag)
	{
		if (Keyboard_IsPress(DIK_UP) || GamePad_IsPress(0, BUTTON_A))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			kujira_2P.speed += 0.08;
			kujira_2P.button_flag = false;
		}
	}
	if (kujira_2P.button == 2 && kujira_2P.button_flag)
	{
		if (Keyboard_IsPress(DIK_RIGHT) || GamePad_IsPress(0, BUTTON_B))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			kujira_2P.speed += 0.05;
			kujira_2P.button_flag = false;
		}
	}
	if (kujira.button == 3 && kujira.button_flag)
	{
		if (Keyboard_IsPress(DIK_DOWN) || GamePad_IsPress(0, BUTTON_X))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			kujira_2P.speed += 0.03;
			kujira_2P.button_flag = false;
		}
	}
	if (kujira_2P.button == 4 && kujira_2P.button_flag)
	{
		if (Keyboard_IsPress(DIK_LEFT) || GamePad_IsPress(0, BUTTON_Y))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			kujira_2P.speed += 0.01;
			kujira_2P.button_flag = false;
		}
	}
	if (Goal_Flag_2P_Kujira())
	{
		if (kujira_2P.pos.y > 20)
		{
			kujira_2P.pos.y -= kujira_2P.speed;
		}
	}
	if (Goal_Flag_2P_Kujira())
	{
		if (kujira_2P.pos.y > 25)
		{
			kujira_2P.pos.y -= 1.0;
		}
		else
		{
			kujira_2P.end_flag = true;
		}
	}

	// 座標の更新処理
	kujira_2P.pos += dir;

}

bool Goal_Flag_1P_Kujira()
{
	return Goal_1P_Kujira;
}
bool Goal_Flag_2P_Kujira()
{
	return Goal_2P_Kujira;
}

float GetSpeed_1P_Kujira()
{
	return kujira.speed;
}
float GetSpeed_2P_Kujira()
{
	return kujira_2P.speed;
}

bool End_1P_Kujira()
{
	return kujira.end_flag;
}
bool End_2P_Kujira()
{
	return kujira_2P.end_flag;
}

int	Minute_1P_Kujira()
{
	return Time_Minute_1P_Kujira;
}
int	Minute_2P_Kujira()
{
	return Time_Minute_2P_Kujira;
}

int Second_1P_Kujira()
{
	return Time_Second_1P_Kujira;
}
int Second_2P_Kujira()
{
	return Time_Second_2P_Kujira;
}
