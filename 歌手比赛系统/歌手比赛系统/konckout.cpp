#include "konckout.h"

Konckout::Konckout() :C_basis(),Player()
{
	CollegeStatistics.clear();
	AgeStatistics.clear();
	SexStatistics.clear();
}



void Konckout::statistics()//统计数据
{
	cout << "正在统计数据" << endl;
	for (int i = 0;i < getPlayerNumber();i++)
	{
		string college = player_infomation[i].getCollege();
		CollegeStatistics[college]++;
	}
	for (int i = 0;i < getPlayerNumber();i++)
	{
		int age = player_infomation[i].getAge();
		AgeStatistics[age]++;
	}
	for (int i = 0;i < getPlayerNumber();i++)
	{
		string sex = player_infomation[i].getSex();
		SexStatistics[sex]++;
	}
	for (int i = 0;i < 20;i++)
	{
		Fsinger[i] = player_infomation[i];
	}
	Sleep(500);
	cout << "统计数据成功" << endl;
	Sleep(500);
}

void Konckout::statisticsDisplay()//显示统计数据
{
	system("cls");
	cout << setw(30) << "选拔赛数据统计" << endl << endl;
	cout << setw(5) << "比赛人数:" << getPlayerNumber() << endl;
	cout << "各学院参赛情况" << endl << endl;
	for (map<string, int>::iterator it = CollegeStatistics.begin();it != CollegeStatistics.end();it++)
	{
		cout << setw(10) << it->first << ":" << setw(2) << it->second << endl;
	}
	cout << endl;
	cout << "各年龄段参赛情况" << endl << endl;
	for (map<int, int>::iterator it = AgeStatistics.begin();it != AgeStatistics.end();it++)
	{
		cout << "年龄" << setw(5) << it->first << "" << ":" << setw(2) << it->second << endl;
	}
	cout << endl;
	cout << "男女参赛情况" << endl << endl;
	for (map<string, int>::iterator it = SexStatistics.begin();it != SexStatistics.end();it++)
	{
		cout << setw(10) << it->first << ":" << setw(2) << it->second << endl;
	}
	cout << "\n提示:按任意键返回";
	_getch();
}

void Konckout::finalcontestList()
{
	system("cls");
	cout << setw(40) << "入围总决赛名单" << endl << endl;;
	cout << setw(15) << "姓名" << setw(15) << "编号" << setw(20) << "学号" << endl;
	for (int i = 0;i < 20;i++)
	{
		string name, student_ID;
		int number;
		name = Fsinger[i].getName();
		number = Fsinger[i].getNumber();
		student_ID = Fsinger[i].getStudent_id();
		cout << setw(15) << name << setw(15) << number << setw(20) << student_ID << endl;
	}
	cout << endl;
	system("pause");
}
