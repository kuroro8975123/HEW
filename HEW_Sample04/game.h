#pragma once

void Game_Initialize(void);
void Game_Finalize(void);
void Game_Update(void);
void Game_Draw(void);

void Game_AddScore(int score);
void Game_AddKillCount(void);
bool Goal_Flag_P();
bool Goal_Flag_E01();
bool Goal_Flag_E02();
bool Goal_Flag_E03();
