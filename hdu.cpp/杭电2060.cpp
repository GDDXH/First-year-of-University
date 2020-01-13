#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<string>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;
int main()
{
	int amout,billiard,score1,score2,i,j;
	cin>>amout;
	while(amout--)	
	{
		bool flag=false;
		cin>>billiard>>score1>>score2;
		if(billiard>6)
		{
			if(8*(billiard-6)+27+score1>=score2)	
			flag=true; 
		}
		else
		{
			for(i=7,j=billiard;j>0;j--,i--)
			{
				score1+=i;
			}
			if(score1>=score2) 
				flag=true; 
		}
		if(flag)
		cout<<"Yes\n";
		else
		cout<<"No\n"; 
	}
	return 0;;
}
