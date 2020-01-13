#include"SingerList.h"
#include"Load.h"
#include"contest.h"
using namespace std;
int main()
{
	Load::Load_UI();//ʹ��Load�ľ�̬����
	while (1)
	{
		int choose;
		choose = Load::choose_UI();//ʹ��Load�ľ�̬����
		if (choose == 1)
		{
			bool flag;
			SingerList singerlist;
			singerlist.creat_UI();//���溯��
			flag = singerlist.creat_list();//��������,��������
			if (!flag)
				continue;
			singerlist.test_num();//������Ƿ��ظ�
			singerlist.infile_judge();//������ί����

			bool outfile_flag = false;
			//����ѡ����Ϣ����Ϊtrue,����Ϊfalse,�ô�:����ִ����������ʱ���޸�����,��ʱ���˳�ϵͳ,������ʾ:����δ����
			while (1)
			{
				int t = singerlist.main_UI();//�����溯��


				if (t == 0)//ѡ�� 0 ���˳�ϵͳ,ͬʱ��������Ƿ񱣴�,δ����,������
				{
					if (!outfile_flag)
					{
						cout << "Warning:����δ����" << endl
							<< "����ִ�������� 1 �������� 0   :";
						cin >> t;
						if (t == 0)
							continue;
					}
					break;
				}
				switch (t)
				{
						//������Ϣ
					case 1:singerlist.add_information();outfile_flag = false;break;
						//��ί����
					case 2:
						srand((unsigned)time(0));// Ϊ���ڲ��Գ���ʹ�������
						singerlist.sort_number();
						singerlist.mark_score();
						outfile_flag = false;break;

						//�ɼ�����
					case 3:	
						if (singerlist.test_score(singerlist.gethead()))//���ѡ���Ƿ��Ѿ�����
						{
							QuickSort(singerlist.gethead(), NULL);
							singerlist.rank_list();
							outfile_flag = false;
						}
						break;

						//��ѯ����
					case 4:
						singerlist.seek_UI();//���溯��
						singerlist.seek();break;

						//׷��ѡ��
					case 5:	singerlist.add_singer();
						outfile_flag = false;break;

					//�޸�ѡ������
					case 6:
						singerlist.modify_UI();//���溯��
						singerlist.modify();
						outfile_flag = false;break;

					//��ʾѡ������
					case 7:	singerlist.print_list();break;

						//�������
					case 8:
						singerlist.statistics_UI();//���溯��
						singerlist.statistics();break;
					case 9:outfile_flag = singerlist.outfile();
						break;

					default:cerr << "���������,����������" << endl;Sleep(3000);break;
				}//switch()����
			}//if(choose ==1)�е�while(1)����

		}//if(choose ==1)����
		else if (choose == 2)
		{
			int t;
			Contest contest;
			t = contest.input_UI();//ѡ������ѡ����or�ܾ����Ľ���
			if (t == 0)//ѡ�񷵻���һ����
			{
				continue;
			}
		
			if (t == 1)
			{
				contest.inputKSinger();
				contest.statistics();
				while (1)
				{
					t = contest.Konckout_UI();
					if (t == 0)
					{
						break;
					}
					switch (t)
					{
					case 1:contest.add_information();break;//���Ʊ�����Ϣ
					case 2:contest.display();break;//��ʾ������Ϣ
					case 3:contest.statisticsDisplay();break;//��ʾ����ͳ�ƽ��
					case 4:contest.finalcontestList();break;//��ʾ��������
					case 5:contest.saveKData();break;
					default:cerr << "���������,����������" << endl;Sleep(3000);break;
					}
				}//while(1)����
			}
			else//t==2
			{
				contest.inputFSinger();
				contest.inputTopTensinger();
				while (1)
				{
					t = contest.Finalcontest_UI();
					if (t == 0)
					{
						break;
					}
					if (t == 1)
					{
						while (1)
						{
							int temp = contest.addInformation_UI();
							if (temp == 0)
								break;
							switch (temp)
							{
								case 1:contest.add_information();break;
								case 2:contest.inputPresenter();break;
								case 3:contest.inputDepartment();break;
								case 4:contest.inputSpend();break;
								case 5:contest.inputAudience();break;
								default:cerr << "���������,����������" << endl;Sleep(3000);break;
							}
						}
					}
					else if (t == 2)
					{
						contest.displayDS();
					}

					else 
						contest.saveFData();
				}
			}	//else����
		}// else if(choose ==2 )����

	}//while(1)����
	return 0;
}
