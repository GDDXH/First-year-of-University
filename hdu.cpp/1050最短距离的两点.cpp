#include<iostream>
using namespace std;
struct Point {
	int x,y;
}point[1010];
int main()
{
	int n;
	while(cin>>n&&n)
	{
		int min = 0x3f3f3f3f;
		for(int i=0;i<n;i++)
			cin>>point[i].x>>point[i].y;
		Point ans1,ans2;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				int distance = (point[i].x-point[j].x)*(point[i].x-point[j].x)+(point[i].y-point[j].y)*(point[i].y-point[j].y);
				if(distance<min)
				{
					ans1=point[i];
					ans2=point[j];
					min = distance;
				}
			}
		 }
		 cout<<"("<<ans1.x<<","<<ans1.y<<") ("<<ans2.x<<","<<ans2.y<<")"<<endl;
	}
	return 0;
}
