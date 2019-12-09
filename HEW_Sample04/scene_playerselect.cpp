#include "input.h"
#include "scene.h"
#include "sprite.h"
#include "texture.h"
#include "fade.h"
#include "enemy.h"



void P_Select_Initialize(void)
{
	Fade_Start(false, 90, D3DCOLOR_RGBA(0, 0, 0, 0));
}

void P_Select_Finalize(void)
{
}

void P_Select_Update(void)
{
	if (Keyboard_IsTrigger(DIK_A)) {
		Scene_Change(SCENE_INDEX_GAME);
	}
	if (Keyboard_IsTrigger(DIK_B)) {
		Scene_Change(SCENE_INDEX_GAME);
	}
	if (Keyboard_IsTrigger(DIK_X)) {
		Scene_Change(SCENE_INDEX_GAME);
	}
	if (Keyboard_IsTrigger(DIK_Y)) {
		Scene_Change(SCENE_INDEX_GAME);
	}
}

void P_Select_Draw(void)
{
	
	Sprite_Draw(TEXTURE_INDEX_POOL, 0.0f, 0.0f);
	Sprite_Draw(TEXTURE_INDEX_CHARASELE, 0.0f, 0.0f);
	Sprite_Draw(TEXTURE_INDEX_CHARASEN, 300.0f, 0.0f);

	Sprite_Draw(TEXTURE_INDEX_ENEMY, 200.0f, 250.0f);
	Sprite_Draw(TEXTURE_INDEX_ENEMY, 400.0f, 250.0f);
	Sprite_Draw(TEXTURE_INDEX_ENEMY, 600.0f, 250.0f);
	Sprite_Draw(TEXTURE_INDEX_ENEMY, 800.0f, 250.0f);

	Sprite_Draw(TEXTURE_INDEX_BUTTON2, 215, 450, 19, 220, 33, 33);
	Sprite_Draw(TEXTURE_INDEX_BUTTON2, 415, 450, 70, 220, 33, 33);
	Sprite_Draw(TEXTURE_INDEX_BUTTON2, 615, 450, 124, 220, 33, 33);
	Sprite_Draw(TEXTURE_INDEX_BUTTON2, 815, 450, 177, 220, 33, 33);
}

	

