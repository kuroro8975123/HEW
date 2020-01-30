#pragma once

#include <d3d9.h>

typedef enum TextureIndex
{
	TEXTURE_INDEX_TITLE1,			//01.�^�C�g�����
	TEXTURE_INDEX_TITLE2,			//02.�^�C�g�����
	TEXTURE_INDEX_TUTORIAL,		//03.�`���[�g���A�����
	TEXTURE_INDEX_GAME,				//04.�Q�[�����	
	TEXTURE_INDEX_RESULT,			//05.���U���g���
	TEXTURE_INDEX_PLAYER,			//06.�v���C���[
	TEXTURE_INDEX_ENEMY,			//07.�G�H
	TEXTURE_INDEX_NUMBER,		//08.����
	TEXTURE_INDEX_3,					//09.�J�E���g�_�E��
	TEXTURE_INDEX_2,					//10.�J�E���g�_�E��
	TEXTURE_INDEX_1,					//11.�J�E���g�_�E��
	TEXTURE_INDEX_START,			//12.�J�E���g�_�E��
	TEXTURE_INDEX_BUTTON,			//13.�{�^��
	TEXTURE_INDEX_PRESS,			//14.pressanykey
	TEXTURE_INDEX_CHARASELE,	//15.�L�����N�^�[�I��
	TEXTURE_INDEX_POOL,				//16.�v�[��
	TEXTURE_INDEX_CHARASEN,		//17.�L�����N�^�[��I�����Ă�������
	TEXTURE_INDEX_BUTTON2,		//18.�{�^��2
	TEXTURE_INDEX_BLOCK,			//19.�u���b�N�T���v��
	TEXTURE_INDEX_A_BUTTON,		//20.A�{�^��
	TEXTURE_INDEX_B_BUTTON,		//21.B�{�^��		
	TEXTURE_INDEX_X_BUTTON,		//22.X�{�^��
	TEXTURE_INDEX_Y_BUTTON,		//23.Y�{�^��
	TEXTURE_INDEX_KAZIKI,			//24.�J�W�L
	TEXTURE_INDEX_KUZIRA,			//25.�N�W��
	TEXTURE_INDEX_IRUKA,			//26.�C���J
	TEXTURE_INDEX_UMA,				//27.�n
	TEXTURE_INDEX_MAP,				//28.�}�b�v
	TEXTURE_INDEX_BG,				//29.�w�i
	TEXTURE_INDEX_KAZIKI_ANIMATION, //�J�W�L
	TEXTURE_INDEX_UMA_ANIMATION,    //�n
	TEXTURE_INDEX_IRUKA_ANIMATION,  //�C���J
	TEXTURE_INDEX_KUZIRA_ANIMATION, //�N�W��
	TEXTURE_INDEX_KAZIKI_SELECT, //�J�W�L
	TEXTURE_INDEX_KUJIRA_SELECT, //�N�W��
	TEXTURE_INDEX_IRUKA_SELECT, //�C���J
	TEXTURE_INDEX_UMA_SELECT,   //�n
	TEXTURE_INDEX_LEFT,        //��
	TEXTURE_INDEX_RIGHT,       //�E
	TEXTURE_INDEX_WINNER,      //����
	TEXTURE_INDEX_LOSER,       //�s�k
	TEXTURE_INDEX_WORLDRECORD, //���E�L�^
	TEXTURE_INDEX_1P,          //1P
	TEXTURE_INDEX_2P,          //2P
	TEXTURE_INDEX_1ST,          //1st
	TEXTURE_INDEX_2ND,          //2nd
	TEXTURE_INDEX_3RD,          //3rd
	TEXTURE_INDEX_4TH,          //4th
	TEXTURE_INDEX_5TH,          //5th
<<<<<<< HEAD
	TEXTURE_INDEX_1P_MAP,          //1P
	TEXTURE_INDEX_2P_MAP,          //1P

=======
	TEXTURE_INDEX_START_GOAL,		//�X�^�[�g�ƃS�[��
>>>>>>> 30c7be4363dd7eb0345bf129664dd2c93b975c90
	TEXTURE_INDEX_MAX
};


int Texture_Load(void); //������
void Texture_Release(void); //�I������
LPDIRECT3DTEXTURE9 Texture_GetTexture(TextureIndex index);
int Texture_GetWidth(TextureIndex index);
int Texture_GetHeight(TextureIndex index);