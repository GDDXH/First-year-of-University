#pragma once
#include"konckout.h"
#include"finalcontest.h"
#include"CLoad.h"
//比赛类
class Contest :public Konckout, public FinalContest, public CLoad
{
public:
	Contest();
	void inputKSinger();//读入选拔赛选手数据
	void inputFSinger();//读入决赛选手数据
	void add_information();//完善数据
	string getHost()const;//访问函数
	string getSponsor()const;//访问函数
	void inputHost(string);//修改函数
	void inputSponsor(string);//修改函数
	void display();//显示输出函数
	void saveKData();//输出选拔赛信息
	void saveFData();//输出决赛信息
protected:
	string host;//比赛举办方
	string sponsor;//比赛赞助商
};