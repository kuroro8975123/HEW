//
//	�t�@�C���C���N���[�h
//

#include "main.h"
#include "minimap.h"
#include "player.h"
#include "sprite.h"
#include "game.h"

//
//	�}�N����`
//

//�ԓ_�̏����ʒu(���s���ʂ����Ē���)
#define POINT_POS_X		(1700.0f)
#define POINT_POS_Y		(500.0f)


//
//	�v���g�^�C�v�錾
//

typedef struct 
{

	D3DXVECTOR2 pos;
	
}Pos_Data;


//
//	�O���[�o���錾
//

Pos_Data			g_posPoint[2];

//�v���C���[�̈ʒu������
static	D3DXVECTOR2	g_playerpos[2];

//������
void Minimap_Initialize() {

	for (int i = 0; i < 2; i++)
	{
		g_posPoint[i].pos.x = POINT_POS_X + i * 100.0f;
		g_posPoint[i].pos.y = POINT_POS_Y;
	}

}

//�I��
void Minimap_Finalize() {

}

//�X�V
void Minimap_Update() {

	for (int i = 0; i < 2;i++)
	{
		//�v���C���[�̈ʒu���擾(�����̓v���C���[�̔ԍ�)
		//g_posPoint[i]=Get_PlayerPos(i);

		//�v���C���[�̈ʒu���~�j�}�b�v�ɔ��f
		//���s���ʂ����Ȃ���ʒu����
		//g_posPoint[i].pos.y += g_playerpos[i].y / 10.0f;
	}
}

//�`��
void Minimap_Draw() {

	//�~�j�}�b�v�̕\��
	//Sprite_Draw(TEXTURE_INDEX_MAP,1000.0f,100.0f);

	//�~�j�}�b�v�̒��̐ԓ_�\��
	for (int i = 0; i < 2; i++)
	{
		//Sprite_Draw(TEXTURE_INDEX_POINT,g_posPoint[i].pos.x,g_posPoint[i].pos.y)
	}

}