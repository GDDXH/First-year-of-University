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
class Judge//��ί��
{
public:
	Judge();
	Judge(const node temp[10]);
	const node* getJudge();//���ʺ���,����һ����ί��Ϣ��node �ṹ������ĳ�ָ��
	void inputJudge(string s[10])//�޸ĺ���
	{
		for (int i = 0;i < 10;i++)
		{
			judge[i].name = s[i];
		}
	}

protected:
	node judge[10];
};