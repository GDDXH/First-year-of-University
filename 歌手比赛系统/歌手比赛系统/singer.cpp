#include"singer.h"
Singer::Singer() :Student(),Judge()//���캯��
{
	song = "δ����";
	sum_score = 0;
	average_score = 0;
	ranking = 0;
	flag = false;
}
Singer::Singer(const Singer & temp)://�������캯��
	Student(temp.name, temp.age, temp.sex,temp.student_id,temp.college),Judge(temp.judge)//student��Ĺ��캯��
{
	    const node * p = temp.judge;
		song = temp.song;
		number = temp.number;
		sum_score = temp.sum_score;
		average_score = temp.average_score;
		ranking = temp.ranking;
		flag = temp.flag;	
}

Singer::~Singer(){}
void Singer::calculation()//�����ܷ���ƽ����
{
	
	for (int i = 1;i < 9;i++)
		sum_score += judge[i].score;
	average_score = sum_score / 8;
	sum_score += judge[0].score + judge[9].score;
}  
void Singer::mark()//��ί���
{
	//int t;
	cout << "PS:������ 0 -- 100 ֮�������" << endl << endl;
	for (int i = 0;i < 10;i++)
	{
		// ���������,���ڼ�����
		judge[i].score = rand() % 20 + 80;
		cout << judge[i].name << "��ί�����֣�" << judge[i].score << endl;;
		/*
		//�ֶ���������
		cin >> t;
		if (t >= 0 && t <= 100)
		{
			judge[i].score = t;
		}
		else
		{
			cout << "�������,����������" << endl;
			i--;
		}
		*/
	}
	calculation();
	cout << endl << "�ܳɼ���" << sum_score << "\tƽ���֣�" << average_score << endl << endl;
}
void Singer::input(string na, int n, string stu, string so, string s, int a, string c)
{
	//�޸ĺ���,�����ļ���������ʱ(������Ϣ),������ֵ
	name = na;//����
	number = n;//���
	student_id = stu;//ѧ��
	song = so;//��������
	sex = s;//�Ա�
	age = a;//����
	college = c;//ѧԺ
}
void Singer::input(string s,int n)
{	
	//�޸ĺ���,�����ļ���������ʱ(δ������Ϣ),������ֵ
	name = s;//����
	number = n;//���
}


void Singer::inputRanking(int r)
{
	//�޸ĺ���,���ڳɼ������,��ѡ������
	ranking = r;

}
void Singer::inputSong(string s)
{
	//�޸ĺ���,��ѡ�ֲ���������ֵ
	song = s;
}

void Singer::inputFlag(bool b)
{
	//��ѡ����Ϣ����,�� flag = true ,else flag = false
	flag = b;
}
int Singer::getNumber()const
{
	//���ʺ���,���ر��
	return number;
}
int  Singer::getSum_score() const
{
	//���ʺ���,�����ܷ�
	return sum_score;
}
double Singer::getAverage_score() const
{
	//���ʺ���,����ƽ����
	return average_score;
}
int Singer::getRanking() const
{
	//���ʺ���,��������
	return ranking;
}
string Singer::getSong() const
{
	//���ʺ���,���ز�������
	return song;
}

void Singer::display_judge()
{
	// ��ʾ�������,�����ί�����Ϣ
	for (int i = 0;i < 10;i++)
	{
		cout << judge[i].name << "��ί���:" << judge[i].score << endl; 
	}
}
void Singer::display()
{
	cout.setf(ios::left);
	//cout << "����\tѧ��\t\t��������\t����\t�Ա�\tѧԺ" << endl;
	cout << name << "\t" << student_id << "\t" << setw(8) << song << "\t" << age << "\t" << sex << "\t" << college << endl;
}

bool Singer::getFlag() const
{
	// //���ʺ���,����flag(��ѡ����Ϣ����,�� flag = true ,else flag = false)
	return flag;
}

ostream &operator<<(ostream &output, Singer &temp)
{	
	// �����������,���������������
	output.precision(2);
	//cout<< "����\t���\tѧ��\t�ܷ�\tƽ����\t����" << endl;
	output <<setw(4)<<temp.name << "\t" <<setw(2)<< temp.number << "\t"
		<< setw(12) << temp.student_id<<"\t"<<setw(3) << temp.sum_score << "\t"
		<< fixed <<temp.average_score<< "\t��" << temp.ranking << "��" << endl;
	return output;
}

