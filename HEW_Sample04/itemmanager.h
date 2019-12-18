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

	bool GetPopFrag();
};