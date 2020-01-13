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
	int i,m,n;
	bool flag;
	/*for(i=100,j=1;i<1000;i++)
	{
		int a,b,c;
		a=i/100;
		b=(i/10)%10;
		c=i%10;
		if(i==a*a*a+b*b*b+c*c*c)
		{
			cout<<i<<endl; 
		}
	}*/
//Ë®ÏÉ»¨Êý£º 153£¬370£¬371£¬407
	while(~scanf("%d%d",&m,&n))
	{
		flag=false;
		for(i=m;i<=n;i++)
		{
			if(i==153||i==370||i==371||i==407)
			{
				if(flag)
                    printf(" ");
                printf("%d",i);
                flag=true;
			}
		}
		 if(flag==0)
            printf("no\n");
        else
            printf("\n");
	}	
	return 0;
}
