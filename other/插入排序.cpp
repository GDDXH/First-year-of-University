/*
* 插入排序:	直接插入排序
*   		折半（二分）插入排序
*    		希尔插入排序	
*直接插入排序的时间复杂度为O(n2),空间复杂度O(1),稳定排序 
*这里介绍三种直接插入排序 (方法相同,只是代码简洁度不同)
* 其中 第三种代码最简洁 (类似冒泡)  第二种直接插入排序最快 
*
*第四种为二分插入排序 , 效率一般般
* 
*第五种与第六种为希尔排序,效率与快排相同
*第五种按定义编写
*第六种:进行下改进和优化，以第二次排序为例，原来是每次从1A到1E，从2A到2E，可以改成从1B开始，
先和1A比较，然后取2B与2A比较，再取1C与前面自己组内的数据比较…….使代码更为简洁 
*/
#include<iostream>
#include<cstdlib> 
#include<iomanip>
#include<ctime>
using namespace std;
const int Size = 100000;
void InsertSort1(int a[],int size);
void InsertSort2(int a[],int size);
void InsertSort3(int a[],int size);
void BinaryInsertSort(int a[],int size); 
void ShellSort1(int a[],int size);
void ShellSort2(int a[],int size);
int main()
{
	srand(unsigned(time(NULL)));
	int a[Size];
	int count = 10;
	while(count--)
	{
		for(int i=0;i<Size;i++)
		a[i] = rand()%Size;	
		clock_t start = clock();
		//BinaryInsertSort(a,Size);
		//InsertSort2(a,Size);
		ShellSort2(a,Size);
		clock_t finish = clock();
		cout<<double(finish - start)<<"ms"<<endl;
	}	
	/*
	for(int i=0;i<Size;i++)
	{
		cout<<setw(4)<<a[i];
		if((i+1)%20==0)
			cout<<endl;  
	}
	*/
	
} 
void InsertSort1(int a[],int size) 
{
	int i , j , k;
	for(i=1;i<size;i++)
	{
		
		for(j= i-1;j>=0;j--)
			if(a[i]>a[j])
				break;
		if(j!=i-1)
		{
			int temp = a[i];
			for(k=i-1;k>j;k--)
			 	a[k+1] = a[k]; 
			a[k+1] = temp;//此时 j==k 
		}
	} 	
}
void InsertSort2(int a[],int size)
{
	int i,j;
	for(i=1;i<size;i++)
		if(a[i]<a[i-1])
		{
			int key = a[i];
			for(j=i-1;j>=0&&a[j]>key;j--)
			{
				a[j+1] = a[j];
			}
			a[j+1] = key;
		}
}
void InsertSort3(int a[],int size)
{
	int i,j;
	for(i=1;i<size;i++)
		for(j=i-1;j>=0&&a[j]>a[j+1];j--)
			swap(a[j],a[j+1]);
}
void BinaryInsertSort(int a[],int size)
{
	
	int i,j;
	for(i=1;i<size;i++)
	{
		if(a[i]<a[i-1])
		{
			int key= a[i];
			int low = 1, high = i-1;
        	while (low <= high)
			{
            	int	mid = (low+high)/2;
           	 	if(a[mid] > key)
               		high = mid-1;
            	else
                	low = mid+1;
        	}
			for(j=i-1;j>=high;j--)
			{
				a[j+1] = a[j];
			}
			a[j+1] = key;
		}
	}	
}
void ShellSort1(int a[],int size)
{
	int i, j, k, key, gap;  
    for (gap = size / 2; gap > 0; gap /= 2) //步长  
        for (i = 0; i < gap; i++)        //直接插入排序        
            for (j = i + gap; j < size; j += gap)   
                if (a[j] < a[j - gap])  
                {  
                	key = a[j];
                	for(k=j-gap;k>=0&&a[k]>key;k-= gap)
                        a[k + gap] = a[k];  
                    a[k + gap] = key;  
                }  
  
}
void ShellSort2(int a[], int size)  
{  
    int i, k , gap;  
    for (gap = size / 2; gap > 0; gap /= 2)  
        for (i = gap; i < size; i++)//从数组第gap个元素开始  
            if (a[i] < a[i - gap])//每个元素与自己组内的数据进行直接插入排序  
            {  
                int key = a[i]; 
				for(k=i-gap;k>=0&&a[k]>key;k-=gap)
				{
				    a[k + gap] = a[k];  	
				} 
                a[k + gap] = key;  
            }  
}  
