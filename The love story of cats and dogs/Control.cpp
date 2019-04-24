#include "stdafx.h"
#include "Control.h"


CControl::CControl()
	: NUMBER(0)
{
}


CControl::~CControl()
{
}


// ������ɶ���Ⱥ��ָ������������
void CControl::Rand_Init_Animal()
{
	//����Ⱥ����
	int num;
	cout << "����������Ҫ�Ķ���Ⱥ����(è������1:1):";
	cin >> num;
	cout << "�����������磬���Եȡ�������\n";
	for (int i = 0; i < num; i++)
	{
		int tmp = num / 2;
		if (i < tmp)
		{
			Number++;
			NUMBER++;
			id_isalive[Number] = 1;
			CAnimal *p = new CDog;
			p->Init_ID(Number);
			p->Rand_Init_PerInfor();
			animal.push_back(p);
		}
		else
		{
			NUMBER++;
			Number++;
			id_isalive[Number] = 1;
			CAnimal *p = new CCats;
			p->Init_ID(Number);
			p->Rand_Init_PerInfor();
			animal.push_back(p);
		}
	}
	cout << "��ɣ�" << endl;
}


// ��ӡ���еĶ�����Ϣ
void CControl::Disp_All_PerInfor()
{
	int i;
	for (i = 0; i < Number; i++)
	{
		animal[i]->Disp_PersonalInformation();
	}
}


// �޸�
void CControl::Change()
{
	int tmp;
	string name;
	int G_id;
	cout << "��������Ҫ�޸���Ϣ���������:";
	cin >> name;
	system("cls");
	G_id = Find_Name_Id(name);
	animal[G_id - 1]->Disp_PersonalInformation();
	cout << "��������Ҫ�޸ĵ���Ϣ:\n1.����\n2.����\n3.���\n4.��ֵ\n5.����ֵ\n6.���\n7.�ҳ�ֵ\n8.����\n9.��ŭֵ\n10.�˳�\n";
	cin >> tmp;
	switch (tmp)
	{
	case 1:animal[G_id - 1]->Change_Name();
		break;
	case 2:animal[G_id - 1]->Change_Age();
		break;
	case 3:animal[G_id - 1]->Change_Kind();
		break;
	case 4:animal[G_id - 1]->Change_Face();
		break;
	case 5:animal[G_id - 1]->Change_Charm();
		break;
	case 6:animal[G_id - 1]->Change_Deposit();
		break;
	case 7:animal[G_id - 1]->Change_Loyalty();
		break;
	case 8:animal[G_id - 1]->Change_Patience();
		break;
	case 9:animal[G_id - 1]->Change_Anger();
		break;
	case 10:
		break;
	}
}


// �½�����
void CControl::Init_PersonalInformation()
{
	Number++;
	NUMBER++;
	id_isalive[Number] = 1;
	int tmp;
	string name;
	do
	{
		cout << "�����붯������:\n1.������\t2.������\n";
		cin >> tmp;
	} while (tmp != 1 && tmp != 2);
	if (tmp == 1)
	{
		CAnimal*p = new CDog;
		animal.push_back(p);
	}
	if (tmp == 2)
	{
		CAnimal*p = new CCats;
		animal.push_back(p);
	}
	animal[Number - 1]->Init_ID(Number);
	animal[Number - 1]->Change_Name();
	animal[Number - 1]->Change_Age();
	animal[Number - 1]->Change_Face();
	animal[Number - 1]->Change_Charm();
	animal[Number - 1]->Change_Deposit();
	animal[Number - 1]->Change_Loyalty();
	animal[Number - 1]->Change_Patience();
	animal[Number - 1]->Disp_PersonalInformation();
}


// ����������id
int CControl::Find_Name_Id(string name)
{
	for (int j = 0; j < Number; j++)
	{
		if (animal[j]->Get_Name() == name)
		{
			return j + 1;
		}
	}
	return 0;
}


// �˹�ָ������
void CControl::Manpower_Death(int id)
{
	id_isalive[id] = 0;
	animal[id - 1]->Change_Isalive_Death();
	Number--;
}



// �˹�ָ������
void CControl::Manpower_Alive(int id)
{
	id_isalive[id] = 1;
	animal[id - 1]->Change_Isalive_Alive();
	Number++;
}


// �˹��ı�˭��˭�ĺø�
void CControl::Manpower_Favor(int id, int to)
{
	animal[id - 1]->Change_Favor(to);
}



// �˹��ı�˭��˭�İ���ָ��
void CControl::Manpower_Love(int id, int to)
{
	animal[id - 1]->Change_Love(to);
}


//�˹��ı�˭��˭������ֵ
void CControl::Manpower_Quarrel(int id, int to)
{
	animal[id - 1]->Change_Quarrel(to);
}

// �õ��ø�ֵ����
int CControl::Get_BaseLine_Favor()
{
	return BaseLine_Favor;
}

// �ж�������ĺø�ֵ�Ƿ񵽴����
bool CControl::Judge_BaseLine_Favor(int id, int to)
{
	if (animal[id - 1]->Get_Score_Favor(to) >= Get_BaseLine_Favor() && animal[to - 1]->Get_Score_Favor(id) >= Get_BaseLine_Favor())
		return true;
	else
		return false;
}


// d�õ�����ָ������
int CControl::Get_BaseLine_Love()
{
	return BaseLine_Love;
}

//�ж�������İ���ָ���Ƿ񵽴����
bool CControl::Judge_BaseLine_Love(int id, int to)
{
	if (animal[id - 1]->Get_Score_Love(to) >= Get_BaseLine_Love() && animal[to - 1]->Get_Score_Love(id) >= Get_BaseLine_Love())
		return true;
	else
		return false;
}



// ���ݻ�����Ϣ�ӷ� �������в���֮ǰ ����֮��
void CControl::Rule_Up_Base()
{
	int i, j;
	for (i = 0; i < Number; i++)
	{
		if (animal[i]->Get_Score_Face() > 50)
		{
			for (j = 0; j < Number; j++)
			{
				animal[j]->Change_System_Up_Favor(i, 5);
			}
		}
		if (animal[i]->Get_Score_Deposit() > 30000000)
		{
			for (j = 0; j < Number; j++)
			{
				animal[j]->Change_System_Up_Favor(i, 5);
			}
		}
		if (animal[i]->Get_Score_Patience() > 50)
		{
			for (j = 0; j < Number; j++)
			{
				animal[j]->Change_System_Up_Favor(i, 5);
			}
		}
		if (animal[i]->Get_Score_Loyalty() > 50)
		{
			for (j = 0; j < Number; j++)
			{
				animal[j]->Change_System_Up_Favor(i, 5);
			}
		}
		if (animal[i]->Get_Score_Charm() > 50)
		{
			for (j = 0; j < Number; j++)
			{
				animal[j]->Change_System_Up_Favor(i, 5);
			}
		}
	}
}

// �ж����˵ĺø�ֵʱ�򳬹�ĳֵ
bool CControl::Judge_Favor_Exceed(int id, int to, int score)
{
	if (animal[id - 1]->Get_Score_Favor(to) >= score && animal[to - 1]->Get_Score_Favor(id) >= score)
	{
		return true;
	}
	else
		return false;
}


// ��id������
string CControl::Find_Id_Name(int id)
{
	for (int j = 0; j < Number; j++)
	{
		if (animal[j]->Get_ID() == id)
		{
			return animal[j]->Get_Name();
		}
	}
}

//��Ȼ�ֺ� ���� �ȼ�1 �� 1-3
void CControl::Disaster_Earthquake_1(int id, int to)
{
	srand((unsigned int)time(0));
	int lv = rand() % 3 + 1;
	cout << "һ��" << lv << "��������\n";

	cout << Find_Id_Name(id) << "��" << Find_Id_Name(to) << "�ȹ���һ���������˴�֮����ӹ���\n";
	cout << "˫���øж�����10" << endl;
	animal[id - 1]->Change_System_Up_Favor(to, 10);
	animal[to - 1]->Change_System_Up_Favor(id, 10);
	Sleep(3000);
}

//��Ȼ�ֺ� ���� �ȼ�2 �� 4-6
void CControl::Disaster_Earthquake_2(int id, int to)
{

	srand((unsigned int)time(0));
	int lv = rand() % (6 - 4 + 1) + 4;
	cout << "һ��" << lv << "��������\n";
	cout << Find_Id_Name(id) << "��" << Find_Id_Name(to) << "�ļ��⵽�ٻ������ǲ�û�о�ɥ����������޺��˷���\n";
	cout << "˫���øж�����30" << endl;
	animal[id - 1]->Change_System_Up_Favor(to, 10);
	animal[to - 1]->Change_System_Up_Favor(id, 10);
	Sleep(3000);
}

//��Ȼ�ֺ� ���� �ȼ�3 �� 7-9
void CControl::Disaster_Earthquake_3(int id, int to)
{

	srand((unsigned int)time(0));
	int lv = rand() % (9 - 7 + 1) + 7;
	cout << "һ��" << lv << "��������\n";
	cout << "һ���޴�����ѽ����ˣ���������ĩ��һ��";
	if (Judge_Favor_Exceed(id, to, 10))
	{
		cout << "�޴�ĵ����" << Find_Id_Name(to) << "��ס�ˣ�";
		cout << Find_Id_Name(id) << "�����ڳ���" << Find_Id_Name(to) << "��\n";
		cout << Find_Id_Name(to) << "��" << Find_Id_Name(id) << "ʮ�ָм���\n˫���ø�ֵ����60";
		cout << "�����ֹ�������һ���ؽ��˼�԰��\n";
		animal[id - 1]->Change_System_Up_Favor(to, 60);
		animal[to - 1]->Change_System_Up_Favor(id, 60);
	}
	else
	{
		cout << "��Ϊ����̫�ֲ���";
		cout << Find_Id_Name(id) << "��" << Find_Id_Name(to) << "�����Ȳ�û�з�������\n";
		cout << Find_Id_Name(to) << "�뿪������\n";
		animal[to - 1]->Change_Isalive_Death();
		id_isalive[to] = 1;
		Number--;
	}
	Sleep(3000);
}

// �����ֺ�
void CControl::Disaster_Flood(int id, int to)
{
	cout << "�ƺӷ����˴�ˮ��������ض�����û�ˡ�һ��С��";
	cout << Find_Id_Name(to) << "����һ�����챻��ˮ�����ˣ�";
	if (Judge_Favor_Exceed(id, to, 0))
	{
		cout << Find_Id_Name(id) << "Ѹ�ٵ����һֻ��ץס��" << Find_Id_Name(to) << "��\n";
		cout << Find_Id_Name(to) << "ʮ�ָ�л" << Find_Id_Name(id) << "��\n˫���ø�ֵ����40\n\n";
		animal[id - 1]->Change_System_Up_Favor(to, 40);
		animal[to - 1]->Change_System_Up_Favor(id, 40);
	}
	else
	{
		cout << Find_Id_Name(id) << "Ѹ�ٵ����һֻ����Ҫץס" << Find_Id_Name(to) << "����̫����\n";
		cout << Find_Id_Name(to) << "�Ѿ�����ˮ�����ˣ������뿪������\n";
		animal[to - 1]->Change_Isalive_Death();
		id_isalive[to] = 1;
		Number--;
	}
	Sleep(3000);
}

//����
void CControl::Disaster_Famine(int id, int to)
{
	cout << "��ʳ�ճɺܲ��ã�";
	cout << Find_Id_Name(to) << "��ʳ���Ѿ������ˣ�����" << Find_Id_Name(id) << "��һ�㡣\n";
	if (Judge_Favor_Exceed(id, to, 20))
	{
		cout << Find_Id_Name(id) << "�ܴ󷽵İ��Լ���ʳ��ָ�����.\n˫���ĺø�ֵ����30\n";
	}
	else
	{
		cout << "����" << Find_Id_Name(id) << "��ʳ��Ҳ�����ˣ�ֻ����һ��㣬��" << Find_Id_Name(to) << "ȥ�������￴����\n˫���øм���10\n";
		animal[id]->Change_System_Down_Favor(to, 10);
		animal[to]->Change_System_Down_Favor(id, 10);
	}
	Sleep(3000);
}


// �õ���������
int CControl::Get_Number()
{
	return Number;
}


// �õ�ʱ����
int CControl::Get_Date()
{
	return Date;
}


// ��ӡʱ����
void CControl::Disp_Date()
{
	cout << "\n* è����:" << Date << "��\n\n";
}


// ������
void CControl::Rule_Marry(int id, int to)
{
	if ((animal[id - 1]->Get_Spouse() == "��" && animal[to - 1]->Get_Spouse() == "��")
		&& ((animal[id - 1]->Get_Int_Kind() == 1 && animal[to - 1]->Get_Int_Kind() == 2) ||
		((animal[id - 1]->Get_Int_Kind() == 2 && animal[to - 1]->Get_Int_Kind() == 2))))
	{
		cout << "����ָ���Ѵﵽ��ֵ���Ƿ�������ĸ����ϵͳ:\n*1.ʹ��\n*2.��ʹ��\n";
		int tmp;
		while (1)
		{
			cout << "*";
			cin >> tmp;
			if (tmp == 1)
			{
				cout << "��Ȼ" << Find_Id_Name(id) << "��" << Find_Id_Name(to) << "�����������ĸ���ԣ���Ե����\n";
				break;
			}
			if (tmp == 2)
			{
				if (Judge_BaseLine_Love(id, to) && Judge_BaseLine_Love(to, id))
				{
					cout << "Ը�����������ճɾ�����ǰ��ע����ϲ����Ե���»��ϲ������úϣ�\n";
					cout << Find_Id_Name(id) << "��" << Find_Id_Name(to) << "����ĥ�ѣ��޳�������\n";
					animal[id - 1]->Change_System_Spouse(Find_Id_Name(to));
					animal[to - 1]->Change_System_Spouse(Find_Id_Name(id));
					Num_Spouse++;
					Arr_Spouse[0][Num_Spouse] = id;
					Arr_Spouse[1][Num_Spouse] = to;
					Sleep(3000);
					break;
				}
			}
			else
				cout << "�����������������\n";
		}
	}
	else
		cout << "�ݲ���������ҵ��\n";
}


// ������
void CControl::Rule_Divorce(int id, int to)
{
	if ((animal[id - 1]->Get_Spouse() == "��" && animal[to - 1]->Get_Spouse() == "��")
		&& ((animal[id - 1]->Get_Int_Kind() == 1 && animal[to - 1]->Get_Int_Kind() == 2) ||
		((animal[id - 1]->Get_Int_Kind() == 2 && animal[to - 1]->Get_Int_Kind() == 2))))
	{
		if (!(Judge_BaseLine_Love(id, to)) || !(Judge_BaseLine_Love(to, id)))
		{
			cout << "������ף��������ף���ϸ�����ٿ���\n";
		}
		if (!(Judge_BaseLine_Love(id, to) && Judge_BaseLine_Love(to, id)))
		{
			cout << "��Ϧ��Ϧ���������ɣ����޼�ʱ�ݡ�\n�׺�ɣ�����Բȱ��Ե������Ѱ��";
			cout << Find_Id_Name(id) << "��" << Find_Id_Name(to) << "�������ѣ��Ӵ�Ե�������������ϵ��\n";
			animal[id - 1]->Change_System_Spouse("��");
			animal[to - 1]->Change_System_Spouse("��");
			Num_Spouse--;
			Arr_Spouse[0][Num_Spouse + 1] = 0;
			Arr_Spouse[1][Num_Spouse + 1] = 0;
		}
	}
	else
		cout << "�ݲ���������ҵ��\n";
}


// ÿ���ս���һ�θ���ȸ���ֵ
void CControl::Judge_3Day()
{
	Rule_Up_Base();
	int i, j;
	for (i = 1; i <= Number; i++)
	{
		for (j = i; j <= Number; j++)
		{
			animal[i - 1]->Rule_Favor_Love(j);
		}
	}
	for (i = 1; i <= Number; i++)
	{
		for (j = i; j <= Number; j++)
		{
			if (Judge_BaseLine_Love(i, j))
			{
				if (Judge_BaseLine_Love(j, i))
				{
					Rule_Marry(i, j);
				}
			}
		}
	}
}


// �޸�����
void CControl::Change_Date(int date)
{
	Date = Get_Date() + date;
}


// �õ��Ƿ���ı�־
int CControl::Get_Isalive(int id)
{
	return id_isalive[id];
}

void CControl::Events_Dinner(int id, int to)
{
	cout << Find_Id_Name(id) << "��" << Find_Id_Name(to) << "��·��ż����ǡ��û�£���Լ�Է���\n˫���øж�����10\n";
	animal[id - 1]->Change_System_Up_Favor(to, 10);
	animal[to - 1]->Change_System_Up_Favor(id, 10);
	Sleep(3000);
}

void CControl::Events_Date(int id, int to)
{
	cout << Find_Id_Name(id) << "��" << Find_Id_Name(to) << "�ڼ���ǰ��Լ����ȥ���ȹݺȿ���\n˫���øж�����20\n";
	animal[id - 1]->Change_System_Up_Favor(to, 20);
	animal[to - 1]->Change_System_Up_Favor(id, 20);
	Sleep(3000);
}

void CControl::Events_Quarrel(int id, int to)
{
	cout << Find_Id_Name(id) << "��" << Find_Id_Name(to) << "��Ϊ�յ����컹�Ƿ������쳳������\n˫���øжȼ���10\n";
	animal[id - 1]->Change_System_Down_Favor(to, 10);
	animal[to - 1]->Change_System_Down_Favor(id, 10);
	Sleep(3000);
}

void CControl::Events_KTV(int id, int to)
{
	cout << Find_Id_Name(id) << "��" << Find_Id_Name(to) << "����û�£�һ��ȥktv����һ���ϵĸ�\n˫���øж�����20\n";
	animal[id - 1]->Change_System_Up_Favor(to, 20);
	animal[to - 1]->Change_System_Up_Favor(id, 20);
	Sleep(3000);
}

void CControl::Events_Hospital(int id, int to)
{
	cout << Find_Id_Name(id) << "ȥ" << Find_Id_Name(to) << "���﷢�����������ˣ�����������ȥҽԺ\n˫���øж�����20\n";
	animal[id - 1]->Change_System_Up_Favor(to, 20);
	animal[to - 1]->Change_System_Up_Favor(id, 20);
	Sleep(3000);
}

void CControl::Events_Study(int id, int to)
{
	cout << Find_Id_Name(id) << "��" << Find_Id_Name(to) << "һ��ȥ��ϰ�ҿ�����\n˫���øж�����20\n";
	animal[id - 1]->Change_System_Up_Favor(to, 20);
	animal[to - 1]->Change_System_Up_Favor(id, 20);
	Sleep(3000);
}

void CControl::Events_Code(int id, int to)
{
	cout << Find_Id_Name(id) << "��" << Find_Id_Name(to) << "һ���ô��룬���ཻ������\n˫���øж�����40\n";
	animal[id - 1]->Change_System_Up_Favor(to, 40);
	animal[to - 1]->Change_System_Up_Favor(id, 40);
	Sleep(3000);
}

void CControl::Events_Visit(int id, int to)
{
	cout << Find_Id_Name(id) << "ȥ�ݷ�" << Find_Id_Name(to) << "�����ܸ�������������\n˫���øж�����20\n";
	animal[id - 1]->Change_System_Up_Favor(to, 20);
	animal[to - 1]->Change_System_Up_Favor(id, 20);
	Sleep(3000);
}

void CControl::Events_Play(int id, int to)
{
	cout << Find_Id_Name(id) << "��" << Find_Id_Name(to) << "һ��ȥ����԰����תľ��\n˫���øж�����30\n";
	animal[id - 1]->Change_System_Up_Favor(to, 30);
	animal[to - 1]->Change_System_Up_Favor(id, 30);
	Sleep(3000);
}

void CControl::Events_Fight(int id, int to)
{
	cout << Find_Id_Name(id) << "��" << Find_Id_Name(to) << "һ�Բ��Ͼʹ������ˣ�ԭ��Ȼ��д�������̫˧��\n˫���øжȼ���20\n";
	animal[id - 1]->Change_System_Down_Favor(to, 20);
	animal[to - 1]->Change_System_Down_Favor(id, 20);
	Sleep(3000);
}


void CControl::Disp_Per(int id)
{
	animal[id - 1]->Disp_PersonalInformation();
}


void CControl::Disp_Per_Favor(int id)
{
	int tmp = 1;
	for (int i = 1;i <= NUMBER;i++)
	{
		
		if (i != id)
		{
			cout << "��" << Find_Id_Name(i) << "�ø�:";
			animal[id - 1]->Disp_Score_Favor(i);

			if (tmp % 3 == 0)
			{
				cout << endl;
			}
			else
				cout << "\t";
			tmp++;
		}
	}
}

void CControl::Disp_Per_Love(int id)
{
	int tmp = 1;
	for (int i = 1; i <= NUMBER; i++)
	{

		if (i != id)
		{
			cout << "��" << Find_Id_Name(i) << "����:";
			animal[id - 1]->Disp_Score_Love(i);

			if (tmp % 3 == 0)
			{
				cout << endl;
			}
			else
				cout << "\t";
			tmp++;
		}
	}
}

