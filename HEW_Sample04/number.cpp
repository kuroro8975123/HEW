#include "texture.h"
#include "sprite.h"
#include "number.h"


void Number_Draw(float x, float y, int n)
{
	if( n < 0 || n > 10 ) return;

	Sprite_Draw(TEXTURE_INDEX_NUMBER,
		x, y,
		NUMBER_WIDTH * n, 0,
		NUMBER_WIDTH, NUMBER_HEIGHT);
}

