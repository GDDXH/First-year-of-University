#include "contest.h"

Contest::Contest() :Konckout(), FinalContest(), C_basis(), Player(),CLoad()
{
	host = "δ����";
	sponsor = "δ����";
}

void Contest::inputKSinger()
{
	string s;
	fstream infile;
	/*
	cout << "�������ļ���:";
	cin >> s;
	infile.open(s+".dat");
	*/
	infile.open("ѡ�������.dat");
	if (!infile)
	{
		system("cls");
		system("color 1F");
		cerr << "Error:�޷����ļ�,�������!!!" << endl;
		abort();
	}
	string name, student_ID, song, sex, college;//����,ѧ��,��������,�Ա�,����ѧԺ
	int number, age, sum,rank;//���,����,�ܷ�,����
	double  average;//ƽ����

	while (infile >> name >> number >> student_ID >> song >> sex >> age >> college >> sum >> average >> rank)
	{
		Singer t(name, number, student_ID, song, sex, age, college, sum, average, rank);
		player_infomation.push_back(t);
	}
	inputPlayerNumber(player_infomation.size());
	cout << "�������ݳɹ�" << endl;
	Sleep(300);
}

void Contest::inputFSinger()
{
	string s;
	fstream infile;
	/*
	cout << "�������ļ���:";
	cin >> s;
	infile.open(s+".dat");
	*/
	infile.open("�ܾ������.dat");
	if (!infile)
	{
		system("cls");
		system("color 1F");
		cerr << "Error:�޷����ļ�,�������!!!" << endl;
		abort();
	}
	string name, student_ID, song, sex, college;//����,ѧ��,��������,�Ա�,����ѧԺ
	int number, age, sum, rank;//���,����,�ܷ�,����
	double  average;//ƽ����

	while (infile >> name >> number >> student_ID >> song >> sex >> age >> college >> sum >> average >> rank)
	{
		Singer t(name, number, student_ID, song, sex, age, college, sum, average, rank);
		player_infomation.push_back(t);
	}
	cout << "�������ݳɹ�" << endl;
	Sleep(300);
}


void Contest::add_information()
{
	string s;
	cout << "�������������:";
	cin >> s;
	inputName(s);
	cout << "���������ʱ��:";
	cin >> s;
	inputWhen(s);
	cout << "����������ص�:";
	cin >> s;
	inputWhere(s);
	cout << "������������췽:";
	cin >> s;
	inputHost(s);
	cout << "���������������:";
	cin >> s;
	inputSponsor(s);
	cout << "���Ʊ�����Ϣ�ɹ�" << endl;
	cout << "\n��ʾ:�����������";
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
	cout << "�������ƣ�" << setw(20) << name << endl
		<< "����ʱ�䣺" << setw(20) << when << endl
		<< "�����ص㣺" << setw(20) << where << endl
		<< "�������췽��" << setw(20) << host << endl
		<< "���������̣�" << setw(20) << sponsor << endl;
	cout << "\n��ʾ:�����������";
	_getch();
}

void Contest::saveKData()
{
	string s;
	fstream outfile;
	/*
	cout << "�������ļ���(���ڱ���ѡ������Ϣ):";
	cin >> s;
	outfile.open(s + ".dat");
	*/
	outfile.open("ѡ������Ϣ.dat");
	if (!outfile)
	{
		system("cls");
		system("color 1F");
		cerr << "Error:�޷����ļ�,�������!!!" << endl;
		abort();
	}
	outfile << "��������:" << setw(30) << name << endl
		<< "����ʱ��:" << setw(30) << when << endl
		<< "�����ص�:" << setw(30) << where << endl
		<< "���췽:" << setw(30) << host << endl
		<< "������:" << setw(30) << sponsor << endl;
	outfile << setw(30) << "ѡ��������ͳ��" << endl << endl;
	outfile << setw(5) << "��������:" << getPlayerNumber()<< endl;
	outfile << "��ѧԺ�������" << endl << endl;
	for (map<string, int>::iterator it = CollegeStatistics.begin();it != CollegeStatistics.end();it++)
	{
		outfile << setw(10) << it->first << ":" << setw(2) << it->second << endl;
	}
	outfile << "������β������" << endl << endl;
	for (map<int, int>::iterator it = AgeStatistics.begin();it != AgeStatistics.end();it++)
	{
		outfile << "����" << setw(5) << it->first << "" << ":" << setw(2) << it->second << endl;
	}
	outfile << "��Ů�������" << endl << endl;
	for (map<string, int>::iterator it = SexStatistics.begin();it != SexStatistics.end();it++)
	{
		outfile << setw(10) << it->first << ":" << setw(2) << it->second << endl;
	}
	outfile.close();
	cout << "����ѡ������Ϣ�ɹ���"<<endl;
	system("pause");



	/*
	cout << "�������ļ������������ѡ��������:";
	cin >> s;
	outfile.open(s + ".dat");
	*/
	outfile.open("�ܾ�������.dat");
	if (!outfile)
	{
		system("cls");
		system("color 1F");
		cerr << "Error:�޷����ļ�,�������!!!" << endl;
		abort();
	}
	for (int i = 0;i < 20;i++)
	{
		string name, student_ID, song, sex, college;//����,ѧ��,��������,�Ա�,����ѧԺ
		int number,age;//���,����,�ܷ�,����
		name = Fsinger[i].getName();
		student_ID = Fsinger[i].getStudent_id();
		song = Fsinger[i].getSong();
		sex = Fsinger[i].getSex();
		college = Fsinger[i].getCollege();
		number = Fsinger[i].getNumber();
		age = Fsinger[i].getAge();
		outfile << name << " " << number << " " << student_ID << " " << song << " " << sex << " " << age << " " << college << endl;
	}
	cout << "�����ܾ���������Ϣ�ɹ���" << endl;
	system("pause");
}

void Contest::saveFData()
{
	string s;
	fstream outfile;
	int len;
	/*
	cout << "�������ļ���(���ڱ���ѡ������Ϣ):";
	cin >> s;
	outfile.open(s + ".dat");
	*/
	outfile.open("�ܾ�����Ϣ.dat");
	if (!outfile)
	{
		system("cls");
		system("color 1F");
		cerr << "Error:�޷����ļ�,�������!!!" << endl;
		abort();
	}
	outfile << "��������:" << setw(30) << name << endl
		<< "����ʱ��:" << setw(30) << when << endl
		<< "�����ص�:" << setw(30) << where << endl
		<< "���췽:" << setw(30) << host << endl
		<< "������:" << setw(30) << sponsor << endl << endl;;
	for (int i = 0;i < 2;i++)
	{
		outfile << "��" << i+1 << "λ����������:" << setw(20) << Presenter[i].getName() << endl;
		outfile << "��" << i+1 << "λ�������Ա�:" << setw(20) << Presenter[i].getSex() << endl;
		outfile << "��" << i+1 << "λ����������:" << setw(20) << Presenter[i].getAge() << endl;
		outfile << "��" << i+1 << "λ������ѧ��:" << setw(20) << Presenter[i].getStudent_id() << endl;
		outfile << "��" << i+1 << "λ������ѧԺ:" << setw(20) << Presenter[i].getCollege() << endl;
	}

	outfile << endl << setw(40) << "���λ���벿��" << endl;
	len = department.size();
	for (int i = 0;i < len;i++)
	{
		outfile << setw(10) << department[i] << endl; 
	}

	outfile << endl << setw(40) << "���λ����" << endl;
	len = spend.size();
	for (int i = 0;i < len;i++)
	{
		outfile << setw(40) << spend[i] << endl;
	}
	outfile << endl << "�ܾ�������:" << audience << endl;
	outfile.close();
	cout << "�����ܾ�����Ϣ�ɹ���" << endl;
	system("pause");


	/*
	cout << "�������ļ������������ѡ��������:";
	cin >> s;
	outfile.open(s + ".dat");
	*/
	outfile.open("ʮ�Ѹ�������.dat");
	if (!outfile)
	{
		system("cls");
		system("color 1F");
		cerr << "Error:�޷����ļ�,�������!!!" << endl;
		abort();
	}
	for (int i = 0;i < 10;i++)
	{
		string name, student_ID, song, sex, college;//����,ѧ��,��������,�Ա�,����ѧԺ
		int number, age,rank;//���,����,����
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
	cout << "����ʮ�Ѹ���������Ϣ�ɹ���" << endl;
	system("pause");
}


