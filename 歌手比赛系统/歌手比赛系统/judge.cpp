#include "judge.h"
Judge::Judge()//Ĭ�Ϲ��캯��
{
	for(int i=0;i<10;i++)
		judge[i].name ="δ����";
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
	//���ʺ���,����ָ����ί��һnode �ṹ�������ָ��
	return judge;
}
