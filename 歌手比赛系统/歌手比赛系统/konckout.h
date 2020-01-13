#pragma once
#include"c_basis.h"
#include"player.h"
//选拔赛类
class Konckout:virtual public C_basis, virtual public Player
{
public:
	Konckout();
	void statistics();//数据统计
	void statisticsDisplay();//显示数据统计结果
	void finalcontestList();//显示入围总决赛名单
protected:

	map<string, int> CollegeStatistics;//统计各学院参赛人数
	map<int, int> AgeStatistics;//统计各年龄参赛人数
	map<string, int>SexStatistics;//统计男女参赛人数
	Singer Fsinger[20];//决赛选手
};