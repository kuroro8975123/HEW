#pragma once

#include <Windows.h>
#include <d3dx9.h>

#define SCREEN_WIDTH  (1980)              // �X�N���[��(�N���C�A���g�̈�)�̕�
#define SCREEN_HEIGHT  (968)              // �X�N���[��(�N���C�A���g�̈�)�̍���

//�E�B���h�E�n���h����Getter
HWND GetHWND();
double frand();
D3DXVECTOR2 GetAnimTbl(int set, int muki, int anim);