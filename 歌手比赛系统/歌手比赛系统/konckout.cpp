#include "konckout.h"

Konckout::Konckout() :C_basis(),Player()
{
	CollegeStatistics.clear();
	AgeStatistics.clear();
	SexStatistics.clear();
}



void Konckout::statistics()//ͳ������
{
	cout << "����ͳ������" << endl;
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
	cout << "ͳ�����ݳɹ�" << endl;
	Sleep(500);
}

void Konckout::statisticsDisplay()//��ʾͳ������
{
	system("cls");
	cout << setw(30) << "ѡ��������ͳ��" << endl << endl;
	cout << setw(5) << "��������:" << getPlayerNumber() << endl;
	cout << "��ѧԺ�������" << endl << endl;
	for (map<string, int>::iterator it = CollegeStatistics.begin();it != CollegeStatistics.end();it++)
	{
		cout << setw(10) << it->first << ":" << setw(2) << it->second << endl;
	}
	cout << endl;
	cout << "������β������" << endl << endl;
	for (map<int, int>::iterator it = AgeStatistics.begin();it != AgeStatistics.end();it++)
	{
		cout << "����" << setw(5) << it->first << "" << ":" << setw(2) << it->second << endl;
	}
	cout << endl;
	cout << "��Ů�������" << endl << endl;
	for (map<string, int>::iterator it = SexStatistics.begin();it != SexStatistics.end();it++)
	{
		cout << setw(10) << it->first << ":" << setw(2) << it->second << endl;
	}
	cout << "\n��ʾ:�����������";
	_getch();
}

void Konckout::finalcontestList()
{
	system("cls");
	cout << setw(40) << "��Χ�ܾ�������" << endl << endl;;
	cout << setw(15) << "����" << setw(15) << "���" << setw(20) << "ѧ��" << endl;
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
