#pragma once
#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>
#include<iomanip>
#include<time.h>
#include<Windows.h>
#include<conio.h>
#include<cstdlib>
#include<vector>
#include<map>
using namespace std;
const int Size = 100;//�޶����,������ֱ���ϵͳ��ʹ�õĵı���,�����߲�Ӧ����100��
//������get ��ͷ�ĺ���,�����ʺ���,����ĳ������
//������input��ͷ�ĺ���,���޸ĺ���,��ĳ�����ݸ�ֵ
//����display����,����ʾ�������
class Person
{
public:
	//���캯��
	Person();
	Person(string n, int a, string s) :name(n), age(a), sex(s){};

	string getName()const;//���ʺ���,��������
	int getAge()const;//���ʺ���,��������
	string getSex()const;//���ʺ���,�����Ա�

	void inputName(string);//�޸ĺ���,�޸�����
	void inputAge(int);//�޸ĺ���,�޸�����
	void inputSex(string);//�޸ĺ���,�޸��Ա�
	void inputAge();//�޸ĺ���,�޸�����
	void inputSex();//�޸ĺ���,�޸��Ա�
	virtual void display();//��ʾ�������
protected:
	string name;//����
	int age;//����
	string sex;//�Ա�
};
