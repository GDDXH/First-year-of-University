/*
������Ƿ����ļ���,������:�������ݲ���������,��ί���
�ɼ�����,׷��ѡ��,���ݲ�ѯ��
*/
#pragma once
#include"singer.h"
#include"test.h"
#include"SLoad.h"
class SingerList :public Test,public SLoad
{
private: 
	list *head;//list �� �Լ�����Ľṹ��,�����singer.h
public:
	SingerList();
	bool creat_list();//����ѡ�����ݲ�����ѡ����Ϣ��
	void infile_judge();//������ί��Ϣ
	void add_information();//����ѡ����Ϣ
	bool outfile();//������Ϣ���ļ�
	void mark_score();//���
	void statistics();//����ͳ��
	void print_list();//��ʾѡ��
	void sort_number();//ѡ�ֳɼ�����
	void seek();//��ѯ����
	void modify();//�޸Ĺ���
	void add_singer();//���ѡ�� 
	void delete_singer();//ɾ��ѡ��
	list *gethead()const;//���ʺ���
	void rank_list();//�������,��ѡ������
	friend void QuickSort(list* pBegin, list* pEnd);//��Ԫ���� ������ʵ�ֿ�������
	~SingerList();//��������
};


