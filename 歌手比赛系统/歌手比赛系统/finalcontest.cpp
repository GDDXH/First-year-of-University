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
	cout << setw(40) << "ʮ�Ѹ���" << endl << endl;
	cout << "����\t���\tѧ��\t\t�ܷ�\tƽ����\t����" << endl;
	for (int i = 0;i < 10;i++)
	{
		cout << TopTensinger[i];
	}
	cout << "����\tѧ��\t\t��������\t����\t�Ա�\tѧԺ" << endl;
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
		cout << "�������" << i+1 << "λ����������:";
		cin >> s;
		Presenter[i].inputName(s);
		cout << "�������" << i+1 << "λ�������Ա�:";
		cin >> s;
		Presenter[i].inputSex(s);
		cout << "�������" << i+1 << "λ����������:";
		cin >> n;
		Presenter[i].inputAge(n);
		cout << "�������" << i+1 << "λ������ѧ��:";
		cin >> s;
		Presenter[i].inputStudent_id(s);
		cout << "�������" << i+1 << "λ������ѧԺ:";
		cin >> s;
		Presenter[i].inputCollege(s);
		cout << "������Ϣ�ɹ�" << endl << endl;
	}
	system("pause");
}

void FinalContest::inputAudience()//�����������
{
	cout << "�����������:";
	cin >> audience;
	system("pause");
}

int FinalContest::getAudience()//���ʺ��� ����:���ع�������
{
	return audience;
}

void FinalContest::inputDepartment()
{
	string s;
	cout << "��������벿��(0����):";
	while (cin >> s)
	{	
		if (s == "0")
		{
			break;
		}
		this->department.push_back(s);
		cout << "��������벿��(0����):";
	}
	cout << "���Ʋ��벿�ųɹ�" << endl;
	system("pause");
}

void FinalContest::inputSpend()
{
	string s;
	cout << "�����뿪��(0����):";
	while (cin >> s)
	{
		if (s == "0")
		{
			break;
		}
		this->spend.push_back(s);
		cout << "�����뿪��(0����):";
	}
	cout << "���ƿ����ɹ�" << endl;
	system("pause");
}

void FinalContest::displayDS()
{
	cout << endl << endl;
	displayTopTensinger();
	cout << "��������Ϣ" << endl;
	for (int i = 0;i < 2;i++)
	{
		cout << "��" << i + 1 << "λ����������:" << Presenter[i].getName() << endl;
		cout << "��" << i + 1 << "λ�������Ա�:" << Presenter[i].getSex() << endl;
		cout << "��" << i + 1 << "λ����������:" << Presenter[i].getAge() << endl;
		cout << "��" << i + 1 << "λ������ѧ��:" << Presenter[i].getStudent_id() << endl;
		cout << "��" << i + 1 << "λ������ѧԺ:" << Presenter[i].getCollege() << endl << endl;
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
	cout << "����:" << audience << endl;
	system("pause");
}
