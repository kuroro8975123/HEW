/*================================
	Item_main.cpp
	����:�����@�F�I
	�ŏI�X�V��:2019_12_05(Thr)
================================*/

#include "item.h"
#include "main.h"
#include "sprite.h"
#include "texture.h"
#include "input.h"


//Item_system�N���X�̊֐�-------------------------------

Item_system::Item_system(int n) {
	pos.x = 27.0f + n * 255;	pos.y = 32.0f;
	Pop_item = false;
}

Item_system::~Item_system(){

}

void Item_system::Update(){

	//�A�C�e���̃|�b�v�����������B
	
	if (!Pop_item)
	{
		pop_pos = rand() % 3;
		Pop_item = true;
	}
	//�A�C�e���̈ړ��������B


	//�v���C���[�Ƃ̓����蔻��A�擾��̃A�C�e�����I�����������B


}

void Item_system::Draw() {

	if (Pop_item)
		Sprite_Draw(TEXTURE_INDEX_BLOCK, pos.x + pop_pos * 75, pos.y);
}

bool Item_system::Get_ItemFrag(){
	return Pop_item;
}

bool Item_system::Get_GetItem() {
	return Get_item;
}

//Item�N���X�̊֐�--------------------------------------

//�R���X�g���N�^
Item::Item() {

}
//��������̃R���X�g���N�^
//Item::Item(float x,float y) {
//	pos.x = x;	pos.y = y;
//}
//�f�X�g���N�^
Item::~Item() {
	
}
//�X�V
void Item::Update() {

}
//�`��
void Item::Draw() {
	
}

//�A�C�e���g�p
void Item::ItemUse() {

}


//Shark�N���X�̊֐�------------------------------------------

//�R���X�g���N�^
Shark::Shark(){

}
//�f�X�g���N�^
Shark::~Shark() {

}
//�X�V
void Shark::Update() {

}
//�`��
void Shark::Draw() {

}

//Cooking�N���X�̊֐�----------------------------------------

//�R���X�g���N�^
Cooking::Cooking() {

}
//�f�X�g���N�^
Cooking::~Cooking() {

}
//�X�V
void Cooking::Update() {

}
//�`��
void Cooking::Draw() {

}

//Oct�N���X�̊֐�--------------------------------------------

//�R���X�g���N�^
Oct::Oct() {

}
//�f�X�g���N�^
Oct::~Oct() {

}
//�X�V
void Oct::Update() {

}
//�`��
void Oct::Draw() {

}

//Drag�N���X�̊֐�-------------------------------------------

//�R���X�g���N�^
Drag::Drag() {

}
//�f�X�g���N�^
Drag::~Drag() {

}
//�X�V
void Drag::Update() {

}
//�`��
void Drag::Draw() {

}

//Fishing�N���X�̊֐�----------------------------------------

//�R���X�g���N�^
Fishing::Fishing() {

}
//�f�X�g���N�^
Fishing::~Fishing() {

}
//�X�V
void Fishing::Update() {

}
//�`��
void Fishing::Draw() {

}

//Carrot�N���X�̊֐�-----------------------------------------

//�R���X�g���N�^
Carrot::Carrot() {

}
//�f�X�g���N�^
Carrot::~Carrot() {

}
//�X�V
void Carrot::Update() {

}
//�`��
void Carrot::Draw() {

}