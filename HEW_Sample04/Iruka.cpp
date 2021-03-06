#include "Iruka.h"
#include "main.h"
#include "input.h"
#include "timer.h"
#include "sprite.h"
#include "sound.h"

#define NOMAL_SCR		(1)	//コースの長さ
#define END_SCR			(NOMAL_SCR + 1)
#define ANIME_PATTERN_MAX	7
#define MAX_SPEED       (10000)

int Count_1P_Iruka;
int Count_2P_Iruka;
bool Goal_1P_Iruka;
bool Goal_2P_Iruka;
float Move_BG1_Iruka; 
float Move_BG_1P_Iruka;
float Move_BG_1P_Iruka_;
float Move_BG2_Iruka;
float Move_BG_2P_Iruka;
float Move_BG_2P_Iruka_;
int Time_Minute_1P_Iruka;
int Time_Second_1P_Iruka;
int Time_Minute_2P_Iruka;
int Time_Second_2P_Iruka;
static int g_animCount;

static float Speed_Button;
static float Speed;
static float END;

static float Speed_Button_2P;
static float Speed_2P;
static float END_2P;
static float Start;


Iruka iruka;
Iruka_2P iruka_2P;

void Iruka_Initialize_1P(float x, float y)
{

	iruka.pos.x = x;
	iruka.pos.y = y;
	iruka.speed = 0;
	iruka.button = 0;
	iruka.button_flag = false;
	iruka.end_flag = false;
	g_animCount = 0;
	Count_1P_Iruka = 0;
	Move_BG1_Iruka = 0;
	Move_BG_1P_Iruka = 0;
	Move_BG_1P_Iruka_ = 0;
	Goal_1P_Iruka = false;
	Speed = 0;
	Speed_Button = 0;
	END = 0;
	Start = 0;

}
void Iruka_Initialize_2P(float x, float y)
{

	iruka_2P.pos.x = x;
	iruka_2P.pos.y = y;
	iruka_2P.speed = 0;
	iruka_2P.button = 0;
	iruka_2P.button_flag = false;
	iruka_2P.end_flag = false;
	g_animCount = 0;
	Count_2P_Iruka = 0;
	Move_BG2_Iruka = 0;
	Move_BG_2P_Iruka = 0;
	Move_BG_2P_Iruka_ = 0;
	Goal_2P_Iruka = false;
	Speed_2P = 0;
	Speed_Button_2P = 0;
	END_2P = 0;


}
void Iruka_Finalize(void)
{

}
void Iruka_Update_1P(void)
{
	//プレイヤー
	if ((Speed_Button + Speed) <= MAX_SPEED)
	{
		Speed += 1.0;
		Speed_Button += GetSpeed_1P_Iruka();
		END = (Speed + Speed_Button);

		Move_BG1_Iruka += 1.0;
		Move_BG_1P_Iruka_ += GetSpeed_1P_Iruka();
		Move_BG_1P_Iruka = (Move_BG1_Iruka + Move_BG_1P_Iruka_);

		if (Move_BG1_Iruka + Move_BG_1P_Iruka_ > (SCREEN_HEIGHT + 250))
		{
			Move_BG1_Iruka = 250;
			Move_BG_1P_Iruka_ = 250;
			Count_1P_Iruka++;
		}
		if (Move_BG_1P_Iruka > (SCREEN_HEIGHT * 2) +500)
		{
			Move_BG_1P_Iruka = 500;

		}
	}
	else
	{
		Speed += 1.0;
		Speed_Button += GetSpeed_1P_Iruka();
		END = (Speed + Speed_Button);

		if (Move_BG_1P_Iruka_ + Move_BG1_Iruka < (SCREEN_HEIGHT * 2 - 510))
		{
			Move_BG_1P_Iruka_ += GetSpeed_1P_Iruka();
			Move_BG1_Iruka += 1.1;
		}
		if (Move_BG_1P_Iruka < (SCREEN_HEIGHT * 2 - 510))
		{
			Move_BG_1P_Iruka = (Move_BG_1P_Iruka_ + Move_BG1_Iruka);
		}
		else if (Move_BG_1P_Iruka > (SCREEN_HEIGHT * 2 - 510))
		{
			if (Goal_1P_Iruka == false) {
				Time_Minute_1P_Iruka = Timer_GetMinute();
				Time_Second_1P_Iruka = Timer_GetSecond();
				PlaySound(SOUND_LABEL_SE_TIMEOUT);
			}
			Goal_1P_Iruka = true;
		}
	}
	Iruka_Button_1P();
	
	g_animCount += 1;

	if (g_animCount > ANIME_PATTERN_MAX)
	{
		g_animCount = 0;
	}

}
void Iruka_Update_2P(void)
{
	//プレイヤー
	if ((Speed_Button_2P + Speed_2P) <= MAX_SPEED)
	{
		Speed_2P += 1.0;
		Speed_Button_2P += GetSpeed_2P_Iruka();
		END_2P = (Speed_2P + Speed_Button_2P);

		Move_BG2_Iruka += 1.0;
		Move_BG_2P_Iruka_ += GetSpeed_2P_Iruka();
		Move_BG_2P_Iruka = (Move_BG2_Iruka + Move_BG_2P_Iruka_);

		if (Move_BG2_Iruka + Move_BG_2P_Iruka_ > (SCREEN_HEIGHT + 250))
		{
			Move_BG2_Iruka = 250;
			Move_BG_2P_Iruka_ = 250;
			Count_2P_Iruka++;
		}
		if (Move_BG_2P_Iruka > (SCREEN_HEIGHT * 2) + 500)
		{
			Move_BG_2P_Iruka = 500;

		}
	}
	else 
	{
		Speed_2P += 1.0;
		Speed_Button_2P += GetSpeed_2P_Iruka();
		END_2P = (Speed_2P + Speed_Button_2P);

		if (Move_BG_2P_Iruka_ + Move_BG2_Iruka < (SCREEN_HEIGHT * 2 - 510))
		{
			Move_BG_2P_Iruka_ += GetSpeed_2P_Iruka();
			Move_BG2_Iruka += 1.1;
		}
		if (Move_BG_2P_Iruka < (SCREEN_HEIGHT * 2 - 510))
		{
			Move_BG_2P_Iruka = (Move_BG_2P_Iruka_ + Move_BG2_Iruka);
		}
		else if (Move_BG_2P_Iruka > (SCREEN_HEIGHT * 2 - 510))
		{
			if (Goal_2P_Iruka == false) {
				Time_Minute_2P_Iruka = Timer_GetMinute();
				Time_Second_2P_Iruka = Timer_GetSecond();
				PlaySound(SOUND_LABEL_SE_TIMEOUT);
			}
			Goal_2P_Iruka = true;
		}
	}
	Iruka_Button_2P();
	
	g_animCount += 1;

	if (g_animCount > ANIME_PATTERN_MAX)
	{
		g_animCount = 0;
	}

}
void Iruka_Draw_1P(void)
{
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 4), Move_BG_1P_Iruka_ + Move_BG1_Iruka, (SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT);
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 4), (-SCREEN_HEIGHT + 250) + Move_BG_1P_Iruka_ + Move_BG1_Iruka,  (SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT - 50);
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 4), ((-SCREEN_HEIGHT * 2) + 500) + Move_BG_1P_Iruka_ + Move_BG1_Iruka, (SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT - 50);
	
	if (END < SCREEN_HEIGHT)
	{
		Sprite_Draw(TEXTURE_INDEX_START_GOAL, 0, END + 500);
	}
	Sprite_Draw(TEXTURE_INDEX_1P, iruka.pos.x - 15, iruka.pos.y + 250);
	
	if (!Goal_1P_Iruka)
	{

		Sprite_Draw(TEXTURE_INDEX_IRUKA_ANIMATION, iruka.pos.x, iruka.pos.y, g_animCount * 100, 0, 100, 300);


		if (iruka.button == 1 && iruka.button_flag)
		{
			Sprite_Draw(TEXTURE_INDEX_A_BUTTON, 660, 890);
		}
		if (iruka.button == 2 && iruka.button_flag)
		{
			Sprite_Draw(TEXTURE_INDEX_B_BUTTON, 660, 890);
		}
		if (iruka.button == 3 && iruka.button_flag)
		{
			Sprite_Draw(TEXTURE_INDEX_X_BUTTON, 660, 890);
		}
		if (iruka.button == 4 && iruka.button_flag)
		{
			Sprite_Draw(TEXTURE_INDEX_Y_BUTTON, 660, 890);
		}
	}
	else
	{
		Sprite_Draw(TEXTURE_INDEX_IRUKA_ANIMATION, iruka.pos.x, iruka.pos.y, 0, 0, 100, 300);
	}
}
void Iruka_Draw_2P(void)
{
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 2), Move_BG_2P_Iruka_ + Move_BG2_Iruka, (SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT);
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 2), (-SCREEN_HEIGHT + 250) + Move_BG_2P_Iruka_ + Move_BG2_Iruka,  (SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT - 50);
	Sprite_Draw(TEXTURE_INDEX_GAME, (SCREEN_WIDTH / 2), ((-SCREEN_HEIGHT * 2) + 500) + Move_BG_2P_Iruka_ + Move_BG2_Iruka, (SCREEN_WIDTH / 2), 0.0f, (SCREEN_WIDTH / 4), SCREEN_HEIGHT - 50);
	if (END_2P < SCREEN_HEIGHT)
	{
		Sprite_Draw(TEXTURE_INDEX_START_GOAL, SCREEN_WIDTH / 2, END_2P + 500);
	}
	Sprite_Draw(TEXTURE_INDEX_2P, iruka_2P.pos.x - 10, iruka_2P.pos.y + 250);
	if (!Goal_2P_Iruka)
	{

		Sprite_Draw(TEXTURE_INDEX_IRUKA_ANIMATION, iruka_2P.pos.x, iruka_2P.pos.y, g_animCount * 100, 0, 100, 300);

		if (iruka_2P.button == 1 && iruka_2P.button_flag)
		{
			Sprite_Draw(TEXTURE_INDEX_A_BUTTON, 1140, 890);
		}
		if (iruka_2P.button == 2 && iruka_2P.button_flag)
		{
			Sprite_Draw(TEXTURE_INDEX_B_BUTTON, 1140, 890);
		}
		if (iruka_2P.button == 3 && iruka_2P.button_flag)
		{
			Sprite_Draw(TEXTURE_INDEX_X_BUTTON, 1140, 890);
		}
		if (iruka_2P.button == 4 && iruka_2P.button_flag)
		{
			Sprite_Draw(TEXTURE_INDEX_Y_BUTTON, 1140, 890);
		}
	}
	else
	{
		Sprite_Draw(TEXTURE_INDEX_IRUKA_ANIMATION, iruka_2P.pos.x, iruka_2P.pos.y, 0, 0, 100, 300);
	}
}

void Iruka_Button_1P(void)
{
	D3DXVECTOR2 dir = D3DXVECTOR2(0.0f, 0.0f);

	if (iruka.button_flag == false)
	{
		iruka.button = rand() % 4 + 1;
		iruka.button_flag = true;
	}
	if (iruka.button == 1 && iruka.button_flag)
	{
		if (Keyboard_IsPress(DIK_UP) || GamePad_IsPress(0, BUTTON_A))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			iruka.speed += 0.08;
			iruka.button_flag = false;
		}
	}
	if (iruka.button == 2 && iruka.button_flag)
	{
		if (Keyboard_IsPress(DIK_RIGHT) || GamePad_IsPress(0, BUTTON_B))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			iruka.speed += 0.05;
			iruka.button_flag = false;
		}
	}
	if (iruka.button == 3 && iruka.button_flag)
	{
		if (Keyboard_IsPress(DIK_DOWN) || GamePad_IsPress(0, BUTTON_X))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			iruka.speed += 0.03;
			iruka.button_flag = false;
		}
	}
	if (iruka.button == 4 && iruka.button_flag)
	{
		if (Keyboard_IsPress(DIK_LEFT) || GamePad_IsPress(0, BUTTON_Y))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			iruka.speed += 0.01;
			iruka.button_flag = false;
		}
	}
	if (Goal_Flag_1P_Iruka())
	{
		if (iruka.pos.y > 20)
		{
			iruka.pos.y -= iruka.speed;
		}
	}
	if (Goal_Flag_1P_Iruka())
	{
		if (iruka.pos.y > 25)
		{
			iruka.pos.y -= 1.0;
		}
		else
		{
			iruka.end_flag = true;
		}
	}

	// 座標の更新処理
	iruka.pos += dir;

}
void Iruka_Button_2P(void)
{
	D3DXVECTOR2 dir = D3DXVECTOR2(0.0f, 0.0f);

	if (iruka_2P.button_flag == false)
	{
		iruka_2P.button = rand() % 4 + 1;
		iruka_2P.button_flag = true;
	}
	if (iruka_2P.button == 1 && iruka_2P.button_flag)
	{
		if (Keyboard_IsPress(DIK_UP) || GamePad_IsPress(0, BUTTON_A))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			iruka_2P.speed += 0.08;
			iruka_2P.button_flag = false;
		}
	}
	if (iruka_2P.button == 2 && iruka_2P.button_flag)
	{
		if (Keyboard_IsPress(DIK_RIGHT) || GamePad_IsPress(0, BUTTON_B))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			iruka_2P.speed += 0.05;
			iruka_2P.button_flag = false;
		}
	}
	if (iruka_2P.button == 3 && iruka_2P.button_flag)
	{
		if (Keyboard_IsPress(DIK_DOWN) || GamePad_IsPress(0, BUTTON_X))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			iruka_2P.speed += 0.03;
			iruka_2P.button_flag = false;
		}
	}
	if (iruka_2P.button == 4 && iruka_2P.button_flag)
	{
		if (Keyboard_IsPress(DIK_LEFT) || GamePad_IsPress(0, BUTTON_Y))
		{
			PlaySound(SOUND_LABEL_SE_ATARI);
			iruka_2P.speed += 0.01;
			iruka_2P.button_flag = false;
		}
	}
	if (Goal_Flag_2P_Iruka())
	{
		if (iruka_2P.pos.y > 20)
		{
			iruka_2P.pos.y -= iruka_2P.speed;
		}
	}
	if (Goal_Flag_2P_Iruka())
	{
		if (iruka_2P.pos.y > 25)
		{
			iruka_2P.pos.y -= 1.0;
		}
		else
		{
			iruka_2P.end_flag = true;
		}
	}

	// 座標の更新処理
	iruka_2P.pos += dir;

}

bool Goal_Flag_1P_Iruka()
{
	return Goal_1P_Iruka;
}
bool Goal_Flag_2P_Iruka()
{
	return Goal_2P_Iruka;
}

float GetSpeed_1P_Iruka()
{
	return iruka.speed;
}
float GetSpeed_2P_Iruka()
{
	return iruka_2P.speed;
}

bool End_1P_Iruka()
{
	return iruka.end_flag;
}
bool End_2P_Iruka()
{
	return iruka_2P.end_flag;
}

int	Minute_1P_Iruka()
{
	return Time_Minute_1P_Iruka;
}
int	Minute_2P_Iruka()
{
	return Time_Minute_2P_Iruka;
}

int Second_1P_Iruka()
{
	return Time_Second_1P_Iruka;
}
int Second_2P_Iruka()
{
	return Time_Second_2P_Iruka;
}

float Iruka_Speed_1P()
{
	return END;
}
float Iruka_Speed_2P()
{
	return END_2P;
}
