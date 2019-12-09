
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	順位決定仕様
	・各プレイヤー毎のタイム分け( game.cppにて )
	・順位決定( result.cppにて )

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "input.h"
#include "scene.h"
#include "sprite.h"
#include "texture.h"
#include "fade.h"
#include "main.h"
#include "game.h"
#include "score_draw.h"
#include "number.h"
#include "timer.h"

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
	Sprite_Draw(TEXTURE_INDEX_PLAYER, SCREEN_WIDTH / 2 - 40.0f, 150.0f);
	Sprite_Draw(TEXTURE_INDEX_ENEMY, 200.0f, 250.0f);
	Sprite_Draw(TEXTURE_INDEX_ENEMY, 754.0f, 250.0f);
	//Sprite_Draw(TEXTURE_INDEX_GAME, 0.0f, 0.0f);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			if (Player[i].Second < Player[j].Second)
			{
				if (Player[i].Minute <= Player[j].Minute)
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
		Minute_Draw(440, 50, Player[i].Minute, 2, true);
		Second_Draw(520, 50, Player[i].Second, 2, true);
	}
}
