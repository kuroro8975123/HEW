#pragma once

void Timer_Initialize(void);
void Timer_Uninit(void);
void Timer_Update(void);
void Second_Draw(float x, float y, int second, int fig, bool bZero);
void Second_Draw(float x, float y, int second, int fig, bool bZero, float sx, float sy);
void Minute_Draw(float x, float y, int minute, int fig, bool bZero); 
void Minute_Draw(float x, float y, int minute, int fig, bool bZero, float sx, float sy);
int Timer_GetMinute();
int Timer_GetSecond();