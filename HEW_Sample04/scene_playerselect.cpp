#include "main.h"
#include "input.h"
#include "scene.h"
#include "sprite.h"
#include "texture.h"
#include "fade.h"
#include "enemy.h"

#include "enemy.h"

#include "scene_playerselect.h"
#include "sound.h"

int Select_1P;
int Select_2P;
int Select_Count;
int frame;
bool Select;
bool Left;
bool Right;

bool oneP;

Select_Kaziki kaziki;
Select_Kujira kuzira;
Select_Iruka iruka;
Select_Uma uma;

void P_Select_Initialize(void)
{
	Fade_Start(false, 90, D3DCOLOR_RGBA(0, 0, 0, 0));
	Select_1P = 0;
	Select_2P = 0;
	Select_Count = 0;
	kaziki.pos.x = 200;
	kaziki.pos.y = 0;
	kaziki.flag = true;
	kuzira.pos.x = 100 + SCREEN_WIDTH;
	kuzira.pos.y = 0;
	kuzira.flag = false;
	iruka.pos.x = (150 + (SCREEN_WIDTH * 2));
	iruka.pos.y = -50;
	iruka.flag = false;
	uma.pos.x = (200 + (SCREEN_WIDTH * 3));
	uma.pos.y = 0;
	uma.flag = false;
	Select = false;
	Left = false;
	Right = false;
	oneP = false;
}

void P_Select_Finalize(void)
{
}

void P_Select_Update(void)
{
	if (kaziki.flag)
	{
		//if (Keyboard_IsTrigger(DIK_Y) || GamePad_IsTrigger(2, BUTTON_LB))
		//{
		//}
		if (Keyboard_IsTrigger(DIK_E) || GamePad_IsPress(2, BUTTON_RB))
		{
			PlaySound(SOUND_LABEL_SE_KASORU);
			Left = true;
		}
		if (Left)
		{
<<<<<<< HEAD
			//if (kuzira.pos.x >= 550)
=======
>>>>>>> 37ffc62761056abfff0589254b4282c60930ebe5
			if (kuzira.pos.x > 300)
			{
				kaziki.pos.x -= 50;
				kuzira.pos.x -= 50;
				iruka.pos.x -= 50;
				uma.pos.x -= 50;
			}
			else
			{
				Left = false;
				kaziki.flag = false;
				kuzira.flag = true;
			}
		}
	}
	if (kuzira.flag)
	{
		if (Keyboard_IsTrigger(DIK_Q) || GamePad_IsTrigger(2, BUTTON_LB))
		{
			PlaySound(SOUND_LABEL_SE_KASORU);
			Right = true;

		}
		if (Keyboard_IsTrigger(DIK_E) || GamePad_IsPress(2, BUTTON_RB))
		{
			PlaySound(SOUND_LABEL_SE_KASORU);
			Left = true;
		}
		if (Left)
		{
			if (iruka.pos.x >= 200)
			{
				kaziki.pos.x -= 50;
				kuzira.pos.x -= 50;
				iruka.pos.x -= 50;
				uma.pos.x -= 50;
			}
			else
			{
				Left = false;
				kuzira.flag = false;
				iruka.flag = true;
			}
		}
		if (Right)
		{
			if (kaziki.pos.x <= 200)
			{
				kaziki.pos.x += 50;
				kuzira.pos.x += 50;
				iruka.pos.x += 50;
				uma.pos.x += 50;

			}
			else
			{
				Right = false;
				kuzira.flag = false;
				kaziki.flag = true;
			}
		}
	}
	if (iruka.flag)
	{
		if (Keyboard_IsTrigger(DIK_Q) || GamePad_IsTrigger(2, BUTTON_LB))
		{
			PlaySound(SOUND_LABEL_SE_KASORU);
			Right = true;

		}
		if (Keyboard_IsTrigger(DIK_E) || GamePad_IsPress(2, BUTTON_RB))
		{
			PlaySound(SOUND_LABEL_SE_KASORU);
			Left = true;
		}
		if (Left)
		{
			if (uma.pos.x >= 300)
			{
				kaziki.pos.x -= 50;
				kuzira.pos.x -= 50;
				iruka.pos.x -= 50;
				uma.pos.x -= 50;
			}
			else
			{
				Left = false;
				iruka.flag = false;
				uma.flag = true;
			}
		}
		if (Right)
		{
			if (kuzira.pos.x <= 300)
			{
				kaziki.pos.x += 50;
				kuzira.pos.x += 50;
				iruka.pos.x += 50;
				uma.pos.x += 50;

			}
			else
			{
				Right = false;
				iruka.flag = false;
				kuzira.flag = true;
			}
		}
	}
	if (uma.flag)
	{
		if (Keyboard_IsTrigger(DIK_Q) || GamePad_IsTrigger(2, BUTTON_LB))
		{
			PlaySound(SOUND_LABEL_SE_KASORU);
			Right = true;

		}
		if (Keyboard_IsTrigger(DIK_Y) || GamePad_IsPress(2, BUTTON_RB))
		{
		}
		if (Right)
		{
			if (iruka.pos.x < 200)
			{
				kaziki.pos.x += 50;
				kuzira.pos.x += 50;
				iruka.pos.x += 50;
				uma.pos.x += 50;
			}
			else
			{
				Right = false;
				uma.flag = false;
				iruka.flag = true;
			}
		}
	}


	if (!oneP)
	{
		if (Keyboard_IsTrigger(DIK_B) || GamePad_IsTrigger(2, BUTTON_A))
		{
			if (kaziki.flag)
			{
				PlaySound(SOUND_LABEL_SE_KETTEI);
				Select_1P = 1;
				Select_Count = 1;
				oneP = true;
			}
			else if (kuzira.flag)
			{
				PlaySound(SOUND_LABEL_SE_KETTEI);
				Select_1P = 2;
				Select_Count = 1;
				oneP = true;
			}
			else if (iruka.flag)
			{
				PlaySound(SOUND_LABEL_SE_KETTEI);
				Select_1P = 3;
				Select_Count = 1;
				oneP = true;
			}
			else if (uma.flag)
			{
				PlaySound(SOUND_LABEL_SE_KETTEI);
				Select_1P = 4;
				Select_Count = 1;
				oneP = true;
			}
		}
	}
	if (oneP)
	{
		if (Keyboard_IsTrigger(DIK_N) || GamePad_IsTrigger(2, BUTTON_B) && Select_Count == 1)
		{
			if (kaziki.flag)
			{
				PlaySound(SOUND_LABEL_SE_KETTEI);
				Select_2P = 1;
				Select_Count = 2;
			}
			else if (kuzira.flag)
			{
				PlaySound(SOUND_LABEL_SE_KETTEI);
				Select_2P = 2;
				Select_Count = 2;
			}
			else if (iruka.flag)
			{
				PlaySound(SOUND_LABEL_SE_KETTEI);
				Select_2P = 3;
				Select_Count = 2;
			}
			else if (uma.flag)
			{
				PlaySound(SOUND_LABEL_SE_KETTEI);
				Select_2P = 4;
				Select_Count = 2;
			}
		}
	}
	if (Select_Count == 2)
	{
		//Scene_Change(SCENE_INDEX_RESULT);
		Scene_Change(SCENE_INDEX_GAME);
	}
}

void P_Select_Draw(void)
{

	Sprite_Draw(TEXTURE_INDEX_POOL, 0.0f, 0.0f);
	Sprite_Draw(TEXTURE_INDEX_CHARASEN, 150.0f, -80.0f);

	Sprite_Draw(TEXTURE_INDEX_RIGHT, 1500.0f, 400.0f);
	Sprite_Draw(TEXTURE_INDEX_LEFT, 150.0f, 400.0f);

	Sprite_Draw(TEXTURE_INDEX_KAZIKI_SELECT, kaziki.pos.x, kaziki.pos.y);
	Sprite_Draw(TEXTURE_INDEX_KUJIRA_SELECT, kuzira.pos.x, kuzira.pos.y);
	Sprite_Draw(TEXTURE_INDEX_IRUKA_SELECT, iruka.pos.x, iruka.pos.y);
	Sprite_Draw(TEXTURE_INDEX_UMA_SELECT, uma.pos.x, uma.pos.y);
}


int Get_Select_1P()
{
	return Select_1P;
}

int Get_Select_2P()
{
	return Select_2P;
}

