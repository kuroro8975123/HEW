#pragma once

//Item_main�N���X
class Item_main
{
protected:	//���ł��Ȃ�

private:	//�q�N���X�Ȃ犱�\

public:		//�ǂ�����ł����\

	Item_main();		//�R���X�g���N�^
	//Item_main(����)	//��������̃R���X�g���N�^
	~Item_main();		//�f�X�g���N�^

	void Initialize();	//������
	void Finalize();	//�I��
	void Update();		//�X�V
	void Draw();		//�`��

};

//�A�C�e��(�T��)�̃N���X -> Item_main�N���X
class Shark :public Item_main
{
protected:	//���ł��Ȃ�

private:	//�q�N���X�Ȃ犱�\

public:		//�ǂ�����ł����\
	
	Shark();		//�R���X�g���N�^
	//Shark(����);	//��������̃R���X�g���N�^
	~Shark();		//�f�X�g���N�^

	void Initialize();	//������
	void Finalize();	//�I��
	void Update();		//�X�V
	void Draw();		//�`��

};

//�A�C�e��(����)�̃N���X -> Item_main�N���X
class Cooking :public Item_main
{
protected:	//���ł��Ȃ�

private:	//�q�N���X�Ȃ犱�\

public:		//�ǂ�����ł����\

	Cooking();			//�R���X�g���N�^
	//Cooking(����);	//��������̃R���X�g���N�^
	~Cooking();			//�f�X�g���N�^

	void Initialize();	//������
	void Finalize();	//�I��
	void Update();		//�X�V
	void Draw();		//�`��

};

//�A�C�e��(�^�R�n)�̃N���X -> Item_main�N���X
class Oct :public Item_main
{
protected:	//���ł��Ȃ�

private:	//�q�N���X�Ȃ犱�\

public:		//�ǂ�����ł����\

	Oct();			//�R���X�g���N�^
	//Oct(����);	//��������̃R���X�g���N�^
	~Oct();			//�f�X�g���N�^

	void Initialize();	//������
	void Finalize();	//�I��
	void Update();		//�X�V
	void Draw();		//�`��

};

//�A�C�e��(��)�̃N���X -> Item_main�N���X
class Drag :public Item_main
{
protected:	//���ł��Ȃ�

private:	//�q�N���X�Ȃ犱�\

public:		//�ǂ�����ł����\

	
	Drag();			//�R���X�g���N�^
	//Drag(����);	//��������̃R���X�g���N�^
	~Drag();		//�f�X�g���N�^

	void Initialize();	//������
	void Finalize();	//�I��
	void Update();		//�X�V
	void Draw();		//�`��

};

//�A�C�e��(�ނ�)�̃N���X -> Item_main�N���X
class Fishing :public Item_main
{
protected:	//���ł��Ȃ�

private:	//�q�N���X�Ȃ犱�\

public:		//�ǂ�����ł����\
	
	Fishing();			//�R���X�g���N�^
	//Fishing(����);	//��������̃R���X�g���N�^
	~Fishing();			//�f�X�g���N�^

	void Initialize();	//������
	void Finalize();	//�I��
	void Update();		//�X�V
	void Draw();		//�`��

};

//�A�C�e��(�ɂ񂶂�)�̃N���X -> Item_main�N���X
class Carrot :public Item_main
{
protected:	//���ł��Ȃ�

private:	//�q�N���X�Ȃ犱�\

public:		//�ǂ�����ł����\

	Carrot();			//�R���X�g���N�^
	//Carrot(����);		//��������̃R���X�g���N�^
	~Carrot();			//�f�X�g���N�^

	void Initialize();	//������
	void Finalize();	//�I��
	void Update();		//�X�V
	void Draw();		//�`��

};