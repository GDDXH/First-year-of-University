#include "judge.h"
Judge::Judge()//默认构造函数
{
	for(int i=0;i<10;i++)
		judge[i].name ="未完善";
}
Judge::Judge(const node temp[10])
{
	for (int i = 0;i < 10;i++)
	{
		judge[i].name = temp[i].name;
		judge[i].score = temp[i].score;
	}
}
const node * Judge::getJudge()
{
	//访问函数,返回指向评委这一node 结构体数组的指针
	return judge;
}
