#pragma once

#include <Windows.h>
#include <d3dx9.h>

#define SCREEN_WIDTH  (1920)              // スクリーン(クライアント領域)の幅
#define SCREEN_HEIGHT  (1080)              // スクリーン(クライアント領域)の高さ

//ウィンドウハンドルのGetter
HWND GetHWND();
double frand();
