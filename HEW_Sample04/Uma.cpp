#include "Uma.h"
#include "main.h"
#include "input.h"
#include "timer.h"
#include "sprite.h"
#include "sound.h"

#define NOMAL_SCR		(1)	//コースの長さ
#define END_SCR			(NOMAL_SCR + 1)
#define ANIME_PATTERN_MAX	7

int Count_1P_Uma;
int Count_2P_Uma;
bool Goal_1P_Uma;
bool Goal_2P_Uma;
float Move_BG1_Uma;
float Move_BG_1P_Uma;
float Move_BG_1P_Uma_;
float Move_BG2;
float Move_BG2_2P_Uma;
float Move_BG2_2P_Uma_;
int Time_Minute_1P_Uma;
int Time_Second_1P_Uma;
int Time_Minute_2P_Uma;
int Time_Second_2P_Uma;
static int g_animCount;

Uma uma;
Uma_2P uma_2P;

void Uma_Initialize_1P(float x, float y)
{

	uma.pos.x = x;
	uma.pos.y = y;
	uma.speed = 0;
	uma.button = 0;
	uma.button_flag = false;
	uma.end_flag = false;
	g_animCount = 0;

}
void Uma_Initialize_2P(float x, float y)
{

	uma_2P.pos.x = x;
	uma_2P.pos.y = y;
	uma_2P.speed = 0;
	uma_2P.button = 0;
	uma_2P.button_flag = false;
	uma_2P.end_flag = false;
	g_animCount = 0;

}
void Uma_Finalize(void)
{

}
void Uma_Update_1P(void)
{
	//プレイヤー
	if (Count_1P_Uma <= NOMAL_SCR)
	{
		Move_BG1_Uma += 1.0;
		Move_BG_1P_Uma_ += GetSpeed_1P_Uma();
		Move_BG_1P_Uma = (Move_BG1_Uma + Move_BG_1P_Uma_);

		if (Move_BG1_Uma + Move_BG_1P_Uma_ > (SCREEN_HEIGHT + 150))
		{
			Move_BG1_Uma = 150;
			Move_BG_1P_Uma_ = 150;
			Count_1P_Uma++;
		}
		if (Move_BG_1P_Uma > (SCREEN_HEIGHT * 2) + 300)
		{
			Move_BG_1P_Uma = 300;

		}
	}
	else if (Count_1P_Uma >= END_SCR)
	{
		if (Move_BG_1P_Uma_ + Move_BG1_Uma < (SCREEN_HEIGHT * 2 - 310))
		{
			Move_BG_1P_Uma_ += GetSpeed_1P_Uma();
			Move_BG1_Uma += 0.1;
		}
		if (Move_BG_1P_Uma < (SCREEN_HEIGHT * 2 - 310))
		{
			Move_BG_1P_Uma = (Move_BG_1P_Uma_ + Move_BG1_Uma);
		}
		else if (Move_BG_1P_Uma > (SCREEN_HEIGHT * 2 - 310))
		{
			if (Goal_1P_Uma == false) {
				Time_Minute_1P_Uma = Timer_GetMinute();
				Time_Second_1P_Uma = Timer_GetSecond();
				PlaySound(SOUND_LABEL_SE_TIMEOUT);
			}
			Goal_1P_Uma = true;
		}
	}
	Uma_Button_1P();

	g_animCount += 1;

	if (g_animCount > ANIME_PATTERN_MAX)
	{
		g_animCount = 0;
	}

}
void Uma_Update_2P(void)
{
	//プレイヤー
	if (Count_2P_Uma <= NOMAL_SCR)
	{
		Move_BG2 += 1.0;
		Move_BG2_2P_Uma_ += GetSpeed_2P_Uma();
		Move_BG2_2P_Uma = (Move_BG2 + Move_BG2_2P_Uma_);

		if (Move_BG2 + Move_BG2_2P_Uma_ > (SCREEN_HEIGHT + 150))
		{
			Move_BG2 = 150;
			Move_BG2_2P_Uma_ = 150;
			Count_2P_Uma++;
		}
		if (Move_BG2_2P_Uma > (SCREEN_HEIGHT * 2) + 300)
		{
			Move_BG2_2P_Uma = 300;

		}
	}
	else if (Count_2P_Uma >= END_SCR)
	{
		if (Move_BG2_2P_Uma_ + Move_BG2 < (SCREEN_HEIGHT * 2 - 310))
		{
			Move_BG2_2P_Uma_ += GetSpeed_2P_Uma();
			Move_BG2 += 0.1;
		}
		if (Move_BG2_2P_Uma < (SCREEN_HEIGHT * 2 - 310))
		{
			Move_BG2_2P_Uma = (Move_BG2_2P_Uma_ + Move_BG2);
		}
		else if (Move_BG2_2P_Uma > (SCREEN_HEIGHT * 2 - 310))
		{
			if (Goal_2P_Uma == false) {
				Time_Minute_2P_Uma = Timer_GetMinute();
				Time_Second_2P_Uma = Timer_GetSecond();
				PlaySound(SOUND_LABEL_SE_TIMEOUT);
			}
			Goal_2P_Uma = true;
		}
	}
	Uma_Button_2P();

	g_animCount += 1;

	if (g_animCount > ANIME_PATTERN_MAX)
	{
		g_animCount = 0;
	}


}
void Uma_Draw_1P(void)
{
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 4), Move_BG_1P_Uma_ + Move_BG1_Uma, (SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT);
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 4), (-SCREEN_HEIGHT + 150) + Move_BG_1P_Uma_ + Move_BG1_Uma, (SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT - 50);
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 4), ((-SCREEN_HEIGHT * 2) + 300) + Move_BG_1P_Uma_, (SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT - 50);

	Sprite_Draw(TEXTURE_INDEX_UMA_ANIMATION, uma.pos.x, uma.pos.y, g_animCount * 100, 0, 100, 300);

	if (uma.button == 1 && uma.button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_A_BUTTON, 650, 80);
	}
	if (uma.button == 2 && uma.button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_B_BUTTON, 650, 80);
	}
	if (uma.button == 3 && uma.button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_X_BUTTON, 650, 80);
	}
	if (uma.button == 4 && uma.button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_Y_BUTTON, 650, 80);
	}

}
void Uma_Draw_2P(void)
{
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 2), Move_BG2_2P_Uma_ + Move_BG2, (SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT);
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 2), (-SCREEN_HEIGHT + 150) + Move_BG2_2P_Uma_ + Move_BG2, (SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT - 50);
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 2), ((-SCREEN_HEIGHT * 2) + 300) + Move_BG2_2P_Uma_, (SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT - 50);

	Sprite_Draw(TEXTURE_INDEX_UMA_ANIMATION, uma_2P.pos.x, uma_2P.pos.y, g_animCount * 100, 0, 100, 300);

	if (uma.button == 1 && uma.button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_A_BUTTON, 1175, 80);
	}
	if (uma.button == 2 && uma.button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_B_BUTTON, 1175, 80);
	}
	if (uma.button == 3 && uma.button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_X_BUTTON, 1175, 80);
	}
	if (uma.button == 4 && uma.button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_Y_BUTTON, 1175, 80);
	}

}

void Uma_Button_1P(void)
{
	D3DXVECTOR2 dir = D3DXVECTOR2(0.0f, 0.0f);

	if (uma.button_flag == false)
	{
		uma.button = rand() % 4 + 1;
		uma.button_flag = true;
	}
	if (uma.button == 1 && uma.button_flag)
	{
		if (Keyboard_IsPress(DIK_UP) || GamePad_IsPress(0, BUTTON_A))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			uma.speed += 0.08;
			uma.button_flag = false;
		}
	}
	if (uma.button == 2 && uma.button_flag)
	{
		if (Keyboard_IsPress(DIK_RIGHT) || GamePad_IsPress(0, BUTTON_B))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			uma.speed += 0.05;
			uma.button_flag = false;
		}
	}
	if (uma.button == 3 && uma.button_flag)
	{
		if (Keyboard_IsPress(DIK_DOWN) || GamePad_IsPress(0, BUTTON_X))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			uma.speed += 0.03;
			uma.button_flag = false;
		}
	}
	if (uma.button == 4 && uma.button_flag)
	{
		if (Keyboard_IsPress(DIK_LEFT) || GamePad_IsPress(0, BUTTON_Y))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			uma.speed += 0.01;
			uma.button_flag = false;
		}
	}
	if (Goal_Flag_1P_Uma())
	{
		if (uma.pos.y > 20)
		{
			uma.pos.y -= uma.speed;
		}
	}
	if (Goal_Flag_1P_Uma())
	{
		if (uma.pos.y > 25)
		{
			uma.pos.y -= 1.0;
		}
		else
		{
			uma.end_flag = true;
		}
	}

	// 座標の更新処理
	uma.pos += dir;

}
void Uma_Button_2P(void)
{
	D3DXVECTOR2 dir = D3DXVECTOR2(0.0f, 0.0f);

	if (uma_2P.button_flag == false)
	{
		uma_2P.button = rand() % 4 + 1;
		uma_2P.button_flag = true;
	}
	if (uma_2P.button == 1 && uma_2P.button_flag)
	{
		if (Keyboard_IsPress(DIK_UP) || GamePad_IsPress(2, BUTTON_A))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			uma_2P.speed += 0.08;
			uma_2P.button_flag = false;
		}
	}
	if (uma_2P.button == 2 && uma_2P.button_flag)
	{
		if (Keyboard_IsPress(DIK_RIGHT) || GamePad_IsPress(2, BUTTON_B))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			uma_2P.speed += 0.05;
			uma_2P.button_flag = false;
		}
	}
	if (uma.button == 3 && uma.button_flag)
	{
		if (Keyboard_IsPress(DIK_DOWN) || GamePad_IsPress(2, BUTTON_X))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			uma_2P.speed += 0.03;
			uma_2P.button_flag = false;
		}
	}
	if (uma_2P.button == 4 && uma_2P.button_flag)
	{
		if (Keyboard_IsPress(DIK_LEFT) || GamePad_IsPress(2, BUTTON_Y))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			uma_2P.speed += 0.01;
			uma_2P.button_flag = false;
		}
	}
	if (Goal_Flag_2P_Uma())
	{
		if (uma_2P.pos.y > 20)
		{
			uma_2P.pos.y -= uma_2P.speed;
		}
	}
	if (Goal_Flag_2P_Uma())
	{
		if (uma_2P.pos.y > 25)
		{
			uma_2P.pos.y -= 1.0;
		}
		else
		{
			uma_2P.end_flag = true;
		}
	}

	// 座標の更新処理
	uma_2P.pos += dir;

}

bool Goal_Flag_1P_Uma()
{
	return Goal_1P_Uma;
}
bool Goal_Flag_2P_Uma()
{
	return Goal_2P_Uma;
}

float GetSpeed_1P_Uma()
{
	return uma.speed;
}
float GetSpeed_2P_Uma()
{
	return uma_2P.speed;
}

bool End_1P_Uma()
{
	return uma.end_flag;
}
bool End_2P_Uma()
{
	return uma_2P.end_flag;
}

int	Minute_1P_Uma()
{
	return Time_Minute_1P_Uma;
}
int	Minute_2P_Uma()
{
	return Time_Minute_2P_Uma;
}

int Second_1P_Uma()
{
	return Time_Second_1P_Uma;
}
int Second_2P_Uma()
{
	return Time_Second_2P_Uma;
}
