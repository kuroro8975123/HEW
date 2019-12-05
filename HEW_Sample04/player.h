#pragma once

#include <d3dx9.h>

//Character_main�N���X
class Character_main
{
protected:	//���ł��Ȃ�
				//�ʒu
private:	//�q�N���X�Ȃ犱�\
	
	D3DXVECTOR2 pos;
	float       speed;          //�X�s�[�h
	int button;
	bool button_flag;
	bool end_flag;

public:		//�ǂ�����ł����\
	

	Character_main(float x,float y);		//�R���X�g���N�^
	//Item_main(����)	//��������̃R���X�g���N�^
	~Character_main();		//�f�X�g���N�^

	//void Initialize();	//������
	//void Finalize();	//�I��
	virtual void Update();		//�X�V
	virtual void Draw();		//�`��

	virtual float Player_GetSpeed()
	{
		return speed;
	}

	virtual bool Player_End()
	{
		return end_flag;
	}

};


//void Player_Initialize(void);
//void Player_Finalize(void);
//void Player_Update(void);
//void Player_Draw(void);
//
//float Player_GetSpeed();
//bool Player_End();

