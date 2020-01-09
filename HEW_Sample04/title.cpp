#include "input.h"
#include "scene.h"
#include "sprite.h"
//#include "texture.h"
#include "fade.h"
#include "main.h"
#include <d3d9.h>

static bool g_bEnd = false;
static float y;


void Title_Initialize(void)
{
	g_bEnd = false;
	y = 0;
}

void Title_Finalize(void)
{
}

void Title_Update(void)
{
	if( !g_bEnd ) { 
		if( Keyboard_IsTrigger(DIK_SPACE) || GamePad_IsTrigger(0, BUTTON_A)) {
			Fade_Start(true, 30, D3DCOLOR_RGBA(255, 255, 255, 255));
			g_bEnd = true;
		}
	}
	else{
		if( !Fade_IsFade() ) {
			Scene_Change(SCENE_INDEX_TUTORIAL);
		}
	}
	y += 1.0f;
	if (y > 500)
		y = 0;

}

void Title_Draw(void)
{
	
	
	Sprite_Draw(TEXTURE_INDEX_TITLE2, 0.0f, 0.0f);
	Sprite_Draw(TEXTURE_INDEX_TITLE1, 0.0f, 0.0f);
	Sprite_Draw(TEXTURE_INDEX_PRESS, 130.0f, 140.0f);
	
	//Sprite_Draw(TEXTURE_INDEX_BG, 0.0f, y);
	//Sprite_Draw(TEXTURE_INDEX_BG, 0.0f, -500 + y);
	
}
