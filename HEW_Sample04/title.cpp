#include "input.h"
#include "scene.h"
#include "fade.h"
#include "main.h"
#include "sound.h"
#include <d3d9.h>

static bool g_bEnd = false;

#include "sprite.h"
//#include "texture.h"


void Title_Initialize(void)
{
	g_bEnd = false;
}

void Title_Finalize(void)
{
}

void Title_Update(void)
{
	if( !g_bEnd ) { 
		if( Keyboard_IsTrigger(DIK_SPACE) || GamePad_IsTrigger(2, BUTTON_A)) {
			PlaySound(SOUND_LABEL_SE_AWA);
			Fade_Start(true, 30, D3DCOLOR_RGBA(255, 255, 255, 255));
			g_bEnd = true;
		}
	}
	else{
		if( !Fade_IsFade() ) {
			//Scene_Change(SCENE_INDEX_TUTORIAL);
			Scene_Change(SCENE_INDEX_P_SELECT);
			//Scene_Change(SCENE_INDEX_GAME);
		}
	}

}

void Title_Draw(void)
{
	
	
	Sprite_Draw(TEXTURE_INDEX_TITLE2, 0.0f, 0.0f);
	Sprite_Draw(TEXTURE_INDEX_TITLE1, 0.0f, 0.0f);
	Sprite_Draw(TEXTURE_INDEX_PRESS, SCREEN_WIDTH / 3 - 200.0f, SCREEN_HEIGHT / 3);

	//Sprite_Draw(TEXTURE_INDEX_BG, 0.0f, y);
	//Sprite_Draw(TEXTURE_INDEX_BG, 0.0f, -500 + y);
	
}
