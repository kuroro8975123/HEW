#pragma once

#include <d3dx9.h>

struct Select_Kaziki
{
	D3DXVECTOR2 pos;
	bool flag;
};

struct Select_Kujira
{
	D3DXVECTOR2 pos;
	bool flag;
};

struct Select_Iruka
{
	D3DXVECTOR2 pos;
	bool flag;
};

struct Select_Uma
{
	D3DXVECTOR2 pos;
	bool flag;
};

void P_Select_Initialize(void);
void P_Select_Finalize(void);
void P_Select_Update(void);
void P_Select_Draw(void);

int Get_Select_1P();
int Get_Select_2P();

