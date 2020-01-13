#include<iostream>
using namespace std;
int main()
{
	int x1,y1;//第一个整数对为所给定的点
	int x2,y2;//记录所求的点 
	int m,n;//所有其他的点
	long long int distance=2147483647; 
	cin>>x1>>y1;
	while(cin>>m>>n)
	{
		
		long long int sum=(x1-m)*(x1-m)+(y1-n)*(y1-n);//非常容易超过int范围 
		if(distance>sum)
		{
			distance=sum;
			x2=m;
			y2=n; 
		}
	}
	cout<<x2<<" "<<y2<<endl;
}
