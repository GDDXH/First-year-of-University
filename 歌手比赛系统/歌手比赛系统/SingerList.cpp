#include"SingerList.h"
SingerList::SingerList():Test(),SLoad()//构造函数
{
	head = NULL;	
}
bool SingerList::creat_list()//建立链表
{
	// 选手信息必须通过文件读入
	string na,stu,so,s,c;
	int n,a;
	list *p, *next_p;
	head = NULL;
	p = new list, next_p = new list;

	/*
	cout << " ● ●---------------------------------------------------------- ● ●" << endl;
	cout << "             1：文件输入(信息未完善)    2：文件输入(信息已完善)       " << endl;
	cout << "                                        0: 返回上一界面               " << endl;
	cout << " ● ●---------------------------------------------------------- ● ●" << endl;
	*/
	cout << "请输入你的操作：";
	cin >> n;
	if (n == 0)
	{
		return false;
	}
    else if (n != 1 && n != 2)
	{
		cerr << "Warning:输入错误!!!"<<endl;
		abort();
	}
	else if (n == 1)
	{
		cout << "输入文件名:   ";
		cin >> s;
		cout << endl;
		ifstream infile;
		infile.open(s + ".dat");
		if (!infile.is_open())
		{
			system("cls");
			system("color 1F");
			cerr << "Error:无法打开文件"<< endl;
			abort();
		}

		if (infile >> na >> n )
		{
			if (n <= 0 || n > Size)
			{
				system("cls");
				system("color 1F");
				cerr << "文件信息错误,程序结束" << endl;
				abort();
			}
			num.push_back(n);
			p->data.input(na, n);
			head = p;
			while (infile >> na >> n )
			{
				if (n <= 0 || n > Size)
				{
					system("cls");
					system("color 1F");
					cerr << "文件信息错误,程序结束" << endl;
					abort();
				}
				num.push_back(n);
				next_p->data.input(s, n);
				p->next = next_p;
				p = next_p;
				next_p = new list;
			}
			p->next = NULL;
			delete next_p;
			infile.close();
			cout << "建立选手信息表成功" << endl;
			cout << "建议:请先完善选手信息!!!" << endl;
		}
		else
		{
			system("cls");
			system("color 1F");
			cerr << "Warning:文件为空,创建链表失败!!!!!" << endl;
			abort();
		}
	}
	else if (n == 2)
	{
			cout << "PS:选手数据需按规则排序:姓名、编号、学号、参赛歌曲、性别、年龄、所属学院" << endl;
			cout << "输入文件名:   ";
			cin >> s;
			cout << endl;
			ifstream infile;
			infile.open(s + ".dat");
			if (!infile.is_open())
			{
				system("cls");
				system("color 1F");
				cerr << "Error:无法打开文件" << endl;
				abort();
			}
			if (infile >> na>>n>>stu>>so>>s>>a>>c)
			{
				if (n <= 0 || n > Size)
				{
					system("cls");
					system("color 1F");
					cerr << "文件信息错误,程序结束" << endl;
					abort();
				}
				num.push_back(n);
				p->data.input(na, n, stu, so, s, a, c);
				p->data.inputFlag(true);
				head = p;
				while (infile >> na >> n >> stu >> so >> s >> a >> c)
				{
					if (n <= 0 || n > Size)
					{
						system("cls");
						system("color 1F");
						cout << "文件信息错误,程序结束" << endl;
						abort();
					}
					num.push_back(n);
					next_p->data.input(na, n, stu, so, s, a, c);
					next_p->data.inputFlag(true);
					p->next = next_p;
					p = next_p;
					next_p = new list;
				}
				p->next = NULL;
				delete next_p;
				infile.close();
				cout << "建立选手信息表成功" << endl;
			}
			else
			{
				system("cls");
				system("color 1F");
				cerr << "Warning:文件为空,创建链表失败!!!!!" << endl;
				abort();
			}
	}
	return true;//创建链表成功
}
void SingerList::infile_judge()//输入评委
{
	list *p = head;
	string s[10];
	cout << "请通过文件输入评委信息" << endl;
	cout << "输入文件名:   ";
	cin >> s[0];
	cout << endl;
	ifstream infile;
	infile.open(s[0] + ".dat");
	if (!infile.is_open())
	{
		system("cls");
		system("color 1F");
		cerr << "Error:无法打开文件,程序出错!!!" << endl;
		Sleep(500);
		abort();
	}
	for (int i = 0;i < 10;i++)
	{
		infile >> s[i];
	}
	while (p != NULL)
	{
		p->data.inputJudge(s);
		p = p->next;
	}
	infile.close();
	cout << "\n提示:按任意键返回";
	_getch();
}
void SingerList::add_information()//完善信息
{
	cout << "该功能模块能完善选手的相关信息:参赛歌曲,性别,年龄,学号,学院" << endl << endl;
	list *p = head;
	string s,c,id;
	bool sign = true;
	if (p == NULL)
	{
		cout << "Warning:选手信息表尚未创建!!!" << endl;
	}
	else
	{
		while (p != NULL) 
		{
			if (!p->data.getFlag())
			{
				cout << "选手姓名:" << p->data.getName() << "\t选手编号:" << p->data.getNumber() << endl;
				cout << "请输入参赛歌曲:";
				cin >> s;
				p->data.inputSong(s);
				cout << "完善参赛歌曲信息成功" << endl;

				p->data.inputSex();
				p->data.inputAge();

				while (sign)
				{
					sign = false;
					try {
						cout << "请输入学号:";
						cin >> id;
						test_ID(id);
					}
					catch (int)
					{
						cout << "学号" << id << "已存在" << endl;
						sign = true;
					}
					catch (double)
					{
						cout << "学号" << id << "不符合规则" << endl;
						sign = true;
					}
				}
				p->data.inputStudent_id(id);
				ID.push_back(id);
				cout << "完善参赛歌曲信息成功" << endl;

				cout << "请输入学院:";
				cin >> c;
				p->data.inputCollege(c);
				cout << "完善所属学院信息成功" << endl << endl << endl;
				p->data.inputFlag(true);
			}
			p = p->next;
		}
	}
	cout << "成功所有完善选手信息" << endl;
	cout << "\n提示:按任意键返回";
	_getch();
}

void SingerList::print_list()//遍历链表,显示选手信息
{
	list *p = head;
	cout << "姓名\t编号\t学号\t\t总分\t平均分\t名次" << endl;
	while (p != NULL)
	{
		cout << p->data;
		p = p->next;
	}
	cout << "姓名\t学号\t\t参赛歌曲\t年龄\t性别\t学院" << endl;
	p = head;
	while (p != NULL)
	{
		Singer temp = p->data;
		Person *s = &temp;
		s->display();
		p = p->next;
	}
	if (head->data.getRanking() == 0)
		cout << "PS:执行成绩排序操作后,才能看的正确名次" << endl << endl;
	cout << "\n提示:按任意键返回";
	_getch();
}
void SingerList::sort_number()//链表排序
{
	//冒泡排序,评委打分时,应按照选手编号顺序
	list * p, *q;
	for (p = head;p->next!= NULL;p = p->next)
	{
		for (q = p->next;q != NULL;q = q->next)
		{
			if (p->data.getNumber()>q->data.getNumber())
			{
				Singer temp;
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
		}
	}
}

void SingerList::seek()//查询函数
{
	list *p = head;
	string s;
	int num;
	bool flag = true;

	/*
	cout << " ● ●---------------------------------------------------------- ● ●" << endl;
	cout << "             1：按姓名查询                  2：按编号查询             " << endl;
	cout << "                                            0: 返回上一界面           " << endl;
	cout << " ● ●---------------------------------------------------------- ● ●" << endl;
	*/
	cout << "请输入你的操作：";
	cin >> num;
	if (num == 0 )
	{
		return;
	}
	else if (num != 1 && num != 2)
	{
		cout << "Warning::输入错误!!!" << endl;
		Sleep(500);
		return;
	}
	else if (num == 1)
	{
		//选手姓名可能重复
		cout << "请输入姓名:";
		cin >> s;
		cout << "姓名为" << s << "的歌手有:" << endl;
		while (p != NULL)
		{
			string temp = p->data.getName();
			if (s == temp)
			{
				if (flag)
				{
					cout << "姓名\t编号\t学号\t\t总分\t平均分\t名次" << endl;
					flag = false;
				}
				cout << p->data;
			}
			p = p->next;
		}
		if (flag)
			cout << "没有找到相关选手信息" << endl;
		cout << "\n查找结束" << endl;
	}

	else if (num == 2)
	{
		// 编号必定为一
		cout << "请输入编号:";
		cin >> num;
		try {
			flag = true;
			test_num(num*1.0);
		}
		catch (int)
		{
			cout << "没有此编号" << endl;
			flag = false;
		}
		catch (double)
		{
			cout << "该编号不符合规则" << endl;
			flag =false;
		}
		if(flag)//flag == true 则编号存在
			while (p != NULL)
			{
				int temp = p->data.getNumber();
				if (num == temp)
				{
					cout << "姓名\t编号\t学号\t\t总分\t平均分\t名次" << endl;
					cout << p->data;
					cout << "姓名\t学号\t\t参赛歌曲\t年龄\t性别\t学院" << endl;
					p->data.display();
					cout << "具体评分:" << endl;
					p->data.display_judge();
					break;
				}
				p = p->next;
			}
	}
	cout << "\n提示:按任意键返回";
	_getch();
}
void SingerList::modify()//修改函数
{
	int t;
	/*
	cout << " ● ●---------------------------------------------------------- ● ●" << endl;
	cout << "             1：删除选手                  2：修改姓名                 " << endl;
	cout << "             3：修改性别                  4：修改年龄                 " << endl;
	cout << "             5: 修改参赛歌曲              6: 修改学院                 " << endl;
	cout << "                                          0：返回上一界面             " << endl;
	cout << " ● ●---------------------------------------------------------- ● ●" << endl;
	*/
	cout << "请输入你的选择:";
		cin >> t;
	if (t == 0)
		return;
	else if (t == 1)
		delete_singer();
	else if (t == 2)
	{
		int num;
		string  s;


			try {
				cout << "请输入选手的编号:";
				cin >> num;
				test_num(num*1.0);
			}
			catch (int )
			{
				cout << "编号" << num << "不存在" << endl;
				Sleep(500);
				return;
			}
			catch (double n)
			{
				cout << "编号" << (int)n << "不符合规则" << endl;
				Sleep(500);
				return;
			}

			cout << "请输入姓名" << endl;
			cin >> s;
			list *p = head;
			while (p != NULL)
			{
				if (num == p->data.getNumber())
				{
					p->data.inputName(s);
					break;
				}
				p = p->next;
			}
			cout << "修改成功" << endl;
		}
	else if (t == 3)
	{
		int num;
		string  s;


		try {
			cout << "请输入选手的编号:";
			cin >> num;
			test_num(num*1.0);
		}
		catch (int)
		{
			cout << "编号" << num << "不存在" << endl;
			Sleep(500);
			return;
		}
		catch (double n)
		{
			cout << "编号" << (int)n << "不符合规则" << endl;
			Sleep(500);
			return;
		}
		cout << "请输入性别(male or female)" << endl;
		cin >> s;
		list *p = head;
		while (p != NULL)
		{
			if (num == p->data.getNumber())
			{
				p->data.inputSex(s);
				break;
			}
			p = p->next;
		}
		cout << "修改成功" << endl;
	}
	else if (t == 4)
	{
		int num;
		int age;


		try {
			cout << "请输入选手的编号:";
			cin >> num;
			test_num(num*1.0);
		}
		catch (int)
		{
			cout << "编号" << num << "不存在" << endl;
			Sleep(500);
			return;
		}
		catch (double n)
		{
			cout << "编号" << (int)n << "不符合规则" << endl;
			Sleep(500);
			return;
		}
		cout << "请输入年龄" << endl;
		cin >> age ;
		list *p = head;
		while (p != NULL)
		{
			if (num == p->data.getNumber())
			{
				p->data.inputAge(age);
				break;
			}
			p = p->next;
		}
		cout << "修改成功" << endl;
	}
	else if (t == 5)
	{
		int num;
		string  s;


		try {
			cout << "请输入选手的编号:";
			cin >> num;
			test_num(num*1.0);
		}
		catch (int)
		{
			cout << "编号" << num << "不存在" << endl;
			Sleep(500);
			return;
		}
		catch (double n)
		{
			cout << "编号" << (int)n << "不符合规则" << endl;
			Sleep(500);
			return;
		}
		cout << "请输入参赛歌曲" << endl;
		cin >> s;
		list *p = head;
		while (p != NULL)
		{
			if (num == p->data.getNumber())
			{
				p->data.inputSong(s);
				break;
			}
			p = p->next;
		}
		cout << "修改成功" << endl;
	}
	else if (t == 5)//修改学院
	{
		int num;
		string  s;


		try {
			cout << "请输入选手的编号:";
			cin >> num;
			test_num(num*1.0);
		}
		catch (int)
		{
			cout << "编号" << num << "不存在" << endl;
			Sleep(500);
			return;
		}
		catch (double n)
		{
			cout << "编号" << (int)n << "不符合规则" << endl;
			Sleep(500);
			return;
		}
		cout << "请输入学院" << endl;
		cin >> s;
		list *p = head;
		while (p != NULL)
		{
			if (num == p->data.getNumber())
			{
				p->data.inputCollege(s);
				break;
			}
			p = p->next;
		}
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "输入错误,默认返回" << endl;
	}
	cout << "\n提示:按任意键返回";
	_getch();
}
void SingerList::add_singer()//追加选手数据
{
	bool sign = true;
	string s[10];
	int n;
	list *p = head, *add_p;
	add_p = new list;

	while (p->next != NULL)
	{
		p = p->next;
	}
	cout << "请输入新增选手的姓名:";
	cin >> s[0];
	while (sign)
	{
		sign = false;
		try {
			cout << "请输入新增选手的编号:";
				cin >> n;
			test_num(n);
		}
		catch (int n)
		{
			cout << "编号" << n << "已存在" << endl;
			sign = true;
		}
		catch (double n)
		{
			cout << "编号" <<(int)n << "不符合规则" << endl;
			sign = true;
		}
	}
	num.push_back(n);//储存新增选手编号
	add_p->data.input(s[0], n);//将姓名与编号赋值给新的选手

	//给新增选手赋值相关评委信息
	const node *temp = p->data.getJudge();
	for (int i = 0;i < 10;i++)
	{
		s[i] = (temp + i)->name;
	}
	add_p->data.inputJudge(s);

	p->next = add_p;
	p = add_p;
	p->next = NULL;
	cout << "追加选手成功,建议立刻完善选手信息" << endl;
	cout << "\n提示:按任意键返回";
	_getch();
}

void SingerList::delete_singer()//删除选手
{
	list *p = head,*q=head;
	int num;
	if (head == NULL)
		cout << "Warning:链表为空" << endl;

	cout << "请输入你要删除的选手编号:";
	cin >> num;
	
	//检测选手编号是否存在存在
	try {
		test_num(num*1.0);
	}
	catch (int)
	{
		cout << "没有此编号" << endl;
		Sleep(500);
		return;
	}
	catch (double)
	{
		cout << "该编号不符合规则" << endl;
		Sleep(500);
		return;
	}

	//遍历链表,因为删除某一节点,需使前一节点指向删除节点所指向的节点,故声明q,记录前一节点
	while (num!=p->data.getNumber()&&p->next!= NULL)
	{
		q = p;
		p = p->next;
	}
	if (num == p->data.getNumber())
	{
		//分为删除头结点,与删除中间节点两种
		if (p == head)
		{
			head = head->next;
			delete p;
			cout << "成功删除选手数据" << endl; 
		}
		else
		{
			q->next = p->next;
			delete p;
			cout << "成功删除选手数据" << endl;
		}
	}
}

bool SingerList::outfile()//输出数据
{
	list *p = head;
	string na,stu,s,c,so;
	int n, sum,a,rank;
	double  average;

	cout << "请问是否要保存信息(1:继续保存 0:返回上一界面)" << endl;
	cin >> n;
	if (n == 0)
		return false;
	else if (n != 1)
	{
		cout << "输入错误,默认返回上一界面" << endl;
		return false;
	}

	//输出选手数据
	cout << "现将保存选手数据,请输入文件名(建议输入:选拔赛结果 或 总决赛结果):";
	cin >> s;
	ofstream out;
	out.open(s + ".dat");
	//遍历链表
	while (p != NULL)
	{
		na = p->data.getName();//姓名
		n = p->data.getNumber();//编号
		stu = p->data.getStudent_id();//学号
		so = p->data.getSong();//参赛歌曲
		s = p->data.getSex();//性别
		a = p->data.getAge();//年龄
		c = p->data.getCollege();//所属学院
		sum = p->data.getSum_score();//总分
		average = p->data.getAverage_score();//平均分
		rank = p->data.getRanking();//排名
		out.precision(2);
		out << na << " " << n << " " << stu << " " << so << " " << s << " "
			<< a << " " << c << " " << sum << " " << average << " " << rank << endl;
		p = p->next;
	}
	cout << endl << "保存选手数据成功" << endl;


	//输出评委打分信息
	out.close();//关闭文件
	cout << "现将保存评委打分信息,请输入文件名:" << endl;
	cin >> s;
	out.open(s + ".dat");
	p = head;
	while (p != NULL)
	{
		const node *q = p->data.getJudge();
		n = p->data.getNumber();//编号
		out << "选手编号:" << n << endl; 
		for (int i = 0;i < 10;i++)
		{
			out << "评委:" << (q + i)->name << "打分:" << (q + i)->score << endl;
		}
		p = p->next;
	}
	cout << "保存评委信息成功" << endl;
	out.close(); // 关闭文件

	cout << "\n提示:按任意键返回";
	_getch();

	return true;
}

void SingerList::mark_score()//评委打分
{
	list  *p = head;
	string name,song;
	int num, sum;

	//遍历链表
	while (p != NULL)
	{
		name = p->data.getName();
		num = p->data.getNumber();
		sum = p->data.getSum_score();//用于检测是否已经评分
		song = p->data.getSong();
		if (sum == 0)
		{
			cout << "歌手姓名:" << setw(6) << name << "\t编号: " << setw(3) << num << "\t参赛歌曲: " << setw(6) << song << endl;

			p->data.mark();//调用Singer类方法
			p = p->next;
		}
		else
		{
			cout << "歌手姓名: " << setw(6) << name << "\t编号:" << setw(3) << num << " 已经完成评分" << endl;
			p = p->next;
		}
	}
	cout << "\n提示:按任意键返回";
	_getch();
}

void SingerList::statistics()
{
	// 数据统计
	list *p = head;
	string s;
	int t;
	/*
	cout << " ● ●---------------------------------------------------------- ● ●" << endl;
	cout << "             1：根据性别                2：根据年龄                   " << endl;
	cout << "             3: 根据学院                4: 根据总分                   " << endl;
	cout << "             5: 根据平均分              6: 根据名次                   " << endl;
	cout << "                                        0: 返回上一界面               " << endl;
	cout << " ● ●---------------------------------------------------------- ● ●" << endl;
	*/
	cout << "请输入你的操作:";
	cin >> t;
	if (t == 0)
	{
		return;
	}
	switch (t)
	{
	case 1:
		cout << "请输入: male 或 female: ";
		cin >> s;
		cout << "姓名\t编号\t学号\t\t总分\t平均分\t名次" << endl;
		while (p != NULL)//遍历链表
		{
			if(p->data.getSex()==s)
				cout << p->data;//调用singer类中流运算符重载
			p = p->next;
		}
		cout << "姓名\t学号\t\t参赛歌曲\t年龄\t性别\t学院" << endl;
		p = head;
		while (p != NULL)
		{
			if (p->data.getSex() == s)
				p->data.display();//调用的是singer 类中的display'
			p = p->next;
		}
		break;
	case 2:
		cout << "请输入年龄(建议20,21,22,23): ";
		cin >> t;
		cout << "姓名\t编号\t学号\t\t总分\t平均分\t名次" << endl;
		while (p != NULL)
		{
			if (p->data.getAge() == t)
				cout << p->data;
			p = p->next;
		}
		cout << "姓名\t学号\t\t参赛歌曲\t年龄\t性别\t学院" << endl;
		p = head;
		while (p != NULL)
		{
			if (p->data.getAge() == t)
				p->data.display();//调用的是singer 类中的display'
			p = p->next;
		}
		break;
	case 3:
		cout << "请输入学院(建议:计算机,理学院,经贸,人文,环境,化工,建工,机械,法学,外国语): ";
		cin >> s;
		cout << "姓名\t编号\t学号\t\t总分\t平均分\t名次" << endl;
		while (p != NULL)
		{
			if (p->data.getCollege() == s)
				cout << p->data;
			p = p->next;
		}
		cout << "姓名\t学号\t\t参赛歌曲\t年龄\t性别\t学院" << endl;
		p = head;
		while (p != NULL)
		{
			if (p->data.getCollege() == s)
				p->data.display();//调用的是singer 类中的display'
			p = p->next;
		}
		break;
	case 4:
		cout << "请输入总分(结果为大于等于该值得数据): ";
		cin >> t;
		cout << "姓名\t编号\t学号\t\t总分\t平均分\t名次" << endl;
		while (p != NULL)
		{
			if (p->data.getSum_score() >= t)
				cout << p->data;
			p = p->next;
		}
		cout << "姓名\t学号\t\t参赛歌曲\t年龄\t性别\t学院" << endl;
		p = head;
		while (p != NULL)
		{
			if (p->data.getSum_score() >= t)
				p->data.display();//调用的是singer 类中的display'
			p = p->next;
		}
		break;
	case 5:
		cout << "请输入平均分(结果为大于等于该值得数据): ";
		cin >> t;
		cout << "姓名\t编号\t学号\t\t总分\t平均分\t名次" << endl;
		while (p != NULL)
		{
			if (p->data.getAverage_score() >= t)
				cout << p->data;
			p = p->next;
		}
		cout << "姓名\t学号\t\t参赛歌曲\t年龄\t性别\t学院" << endl;
		p = head;
		while (p != NULL)
		{
			if (p->data.getAverage_score() >= t)
				p->data.display();//调用的是singer 类中的display'
			p = p->next;
		}
		break;
	case 6:
		cout << "请输入名次(结果为小于等于该值得数据): ";
		cin >> t;
		cout << "姓名\t编号\t学号\t\t总分\t平均分\t名次" << endl;
		while (p != NULL)
		{
			if (p->data.getRanking() <= t)
				cout << p->data;
			p = p->next;
		}
		cout << "姓名\t学号\t\t参赛歌曲\t年龄\t性别\t学院" << endl;
		p = head;
		while (p != NULL)
		{
			if (p->data.getRanking() <= t)
				p->data.display();//调用的是singer 类中的display'
			p = p->next;
		}
		break;
	default:cout << "输入错误!!!" << endl;
	}
	cout << "\n提示:按任意键返回";
	_getch();
}

list * SingerList::gethead()const//访问函数,返回链表头指针
{
	return head;
}

void SingerList::rank_list()//排名
{
	list *p = head;
	int count=1;
	cout << "姓名\t编号\t学号\t\t总分\t平均分\t名次" << endl;
	while (p != NULL)
	{
		p->data.inputRanking(count);
		count++;
		cout << p->data;
		p = p->next;
	}
	cout << "\n提示:按任意键返回";
	_getch();
}

SingerList::~SingerList()//析构函数
{
	list *p = head;
	if (p == NULL)
	{
		return;//链表为空,不用处理
	}
	while (p!=NULL)
	{
		list *temp = p->next;
		delete p;
		p = temp;
	}
	num.clear();
	ID.clear();
}
// 用于根据选手成绩快速排序的函数
void QuickSort(list* pBegin, list* pEnd)
{
	/*
	这两个指针均往next方向移动，移动的过程中保持p之前的key都小于选定的key，
	p和q之间的key都大于选定的key，那么当q走到末尾的时候便完成了一次支点的寻找。
	*/
	if (pBegin != pEnd)
	{
		Singer key = pBegin ->data;
		list* p = pBegin;
		list* q = p->next;
		Singer temp;

		while (q != pEnd)
		{
			if (q->data.getAverage_score() > key.getAverage_score())
			{
				//值交换
				p = p->next;
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
			else if (q->data.getAverage_score() == key.getAverage_score())//如果平均分相同,根据总分,PS:若总分也相同,那就是比赛机制问题
			{
				if (q->data.getSum_score() > key.getSum_score())
				{
					//值交换
					p = p->next;
					temp = p->data;
					p->data = q->data;
					q->data = temp;
				}
			}
			q = q->next;
		}

		temp = p->data;
		p->data = pBegin->data;
		pBegin->data = temp;
		
		// 运用分治法
		QuickSort(pBegin, p);
		QuickSort(p->next, pEnd);
	}
}
