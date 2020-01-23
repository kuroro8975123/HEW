//#pragma once
//
//#include <d3dx9.h>
//
////Character_mainクラス
//class Character_main
//{
//protected:	//干渉できない
//				//位置
//private:	//子クラスなら干渉可能
//	
//	D3DXVECTOR2 pos;
//	float       speed;          //スピード
//	int			button;
//	bool button_flag;
//	bool end_flag;
//
//public:		//どこからでも干渉可能
//	int select;
//
//	Character_main();		//コンストラクタ
//	Character_main(float x, float y);	//引数ありのコンストラクタ
//	~Character_main();		//デストラクタ
//
//	virtual void Update();		//更新
//	virtual void Draw();		//描画
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
////カジキちゃん
//class Kaziki :public Character_main
//{
//protected:
//
//private:
//	D3DXVECTOR2 pos;
//	float       speed;          //スピード
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
////クジラ
//class Kujira :public Character_main
//{
//protected:
//
//private:
//	D3DXVECTOR2 pos;
//	float       speed;          //スピード
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
////イルカ
//class Iruka :public Character_main
//{
//protected:
//
//private:
//	D3DXVECTOR2 pos;
//	float       speed;          //スピード
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
////馬
//class Uma :public Character_main
//{
//protected:
//
//private:
//	D3DXVECTOR2 pos;
//	float       speed;          //スピード
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
