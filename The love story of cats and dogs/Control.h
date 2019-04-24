#pragma once
#include "stdafx.h"
class CControl
{
public:
	CControl();
	~CControl();
protected:
	// 动物的编号
	int id_isalive[1000] = { 0 };
	// 动物群
	vector<CAnimal *> animal;
	// 动物数量
	int Number = 0;
	//好感值基线
	int BaseLine_Favor = 50;
	//爱情指数基线，达到即可结婚
	int BaseLine_Love = 50;

public:

	// 随机生成动物群（指定动物数量）
	void Rand_Init_Animal();

	// 打印所有的动物信息
	void Disp_All_PerInfor();

	// 修改
	void Change();

	// 新建动物
	void Init_PersonalInformation();
	// 用姓名查找id
	int Find_Name_Id(string name);
	// 用id找姓名
	string Find_Id_Name(int id);

	// 人工指定死亡
	void Manpower_Death(int id);
	// 人工指定复活
	void Manpower_Alive(int id);
	// 人工提升谁对谁的好感
	void Manpower_Favor(int id, int to);
	// 人工改变谁对谁的爱情指数
	void Manpower_Love(int id, int to);
	//人工改变谁对谁的争吵值
	void Manpower_Quarrel(int id, int to);

	// 得到好感值基线
	int Get_BaseLine_Favor();
	// 判断两动物的好感值是否到达基线
	bool Judge_BaseLine_Favor(int id, int to);
	// 得到爱情指数基线
	int Get_BaseLine_Love();
	//判断两动物的爱情指数是否到达基线
	bool Judge_BaseLine_Love(int id, int to);
	// 根据基本信息加分 放在所有操作之前 生成之后
	void Rule_Up_Base();
	// 判断两人的好感值时候超过某值
	bool Judge_Favor_Exceed(int id, int to, int score);

	//自然灾害 地震 等级1 震级 1-3
	void Disaster_Earthquake_1(int id, int to);
	//自然灾害 地震 等级2 震级 4-6
	void Disaster_Earthquake_2(int id, int to);
	//自然灾害 地震 等级3 震级 7-9
	void Disaster_Earthquake_3(int id, int to);
	// 洪涝灾害
	void Disaster_Flood(int id, int to);
	//饥荒
	void Disaster_Famine(int id, int to);
	// 得到动物数量
	int Get_Number();
protected:
	// 时间线
	int Date = 0;
public:
	// 得到时间线 
	int Get_Date();
	// 打印时间线
	void Disp_Date();
	// 结婚规则
	void Rule_Marry(int id, int to);
protected:
	// 记录结婚的动物
	int Arr_Spouse[2][1000] = { 0 };
	//记录结婚的对数
	int Num_Spouse = 0;
public:
	// 离婚规则
	void Rule_Divorce(int id, int to);
	// 每三日结算一次感情等各种值
	void Judge_3Day();
	// 修改日期
	void Change_Date(int date);
	// 得到是否存活的标志
	int Get_Isalive(int id);
	// 吃个饭规则
	virtual void Events_Dinner(int id, int to);
	void Events_Date(int id, int to);
	void Events_Study(int id, int to);
	void Events_Code(int id, int to);
	void Events_Visit(int id, int to);
	void Events_Play(int id, int to);
	void Events_Fight(int id, int to);
	void Events_Quarrel(int id, int to);
	void Events_KTV(int id, int to);
	void Events_Hospital(int id, int to);
protected:
	int NUMBER;
public:
	void Disp_Per(int id);
	void Disp_Per_Favor(int id);
	void Disp_Per_Love(int id);
};

