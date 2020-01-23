#include "input.h"
#include "scene.h"
#include "sprite.h"
#include "texture.h"
#include "fade.h"
#include "enemy.h"
#include "player.h"
#include "scene_playerselect.h"

int Select_1P;
int Select_2P;
int Select_Count;
void P_Select_Initialize(void)
{
	Fade_Start(false, 90, D3DCOLOR_RGBA(0, 0, 0, 0));
	Select_1P = 0;
	Select_2P = 0;
	Select_Count = 0;
}

void P_Select_Finalize(void)
{
}

void P_Select_Update(void)
{
	

	if (Keyboard_IsTrigger(DIK_A)) //カジキ
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
	if (Keyboard_IsTrigger(DIK_B)) //クジラ
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
	if (Keyboard_IsTrigger(DIK_X)) //イルカ
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
	if (Keyboard_IsTrigger(DIK_Y)) //馬
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
	if (Select_Count == 2)
	{
		Scene_Change(SCENE_INDEX_GAME);
	}
}

void P_Select_Draw(void)
{
	
	Sprite_Draw(TEXTURE_INDEX_POOL, 0.0f, 0.0f);
	//Sprite_Draw(TEXTURE_INDEX_CHARASELE, 0.0f, 0.0f);
	Sprite_Draw(TEXTURE_INDEX_CHARASEN, 150.0f, -80.0f);

	Sprite_Draw(TEXTURE_INDEX_KAZIKI, 184.0f, 200.0f);		//カジキ
	Sprite_Draw(TEXTURE_INDEX_KUZIRA, 352.0f, 200.0f);		//クジラ
	Sprite_Draw(TEXTURE_INDEX_IRUKA, 600.0f, 200.0f);		//イルカ
	Sprite_Draw(TEXTURE_INDEX_UMA, 784.0f, 240.0f);			//馬

	Sprite_Draw(TEXTURE_INDEX_A_BUTTON, 215, 450);
	Sprite_Draw(TEXTURE_INDEX_B_BUTTON, 415, 450);
	Sprite_Draw(TEXTURE_INDEX_X_BUTTON, 615, 450);
	Sprite_Draw(TEXTURE_INDEX_Y_BUTTON, 815, 450);
}

int Get_Select_1P()
{
	return Select_1P;
}

int Get_Select_2P()
{
	return Select_2P;
}

