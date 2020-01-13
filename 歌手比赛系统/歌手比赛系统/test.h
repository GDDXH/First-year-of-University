#pragma once
#include"singer.h"
//当输入选手数据时,要确保选手的编号与学号均不同;
class Test
{
protected:
	vector <int>num;//记录所有选手的编号
	vector <string>ID;//记录所有选手的学号
public:
	Test() {
		num.clear();
		ID.clear();
	}

	//三个用于检测编号是否重复的函数,
	void test_num();
	void test_num(int);
	void test_num(double);

	//用于检测学号是否重复
	void test_ID(string);

	//用于检测评委是否已评分
	bool test_score(list * head);
};