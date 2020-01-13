#include "CLoad.h"

int CLoad::Konckout_UI()
{
	int t;
	system("cls");
	cout << " ● ●---------------------------------------------------------- ● ●" << endl;
	cout << "          1：完善比赛信息               2：显示比赛信息               " << endl;
	cout << "          3：显示统计数据               4：显示总决赛名单             " << endl;
	cout << "          5: 保存数据                   0：返回初始界面               " << endl;
	cout << " ● ●---------------------------------------------------------- ● ●" << endl;
	cout << endl << "请输入你的选择:";
	cin >> t;
	return t;
}

int CLoad::Finalcontest_UI()
{
	int t;
	system("cls");
	cout << " ● ●---------------------------------------------------------- ● ●" << endl;
	cout << "          1：完善比赛信息               2：显示比赛信息               " << endl;
	cout << "          3: 保存数据                   0：返回上一界面               " << endl;
	cout << " ● ●---------------------------------------------------------- ● ●" << endl;
	cout << "请输入你的操作:";
	cin >> t;
	if (t < 0 || t>3)
	{
		system("cls");
		system("color 1F");
		cerr << "input error!" << endl;
		abort();
	}
	return t;
}

int CLoad::input_UI()
{
	int t;
	system("cls");
	cout << " ● ●---------------------------------------------------------- ● ●" << endl;
	cout << "        1：输入选拔赛信息           2：输入决赛信息                   " << endl;
	cout << "                                    0: 返回上一界面                   " << endl;
	cout << " ● ●---------------------------------------------------------- ● ●" << endl;
	cout << "请输入你的选择:";
	cin >> t;
	if (t != 1 && t != 2 && t != 0)
	{
		system("cls");
		system("color 1F");
		cerr << "input error！" << endl;
		abort();
	}
	return t;
}

int CLoad::addInformation_UI()
{
	int t;
	system("cls");
	cout << " ● ●---------------------------------------------------------- ● ●" << endl;
	cout << "          1: 完善比赛信息                   2：完善主持人信息         " << endl;
	cout << "          3：完善参与部门信息               4: 完善开销               " << endl;
	cout << "          5：完善观众数                     0：返回初始界面           " << endl;
	cout << " ● ●---------------------------------------------------------- ● ●" << endl;
	cout << "请输入你的选择:";
	cin >> t;
	if (t < 0 || t>5)
	{
		system("cls");
		system("color 1F");
		cerr << "input error!" << endl;
		abort();
	}
	return t;
}
