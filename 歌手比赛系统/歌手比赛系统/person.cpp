#include"person.h"
Person::Person()//���캯��
{
	name = "δ����";
	age = 0;
	sex = "δ����";
}
string Person::getName() const
{
	return name;
}

int Person::getAge() const
{
	return age;
}

string Person::getSex() const
{
	return sex;
}

void Person::inputAge(int a)
{
	age = a;
}

void Person::inputSex(string s)
{
	sex = s;
}

void Person::inputAge()
{
	int a;
	cout << "����������:";
	while (cin >> a)
	{
		if (a > 18 && a < 25)
		{
			age = a;
			cout << "��������ɹ�" << endl;
			break;
		}
		else
		{
			cout << "�������,����������:";
		}
	}
}

void Person::inputSex()
{
	string s;
	cout << "�������Ա�(��->male,Ů->female):";
	while (cin >> s)
	{
		if (s != "male"&&s != "female")
		{
			cout << "�������,����������(��->man,Ů->female):";
			continue;
		}
		sex = s;
		cout << "�����Ա���Ϣ�ɹ�" << endl;
		break;
	}
}

void Person::display()
{
	cout << name << "\t" << sex << "\t" << age << endl;
}

void Person::inputName(string n)
{
	name =n;
}
