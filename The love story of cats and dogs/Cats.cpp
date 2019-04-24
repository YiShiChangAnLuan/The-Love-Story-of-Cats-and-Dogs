#include "stdafx.h"
#include "Cats.h"


CCats::CCats()
{
	Kind = "ß÷ĞÇÈË";
	int_kind = 2;
	Rand_Init_PerInfor();
}


CCats::~CCats()
{
}


void CCats::Rand_Name()
{
	srand((unsigned int)time(NULL));
	int tmp;
	string name[25] = {
		"°²°²","ÇIÇI","°²»Ü","¾ıÄÈ","Óïµû",
		"¸èÀ»","¸èÔÏ","¸êÑÅ","º®Ñã","ºÍÃÀ",
		"¼ÒÜ°","¼ÑÔÃ","À¼ÃÎ","ÂüÇà","ÂüÀö",
		"æ¹ÄÈ","·¼ğ¥","¹ÅÔÏ","¹ÈÑ©","¹åçâ",
		"º£¶ù","º¬ÎÄ","ºÍâù","ºÓÁé","ºÉ×Ï" };
	tmp = rand() % 24;
	Name = name[tmp];
}

void CCats::Rand_Init_PerInfor()
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