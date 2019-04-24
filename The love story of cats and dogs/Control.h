#pragma once
#include "stdafx.h"
class CControl
{
public:
	CControl();
	~CControl();
protected:
	// ����ı��
	int id_isalive[1000] = { 0 };
	// ����Ⱥ
	vector<CAnimal *> animal;
	// ��������
	int Number = 0;
	//�ø�ֵ����
	int BaseLine_Favor = 50;
	//����ָ�����ߣ��ﵽ���ɽ��
	int BaseLine_Love = 50;

public:

	// ������ɶ���Ⱥ��ָ������������
	void Rand_Init_Animal();

	// ��ӡ���еĶ�����Ϣ
	void Disp_All_PerInfor();

	// �޸�
	void Change();

	// �½�����
	void Init_PersonalInformation();
	// ����������id
	int Find_Name_Id(string name);
	// ��id������
	string Find_Id_Name(int id);

	// �˹�ָ������
	void Manpower_Death(int id);
	// �˹�ָ������
	void Manpower_Alive(int id);
	// �˹�����˭��˭�ĺø�
	void Manpower_Favor(int id, int to);
	// �˹��ı�˭��˭�İ���ָ��
	void Manpower_Love(int id, int to);
	//�˹��ı�˭��˭������ֵ
	void Manpower_Quarrel(int id, int to);

	// �õ��ø�ֵ����
	int Get_BaseLine_Favor();
	// �ж�������ĺø�ֵ�Ƿ񵽴����
	bool Judge_BaseLine_Favor(int id, int to);
	// �õ�����ָ������
	int Get_BaseLine_Love();
	//�ж�������İ���ָ���Ƿ񵽴����
	bool Judge_BaseLine_Love(int id, int to);
	// ���ݻ�����Ϣ�ӷ� �������в���֮ǰ ����֮��
	void Rule_Up_Base();
	// �ж����˵ĺø�ֵʱ�򳬹�ĳֵ
	bool Judge_Favor_Exceed(int id, int to, int score);

	//��Ȼ�ֺ� ���� �ȼ�1 �� 1-3
	void Disaster_Earthquake_1(int id, int to);
	//��Ȼ�ֺ� ���� �ȼ�2 �� 4-6
	void Disaster_Earthquake_2(int id, int to);
	//��Ȼ�ֺ� ���� �ȼ�3 �� 7-9
	void Disaster_Earthquake_3(int id, int to);
	// �����ֺ�
	void Disaster_Flood(int id, int to);
	//����
	void Disaster_Famine(int id, int to);
	// �õ���������
	int Get_Number();
protected:
	// ʱ����
	int Date = 0;
public:
	// �õ�ʱ���� 
	int Get_Date();
	// ��ӡʱ����
	void Disp_Date();
	// ������
	void Rule_Marry(int id, int to);
protected:
	// ��¼���Ķ���
	int Arr_Spouse[2][1000] = { 0 };
	//��¼���Ķ���
	int Num_Spouse = 0;
public:
	// ������
	void Rule_Divorce(int id, int to);
	// ÿ���ս���һ�θ���ȸ���ֵ
	void Judge_3Day();
	// �޸�����
	void Change_Date(int date);
	// �õ��Ƿ���ı�־
	int Get_Isalive(int id);
	// �Ը�������
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

