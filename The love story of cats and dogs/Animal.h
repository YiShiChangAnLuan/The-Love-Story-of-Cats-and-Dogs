#pragma once

class CAnimal
{
public:
	CAnimal();
	virtual ~CAnimal();
protected:
	// ����ı��
	int ID;
	//���������
	string Name;
	//����
	string isalive = "����";
	//����ţ�������Ϊ1��������Ϊ2
	int int_kind;
	//��ż
	string Spouse = "��";
	//string Sex;
	//���
	string Kind;
	//����
	int Age;
	//��ֵ
	double Score_Face;
	//����ֵ
	double Score_Charm;
	//�ҳ�ֵ
	double Score_Loyalty;
	//���
	long long Score_Deposit;
	//��ŭֵ
	double Score_Anger = 0;
	//����ֵ
	double Score_Patience;

	//  2017/5/9 ��ʱ��λ�������������ʾ���ȴ����������ݽṹ����ʾ

	//�ø�ֵ
	double Score_Favor[1000] = { 0 };
	//����ֵ
	//double Score_Quarrel[1000] = { 0 };
	//����ָ��
	double Score_Love[1000] = { 0 };

	//�ø�ֵ����
	int ABaseLine_Favor = 50;
	//����ָ�����ߣ��ﵽ���ɽ��
	int ABaseLine_Love = 50;

public:
	// �õ���ֵ
	int Get_ID();
	// �õ�����
	int Get_Age();
	// �õ�����
	string Get_Name();
	// �õ��Ա�
	//string Get_Sex();
	//�õ����
	string Get_Kind();
	// �õ���ŭֵ
	double Get_Score_Anger();
	// �õ�����ֵ
	double Get_Score_Charm();
	// �õ����
	long long Get_Score_Deposit();
	// �õ���ֵ
	double Get_Score_Face();
	// �õ��ҳ�ֵ
	double Get_Score_Loyalty();
	// �õ�����ֵ
	double Get_Score_Patience();


	//������İ취���õ�˫��֮���ϵ����Ϣ
	// �õ���ID����İ���ָ��
	double Get_Score_Love(int id);
	// �õ���ID���������ֵ
	//double Get_Score_Quarrel(int id);
	//�õ���ID����ĺø�ֵ
	double Get_Score_Favor(int id);

	// ��ӡid
	void Disp_ID();
	//��ӡage
	void Disp_Age();
	//�Ա�
	//void Disp_Sex();
	//��ӡ����
	void Disp_Name();
	//��ӡ���
	void Disp_Kind();
	//��ӡ��ŭֵ
	void Disp_Score_Anger();
	//��ӡ����ֵ
	void Disp_Score_Charm();
	//��ӡ���
	void Disp_Score_Deposit();
	//��ӡ��ֵ
	void Disp_Score_Face();
	//��ӡ�ҳ�ֵ
	void Disp_Score_Loyalty();
	//��ӡ����ֵ
	void Disp_Score_Patience();


	//��ӡ�ø�ֵ
	void Disp_Score_Favor(int id);
	//��ӡ����ָ��
	void Disp_Score_Love(int id);
	//��ӡ����ֵ
	//void Disp_Score_Quarrel(int id);

	// ��ӡ������Ϣ
	void Disp_PersonalInformation();

	/*// ��ʼ�����˻�����Ϣ
	virtual void Init_PersonalInformation();*/
	// �޸�����
	void Change_Name();
	// �޸��Ա�
	//void Change_Sex();
	//�޸����
	void Change_Kind();
	// �޸ķ�ŭֵ
	void Change_Anger();
	// �޸�����ֵ
	void Change_Charm();
	// �޸Ĵ��
	void Change_Deposit();
	// �޸���ֵ
	void Change_Face();
	// �޸��ҳ�ֵ
	void Change_Loyalty();
	// �޸�����ֵ
	void Change_Patience();

	// ��ʼ���������Ļ�����Ϣ
	virtual void Rand_Init_PerInfor() = 0;
	// �麯�� �������
	virtual void Rand_Name() = 0;
	// ��ʼ��ID
	void Init_ID(int n);
	// �޸�����
	void Change_Age();
	// ��ӡ�Ƿ�����
	void Disp_Isalive();
	string Get_Isalive();
	// �ĳ�����
	void Change_Isalive_Death();
	// �ĳ�����
	void Change_Isalive_Alive();
	// �޸Ķ�˭�ĺø�
	void Change_Favor(int id);
	// �޸Ķ�˭�İ���ָ��
	void Change_Love(int id);
	// �޸Ķ�˭������ֵ
	void Change_Quarrel(int id);
	// �õ���ż����
	string Get_Spouse();
	// ��ӡ��ż
	void Disp_Spouse();
	//ϵͳ�޸ĺø�ֵ ��Ҫ���� 1��id һ������
	void Change_System_Up_Favor(int to,int favor);
	//ϵͳ�޸ĺø�ֵ ��Ҫ���� 1��id һ������
	void Change_System_Down_Favor(int to, int favor);
	//�ø�ֵ�һ�����ָ��
	void Rule_Favor_Love(int to);
	// �޸İ�������
	void Change_System_Spouse(string spouse_name);
	int Get_ABaseLine_Love();
	int Get_ABaseLine_Favor();
	int Get_Int_Kind();
};

