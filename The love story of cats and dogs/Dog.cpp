#include "stdafx.h"
#include "Dog.h"


CDog::CDog()
{
	Kind = "������";
	int_kind = 1;
	Rand_Init_PerInfor();
}


CDog::~CDog()
{
}


// �������
void CDog::Rand_Name()
{
	srand((unsigned int)time(NULL));
	int tmp;
	string name[25] = { "Ң�","����","�ʕF","����","�հ�",
		"����","����","���","����","����",
		"����","Ǭ��","����","����","����",
		"����","����","����","��޿","���",
		"���","����","ʿ��","����","����", };
	tmp = rand() % 24;
	Name = name[tmp];
}

void CDog::Rand_Init_PerInfor()
{
	Rand_Name();
	Score_Anger = 0;
	srand((unsigned int)time(0));
	int age = rand() % (35 - 18 + 1) + 18;	Age = age;
	int face = rand() % 100; Score_Face = face;
	int loyalty = rand() % 100; Score_Loyalty = loyalty;
	int patience = rand() % 100; Score_Patience = patience;
	int charm = rand() % 100; Score_Charm = charm;
	int deposit = rand() % 100000000; Score_Deposit = deposit;
	int tmp = rand() % 3;
	Sleep(1000);
}