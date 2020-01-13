#include<iostream>
#include<cstdlib>
#include<ctime> 
using namespace std;
const int size = 100; 
void MinHeapFixdown(int a[], int i, int size)  
{  
    int j, temp;  
    temp = a[i];  
    j = 2 * i + 1;  
    while (j < size)  
    {  
        if (j + 1 < size && a[j + 1] < a[j])
            j++;  
        if (a[j] >= temp)  
            break;  
        a[i] = a[j];
        i = j;  
        j = 2 * i + 1;  
    }  
    a[i] = temp;  
}  
void MakeMinHeap(int a[], int size)  
{  
    for (int i = size / 2 - 1; i >= 0; i--)  
        MinHeapFixdown(a, i, size);  
}  
void MinheapsortTodescendarray(int a[], int size)  
{  
    for (int i = size - 1; i >= 1; i--)  
    {  
        swap(a[i], a[0]);  
        MinHeapFixdown(a, 0, i);  
    }  
}  
int main()
{
	srand(time(NULL));
	int a[size];
	for(int i=0;i<size;i++)
	{
		a[i] = rand()%size;
	}
	MakeMinHeap(a,size);
	MinheapsortTodescendarray(a,size);
	for(int i=0;i<size;i++)
	{
		cout<<a[i]<<endl;
	} 	 
}
