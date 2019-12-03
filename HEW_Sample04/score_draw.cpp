#include "number.h"
#include "sprite.h"

void Score_Draw(float x, float y, int score, int fig, bool bZero)
{
	//// カンスト用の最大数値を作る
	//int count_stop_score = 1;
	//for (int i = 0; i < fig; i++) {
	//	count_stop_score *= 10;
	//}

	////最大値の補正処理
	//if (score >= count_stop_score) {
	//	score = count_stop_score - 1;
	//}

	//	if( bZero ) {

	for (int i = 0; i < fig; i++) {

		int n = score % 10;
		score /= 10;

		Number_Draw(x + NUMBER_WIDTH * (fig - (i + 1)), y, n);
	}
	//	}
	Sprite_Draw(TEXTURE_INDEX_NUMBER, 0.0f, 0.0f);

}