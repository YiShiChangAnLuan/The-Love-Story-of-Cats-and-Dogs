#pragma once
#include "Animal.h"
#include "stdafx.h"
class CDog :
	public CAnimal
{
public:
	CDog();
	~CDog();
	// �������
	void Rand_Name();
	//�������������
	void Rand_Init_PerInfor();
};

