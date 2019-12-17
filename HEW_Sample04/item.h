#pragma once

#include <d3dx9.h>
#include "collision.h"

class Item_system
{
protected:
	int			pop_time;	//アイテムポップの時間
	int			pop_pos;	//アイテムポップの場所
	int			pop_cnt;	//アイテムポップのフレームカウント
private:

public:
	bool		Pop_item;	//アイテムの出現フラグ
	bool		Get_item;	//アイテム所持フラグ
	D3DXVECTOR2	pos;		//アイテムポップのポジション

	Item_system(int n);
	~Item_system();

	virtual void Update();
	virtual void Draw();

	virtual bool Get_ItemFrag();	//アイテム出現フラグのゲッター
	virtual bool Get_GetItem();		//アイテム取得のゲッター
};

//Itemクラス
class Item
{
protected:	//干渉できない
	CIRCLE	collision;
private:	//子クラスなら干渉可能

public:		//どこからでも干渉可能

	Item();						//コンストラクタ
	//Item(float x, float y);	//引数ありのコンストラクタ
	~Item();						//デストラクタ

	virtual void Update();			//更新
	virtual void Draw();			//描画

	virtual void ItemUse();			//アイテム使用
};

//アイテム(サメ)のクラス -> Item_mainクラス
class Shark :public Item
{
protected:	//干渉できない

private:	//子クラスなら干渉可能

public:		//どこからでも干渉可能
	
	Shark();		//コンストラクタ
	//Shark(引数);	//引数ありのコンストラクタ
	~Shark();		//デストラクタ

	virtual void Update();		//更新
	virtual void Draw();		//描画

};

//アイテム(調理)のクラス -> Item_mainクラス
class Cooking :public Item
{
protected:	//干渉できない

private:	//子クラスなら干渉可能

public:		//どこからでも干渉可能

	Cooking();			//コンストラクタ
	//Cooking(引数);	//引数ありのコンストラクタ
	~Cooking();			//デストラクタ

	virtual void Update();		//更新
	virtual void Draw();		//描画

};

//アイテム(タコ墨)のクラス -> Item_mainクラス
class Oct :public Item
{
protected:	//干渉できない

private:	//子クラスなら干渉可能

public:		//どこからでも干渉可能

	Oct();			//コンストラクタ
	//Oct(引数);	//引数ありのコンストラクタ
	~Oct();			//デストラクタ

	virtual void Update();		//更新
	virtual void Draw();		//描画

};

//アイテム(薬)のクラス -> Item_mainクラス
class Drag :public Item
{
protected:	//干渉できない

private:	//子クラスなら干渉可能

public:		//どこからでも干渉可能

	
	Drag();			//コンストラクタ
	//Drag(引数);	//引数ありのコンストラクタ
	~Drag();		//デストラクタ

	virtual void Update();		//更新
	virtual void Draw();		//描画

};

//アイテム(投げ網釣り)のクラス -> Item_mainクラス
class Fishing :public Item
{
protected:	//干渉できない

private:	//子クラスなら干渉可能

public:		//どこからでも干渉可能
	
	Fishing();			//コンストラクタ
	//Fishing(引数);	//引数ありのコンストラクタ
	~Fishing();			//デストラクタ

	virtual void Update();		//更新
	virtual void Draw();		//描画

};

//アイテム(にんじん)のクラス -> Item_mainクラス
class Carrot :public Item
{
protected:	//干渉できない

private:	//子クラスなら干渉可能

public:		//どこからでも干渉可能

	Carrot();			//コンストラクタ
	//Carrot(引数);		//引数ありのコンストラクタ
	~Carrot();			//デストラクタ

	virtual void Update();		//更新
	virtual void Draw();		//描画

};