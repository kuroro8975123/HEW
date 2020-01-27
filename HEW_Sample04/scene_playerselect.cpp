#include "main.h"
#include "input.h"
#include "scene.h"
#include "sprite.h"
#include "texture.h"
#include "fade.h"
<<<<<<< HEAD
#include "enemy.h"
=======

#include "enemy.h"

>>>>>>> c18442c46a1f60fd0983b31cee829280e386b306
#include "scene_playerselect.h"

int Select_1P;
int Select_2P;
int Select_Count;
int frame;
bool Select;
bool Left;
bool Right;

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
	kaziki.pos.x = 450;
	kaziki.pos.y = 100;
	kaziki.flag = true;
	kuzira.pos.x = 450 + SCREEN_WIDTH;
	kuzira.pos.y = 100;
	kuzira.flag = false;
	iruka.pos.x = (450 + (SCREEN_WIDTH * 2));
	iruka.pos.y = 100;
	iruka.flag = false;
	uma.pos.x = (450 + (SCREEN_WIDTH * 3));
	uma.pos.y = 100;
	uma.flag = false;
	Select = false;
	Left = false;
	Right = false;
}

void P_Select_Finalize(void)
{
}

void P_Select_Update(void)
{
	if (kaziki.flag)
	{
		if (Keyboard_IsTrigger(DIK_Y) || GamePad_IsTrigger(2, BUTTON_LB))
		{
			Left = true;
		}
		if (Keyboard_IsTrigger(DIK_Y) || GamePad_IsPress(2, BUTTON_RB))
		{

		}

	}
	if (Left)
	{
		if (kuzira.pos.x > 550)
		{
			kaziki.pos.x -= 25;
			kuzira.pos.x -= 25;
			iruka.pos.x -= 25;
			uma.pos.x -= 25;
		}
		else
		{
			Left = false;
		}
	}

	if (Select_Count == 2)
	{
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

