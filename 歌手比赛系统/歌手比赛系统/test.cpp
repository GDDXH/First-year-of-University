#include "test.h"

void Test::test_num()//检测选手编号,确保无重复
{
	cout << endl;
	int len = num.size();
	sort(num.begin(),num.end());
	for (int i = 1;i < len;i++)
	{
		if (num[i] == num[i - 1])
		{
			cout << "编号" << num[i] << "重复,程序将结束,请修改文本文件!!!!!!!!!" << endl;
			Sleep(3000);
			abort();
		}
	}

}

void Test::test_num(int n)
{
	int len = num.size();
	if (n <= 0 || n > Size)//编号小于等于零或大于上限,则抛出异常
		throw n*1.0;
	for (int i = 0;i < len;i++)//编号相同,则抛出异常
	{
		if (n == num[i])
			throw n;
	}
}

void Test::test_num(double n)
{
	bool sign = false;
	int t =(int) n;
	int len = num.size();
	if (t <= 0 || t > Size) //编号小于等于零或大于上限, 则抛出异常
		throw n;
	for (int i = 0;i < len;i++)//没有此编号则抛出异常
	{
		if (n == num[i])
		{
			sign = true;
			return;
		}
	}
	if (!sign)
		throw t;
}

void Test::test_ID(string s)//
{
	int len = ID.size();
	if (s.size() != 12)//学号不是12位,则抛出异常
		throw 1.0;
	for (int i = 0;i < len;i++)//学号重复,则抛出异常
	{
		if (s == ID[i])
			throw 1;
	}
}

bool Test::test_score(list  *head)
{
	list *p = head;
	while (p != NULL)
	{
		if (p->data.getSum_score() == 0)
		{
			cout << "需先评委打分,方可成绩排序" << endl;
			return false;
		}
		p = p->next;
	}
	return true;
}
