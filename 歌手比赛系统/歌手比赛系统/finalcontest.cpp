#include "finalcontest.h"

FinalContest::FinalContest():C_basis(),Player()
{
	department.clear();
	spend.clear();
	audience = 0;
}

void FinalContest::inputTopTensinger()
{
	for (int i = 0;i < 10;i++)
	{
		TopTensinger[i] = player_infomation[i];
	}
}

void FinalContest::displayTopTensinger()
{
	cout << setw(40) << "十佳歌手" << endl << endl;
	cout << "姓名\t编号\t学号\t\t总分\t平均分\t名次" << endl;
	for (int i = 0;i < 10;i++)
	{
		cout << TopTensinger[i];
	}
	cout << "姓名\t学号\t\t参赛歌曲\t年龄\t性别\t学院" << endl;
	for (int i = 0;i < 10;i++)
	{
		TopTensinger[i].display();
	}
	cout << endl;
}

void FinalContest::inputPresenter()
{
	string s;
	int n;
	for (int i = 0;i < 2;i++)
	{
		cout << "请输入第" << i+1 << "位主持人姓名:";
		cin >> s;
		Presenter[i].inputName(s);
		cout << "请输入第" << i+1 << "位主持人性别:";
		cin >> s;
		Presenter[i].inputSex(s);
		cout << "请输入第" << i+1 << "位主持人年龄:";
		cin >> n;
		Presenter[i].inputAge(n);
		cout << "请输入第" << i+1 << "位主持人学号:";
		cin >> s;
		Presenter[i].inputStudent_id(s);
		cout << "请输入第" << i+1 << "位主持人学院:";
		cin >> s;
		Presenter[i].inputCollege(s);
		cout << "完善信息成功" << endl << endl;
	}
	system("pause");
}

void FinalContest::inputAudience()//输入观众人数
{
	cout << "请输入观众数:";
	cin >> audience;
	system("pause");
}

int FinalContest::getAudience()//访问函数 功能:返回观众人数
{
	return audience;
}

void FinalContest::inputDepartment()
{
	string s;
	cout << "请输入参与部门(0结束):";
	while (cin >> s)
	{	
		if (s == "0")
		{
			break;
		}
		this->department.push_back(s);
		cout << "请输入参与部门(0结束):";
	}
	cout << "完善参与部门成功" << endl;
	system("pause");
}

void FinalContest::inputSpend()
{
	string s;
	cout << "请输入开销(0结束):";
	while (cin >> s)
	{
		if (s == "0")
		{
			break;
		}
		this->spend.push_back(s);
		cout << "请输入开销(0结束):";
	}
	cout << "完善开销成功" << endl;
	system("pause");
}

void FinalContest::displayDS()
{
	cout << endl << endl;
	displayTopTensinger();
	cout << "主持人信息" << endl;
	for (int i = 0;i < 2;i++)
	{
		cout << "第" << i + 1 << "位主持人姓名:" << Presenter[i].getName() << endl;
		cout << "第" << i + 1 << "位主持人性别:" << Presenter[i].getSex() << endl;
		cout << "第" << i + 1 << "位主持人年龄:" << Presenter[i].getAge() << endl;
		cout << "第" << i + 1 << "位主持人学号:" << Presenter[i].getStudent_id() << endl;
		cout << "第" << i + 1 << "位主持人学院:" << Presenter[i].getCollege() << endl << endl;
	}
	unsigned  len = department.size();
	for (unsigned  i = 0;i < len;i++)
	{
		cout << department[i] << endl;
	}
	len = spend.size();
	for (unsigned  i = 0;i < len;i++)
	{
		cout << spend[i] << endl;
	}
	cout << "观众:" << audience << endl;
	system("pause");
}
