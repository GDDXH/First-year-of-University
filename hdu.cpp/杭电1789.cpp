#include<iostream>
#include<algorithm> 
using namespace std;

struct node
{
	int deadline,score;
	bool flag;
}Ignatius[1010];
void read_data(node Ignatius[1010],int N); 
bool rule(node a,node b);
int main()
{
	int T,N;
	scanf("%d",&T);
	while(T--)
	{
		int i,j,min,day=0,reduce_score=0;
		
		scanf("%d",&N);
		
		read_data(Ignatius,N);
		
		sort(Ignatius,Ignatius+N,rule);
		
		for(i=0;i<N;i++)
		{
			if(day<Ignatius[i].deadline)
			{
				day++;
				Ignatius[i].flag = true;
			}
			else
			{
				int min=i;
                for(j=0;j<i;j++)
                {   //一定要保证两个条件同时满足 特别是找的要是被标记的
                    if(Ignatius[min].score>Ignatius[j].score&&Ignatius[j].flag) 
					min = j;
                }
                if(min!=i)//当前作业的被罚分数是否大于前面的分数
                {
                    Ignatius[i].flag = true;
                    Ignatius[min].flag = false;
                }
			}
		}
		for(i=0;i<N;i++)
		{
			if(!Ignatius[i].flag)
			reduce_score+=Ignatius[i].score;
		}
		printf("%d\n",reduce_score);
	}
	return 0;
}
bool rule(node a,node b)
{
	if(a.deadline!=b.deadline)
		return a.deadline<b.deadline;
	return a.score>b.score;
	
}
void read_data(node Ignatius[1010],int N)
{
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%d",&Ignatius[i].deadline);
		Ignatius[i].flag=false;
	}
	for(i=0;i<N;i++)
	{
		scanf("%d",&Ignatius[i].score);
	}
	
}

