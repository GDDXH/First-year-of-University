#include "Load.h"
string Load::password = "0";//��̬���������ʼ��
void Load::initialization()//��ʼ������
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

void Load::inputPassword(string t)//�޸ĺ���,�޸ĵ�¼����
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
	system("color 0F");//���ñ���Ϊ��ɫ,����Ϊ����ɫ
	initialization();//��ʼ����,��ʼ��password
	string s;
	int t;
	cout << "�� ��----------------------------------------------------------- �� ��" << endl;
	cout << "                       ���ֱ���ϵͳ��¼����                           " << endl << endl;
	cout << "        1:��¼            2:��¼���޸�����          0:�˳�            " << endl;
	cout << "�� ��----------------------------------------------------------- �� ��" << endl;
	cout << "���������ѡ��:";
	cin >> t;
	if (t == 0)//�����������˳�����
		exit(0);
	else if (t == 1)
	{
		cout << " ����������(����0�˳�):" << endl;
		while (1)
		{
			cin >> s;
			if (s == "0")
				exit(1);
			if (s == password)
			{
				//cout<<"��¼�ɹ�"
				break;
			}
			else
			{
				cout << "�������,����������(����0�˳�):" << endl;
			}
		}
	}
	else if (t == 2)
	{
		cout << " ������ԭ����(����0�˳�):" << endl;
		while (1)
		{
			cin >> s;
			if (s == "0")
				exit(1);
			if (s == password)
			{
				//cout<<"��¼�ɹ�"

				break;
			}
			else
			{
				cout << "�������,����������(����0�˳�):" << endl;
			}
		}
		cout << "������������:";//���������ԭ����Ҳû�й�ϵ
		cin >> s;
		inputPassword(s);
		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		system("cls");
		system("color 1F");
		cerr << "�������,����Ĭ�Ͻ���" << endl;
		abort();
	}
	Sleep(500);
	system("cls");
}

int Load::choose_UI()//ѡ�����
{
	system("cls");
	int t;
	cout << " �� ��---------------------------------------------------------- �� ��" << endl;
	cout << "                       ���ֱ���ϵͳ��¼����                           " << endl << endl;
	cout << "          1:ѡ����Ϣ����         2:������Ϣ����       0:�˳�����      " << endl;
	cout << " �� ��---------------------------------------------------------- �� ��" << endl << endl;
	cout << "���������ѡ��: ";
	cin >> t;
	if (t == 0)//�˳�����
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
