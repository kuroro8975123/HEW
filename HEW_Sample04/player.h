//#pragma once
//
//#include <d3dx9.h>
//
////Character_main�N���X
//class Character_main
//{
//protected:	//���ł��Ȃ�
//				//�ʒu
//private:	//�q�N���X�Ȃ犱�\
//	
//	D3DXVECTOR2 pos;
//	float       speed;          //�X�s�[�h
//	int			button;
//	bool button_flag;
//	bool end_flag;
//
//public:		//�ǂ�����ł����\
//	int select;
//
//	Character_main();		//�R���X�g���N�^
//	Character_main(float x, float y);	//��������̃R���X�g���N�^
//	~Character_main();		//�f�X�g���N�^
//
//	virtual void Update();		//�X�V
//	virtual void Draw();		//�`��
//
//	virtual float Player_GetSpeed()
//	{
//		return speed;
//	}
//
//	virtual bool Player_End()
//	{
//		return end_flag;
//	}
//
//	virtual int Player_GetSelect()
//	{
//		return select;
//	}
//};
//
////�J�W�L�����
//class Kaziki :public Character_main
//{
//protected:
//
//private:
//	D3DXVECTOR2 pos;
//	float       speed;          //�X�s�[�h
//	int			button;
//	bool button_flag;
//	bool end_flag;
//public:
//
//	Kaziki();
//	~Kaziki();
//
//	virtual void Update();
//	virtual void Draw();
//};
//
////�N�W��
//class Kujira :public Character_main
//{
//protected:
//
//private:
//	D3DXVECTOR2 pos;
//	float       speed;          //�X�s�[�h
//	int			button;
//	bool button_flag;
//	bool end_flag;
//public:
//
//	Kujira();
//	~Kujira();
//	
//	virtual void Update();
//	virtual void Draw();
//};
//
////�C���J
//class Iruka :public Character_main
//{
//protected:
//
//private:
//	D3DXVECTOR2 pos;
//	float       speed;          //�X�s�[�h
//	int			button;
//	bool button_flag;
//	bool end_flag;
//public:
//
//	Iruka();
//	~Iruka();
//
//	virtual void Update();
//	virtual void Draw();
//};
//
////�n
//class Uma :public Character_main
//{
//protected:
//
//private:
//	D3DXVECTOR2 pos;
//	float       speed;          //�X�s�[�h
//	int			button;
//	bool button_flag;
//	bool end_flag;
//public:
//
//	Uma();
//	~Uma();
//
//	virtual void Update();
//	virtual void Draw();
//};
//
