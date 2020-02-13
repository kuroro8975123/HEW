#pragma once

#include <d3dx9.h>

void Iruka_Initialize_1P(float x, float y);
void Iruka_Initialize_2P(float x, float y);
void Iruka_Finalize(void);
void Iruka_Update_1P(void);
void Iruka_Update_2P(void);
void Iruka_Draw_1P(void);
void Iruka_Draw_2P(void);

struct Iruka
{
	D3DXVECTOR2 pos;
	float       speed;
	int			button;
	bool button_flag;
	bool end_flag;

};
struct Iruka_2P
{
	D3DXVECTOR2 pos;
	float       speed;         
	int			button;
	bool button_flag;
	bool end_flag;

};

void Iruka_Button_1P();
void Iruka_Button_2P();
bool Goal_Flag_1P_Iruka();
bool Goal_Flag_2P_Iruka();
bool End_1P_Iruka();
bool End_2P_Iruka();
float GetSpeed_1P_Iruka();
float GetSpeed_2P_Iruka();
int Minute_1P_Iruka();
int Minute_2P_Iruka();
int Second_1P_Iruka();
int Second_2P_Iruka();
float Iruka_Speed_1P();
float Iruka_Speed_2P();

