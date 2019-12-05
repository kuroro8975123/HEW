#pragma once

//Character_mainクラス
class Character_main
{
protected:	//干渉できない

private:	//子クラスなら干渉可能

public:		//どこからでも干渉可能

	Character_main();		//コンストラクタ
	//Item_main(引数)	//引数ありのコンストラクタ
	~Character_main();		//デストラクタ

	//void Initialize();	//初期化
	//void Finalize();	//終了
	void Update();		//更新
	void Draw();		//描画

};


void Player_Initialize(void);
void Player_Finalize(void);
void Player_Update(void);
void Player_Draw(void);

float Player_GetSpeed();
bool Player_End();

