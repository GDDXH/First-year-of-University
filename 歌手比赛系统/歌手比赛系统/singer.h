#pragma once
#include"student.h"
#include"judge.h"
//������
class Singer:public Student,public Judge
{
public:
	Singer();//���캯��
	Singer(string  na, int n, string stu, string so, string s, int a, string c, int sum, double average, int rank) :
		Student(na, a, s, stu, c), Judge()
	{
		number = n;
		song = so;
		sum_score = sum;
		average_score = average;
		ranking = rank;
		flag = true;
	}
	Singer(const Singer &);//�������캯��
	
	void calculation();//����ƽ����
	void mark();//���
	void input(string ,int,string ,string,string,int,string);//�޸ĺ���
	void input(string, int);
	void inputRanking(int);//�޸ĺ���,�ڳɼ������֮��,��ѡ������;
	void inputSong(string s);//�޸ĺ������޸Ĳ�������
	void inputFlag(bool);

	int getNumber()const;//���ʺ���
	int  getSum_score()const;//���ʺ���
	double getAverage_score()const;//���ʺ���
	int getRanking()const;//���ʺ���
	string getSong()const;//���ʺ���
	bool getFlag()const;//���ʺ���

	virtual void display();//��ʾ�������,�����������
	void display_judge();//��ʾ�������,�����ί�����Ϣ

	friend ostream &operator<<(ostream &output, Singer &temp);//���������������

	~Singer();//��������

private:
	string song;//��������
	bool  flag;//ѡ����Ϣ�Ƿ�����
	int number;//���
	int  sum_score;//�ܷ�
	double average_score;//ƽ����
	int ranking;//����
};

struct list //���ڽ�������Ľṹ��
{
	Singer data;
	list *next;
};