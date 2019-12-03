#pragma once




#define ENEMY_COUNT 3

void Enemy_Initialize(void);
void Enemy_Finalize(void);
void Enemy_Update(void);
void Enemy_Draw(void);
bool Enemy_IsEnable(int index);
void SetEnemy(float,float);
int Enemy_GetRange(int num);
float Enemy_GetSpeed(int num);
bool Enemy_End(int num);