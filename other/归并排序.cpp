#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime> 
#include<algorithm> 
using namespace std;
void mergearray(int a[],int first,int mid,int last,int temp[])
{
	int i=first,j=mid+1;
	int m=mid,n=last;
	int k= 0;
	while(i<=m&&j<=n)
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	while(i<=m)
		temp[k++]=a[i++];
	while(j<=n)
		temp[k++]=a[j++];
	for(i=0;i<k;i++)
		a[first+i] =temp[i];
}
void mergesort(int a[],int first,int last,int temp[])
{
	if(first<last)
	{
		int mid = (first+last)/2;
		mergesort(a,first,mid,temp);
		mergesort(a,mid+1,last,temp);
		mergearray(a,first,mid,last,temp);
	}
}
int main()
{
	const int size=10;
	srand(unsigned(time(NULL)));
	int a[size];
	for(int i=0;i<size;i++)
	{
		a[i] =rand()%size;
	}
	clock_t start = clock();

	int *p = new int[size];
	mergesort(a,0,size-1,p);
	for(int i=0;i<size;i++)
	{
		cout<<setw(3)<<a[i];
		if((i+1)%20==0)
			cout<<endl;
	}	
	clock_t finish =clock();
	cout<<double((finish - start))<<"ms"<<endl; 
}

  

