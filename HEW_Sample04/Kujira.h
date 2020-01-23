#pragma once

#include <d3dx9.h>

void Kujira_Initialize_1P(float x, float y);
void Kujira_Initialize_2P(float x, float y);
void Kujira_Finalize(void);
void Kujira_Update_1P(void);
void Kujira_Update_2P(void);
void Kujira_Draw_1P(void);
void Kujira_Draw_2P(void);

struct Kujira
{
	D3DXVECTOR2 pos;
	float       speed;
	int			button;
	bool button_flag;
	bool end_flag;

};
struct Kujira_2P
{
	D3DXVECTOR2 pos;
	float       speed;
	int			button;
	bool button_flag;
	bool end_flag;

};

void Kujira_Button_1P();
void Kujira_Button_2P();
bool Goal_Flag_1P_Kujira();
bool Goal_Flag_2P_Kujira();
bool End_1P_Kujira();
bool End_2P_Kujira();
float GetSpeed_1P_Kujira();
float GetSpeed_2P_Kujira();
int Minute_1P_Kujira();
int Minute_2P_Kujira();
int Second_1P_Kujira();
int Second_2P_Kujira();
