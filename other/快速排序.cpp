/*
								快速排序及其优化 
一.  快速排序的基本思想
			快速排序使用分治的思想，通过一趟排序将待排序列分割成两部分，
			其中一部分记录的关键字均比另一部分记录的关键字小。之后分别对这两部分记录继续进行排序，
			以达到整个序列有序的目的。
二.  快速排序的三个步骤

1) 选择基准：在待排序列中，按照某种方式挑出一个元素，作为 “基准”(pivot)；

2) 分割操作：以该基准在序列中的实际位置，把序列分成两个子序列。
此时，在基准左边的元素都比该基准小，在基准右边的元素都比基准大；

3) 递归地对两个序列进行快速排序，直到序列为空或者只有一个元素；

三.  选择基准元的方式

对于分治算法，当每次划分时，算法若都能分成两个等长的子序列时，
那么分治算法效率会达到最大.也就是说，基准的选择是很重要的。
选择基准的方式决定了两个分割后两个子序列的长度，进而对整个算法的效率产生决定性影响。
最理想的方法是，选择的基准恰好能把待排序序列分成两个等长的子序列。
*/ 
#include<iostream>
#include<algorithm>
#include<cstdlib> 
#include<iomanip>
#include<ctime>
using namespace std;
const int Size = 100000;
void QuickSort(int a[],int left,int right);//固定基准 
void RandomQuickSort(int a[],int left,int right);// 随机基准 
void MedianOfThreeQuickSort(int a[],int left,int right);//三数取中(取数组最左边、最右边和最中间的三个元素的中间值作为中轴) 
void InsertSort(int a[],int left,int right);//(直接)插入排序 
void  MedianOfThree_Insert_GatherQuickSort(int a[],int left,int right);//三数取中+插入排序+聚集元素 
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
*固定基准元（基本的快速排序）
*随机数组是速度 16ms(100000数据大小) ,但若是有序数据,则150ms(10000数据大小),若是重复数据,则150ms(10000数据大小)
*如果数组已经有序时，此时的分割就是一个非常不好的分割。因为每次划分只能使待排序序列减一，
*此时为最坏情况，快速排序沦为冒泡排序，时间复杂度为Θ(n^2)。
*而且，输入的数据是有序或部分有序的情况是相当常见的。
*因此，使用第一个元素作为基准元是非常糟糕的，应该立即放弃这种想法。
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
		a[i] = x;//此时  i == j
		QuickSort(a,left,i-1);
		QuickSort(a,i+1,right); 
	}
}
/*
思想：取待排序列中任意一个元素作为基准元。 
引入的原因：在待排序列是部分有序时，固定选取基准元使快排效率底下，要缓解这种情况，就引入了随机选取基准元。
随机数组是速度 20ms(100000数据大小) ,但若是有序数据,则10ms(100000数据大小),若是重复数据,则150ms(10000数据大小)
测试数据分析：:这是一种相对安全的策略。由于基准元的位置是随机的，那么产生的分割也不会总是会出现劣质的分割。
在整个数组数字全相等时，仍然是最坏情况，时间复杂度是O(n^2）。
实际上，随机化快速排序得到理论最坏情况的可能性仅为1/(2^n）。
所以随机化快速排序可以对于绝大多数输入数据达到O(nlogn）的期望时间复杂度。
一位前辈做出了一个精辟的总结：“随机化快速排序可以满足一个人一辈子的人品需求。” 
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
		a[i] = x;//此时  i == j
		RandomQuickSort(a,left,i-1);
		RandomQuickSort(a,i+1,right); 
	}
}
/* 
引入的原因：虽然随机选取基准时，减少出现不好分割的几率，但是还是最坏情况下还是O(n^2），
要缓解这种情况，就引入了三数取中选取基准。

分析：最佳的划分是将待排序的序列分成等长的子序列，最佳的状态我们可以使用序列的中间的值，也就是第N/2个数。
可是，这很难算出来，并且会明显减慢快速排序的速度。这样的中值的估计可以通过随机选取三个元素并用它们的中值作为基准元而得到。
事实上，随机性并没有多大的帮助，因此一般的做法是使用左端、右端和中心位置上的三个元素的中值作为基准元。
显然使用三数中值分割法消除了预排序输入的不好情形，并且减少快排大约14%的比较次数。

随机数组是速度16ms(100000数据大小) ,但若是有序数据,则6ms(100000数据大小),若是重复数据,则150ms(10000数据大小),可见无法解决重复数组 
*/ 
void MedianOfThreeQuickSort(int a[],int left,int right)
{
	if(left<right)
	{
		int mid = (left+right)/2;
		// 三个if,将中间大小的数与第一个数交换
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
		a[i] = x;//此时  i == j
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
优化一：当待排序序列的长度分割到一定大小后，使用插入排序

原因：对于很小和部分有序的数组，快排不如插排好。当待排序序列的长度分割到一定大小后，
继续分割的效率比插入排序要差，此时可以使用插排而不是快排。

截止范围：待排序序列长度N = 10，虽然在5~20之间任一截止范围都有可能产生类似的结果，
这种做法也避免了一些有害的退化情形。

优化二：在一次分割结束后，可以把与Key相等的元素聚在一起，继续下次分割时，不用再对与key相等元素分割
举例：

待排序序列 1 4 6 7 6 6 7 6 8 6

三数取中选取基准：下标为4的数6

转换后，待分割序列：6 4 6 7 1 6 7 6 8 6

             基准key：6

本次划分后，未对与key元素相等处理的结果：1 4 6 6 7 6 7 6 8 6

下次的两个子序列为：1 4 6 和 7 6 7 6 8 6

本次划分后，对与key元素相等处理的结果：1 4 6 6 6 6 6 7 8 7

下次的两个子序列为：1 4 和 7 8 7

经过对比，我们可以看出，在一次划分后，把与key相等的元素聚在一起，能减少迭代次数，效率会提高不少

具体过程：在处理过程中，会有两个步骤

第一步，在划分过程中，把与key相等元素放入数组的两端

第二步，划分结束后，把与key相等的元素移到枢轴周围

 机数组是速度16ms(100000数据大小) ,若是有序数据,则6ms(100000数据大小),若是重复数据,则1ms(100000数据大小)
*/ 
void  MedianOfThree_Insert_GatherQuickSort(int a[],int left,int right)
{
	//插排，递归出口
	if (right - left + 1 < 10)
    {
        InsertSort(a, left, right);
        return;
    }        
	 //三数取中                                       
    int mid = (left+right)/2;
	if (a[mid] > a[right])
        swap(a[mid],a[right]);
    if (a[left] > a[right])
        swap(a[left],a[right]);
    if (a[mid] > a[left])
        swap(a[mid],a[left]);             
    //进行左右分组（处理相等元素）
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
            if (a[last] == key)                   //处理相等元素，将相等的元素放置数组两端
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
	//一次快排结束
    //把与基准元key相同的元素移到最终位置周围
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
