#pragma once
#include"person.h"
struct node
{
	string name;
	int score;
	bool operator<(node  b)
	{
		return this->score < b.score;
	}
};
class Judge//评委类
{
public:
	Judge();
	Judge(const node temp[10]);
	const node* getJudge();//访问函数,返回一个评委信息的node 结构体数组的常指针
	void inputJudge(string s[10])//修改函数
	{
		for (int i = 0;i < 10;i++)
		{
			judge[i].name = s[i];
		}
	}

protected:
	node judge[10];
};