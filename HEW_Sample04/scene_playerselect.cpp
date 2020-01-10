#include "input.h"
#include "scene.h"
#include "sprite.h"
//#include "texture.h"
#include "fade.h"
#include "enemy.h"
#include "player.h"


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

	

