
#include "player.h"
#include "main.h"
#include "input.h"
#include "sprite.h"
#include "game.h"


#define PLAYER_WIDTH	(32)
#define PLAYER_HEIGHT	(32)

#define ANIME_PATTERN_MAX		3
#define ANIME_PATTERN_SKIPFRAME 8


typedef struct
{
	D3DXVECTOR2 pos;			//位置

	float       speed;          //スピード

}PLAYER;

PLAYER player;
int button;
bool button_flag;
bool end_flag;

void Player_Initialize(void)
{
	//プレイヤーの初期化
	player.pos.x = 100;
	player.pos.y = 500;
	player.speed = 0;
	button = 0;
	button_flag = false;
	end_flag = false;
}

void Player_Finalize(void)
{

}

void Player_Update(void)
{
	D3DXVECTOR2 dir = D3DXVECTOR2(0.0f, 0.0f);

	if (button_flag == false)
	{
		button = rand() % 4 + 1;
		button_flag = true;
	}
	if (button == 1 && button_flag)
	{
		if (Keyboard_IsPress(DIK_UP) || GamePad_IsPress(0, BUTTON_A))
		{
			player.speed += 0.08;
			button_flag = false;
		}
	}
	if (button == 2 && button_flag)
	{
		if (Keyboard_IsPress(DIK_RIGHT) || GamePad_IsPress(0, BUTTON_B))
		{
			player.speed += 0.05;
			button_flag = false;
		}
	}
	if (button == 3 && button_flag)
	{
		if (Keyboard_IsPress(DIK_DOWN) || GamePad_IsPress(0, BUTTON_X))
		{
			player.speed += 0.03;
			button_flag = false;
		}
	}
	if (button == 4 && button_flag)
	{
		if (Keyboard_IsPress(DIK_LEFT) || GamePad_IsPress(0, BUTTON_Y))
		{
			player.speed += 0.01;
			button_flag = false;
		}
	}
	if (Goal_Flag_P())
	{
		if (player.pos.y > 20)
		{
			player.pos.y -= player.speed;
		}
	}
	if (Goal_Flag_P())
	{
		if (player.pos.y > 25)
		{
			player.pos.y -= 1.0;
		}
		else
		{
			end_flag = true;
		}
	}

	// 座標の更新処理
	player.pos += dir;
}

void Player_Draw(void)
{
	Sprite_Draw(TEXTURE_INDEX_PLAYER,
		player.pos.x,
		player.pos.y);

	if (button == 1 && button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_BUTTON, 110, 50, 19, 220, 33, 33);
	}
	if (button == 2 && button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_BUTTON, 110, 50, 70, 220, 33, 33);
	}
	if (button == 3 && button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_BUTTON, 110, 50, 124, 220, 33, 33);
	}
	if (button == 4 && button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_BUTTON, 110, 50, 177, 220, 33, 33);
	}


}

float Player_GetSpeed()
{
	return player.speed;
}

bool Player_End()
{
	return end_flag;
}