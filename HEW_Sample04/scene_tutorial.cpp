#include "input.h"
#include "scene.h"
#include "sprite.h"
#include "texture.h"
#include "fade.h"



void Tutorial_Initialize(void)
{
	Fade_Start(false, 90, D3DCOLOR_RGBA(0, 0, 0, 0));
}

void Tutorial_Finalize(void)
{
}

void Tutorial_Update(void)
{
	if (Keyboard_IsTrigger(DIK_SPACE) || GamePad_IsTrigger(0, BUTTON_A)) {
		Scene_Change(SCENE_INDEX_P_SELECT);
	}
}

void Tutorial_Draw(void)
{
	Sprite_Draw(TEXTURE_INDEX_TUTORIAL, 0.0f, 0.0f);
}
