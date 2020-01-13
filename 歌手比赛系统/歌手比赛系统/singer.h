#pragma once
#include"student.h"
#include"judge.h"
//歌手类
class Singer:public Student,public Judge
{
public:
	Singer();//构造函数
	Singer(string  na, int n, string stu, string so, string s, int a, string c, int sum, double average, int rank) :
		Student(na, a, s, stu, c), Judge()
	{
		number = n;
		song = so;
		sum_score = sum;
		average_score = average;
		ranking = rank;
		flag = true;
	}
	Singer(const Singer &);//拷贝构造函数
	
	void calculation();//计算平均分
	void mark();//打分
	void input(string ,int,string ,string,string,int,string);//修改函数
	void input(string, int);
	void inputRanking(int);//修改函数,在成绩排序后之后,给选手名次;
	void inputSong(string s);//修改函数，修改参赛歌曲
	void inputFlag(bool);

	int getNumber()const;//访问函数
	int  getSum_score()const;//访问函数
	double getAverage_score()const;//访问函数
	int getRanking()const;//访问函数
	string getSong()const;//访问函数
	bool getFlag()const;//访问函数

	virtual void display();//显示输出函数,输出对象数据
	void display_judge();//显示输出函数,输出评委打分信息

	friend ostream &operator<<(ostream &output, Singer &temp);//重载流插入运算符

	~Singer();//析构函数

private:
	string song;//参赛歌曲
	bool  flag;//选手信息是否完善
	int number;//编号
	int  sum_score;//总分
	double average_score;//平均分
	int ranking;//排名
};

struct list //用于建立链表的结构体
{
	Singer data;
	list *next;
};