//Դ������Dev-c++5.11���� 
// By 201626811420  14������ 
#include<iostream>
#include<string>
using namespace std;
struct list{//����ṹ�� 
	int	ID;//ѧ��ѧ�� ������Ϊ���� 
	string name;//ѧ������ ,����Ϊ�ַ��� 
	list *next;
};
struct list *creat();//�������� 
void print(struct list *head);//��ӡ���� 
struct list *del(struct list *head);//ɾ������ 
struct list *insert(struct list *head);//������� 
int main()
{
	list * head=NULL;
	head = creat();
	while(1)//������ 
	{
		int i;
		cout<<" �� ��---------------------------------------------------------- �� ��"<<endl;
		cout<<"       ���� 1����ӡ����              ���� 2��ɾ�����                 "<<endl;
		cout<<"       ���� 3������ڵ�              ���� 4���˳�                     "<<endl;
		cout<<" �� ��---------------------------------------------------------- �� ��"<<endl;
		cout<<"��������Ĳ�����"; 
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
struct list *creat()//�������� 
{
    list *p,*next_p,*head = NULL;
    p=next_p=new list;
    cout<<"������ѧ��������(����0��0Ϊ����)��"<<endl; 
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
void print(struct list*head)//��ӡ����
{
	list *p;
	int sign = 1;
	p = head;
	while(p!=NULL)
	{		
		cout<<"��"<<sign++<<"�� ѧ�ţ� "<<p->ID<<" ������ "<<p->name<<endl;
		p=p->next;
	}	
}
struct list *del(struct list *head)//ɾ������ 
{
	list * p=head,*before;
	int num;
	if(head==NULL)
	{
		cout<<"����ʧ�ܣ�������������"<<endl;
		return head; 
	}
	cout<<"��������Ҫɾ����ѧ��ѧ�ţ�";
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
		cout<<"ɾ��Ԫ�سɹ�"<<endl;
	}
	else
	{
		cout<<"����ʧ�ܣ�û�����ѧ��"<<endl; 
	} 
	return head;
} 
struct list *insert(struct list *head)//������� ,���ܲ������ƣ��޷����뵽head֮ǰ 
{
	int num;
	list * p = head, *before;
	if(head == NULL)
	{
		cout<<"����ʧ�ܣ�������������"<<endl;
		return head; 
	} 
	cout<<"��������Ҫ���뵽�ĸ�ѧ�ź�: ";
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
		cout<<"������ѧ��������: ";
		cin>>temp->ID>>temp->name;
		temp->next = p->next;
		p->next =temp;
		cout<<"����Ԫ�سɹ�"<<endl;	
	} 
	else
	{
		cout<<"����ʧ�ܣ�û�����ѧ��"<<endl; 
	}
	return head;	
}
