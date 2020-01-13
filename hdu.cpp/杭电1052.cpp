#include<iostream>
#include<algorithm>
using namespace std;
int horse_racing(int tian[],int king[],int N);
void read_data(int tian[],int king[],int N);
int main()
{
	int N;

	while(scanf("%d",&N),N)
	{
		int  tian[1010],king[1010],money;

		read_data(tian,king,N);

		sort(tian,tian+N);
		sort(king,king+N);
		
		money = horse_racing(tian,king,N);
		printf("%d\n", money ); 
	}
	return 0;
} 
void read_data(int tian[],int king[],int N)
{
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%d",&tian[i]);
	}
	for(i=0;i<N;i++)
	{
		scanf("%d",&king[i]);
	}
}
int horse_racing(int tian[1010],int king[1010],int N)
{
 	int t_slow=0,k_slow=0,t_quick=N-1,k_quick=N-1,money=0;
 	
 	while(t_slow<=t_quick)
	{
		if(tian[t_slow]>king[k_slow])
		{
			t_slow++;
			k_slow++;
			money+=200;	
		}
		else if(tian[t_slow]<king[k_slow])
		{
			t_slow++;
			k_quick--;
			money-=200;
		}
		else//tian[t_slow]==king[t_slow]	
		{
			if(tian[t_quick]>king[k_quick])
			{
				t_quick--;
				k_quick--;
				money+=200;	
			}
			else if(tian[t_slow]==king[k_quick])
			{
				t_slow++;
				k_quick--;
			}
			else
			{
				t_slow++;
				k_quick--;
				money-=200;
			}
		}
	}
	return money;
}
/*在上面的基础上，可以进一步的优化代码 
int horse_racing(int tian[1010],int king[1010],int N)
{
 	int t_slow=0,k_slow=0,t_quick=N-1,k_quick=N-1,money=0;
 	
 	while(t_slow<=t_quick)
	{
		if(tian[t_slow]>king[k_slow])
		{
			t_slow++;
			k_slow++;
			money+=200;	
		}
		else if(tian[t_slow]<king[k_slow])
		{
			t_slow++;
			k_quick--;
			money-=200;
		}
		else if(tian[t_quick]>king[k_quick])//满足tian[t_slow]==king[t_slow]
		{
			t_quick--;
			k_quick--;
			money+=200;	
		}
		else if(tian[t_slow]==king[k_quick])
		{
			t_slow++;
			k_quick--;
		}
		else
		{
			t_slow++;
			k_quick--;
			money-=200;
		}
	}
	return money;
}*/ 
