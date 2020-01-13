#include"SingerList.h"
SingerList::SingerList():Test(),SLoad()//���캯��
{
	head = NULL;	
}
bool SingerList::creat_list()//��������
{
	// ѡ����Ϣ����ͨ���ļ�����
	string na,stu,so,s,c;
	int n,a;
	list *p, *next_p;
	head = NULL;
	p = new list, next_p = new list;

	/*
	cout << " �� ��---------------------------------------------------------- �� ��" << endl;
	cout << "             1���ļ�����(��Ϣδ����)    2���ļ�����(��Ϣ������)       " << endl;
	cout << "                                        0: ������һ����               " << endl;
	cout << " �� ��---------------------------------------------------------- �� ��" << endl;
	*/
	cout << "��������Ĳ�����";
	cin >> n;
	if (n == 0)
	{
		return false;
	}
    else if (n != 1 && n != 2)
	{
		cerr << "Warning:�������!!!"<<endl;
		abort();
	}
	else if (n == 1)
	{
		cout << "�����ļ���:   ";
		cin >> s;
		cout << endl;
		ifstream infile;
		infile.open(s + ".dat");
		if (!infile.is_open())
		{
			system("cls");
			system("color 1F");
			cerr << "Error:�޷����ļ�"<< endl;
			abort();
		}

		if (infile >> na >> n )
		{
			if (n <= 0 || n > Size)
			{
				system("cls");
				system("color 1F");
				cerr << "�ļ���Ϣ����,�������" << endl;
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
					cerr << "�ļ���Ϣ����,�������" << endl;
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
			cout << "����ѡ����Ϣ��ɹ�" << endl;
			cout << "����:��������ѡ����Ϣ!!!" << endl;
		}
		else
		{
			system("cls");
			system("color 1F");
			cerr << "Warning:�ļ�Ϊ��,��������ʧ��!!!!!" << endl;
			abort();
		}
	}
	else if (n == 2)
	{
			cout << "PS:ѡ�������谴��������:��������š�ѧ�š������������Ա����䡢����ѧԺ" << endl;
			cout << "�����ļ���:   ";
			cin >> s;
			cout << endl;
			ifstream infile;
			infile.open(s + ".dat");
			if (!infile.is_open())
			{
				system("cls");
				system("color 1F");
				cerr << "Error:�޷����ļ�" << endl;
				abort();
			}
			if (infile >> na>>n>>stu>>so>>s>>a>>c)
			{
				if (n <= 0 || n > Size)
				{
					system("cls");
					system("color 1F");
					cerr << "�ļ���Ϣ����,�������" << endl;
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
						cout << "�ļ���Ϣ����,�������" << endl;
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
				cout << "����ѡ����Ϣ��ɹ�" << endl;
			}
			else
			{
				system("cls");
				system("color 1F");
				cerr << "Warning:�ļ�Ϊ��,��������ʧ��!!!!!" << endl;
				abort();
			}
	}
	return true;//��������ɹ�
}
void SingerList::infile_judge()//������ί
{
	list *p = head;
	string s[10];
	cout << "��ͨ���ļ�������ί��Ϣ" << endl;
	cout << "�����ļ���:   ";
	cin >> s[0];
	cout << endl;
	ifstream infile;
	infile.open(s[0] + ".dat");
	if (!infile.is_open())
	{
		system("cls");
		system("color 1F");
		cerr << "Error:�޷����ļ�,�������!!!" << endl;
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
	cout << "\n��ʾ:�����������";
	_getch();
}
void SingerList::add_information()//������Ϣ
{
	cout << "�ù���ģ��������ѡ�ֵ������Ϣ:��������,�Ա�,����,ѧ��,ѧԺ" << endl << endl;
	list *p = head;
	string s,c,id;
	bool sign = true;
	if (p == NULL)
	{
		cout << "Warning:ѡ����Ϣ����δ����!!!" << endl;
	}
	else
	{
		while (p != NULL) 
		{
			if (!p->data.getFlag())
			{
				cout << "ѡ������:" << p->data.getName() << "\tѡ�ֱ��:" << p->data.getNumber() << endl;
				cout << "�������������:";
				cin >> s;
				p->data.inputSong(s);
				cout << "���Ʋ���������Ϣ�ɹ�" << endl;

				p->data.inputSex();
				p->data.inputAge();

				while (sign)
				{
					sign = false;
					try {
						cout << "������ѧ��:";
						cin >> id;
						test_ID(id);
					}
					catch (int)
					{
						cout << "ѧ��" << id << "�Ѵ���" << endl;
						sign = true;
					}
					catch (double)
					{
						cout << "ѧ��" << id << "�����Ϲ���" << endl;
						sign = true;
					}
				}
				p->data.inputStudent_id(id);
				ID.push_back(id);
				cout << "���Ʋ���������Ϣ�ɹ�" << endl;

				cout << "������ѧԺ:";
				cin >> c;
				p->data.inputCollege(c);
				cout << "��������ѧԺ��Ϣ�ɹ�" << endl << endl << endl;
				p->data.inputFlag(true);
			}
			p = p->next;
		}
	}
	cout << "�ɹ���������ѡ����Ϣ" << endl;
	cout << "\n��ʾ:�����������";
	_getch();
}

void SingerList::print_list()//��������,��ʾѡ����Ϣ
{
	list *p = head;
	cout << "����\t���\tѧ��\t\t�ܷ�\tƽ����\t����" << endl;
	while (p != NULL)
	{
		cout << p->data;
		p = p->next;
	}
	cout << "����\tѧ��\t\t��������\t����\t�Ա�\tѧԺ" << endl;
	p = head;
	while (p != NULL)
	{
		Singer temp = p->data;
		Person *s = &temp;
		s->display();
		p = p->next;
	}
	if (head->data.getRanking() == 0)
		cout << "PS:ִ�гɼ����������,���ܿ�����ȷ����" << endl << endl;
	cout << "\n��ʾ:�����������";
	_getch();
}
void SingerList::sort_number()//��������
{
	//ð������,��ί���ʱ,Ӧ����ѡ�ֱ��˳��
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

void SingerList::seek()//��ѯ����
{
	list *p = head;
	string s;
	int num;
	bool flag = true;

	/*
	cout << " �� ��---------------------------------------------------------- �� ��" << endl;
	cout << "             1����������ѯ                  2������Ų�ѯ             " << endl;
	cout << "                                            0: ������һ����           " << endl;
	cout << " �� ��---------------------------------------------------------- �� ��" << endl;
	*/
	cout << "��������Ĳ�����";
	cin >> num;
	if (num == 0 )
	{
		return;
	}
	else if (num != 1 && num != 2)
	{
		cout << "Warning::�������!!!" << endl;
		Sleep(500);
		return;
	}
	else if (num == 1)
	{
		//ѡ�����������ظ�
		cout << "����������:";
		cin >> s;
		cout << "����Ϊ" << s << "�ĸ�����:" << endl;
		while (p != NULL)
		{
			string temp = p->data.getName();
			if (s == temp)
			{
				if (flag)
				{
					cout << "����\t���\tѧ��\t\t�ܷ�\tƽ����\t����" << endl;
					flag = false;
				}
				cout << p->data;
			}
			p = p->next;
		}
		if (flag)
			cout << "û���ҵ����ѡ����Ϣ" << endl;
		cout << "\n���ҽ���" << endl;
	}

	else if (num == 2)
	{
		// ��űض�Ϊһ
		cout << "��������:";
		cin >> num;
		try {
			flag = true;
			test_num(num*1.0);
		}
		catch (int)
		{
			cout << "û�д˱��" << endl;
			flag = false;
		}
		catch (double)
		{
			cout << "�ñ�Ų����Ϲ���" << endl;
			flag =false;
		}
		if(flag)//flag == true ���Ŵ���
			while (p != NULL)
			{
				int temp = p->data.getNumber();
				if (num == temp)
				{
					cout << "����\t���\tѧ��\t\t�ܷ�\tƽ����\t����" << endl;
					cout << p->data;
					cout << "����\tѧ��\t\t��������\t����\t�Ա�\tѧԺ" << endl;
					p->data.display();
					cout << "��������:" << endl;
					p->data.display_judge();
					break;
				}
				p = p->next;
			}
	}
	cout << "\n��ʾ:�����������";
	_getch();
}
void SingerList::modify()//�޸ĺ���
{
	int t;
	/*
	cout << " �� ��---------------------------------------------------------- �� ��" << endl;
	cout << "             1��ɾ��ѡ��                  2���޸�����                 " << endl;
	cout << "             3���޸��Ա�                  4���޸�����                 " << endl;
	cout << "             5: �޸Ĳ�������              6: �޸�ѧԺ                 " << endl;
	cout << "                                          0��������һ����             " << endl;
	cout << " �� ��---------------------------------------------------------- �� ��" << endl;
	*/
	cout << "���������ѡ��:";
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
				cout << "������ѡ�ֵı��:";
				cin >> num;
				test_num(num*1.0);
			}
			catch (int )
			{
				cout << "���" << num << "������" << endl;
				Sleep(500);
				return;
			}
			catch (double n)
			{
				cout << "���" << (int)n << "�����Ϲ���" << endl;
				Sleep(500);
				return;
			}

			cout << "����������" << endl;
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
			cout << "�޸ĳɹ�" << endl;
		}
	else if (t == 3)
	{
		int num;
		string  s;


		try {
			cout << "������ѡ�ֵı��:";
			cin >> num;
			test_num(num*1.0);
		}
		catch (int)
		{
			cout << "���" << num << "������" << endl;
			Sleep(500);
			return;
		}
		catch (double n)
		{
			cout << "���" << (int)n << "�����Ϲ���" << endl;
			Sleep(500);
			return;
		}
		cout << "�������Ա�(male or female)" << endl;
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
		cout << "�޸ĳɹ�" << endl;
	}
	else if (t == 4)
	{
		int num;
		int age;


		try {
			cout << "������ѡ�ֵı��:";
			cin >> num;
			test_num(num*1.0);
		}
		catch (int)
		{
			cout << "���" << num << "������" << endl;
			Sleep(500);
			return;
		}
		catch (double n)
		{
			cout << "���" << (int)n << "�����Ϲ���" << endl;
			Sleep(500);
			return;
		}
		cout << "����������" << endl;
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
		cout << "�޸ĳɹ�" << endl;
	}
	else if (t == 5)
	{
		int num;
		string  s;


		try {
			cout << "������ѡ�ֵı��:";
			cin >> num;
			test_num(num*1.0);
		}
		catch (int)
		{
			cout << "���" << num << "������" << endl;
			Sleep(500);
			return;
		}
		catch (double n)
		{
			cout << "���" << (int)n << "�����Ϲ���" << endl;
			Sleep(500);
			return;
		}
		cout << "�������������" << endl;
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
		cout << "�޸ĳɹ�" << endl;
	}
	else if (t == 5)//�޸�ѧԺ
	{
		int num;
		string  s;


		try {
			cout << "������ѡ�ֵı��:";
			cin >> num;
			test_num(num*1.0);
		}
		catch (int)
		{
			cout << "���" << num << "������" << endl;
			Sleep(500);
			return;
		}
		catch (double n)
		{
			cout << "���" << (int)n << "�����Ϲ���" << endl;
			Sleep(500);
			return;
		}
		cout << "������ѧԺ" << endl;
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
		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "�������,Ĭ�Ϸ���" << endl;
	}
	cout << "\n��ʾ:�����������";
	_getch();
}
void SingerList::add_singer()//׷��ѡ������
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
	cout << "����������ѡ�ֵ�����:";
	cin >> s[0];
	while (sign)
	{
		sign = false;
		try {
			cout << "����������ѡ�ֵı��:";
				cin >> n;
			test_num(n);
		}
		catch (int n)
		{
			cout << "���" << n << "�Ѵ���" << endl;
			sign = true;
		}
		catch (double n)
		{
			cout << "���" <<(int)n << "�����Ϲ���" << endl;
			sign = true;
		}
	}
	num.push_back(n);//��������ѡ�ֱ��
	add_p->data.input(s[0], n);//���������Ÿ�ֵ���µ�ѡ��

	//������ѡ�ָ�ֵ�����ί��Ϣ
	const node *temp = p->data.getJudge();
	for (int i = 0;i < 10;i++)
	{
		s[i] = (temp + i)->name;
	}
	add_p->data.inputJudge(s);

	p->next = add_p;
	p = add_p;
	p->next = NULL;
	cout << "׷��ѡ�ֳɹ�,������������ѡ����Ϣ" << endl;
	cout << "\n��ʾ:�����������";
	_getch();
}

void SingerList::delete_singer()//ɾ��ѡ��
{
	list *p = head,*q=head;
	int num;
	if (head == NULL)
		cout << "Warning:����Ϊ��" << endl;

	cout << "��������Ҫɾ����ѡ�ֱ��:";
	cin >> num;
	
	//���ѡ�ֱ���Ƿ���ڴ���
	try {
		test_num(num*1.0);
	}
	catch (int)
	{
		cout << "û�д˱��" << endl;
		Sleep(500);
		return;
	}
	catch (double)
	{
		cout << "�ñ�Ų����Ϲ���" << endl;
		Sleep(500);
		return;
	}

	//��������,��Ϊɾ��ĳһ�ڵ�,��ʹǰһ�ڵ�ָ��ɾ���ڵ���ָ��Ľڵ�,������q,��¼ǰһ�ڵ�
	while (num!=p->data.getNumber()&&p->next!= NULL)
	{
		q = p;
		p = p->next;
	}
	if (num == p->data.getNumber())
	{
		//��Ϊɾ��ͷ���,��ɾ���м�ڵ�����
		if (p == head)
		{
			head = head->next;
			delete p;
			cout << "�ɹ�ɾ��ѡ������" << endl; 
		}
		else
		{
			q->next = p->next;
			delete p;
			cout << "�ɹ�ɾ��ѡ������" << endl;
		}
	}
}

bool SingerList::outfile()//�������
{
	list *p = head;
	string na,stu,s,c,so;
	int n, sum,a,rank;
	double  average;

	cout << "�����Ƿ�Ҫ������Ϣ(1:�������� 0:������һ����)" << endl;
	cin >> n;
	if (n == 0)
		return false;
	else if (n != 1)
	{
		cout << "�������,Ĭ�Ϸ�����һ����" << endl;
		return false;
	}

	//���ѡ������
	cout << "�ֽ�����ѡ������,�������ļ���(��������:ѡ������� �� �ܾ������):";
	cin >> s;
	ofstream out;
	out.open(s + ".dat");
	//��������
	while (p != NULL)
	{
		na = p->data.getName();//����
		n = p->data.getNumber();//���
		stu = p->data.getStudent_id();//ѧ��
		so = p->data.getSong();//��������
		s = p->data.getSex();//�Ա�
		a = p->data.getAge();//����
		c = p->data.getCollege();//����ѧԺ
		sum = p->data.getSum_score();//�ܷ�
		average = p->data.getAverage_score();//ƽ����
		rank = p->data.getRanking();//����
		out.precision(2);
		out << na << " " << n << " " << stu << " " << so << " " << s << " "
			<< a << " " << c << " " << sum << " " << average << " " << rank << endl;
		p = p->next;
	}
	cout << endl << "����ѡ�����ݳɹ�" << endl;


	//�����ί�����Ϣ
	out.close();//�ر��ļ�
	cout << "�ֽ�������ί�����Ϣ,�������ļ���:" << endl;
	cin >> s;
	out.open(s + ".dat");
	p = head;
	while (p != NULL)
	{
		const node *q = p->data.getJudge();
		n = p->data.getNumber();//���
		out << "ѡ�ֱ��:" << n << endl; 
		for (int i = 0;i < 10;i++)
		{
			out << "��ί:" << (q + i)->name << "���:" << (q + i)->score << endl;
		}
		p = p->next;
	}
	cout << "������ί��Ϣ�ɹ�" << endl;
	out.close(); // �ر��ļ�

	cout << "\n��ʾ:�����������";
	_getch();

	return true;
}

void SingerList::mark_score()//��ί���
{
	list  *p = head;
	string name,song;
	int num, sum;

	//��������
	while (p != NULL)
	{
		name = p->data.getName();
		num = p->data.getNumber();
		sum = p->data.getSum_score();//���ڼ���Ƿ��Ѿ�����
		song = p->data.getSong();
		if (sum == 0)
		{
			cout << "��������:" << setw(6) << name << "\t���: " << setw(3) << num << "\t��������: " << setw(6) << song << endl;

			p->data.mark();//����Singer�෽��
			p = p->next;
		}
		else
		{
			cout << "��������: " << setw(6) << name << "\t���:" << setw(3) << num << " �Ѿ��������" << endl;
			p = p->next;
		}
	}
	cout << "\n��ʾ:�����������";
	_getch();
}

void SingerList::statistics()
{
	// ����ͳ��
	list *p = head;
	string s;
	int t;
	/*
	cout << " �� ��---------------------------------------------------------- �� ��" << endl;
	cout << "             1�������Ա�                2����������                   " << endl;
	cout << "             3: ����ѧԺ                4: �����ܷ�                   " << endl;
	cout << "             5: ����ƽ����              6: ��������                   " << endl;
	cout << "                                        0: ������һ����               " << endl;
	cout << " �� ��---------------------------------------------------------- �� ��" << endl;
	*/
	cout << "��������Ĳ���:";
	cin >> t;
	if (t == 0)
	{
		return;
	}
	switch (t)
	{
	case 1:
		cout << "������: male �� female: ";
		cin >> s;
		cout << "����\t���\tѧ��\t\t�ܷ�\tƽ����\t����" << endl;
		while (p != NULL)//��������
		{
			if(p->data.getSex()==s)
				cout << p->data;//����singer���������������
			p = p->next;
		}
		cout << "����\tѧ��\t\t��������\t����\t�Ա�\tѧԺ" << endl;
		p = head;
		while (p != NULL)
		{
			if (p->data.getSex() == s)
				p->data.display();//���õ���singer ���е�display'
			p = p->next;
		}
		break;
	case 2:
		cout << "����������(����20,21,22,23): ";
		cin >> t;
		cout << "����\t���\tѧ��\t\t�ܷ�\tƽ����\t����" << endl;
		while (p != NULL)
		{
			if (p->data.getAge() == t)
				cout << p->data;
			p = p->next;
		}
		cout << "����\tѧ��\t\t��������\t����\t�Ա�\tѧԺ" << endl;
		p = head;
		while (p != NULL)
		{
			if (p->data.getAge() == t)
				p->data.display();//���õ���singer ���е�display'
			p = p->next;
		}
		break;
	case 3:
		cout << "������ѧԺ(����:�����,��ѧԺ,��ó,����,����,����,����,��е,��ѧ,�����): ";
		cin >> s;
		cout << "����\t���\tѧ��\t\t�ܷ�\tƽ����\t����" << endl;
		while (p != NULL)
		{
			if (p->data.getCollege() == s)
				cout << p->data;
			p = p->next;
		}
		cout << "����\tѧ��\t\t��������\t����\t�Ա�\tѧԺ" << endl;
		p = head;
		while (p != NULL)
		{
			if (p->data.getCollege() == s)
				p->data.display();//���õ���singer ���е�display'
			p = p->next;
		}
		break;
	case 4:
		cout << "�������ܷ�(���Ϊ���ڵ��ڸ�ֵ������): ";
		cin >> t;
		cout << "����\t���\tѧ��\t\t�ܷ�\tƽ����\t����" << endl;
		while (p != NULL)
		{
			if (p->data.getSum_score() >= t)
				cout << p->data;
			p = p->next;
		}
		cout << "����\tѧ��\t\t��������\t����\t�Ա�\tѧԺ" << endl;
		p = head;
		while (p != NULL)
		{
			if (p->data.getSum_score() >= t)
				p->data.display();//���õ���singer ���е�display'
			p = p->next;
		}
		break;
	case 5:
		cout << "������ƽ����(���Ϊ���ڵ��ڸ�ֵ������): ";
		cin >> t;
		cout << "����\t���\tѧ��\t\t�ܷ�\tƽ����\t����" << endl;
		while (p != NULL)
		{
			if (p->data.getAverage_score() >= t)
				cout << p->data;
			p = p->next;
		}
		cout << "����\tѧ��\t\t��������\t����\t�Ա�\tѧԺ" << endl;
		p = head;
		while (p != NULL)
		{
			if (p->data.getAverage_score() >= t)
				p->data.display();//���õ���singer ���е�display'
			p = p->next;
		}
		break;
	case 6:
		cout << "����������(���ΪС�ڵ��ڸ�ֵ������): ";
		cin >> t;
		cout << "����\t���\tѧ��\t\t�ܷ�\tƽ����\t����" << endl;
		while (p != NULL)
		{
			if (p->data.getRanking() <= t)
				cout << p->data;
			p = p->next;
		}
		cout << "����\tѧ��\t\t��������\t����\t�Ա�\tѧԺ" << endl;
		p = head;
		while (p != NULL)
		{
			if (p->data.getRanking() <= t)
				p->data.display();//���õ���singer ���е�display'
			p = p->next;
		}
		break;
	default:cout << "�������!!!" << endl;
	}
	cout << "\n��ʾ:�����������";
	_getch();
}

list * SingerList::gethead()const//���ʺ���,��������ͷָ��
{
	return head;
}

void SingerList::rank_list()//����
{
	list *p = head;
	int count=1;
	cout << "����\t���\tѧ��\t\t�ܷ�\tƽ����\t����" << endl;
	while (p != NULL)
	{
		p->data.inputRanking(count);
		count++;
		cout << p->data;
		p = p->next;
	}
	cout << "\n��ʾ:�����������";
	_getch();
}

SingerList::~SingerList()//��������
{
	list *p = head;
	if (p == NULL)
	{
		return;//����Ϊ��,���ô���
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
// ���ڸ���ѡ�ֳɼ���������ĺ���
void QuickSort(list* pBegin, list* pEnd)
{
	/*
	������ָ�����next�����ƶ����ƶ��Ĺ����б���p֮ǰ��key��С��ѡ����key��
	p��q֮���key������ѡ����key����ô��q�ߵ�ĩβ��ʱ��������һ��֧���Ѱ�ҡ�
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
				//ֵ����
				p = p->next;
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
			else if (q->data.getAverage_score() == key.getAverage_score())//���ƽ������ͬ,�����ܷ�,PS:���ܷ�Ҳ��ͬ,�Ǿ��Ǳ�����������
			{
				if (q->data.getSum_score() > key.getSum_score())
				{
					//ֵ����
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
		
		// ���÷��η�
		QuickSort(pBegin, p);
		QuickSort(p->next, pEnd);
	}
}
