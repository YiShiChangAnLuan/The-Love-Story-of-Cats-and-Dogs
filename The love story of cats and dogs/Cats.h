#pragma once
#include "Animal.h"
#include "stdafx.h"
class CCats : 
	public CAnimal
{
public:
	CCats();
	~CCats();
	// 随机姓名
	void Rand_Name();
	//建立随机喵星人
	void Rand_Init_PerInfor();
};

