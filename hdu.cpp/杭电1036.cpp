#include<iostream>
#include<string> 
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int t,number,result,time;
	double distance;
	string s;
	bool flag;
	cin>>t>>distance;
	while(cin>>number)
	{
		time=0;
		flag=true;
		for(int i=0;i<t;i++)
		{
			cin>>s;
			if(s[0]=='-')
			{
				flag=false;
			}
			time+=(s[0]-48)*3600+(s[2]-48)*600+(s[3]-48)*60+(s[5]-48)*10+s[6]-48;
		}
		if(flag)
		{
			result=time/distance+0.5;//这里算出来了平均每走一千米所需要的时间（s）,这里由于数据的缘故需要四舍五入！ 
			if(result-result/60*60<10) 
            	printf("%3d: %d:0%d min/km\n",number,result/60,result-result/60*60); 
        	else 
            	printf("%3d: %d:%d min/km\n",number,result/60,result-result/60*60); 
		}
		else
			printf("%3d: -\n",number);
	}
} 
