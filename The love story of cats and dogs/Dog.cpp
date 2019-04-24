#include "stdafx.h"
#include "Dog.h"


CDog::CDog()
{
	Kind = "ÍôĞÇÈË";
	int_kind = 1;
	Rand_Init_PerInfor();
}


CDog::~CDog()
{
}


// Ëæ»úĞÕÃû
void CDog::Rand_Name()
{
	srand((unsigned int)time(NULL));
	int tmp;
	string name[25] = { "Ò¢ê»","·¶·É","ÀÊ•F","¾°êÏ","ÈÕ°º",
		"À¥ÎÄ","°ºÓî","ê»êÍ","°º¸ß","º­³¬",
		"ºèÆø","Ç¬³½","»ÀÀö","ÖÙÓî","¿ª×æ",
		"ËÉÕÕ","ïØÕÜ","ÄÁìÇ","½ğŞ¿","ãå½õ",
		"Õñ¹â","ÁØö­","Ê¿¶°","ìõîø","ÖÎĞË", };
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