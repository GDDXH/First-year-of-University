#pragma once
#include"person.h"
// 登录界面
class Load
{
public:
	static void initialization();//静态函数,功能:从文件中读入password并赋值
	static void inputPassword(string);//静态函数,功能:改变密码
	static void Load_UI();//静态函数,功能:登录界面
	static int choose_UI();//选择界面函数,功能:选手信息管理 or 比赛信息管理
protected:
	static string password;//静态成员变量,登录密码
};
