#pragma once

//Character_main�N���X
class Character_main
{
protected:	//���ł��Ȃ�

private:	//�q�N���X�Ȃ犱�\

public:		//�ǂ�����ł����\

	Character_main();		//�R���X�g���N�^
	//Item_main(����)	//��������̃R���X�g���N�^
	~Character_main();		//�f�X�g���N�^

	//void Initialize();	//������
	//void Finalize();	//�I��
	void Update();		//�X�V
	void Draw();		//�`��

};


void Player_Initialize(void);
void Player_Finalize(void);
void Player_Update(void);
void Player_Draw(void);

float Player_GetSpeed();
bool Player_End();

