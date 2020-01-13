#include "contest.h"

Contest::Contest() :Konckout(), FinalContest(), C_basis(), Player(),CLoad()
{
	host = "未完善";
	sponsor = "未完善";
}

void Contest::inputKSinger()
{
	string s;
	fstream infile;
	/*
	cout << "请输入文件名:";
	cin >> s;
	infile.open(s+".dat");
	*/
	infile.open("选拔赛结果.dat");
	if (!infile)
	{
		system("cls");
		system("color 1F");
		cerr << "Error:无法打开文件,程序出错!!!" << endl;
		abort();
	}
	string name, student_ID, song, sex, college;//姓名,学号,参赛歌曲,性别,所属学院
	int number, age, sum,rank;//编号,年龄,总分,排名
	double  average;//平均分

	while (infile >> name >> number >> student_ID >> song >> sex >> age >> college >> sum >> average >> rank)
	{
		Singer t(name, number, student_ID, song, sex, age, college, sum, average, rank);
		player_infomation.push_back(t);
	}
	inputPlayerNumber(player_infomation.size());
	cout << "读入数据成功" << endl;
	Sleep(300);
}

void Contest::inputFSinger()
{
	string s;
	fstream infile;
	/*
	cout << "请输入文件名:";
	cin >> s;
	infile.open(s+".dat");
	*/
	infile.open("总决赛结果.dat");
	if (!infile)
	{
		system("cls");
		system("color 1F");
		cerr << "Error:无法打开文件,程序出错!!!" << endl;
		abort();
	}
	string name, student_ID, song, sex, college;//姓名,学号,参赛歌曲,性别,所属学院
	int number, age, sum, rank;//编号,年龄,总分,排名
	double  average;//平均分

	while (infile >> name >> number >> student_ID >> song >> sex >> age >> college >> sum >> average >> rank)
	{
		Singer t(name, number, student_ID, song, sex, age, college, sum, average, rank);
		player_infomation.push_back(t);
	}
	cout << "读入数据成功" << endl;
	Sleep(300);
}


void Contest::add_information()
{
	string s;
	cout << "请输入比赛名称:";
	cin >> s;
	inputName(s);
	cout << "请输入比赛时间:";
	cin >> s;
	inputWhen(s);
	cout << "请输入比赛地点:";
	cin >> s;
	inputWhere(s);
	cout << "请输入比赛主办方:";
	cin >> s;
	inputHost(s);
	cout << "请输入比赛赞助商:";
	cin >> s;
	inputSponsor(s);
	cout << "完善比赛信息成功" << endl;
	cout << "\n提示:按任意键返回";
	_getch();
}
string Contest::getHost()const
{
	return host;
}

string Contest::getSponsor()const
{
	return sponsor;
}
void Contest::inputHost(string h)
{
	host = h;
}

void Contest::inputSponsor(string s)
{
	sponsor = s;
}

void Contest::display()
{	
	system("cls");
	cout << "比赛名称：" << setw(20) << name << endl
		<< "比赛时间：" << setw(20) << when << endl
		<< "比赛地点：" << setw(20) << where << endl
		<< "比赛主办方：" << setw(20) << host << endl
		<< "比赛赞助商：" << setw(20) << sponsor << endl;
	cout << "\n提示:按任意键返回";
	_getch();
}

void Contest::saveKData()
{
	string s;
	fstream outfile;
	/*
	cout << "请输入文件名(用于保存选拔赛信息):";
	cin >> s;
	outfile.open(s + ".dat");
	*/
	outfile.open("选拔赛信息.dat");
	if (!outfile)
	{
		system("cls");
		system("color 1F");
		cerr << "Error:无法打开文件,程序出错!!!" << endl;
		abort();
	}
	outfile << "比赛名称:" << setw(30) << name << endl
		<< "比赛时间:" << setw(30) << when << endl
		<< "比赛地点:" << setw(30) << where << endl
		<< "主办方:" << setw(30) << host << endl
		<< "赞助商:" << setw(30) << sponsor << endl;
	outfile << setw(30) << "选拔赛数据统计" << endl << endl;
	outfile << setw(5) << "比赛人数:" << getPlayerNumber()<< endl;
	outfile << "各学院参赛情况" << endl << endl;
	for (map<string, int>::iterator it = CollegeStatistics.begin();it != CollegeStatistics.end();it++)
	{
		outfile << setw(10) << it->first << ":" << setw(2) << it->second << endl;
	}
	outfile << "各年龄段参赛情况" << endl << endl;
	for (map<int, int>::iterator it = AgeStatistics.begin();it != AgeStatistics.end();it++)
	{
		outfile << "年龄" << setw(5) << it->first << "" << ":" << setw(2) << it->second << endl;
	}
	outfile << "男女参赛情况" << endl << endl;
	for (map<string, int>::iterator it = SexStatistics.begin();it != SexStatistics.end();it++)
	{
		outfile << setw(10) << it->first << ":" << setw(2) << it->second << endl;
	}
	outfile.close();
	cout << "保存选拔赛信息成功！"<<endl;
	system("pause");



	/*
	cout << "请输入文件名（保存决赛选手名单）:";
	cin >> s;
	outfile.open(s + ".dat");
	*/
	outfile.open("总决赛名单.dat");
	if (!outfile)
	{
		system("cls");
		system("color 1F");
		cerr << "Error:无法打开文件,程序出错!!!" << endl;
		abort();
	}
	for (int i = 0;i < 20;i++)
	{
		string name, student_ID, song, sex, college;//姓名,学号,参赛歌曲,性别,所属学院
		int number,age;//编号,年龄,总分,排名
		name = Fsinger[i].getName();
		student_ID = Fsinger[i].getStudent_id();
		song = Fsinger[i].getSong();
		sex = Fsinger[i].getSex();
		college = Fsinger[i].getCollege();
		number = Fsinger[i].getNumber();
		age = Fsinger[i].getAge();
		outfile << name << " " << number << " " << student_ID << " " << song << " " << sex << " " << age << " " << college << endl;
	}
	cout << "保存总决赛名单信息成功！" << endl;
	system("pause");
}

void Contest::saveFData()
{
	string s;
	fstream outfile;
	int len;
	/*
	cout << "请输入文件名(用于保存选拔赛信息):";
	cin >> s;
	outfile.open(s + ".dat");
	*/
	outfile.open("总决赛信息.dat");
	if (!outfile)
	{
		system("cls");
		system("color 1F");
		cerr << "Error:无法打开文件,程序出错!!!" << endl;
		abort();
	}
	outfile << "比赛名称:" << setw(30) << name << endl
		<< "比赛时间:" << setw(30) << when << endl
		<< "比赛地点:" << setw(30) << where << endl
		<< "主办方:" << setw(30) << host << endl
		<< "赞助商:" << setw(30) << sponsor << endl << endl;;
	for (int i = 0;i < 2;i++)
	{
		outfile << "第" << i+1 << "位主持人姓名:" << setw(20) << Presenter[i].getName() << endl;
		outfile << "第" << i+1 << "位主持人性别:" << setw(20) << Presenter[i].getSex() << endl;
		outfile << "第" << i+1 << "位主持人年龄:" << setw(20) << Presenter[i].getAge() << endl;
		outfile << "第" << i+1 << "位主持人学号:" << setw(20) << Presenter[i].getStudent_id() << endl;
		outfile << "第" << i+1 << "位主持人学院:" << setw(20) << Presenter[i].getCollege() << endl;
	}

	outfile << endl << setw(40) << "本次活动参与部门" << endl;
	len = department.size();
	for (int i = 0;i < len;i++)
	{
		outfile << setw(10) << department[i] << endl; 
	}

	outfile << endl << setw(40) << "本次活动开销" << endl;
	len = spend.size();
	for (int i = 0;i < len;i++)
	{
		outfile << setw(40) << spend[i] << endl;
	}
	outfile << endl << "总决赛观众:" << audience << endl;
	outfile.close();
	cout << "保存总决赛信息成功！" << endl;
	system("pause");


	/*
	cout << "请输入文件名（保存决赛选手名单）:";
	cin >> s;
	outfile.open(s + ".dat");
	*/
	outfile.open("十佳歌手名单.dat");
	if (!outfile)
	{
		system("cls");
		system("color 1F");
		cerr << "Error:无法打开文件,程序出错!!!" << endl;
		abort();
	}
	for (int i = 0;i < 10;i++)
	{
		string name, student_ID, song, sex, college;//姓名,学号,参赛歌曲,性别,所属学院
		int number, age,rank;//编号,年龄,排名
		name = TopTensinger[i].getName();
		student_ID = TopTensinger[i].getStudent_id();
		song = TopTensinger[i].getSong();
		sex = TopTensinger[i].getSex();
		college = TopTensinger[i].getCollege();
		number = TopTensinger[i].getNumber();
		age = TopTensinger[i].getAge();
		rank = TopTensinger[i].getRanking();
		outfile << name << " " << number << " " << student_ID << " " << song << " " << sex << " " << age << " " << college << " " << rank << endl;
	}
	cout << "保存十佳歌手名单信息成功！" << endl;
	system("pause");
}


