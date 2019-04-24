#include "stdafx.h"
#include "Animal.h"


CAnimal::CAnimal()
{

}


CAnimal::~CAnimal()
{

}


// 得到颜值
int CAnimal::Get_ID()
{
	return ID;
}


// 得到年龄
int CAnimal::Get_Age()
{
	return Age;
}


// 得到名字
string CAnimal::Get_Name()
{
	return Name;
}



// 得到愤怒值
double CAnimal::Get_Score_Anger()
{
	return Score_Anger;
}


// 得到魅力值
double CAnimal::Get_Score_Charm()
{
	return Score_Charm;
}


// 得到存款
long long CAnimal::Get_Score_Deposit()
{
	return Score_Deposit;
}


// 得到颜值
double CAnimal::Get_Score_Face()
{
	return Score_Face;
}


// 得到该ID动物的爱情指数
double CAnimal::Get_Score_Love(int id)
{
	return Score_Love[id];
}


// 得到忠诚值
double CAnimal::Get_Score_Loyalty()
{
	return Score_Loyalty;
}


// 得到耐心值
double CAnimal::Get_Score_Patience()
{
	return Score_Patience;
}


// 得到该ID动物的争吵值
//double CAnimal::Get_Score_Quarrel(int id)
//{
	//return Score_Quarrel[id];
//}

//得到该ID动物的好感值
double CAnimal::Get_Score_Favor(int id)
{
	return Score_Favor[id];
}


// 得到性别
//string CAnimal::Get_Sex()
//{
//	return Sex;
//}

string CAnimal::Get_Kind()
{
	return Kind;
}


// 打印id
void CAnimal::Disp_ID()
{
	cout << "编号:" << Get_ID();
}

void CAnimal::Disp_Age()
{
	cout << "年龄:" << Get_Age();
}

//void CAnimal::Disp_Sex()
//{
//	cout << "性别:" << Get_Sex();
//}

void CAnimal::Disp_Name()
{
	cout << "名字:" << Get_Name();
}

void CAnimal::Disp_Kind()
{
	cout << "类别:" << Get_Kind();
}

void CAnimal::Disp_Score_Anger()
{
	cout << "愤怒值:" << Get_Score_Anger();
}

void CAnimal::Disp_Score_Charm()
{
	cout << "魅力值:" << Get_Score_Charm();
}

void CAnimal::Disp_Score_Deposit()
{
	cout << "存款:" << Get_Score_Deposit();
}

void CAnimal::Disp_Score_Face()
{
	cout << "颜值:" << Get_Score_Face();
}

void CAnimal::Disp_Score_Loyalty()
{
	cout << "忠诚值:" << Get_Score_Loyalty();
}

void CAnimal::Disp_Score_Patience()
{
	cout << "耐心值:" << Get_Score_Patience();
}

void CAnimal::Disp_Score_Favor(int id)
{
	cout << Get_Score_Favor(id);
}

void CAnimal::Disp_Score_Love(int id)
{
	cout  << Get_Score_Love(id);
}

//void CAnimal::Disp_Score_Quarrel(int id)
//{
//	cout << "对其争吵指数:" << Get_Score_Quarrel(id);
//}


// 打印个人信息
void CAnimal::Disp_PersonalInformation()
{
	cout << "*";
	Disp_Name(); cout << "\n";
	Disp_Isalive();cout << "\t";
	Disp_Age(); cout << "\t\t";
	Disp_Kind(); cout << "\n";
	Disp_Spouse(); cout << "\t\t";
	Disp_Score_Face(); cout << "\t\t";;
	Disp_Score_Charm(); cout << "\n";
	Disp_Score_Deposit(); cout << "\t";
	Disp_Score_Loyalty(); cout << "\t";
	Disp_Score_Patience(); cout << "\n";
	//Disp_Score_Anger(); cout << "\n";
	cout << endl;
}


// 人工初始化个人基本信息
/*void CAnimal::Init_PersonalInformation()
{
	int face, charm, deposit, loyalty, patience;
	string name;
	cout << "请输入动物的名字:";
	cin >> name; Name = name;
	cout << "请以此输入动物的颜值,魅力值,存款,忠诚值,耐心:";
	cin >> face; Score_Face = face;
	cin >> charm; Score_Charm = charm;
	cin >> deposit; Score_Deposit = deposit;
	cin >> loyalty; Score_Loyalty = loyalty;
	cin >> patience; Score_Patience = patience;
}*/


// 修改名字
void CAnimal::Change_Name()
{
	string name;
	cout << "请输出修改后的名字:";
	cin >> name;
	Name = name;
}


// 修改性别
//void CAnimal::Change_Sex()
//{
//	string sex;
//	cout << "请输出修改后的性别:";
//	cin >> sex;
//	Sex = sex;
//}

void CAnimal::Change_Kind()
{
	int kind;
	cout << "请输入类别:";
	cout << "1.汪星人\t2.喵星人\n";
	cout << "请输入:";
	cin >> kind;
	if (kind == 1)
	{
		int_kind = 1;
		Kind = "汪星人";
	}
	if (kind == 2)
	{
		int_kind = 2;
		Kind = "喵星人";
	}
}


// 修改愤怒值
void CAnimal::Change_Anger()
{
	int anger;
	cout << "请输入愤怒值:";
	cin >> anger;
	Score_Anger = anger;
}


// 修改魅力值
void CAnimal::Change_Charm()
{
	int charm;
	cout << "请输入魅力值:";
	cin >> charm;
	Score_Charm = charm;
}


// 修改存款
void CAnimal::Change_Deposit()
{
	int deposit;
	cout << "请输入存款:";
	cin >> deposit;
	Score_Deposit = deposit;
}


// 修改颜值
void CAnimal::Change_Face()
{
	int face;
	cout << "请输入颜值:";
	cin >> face;
	Score_Face = face;
}


// 修改忠诚值
void CAnimal::Change_Loyalty()
{
	int loyalty;
	cout << "请输入忠诚值:";
	cin >> loyalty;
	Score_Loyalty = loyalty;
}


// 修改耐心值
void CAnimal::Change_Patience()
{
	int patience;
	cout << "请输入耐心值:";
	cin >> patience;
	Score_Patience = patience;
}


// 初始化ID
void CAnimal::Init_ID(int n)
{
	ID = n;
}


// 修改年龄
void CAnimal::Change_Age()
{
	int age;
	cout << "请输入年龄:";
	cin >> age;
	Age = age;
}


// 打印是否生死
void CAnimal::Disp_Isalive()
{
	cout << "生死:" << Get_Isalive();
}


string CAnimal::Get_Isalive()
{
	return isalive;
}


// 改成死亡
void CAnimal::Change_Isalive_Death()
{
	isalive = "死亡";
}


// 改成生存
void CAnimal::Change_Isalive_Alive()
{
	isalive = "生存";
}


// 修改对谁的好感
void CAnimal::Change_Favor(int id)
{
	int tmp;
	cout << "请输入好感值:";
	cin >> tmp;
	Score_Favor[id] = tmp;
}


// 修改对谁的爱情指数
void CAnimal::Change_Love(int id)
{
	int tmp;
	cout << "请输入爱情指数:";
	cin >> tmp;
	Score_Love[id] = tmp;
}


// 修改对谁的争吵值
void CAnimal::Change_Quarrel(int id)
{
	int tmp;
	cout << "请输入争吵值:";
	cin >> tmp;
	//Score_Quarrel[id] = tmp;
}


// 得到配偶名字
string CAnimal::Get_Spouse()
{
	return Spouse;
}


// 打印配偶
void CAnimal::Disp_Spouse()
{
	cout << "配偶:" <<Get_Spouse();
}

void CAnimal::Change_System_Up_Favor(int to, int favor)
{
	Score_Favor[to] = favor + Get_Score_Favor(to);
}

void CAnimal::Change_System_Down_Favor(int to, int favor)
{
	Score_Favor[to] = favor - Get_Score_Favor(to);
}

//好感值兑换爱情指数
void CAnimal::Rule_Favor_Love(int to)
{
	if (Get_Score_Favor(to) >= Get_ABaseLine_Favor())
	{
		Score_Love[to] = (Get_Score_Favor(to) - Get_ABaseLine_Favor());
	}
}



// 修改伴侣名字
void CAnimal::Change_System_Spouse(string spouse_name)
{
	Spouse = spouse_name;
}


int	CAnimal::Get_ABaseLine_Love()
{
	return ABaseLine_Love;
}


int CAnimal::Get_ABaseLine_Favor()
{
	return ABaseLine_Favor;
}


int CAnimal::Get_Int_Kind()
{
	return int_kind;
}
