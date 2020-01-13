#include<iostream>
#include<cstdlib> 
#include<iomanip>
#include<ctime>
using namespace std;
const int Size = 10000;
void BubbleSort(int a[],int size);
void Selectsort(int a[], int size);
int main ()
{
	srand(unsigned(time(NULL)));
	int a[Size];
	for(int i=0;i<Size;i++)
		a[i] = rand()%Size;	
	clock_t start = clock();
	//BubbleSort(a,Size);
	Selectsort(a,Size);
	clock_t finish = clock();
	cout<<double(finish - start)<<"ms"<<endl;
	/* 
	for(int i=0;i<Size;i++)
	{
		cout<<a[i]<<" ";
		if((i+1)%10==0)
		cout<<endl;
	}
	*/
}
void BubbleSort(int a[],int size)
{
	bool flag = true;
	for(int i=0;i<size&&flag;i++)
	{
		flag = false;
		for(int j =i;j<size;j++)
		{
			if(a[j]<a[i])
			{
				swap(a[j],a[i]);
				flag = true;
			}
		}
	}
}
void Selectsort(int a[], int size)  
{  
    int i, j, MinIndex;  
    for (i = 0; i < size; i++)  
    {  
        MinIndex = i; //找最小元素的位置  
        for (j = i + 1; j < size; j++)  
            if (a[j] < a[MinIndex])  
            	MinIndex = j;   
        swap(a[i], a[MinIndex]); //将这个元素放到无序区的开头  
    }  
}  
