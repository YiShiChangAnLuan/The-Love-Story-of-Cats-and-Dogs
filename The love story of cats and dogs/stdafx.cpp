// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// The love story of cats and dogs.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

// TODO: �� STDAFX.H �������κ�����ĸ���ͷ�ļ���
//�������ڴ��ļ�������

//��һ�����
int Menu1()
{
	int tmp;
	while (true)
	{


		//cout << "           **********************\n";
		cout << endl;
		cout << "* СèС���ǵİ������\n";
		cout << "\nһȺС����Сè������һƬ������������ˣ���������ס��\n���������Ҳ����ô��ʵ��������Ʒ�¸��С�����׿Խ���������\n�������߸�˧���׸�������ȻҲ��������һ�����ˣ�\n�˴�֮�䶼��һ���Ĺ��򣬵������������󣬲Ż��кøУ�\n�Żᰮ�϶Է����������޸�����Ҳ������ʶʱһ�����飬\n���Ҳ���ò��ֵ�����СèС��������Ҳ�����޵ģ�\n�����������ˣ�С���ǲ���Ϊ��ĳ��С������������ɭ�ֵġ� \n";
		cout << "\n";
		cout << "1.�����µ�è������\n";
		cout << "2.�˳�\n";
		cout << "*";
		while (1)
		{
			cin >> tmp;
			if (tmp != 2 && tmp != 1)
			{
				cout << "����������������롣";
			}
			if (tmp == 1)
			{
				system("cls");
				return Menu2();
			}
			if (tmp == 2)
			{
				return 0;
			}

		}
	}
}

//�ڶ������
int Menu2()
{
	int tmp, tmp1,tmp2;
	int i, j;
	int date;
	string name1, name2, name;
	CControl *a = new CControl();
	a->Rand_Init_Animal();
Loop1:
	while (1)
	{
		a->Disp_Date();
		cout << endl;
		cout << "1.�鿴��Ϣ\n";
		cout << "2.��ʼ���ǵ�����\n";
		cout << "3.�½�����\n";
		cout << "4.�˹���Ԥ\n";
		cout << "5.��ʼ����������\n";
		cout << "6.�˳�����\n";
		cout << "*";
		cin >> tmp;
		system("cls");
		switch (tmp)
		{
		case 1:
			while (1)
			{
				cout << "1.�鿴���ж���\n2.�鿴��������(����ϸ�鿴�øжȰ���ָ��)\n3.������һ��\n*";
				cin >> tmp1;
				if (tmp1 == 1)
				{
					if (a->Get_Number() <= 0)
					{
						cout << "������û�ж���\n\n";
					}
					else
						a->Disp_All_PerInfor();
				}
				else if (tmp1 == 2)
				{
					cout << "������˶��������:";
					cin >> name;
					tmp2 = a->Find_Name_Id(name);
					if (tmp2 == 0)
					{
						cout << "û�д˶���\n";
					}
					else
					{
						a->Disp_Per(tmp2);
						a->Disp_Per_Favor(tmp2);
						cout << endl;
						a->Disp_Per_Love(tmp2);
						cout << endl;
					}
				}
				else if (tmp1 == 3)
				{
					goto Loop1;
				}
				else
					cout << "����������������롣\n";
			}
			break;


		case 2:
			cout << "�����붯�����������:";
			cin >> date;
			for (i = 0; i < date; i++)
			{
				if (a->Get_Number() < 2)
				{
					cout << "��������������ֻ���뼰ʱ��ֵ��";
					break;
				}
				int A, B, tmp;//ab��������
				a->Change_Date(1);
				a->Disp_Date();
				srand((unsigned int)time(NULL));
				do
				{
					A = rand() % a->Get_Number() + 1;
					B = rand() % a->Get_Number() + 1;
				} while ((a->Get_Isalive(A) != 1) || (a->Get_Isalive(B) != 1) || A == B);
				Sleep(1000);
				tmp = rand() % 35 + 1;
				if (tmp > 0 && tmp <= 3)
				{
					a->Events_Dinner(A, B);
				}
				else if (tmp > 3 && tmp <= 6)
				{
					a->Events_Date(A, B);
				}
				else if (tmp > 6 && tmp <= 9)
				{
					a->Events_Quarrel(A, B);
				}
				else if (tmp > 9 && tmp <= 12)
				{
					a->Events_KTV(A, B);
				}
				else if (tmp > 12 && tmp <= 15)
				{
					a->Events_Hospital(A, B);
				}
				else if (tmp > 15 && tmp <= 18)
				{
					a->Events_Study(A, B);
				}
				else if (tmp > 18 && tmp <= 21)
				{
					a->Events_Code(A, B);
				}
				else if (tmp > 21 && tmp <= 24)
				{
					a->Events_Visit(A, B);
				}
				else if (tmp > 24 && tmp <= 27)
				{
					a->Events_Play(A, B);
				}
				else if (tmp > 27 && tmp <= 30)
				{
					a->Events_Fight(A, B);
				}
				else if (tmp > 30 && tmp <= 31)
				{
					a->Disaster_Earthquake_1(A, B);
				}
				else if (tmp > 31 && tmp <= 32)
				{
					a->Disaster_Earthquake_2(A, B);
				}
				else if (tmp > 32 && tmp <= 33)
				{
					a->Disaster_Earthquake_3(A, B);
				}
				else if (tmp > 33 && tmp <= 34)
				{
					a->Disaster_Famine(A, B);
				}
				else if (tmp > 34 && tmp <= 35)
				{
					a->Disaster_Flood(A, B);
				}
				else if (a->Get_Date() % 3 == 0)
				{
					a->Judge_3Day();
				}
			}
			break;



		case 3:
			cout << "1.�Զ����½�\n2.����½�\n3.������һ��\n*";
			while (1)
			{
				cin >> tmp1;
				if (tmp1 == 1)
				{
					a->Init_PersonalInformation();
					break;
				}
				else if (tmp1 == 2)
				{
					a->Rand_Init_Animal();
					break;
				}
				else if (tmp1 == 3)
				{
					break;
				}
				else
					cout << "����������������롣\n";
			}
			break;
		case 4:
		Loop2:
			system("cls");
			while (1)
			{
				a->Disp_All_PerInfor();
				cout << "1.����\n";
				cout << "2.����\n";
				cout << "3.��A��B�ø�ֵ�仯\n";
				cout << "4.��A��B����ֵ�仯\n";
				cout << "5.��A��B����ֵ�仯\n";
				cout << "6.�����¼�\n";
				cout << "7.�޸�\n";
				cout << "8.������һ��\n";
				cout << "*";
				cin >> tmp;
				switch (tmp)
				{
				case 1:
					cout << "���ź��������ˣ��������������֣�";
					cin >> name;
					a->Manpower_Death(a->Find_Name_Id(name));
					break;
				case 2:
					cout << "�ϱ���һ�����������£��������������֣�";
					cin >> name;
					a->Manpower_Alive(a->Find_Name_Id(name));
					break;
				case 3:

					cout << "������A������:";
					cin >> name1;
					cout << "������B������:";
					cin >> name2;
					a->Manpower_Favor(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
					break;
				case 4:
					cout << "������A������:";
					cin >> name1;
					cout << "������B������:";
					cin >> name2;
					a->Manpower_Love(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
					break;
				case 5:
					cout << "������A������:";
					cin >> name1;
					cout << "������B������:";
					cin >> name2;
					a->Manpower_Quarrel(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
					break;
				case 6:
					while (1)
					{
						system("cls");
						a->Disp_All_PerInfor();
						cout << "1.������΢����\n";
						cout << "2.�����жȵ���\n";
						cout << "3.�����ضȵ���\n";
						cout << "4.���������ֺ�\n";
						cout << "5.��������\n";
						cout << "6.�Է�\n";
						cout << "7.Լ��\n";
						cout << "8.����\n";
						cout << "9.k��\n";
						cout << "10.��ҽԺ\n";
						cout << "11.��ϰ\n";
						cout << "12.�ô���\n";
						cout << "13.�ݷ�\n";
						cout << "14.����԰\n";
						cout << "15.���\n";
						cout << "16.������һ��\n";
						cout << "*";
						cin >> tmp1;
						switch (tmp1)
						{
						case 1:
							cout << "*��������λ���������:";
							cin >> name1;
							cin >> name2;
							a->Disaster_Earthquake_1(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
							break;
						case 2:
							cout << "*��������λ���������:";
							cin >> name1;
							cin >> name2;
							a->Disaster_Earthquake_2(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
							break;
						case 3:
							cout << "*��������λ���������:";
							cin >> name1;
							cin >> name2;
							a->Disaster_Earthquake_3(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
							break;
						case 4:
							cout << "*��������λ���������:";
							cin >> name1;
							cin >> name2;
							a->Disaster_Flood(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
							break;
						case 5:
							cout << "*��������λ���������:";
							cin >> name1;
							cin >> name2;
							a->Disaster_Famine(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
							break;
						case 6:
							cout << "*��������λ���������:";
							cin >> name1;
							cin >> name2;
							a->Events_Dinner(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
						case 7:
							cout << "*��������λ���������:";
							cin >> name1;
							cin >> name2;
							a->Events_Date(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
						case 8:
							cout << "*��������λ���������:";
							cin >> name1;
							cin >> name2;
							a->Events_Quarrel(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
						case 9:
							cout << "*��������λ���������:";
							cin >> name1;
							cin >> name2;
							a->Events_KTV(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
						case 10:
							cout << "*��������λ���������:";
							cin >> name1;
							cin >> name2;
							a->Events_Hospital(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
						case 11:
							cout << "*��������λ���������:";
							cin >> name1;
							cin >> name2;
							a->Events_Study(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
						case 12:
							cout << "*��������λ���������:";
							cin >> name1;
							cin >> name2;
							a->Events_Code(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
						case 13:
							cout << "*��������λ���������:";
							cin >> name1;
							cin >> name2;
							a->Events_Visit(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
						case 14:
							cout << "*��������λ���������:";
							cin >> name1;
							cin >> name2;
							a->Events_Play(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
						case 15:
							cout << "*��������λ���������:";
							cin >> name1;
							cin >> name2;
							a->Events_Fight(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
						case 16:
							system("cls");
							goto Loop2;
							break;
						}
					}
					break;
				case 7:
					system("cls");
					a->Disp_All_PerInfor();
					a->Change();
					break;
				case 8:
					system("cls");
					goto Loop1;
					break;
				}
				system("cls");
			}
			break;
		case 5:delete a;
			system("cls");
			return Menu1();
			break;
		case 6:return 0;
			break;
		}
	}
}