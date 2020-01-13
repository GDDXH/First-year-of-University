#include<iostream>
#include<cstdio>
using namespace std;
int map[5][5];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
struct node
{
	int x,y,layer;
}step[100];
void print(int i)
{
	if(step[i].layer!=-1)
	{
		print(step[i].layer);
		printf("(%d, %d)\n",step[i].x,step[i].y);
	}
}
void bfs(int a,int b)
{
	int number = 0, maybe = 1,next_x,next_y;
	step[number].x=a;
	step[number].y=b;
	step[number].layer=-1;
	while(number<maybe)
	{
		for(int i=0;i<4;i++)
		{
			next_x = step[number].x + dx[i];
			next_y = step[number].y + dy[i];
			if(next_x>=0&&next_y>=0&&next_y<5&&next_x<5&&!map[next_x][next_y])
			{
				map[next_x][next_y] = 1;
				step[maybe].x = next_x;
				step[maybe].y = next_y;
				step[maybe].layer =  number;
				maybe++;
			}
			if(next_x==4&&next_y==4)
			{
				print(number);
				return ;
			}
		}	
		number++;	
	} 

}
int main()
{
	int i,j;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			scanf("%d",&map[i][j]);
	printf("(0, 0)\n");
	bfs(0,0);
	printf("(4, 4)\n");
	return 0;	 
}
