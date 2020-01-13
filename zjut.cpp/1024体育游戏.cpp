#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath> 
using namespace std;
struct coordinate
{
	double number,x,y; 
} array[1010];
bool rule(coordinate a,coordinate b)
{
	return a.number<b.number;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i , size , start_x , start_y;
		double distance = 0;
		scanf("%d %d %d",&size,&start_x,&start_y);
		for(i = 0 ; i <size ; i++)
		{
			scanf("%lf %lf %lf",&array[i].number,&array[i].x,&array[i].y);
		}
		sort(array,array+size,rule);
		for(i = 0 ; i < size ; i++)
		{
			distance += sqrt((array[i].x-start_x)*(array[i].x-start_x)+(array[i].y-start_y)*(array[i].y-start_y));
			start_x = array[i].x;
			start_y = array[i].y;
		}
		printf("%.3lf\n",distance);
	}
	return 0;
}
