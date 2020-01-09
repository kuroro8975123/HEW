#include <d3dx9.h>
//#include "debugPrintf.h"
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
	{ "asset/texture/title1.png", 1024, 576 },						//01.タイトル画面
	{ "asset/texture/title2.png", 1024, 576 },						//02.タイトル画面
	{ "asset/texture/tutorial.png", 1024, 576 },						//03.チュートリアル画面
	{ "asset/texture/game01.png", 1024, 576 },					//04.ゲーム画面
	{ "asset/texture/result.png", 1024, 576 },						//05.リザルト画面
	{ "asset/texture/player.png", 64, 128 },							//06.プレイヤー
	{ "asset/texture/enemy.png", 64, 128 },							//07.敵？
	{ "asset/texture/number.png", 352, 32 },						//08.数字
	{ "asset/texture/3.png", 512, 288 },								//09.カウントダウン
	{ "asset/texture/2.png", 512, 288 },								//10.カウントダウン
	{ "asset/texture/1.png", 512, 288 },								//11.カウントダウン
	{ "asset/texture/START.png", 912, 512 },						//12.カウントダウン
	{ "asset/texture/button.png", 400, 400 },						//13.ボタン
	{ "asset/texture/pressanykey.png", 712, 400},	//14.ボタン
	{ "asset/texture/chara_select.png", 512, 288 },					//15.キャラクターセレクト
	{ "asset/texture/title2.png", 1024, 576 },							//16.キャラクターセレクト
	{ "asset/texture/chara_select.png", 712, 400 },					//17.キャラクターを選択してください
	{ "asset/texture/button2.png", 400, 400 },						//18.キャラクターを選択してください
	{"asset/texture/Block.png",52,52},									//19ロックサンプル
	

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
			// DebugPrintf("テクスチャの読み込みに失敗 ... %s\n", g_TextureFiles[i].filename);
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
