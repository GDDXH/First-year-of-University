#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct data
{
	string name;
	int    score[5];
	int average;	
}num[1000];
int  rule(data a,data b)
{
	return a.average>b.average;
}
int main()
{
	int i=0,j;
	while(cin>>num[i].name)
	{
		num[i].average=0;
		for(j=0;j<5;j++)
		{
			cin>>num[i].score[j];
			num[i].average+=num[i].score[j];
		}
		i++;
	}
	sort(num,num+i,rule);
	for(i=0;num[i].average>=305;i++)
	{
		cout<<i+1<<" "<<num[i].name<<endl;
	}
}
