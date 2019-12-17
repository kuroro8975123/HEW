/*================================
	Item_main.cpp
	制作:岡部　友紀
	最終更新日:2019_12_05(Thr)
================================*/

#include "item.h"
#include "main.h"
#include "sprite.h"
#include "texture.h"
#include "input.h"


//Item_systemクラスの関数-------------------------------

Item_system::Item_system(int n) {
	pos.x = 27.0f + n * 255;	pos.y = 32.0f;
	Pop_item = false;
}

Item_system::~Item_system(){

}

void Item_system::Update(){

	//アイテムのポップ処理を書く。
	
	if (!Pop_item)
	{
		pop_pos = rand() % 3;
		Pop_item = true;
	}
	//アイテムの移動を書く。


	//プレイヤーとの当たり判定、取得後のアイテム抽選処理を書く。


}

void Item_system::Draw() {

	if (Pop_item)
		Sprite_Draw(TEXTURE_INDEX_BLOCK, pos.x + pop_pos * 75, pos.y);
}

bool Item_system::Get_ItemFrag(){
	return Pop_item;
}

bool Item_system::Get_GetItem() {
	return Get_item;
}

//Itemクラスの関数--------------------------------------

//コンストラクタ
Item::Item() {

}
//引数ありのコンストラクタ
//Item::Item(float x,float y) {
//	pos.x = x;	pos.y = y;
//}
//デストラクタ
Item::~Item() {
	
}
//更新
void Item::Update() {

}
//描画
void Item::Draw() {
	
}

//アイテム使用
void Item::ItemUse() {

}


//Sharkクラスの関数------------------------------------------

//コンストラクタ
Shark::Shark(){

}
//デストラクタ
Shark::~Shark() {

}
//更新
void Shark::Update() {

}
//描画
void Shark::Draw() {

}

//Cookingクラスの関数----------------------------------------

//コンストラクタ
Cooking::Cooking() {

}
//デストラクタ
Cooking::~Cooking() {

}
//更新
void Cooking::Update() {

}
//描画
void Cooking::Draw() {

}

//Octクラスの関数--------------------------------------------

//コンストラクタ
Oct::Oct() {

}
//デストラクタ
Oct::~Oct() {

}
//更新
void Oct::Update() {

}
//描画
void Oct::Draw() {

}

//Dragクラスの関数-------------------------------------------

//コンストラクタ
Drag::Drag() {

}
//デストラクタ
Drag::~Drag() {

}
//更新
void Drag::Update() {

}
//描画
void Drag::Draw() {

}

//Fishingクラスの関数----------------------------------------

//コンストラクタ
Fishing::Fishing() {

}
//デストラクタ
Fishing::~Fishing() {

}
//更新
void Fishing::Update() {

}
//描画
void Fishing::Draw() {

}

//Carrotクラスの関数-----------------------------------------

//コンストラクタ
Carrot::Carrot() {

}
//デストラクタ
Carrot::~Carrot() {

}
//更新
void Carrot::Update() {

}
//描画
void Carrot::Draw() {

}