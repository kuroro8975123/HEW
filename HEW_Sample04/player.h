#pragma once



void Player_Initialize(void);
void Player_Finalize(void);
void Player_Update(void);
void Player_Draw(void);

void Player_AddDamage(int damage);
void Player_HP(int dama);
int Player_GetHitPoint();
int Player_GetHP();
float Player_GetSpeed();
bool Player_End();

