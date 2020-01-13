/*
* ��������:	ֱ�Ӳ�������
*   		�۰루���֣���������
*    		ϣ����������	
*ֱ�Ӳ��������ʱ�临�Ӷ�ΪO(n2),�ռ临�Ӷ�O(1),�ȶ����� 
*�����������ֱ�Ӳ������� (������ͬ,ֻ�Ǵ�����Ȳ�ͬ)
* ���� �����ִ������� (����ð��)  �ڶ���ֱ�Ӳ���������� 
*
*������Ϊ���ֲ������� , Ч��һ���
* 
*�������������Ϊϣ������,Ч���������ͬ
*�����ְ������д
*������:�����¸Ľ����Ż����Եڶ�������Ϊ����ԭ����ÿ�δ�1A��1E����2A��2E�����Ըĳɴ�1B��ʼ��
�Ⱥ�1A�Ƚϣ�Ȼ��ȡ2B��2A�Ƚϣ���ȡ1C��ǰ���Լ����ڵ����ݱȽϡ���.ʹ�����Ϊ��� 
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
			a[k+1] = temp;//��ʱ j==k 
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
    for (gap = size / 2; gap > 0; gap /= 2) //����  
        for (i = 0; i < gap; i++)        //ֱ�Ӳ�������        
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
        for (i = gap; i < size; i++)//�������gap��Ԫ�ؿ�ʼ  
            if (a[i] < a[i - gap])//ÿ��Ԫ�����Լ����ڵ����ݽ���ֱ�Ӳ�������  
            {  
                int key = a[i]; 
				for(k=i-gap;k>=0&&a[k]>key;k-=gap)
				{
				    a[k + gap] = a[k];  	
				} 
                a[k + gap] = key;  
            }  
}  
