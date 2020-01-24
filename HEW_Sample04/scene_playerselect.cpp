#include "main.h"
#include "input.h"
#include "scene.h"
#include "sprite.h"
#include "texture.h"
#include "fade.h"

#include "enemy.h"

#include "scene_playerselect.h"

int Select_1P;
int Select_2P;
int Select_Count;
float move_x;
float move_y;
float move;
bool Select;
bool Left;
bool Right;

D3DXVECTOR2 SelectPos;

void P_Select_Initialize(void)
{
	Fade_Start(false, 90, D3DCOLOR_RGBA(0, 0, 0, 0));
	Select_1P = 0;
	Select_2P = 0;
	Select_Count = 0;
	SelectPos.x = 450;
    SelectPos.y = 100;
	move_x = 0;
	move_y = 0;
	move = 0;
	Select = false;
	Left = false;
	Right = false;
}

void P_Select_Finalize(void)
{
}

void P_Select_Update(void)
{
	

	if (Keyboard_IsTrigger(DIK_A) || GamePad_IsPress(2, BUTTON_A)) //カジキ
	{
		if (Select_Count == 0)
		{
			Select_1P = 1;
			Select_Count++;
		}
		else if (Select_Count == 1)
		{
			Select_2P = 1;
			Select_Count++;
		}
	}
	if (Keyboard_IsTrigger(DIK_B) || GamePad_IsPress(2, BUTTON_B)) //クジラ
	{
		if (Select_Count == 0)
		{
			Select_1P = 2;
			Select_Count++;
		}
		else if (Select_Count == 1)
		{
			Select_2P = 2;
			Select_Count++;
		}

	}
	if (Keyboard_IsTrigger(DIK_X) || GamePad_IsPress(2, BUTTON_X)) //イルカ
	{
		if (Select_Count == 0)
		{
			Select_1P = 3;
			Select_Count++;
		}
		else if (Select_Count == 1)
		{
			Select_2P = 3;
			Select_Count++;
		}

	}
	if (Keyboard_IsTrigger(DIK_Y) || GamePad_IsPress(2, BUTTON_Y)) //馬
	{
		if (Select_Count == 0)
		{
			Select_1P = 4;
			Select_Count++;
		}
		else if (Select_Count == 1)
		{
			Select_2P = 4;
			Select_Count++;
		}

	}
	if (Keyboard_IsTrigger(DIK_Y) || GamePad_IsPress(2, BUTTON_LB))
	{		
		//for (; move_x < SCREEN_WIDTH;)
		//{
			move_x += 1.5;
		//}

		//Left = true;
	}
	if (Keyboard_IsTrigger(DIK_Y) || GamePad_IsPress(2, BUTTON_RB))
	{	
		//for (; move_x > -SCREEN_WIDTH;)
		//{
			move_x -= 1.5;
		//	//move += move_x;
		//}

		//Right = true;
	}
	//if (Right)
	//{
	//	Right = false;
	//	//move_x = 0;
	//}
	//if (Left)
	//{
	//
	//	Left = false;
	//	//move_x = 0;
	//}
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
	
	Sprite_Draw(TEXTURE_INDEX_KAZIKI_SELECT, SelectPos.x + move_x, SelectPos.y);
	Sprite_Draw(TEXTURE_INDEX_KUJIRA_SELECT, SelectPos.x + SCREEN_WIDTH + move_x, SelectPos.y);
	Sprite_Draw(TEXTURE_INDEX_IRUKA_SELECT, SelectPos.x + SCREEN_WIDTH * 2 + move_x, SelectPos.y);
	Sprite_Draw(TEXTURE_INDEX_UMA_SELECT, SelectPos.x + SCREEN_WIDTH * 3 + move_x, SelectPos.y);

}

void Move()
{
	if (move_x < SCREEN_WIDTH)
	{
		move_x += 1.5;
	}
}

void Move_()
{
	if (move_x > -SCREEN_WIDTH)
	{
		move_x -= 1.5;
	}
}

int Get_Select_1P()
{
	return Select_1P;
}

int Get_Select_2P()
{
	return Select_2P;
}

