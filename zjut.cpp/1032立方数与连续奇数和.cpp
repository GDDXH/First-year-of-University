#include<iostream>//���÷��˹����,���Եõ���n�����ĵ�һ����ǣ�n^2-n+1,�������о���n��
#include<cstdio>
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int First_item=n*n-n+1;
		printf("%d",First_item);
		for(int i=1;i<n;i++)
		{
			printf("+%d",First_item+2*i);
		}
		printf("\n");
	}
	return 0;
	
 } 
