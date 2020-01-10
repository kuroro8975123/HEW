
#include "enemy.h"
#include "main.h"
#include "sprite.h"
#include "player.h"
#include <time.h>
#include "game.h"

#define _USE_MATH_DEFINES
#include <math.h>

#define ENEMY_WIDTH				(32)
#define ENEMY_HEIGHT			(32)
#define ANIME_PATTERN_MAX		(3)
#define ANIME_PATTERN_SKIPFRAME (8)

#define ENEMY_SEARCH_RADIUS		(200.0f)
#define ENEMY_SEARCH_ANGLE		(0.85f)
#define ENEMY_CHASE_SPEED		(3.0f)
#define ENEMY_RETURN_SPEED		(1.0f)
#define COURSE_RANGE            (1500)

typedef struct
{
	int			enable;	//生存フラグ

	D3DXVECTOR2 pos;	//位置
	int			color;	//色
	int			muki;	//向き（移動方向）

	int			animePattern;	//アニメパターン
	int			animeFrame;		//パターン切り替えウエイト


	float		range;

	int			frame;
	int			frame_alpha;

	float		speed;
	int			addspeed;
	int			movecount;
	bool        end;

}ENEMY_DATA;

ENEMY_DATA enemy[ENEMY_COUNT];




void Enemy_Initialize(void)
{
	//敵の初期化
	for (int i = 0; i < ENEMY_COUNT; i++) {

		enemy[i].enable = false;

		enemy[i].range = 1000.0f;

		enemy[i].speed = 0.25;

		enemy[i].end = false;
	}


	SetEnemy(334, 300);
	SetEnemy(590, 300);
	SetEnemy(846, 300);

	srand((unsigned int)time(NULL));
}

void Enemy_Finalize(void)
{

}

void Enemy_Update(void)
{
	D3DXVECTOR2 dir = D3DXVECTOR2(0.0f, 0.0f);

	for (int i = 0; i < ENEMY_COUNT; i++) {

		//敵の速度加算処理
		if (enemy[i].movecount >= 5)
		{

			enemy[i].addspeed = rand() % 4;

			switch (enemy[i].addspeed)
			{
			case 0:
				enemy[i].speed += 0.01;
				break;
			case 2:
				enemy[i].speed += 0.03;
				break;
			case 3:
				enemy[i].speed += 0.05;
				break;
			case 4:
				enemy[i].speed += 0.04;
				break;
			default:break;
			}

			enemy[i].movecount = 0;
		}
		if (Goal_Flag_E01())
		{
			if (enemy[0].pos.y > 20)
			{
				enemy[0].pos.y -= enemy[0].speed;
			}
			else
			{
				enemy[0].end = true;
			}
		}
		if (Goal_Flag_E02())
		{
			if (enemy[1].pos.y > 20)
			{
				enemy[1].pos.y -= enemy[1].speed;
			}
			else
			{
				enemy[1].end = true;
			}

		}
		if (Goal_Flag_E03())
		{
			if (enemy[2].pos.y > 20)
			{
				enemy[2].pos.y -= enemy[2].speed;
			}
			else
			{
				enemy[2].end = true;
			}

		}

		//敵の移動処理
		enemy[i].pos += dir;

		enemy[i].movecount++;
	}
}

void Enemy_Draw(void)
{
	for (int i = 0; i < ENEMY_COUNT; i++) {

		//生存フラグがTRUEの敵のみ処理を行う
		if (!enemy[i].enable) {
			continue;
		}

		/*--------------------------------------------------------
		提出用にイルカにしてあります。
		----------------------------------------------------------*/
		Sprite_Draw(TEXTURE_INDEX_IRUKA,
			enemy[i].pos.x,
			enemy[i].pos.y);
	}
}

void SetEnemy(float x, float y)
{

	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		if (enemy[i].enable == false)
		{
			enemy[i].pos.x = x;
			enemy[i].pos.y = y;
			enemy[i].enable = true;
			break;
		}
	}

}
void Enemy_Destroy(int index)
{
	enemy[index].enable = false;
}

bool Enemy_IsEnable(int index)
{
	return enemy[index].enable;
}

int Enemy_GetRange(int num)
{
	return enemy[num].range;
}

float Enemy_GetSpeed(int num)
{
	return enemy[num].speed;
}

bool Enemy_End(int num)
{
	return  enemy[num].end;
}