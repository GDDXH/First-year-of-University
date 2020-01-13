#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	const int size=3;
	char a[size],temp;
	int i,j;
	while(scanf("%s",a)!=EOF)
	{
		bool flag=1;
		for(i=0;i<size-1&&flag;i++)
		{
			flag=0;
			for(j=i+1;j<size;j++)
			{
				if(a[j]<a[i])
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
					flag=1;
				}
			}  
		}
       printf("%c %c %c\n",a[0],a[1],a[2]);
	}
	return 0;	 
}
