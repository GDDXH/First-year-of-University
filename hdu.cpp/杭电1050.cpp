#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	//�����ȵ��ظ����ô��� 
	int	a[201]; 
	int T,N,i,j,max;
	scanf("%d",&T);
	while(T--)
	{
		int s,t;
		memset(a,0,sizeof(a));
		max=0;
		
		scanf("%d",&N);
		
		for(i=0;i<N;i++)
		{
			scanf("%d %d",&s,&t);
			if(s>t)//s,t�Ĵ�Сһ��Ҫע�� 
			{
				s^=t;
				t^=s;
				s^=t;
			}
			s=(s+1)/2;
			t=(t+1)/2;
			for(j=s;j<=t;j++)
			{
				a[j]++;	
				if(a[j]>max)
					max=a[j];//���ַ��������������ܶ� 
			}
		}
		
		/*for(i=0;i<201;i++)����Ҳ�ܿ� 
		{
			if(a[i]>max)
			max=a[i];
		}*/
		
		//sort(a,a+201);�ɼ������վ���Ҫ���ܶ�ʱ�� 
		
		//	printf("%d\n",a[200]*10);
		printf("%d\n",max*10);
	}
}
