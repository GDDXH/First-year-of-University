#include "SLoad.h"
int SLoad::main_UI()//主界面函数
{
	int t;
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置字体为白色


	cout << "\t\t*___________________________________________________________*" << endl
		<< "\t\t|                                                          |" << endl
		<< "\t\t|";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//设置字体红色

	cout << "\t\t    欢迎使用歌手比赛系统                   ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);;//设置字体为白色
	cout << "|" << endl;
	cout << "\t\t|                                                          |" << endl;
	cout << "\t\t|\t选手信息操作菜单:                                  |" << endl
		<< "\t\t|\t1、完善信息                   2、评委打分          |" << endl
		<< "\t\t|\t3、成绩排序                   4、查询系统          |" << endl
		<< "\t\t|\t5、追加选手                   6、修改系统          |" << endl
		<< "\t\t|\t7、显示全部选手数据           8、统计系统          |" << endl
		<< "\t\t|\t9、输出数据                   0、返回上一界面      |" << endl
		<< "\t\t|                                                          |" << endl;
	cout << "\t\t*__________________________________________________________*" << endl
		<< "\t\t                                       PS:请先读入数据" << endl
		<< "\t\t                                       并完善信息       " << endl
		<< endl << "请输入你的选择:";
	cin>>t;
	return t;
}
void SLoad::statistics_UI()
{
	system("cls");
	cout << " ● ●---------------------------------------------------------- ● ●" << endl;
	cout << "             1：根据性别                2：根据年龄                   " << endl;
	cout << "             3: 根据学院                4: 根据总分                   " << endl;
	cout << "             5: 根据平均分              6: 根据名次                   " << endl;
	cout << "                                        0: 返回上一界面               " << endl;
	cout << " ● ●---------------------------------------------------------- ● ●" << endl;
}

void SLoad::creat_UI()
{
	system("cls");
	cout << " ● ●---------------------------------------------------------- ● ●" << endl;
	cout << "             1：文件输入(信息未完善)    2：文件输入(信息已完善)       " << endl;
	cout << "                                        0: 返回上一界面               " << endl;
	cout << " ● ●---------------------------------------------------------- ● ●" << endl;
}

void SLoad::seek_UI()
{
	system("cls");
	cout << " ● ●---------------------------------------------------------- ● ●" << endl;
	cout << "             1：按姓名查询                  2：按编号查询             " << endl;
	cout << "                                            0: 返回上一界面           " << endl;
	cout << " ● ●---------------------------------------------------------- ● ●" << endl;
}

void SLoad::modify_UI()
{
	system("cls");
	cout << " ● ●---------------------------------------------------------- ● ●" << endl;
	cout << "             1：删除选手                  2：修改姓名                 " << endl;
	cout << "             3：修改性别                  4：修改年龄                 " << endl;
	cout << "             5: 修改参赛歌曲              6: 修改学院                 " << endl;
	cout << "                                          0：返回上一界面             " << endl;
	cout << " ● ●---------------------------------------------------------- ● ●" << endl;
}

