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
#include "collision.h"

//Item_main�N���X�̊֐�--------------------------------------

//�R���X�g���N�^
Item_main::Item_main() {

}
//��������̃R���X�g���N�^
Item_main::Item_main(float x,float y) {
	pos.x = x;	pos.y = y;
	Get_item = false;
}
//�f�X�g���N�^
Item_main::~Item_main() {

}
//�X�V
void Item_main::Update() {

}
//�`��
void Item_main::Draw() {

}

//�A�C�e���g�p
void Item_main::ItemUse() {

}

//�A�C�e�������t���O�̃Q�b�^�[
bool Item_main::Get_ItemFrag() {
	return	Item_main::Get_item;
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