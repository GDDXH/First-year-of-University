#include<iostream>//第1500个丑数859963392
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<string>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cctype>
using namespace std;
int main()
{/* 简单方法，但速度极慢，需18秒 
	int amout=1,number=2;
	while(amout<1500)
	{
		int temp=number;
		amout_2=amout_3=amout_5=0;
		while(temp%2 == 0)
		{
			temp = temp/2;
		} 
		while(temp%3 == 0)
		{
			temp = temp/3;
		}
		while(temp%5 == 0)
		{
			temp = temp/5; 
		}
		if(temp==1)
		{
			amout++;
		}
		number++;
	}*/ 
	int amout=2,number[2000]={0,1},m2=1,m3=1,m5=1;
	while(amout<=1500)
	{
		number[amout]=min(min(number[m2]*2,number[m3]*3),number[m5]*5);
		if(number[amout]==2*number[m2])m2++;
		if(number[amout]==3*number[m3])m3++;
		if(number[amout]==5*number[m5])m5++;
		amout++;
	}
	cout<<number[1500]<<endl;
}
