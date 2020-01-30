#include "input.h"
#include "scene.h"
#include "sprite.h"
#include "fade.h"
#include "main.h"
#include "timer.h"
#include "worldrecord.h"
#include "worldrecord_2.h"

typedef struct {
	int Min;
	int Sec;
}RECORD;

static RECORD	g_Wrecord[5];			//�v���C���[���R�[�h�i���l���j

void WorldRecord_2_Initialize(void)
{
	Fade_Start(false, 90, D3DCOLOR_RGBA(0, 0, 0, 0));

	for (int i = 0; i < 5; i++)
	{
		g_Wrecord[i].Min = Get_WorldMin(i);
		g_Wrecord[i].Sec = Get_WorldSec(i);
	}

}

void WorldRecord_2_Finalize(void)
{
}

void WorldRecord_2_Update(void)
{
	if (Keyboard_IsTrigger(DIK_SPACE) || GamePad_IsTrigger(0, BUTTON_A)) {
		Scene_Change(SCENE_INDEX_TITLE);
	}
}

void WorldRecord_2_Draw()
{
	Sprite_Draw(TEXTURE_INDEX_WORLDRECORD, 0.0f, 0.0f);
	Sprite_Draw(TEXTURE_INDEX_1ST, 450.0f, 150.0f);
	Sprite_Draw(TEXTURE_INDEX_2ND, 250.0f, 350.0f);
	Sprite_Draw(TEXTURE_INDEX_3RD, 1050.0f, 350.0f);
	Sprite_Draw(TEXTURE_INDEX_4TH, 250.0f, 550.0f);
	Sprite_Draw(TEXTURE_INDEX_5TH, 1050.0f, 550.0f);

	Minute_Draw(750, 250, g_Wrecord[0].Min, 2, true, 1.5f, 1.5f);	//1�ʕ���
	Second_Draw(950, 250, g_Wrecord[0].Sec, 2, true, 1.5f, 1.5f);	//1�ʕb��

	Minute_Draw(440, 425, g_Wrecord[1].Min, 2, true);				//2�ʕ���
	Second_Draw(600, 425, g_Wrecord[1].Sec, 2, true);				//2�ʕb��

	Minute_Draw(1240, 425, g_Wrecord[2].Min, 2, true);				//3�ʕ���
	Second_Draw(1400, 425, g_Wrecord[2].Sec, 2, true);				//3�ʕb��

	Minute_Draw(440, 625, g_Wrecord[3].Min, 2, true);				//4�ʕ���
	Second_Draw(600, 625, g_Wrecord[3].Sec, 2, true);				//4�ʕb��

	Minute_Draw(1240, 625, g_Wrecord[4].Min, 2, true);				//5�ʕ���
	Second_Draw(1400, 625, g_Wrecord[4].Sec, 2, true);				//5�ʕb��
}
