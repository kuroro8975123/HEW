/*============================
	DirectX:Collision
	製作者:岡部　友紀
------------------------------
	DATE:2019_0920(Fri)
	追記:2019_0929(Sun)
============================*/

/*============================
	ヘッダーファイル読み込み
============================*/

#include "game.h"
#include "collision.h"
#include "scene.h"

/*============================
		　マクロ定義
============================*/

/*============================
	　グローバル変数宣言
============================*/

static bool HitCircle(const CIRCLE* pCircle_a, const CIRCLE* pCircle_b);

bool HitCircle(const CIRCLE* p_circle_a, const CIRCLE* p_circle_b)
{
	//引数からベクトル型の変数を作る
	D3DXVECTOR2 dst1(p_circle_a->cx, p_circle_a->cy);
	D3DXVECTOR2 dst2(p_circle_b->cx, p_circle_b->cy);
	//二点間のベクトルを作る
	D3DXVECTOR2 distance = dst2 - dst1;
	//作ったベクトルの長さを求める
	float length = D3DXVec2Length(&distance);
	//お互いの半径を足した値を求める
	float size = p_circle_a->r + p_circle_b->r;

	//ベクトルの長さとお互いの半径を足した値を比較する
	//→ベクトルの長さの方が小さければヒットしている！
	if (length < size){
		return true;
	}
	//ヒットしていなかった
	return false;
}

bool HitCupsule(const CIRCLE* p_circle, const CUPSULE* p_cupsule)
{
	//円とカプセルの位置
	D3DXVECTOR2 cir_pos = D3DXVECTOR2(p_circle->cx, p_circle->cy);
	D3DXVECTOR2 cup_pos = D3DXVECTOR2(p_cupsule->x, p_cupsule->y);
	D3DXVECTOR2 cup_end = D3DXVECTOR2(p_cupsule->ex, p_cupsule->ey);

	D3DXVECTOR2 distance = cir_pos - cup_pos;

	float t = 0.0f;

	//交点を求める
	t = (cup_end.x * distance.x + cup_end.y * distance.y) /
		(cup_end.x * cup_end.x  + cup_end.y * cup_end.y);

	if (t < 0.0f)
		t = 0.0f;
	if (t > 1.0f)
		t = 1.0f;

	D3DXVECTOR2 pos_cross;
	pos_cross.x = (cup_end.x * t) + cup_pos.x;
	pos_cross.y = (cup_end.y * t) + cup_pos.y;

	//交点までの長さとお互いの半径を足したものの大きさを比べる
	float cross_len = (pos_cross.x - cir_pos.x) * (pos_cross.x - cir_pos.x) +
                	  (pos_cross.y - cir_pos.y) * (pos_cross.y - cir_pos.y);

	float size = (p_circle->r + p_cupsule->r);

	//→ベクトルの長さの方が小さければヒットしている！
	if (cross_len < size * size)
	{
		return true;
	}

	//ヒットしていなかった
	return false;
}

void Collision_Initialize(void)
{
}

void Collision_Update(void)
{
  	
}