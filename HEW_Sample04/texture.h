#pragma once

#include <d3d9.h>

typedef enum
{
	TEXTURE_INDEX_TITLE,//01.�^�C�g�����
	TEXTURE_INDEX_TUTORIAL,//02.�`���[�g���A�����
	TEXTURE_INDEX_GAME,//03.�Q�[�����	
	TEXTURE_INDEX_RESULT,//04.���U���g���
	TEXTURE_INDEX_PLAYER,//05.�v���C���[
	TEXTURE_INDEX_ENEMY,//06.�G�H
	TEXTURE_INDEX_NUMBER,//07.����
	TEXTURE_INDEX_3,//08.�J�E���g�_�E��
	TEXTURE_INDEX_2,//09.�J�E���g�_�E��
	TEXTURE_INDEX_1,//10.�J�E���g�_�E��
	TEXTURE_INDEX_START,//11.�J�E���g�_�E��
	TEXTURE_INDEX_BUTTON,//12.�{�^��
	TEXTURE_INDEX_PRESS, //13.pressanykey
	TEXTURE_INDEX_CHARASELE,//14.�L�����N�^�[�I��
	TEXTURE_INDEX_POOL,//15.�v�[��
	TEXTURE_INDEX_CHARASEN,//�L�����N�^�[��I�����Ă�������
	TEXTURE_INDEX_BUTTON2,//12.�{�^��2


	TEXTURE_INDEX_MAX
}TextureIndex;

int Texture_Load(void); //������
void Texture_Release(void); //�I������
LPDIRECT3DTEXTURE9 Texture_GetTexture(TextureIndex index);
int Texture_GetWidth(TextureIndex index);
int Texture_GetHeight(TextureIndex index);
