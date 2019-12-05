#pragma once

//Item_mainクラス
class Item_main
{
protected:	//干渉できない

private:	//子クラスなら干渉可能

public:		//どこからでも干渉可能

	Item_main();		//コンストラクタ
	//Item_main(引数)	//引数ありのコンストラクタ
	~Item_main();		//デストラクタ

	void Initialize();	//初期化
	void Finalize();	//終了
	void Update();		//更新
	void Draw();		//描画

};

//アイテム(サメ)のクラス -> Item_mainクラス
class Shark :public Item_main
{
protected:	//干渉できない

private:	//子クラスなら干渉可能

public:		//どこからでも干渉可能
	
	Shark();		//コンストラクタ
	//Shark(引数);	//引数ありのコンストラクタ
	~Shark();		//デストラクタ

	void Initialize();	//初期化
	void Finalize();	//終了
	void Update();		//更新
	void Draw();		//描画

};

//アイテム(調理)のクラス -> Item_mainクラス
class Cooking :public Item_main
{
protected:	//干渉できない

private:	//子クラスなら干渉可能

public:		//どこからでも干渉可能

	Cooking();			//コンストラクタ
	//Cooking(引数);	//引数ありのコンストラクタ
	~Cooking();			//デストラクタ

	void Initialize();	//初期化
	void Finalize();	//終了
	void Update();		//更新
	void Draw();		//描画

};

//アイテム(タコ墨)のクラス -> Item_mainクラス
class Oct :public Item_main
{
protected:	//干渉できない

private:	//子クラスなら干渉可能

public:		//どこからでも干渉可能

	Oct();			//コンストラクタ
	//Oct(引数);	//引数ありのコンストラクタ
	~Oct();			//デストラクタ

	void Initialize();	//初期化
	void Finalize();	//終了
	void Update();		//更新
	void Draw();		//描画

};

//アイテム(薬)のクラス -> Item_mainクラス
class Drag :public Item_main
{
protected:	//干渉できない

private:	//子クラスなら干渉可能

public:		//どこからでも干渉可能

	
	Drag();			//コンストラクタ
	//Drag(引数);	//引数ありのコンストラクタ
	~Drag();		//デストラクタ

	void Initialize();	//初期化
	void Finalize();	//終了
	void Update();		//更新
	void Draw();		//描画

};

//アイテム(釣り)のクラス -> Item_mainクラス
class Fishing :public Item_main
{
protected:	//干渉できない

private:	//子クラスなら干渉可能

public:		//どこからでも干渉可能
	
	Fishing();			//コンストラクタ
	//Fishing(引数);	//引数ありのコンストラクタ
	~Fishing();			//デストラクタ

	void Initialize();	//初期化
	void Finalize();	//終了
	void Update();		//更新
	void Draw();		//描画

};

//アイテム(にんじん)のクラス -> Item_mainクラス
class Carrot :public Item_main
{
protected:	//干渉できない

private:	//子クラスなら干渉可能

public:		//どこからでも干渉可能

	Carrot();			//コンストラクタ
	//Carrot(引数);		//引数ありのコンストラクタ
	~Carrot();			//デストラクタ

	void Initialize();	//初期化
	void Finalize();	//終了
	void Update();		//更新
	void Draw();		//描画

};