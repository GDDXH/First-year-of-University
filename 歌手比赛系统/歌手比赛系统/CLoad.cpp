#include "CLoad.h"

int CLoad::Konckout_UI()
{
	int t;
	system("cls");
	cout << " �� ��---------------------------------------------------------- �� ��" << endl;
	cout << "          1�����Ʊ�����Ϣ               2����ʾ������Ϣ               " << endl;
	cout << "          3����ʾͳ������               4����ʾ�ܾ�������             " << endl;
	cout << "          5: ��������                   0�����س�ʼ����               " << endl;
	cout << " �� ��---------------------------------------------------------- �� ��" << endl;
	cout << endl << "���������ѡ��:";
	cin >> t;
	return t;
}

int CLoad::Finalcontest_UI()
{
	int t;
	system("cls");
	cout << " �� ��---------------------------------------------------------- �� ��" << endl;
	cout << "          1�����Ʊ�����Ϣ               2����ʾ������Ϣ               " << endl;
	cout << "          3: ��������                   0��������һ����               " << endl;
	cout << " �� ��---------------------------------------------------------- �� ��" << endl;
	cout << "��������Ĳ���:";
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
	cout << " �� ��---------------------------------------------------------- �� ��" << endl;
	cout << "        1������ѡ������Ϣ           2�����������Ϣ                   " << endl;
	cout << "                                    0: ������һ����                   " << endl;
	cout << " �� ��---------------------------------------------------------- �� ��" << endl;
	cout << "���������ѡ��:";
	cin >> t;
	if (t != 1 && t != 2 && t != 0)
	{
		system("cls");
		system("color 1F");
		cerr << "input error��" << endl;
		abort();
	}
	return t;
}

int CLoad::addInformation_UI()
{
	int t;
	system("cls");
	cout << " �� ��---------------------------------------------------------- �� ��" << endl;
	cout << "          1: ���Ʊ�����Ϣ                   2��������������Ϣ         " << endl;
	cout << "          3�����Ʋ��벿����Ϣ               4: ���ƿ���               " << endl;
	cout << "          5�����ƹ�����                     0�����س�ʼ����           " << endl;
	cout << " �� ��---------------------------------------------------------- �� ��" << endl;
	cout << "���������ѡ��:";
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
