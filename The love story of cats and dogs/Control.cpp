#include "stdafx.h"
#include "Control.h"


CControl::CControl()
	: NUMBER(0)
{
}


CControl::~CControl()
{
}


// 随机生成动物群（指定动物数量）
void CControl::Rand_Init_Animal()
{
	//动物群数量
	int num;
	cout << "请输入你需要的动物群数量(猫狗比例1:1):";
	cin >> num;
	cout << "正在生成世界，请稍等。。。。\n";
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
	cout << "完成！" << endl;
}


// 打印所有的动物信息
void CControl::Disp_All_PerInfor()
{
	int i;
	for (i = 0; i < Number; i++)
	{
		animal[i]->Disp_PersonalInformation();
	}
}


// 修改
void CControl::Change()
{
	int tmp;
	string name;
	int G_id;
	cout << "请输入你要修改信息动物的名字:";
	cin >> name;
	system("cls");
	G_id = Find_Name_Id(name);
	animal[G_id - 1]->Disp_PersonalInformation();
	cout << "请输入你要修改的信息:\n1.姓名\n2.年龄\n3.类别\n4.颜值\n5.魅力值\n6.存款\n7.忠诚值\n8.耐心\n9.愤怒值\n10.退出\n";
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


// 新建动物
void CControl::Init_PersonalInformation()
{
	Number++;
	NUMBER++;
	id_isalive[Number] = 1;
	int tmp;
	string name;
	do
	{
		cout << "请输入动物的类别:\n1.汪星人\t2.喵星人\n";
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


// 用姓名查找id
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


// 人工指定死亡
void CControl::Manpower_Death(int id)
{
	id_isalive[id] = 0;
	animal[id - 1]->Change_Isalive_Death();
	Number--;
}



// 人工指定复活
void CControl::Manpower_Alive(int id)
{
	id_isalive[id] = 1;
	animal[id - 1]->Change_Isalive_Alive();
	Number++;
}


// 人工改变谁对谁的好感
void CControl::Manpower_Favor(int id, int to)
{
	animal[id - 1]->Change_Favor(to);
}



// 人工改变谁对谁的爱情指数
void CControl::Manpower_Love(int id, int to)
{
	animal[id - 1]->Change_Love(to);
}


//人工改变谁对谁的争吵值
void CControl::Manpower_Quarrel(int id, int to)
{
	animal[id - 1]->Change_Quarrel(to);
}

// 得到好感值基线
int CControl::Get_BaseLine_Favor()
{
	return BaseLine_Favor;
}

// 判断两动物的好感值是否到达基线
bool CControl::Judge_BaseLine_Favor(int id, int to)
{
	if (animal[id - 1]->Get_Score_Favor(to) >= Get_BaseLine_Favor() && animal[to - 1]->Get_Score_Favor(id) >= Get_BaseLine_Favor())
		return true;
	else
		return false;
}


// d得到爱情指数基线
int CControl::Get_BaseLine_Love()
{
	return BaseLine_Love;
}

//判断两动物的爱情指数是否到达基线
bool CControl::Judge_BaseLine_Love(int id, int to)
{
	if (animal[id - 1]->Get_Score_Love(to) >= Get_BaseLine_Love() && animal[to - 1]->Get_Score_Love(id) >= Get_BaseLine_Love())
		return true;
	else
		return false;
}



// 根据基本信息加分 放在所有操作之前 生成之后
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

// 判断两人的好感值时候超过某值
bool CControl::Judge_Favor_Exceed(int id, int to, int score)
{
	if (animal[id - 1]->Get_Score_Favor(to) >= score && animal[to - 1]->Get_Score_Favor(id) >= score)
	{
		return true;
	}
	else
		return false;
}


// 用id找姓名
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

//自然灾害 地震 等级1 震级 1-3
void CControl::Disaster_Earthquake_1(int id, int to)
{
	srand((unsigned int)time(0));
	int lv = rand() % 3 + 1;
	cout << "一场" << lv << "地震发生了\n";

	cout << Find_Id_Name(id) << "和" << Find_Id_Name(to) << "度过了一场插曲，彼此之间更加关心\n";
	cout << "双方好感度增加10" << endl;
	animal[id - 1]->Change_System_Up_Favor(to, 10);
	animal[to - 1]->Change_System_Up_Favor(id, 10);
	Sleep(3000);
}

//自然灾害 地震 等级2 震级 4-6
void CControl::Disaster_Earthquake_2(int id, int to)
{

	srand((unsigned int)time(0));
	int lv = rand() % (6 - 4 + 1) + 4;
	cout << "一场" << lv << "地震发生了\n";
	cout << Find_Id_Name(id) << "和" << Find_Id_Name(to) << "的家遭到毁坏，他们并没有沮丧，互相鼓励修好了房子\n";
	cout << "双方好感度增加30" << endl;
	animal[id - 1]->Change_System_Up_Favor(to, 10);
	animal[to - 1]->Change_System_Up_Favor(id, 10);
	Sleep(3000);
}

//自然灾害 地震 等级3 震级 7-9
void CControl::Disaster_Earthquake_3(int id, int to)
{

	srand((unsigned int)time(0));
	int lv = rand() % (9 - 7 + 1) + 7;
	cout << "一场" << lv << "地震发生了\n";
	cout << "一场巨大的灾难降临了，像是世界末日一样";
	if (Judge_Favor_Exceed(id, to, 10))
	{
		cout << "巨大的地震把" << Find_Id_Name(to) << "埋住了，";
		cout << Find_Id_Name(id) << "疯狂的挖出了" << Find_Id_Name(to) << "。\n";
		cout << Find_Id_Name(to) << "对" << Find_Id_Name(id) << "十分感激。\n双方好感值增加60";
		cout << "他们乐观起来，一起重建了家园。\n";
		animal[id - 1]->Change_System_Up_Favor(to, 60);
		animal[to - 1]->Change_System_Up_Favor(id, 60);
	}
	else
	{
		cout << "因为地震太恐怖，";
		cout << Find_Id_Name(id) << "对" << Find_Id_Name(to) << "的抢救并没有发挥作用\n";
		cout << Find_Id_Name(to) << "离开了世间\n";
		animal[to - 1]->Change_Isalive_Death();
		id_isalive[to] = 1;
		Number--;
	}
	Sleep(3000);
}

// 洪涝灾害
void CControl::Disaster_Flood(int id, int to)
{
	cout << "黄河发起了大水，房子田地都被淹没了。一不小心";
	cout << Find_Id_Name(to) << "脚下一滑，快被洪水冲走了，";
	if (Judge_Favor_Exceed(id, to, 0))
	{
		cout << Find_Id_Name(id) << "迅速的伸出一只手抓住了" << Find_Id_Name(to) << "。\n";
		cout << Find_Id_Name(to) << "十分感谢" << Find_Id_Name(id) << "。\n双方好感值增加40\n\n";
		animal[id - 1]->Change_System_Up_Favor(to, 40);
		animal[to - 1]->Change_System_Up_Favor(id, 40);
	}
	else
	{
		cout << Find_Id_Name(id) << "迅速的伸出一只手想要抓住" << Find_Id_Name(to) << "可是太晚了\n";
		cout << Find_Id_Name(to) << "已经被洪水冲走了，最终离开了世界\n";
		animal[to - 1]->Change_Isalive_Death();
		id_isalive[to] = 1;
		Number--;
	}
	Sleep(3000);
}

//饥荒
void CControl::Disaster_Famine(int id, int to)
{
	cout << "粮食收成很不好，";
	cout << Find_Id_Name(to) << "的食物已经吃完了，想找" << Find_Id_Name(id) << "借一点。\n";
	if (Judge_Favor_Exceed(id, to, 20))
	{
		cout << Find_Id_Name(id) << "很大方的把自己的食物分给了他.\n双方的好感值增加30\n";
	}
	else
	{
		cout << "可是" << Find_Id_Name(id) << "的食物也不够了，只给了一点点，让" << Find_Id_Name(to) << "去别人那里看看。\n双方好感减少10\n";
		animal[id]->Change_System_Down_Favor(to, 10);
		animal[to]->Change_System_Down_Favor(id, 10);
	}
	Sleep(3000);
}


// 得到动物数量
int CControl::Get_Number()
{
	return Number;
}


// 得到时间线
int CControl::Get_Date()
{
	return Date;
}


// 打印时间线
void CControl::Disp_Date()
{
	cout << "\n* 猫狗历:" << Date << "天\n\n";
}


// 结婚规则
void CControl::Rule_Marry(int id, int to)
{
	if ((animal[id - 1]->Get_Spouse() == "无" && animal[to - 1]->Get_Spouse() == "无")
		&& ((animal[id - 1]->Get_Int_Kind() == 1 && animal[to - 1]->Get_Int_Kind() == 2) ||
		((animal[id - 1]->Get_Int_Kind() == 2 && animal[to - 1]->Get_Int_Kind() == 2))))
	{
		cout << "爱情指数已达到定值，是否启动父母反对系统:\n*1.使用\n*2.不使用\n";
		int tmp;
		while (1)
		{
			cout << "*";
			cin >> tmp;
			if (tmp == 1)
			{
				cout << "虽然" << Find_Id_Name(id) << "和" << Find_Id_Name(to) << "感情至深，但父母反对，姻缘难续\n";
				break;
			}
			if (tmp == 2)
			{
				if (Judge_BaseLine_Love(id, to) && Judge_BaseLine_Love(to, id))
				{
					cout << "愿天下有情人终成眷属，前生注定，喜结良缘。新婚大喜！百年好合！\n";
					cout << Find_Id_Name(id) << "和" << Find_Id_Name(to) << "经历磨难，修成正果！\n";
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
				cout << "输入错误请重新输入\n";
		}
	}
	else
		cout << "暂不处理这项业务\n";
}


// 离婚规则
void CControl::Rule_Divorce(int id, int to)
{
	if ((animal[id - 1]->Get_Spouse() == "无" && animal[to - 1]->Get_Spouse() == "无")
		&& ((animal[id - 1]->Get_Int_Kind() == 1 && animal[to - 1]->Get_Int_Kind() == 2) ||
		((animal[id - 1]->Get_Int_Kind() == 2 && animal[to - 1]->Get_Int_Kind() == 2))))
	{
		if (!(Judge_BaseLine_Love(id, to)) || !(Judge_BaseLine_Love(to, id)))
		{
			cout << "离婚容易，婚姻不易，仔细考虑再考虑\n";
		}
		if (!(Judge_BaseLine_Love(id, to) && Judge_BaseLine_Love(to, id)))
		{
			cout << "今夕何夕，明月依旧，爱恨几时休。\n沧海桑田，阴晴圆缺，缘分最难寻。";
			cout << Find_Id_Name(id) << "和" << Find_Id_Name(to) << "感情破裂，从此缘尽，解除婚姻关系。\n";
			animal[id - 1]->Change_System_Spouse("无");
			animal[to - 1]->Change_System_Spouse("无");
			Num_Spouse--;
			Arr_Spouse[0][Num_Spouse + 1] = 0;
			Arr_Spouse[1][Num_Spouse + 1] = 0;
		}
	}
	else
		cout << "暂不处理这项业务\n";
}


// 每三日结算一次感情等各种值
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


// 修改日期
void CControl::Change_Date(int date)
{
	Date = Get_Date() + date;
}


// 得到是否存活的标志
int CControl::Get_Isalive(int id)
{
	return id_isalive[id];
}

void CControl::Events_Dinner(int id, int to)
{
	cout << Find_Id_Name(id) << "和" << Find_Id_Name(to) << "在路上偶遇，恰巧没事，相约吃饭。\n双方好感度增加10\n";
	animal[id - 1]->Change_System_Up_Favor(to, 10);
	animal[to - 1]->Change_System_Up_Favor(id, 10);
	Sleep(3000);
}

void CControl::Events_Date(int id, int to)
{
	cout << Find_Id_Name(id) << "和" << Find_Id_Name(to) << "在几天前相约今天去咖啡馆喝咖啡\n双方好感度增加20\n";
	animal[id - 1]->Change_System_Up_Favor(to, 20);
	animal[to - 1]->Change_System_Up_Favor(id, 20);
	Sleep(3000);
}

void CControl::Events_Quarrel(int id, int to)
{
	cout << Find_Id_Name(id) << "和" << Find_Id_Name(to) << "因为空调凉快还是风扇凉快吵了起来\n双方好感度减少10\n";
	animal[id - 1]->Change_System_Down_Favor(to, 10);
	animal[to - 1]->Change_System_Down_Favor(id, 10);
	Sleep(3000);
}

void CControl::Events_KTV(int id, int to)
{
	cout << Find_Id_Name(id) << "和" << Find_Id_Name(to) << "晚上没事，一起去ktv唱了一晚上的歌\n双方好感度增加20\n";
	animal[id - 1]->Change_System_Up_Favor(to, 20);
	animal[to - 1]->Change_System_Up_Favor(id, 20);
	Sleep(3000);
}

void CControl::Events_Hospital(int id, int to)
{
	cout << Find_Id_Name(id) << "去" << Find_Id_Name(to) << "家里发现他斗鸡眼了，立即送了他去医院\n双方好感度增加20\n";
	animal[id - 1]->Change_System_Up_Favor(to, 20);
	animal[to - 1]->Change_System_Up_Favor(id, 20);
	Sleep(3000);
}

void CControl::Events_Study(int id, int to)
{
	cout << Find_Id_Name(id) << "和" << Find_Id_Name(to) << "一起去自习室看漫画\n双方好感度增加20\n";
	animal[id - 1]->Change_System_Up_Favor(to, 20);
	animal[to - 1]->Change_System_Up_Favor(id, 20);
	Sleep(3000);
}

void CControl::Events_Code(int id, int to)
{
	cout << Find_Id_Name(id) << "和" << Find_Id_Name(to) << "一起敲代码，互相交流经验\n双方好感度增加40\n";
	animal[id - 1]->Change_System_Up_Favor(to, 40);
	animal[to - 1]->Change_System_Up_Favor(id, 40);
	Sleep(3000);
}

void CControl::Events_Visit(int id, int to)
{
	cout << Find_Id_Name(id) << "去拜访" << Find_Id_Name(to) << "，他很高兴有人来看他\n双方好感度增加20\n";
	animal[id - 1]->Change_System_Up_Favor(to, 20);
	animal[to - 1]->Change_System_Up_Favor(id, 20);
	Sleep(3000);
}

void CControl::Events_Play(int id, int to)
{
	cout << Find_Id_Name(id) << "和" << Find_Id_Name(to) << "一起去游乐园坐旋转木马\n双方好感度增加30\n";
	animal[id - 1]->Change_System_Up_Favor(to, 30);
	animal[to - 1]->Change_System_Up_Favor(id, 30);
	Sleep(3000);
}

void CControl::Events_Fight(int id, int to)
{
	cout << Find_Id_Name(id) << "和" << Find_Id_Name(to) << "一言不合就打起来了，原因竟然是写代码的人太帅了\n双方好感度减少20\n";
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
			cout << "对" << Find_Id_Name(i) << "好感:";
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
			cout << "对" << Find_Id_Name(i) << "爱情:";
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

