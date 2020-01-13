//源代码由Dev-c++5.11编译 
// By 201626811420  14班沈晨亿 
#include<iostream>
#include<string>
using namespace std;
struct list{//定义结构体 
	int	ID;//学生学号 ，类型为整数 
	string name;//学生姓名 ,类型为字符串 
	list *next;
};
struct list *creat();//建立链表 
void print(struct list *head);//打印链表 
struct list *del(struct list *head);//删除操作 
struct list *insert(struct list *head);//插入操作 
int main()
{
	list * head=NULL;
	head = creat();
	while(1)//主界面 
	{
		int i;
		cout<<" ● ●---------------------------------------------------------- ● ●"<<endl;
		cout<<"       输入 1：打印链表              输入 2：删除结点                 "<<endl;
		cout<<"       输入 3：插入节点              输入 4：退出                     "<<endl;
		cout<<" ● ●---------------------------------------------------------- ● ●"<<endl;
		cout<<"请输入你的操作："; 
		cin>>i;
		if(i==4)
			break;
		switch(i)
		{
			case 1:	print(head);break;
			case 2: head = del(head);break;
			case 3: head = insert(head);break;
		}
	}
	return 0;
} 
struct list *creat()//建立链表 
{
    list *p,*next_p,*head = NULL;
    p=next_p=new list;
    cout<<"请输入学号与姓名(输入0与0为结束)："<<endl; 
    cin>>next_p->ID>>next_p->name;
    if(next_p->ID!=0)
    {
        p = head = next_p;
        next_p=new list;
	}
	cout<<head->ID<<endl;
    while(cin>>next_p->ID>>next_p->name,next_p->ID!=0)
    {     
	   	p->next=next_p;
	   	p=next_p;
	   	next_p=new list;
    }
    cout<<head->ID<<endl;
    delete next_p;
    p->next=NULL;
	return head;
}
void print(struct list*head)//打印链表
{
	list *p;
	int sign = 1;
	p = head;
	while(p!=NULL)
	{		
		cout<<"第"<<sign++<<"项 学号： "<<p->ID<<" 姓名： "<<p->name<<endl;
		p=p->next;
	}	
}
struct list *del(struct list *head)//删除操作 
{
	list * p=head,*before;
	int num;
	if(head==NULL)
	{
		cout<<"操作失败，链表中无数据"<<endl;
		return head; 
	}
	cout<<"请输入你要删除的学生学号：";
	cin>>num; 
	while(num!=p->ID&&p->next!=NULL)
	{
		before = p;
		p=p->next;
	}
	if(num==p->ID)
	{
		if(p==head)
		{
			head = p->next;
		}
		else
		{
			before->next = p->next;
		}
		cout<<"删除元素成功"<<endl;
	}
	else
	{
		cout<<"操作失败，没有这个学生"<<endl; 
	} 
	return head;
} 
struct list *insert(struct list *head)//插入操作 ,功能并不完善，无法插入到head之前 
{
	int num;
	list * p = head, *before;
	if(head == NULL)
	{
		cout<<"操作失败，链表中无数据"<<endl;
		return head; 
	} 
	cout<<"请输入你要插入到哪个学号后: ";
	cin>>num; 
	while(num!=p->ID&&p->next!=NULL)
	{
		before = p;
		p=p->next;
	}
	if(num == p->ID)
	{
		list *temp ;
		temp = new list; 
		cout<<"请输入学号与姓名: ";
		cin>>temp->ID>>temp->name;
		temp->next = p->next;
		p->next =temp;
		cout<<"插入元素成功"<<endl;	
	} 
	else
	{
		cout<<"操作失败，没有这个学生"<<endl; 
	}
	return head;	
}
