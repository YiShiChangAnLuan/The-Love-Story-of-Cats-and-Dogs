// stdafx.cpp : 只包括标准包含文件的源文件
// The love story of cats and dogs.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

// TODO: 在 STDAFX.H 中引用任何所需的附加头文件，
//而不是在此文件中引用

//第一层界面
int Menu1()
{
	int tmp;
	while (true)
	{


		//cout << "           **********************\n";
		cout << endl;
		cout << "* 小猫小狗们的爱情故事\n";
		cout << "\n一群小狗和小猫生活在一片树林里，爱情来了，挡都挡不住，\n动物的世界也是那么真实，可能它品德高尚、优秀卓越且魅力爆棚，\n可能它高富帅、白富美，当然也可能是另一个极端，\n彼此之间都有一定的规则，当这个规则满足后，才会有好感，\n才会爱上对方，乃至最后嫁给它，也可能相识时一见钟情，\n最后也不得不分道扬镳。小猫小狗的耐心也是有限的，\n如果爱情过期了，小狗是不会为了某棵小树而放弃整个森林的。 \n";
		cout << "\n";
		cout << "1.创建新的猫狗世界\n";
		cout << "2.退出\n";
		cout << "*";
		while (1)
		{
			cin >> tmp;
			if (tmp != 2 && tmp != 1)
			{
				cout << "输入错误请重新输入。";
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

//第二层界面
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
		cout << "1.查看信息\n";
		cout << "2.开始他们的生活\n";
		cout << "3.新建动物\n";
		cout << "4.人工干预\n";
		cout << "5.初始化动物世界\n";
		cout << "6.退出世界\n";
		cout << "*";
		cin >> tmp;
		system("cls");
		switch (tmp)
		{
		case 1:
			while (1)
			{
				cout << "1.查看所有动物\n2.查看单个动物(可详细查看好感度爱情指数)\n3.返回上一级\n*";
				cin >> tmp1;
				if (tmp1 == 1)
				{
					if (a->Get_Number() <= 0)
					{
						cout << "世界内没有动物\n\n";
					}
					else
						a->Disp_All_PerInfor();
				}
				else if (tmp1 == 2)
				{
					cout << "请输入此动物的名字:";
					cin >> name;
					tmp2 = a->Find_Name_Id(name);
					if (tmp2 == 0)
					{
						cout << "没有此动物\n";
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
					cout << "输入错误，请重新输入。\n";
			}
			break;


		case 2:
			cout << "请输入动物生活的天数:";
			cin >> date;
			for (i = 0; i < date; i++)
			{
				if (a->Get_Number() < 2)
				{
					cout << "动物数量不足两只，请及时充值！";
					break;
				}
				int A, B, tmp;//ab两个动物
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
			cout << "1.自定义新建\n2.随机新建\n3.返回上一级\n*";
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
					cout << "输入错误，请重新输入。\n";
			}
			break;
		case 4:
		Loop2:
			system("cls");
			while (1)
			{
				a->Disp_All_PerInfor();
				cout << "1.死亡\n";
				cout << "2.复活\n";
				cout << "3.让A对B好感值变化\n";
				cout << "4.让A对B爱情值变化\n";
				cout << "5.让A对B争吵值变化\n";
				cout << "6.操作事件\n";
				cout << "7.修改\n";
				cout << "8.返回上一级\n";
				cout << "*";
				cin >> tmp;
				switch (tmp)
				{
				case 1:
					cout << "很遗憾死神来了，请输入它的名字：";
					cin >> name;
					a->Manpower_Death(a->Find_Name_Id(name));
					break;
				case 2:
					cout << "上辈子一定做了许多好事，请输入他的名字：";
					cin >> name;
					a->Manpower_Alive(a->Find_Name_Id(name));
					break;
				case 3:

					cout << "请输入A的名字:";
					cin >> name1;
					cout << "请输入B的名字:";
					cin >> name2;
					a->Manpower_Favor(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
					break;
				case 4:
					cout << "请输入A的名字:";
					cin >> name1;
					cout << "请输入B的名字:";
					cin >> name2;
					a->Manpower_Love(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
					break;
				case 5:
					cout << "请输入A的名字:";
					cin >> name1;
					cout << "请输入B的名字:";
					cin >> name2;
					a->Manpower_Quarrel(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
					break;
				case 6:
					while (1)
					{
						system("cls");
						a->Disp_All_PerInfor();
						cout << "1.经历轻微地震\n";
						cout << "2.经历中度地震\n";
						cout << "3.经历重度地震\n";
						cout << "4.经历洪涝灾害\n";
						cout << "5.经历饥荒\n";
						cout << "6.吃饭\n";
						cout << "7.约会\n";
						cout << "8.吵架\n";
						cout << "9.k歌\n";
						cout << "10.上医院\n";
						cout << "11.自习\n";
						cout << "12.敲代码\n";
						cout << "13.拜访\n";
						cout << "14.游乐园\n";
						cout << "15.打架\n";
						cout << "16.返回上一级\n";
						cout << "*";
						cin >> tmp1;
						switch (tmp1)
						{
						case 1:
							cout << "*请输入两位动物的名字:";
							cin >> name1;
							cin >> name2;
							a->Disaster_Earthquake_1(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
							break;
						case 2:
							cout << "*请输入两位动物的名字:";
							cin >> name1;
							cin >> name2;
							a->Disaster_Earthquake_2(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
							break;
						case 3:
							cout << "*请输入两位动物的名字:";
							cin >> name1;
							cin >> name2;
							a->Disaster_Earthquake_3(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
							break;
						case 4:
							cout << "*请输入两位动物的名字:";
							cin >> name1;
							cin >> name2;
							a->Disaster_Flood(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
							break;
						case 5:
							cout << "*请输入两位动物的名字:";
							cin >> name1;
							cin >> name2;
							a->Disaster_Famine(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
							break;
						case 6:
							cout << "*请输入两位动物的名字:";
							cin >> name1;
							cin >> name2;
							a->Events_Dinner(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
						case 7:
							cout << "*请输入两位动物的名字:";
							cin >> name1;
							cin >> name2;
							a->Events_Date(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
						case 8:
							cout << "*请输入两位动物的名字:";
							cin >> name1;
							cin >> name2;
							a->Events_Quarrel(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
						case 9:
							cout << "*请输入两位动物的名字:";
							cin >> name1;
							cin >> name2;
							a->Events_KTV(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
						case 10:
							cout << "*请输入两位动物的名字:";
							cin >> name1;
							cin >> name2;
							a->Events_Hospital(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
						case 11:
							cout << "*请输入两位动物的名字:";
							cin >> name1;
							cin >> name2;
							a->Events_Study(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
						case 12:
							cout << "*请输入两位动物的名字:";
							cin >> name1;
							cin >> name2;
							a->Events_Code(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
						case 13:
							cout << "*请输入两位动物的名字:";
							cin >> name1;
							cin >> name2;
							a->Events_Visit(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
						case 14:
							cout << "*请输入两位动物的名字:";
							cin >> name1;
							cin >> name2;
							a->Events_Play(a->Find_Name_Id(name1), a->Find_Name_Id(name2));
						case 15:
							cout << "*请输入两位动物的名字:";
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