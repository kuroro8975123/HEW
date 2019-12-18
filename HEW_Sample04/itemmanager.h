/*======================
	アイテム管理クラス
======================*/

#pragma once

#include "item.h"

class ItemManager
{
private:
	ItemManager *pImanager;
	bool		ispop;


public:

	ItemManager();
	~ItemManager();

	void Popitem();

<<<<<<< HEAD
	//bool GetPopFrag();
=======
	bool GetPopFrag();
>>>>>>> f65add46e1bfe07b1bf22c6ae4ffc1142dc17cc1
};