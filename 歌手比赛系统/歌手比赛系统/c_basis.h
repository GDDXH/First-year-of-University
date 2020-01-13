#pragma once
#include"person.h"
//比赛的基本信息
class C_basis
{
public:
	C_basis() { name = "未完善";when = "未完善";where = "未完善"; };//构造函数
	void inputWhen(string);
	void inputWhere(string);
	void inputName(string);//修改函数
	string getName()const;//访问函数
protected:
	string name;//比赛名称
	string when;//比赛时间
	string where;//比赛地点
};