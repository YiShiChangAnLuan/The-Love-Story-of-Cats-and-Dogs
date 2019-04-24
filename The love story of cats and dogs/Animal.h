#pragma once

class CAnimal
{
public:
	CAnimal();
	virtual ~CAnimal();
protected:
	// 动物的编号
	int ID;
	//动物的名字
	string Name;
	//生死
	string isalive = "生存";
	//类别编号，汪星人为1，喵星人为2
	int int_kind;
	//配偶
	string Spouse = "无";
	//string Sex;
	//类别
	string Kind;
	//年龄
	int Age;
	//颜值
	double Score_Face;
	//魅力值
	double Score_Charm;
	//忠诚值
	double Score_Loyalty;
	//存款
	long long Score_Deposit;
	//愤怒值
	double Score_Anger = 0;
	//耐心值
	double Score_Patience;

	//  2017/5/9 暂时定位此三项用数组表示，等待考虑用数据结构来表示

	//好感值
	double Score_Favor[1000] = { 0 };
	//争吵值
	//double Score_Quarrel[1000] = { 0 };
	//爱情指数
	double Score_Love[1000] = { 0 };

	//好感值基线
	int ABaseLine_Favor = 50;
	//爱情指数基线，达到即可结婚
	int ABaseLine_Love = 50;

public:
	// 得到颜值
	int Get_ID();
	// 得到年龄
	int Get_Age();
	// 得到名字
	string Get_Name();
	// 得到性别
	//string Get_Sex();
	//得到类别
	string Get_Kind();
	// 得到愤怒值
	double Get_Score_Anger();
	// 得到魅力值
	double Get_Score_Charm();
	// 得到存款
	long long Get_Score_Deposit();
	// 得到颜值
	double Get_Score_Face();
	// 得到忠诚值
	double Get_Score_Loyalty();
	// 得到耐心值
	double Get_Score_Patience();


	//用数组的办法来得到双方之间关系的信息
	// 得到该ID动物的爱情指数
	double Get_Score_Love(int id);
	// 得到该ID动物的争吵值
	//double Get_Score_Quarrel(int id);
	//得到该ID动物的好感值
	double Get_Score_Favor(int id);

	// 打印id
	void Disp_ID();
	//打印age
	void Disp_Age();
	//性别
	//void Disp_Sex();
	//打印名字
	void Disp_Name();
	//打印类别
	void Disp_Kind();
	//打印愤怒值
	void Disp_Score_Anger();
	//打印魅力值
	void Disp_Score_Charm();
	//打印存款
	void Disp_Score_Deposit();
	//打印颜值
	void Disp_Score_Face();
	//打印忠诚值
	void Disp_Score_Loyalty();
	//打印耐心值
	void Disp_Score_Patience();


	//打印好感值
	void Disp_Score_Favor(int id);
	//打印爱情指数
	void Disp_Score_Love(int id);
	//打印争吵值
	//void Disp_Score_Quarrel(int id);

	// 打印个人信息
	void Disp_PersonalInformation();

	/*// 初始化个人基本信息
	virtual void Init_PersonalInformation();*/
	// 修改名字
	void Change_Name();
	// 修改性别
	//void Change_Sex();
	//修改类别
	void Change_Kind();
	// 修改愤怒值
	void Change_Anger();
	// 修改魅力值
	void Change_Charm();
	// 修改存款
	void Change_Deposit();
	// 修改颜值
	void Change_Face();
	// 修改忠诚值
	void Change_Loyalty();
	// 修改耐心值
	void Change_Patience();

	// 初始化随机动物的基本信息
	virtual void Rand_Init_PerInfor() = 0;
	// 虚函数 随机姓名
	virtual void Rand_Name() = 0;
	// 初始化ID
	void Init_ID(int n);
	// 修改年龄
	void Change_Age();
	// 打印是否生死
	void Disp_Isalive();
	string Get_Isalive();
	// 改成死亡
	void Change_Isalive_Death();
	// 改成生存
	void Change_Isalive_Alive();
	// 修改对谁的好感
	void Change_Favor(int id);
	// 修改对谁的爱情指数
	void Change_Love(int id);
	// 修改对谁的争吵值
	void Change_Quarrel(int id);
	// 得到配偶名字
	string Get_Spouse();
	// 打印配偶
	void Disp_Spouse();
	//系统修改好感值 需要传入 1个id 一个分数
	void Change_System_Up_Favor(int to,int favor);
	//系统修改好感值 需要传入 1个id 一个分数
	void Change_System_Down_Favor(int to, int favor);
	//好感值兑换爱情指数
	void Rule_Favor_Love(int to);
	// 修改伴侣名字
	void Change_System_Spouse(string spouse_name);
	int Get_ABaseLine_Love();
	int Get_ABaseLine_Favor();
	int Get_Int_Kind();
};

