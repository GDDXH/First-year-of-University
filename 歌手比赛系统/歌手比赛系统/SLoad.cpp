#include "SLoad.h"
int SLoad::main_UI()//�����溯��
{
	int t;
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//��������Ϊ��ɫ


	cout << "\t\t*___________________________________________________________*" << endl
		<< "\t\t|                                                          |" << endl
		<< "\t\t|";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//���������ɫ

	cout << "\t\t    ��ӭʹ�ø��ֱ���ϵͳ                   ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);;//��������Ϊ��ɫ
	cout << "|" << endl;
	cout << "\t\t|                                                          |" << endl;
	cout << "\t\t|\tѡ����Ϣ�����˵�:                                  |" << endl
		<< "\t\t|\t1��������Ϣ                   2����ί���          |" << endl
		<< "\t\t|\t3���ɼ�����                   4����ѯϵͳ          |" << endl
		<< "\t\t|\t5��׷��ѡ��                   6���޸�ϵͳ          |" << endl
		<< "\t\t|\t7����ʾȫ��ѡ������           8��ͳ��ϵͳ          |" << endl
		<< "\t\t|\t9���������                   0��������һ����      |" << endl
		<< "\t\t|                                                          |" << endl;
	cout << "\t\t*__________________________________________________________*" << endl
		<< "\t\t                                       PS:���ȶ�������" << endl
		<< "\t\t                                       ��������Ϣ       " << endl
		<< endl << "���������ѡ��:";
	cin>>t;
	return t;
}
void SLoad::statistics_UI()
{
	system("cls");
	cout << " �� ��---------------------------------------------------------- �� ��" << endl;
	cout << "             1�������Ա�                2����������                   " << endl;
	cout << "             3: ����ѧԺ                4: �����ܷ�                   " << endl;
	cout << "             5: ����ƽ����              6: ��������                   " << endl;
	cout << "                                        0: ������һ����               " << endl;
	cout << " �� ��---------------------------------------------------------- �� ��" << endl;
}

void SLoad::creat_UI()
{
	system("cls");
	cout << " �� ��---------------------------------------------------------- �� ��" << endl;
	cout << "             1���ļ�����(��Ϣδ����)    2���ļ�����(��Ϣ������)       " << endl;
	cout << "                                        0: ������һ����               " << endl;
	cout << " �� ��---------------------------------------------------------- �� ��" << endl;
}

void SLoad::seek_UI()
{
	system("cls");
	cout << " �� ��---------------------------------------------------------- �� ��" << endl;
	cout << "             1����������ѯ                  2������Ų�ѯ             " << endl;
	cout << "                                            0: ������һ����           " << endl;
	cout << " �� ��---------------------------------------------------------- �� ��" << endl;
}

void SLoad::modify_UI()
{
	system("cls");
	cout << " �� ��---------------------------------------------------------- �� ��" << endl;
	cout << "             1��ɾ��ѡ��                  2���޸�����                 " << endl;
	cout << "             3���޸��Ա�                  4���޸�����                 " << endl;
	cout << "             5: �޸Ĳ�������              6: �޸�ѧԺ                 " << endl;
	cout << "                                          0��������һ����             " << endl;
	cout << " �� ��---------------------------------------------------------- �� ��" << endl;
}

