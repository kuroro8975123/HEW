
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	èáà åàíËédól
	ÅEäeÉvÉåÉCÉÑÅ[ñàÇÃÉ^ÉCÉÄï™ÇØ( game.cppÇ…Çƒ )
	ÅEèáà åàíË( result.cppÇ…Çƒ )

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "input.h"
#include "scene.h"
#include "sprite.h"
//#include "texture.h"
#include "fade.h"
#include "main.h"
#include "game.h"
#include "score_draw.h"
#include "number.h"
#include "timer.h"
#include "player.h"

static float y;

int tmpS;
int tmpM;

typedef struct
{
	int Second;
	int Minute;
	int Rank;
}PLAYER;

PLAYER Player[4];

void Result_Initialize(void)
{
	Fade_Start(false, 90, D3DCOLOR_RGBA(0, 0, 0, 0));
	y = 0;

	Player[0].Second = Second_Player01();
	Player[1].Second = Second_Enemy01();
	Player[2].Second = Second_Enemy02();
	Player[3].Second = Second_Enemy03();

	Player[0].Minute = Minute_Player01();
	Player[1].Minute = Minute_Enemy01();
	Player[2].Minute = Minute_Enemy02();
	Player[3].Minute = Minute_Enemy03();
}

void Result_Finalize(void)
{
}

void Result_Update(void)
{
	if( Keyboard_IsTrigger(DIK_SPACE) || GamePad_IsTrigger(0, BUTTON_A)) {
		Scene_Change(SCENE_INDEX_TITLE);
	}
	y += 1.0f;
	if (y > 500)
		y = 0;

}

void Result_Draw()
{
	Sprite_Draw(TEXTURE_INDEX_RESULT, 0.0f, 0.0f);
	//Sprite_Draw(TEXTURE_INDEX_GAME, 0.0f, 0.0f);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			if (Player[i].Second >= Player[j].Second)
			{
				if (Player[i].Minute >= Player[j].Minute)
				{
					tmpS = Player[i].Second;
					Player[i].Second = Player[j].Second;
					Player[j].Second = tmpS;

					tmpM = Player[i].Minute;
					Player[i].Minute = Player[j].Minute;
					Player[j].Minute = tmpM;
				}
			}
		}
	}
	//1à ï`âÊ
	Minute_Draw(440, 120, Player[0].Minute, 2, true);	//1à ï™êî
	Second_Draw(520, 120, Player[0].Second, 2, true);	//1à ïbêî

	if (Player[0].Second == Second_Player01())
	{
		Sprite_Draw(TEXTURE_INDEX_PLAYER, SCREEN_WIDTH / 2 - 40.0f, 220.0f);
	}
	if (Player[0].Second == Second_Enemy01())
	{
		Sprite_Draw(TEXTURE_INDEX_ENEMY, SCREEN_WIDTH / 2 - 40.0f, 220.0f);
	}
	if (Player[0].Second == Second_Enemy02())
	{
		Sprite_Draw(TEXTURE_INDEX_ENEMY, SCREEN_WIDTH / 2 - 40.0f, 220.0f);
	}
	if (Player[0].Second == Second_Enemy03())
	{
		Sprite_Draw(TEXTURE_INDEX_ENEMY, SCREEN_WIDTH / 2 - 40.0f, 220.0f);
	}

	//2à ï`âÊ
	Minute_Draw(100, 200, Player[1].Minute, 2, true);	//2à ï™êî
	Second_Draw(180, 200, Player[1].Second, 2, true);	//2à ïbêî

	if (Player[1].Second == Second_Player01())
	{
		Sprite_Draw(TEXTURE_INDEX_PLAYER, 150.0f, 300.0f);
	}
	if (Player[1].Second == Second_Enemy01())
	{
		Sprite_Draw(TEXTURE_INDEX_ENEMY, 150.0f, 300.0f);
	}
	if (Player[1].Second == Second_Enemy02())
	{
		Sprite_Draw(TEXTURE_INDEX_ENEMY, 150.0f, 300.0f);
	}
	if (Player[1].Second == Second_Enemy03())
	{
		Sprite_Draw(TEXTURE_INDEX_ENEMY, 150.0f, 300.0f);
	}

	//3à ï`âÊ
	Minute_Draw(750, 200, Player[2].Minute, 2, true);	//3à ï™êî
	Second_Draw(830, 200, Player[2].Second, 2, true);	//3à ïbêî

	if (Player[2].Second == Second_Player01())
	{
		Sprite_Draw(TEXTURE_INDEX_PLAYER, 800.0f, 300.0f);
	}
	if (Player[2].Second == Second_Enemy01())
	{
		Sprite_Draw(TEXTURE_INDEX_ENEMY, 800.0f, 300.0f);
	}
	if (Player[2].Second == Second_Enemy02())
	{
		Sprite_Draw(TEXTURE_INDEX_ENEMY, 800.0f, 300.0f);
	}
	if (Player[2].Second == Second_Enemy03())
	{
		Sprite_Draw(TEXTURE_INDEX_ENEMY, 800.0f, 300.0f);
	}
}
