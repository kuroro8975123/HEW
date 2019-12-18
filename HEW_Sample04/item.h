#pragma once

#include <d3dx9.h>
#include "collision.h"

//Item�N���X
class Item
{
protected:	//���ł��Ȃ�
	CIRCLE	collision;
private:	//�q�N���X�Ȃ犱�\

public:		//�ǂ�����ł����\

	Item();						//�R���X�g���N�^
	~Item();						//�f�X�g���N�^

	virtual void Update() = 0;			//�X�V
	virtual void Draw() = 0;			//�`��

	virtual void ItemUse();			//�A�C�e���g�p
};

//�A�C�e��(�T��)�̃N���X -> Item_main�N���X
class Shark :public Item
{
protected:	//���ł��Ȃ�

private:	//�q�N���X�Ȃ犱�\

public:		//�ǂ�����ł����\
	
	Shark();		//�R���X�g���N�^
	//Shark(����);	//��������̃R���X�g���N�^
	~Shark();		//�f�X�g���N�^

	virtual void Update();		//�X�V
	virtual void Draw();		//�`��

};

//�A�C�e��(����)�̃N���X -> Item_main�N���X
class Cooking :public Item
{
protected:	//���ł��Ȃ�

private:	//�q�N���X�Ȃ犱�\

public:		//�ǂ�����ł����\

	Cooking();			//�R���X�g���N�^
	//Cooking(����);	//��������̃R���X�g���N�^
	~Cooking();			//�f�X�g���N�^

	virtual void Update();		//�X�V
	virtual void Draw();		//�`��

};

//�A�C�e��(�^�R�n)�̃N���X -> Item_main�N���X
class Oct :public Item
{
protected:	//���ł��Ȃ�

private:	//�q�N���X�Ȃ犱�\

public:		//�ǂ�����ł����\

	Oct();			//�R���X�g���N�^
	//Oct(����);	//��������̃R���X�g���N�^
	~Oct();			//�f�X�g���N�^

	virtual void Update();		//�X�V
	virtual void Draw();		//�`��

};

//�A�C�e��(��)�̃N���X -> Item_main�N���X
class Drag :public Item
{
protected:	//���ł��Ȃ�

private:	//�q�N���X�Ȃ犱�\

public:		//�ǂ�����ł����\

	
	Drag();			//�R���X�g���N�^
	//Drag(����);	//��������̃R���X�g���N�^
	~Drag();		//�f�X�g���N�^

	virtual void Update();		//�X�V
	virtual void Draw();		//�`��

};

//�A�C�e��(�����Ԓނ�)�̃N���X -> Item_main�N���X
class Fishing :public Item
{
protected:	//���ł��Ȃ�

private:	//�q�N���X�Ȃ犱�\

public:		//�ǂ�����ł����\
	
	Fishing();			//�R���X�g���N�^
	//Fishing(����);	//��������̃R���X�g���N�^
	~Fishing();			//�f�X�g���N�^

	virtual void Update();		//�X�V
	virtual void Draw();		//�`��

};

//�A�C�e��(�ɂ񂶂�)�̃N���X -> Item_main�N���X
class Carrot :public Item
{
protected:	//���ł��Ȃ�

private:	//�q�N���X�Ȃ犱�\

public:		//�ǂ�����ł����\

	Carrot();			//�R���X�g���N�^
	//Carrot(����);		//��������̃R���X�g���N�^
	~Carrot();			//�f�X�g���N�^

	virtual void Update();		//�X�V
	virtual void Draw();		//�`��

};