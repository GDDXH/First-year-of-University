#pragma once
#include"person.h"
//选手界面类
class SLoad
{
public:
	SLoad() {};
	int  main_UI();//选手数据主菜单界面
	void creat_UI();//读入数据界面
	void seek_UI();//查询功能界面
	void modify_UI();//修改功能界面
	void statistics_UI();//统计功能界面

};