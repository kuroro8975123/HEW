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
	{ "asset/texture/title1.png", SCREEN_WIDTH, SCREEN_HEIGHT },						//01.タイトル画面
	{ "asset/texture/title2.png", SCREEN_WIDTH, SCREEN_HEIGHT },						//02.タイトル画面
	{ "asset/texture/tutorial.png", SCREEN_WIDTH, SCREEN_HEIGHT },					//03.チュートリアル画面
	{ "asset/texture/game01.png", SCREEN_WIDTH, SCREEN_HEIGHT },					//04.ゲーム画面
	{ "asset/texture/result.png", SCREEN_WIDTH, SCREEN_HEIGHT },						//05.リザルト画面
	{ "asset/texture/player.png", 64, 128 },							//06.プレイヤー
	{ "asset/texture/enemy.png", 64, 128 },						//07.敵？
	{ "asset/texture/number.png",704 , 64 },						//08.数字
	{ "asset/texture/3.png", 800, 400 },								//09.カウントダウン
	{ "asset/texture/2.png", 800, 400 },								//10.カウントダウン
	{ "asset/texture/1.png", 800, 400 },								//11.カウントダウン
	{ "asset/texture/START.png", 2048, 1024 },						//12.カウントダウン
	{ "asset/texture/button.png", 400, 400 },						//13.ボタン
	{ "asset/texture/pressanykey.png", 1024, 512},				//14.ボタン
	{ "asset/texture/chara_select.png", 512, 288 },				//15.キャラクターセレクト
	{ "asset/texture/title2.png", SCREEN_WIDTH, SCREEN_HEIGHT },						//16.キャラクターセレクト
	{ "asset/texture/chara_select.png", 712, 400 },				//17.キャラクターを選択してください
	{ "asset/texture/button2.png", 400, 400 },					//18.キャラクターを選択してください
	{"asset/texture/Block.png",52,52},								//19ロックサンプル
	{"asset/texture/A_button.png", 64 ,64},						//20.Aボタン
	{"asset/texture/B_button.png",  64 ,64},						//21.Bボタン
	{"asset/texture/X_button.png", 64,64},							//22.Xボタン
	{"asset/texture/Y_button.png",  64 ,64},						//23.Yボタン
	{ "asset/texture/KAZIKI(1).png", 128, 256 },					//24.カジキ
	{ "asset/texture/kujira(1).png", 192, 256 },					//25.クジラ
	{ "asset/texture/iruka.png", 96, 220 },							//26.イルカ
	{ "asset/texture/uma.png", 128, 256 },							//27.馬
	{ "asset/texture/map.png", 128, 500 },							//28.マップ
	{ "asset/texture/game.png", SCREEN_WIDTH, SCREEN_HEIGHT },							//29.背景
	{ "asset/texture/KAZIKI.png",800, 300 },					//30.カジキ
	{ "asset/texture/umauma.png",800, 300 },					//31.馬
	{ "asset/texture/NEW_IRUKA.png",800, 300 },					//32.イルカ
	{ "asset/texture/KUZIRA.png",800, 300 },					//33.クジラ
	{ "asset/texture/ka.png",900, 900 },					//34.カジキセレクト
	{ "asset/texture/kujira.png",900, 900 },					//35.クジラセレクト
	{ "asset/texture/iruka_.png",900, 900 },					//36.イルカセレクト
	{ "asset/texture/uma_.png",900, 900 },					//37.馬セレクト
	{ "asset/texture/left.png",450, 300 },					//38.左
	{ "asset/texture/right.png",450, 300 },					//39.右

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
