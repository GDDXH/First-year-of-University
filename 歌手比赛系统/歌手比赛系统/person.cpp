#include"person.h"
Person::Person()//构造函数
{
	name = "未完善";
	age = 0;
	sex = "未完善";
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
	cout << "请输入年龄:";
	while (cin >> a)
	{
		if (a > 18 && a < 25)
		{
			age = a;
			cout << "完善年龄成功" << endl;
			break;
		}
		else
		{
			cout << "输入错误,请重新输入:";
		}
	}
}

void Person::inputSex()
{
	string s;
	cout << "请输入性别(男->male,女->female):";
	while (cin >> s)
	{
		if (s != "male"&&s != "female")
		{
			cout << "输入错误,请重新输入(男->man,女->female):";
			continue;
		}
		sex = s;
		cout << "完善性别信息成功" << endl;
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
