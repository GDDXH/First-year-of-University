#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
int main()
{
	int i,j,m,n;
	while(scanf("%d%d",&n,&m))
	{
		if(n==0&&m==0)
		{
			break;
		}
	   for (j=(int)sqrt((double)(2*m));j>=1;j--)  
        {  
            i = (2*m/j+1-j)/2;  
            if (m == (2*i+j-1)*j/2)  
            printf("[%d,%d]\n",i,i+j-1);  
        }  
        printf("\n");  
	}
	return 0;
}
