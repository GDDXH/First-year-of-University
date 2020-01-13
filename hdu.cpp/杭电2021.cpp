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
	int size,i,temp,sum;
	while(scanf("%d",&size)!=EOF,size)
	{
		sum=0;
		for(i=0;i<size;i++)
		{
			scanf("%d",&temp);
			sum += temp / 100;  
            temp %= 100;  
            sum += temp / 50;  
            temp %= 50;  
            sum += temp / 10;  
            temp %= 10;  
            sum += temp / 5;  
            temp %= 5;  
            sum += temp / 2;  
            temp %= 2;  
            sum += temp;  		
		}
		printf("%d\n", sum);  
	}	
	return 0;
}
