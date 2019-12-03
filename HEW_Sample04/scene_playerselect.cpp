#include "input.h"
#include "scene.h"
#include "sprite.h"
#include "texture.h"
#include "fade.h"



void P_Select_Initialize(void)
{
	Fade_Start(false, 90, D3DCOLOR_RGBA(0, 0, 0, 0));
}

void P_Select_Finalize(void)
{
}

void P_Select_Update(void)
{
	if (Keyboard_IsTrigger(DIK_SPACE)) {
		Scene_Change(SCENE_INDEX_GAME);
	}
}

void P_Select_Draw(void)
{
	Sprite_Draw(TEXTURE_INDEX_TUTORIAL, 0.0f, 0.0f);
}
