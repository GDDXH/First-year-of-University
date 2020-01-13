#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int main()
{
	int count=0;
	int size[100];
	int n1,n2,n3,n4;
	while(cin>>n1>>n2>>n3>>n4)
	{	
		if(n1==n3||n2==n4)
		{
			size[count]=0;
			count++;
			continue;
		}
		size[count]=abs((n1-n3)*(n2-n4));	
		count++;
	}
	sort(size,size+count);
	for(int i=0;i<count;i++)
	{
		cout<<size[i]<<endl;
	}
	return 0;
} 
