#pragma once
#include "Animal.h"
#include "stdafx.h"
class CDog :
	public CAnimal
{
public:
	CDog();
	~CDog();
	// 随机姓名
	void Rand_Name();
	//建立随机汪星人
	void Rand_Init_PerInfor();
};

