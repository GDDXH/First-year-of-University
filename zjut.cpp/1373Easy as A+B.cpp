#include<iostream>//特地使用一次经典的冒泡排序 
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i,j,size,temp;
		int num[1001];
		cin>>size;
		for(i=1;i<=size;i++)
		{
			cin>>temp;
			num[i]=temp;
		}
		//sort(num+1,num+size+1);
		for(i=1;i<=size-1;i++)//i<size
		{
			bool flag=1;
			for(j=1;j<=size-i;j++)
			{
				if(num[j]>num[j+1])
				{
					temp=num[j];
					num[j]=num[j+1];
					num[j+1]=temp;
					flag=0;
				}
			}
			if(flag)
			break;
		}
		for(i=1;i<=size;i++)
		{
			cout<<num[i];
			if(i!=size)
			{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
