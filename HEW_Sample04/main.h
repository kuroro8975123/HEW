#pragma once

#include <Windows.h>
#include <d3dx9.h>

#define SCREEN_WIDTH  (1980)              // スクリーン(クライアント領域)の幅
#define SCREEN_HEIGHT  (968)              // スクリーン(クライアント領域)の高さ

//ウィンドウハンドルのGetter
HWND GetHWND();
double frand();
D3DXVECTOR2 GetAnimTbl(int set, int muki, int anim);