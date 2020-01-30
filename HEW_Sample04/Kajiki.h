#pragma once

#include <d3dx9.h>

void Kajiki_Initialize_1P(float x, float y);
void Kajiki_Initialize_2P(float x, float y);
void Kajiki_Finalize(void);
void Kajiki_Update_1P(void);
void Kajiki_Update_2P(void);
void Kajiki_Draw_1P(void);
void Kajiki_Draw_2P(void);

struct Kajiki
{
	D3DXVECTOR2 pos;
	float       speed;
	int			button;
	bool button_flag;
	bool end_flag;

};
struct Kajiki_2P
{
	D3DXVECTOR2 pos;
	float       speed;
	int			button;
	bool button_flag;
	bool end_flag;

};

void Kajiki_Button_1P();
void Kajiki_Button_2P();
bool Goal_Flag_1P_Kajiki();
bool Goal_Flag_2P_Kajiki();
bool End_1P_Kajiki();
bool End_2P_Kajiki();
float GetSpeed_1P_Kajiki();
float GetSpeed_2P_Kajiki();
int Minute_1P_Kajiki();
int Minute_2P_Kajiki();
int Second_1P_Kajiki();
int Second_2P_Kajiki();
float Kajiki_Speed_1P();
float Kajiki_Speed_2P();

