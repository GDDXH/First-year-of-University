#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n1,n2,n3;
		scanf("%d %d %d",&n1,&n2,&n3);
		if(n1+n2==n3)
			printf("%d+%d=%d\n",n1,n2,n3);
		else if(n1-n2==n3)
			printf("%d-%d=%d\n",n1,n2,n3);
		else if(n2-n1==n3)
			printf("%d-%d=%d\n",n2,n1,n3);
		else if(n1*n2==n3)
			printf("%d*%d=%d\n",n1,n2,n3);
		else if(n1/n2==n3)
			printf("%d/%d=%d\n",n1,n2,n3);
		else if(n2/n1==n3)
			printf("%d/%d=%d\n",n2,n1,n3);
		else 
			printf("None\n");
	}
	return 0;
}



