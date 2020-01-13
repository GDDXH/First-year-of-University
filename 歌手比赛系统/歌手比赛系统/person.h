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
const int Size = 100;//限定编号,这个歌手比赛系统所使用的的比赛,参赛者不应超过100人
//凡是以get 开头的函数,即访问函数,返回某个数据
//凡是以input开头的函数,即修改函数,给某个数据赋值
//凡是display函数,即显示输出函数
class Person
{
public:
	//构造函数
	Person();
	Person(string n, int a, string s) :name(n), age(a), sex(s){};

	string getName()const;//访问函数,返回姓名
	int getAge()const;//访问函数,返回年龄
	string getSex()const;//访问函数,返回性别

	void inputName(string);//修改函数,修改姓名
	void inputAge(int);//修改函数,修改年龄
	void inputSex(string);//修改函数,修改性别
	void inputAge();//修改函数,修改年龄
	void inputSex();//修改函数,修改性别
	virtual void display();//显示输出函数
protected:
	string name;//姓名
	int age;//年龄
	string sex;//性别
};
