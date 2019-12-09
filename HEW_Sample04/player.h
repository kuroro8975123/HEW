#pragma once

#include <d3dx9.h>

//Character_mainクラス
class Character_main
{
protected:	//干渉できない
				//位置
private:	//子クラスなら干渉可能
	
	D3DXVECTOR2 pos;
	float       speed;          //スピード
	int button;
	bool button_flag;
	bool end_flag;

public:		//どこからでも干渉可能
	

	Character_main(float x,float y);		//コンストラクタ
	//Item_main(引数)	//引数ありのコンストラクタ
	~Character_main();		//デストラクタ

	//void Initialize();	//初期化
	//void Finalize();	//終了
	virtual void Update();		//更新
	virtual void Draw();		//描画

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

