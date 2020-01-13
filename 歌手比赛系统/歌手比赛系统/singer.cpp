#include"singer.h"
Singer::Singer() :Student(),Judge()//构造函数
{
	song = "未完善";
	sum_score = 0;
	average_score = 0;
	ranking = 0;
	flag = false;
}
Singer::Singer(const Singer & temp)://拷贝构造函数
	Student(temp.name, temp.age, temp.sex,temp.student_id,temp.college),Judge(temp.judge)//student类的构造函数
{
	    const node * p = temp.judge;
		song = temp.song;
		number = temp.number;
		sum_score = temp.sum_score;
		average_score = temp.average_score;
		ranking = temp.ranking;
		flag = temp.flag;	
}

Singer::~Singer(){}
void Singer::calculation()//计算总分与平均分
{
	
	for (int i = 1;i < 9;i++)
		sum_score += judge[i].score;
	average_score = sum_score / 8;
	sum_score += judge[0].score + judge[9].score;
}  
void Singer::mark()//评委打分
{
	//int t;
	cout << "PS:请输入 0 -- 100 之间的整数" << endl << endl;
	for (int i = 0;i < 10;i++)
	{
		// 生成随机数,便于检测程序
		judge[i].score = rand() % 20 + 80;
		cout << judge[i].name << "评委的评分：" << judge[i].score << endl;;
		/*
		//手动输入数据
		cin >> t;
		if (t >= 0 && t <= 100)
		{
			judge[i].score = t;
		}
		else
		{
			cout << "输入错误,请重新输入" << endl;
			i--;
		}
		*/
	}
	calculation();
	cout << endl << "总成绩：" << sum_score << "\t平均分：" << average_score << endl << endl;
}
void Singer::input(string na, int n, string stu, string so, string s, int a, string c)
{
	//修改函数,用于文件输入数据时(完善信息),给对象赋值
	name = na;//姓名
	number = n;//编号
	student_id = stu;//学号
	song = so;//参赛歌曲
	sex = s;//性别
	age = a;//年龄
	college = c;//学院
}
void Singer::input(string s,int n)
{	
	//修改函数,用于文件输入数据时(未完善信息),给对象赋值
	name = s;//姓名
	number = n;//编号
}


void Singer::inputRanking(int r)
{
	//修改函数,用于成绩排序后,给选手排名
	ranking = r;

}
void Singer::inputSong(string s)
{
	//修改函数,给选手参赛歌曲赋值
	song = s;
}

void Singer::inputFlag(bool b)
{
	//若选手信息完善,则 flag = true ,else flag = false
	flag = b;
}
int Singer::getNumber()const
{
	//访问函数,返回编号
	return number;
}
int  Singer::getSum_score() const
{
	//访问函数,返回总分
	return sum_score;
}
double Singer::getAverage_score() const
{
	//访问函数,返回平均分
	return average_score;
}
int Singer::getRanking() const
{
	//访问函数,返回排名
	return ranking;
}
string Singer::getSong() const
{
	//访问函数,返回参赛歌曲
	return song;
}

void Singer::display_judge()
{
	// 显示输出函数,输出评委打分信息
	for (int i = 0;i < 10;i++)
	{
		cout << judge[i].name << "评委打分:" << judge[i].score << endl; 
	}
}
void Singer::display()
{
	cout.setf(ios::left);
	//cout << "姓名\t学号\t\t参赛歌曲\t年龄\t性别\t学院" << endl;
	cout << name << "\t" << student_id << "\t" << setw(8) << song << "\t" << age << "\t" << sex << "\t" << college << endl;
}

bool Singer::getFlag() const
{
	// //访问函数,返回flag(若选手信息完善,则 flag = true ,else flag = false)
	return flag;
}

ostream &operator<<(ostream &output, Singer &temp)
{	
	// 重载流运算符,用于输出对象数据
	output.precision(2);
	//cout<< "姓名\t编号\t学号\t总分\t平均分\t名次" << endl;
	output <<setw(4)<<temp.name << "\t" <<setw(2)<< temp.number << "\t"
		<< setw(12) << temp.student_id<<"\t"<<setw(3) << temp.sum_score << "\t"
		<< fixed <<temp.average_score<< "\t第" << temp.ranking << "名" << endl;
	return output;
}

