#include<iostream>
#include<iomanip>
#include<sstream>
#include<fstream>
#include<string>
#include<windows.h>
#include<cstdlib>
using namespace std;
struct account//����һ����Ϊ���˺š��Ľṹ�� 
{
	string  id,password;//�˺������� 
	double money;//��� 
}user[100];
ifstream infile; //�����ı���������� 
ofstream outfile;
void  input();//���뺯�� 
void output();//������� 
int  login(); //��¼���� 
void main_interface(const int);//�����溯�� 
void query(const int);//��ѯ����
void save(const int);//����
void draw(const int);//ȡ��� 
void transfer(const int);//ת�˺��� 
void change_password(const int);
int size;//size�����˽ṹ������Ĵ�С 
string data="ƾ���������ν��������²���:\n";//data��ƾ������¼���û����εĲ����� 
int main()
{
	int i,sign;//sign��һ����ǣ���¼�û���¼�˵ڼ����˺�  
	while(1)
	{ 
		input();
		cout<<" �� ��---------------------------------------------------------- �� ��"<<endl; 
		cout<<"  �� Ҫ ʹ �� �� A T M �� �� �� 1 ���� Ҫ �� �� �� �� �� 0 : ";
		cin>>i;
		if(i==0)//����������� 
		{
			break;
		} 	
		sign=login();
		main_interface(sign);
	}
	cout<<" �� л �� �� ʹ �� "<<endl; 
	output();//����޸Ĺ�����Ϣ 
	return 0;
}
void  input()//�����ı���Ϣ 
{
	int i;
	infile.open("account.txt");//���ı� 
	if (infile.fail())//����ı�û�д򿪣���ʾ���� 
	{
		cout<<" �� ��---------------------------------------------------------- �� ��"<<endl;
		cout<<"                     open the file error!                             "<<endl;
		cout<<" �� ��---------------------------------------------------------- �� ��"<<endl;
	}	
	for(i=0;infile>>user[i].id;i++)//�����û���Ϣ 
	{
		infile>>user[i].password;
		infile>>user[i].money;
	}
	size=i;//i�����˽ṹ������Ĵ�С 
	infile.close();
}
void output()//����ı���Ϣ 
{
	int i;
	outfile.open("account.txt");//���ı� 
	if (outfile.fail())//����ı�û�д򿪣���ʾ���� 
	{
		cout<<" �� ��---------------------------------------------------------- �� ��"<<endl;
		cout<<"                     open the file error!                             "<<endl;
		cout<<" �� ��---------------------------------------------------------- �� ��"<<endl;
	}	
	for(i=0;i<size;i++)
	{
		outfile<<user[i].id<<" "<<user[i].password<<" "<<user[i].money<<endl; //���޸ĵ���Ϣ������ı��� 
	}
	outfile.close();	
} 
int login()//��¼���� 
{	
	string a,b;
	int i,flag=1;
	do
	{
		system("cls");
		cout<<"                    �y�z�|�}�~�����������������~�}�|�z�y               "<<endl;  
    	cout<<"��=================================================================== ��"<<endl;    
    	cout<<"                        ��ӭʹ��xxxx����ATM�Զ�ȡ���                   "<<endl;    
    	cout<<"                              ����ATM����ϵͳ                           "<<endl;  
   		cout<<" �� ��------------------------------------------------------------ �� ��"<<endl;
    	cout<<"                                                                        "<<endl;  
    	cout<<"                      ************************************              "<<endl;  
    	cout<<"                      *         xxxx����                 *              "<<endl;  
    	cout<<"                      *   ��ÿһ������Ϊ������           *              "<<endl; 
		cout<<"                      *   ��С��ATM��Χ����ʽͨ��!       *              "<<endl; 
		cout<<"                      *   ����թƭ����Ƶ��,��������ת��  *              "<<endl;  
		cout<<"                      *   ��Ӧ����Ӵ���������       *              "<<endl;  
    	cout<<"                      ************************************              "<<endl;  
    	cout<<"                                                                        "<<endl;  
    	cout << "**************************��Ҫʹ��ATM��ع��ܣ����ȵ�¼************** "<<endl; 
    	cout<<"                                                                        "<<endl;  
    	cout<<"                                            �������ʣ�����ϵ���йٷ��ͷ�"<<endl;  
    	cout<<"                                                            xxxx-xxxxxxx"<<endl;  
    	cout<<"��====================================================================��"<<endl<<endl;   
		cout << "�� �� �� �� �� ��";
		cin >> a ;
		cout << "�� �� �� �� �� ��" ;
		cin >> b ; 
		for(i=0;i<size;i++)//������˺š��������ı�����Ϣһһƥ�� 
		{
			if(a==user[i].id&&b==user[i].password)
			{
					system("cls");
					cout<<"��===================================================================��"<<endl;
					cout<<"��                            �� ¼ �� ��                            ��"<<endl;
					cout<<"��===================================================================��"<<endl;
					flag=0; 
					break;			
			}
		}
		if(flag)//������� 
		{
			system("cls");
			cout<<"��===================================================================��"<<endl;
			cout<<"��              \a �� �� �� �� �� �� �� �� ��\a                      ��"<<endl;	
			cout<<"��===================================================================��"<<endl<<endl;
			cout<<"�� Ҫ �� �� �� �� �� ��  �� 1 , ��  �� ��  �� 0 :";
			cin >> i;
			if(i==0)
				exit(0);				
		}	
	}while(flag);
	return i;
}
void main_interface(const int sign)//�����溯��
{

	int i; 
	while(1)
	{
		system("cls");
		cout<<" �� ��-------------------------------------------------- �� ��"<<endl;
		cout<<"           -           ATM��ִ�й���            -"<<endl; 
		cout<<"           -           ����1������ѯ          -"<<endl; 
		cout<<"           -           ����2��ȡ��              -"<<endl;	 
		cout<<"           -           ����3�����              -"<<endl;
		cout<<"           -           ����4��ת��              -"<<endl; 
		cout<<"           -           ����5���޸�����          -"<<endl; 
		cout<<"           -           ����6���˳���ǰ�ʺ�      -"<<endl;
		cout<<" �� ��-------------------------------------------------- �� ��"<<endl;
		cout<<"��������Ҫѡ��Ĺ��ܣ�";
		cin>>i;
		if(i==6)
			break;
		switch(i)
		{
		case 1:query(sign);break;
		case 2:draw(sign);break;
		case 3:save(sign);break;
		case 4:transfer(sign);break;
		case 5:change_password(sign);break;
		default:cout<<"�������������������"<<endl;system("cls"); 
		} 
	}
	system("cls");
	cout<<" �� �� Ҫ �� ӡ ƾ �� �� �� �� 1 ���� �� Ҫ �� ӡ ƾ �� 0 ";
	cin>>i;
	if(i==1)
	{
		if(data!="ƾ���������ν��������²���:\n") //���δ�����κβ������򲻴�ӡƾ���� 
			cout<<data<<endl;	
	}
	data="ƾ���������ν��������²���:\n";//��ԭƾ�� 
}
void query(const int sign)//��ѯ����
{
	system("cls");
	int i; 
	cout.precision(2);//��ȷ���� 
	for(i=5;i>0;i--)  
	{
		cout<<"&&==================================================================&&"<<endl;
		cout<<"        ��   ��   ǰ    ��   ��   ��   ��  ��      "; 
		cout<<fixed<<user[sign].money<<endl;	
		cout<<"&&==================================================================&&"<<endl;
		cout<<"      "<<i<<"  ����Զ�����"<<endl; 
		Sleep(1000);
		system("cls");
	}	
}
void save(const int sign)//����
{
	int i,much;
	while(1)
	{
		system("cls");
		cout<<"--------------------------------------"<<endl;
		cout<<"*       �� �� ��  �� ѡ ��           *"<<endl; 
		cout<<"*           ����1��20Ԫ              *"<<endl; 
		cout<<"*           ����2��50Ԫ              *"<<endl;	 
		cout<<"*           ����3��100Ԫ             *"<<endl;
		cout<<"*           ����4���˳�              *"<<endl;
		cout<<"--------------------------------------"<<endl<<endl<<endl;
		cout<<"-��ѡ�������(�����Ҫʱ������)-"<<endl; 
		cin>>i;
		if(i==4)
		{
			break;
		}
		switch(i)
		{
			case 1: 
				do
				{
					cout<<"����ֽ���������(����Ǯ��):";//ȷ���û�����Ľ�� 
					cin>>much;
					if(much!=20)  
					{
						cout<<"\a�����Ǯ������ȷ\a,��ȡ��Ǯ�����·�����ȷ�Ľ��"<<endl;
						cout<<" �� �� 1 �� �� �� �� �� �� ȷ �� �� ��� �� 0 �� ͣ ֹ �� �� �� �� �� �� �� ����"; 
						cin>>i;
						if(i==1) 
							continue;
						else 
							break;
					}	
				}while(much!=20);
				if(much==20)
				{
					data+="���20Ԫ\n"; //��������¼��ƾ���� 
					user[sign].money+=20;
					Sleep(1000);
					cout<<"���ڴ���������ȴ�"<<endl;
					Sleep(1000);
					cout<<"\a���ɹ�\a";
					Sleep(1000);
					output(); //ÿ�β����󣬼�������������ı��� 
					input();	
				}
				break;
			case 2:	
				do
				{
					cout<<"����ֽ���������(����Ǯ��):";//ȷ���û�����Ľ��
					cin>>much;
					if(much!=50) 
					{
						cout<<"\a�����Ǯ������ȷ\a,��ȡ��Ǯ�����·�����ȷ�Ľ��"<<endl;
					}	
				}while(much!=50);
				if(much=50)
				{
					data+="���50Ԫ\n"; 
					user[sign].money+=50;
					Sleep(1000);
					cout<<"���ڴ���������ȴ�"<<endl;
					Sleep(1000);
					cout<<"\a���ɹ�\a";
					Sleep(1000);
					output();
					input();	
				} 
				break;
			case 3:	
				do
				{
					cout<<"����ֽ���������(����Ǯ��):";
					cin>>much;
					if(much!=100) 
					{
						cout<<"\a�����Ǯ������ȷ\a,��ȡ��Ǯ�����·�����ȷ�Ľ��"<<endl;
					}	
				}while(much!=100);//ֱ���û�������ȷ��Ǯ�� 
				if(much==100)
				{
					data+="���100Ԫ\n"; 
					user[sign].money+=100;
					Sleep(1000);
					cout<<"���ڴ���������ȴ�"<<endl;
					Sleep(1000);
					cout<<"\a���ɹ�\a";
					Sleep(1000);
					output();
					input();	
				}
				break;
			default:cout<<"�������������������"<<endl; 
		} 
		Sleep(1000);
	}		
}
void draw(const int sign)//ȡ��� 
{
	int i;
	while(1)
	{
		system("cls");
		cout<<"--------------------------------------"<<endl;
		cout<<"*       ȡ �� ��  �� ѡ ��           *"<<endl; 
		cout<<"*          ����1��20Ԫ               *"<<endl; 
		cout<<"*          ����2��50Ԫ               *"<<endl;	 
		cout<<"*          ����3��100Ԫ              *"<<endl;
		cout<<"*          ����4���˳�               *"<<endl;
		cout<<"--------------------------------------"<<endl<<endl<<endl;
		cout<<"-��ѡ��ȡ����� (ȡ����Ҫʱ������)-"<<endl; 
		cin>>i;
		if(i==4)
		{
			break;
		}
		switch(i)
		{
			case 1:
				if(user[sign].money>=20) 
				{
					data+="ȡ��20Ԫ\n"; 
					user[sign].money-=20;
					cout<<"��ȡ���ֽ�"<<endl;
					Sleep(1000);
					cout<<"ȡ��ɹ�\a"<<endl;
					output();//ÿ�β����󣬼�������������ı���
					input();
				}
				else
					cout<<"����\a"<<endl; 
				Sleep(1000);
				break;
			case 2:	
				if(user[sign].money>=50) 
				{
					data+="ȡ��50Ԫ\n"; 
					user[sign].money-=50;
					cout<<"��ȡ���ֽ�"<<endl;
					Sleep(1000);
					cout<<"ȡ��ɹ�\a"<<endl;
					output();
					input();	
				}
				else 
					cout<<"����\a"<<endl; 
				Sleep(1000);break;
			case 3:	
				if(user[sign].money>=100) 
				{
					data+="ȡ��100Ԫ\n"; 
					user[sign].money-=100;
					cout<<"��ȡ���ֽ�"<<endl;
					Sleep(1000);
					cout<<"ȡ��ɹ�\a"<<endl;
					output();
					input();		
				}
				else
					cout<<"����\a"<<endl; 	
				Sleep(1000);
				break;
			default:cout<<"�������������������"<<endl; 
		} 
		Sleep(1000);
	}	
}
void transfer(const int sign) //ת�˺��� 
{
	system("cls");
	int i,j,flag=1;
	string card,string_j;
	do
	{
		cout<<"������Ҫת��Ŀ����ʺţ�"; 
		cin>>card;
		if(card==user[sign].id) //���ܸ��Լ����˺�ת�� 
		{
			cout<<" �� �� �� �� �� �� ���� �� �� �� �� �� ת �� "<<endl;
			cout<<" �� �� 1 �� �� �� �� �� �� �� ���� �� 0 �� �� �� �� �� �� ����";
			cin>>j;
			if(j==1) 
				continue;
			else 
				break;
		}
		for(i=0;i<size;i++)
		{
			if(card==user[i].id)
			{
				flag=0;
				break;
			}	
	 	} 
	 	if(flag)
	 	{
			cout<<"�����˺Ŵ���"<<endl;
			cout<<" �� �� 1 �� �� �� �� �� �� �� ���� �� 0 �� �� �� �� �� �� ����";
			cin>>j;
			if(j==1) 
				continue;
			else 
				break;
		}
	}while(flag);
	
	if(flag==0)
	{
		do
		{
			cout<<"������ת�˽�";
			cin>> j;
			if(j>user[sign].money)
			{
				cout<<"�������������"<<endl; 
			}	
		}while(j>user[sign].money);
		stringstream ss;//j��int���ͣ�ͨ��stringstream����ֵת��Ϊstring���Ͳ���ֵ��string_j 
		ss<<j;
		ss>>string_j;
		data="ת��"+user[i].id+":"+string_j+"Ԫ\n";
		user[i].money+=j;//���˻�һ��һ�� 
		user[sign].money-=j;
		cout<<"ת�˳ɹ�"<<endl; 
		output();//ÿ�β����󣬼�������������ı���
		input();
	}
	Sleep(1000);
	system("cls");
}
void change_password(const int sign)
{
	string s1,s2;
	int i,flag=0;
	do
	{	
		system("cls");
		cout<<" �� �� �� �� �� �� �� �� : ";
		cin>>s1;
		cout<<" �� �� �� �� �� ��";
		cin>>s2; 
		if(s1!=s2)
		{
			cout<<" �� �� �� �� �� �� �� �� �� ͬ"<<endl; 
			cout<<" �� �� 1 �� �� �� �� �� �� �� ���� �� 0 �� �� �� �� �� �� ����";
			cin>>i;
			if(i==1) 
				continue;
			else 
				break;
		}
		else if(s1==user[sign].password) 
		{
			cout<<" �� �� �� �� �� �� �� ԭ �� �� �� ͬ"<<endl; 
			cout<<" �� �� 1 �� �� �� �� �� �� �� ���� �� 0 �� �� �� �� �� �� ����";
			cin>>i;
			if(i==1) 
				continue;
			else 
				break;
		}
		else if(s1==s2)
		{	
			user[sign].password=s1; 
			flag=1;
			output();
			input();
			for(i=5;i>0;i--) 
			{
			cout<<"&&==================================================================&&"<<endl;
			cout<<"**                ��     ��    ��    ��    ��    ��                 **"<<endl;
			cout<<"&&==================================================================&&"<<endl;
			cout<<"      "<<i<<"  ����Զ�����"<<endl; 
			Sleep(1000);
			system("cls");
			}		
		}
	}while(flag==0);
	system("cls");	
}
