#include "Load.h"
string Load::password = "0";//静态变量类外初始化
void Load::initialization()//初始化函数
{
	string t;
	fstream infile("password.dat", ios::in);
	if (!infile)
	{
		system("cls");
		system("color 1F");
		cerr << "open error!" << endl;
		abort();
	}
	infile >> t;
	password = t;
}

void Load::inputPassword(string t)//修改函数,修改登录密码
{
	password = t;
	fstream outfile("password.dat", ios::out);
	if (!outfile)
	{
		system("cls");
		system("color 1F");
		cerr << "open error!" << endl;
		abort();
	}
	outfile << password;
}

void Load::Load_UI()
{
	system("color 0F");//设置背景为黑色,字体为亮白色
	initialization();//初始函数,初始化password
	string s;
	int t;
	cout << "● ●----------------------------------------------------------- ● ●" << endl;
	cout << "                       歌手比赛系统登录界面                           " << endl << endl;
	cout << "        1:登录            2:登录并修改密码          0:退出            " << endl;
	cout << "● ●----------------------------------------------------------- ● ●" << endl;
	cout << "请输入你的选择:";
	cin >> t;
	if (t == 0)//从这里正常退出程序
		exit(0);
	else if (t == 1)
	{
		cout << " 请输入密码(输入0退出):" << endl;
		while (1)
		{
			cin >> s;
			if (s == "0")
				exit(1);
			if (s == password)
			{
				//cout<<"登录成功"
				break;
			}
			else
			{
				cout << "密码错误,请重新输入(输入0退出):" << endl;
			}
		}
	}
	else if (t == 2)
	{
		cout << " 请输入原密码(输入0退出):" << endl;
		while (1)
		{
			cin >> s;
			if (s == "0")
				exit(1);
			if (s == password)
			{
				//cout<<"登录成功"

				break;
			}
			else
			{
				cout << "密码错误,请重新输入(输入0退出):" << endl;
			}
		}
		cout << "请输入新密码:";//如果输入是原密码也没有关系
		cin >> s;
		inputPassword(s);
		cout << "修改成功" << endl;
	}
	else
	{
		system("cls");
		system("color 1F");
		cerr << "输入错误,程序默认结束" << endl;
		abort();
	}
	Sleep(500);
	system("cls");
}

int Load::choose_UI()//选择界面
{
	system("cls");
	int t;
	cout << " ● ●---------------------------------------------------------- ● ●" << endl;
	cout << "                       歌手比赛系统登录界面                           " << endl << endl;
	cout << "          1:选手信息管理         2:比赛信息管理       0:退出程序      " << endl;
	cout << " ● ●---------------------------------------------------------- ● ●" << endl << endl;
	cout << "请输入你的选择: ";
	cin >> t;
	if (t == 0)//退出程序
	{
		exit(0);
	}
	else if (t != 1 && t != 2)
	{
		system("cls");
		system("color 1F");
		cerr << "input error" << endl; 
		abort();
	}
	return t;
}
