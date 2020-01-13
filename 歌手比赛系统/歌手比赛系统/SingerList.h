/*
这个类是方法的集合,功能有:读入数据并建立链表,评委打分
成绩排序,追加选手,数据查询等
*/
#pragma once
#include"singer.h"
#include"test.h"
#include"SLoad.h"
class SingerList :public Test,public SLoad
{
private: 
	list *head;//list 是 自己定义的结构体,具体见singer.h
public:
	SingerList();
	bool creat_list();//输入选手数据并创建选手信息表
	void infile_judge();//输入评委信息
	void add_information();//完善选手信息
	bool outfile();//保存信息到文件
	void mark_score();//打分
	void statistics();//数据统计
	void print_list();//显示选手
	void sort_number();//选手成绩排序
	void seek();//查询功能
	void modify();//修改功能
	void add_singer();//添加选手 
	void delete_singer();//删除选手
	list *gethead()const;//访问函数
	void rank_list();//在排序后,给选手排名
	friend void QuickSort(list* pBegin, list* pEnd);//友元函数 是用于实现快速排序
	~SingerList();//析构函数
};


