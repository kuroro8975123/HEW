#pragma once


#include <d3dx9.h>

void Uma_Initialize_1P(float x, float y);
void Uma_Initialize_2P(float x, float y);
void Uma_Finalize(void);
void Uma_Update_1P(void);
void Uma_Update_2P(void);
void Uma_Draw_1P(void);
void Uma_Draw_2P(void);

struct Uma
{
	D3DXVECTOR2 pos;
	float       speed;
	int			button;
	bool button_flag;
	bool end_flag;

};
struct Uma_2P
{
	D3DXVECTOR2 pos;
	float       speed;
	int			button;
	bool button_flag;
	bool end_flag;

};

void Uma_Button_1P();
void Uma_Button_2P();
bool Goal_Flag_1P_Uma();
bool Goal_Flag_2P_Uma();
bool End_1P_Uma();
bool End_2P_Uma();
float GetSpeed_1P_Uma();
float GetSpeed_2P_Uma();
int Minute_1P_Uma();
int Minute_2P_Uma();
int Second_1P_Uma();
int Second_2P_Uma();
