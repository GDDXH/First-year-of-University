#pragma once
#include"singer.h"
//������ѡ������ʱ,Ҫȷ��ѡ�ֵı����ѧ�ž���ͬ;
class Test
{
protected:
	vector <int>num;//��¼����ѡ�ֵı��
	vector <string>ID;//��¼����ѡ�ֵ�ѧ��
public:
	Test() {
		num.clear();
		ID.clear();
	}

	//�������ڼ�����Ƿ��ظ��ĺ���,
	void test_num();
	void test_num(int);
	void test_num(double);

	//���ڼ��ѧ���Ƿ��ظ�
	void test_ID(string);

	//���ڼ����ί�Ƿ�������
	bool test_score(list * head);
};