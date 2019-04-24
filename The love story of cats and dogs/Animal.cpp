#include "stdafx.h"
#include "Animal.h"


CAnimal::CAnimal()
{

}


CAnimal::~CAnimal()
{

}


// �õ���ֵ
int CAnimal::Get_ID()
{
	return ID;
}


// �õ�����
int CAnimal::Get_Age()
{
	return Age;
}


// �õ�����
string CAnimal::Get_Name()
{
	return Name;
}



// �õ���ŭֵ
double CAnimal::Get_Score_Anger()
{
	return Score_Anger;
}


// �õ�����ֵ
double CAnimal::Get_Score_Charm()
{
	return Score_Charm;
}


// �õ����
long long CAnimal::Get_Score_Deposit()
{
	return Score_Deposit;
}


// �õ���ֵ
double CAnimal::Get_Score_Face()
{
	return Score_Face;
}


// �õ���ID����İ���ָ��
double CAnimal::Get_Score_Love(int id)
{
	return Score_Love[id];
}


// �õ��ҳ�ֵ
double CAnimal::Get_Score_Loyalty()
{
	return Score_Loyalty;
}


// �õ�����ֵ
double CAnimal::Get_Score_Patience()
{
	return Score_Patience;
}


// �õ���ID���������ֵ
//double CAnimal::Get_Score_Quarrel(int id)
//{
	//return Score_Quarrel[id];
//}

//�õ���ID����ĺø�ֵ
double CAnimal::Get_Score_Favor(int id)
{
	return Score_Favor[id];
}


// �õ��Ա�
//string CAnimal::Get_Sex()
//{
//	return Sex;
//}

string CAnimal::Get_Kind()
{
	return Kind;
}


// ��ӡid
void CAnimal::Disp_ID()
{
	cout << "���:" << Get_ID();
}

void CAnimal::Disp_Age()
{
	cout << "����:" << Get_Age();
}

//void CAnimal::Disp_Sex()
//{
//	cout << "�Ա�:" << Get_Sex();
//}

void CAnimal::Disp_Name()
{
	cout << "����:" << Get_Name();
}

void CAnimal::Disp_Kind()
{
	cout << "���:" << Get_Kind();
}

void CAnimal::Disp_Score_Anger()
{
	cout << "��ŭֵ:" << Get_Score_Anger();
}

void CAnimal::Disp_Score_Charm()
{
	cout << "����ֵ:" << Get_Score_Charm();
}

void CAnimal::Disp_Score_Deposit()
{
	cout << "���:" << Get_Score_Deposit();
}

void CAnimal::Disp_Score_Face()
{
	cout << "��ֵ:" << Get_Score_Face();
}

void CAnimal::Disp_Score_Loyalty()
{
	cout << "�ҳ�ֵ:" << Get_Score_Loyalty();
}

void CAnimal::Disp_Score_Patience()
{
	cout << "����ֵ:" << Get_Score_Patience();
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
//	cout << "��������ָ��:" << Get_Score_Quarrel(id);
//}


// ��ӡ������Ϣ
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


// �˹���ʼ�����˻�����Ϣ
/*void CAnimal::Init_PersonalInformation()
{
	int face, charm, deposit, loyalty, patience;
	string name;
	cout << "�����붯�������:";
	cin >> name; Name = name;
	cout << "���Դ����붯�����ֵ,����ֵ,���,�ҳ�ֵ,����:";
	cin >> face; Score_Face = face;
	cin >> charm; Score_Charm = charm;
	cin >> deposit; Score_Deposit = deposit;
	cin >> loyalty; Score_Loyalty = loyalty;
	cin >> patience; Score_Patience = patience;
}*/


// �޸�����
void CAnimal::Change_Name()
{
	string name;
	cout << "������޸ĺ������:";
	cin >> name;
	Name = name;
}


// �޸��Ա�
//void CAnimal::Change_Sex()
//{
//	string sex;
//	cout << "������޸ĺ���Ա�:";
//	cin >> sex;
//	Sex = sex;
//}

void CAnimal::Change_Kind()
{
	int kind;
	cout << "���������:";
	cout << "1.������\t2.������\n";
	cout << "������:";
	cin >> kind;
	if (kind == 1)
	{
		int_kind = 1;
		Kind = "������";
	}
	if (kind == 2)
	{
		int_kind = 2;
		Kind = "������";
	}
}


// �޸ķ�ŭֵ
void CAnimal::Change_Anger()
{
	int anger;
	cout << "�������ŭֵ:";
	cin >> anger;
	Score_Anger = anger;
}


// �޸�����ֵ
void CAnimal::Change_Charm()
{
	int charm;
	cout << "����������ֵ:";
	cin >> charm;
	Score_Charm = charm;
}


// �޸Ĵ��
void CAnimal::Change_Deposit()
{
	int deposit;
	cout << "��������:";
	cin >> deposit;
	Score_Deposit = deposit;
}


// �޸���ֵ
void CAnimal::Change_Face()
{
	int face;
	cout << "��������ֵ:";
	cin >> face;
	Score_Face = face;
}


// �޸��ҳ�ֵ
void CAnimal::Change_Loyalty()
{
	int loyalty;
	cout << "�������ҳ�ֵ:";
	cin >> loyalty;
	Score_Loyalty = loyalty;
}


// �޸�����ֵ
void CAnimal::Change_Patience()
{
	int patience;
	cout << "����������ֵ:";
	cin >> patience;
	Score_Patience = patience;
}


// ��ʼ��ID
void CAnimal::Init_ID(int n)
{
	ID = n;
}


// �޸�����
void CAnimal::Change_Age()
{
	int age;
	cout << "����������:";
	cin >> age;
	Age = age;
}


// ��ӡ�Ƿ�����
void CAnimal::Disp_Isalive()
{
	cout << "����:" << Get_Isalive();
}


string CAnimal::Get_Isalive()
{
	return isalive;
}


// �ĳ�����
void CAnimal::Change_Isalive_Death()
{
	isalive = "����";
}


// �ĳ�����
void CAnimal::Change_Isalive_Alive()
{
	isalive = "����";
}


// �޸Ķ�˭�ĺø�
void CAnimal::Change_Favor(int id)
{
	int tmp;
	cout << "������ø�ֵ:";
	cin >> tmp;
	Score_Favor[id] = tmp;
}


// �޸Ķ�˭�İ���ָ��
void CAnimal::Change_Love(int id)
{
	int tmp;
	cout << "�����밮��ָ��:";
	cin >> tmp;
	Score_Love[id] = tmp;
}


// �޸Ķ�˭������ֵ
void CAnimal::Change_Quarrel(int id)
{
	int tmp;
	cout << "����������ֵ:";
	cin >> tmp;
	//Score_Quarrel[id] = tmp;
}


// �õ���ż����
string CAnimal::Get_Spouse()
{
	return Spouse;
}


// ��ӡ��ż
void CAnimal::Disp_Spouse()
{
	cout << "��ż:" <<Get_Spouse();
}

void CAnimal::Change_System_Up_Favor(int to, int favor)
{
	Score_Favor[to] = favor + Get_Score_Favor(to);
}

void CAnimal::Change_System_Down_Favor(int to, int favor)
{
	Score_Favor[to] = favor - Get_Score_Favor(to);
}

//�ø�ֵ�һ�����ָ��
void CAnimal::Rule_Favor_Love(int to)
{
	if (Get_Score_Favor(to) >= Get_ABaseLine_Favor())
	{
		Score_Love[to] = (Get_Score_Favor(to) - Get_ABaseLine_Favor());
	}
}



// �޸İ�������
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
