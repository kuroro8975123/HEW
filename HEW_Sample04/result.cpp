#include "input.h"
#include "scene.h"
#include "sprite.h"
#include "texture.h"
#include "fade.h"
#include "main.h"

static float y;


void Result_Initialize(void)
{
	Fade_Start(false, 90, D3DCOLOR_RGBA(0, 0, 0, 0));
	y = 0;
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

void Result_Draw(void)
{
	Sprite_Draw(TEXTURE_INDEX_RESULT, 0.0f, 0.0f);
	Sprite_Draw(TEXTURE_INDEX_PLAYER, SCREEN_WIDTH / 2 - 40.0f, 150.0f);
	Sprite_Draw(TEXTURE_INDEX_ENEMY,200.0f, 250.0f);
	Sprite_Draw(TEXTURE_INDEX_ENEMY, 754.0f, 250.0f);
	//Sprite_Draw(TEXTURE_INDEX_GAME, 0.0f, 0.0f);

}
