/*
								�����������Ż� 
һ.  ��������Ļ���˼��
			��������ʹ�÷��ε�˼�룬ͨ��һ�����򽫴������зָ�������֣�
			����һ���ּ�¼�Ĺؼ��־�����һ���ּ�¼�Ĺؼ���С��֮��ֱ���������ּ�¼������������
			�Դﵽ�������������Ŀ�ġ�
��.  �����������������

1) ѡ���׼���ڴ��������У�����ĳ�ַ�ʽ����һ��Ԫ�أ���Ϊ ����׼��(pivot)��

2) �ָ�������Ըû�׼�������е�ʵ��λ�ã������зֳ����������С�
��ʱ���ڻ�׼��ߵ�Ԫ�ض��ȸû�׼С���ڻ�׼�ұߵ�Ԫ�ض��Ȼ�׼��

3) �ݹ�ض��������н��п�������ֱ������Ϊ�ջ���ֻ��һ��Ԫ�أ�

��.  ѡ���׼Ԫ�ķ�ʽ

���ڷ����㷨����ÿ�λ���ʱ���㷨�����ֳܷ������ȳ���������ʱ��
��ô�����㷨Ч�ʻ�ﵽ���.Ҳ����˵����׼��ѡ���Ǻ���Ҫ�ġ�
ѡ���׼�ķ�ʽ�����������ָ�����������еĳ��ȣ������������㷨��Ч�ʲ���������Ӱ�졣
������ķ����ǣ�ѡ��Ļ�׼ǡ���ܰѴ��������зֳ������ȳ��������С�
*/ 
#include<iostream>
#include<algorithm>
#include<cstdlib> 
#include<iomanip>
#include<ctime>
using namespace std;
const int Size = 100000;
void QuickSort(int a[],int left,int right);//�̶���׼ 
void RandomQuickSort(int a[],int left,int right);// �����׼ 
void MedianOfThreeQuickSort(int a[],int left,int right);//����ȡ��(ȡ��������ߡ����ұߺ����м������Ԫ�ص��м�ֵ��Ϊ����) 
void InsertSort(int a[],int left,int right);//(ֱ��)�������� 
void  MedianOfThree_Insert_GatherQuickSort(int a[],int left,int right);//����ȡ��+��������+�ۼ�Ԫ�� 
int main()
{
	srand(unsigned(time(NULL)));
	int a[Size];
	int count =9;
	while(count--)
	{
		for(int i=0;i<Size;i++)
			a[i] = rand()%Size;	
		//sort(a,a+Size);
		clock_t start = clock();
		//RandomQuickSort(a,0,Size-1);
		//QuickSort(a,0,Size-1);
		//MedianOfThreeQuickSort(a,0,Size-1);
		MedianOfThree_Insert_GatherQuickSort(a,0,Size-1);
		//sort(a,a+Size);
		clock_t finish = clock();
		cout<<double(finish - start)<<"ms"<<endl;
	}

}
/*
*�̶���׼Ԫ�������Ŀ�������
*����������ٶ� 16ms(100000���ݴ�С) ,��������������,��150ms(10000���ݴ�С),�����ظ�����,��150ms(10000���ݴ�С)
*��������Ѿ�����ʱ����ʱ�ķָ����һ���ǳ����õķָ��Ϊÿ�λ���ֻ��ʹ���������м�һ��
*��ʱΪ����������������Ϊð������ʱ�临�Ӷ�Ϊ��(n^2)��
*���ң����������������򲿷������������൱�����ġ�
*��ˣ�ʹ�õ�һ��Ԫ����Ϊ��׼Ԫ�Ƿǳ����ģ�Ӧ���������������뷨��
*/ 
void QuickSort(int a[],int left,int right)
{
	if(left<right)
	{
		int i=left,j=right,x=a[left];
		while(i<j)
		{
			while(i<j&&x<=a[j])
				j--;
				
			if(i<j)
				a[i++] = a[j];
				
			while(i<j&&x>=a[i])    
				i++;
				
			if(i<j)
				a[j--] = a[i];
		}
		a[i] = x;//��ʱ  i == j
		QuickSort(a,left,i-1);
		QuickSort(a,i+1,right); 
	}
}
/*
˼�룺ȡ��������������һ��Ԫ����Ϊ��׼Ԫ�� 
�����ԭ���ڴ��������ǲ�������ʱ���̶�ѡȡ��׼Ԫʹ����Ч�ʵ��£�Ҫ������������������������ѡȡ��׼Ԫ��
����������ٶ� 20ms(100000���ݴ�С) ,��������������,��10ms(100000���ݴ�С),�����ظ�����,��150ms(10000���ݴ�С)
�������ݷ�����:����һ����԰�ȫ�Ĳ��ԡ����ڻ�׼Ԫ��λ��������ģ���ô�����ķָ�Ҳ�������ǻ�������ʵķָ
��������������ȫ���ʱ����Ȼ��������ʱ�临�Ӷ���O(n^2����
ʵ���ϣ��������������õ����������Ŀ����Խ�Ϊ1/(2^n����
�������������������Զ��ھ�������������ݴﵽO(nlogn��������ʱ�临�Ӷȡ�
һλǰ��������һ�����ٵ��ܽ᣺����������������������һ����һ���ӵ���Ʒ���󡣡� 
*/ 
void RandomQuickSort(int a[],int left,int right)
{
	if(left<right)
	{
		int randomIndex = rand()%(right-left)+left;
		swap(a[left],a[randomIndex]);
		
		int i=left,j=right,x=a[left];
		while(i<j)
		{
			while(i<j&&x<=a[j])
				j--;
				
			if(i<j)
				a[i++] = a[j];
				
			while(i<j&&x>=a[i])    
				i++;
				
			if(i<j)
				a[j--] = a[i];
		}
		a[i] = x;//��ʱ  i == j
		RandomQuickSort(a,left,i-1);
		RandomQuickSort(a,i+1,right); 
	}
}
/* 
�����ԭ����Ȼ���ѡȡ��׼ʱ�����ٳ��ֲ��÷ָ�ļ��ʣ����ǻ��������»���O(n^2����
Ҫ�������������������������ȡ��ѡȡ��׼��

��������ѵĻ����ǽ�����������зֳɵȳ��������У���ѵ�״̬���ǿ���ʹ�����е��м��ֵ��Ҳ���ǵ�N/2������
���ǣ����������������һ����Լ�������������ٶȡ���������ֵ�Ĺ��ƿ���ͨ�����ѡȡ����Ԫ�ز������ǵ���ֵ��Ϊ��׼Ԫ���õ���
��ʵ�ϣ�����Բ�û�ж��İ��������һ���������ʹ����ˡ��Ҷ˺�����λ���ϵ�����Ԫ�ص���ֵ��Ϊ��׼Ԫ��
��Ȼʹ��������ֵ�ָ������Ԥ��������Ĳ������Σ����Ҽ��ٿ��Ŵ�Լ14%�ıȽϴ�����

����������ٶ�16ms(100000���ݴ�С) ,��������������,��6ms(100000���ݴ�С),�����ظ�����,��150ms(10000���ݴ�С),�ɼ��޷�����ظ����� 
*/ 
void MedianOfThreeQuickSort(int a[],int left,int right)
{
	if(left<right)
	{
		int mid = (left+right)/2;
		// ����if,���м��С�������һ��������
	    if (a[mid] > a[right])
            swap(a[mid],a[right]);
        if (a[left] > a[right])
            swap(a[left],a[right]);
        if (a[mid] > a[left])
            swap(a[mid],a[left]);          
        int i=left,j=right,x=a[left];
		while(i<j)
		{
			while(i<j&&x<=a[j])
				j--;
				
			if(i<j)
				a[i++] = a[j];
				
			while(i<j&&x>=a[i])    
				i++;
				
			if(i<j)
				a[j--] = a[i];
		}
		a[i] = x;//��ʱ  i == j
		MedianOfThreeQuickSort(a,left,i-1);
		MedianOfThreeQuickSort(a,i+1,right);      
	}	
} 
void InsertSort(int a[],int left,int right)
{
	int i,j,k;
	for(i=left+1;i<=right;i++) 
		if(a[i]<a[i-1])
		{
			int temp = a[i];
			for(j=i-1;j>=left&&a[j]>temp;j--)
				a[j+1] = a[j];
			a[j+1] = temp;
		}
}
/* 
�Ż�һ�������������еĳ��ȷָһ����С��ʹ�ò�������

ԭ�򣺶��ں�С�Ͳ�����������飬���Ų�����źá������������еĳ��ȷָһ����С��
�����ָ��Ч�ʱȲ�������Ҫ���ʱ����ʹ�ò��Ŷ����ǿ��š�

��ֹ��Χ�����������г���N = 10����Ȼ��5~20֮����һ��ֹ��Χ���п��ܲ������ƵĽ����
��������Ҳ������һЩ�к����˻����Ρ�

�Ż�������һ�ηָ�����󣬿��԰���Key��ȵ�Ԫ�ؾ���һ�𣬼����´ηָ�ʱ�������ٶ���key���Ԫ�طָ�
������

���������� 1 4 6 7 6 6 7 6 8 6

����ȡ��ѡȡ��׼���±�Ϊ4����6

ת���󣬴��ָ����У�6 4 6 7 1 6 7 6 8 6

             ��׼key��6

���λ��ֺ�δ����keyԪ����ȴ���Ľ����1 4 6 6 7 6 7 6 8 6

�´ε�����������Ϊ��1 4 6 �� 7 6 7 6 8 6

���λ��ֺ󣬶���keyԪ����ȴ���Ľ����1 4 6 6 6 6 6 7 8 7

�´ε�����������Ϊ��1 4 �� 7 8 7

�����Աȣ����ǿ��Կ�������һ�λ��ֺ󣬰���key��ȵ�Ԫ�ؾ���һ���ܼ��ٵ���������Ч�ʻ���߲���

������̣��ڴ�������У�������������

��һ�����ڻ��ֹ����У�����key���Ԫ�ط������������

�ڶ��������ֽ����󣬰���key��ȵ�Ԫ���Ƶ�������Χ

 ���������ٶ�16ms(100000���ݴ�С) ,������������,��6ms(100000���ݴ�С),�����ظ�����,��1ms(100000���ݴ�С)
*/ 
void  MedianOfThree_Insert_GatherQuickSort(int a[],int left,int right)
{
	//���ţ��ݹ����
	if (right - left + 1 < 10)
    {
        InsertSort(a, left, right);
        return;
    }        
	 //����ȡ��                                       
    int mid = (left+right)/2;
	if (a[mid] > a[right])
        swap(a[mid],a[right]);
    if (a[left] > a[right])
        swap(a[left],a[right]);
    if (a[mid] > a[left])
        swap(a[mid],a[left]);             
    //�������ҷ��飨�������Ԫ�أ�
    int first = left;
    int last = right;
    int low = left ;
    int high = right;
    int lowLength = 0;
    int highLength = 0;
    int key = a[first];
    while (first < last)
    {
        while (first < last && a[last] >= key)
        {
            if (a[last] == key)                   //�������Ԫ�أ�����ȵ�Ԫ�ط�����������
            {
            	swap(a[last],a[high]);
                high--;
                highLength++;
            }
            last--;
    	}
        a[first] = a[last];
        while (first < last && a[first] <= key)
        {
            if (a[first] == key)
            {
            	swap(a[first],a[low]);
                low++;
                lowLength++;
            }
            first++;
        }
        a[last] = a[first];
    }
    a[first] = key;
	//һ�ο��Ž���
    //�����׼Ԫkey��ͬ��Ԫ���Ƶ�����λ����Χ
    int i = first - 1;
    int j = left;
    while (j < low && a[i] != key)
    {
    	swap(a[i],a[j]);
        i--;
        j++;
    }
    i = last + 1;
    j = right;
    while (j > high && a[i] != key)
    {
        swap(a[i],a[j]);      
        i++;
        j--;
    }
    MedianOfThree_Insert_GatherQuickSort(a, left, first - lowLength - 1);
    MedianOfThree_Insert_GatherQuickSort(a, first + highLength + 1, right);
}
