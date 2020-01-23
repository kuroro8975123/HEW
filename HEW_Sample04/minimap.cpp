//
//	ファイルインクルード
//

#include "main.h"
#include "minimap.h"
#include "player.h"
#include "sprite.h"
#include "game.h"

//
//	マクロ定義
//

//赤点の初期位置(実行結果を見て調節)
#define POINT_POS_X		(1700.0f)
#define POINT_POS_Y		(500.0f)


//
//	プロトタイプ宣言
//

typedef struct 
{

	D3DXVECTOR2 pos;
	
}Pos_Data;


//
//	グローバル宣言
//

Pos_Data			g_posPoint[2];

//プレイヤーの位置を入れる
static	D3DXVECTOR2	g_playerpos[2];

//初期化
void Minimap_Initialize() {

	for (int i = 0; i < 2; i++)
	{
		g_posPoint[i].pos.x = POINT_POS_X + i * 100.0f;
		g_posPoint[i].pos.y = POINT_POS_Y;
	}

}

//終了
void Minimap_Finalize() {

}

//更新
void Minimap_Update() {

	for (int i = 0; i < 2;i++)
	{
		//プレイヤーの位置を取得(引数はプレイヤーの番号)
		//g_posPoint[i]=Get_PlayerPos(i);

		//プレイヤーの位置をミニマップに反映
		//実行結果を見ながら位置調整
		//g_posPoint[i].pos.y += g_playerpos[i].y / 10.0f;
	}
}

//描画
void Minimap_Draw() {

	//ミニマップの表示
	//Sprite_Draw(TEXTURE_INDEX_MAP,1000.0f,100.0f);

	//ミニマップの中の赤点表示
	for (int i = 0; i < 2; i++)
	{
		//Sprite_Draw(TEXTURE_INDEX_POINT,g_posPoint[i].pos.x,g_posPoint[i].pos.y)
	}

}