//类的练习，重载运算符，sort函数的使用 
#include<iostream>
#include<string> 
#include<vector>
#include<algorithm>
using namespace std;
class stu 
{
	public:
		stu(){credit=0;}
		void display();
		void change();
		int input();
		friend bool operator <(const stu &a,const stu &b);
		bool operator >(const stu& b); 
		friend bool comp(const stu &a,const stu &b);
	private:
		string s;
		double score[3];
		double credit; 
};
bool operator <(const stu &a,const stu &b)
{
	return a.credit <b.credit;
}
bool stu::operator >(const stu& b)
{
	return credit > b.credit;
}
bool comp(const stu &a,const stu &b)
{
	return a.credit > b.credit;
}
void stu::change()
{
	if(score[0]>=60)
		credit +=(score[0]-50)*3/100;
	if(score[1]>=60)
		credit +=(score[0]-50)*3/100;
	if(score[2]>=60)
		credit +=(score[0]-50)*34/100;		
}
void stu::display()
{
	cout<<s<<" "
		<<score[0]<<" "
		<<score[1]<<" "
		<<score[2]<<endl;
}
int stu::input()
{
	if(cin>>s>>score[0]>>score[1]>>score[2])	
		return 1;
	else
		return 0;
}
int main()
{
	stu temp;
	vector<stu> data;
	while(temp.input())
	{
		temp.change();
		data.push_back(temp);
	}
	sort(data.begin(),data.end(),comp);
	//reverse(data.begin(),data.end());
	for(int i=0;i<data.size();i++)
		data[i].display();	
} 
