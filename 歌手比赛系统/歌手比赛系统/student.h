#pragma once
#include"person.h"
//ѧ����
class Student:public Person
{
public:
	Student();//Ĭ�Ϲ��캯��

	Student(string n, int a, string s,string stu, string c):Person(n,a,s),student_id(stu), college(c) {};//���캯��

	string getStudent_id()const;//���ʺ���
	string getCollege()const;

	void inputStudent_id(string id);//�޸ĺ���
	void  inputCollege(string c);

	virtual void display();//��ʾ�������
protected:
	string student_id;//ѧ��
	string college;//����ѧԺ
};
