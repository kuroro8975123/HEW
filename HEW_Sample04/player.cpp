
#include "player.h"
#include "main.h"
#include "input.h"
#include "sprite.h"
#include "game.h"


#define PLAYER_WIDTH	(32)
#define PLAYER_HEIGHT	(32)

#define ANIME_PATTERN_MAX		3
#define ANIME_PATTERN_SKIPFRAME 8


Character_main::Character_main() {

}
Character_main::Character_main(float x,float y) {
	//プレイヤーの初期化
	pos.x = x;
	pos.y = y;
	speed = 0;
	button = 0;
	button_flag = false;
	end_flag = false;

}
//デストラクタ
Character_main::~Character_main() {

}
//更新
void Character_main::Update() {
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
			speed += 0.08;
			button_flag = false;
		}
	}
	if (button == 2 && button_flag)
	{
		if (Keyboard_IsPress(DIK_RIGHT) || GamePad_IsPress(0, BUTTON_B))
		{
			speed += 0.05;
			button_flag = false;
		}
	}
	if (button == 3 && button_flag)
	{
		if (Keyboard_IsPress(DIK_DOWN) || GamePad_IsPress(0, BUTTON_X))
		{
			speed += 0.03;
			button_flag = false;
		}
	}
	if (button == 4 && button_flag)
	{
		if (Keyboard_IsPress(DIK_LEFT) || GamePad_IsPress(0, BUTTON_Y))
		{
			speed += 0.01;
			button_flag = false;
		}
	}
	if (Goal_Flag_P())
	{
		if (pos.y > 20)
		{
			pos.y -= speed;
		}
	}
	if (Goal_Flag_P())
	{
		if (pos.y > 25)
		{
			pos.y -= 1.0;
		}
		else
		{
			end_flag = true;
		}
	}

	// 座標の更新処理
	pos += dir;
}
//描画
void Character_main::Draw() {

	/*--------------------------------------------------------
	提出用にカジキにしてあります。
	----------------------------------------------------------*/
	Sprite_Draw(TEXTURE_INDEX_KAZIKI,
		pos.x,
		pos.y);

	if (button == 1 && button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_A_BUTTON, 95, 50);
	}
	if (button == 2 && button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_B_BUTTON, 95, 50);
	}
	if (button == 3 && button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_X_BUTTON, 95, 50);
	}
	if (button == 4 && button_flag)
	{
		Sprite_Draw(TEXTURE_INDEX_Y_BUTTON, 95, 50);
	}

}

Kaziki::Kaziki() 
{
	pos.x = 0;
	pos.y = 0;
	speed = 0;
	button_flag = false;
	end_flag = false;
}
Kaziki::~Kaziki()
{

}
void Kaziki::Update()
{

}
void Kaziki::Draw()
{

}

Kujira::Kujira() 
{
	pos.x = 0;
	pos.y = 0;
	speed = 0;
	button_flag = false;
	end_flag = false;
}
Kujira::~Kujira()
{

}
void Kujira::Update()
{

}
void Kujira::Draw()
{

}

Iruka::Iruka() 
{
	pos.x = 0;
	pos.y = 0;
	speed = 0;
	button_flag = false;
	end_flag = false;
}
Iruka::~Iruka()
{

}
void Iruka::Update()
{

}
void Iruka::Draw()
{

}

Uma::Uma() 
{
	pos.x = 0;
	pos.y = 0;
	speed = 0;
	button_flag = false;
	end_flag = false;
}
Uma::~Uma()
{

}
void Uma::Update()
{

}
void Uma::Draw()
{

}
