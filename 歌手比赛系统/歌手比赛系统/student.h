#pragma once
#include"person.h"
//学生类
class Student:public Person
{
public:
	Student();//默认构造函数

	Student(string n, int a, string s,string stu, string c):Person(n,a,s),student_id(stu), college(c) {};//构造函数

	string getStudent_id()const;//访问函数
	string getCollege()const;

	void inputStudent_id(string id);//修改函数
	void  inputCollege(string c);

	virtual void display();//显示输出函数
protected:
	string student_id;//学号
	string college;//所属学院
};
