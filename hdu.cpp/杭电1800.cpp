#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cctype>
using namespace std;
int main()
{
	int N,i,max,k,soldier_level[3001];
	while(scanf("%d",&N)!=EOF)
	{	
		for(i=0;i<N;i++)
			scanf("%d",&soldier_level[i]);
			
		sort(soldier_level,soldier_level+N);
		
		for(i=1,max=0,k=1;i<N;i++)
		{
			if	(soldier_level[i-1]==soldier_level[i])
				k++;
			else
			{
				if(k>max)
					max=k;
				k=1;
			}
		} 
		if(k>max)
			max=k;
		printf("%d\n",max) ;
	}
	return 0;
}
