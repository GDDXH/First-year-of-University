#include<iostream>
#include<iomanip>
#include<sstream>
#include<fstream>
#include<string>
#include<windows.h>
#include<cstdlib>
using namespace std;
struct account//定义一个名为“账号”的结构体 
{
	string  id,password;//账号与密码 
	double money;//存款 
}user[100];
ifstream infile; //定义文本输入输出流 
ofstream outfile;
void  input();//输入函数 
void output();//输出函数 
int  login(); //登录函数 
void main_interface(const int);//主界面函数 
void query(const int);//查询函数
void save(const int);//存款函数
void draw(const int);//取款函数 
void transfer(const int);//转账函数 
void change_password(const int);
int size;//size代表了结构体数组的大小 
string data="凭条：您本次进行了以下操作:\n";//data是凭条，记录了用户本次的操作； 
int main()
{
	int i,sign;//sign是一个标记，记录用户登录了第几个账号  
	while(1)
	{ 
		input();
		cout<<" ● ●---------------------------------------------------------- ● ●"<<endl; 
		cout<<"  若 要 使 用 本 A T M 请 输 入 1 ，若 要 退 出 请 输 入 0 : ";
		cin>>i;
		if(i==0)//跳出程序结束 
		{
			break;
		} 	
		sign=login();
		main_interface(sign);
	}
	cout<<" 感 谢 您 的 使 用 "<<endl; 
	output();//输出修改过的信息 
	return 0;
}
void  input()//读入文本信息 
{
	int i;
	infile.open("account.txt");//打开文本 
	if (infile.fail())//如果文本没有打开，提示错误 
	{
		cout<<" ● ●---------------------------------------------------------- ● ●"<<endl;
		cout<<"                     open the file error!                             "<<endl;
		cout<<" ● ●---------------------------------------------------------- ● ●"<<endl;
	}	
	for(i=0;infile>>user[i].id;i++)//读入用户信息 
	{
		infile>>user[i].password;
		infile>>user[i].money;
	}
	size=i;//i代表了结构体数组的大小 
	infile.close();
}
void output()//输出文本信息 
{
	int i;
	outfile.open("account.txt");//打开文本 
	if (outfile.fail())//如果文本没有打开，提示错误 
	{
		cout<<" ● ●---------------------------------------------------------- ● ●"<<endl;
		cout<<"                     open the file error!                             "<<endl;
		cout<<" ● ●---------------------------------------------------------- ● ●"<<endl;
	}	
	for(i=0;i<size;i++)
	{
		outfile<<user[i].id<<" "<<user[i].password<<" "<<user[i].money<<endl; //将修改的信息输出到文本中 
	}
	outfile.close();	
} 
int login()//登录界面 
{	
	string a,b;
	int i,flag=1;
	do
	{
		system("cls");
		cout<<"                    ▂▃▅▆▇████████▇▆▅▃▂               "<<endl;  
    	cout<<"☆=================================================================== ☆"<<endl;    
    	cout<<"                        欢迎使用xxxx银行ATM自动取款机                   "<<endl;    
    	cout<<"                              自主ATM服务系统                           "<<endl;  
   		cout<<" ● ●------------------------------------------------------------ ● ●"<<endl;
    	cout<<"                                                                        "<<endl;  
    	cout<<"                      ************************************              "<<endl;  
    	cout<<"                      *         xxxx银行                 *              "<<endl;  
    	cout<<"                      *   尽每一份能力为您服务           *              "<<endl; 
		cout<<"                      *   请小心ATM周围非正式通告!       *              "<<endl; 
		cout<<"                      *   近期诈骗案件频发,请勿轻易转账  *              "<<endl;  
		cout<<"                      *   提款卡应避免接触磁性物质       *              "<<endl;  
    	cout<<"                      ************************************              "<<endl;  
    	cout<<"                                                                        "<<endl;  
    	cout << "**************************若要使用ATM相关功能，请先登录************** "<<endl; 
    	cout<<"                                                                        "<<endl;  
    	cout<<"                                            若有疑问，请联系本行官方客服"<<endl;  
    	cout<<"                                                            xxxx-xxxxxxx"<<endl;  
    	cout<<"☆====================================================================☆"<<endl<<endl;   
		cout << "请 输 入 账 号 ：";
		cin >> a ;
		cout << "请 输 入 密 码 ：" ;
		cin >> b ; 
		for(i=0;i<size;i++)//输入的账号、密码与文本中信息一一匹对 
		{
			if(a==user[i].id&&b==user[i].password)
			{
					system("cls");
					cout<<"☆===================================================================☆"<<endl;
					cout<<"☆                            登 录 成 功                            ☆"<<endl;
					cout<<"☆===================================================================☆"<<endl;
					flag=0; 
					break;			
			}
		}
		if(flag)//密码错误 
		{
			system("cls");
			cout<<"☆===================================================================☆"<<endl;
			cout<<"☆              \a 用 户 名 或 者 密 码 错 误\a                      ☆"<<endl;	
			cout<<"☆===================================================================☆"<<endl<<endl;
			cout<<"若 要 重 新 输 入 请 输  入 1 , 退  出 输  入 0 :";
			cin >> i;
			if(i==0)
				exit(0);				
		}	
	}while(flag);
	return i;
}
void main_interface(const int sign)//主界面函数
{

	int i; 
	while(1)
	{
		system("cls");
		cout<<" ● ●-------------------------------------------------- ● ●"<<endl;
		cout<<"           -           ATM可执行功能            -"<<endl; 
		cout<<"           -           输入1；余额查询          -"<<endl; 
		cout<<"           -           输入2：取款              -"<<endl;	 
		cout<<"           -           输入3；存款              -"<<endl;
		cout<<"           -           输入4：转账              -"<<endl; 
		cout<<"           -           输入5：修改密码          -"<<endl; 
		cout<<"           -           输入6；退出当前帐号      -"<<endl;
		cout<<" ● ●-------------------------------------------------- ● ●"<<endl;
		cout<<"请输入你要选择的功能：";
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
		default:cout<<"您输入错误，请重新输入"<<endl;system("cls"); 
		} 
	}
	system("cls");
	cout<<" 如 果 要 打 印 凭 条 请 输 入 1 ，不 需 要 打 印 凭 条 0 ";
	cin>>i;
	if(i==1)
	{
		if(data!="凭条：您本次进行了以下操作:\n") //如果未进行任何操作，则不打印凭条。 
			cout<<data<<endl;	
	}
	data="凭条：您本次进行了以下操作:\n";//还原凭条 
}
void query(const int sign)//查询函数
{
	system("cls");
	int i; 
	cout.precision(2);//余额精确到分 
	for(i=5;i>0;i--)  
	{
		cout<<"&&==================================================================&&"<<endl;
		cout<<"        您   当   前    的   余   额   是  ：      "; 
		cout<<fixed<<user[sign].money<<endl;	
		cout<<"&&==================================================================&&"<<endl;
		cout<<"      "<<i<<"  秒后自动返回"<<endl; 
		Sleep(1000);
		system("cls");
	}	
}
void save(const int sign)//存款函数
{
	int i,much;
	while(1)
	{
		system("cls");
		cout<<"--------------------------------------"<<endl;
		cout<<"*       存 款 面  额 选 择           *"<<endl; 
		cout<<"*           输入1；20元              *"<<endl; 
		cout<<"*           输入2：50元              *"<<endl;	 
		cout<<"*           输入3；100元             *"<<endl;
		cout<<"*           输入4；退出              *"<<endl;
		cout<<"--------------------------------------"<<endl<<endl<<endl;
		cout<<"-请选择存款金额功能(存款需要时间运行)-"<<endl; 
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
					cout<<"请把现金放入机器中(输入钱数):";//确认用户放入的金额 
					cin>>much;
					if(much!=20)  
					{
						cout<<"\a放入的钱数不正确\a,请取走钱，重新放入正确的金额"<<endl;
						cout<<" 输 入 1 则 重 新 放 入 正 确 的 金 额，输 入 0 则 停 止 存 款 返 回 上 级 菜 单："; 
						cin>>i;
						if(i==1) 
							continue;
						else 
							break;
					}	
				}while(much!=20);
				if(much==20)
				{
					data+="存款20元\n"; //将操作记录到凭条中 
					user[sign].money+=20;
					Sleep(1000);
					cout<<"正在存款操作，请等待"<<endl;
					Sleep(1000);
					cout<<"\a存款成功\a";
					Sleep(1000);
					output(); //每次操作后，即将数据输出到文本中 
					input();	
				}
				break;
			case 2:	
				do
				{
					cout<<"请把现金放入机器中(输入钱数):";//确认用户放入的金额
					cin>>much;
					if(much!=50) 
					{
						cout<<"\a放入的钱数不正确\a,请取走钱，重新放入正确的金额"<<endl;
					}	
				}while(much!=50);
				if(much=50)
				{
					data+="存款50元\n"; 
					user[sign].money+=50;
					Sleep(1000);
					cout<<"正在存款操作，请等待"<<endl;
					Sleep(1000);
					cout<<"\a存款成功\a";
					Sleep(1000);
					output();
					input();	
				} 
				break;
			case 3:	
				do
				{
					cout<<"请把现金放入机器中(输入钱数):";
					cin>>much;
					if(much!=100) 
					{
						cout<<"\a放入的钱数不正确\a,请取走钱，重新放入正确的金额"<<endl;
					}	
				}while(much!=100);//直到用户输入正确的钱数 
				if(much==100)
				{
					data+="存款100元\n"; 
					user[sign].money+=100;
					Sleep(1000);
					cout<<"正在存款操作，请等待"<<endl;
					Sleep(1000);
					cout<<"\a存款成功\a";
					Sleep(1000);
					output();
					input();	
				}
				break;
			default:cout<<"您输入错误，请重新输入"<<endl; 
		} 
		Sleep(1000);
	}		
}
void draw(const int sign)//取款函数 
{
	int i;
	while(1)
	{
		system("cls");
		cout<<"--------------------------------------"<<endl;
		cout<<"*       取 款 面  额 选 择           *"<<endl; 
		cout<<"*          输入1；20元               *"<<endl; 
		cout<<"*          输入2：50元               *"<<endl;	 
		cout<<"*          输入3；100元              *"<<endl;
		cout<<"*          输入4；退出               *"<<endl;
		cout<<"--------------------------------------"<<endl<<endl<<endl;
		cout<<"-请选择取款金额功能 (取款需要时间运行)-"<<endl; 
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
					data+="取款20元\n"; 
					user[sign].money-=20;
					cout<<"请取走现金"<<endl;
					Sleep(1000);
					cout<<"取款成功\a"<<endl;
					output();//每次操作后，即将数据输出到文本中
					input();
				}
				else
					cout<<"余额不足\a"<<endl; 
				Sleep(1000);
				break;
			case 2:	
				if(user[sign].money>=50) 
				{
					data+="取款50元\n"; 
					user[sign].money-=50;
					cout<<"请取走现金"<<endl;
					Sleep(1000);
					cout<<"取款成功\a"<<endl;
					output();
					input();	
				}
				else 
					cout<<"余额不足\a"<<endl; 
				Sleep(1000);break;
			case 3:	
				if(user[sign].money>=100) 
				{
					data+="取款100元\n"; 
					user[sign].money-=100;
					cout<<"请取走现金"<<endl;
					Sleep(1000);
					cout<<"取款成功\a"<<endl;
					output();
					input();		
				}
				else
					cout<<"余额不足\a"<<endl; 	
				Sleep(1000);
				break;
			default:cout<<"您输入错误，请重新输入"<<endl; 
		} 
		Sleep(1000);
	}	
}
void transfer(const int sign) //转账函数 
{
	system("cls");
	int i,j,flag=1;
	string card,string_j;
	do
	{
		cout<<"请输入要转入的卡的帐号："; 
		cin>>card;
		if(card==user[sign].id) //不能给自己的账号转账 
		{
			cout<<" 输 入 账 号 错 误 ，无 法 向 现 账 户 转 账 "<<endl;
			cout<<" 输 入 1 则 继 续 修 改 密 码 ，输 入 0 则 返 回 上 级 菜 单：";
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
			cout<<"输入账号错误"<<endl;
			cout<<" 输 入 1 则 继 续 修 改 密 码 ，输 入 0 则 返 回 上 级 菜 单：";
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
			cout<<"请输入转账金额：";
			cin>> j;
			if(j>user[sign].money)
			{
				cout<<"输入金额错误，余额不足"<<endl; 
			}	
		}while(j>user[sign].money);
		stringstream ss;//j是int类型，通过stringstream将其值转化为string类型并赋值给string_j 
		ss<<j;
		ss>>string_j;
		data="转给"+user[i].id+":"+string_j+"元\n";
		user[i].money+=j;//两账户一加一减 
		user[sign].money-=j;
		cout<<"转账成功"<<endl; 
		output();//每次操作后，即将数据输出到文本中
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
		cout<<" 请 输 入 您 的 新 密 码 : ";
		cin>>s1;
		cout<<" 请 再 次 输 入 ：";
		cin>>s2; 
		if(s1!=s2)
		{
			cout<<" 您 两 次 输 入 的 密 码 不 同"<<endl; 
			cout<<" 输 入 1 则 继 续 修 改 密 码 ，输 入 0 则 返 回 上 级 菜 单：";
			cin>>i;
			if(i==1) 
				continue;
			else 
				break;
		}
		else if(s1==user[sign].password) 
		{
			cout<<" 您 输 入 的 密 码 与 原 密 码 相 同"<<endl; 
			cout<<" 输 入 1 则 继 续 修 改 密 码 ，输 入 0 则 返 回 上 级 菜 单：";
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
			cout<<"**                成     功    修    改    密    码                 **"<<endl;
			cout<<"&&==================================================================&&"<<endl;
			cout<<"      "<<i<<"  秒后自动返回"<<endl; 
			Sleep(1000);
			system("cls");
			}		
		}
	}while(flag==0);
	system("cls");	
}
