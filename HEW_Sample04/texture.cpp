#include <d3dx9.h>
//#include "debugPrintf.h"
#include "main.h"
#include "mydirect3d.h"
#include "texture.h"

#define TEXTURE_FILENAME_MAX (64)

typedef struct TextureFile_tag
{
	char filename[TEXTURE_FILENAME_MAX];
	int width;
	int height;
} TextureFile;

static const TextureFile g_TextureFiles[] = {
	{ "asset/texture/title1.png", SCREEN_WIDTH, SCREEN_HEIGHT },						//01.�^�C�g�����
	{ "asset/texture/title2.png", SCREEN_WIDTH, SCREEN_HEIGHT },						//02.�^�C�g�����
	{ "asset/texture/tutorial.png", SCREEN_WIDTH, SCREEN_HEIGHT },					//03.�`���[�g���A�����
	{ "asset/texture/game01.png", SCREEN_WIDTH, SCREEN_HEIGHT },					//04.�Q�[�����
	{ "asset/texture/result.png", SCREEN_WIDTH, SCREEN_HEIGHT },						//05.���U���g���
	{ "asset/texture/player.png", 64, 128 },							//06.�v���C���[
	{ "asset/texture/enemy.png", 64, 128 },						//07.�G�H
	{ "asset/texture/number.png",704 , 64 },						//08.����
	{ "asset/texture/3.png", 800, 400 },								//09.�J�E���g�_�E��
	{ "asset/texture/2.png", 800, 400 },								//10.�J�E���g�_�E��
	{ "asset/texture/1.png", 800, 400 },								//11.�J�E���g�_�E��
	{ "asset/texture/START.png", 2048, 1024 },						//12.�J�E���g�_�E��
	{ "asset/texture/button.png", 400, 400 },						//13.�{�^��
	{ "asset/texture/pressanykey.png", 1024, 512},				//14.�{�^��
	{ "asset/texture/chara_select.png", 512, 288 },				//15.�L�����N�^�[�Z���N�g
	{ "asset/texture/title2.png", SCREEN_WIDTH, SCREEN_HEIGHT },						//16.�L�����N�^�[�Z���N�g
	{ "asset/texture/chara_select.png", 712, 400 },				//17.�L�����N�^�[��I�����Ă�������
	{ "asset/texture/button2.png", 400, 400 },					//18.�L�����N�^�[��I�����Ă�������
	{"asset/texture/Block.png",52,52},								//19���b�N�T���v��
	{"asset/texture/A_button.png", 64 ,64},						//20.A�{�^��
	{"asset/texture/B_button.png",  64 ,64},						//21.B�{�^��
	{"asset/texture/X_button.png", 64,64},							//22.X�{�^��
	{"asset/texture/Y_button.png",  64 ,64},						//23.Y�{�^��
	{ "asset/texture/KAZIKI(1).png", 128, 256 },					//24.�J�W�L
	{ "asset/texture/kujira(1).png", 192, 256 },					//25.�N�W��
	{ "asset/texture/iruka.png", 96, 220 },							//26.�C���J
	{ "asset/texture/uma.png", 128, 256 },							//27.�n
	{ "asset/texture/map.png", 128, 500 },							//28.�}�b�v
	{ "asset/texture/game.png", SCREEN_WIDTH, SCREEN_HEIGHT },							//29.�w�i
	{ "asset/texture/KAZIKI.png",800, 300 },					//30.�J�W�L
	{ "asset/texture/umauma.png",800, 300 },					//31.�n
	{ "asset/texture/NEW_IRUKA.png",800, 300 },					//32.�C���J
	{ "asset/texture/KUZIRA.png",800, 300 },					//33.�N�W��
	{ "asset/texture/ka.png",900, 900 },					//34.�J�W�L�Z���N�g
	{ "asset/texture/kujira.png",900, 900 },					//35.�N�W���Z���N�g
	{ "asset/texture/iruka_.png",900, 900 },					//36.�C���J�Z���N�g
	{ "asset/texture/uma_.png",900, 900 },					//37.�n�Z���N�g
	{ "asset/texture/left.png",450, 300 },					//38.��
	{ "asset/texture/right.png",450, 300 },					//39.�E

};

static const int TEXTURE_FILE_COUNT = sizeof(g_TextureFiles) / sizeof(g_TextureFiles[0]);

static_assert(TEXTURE_INDEX_MAX == TEXTURE_FILE_COUNT, "TEXTURE_INDEX_MAX != TEXTURE_FILE_COUNT");

static LPDIRECT3DTEXTURE9 g_pTextures[TEXTURE_FILE_COUNT] = {};

int Texture_Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetD3DDevice();
	if (!pDevice) {
		return TEXTURE_FILE_COUNT;
	}

	int failed_count = 0;

	for (int i = 0; i < TEXTURE_FILE_COUNT; i++) {

		if (FAILED(D3DXCreateTextureFromFile(pDevice, g_TextureFiles[i].filename, &g_pTextures[i]))) {
			// DebugPrintf("�e�N�X�`���̓ǂݍ��݂Ɏ��s ... %s\n", g_TextureFiles[i].filename);
			failed_count++;
		}
	}

	return failed_count;
}

void Texture_Release(void)
{
	for (int i = 0; i < TEXTURE_FILE_COUNT; i++) {

		if (g_pTextures[i]) {
			g_pTextures[i]->Release();
			g_pTextures[i] = NULL;
		}
	}
}

LPDIRECT3DTEXTURE9 Texture_GetTexture(TextureIndex index)
{
	if (index < 0 || index >= TEXTURE_INDEX_MAX) {
		return NULL;
	}

	return g_pTextures[index];
}

int Texture_GetWidth(TextureIndex index)
{
	if (index < 0 || index >= TEXTURE_INDEX_MAX) {
		return NULL;
	}

	return g_TextureFiles[index].width;
}

int Texture_GetHeight(TextureIndex index)
{
	if (index < 0 || index >= TEXTURE_INDEX_MAX) {
		return NULL;
	}

	return g_TextureFiles[index].height;
}
