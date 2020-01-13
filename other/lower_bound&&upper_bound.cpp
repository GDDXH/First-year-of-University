#include<iostream>
using namespace std;
const int maxn=10;
int a[maxn];
int my_lower_bound(int * a, int maxn, int key)
{
	int low = 0, high = maxn - 1, middle, position = 0;
	while(low < high)
	{
		middle = (high - low)/2 + low;
		if(a[middle] < key)
		{
			low = middle + 1;
			position = low ;
		}
		else
		{
			high = middle;
			position = high; 
		}
	}
	return position;
}
int my_upper_bound(int * a, int maxn, int key)
{
	int low = 0, high = maxn - 1, middle, position = 0;
	while(low < high)
	{
		if(a[middle] > key)
		{
			high = middle - 1 ;
			position = high ;
		}
		else 
		{
			low = middle ;
			position = low ;
		}
	} 
	return position;
}
int lower_bound(int * a, int maxn, int key)
{
	int low = 0, middle , half , len = maxn ;
	while(len > 0)
	{
		half = len >> 1 ;
		middle = low + half ;
		if( a[middle] < key)
		{
			low = middle + 1;
			len = len - half - 1; 
		}
		else
		{
			len = half ;
		}
	 } 
	return low;
}
int upper_bound(int *a ,int maxn ,int key)
{
	int low = 0, len = maxn , middle , half;
	while( len > 0 )
	{
		half = len >> 1;
		middle = low + half;
		if(a[middle]> key)
		{
			len = half;
		}
		else
		{
			low = middle + 1;
			len = len - half - 1;
		}
	 } 
}
int main()
{
	return 0;
 } 
 
