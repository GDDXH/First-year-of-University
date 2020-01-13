#include "student.h"
Student::Student():Person()//构造函数
{
	student_id = "未完善";
	college = "未完善";
}

string Student::getStudent_id()const
{
	return student_id;
}

string Student::getCollege()const
{
	return college;
}

void Student::inputCollege(string c)
{
	college = c;
}

void Student::display()
{
	cout << setw(5)<<name << "\t" << setw(12)<<student_id << "\t" << setw(2)<<age << "\t" << setw(6)<<sex << "\t" << setw(4)<<college << endl;
}

void Student::inputStudent_id(string id) 
{
	student_id = id;
}

