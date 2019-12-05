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
#include "collision.h"

//Item_mainクラスの関数--------------------------------------

//コンストラクタ
Item_main::Item_main() {

}
//引数ありのコンストラクタ
Item_main::Item_main(float x,float y) {
	pos.x = x;	pos.y = y;
	Get_item = false;
}
//デストラクタ
Item_main::~Item_main() {

}
//更新
void Item_main::Update() {

}
//描画
void Item_main::Draw() {

}

//アイテム使用
void Item_main::ItemUse() {

}

//アイテム所持フラグのゲッター
bool Item_main::Get_ItemFrag() {
	return	Item_main::Get_item;
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