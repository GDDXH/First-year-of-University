#include"SingerList.h"
#include"Load.h"
#include"contest.h"
using namespace std;
int main()
{
	Load::Load_UI();//使用Load的静态函数
	while (1)
	{
		int choose;
		choose = Load::choose_UI();//使用Load的静态函数
		if (choose == 1)
		{
			bool flag;
			SingerList singerlist;
			singerlist.creat_UI();//界面函数
			flag = singerlist.creat_list();//读入数据,建立链表
			if (!flag)
				continue;
			singerlist.test_num();//检测编号是否重复
			singerlist.infile_judge();//读书评委数据

			bool outfile_flag = false;
			//保存选手信息表则为true,否则为false,用处:当我执行其他操作时会修改数据,此时若退出系统,会有提示:数据未保存
			while (1)
			{
				int t = singerlist.main_UI();//主界面函数


				if (t == 0)//选择 0 则退出系统,同时检测数据是否保存,未保存,则提醒
				{
					if (!outfile_flag)
					{
						cout << "Warning:数据未保存" << endl
							<< "继续执行请输入 1 否则输入 0   :";
						cin >> t;
						if (t == 0)
							continue;
					}
					break;
				}
				switch (t)
				{
						//完善信息
					case 1:singerlist.add_information();outfile_flag = false;break;
						//评委评分
					case 2:
						srand((unsigned)time(0));// 为便于测试程序使用随机数
						singerlist.sort_number();
						singerlist.mark_score();
						outfile_flag = false;break;

						//成绩排序
					case 3:	
						if (singerlist.test_score(singerlist.gethead()))//检测选手是否已经评分
						{
							QuickSort(singerlist.gethead(), NULL);
							singerlist.rank_list();
							outfile_flag = false;
						}
						break;

						//查询功能
					case 4:
						singerlist.seek_UI();//界面函数
						singerlist.seek();break;

						//追加选手
					case 5:	singerlist.add_singer();
						outfile_flag = false;break;

					//修改选手数据
					case 6:
						singerlist.modify_UI();//界面函数
						singerlist.modify();
						outfile_flag = false;break;

					//显示选手数据
					case 7:	singerlist.print_list();break;

						//输出数据
					case 8:
						singerlist.statistics_UI();//界面函数
						singerlist.statistics();break;
					case 9:outfile_flag = singerlist.outfile();
						break;

					default:cerr << "您输入错误,请重新输入" << endl;Sleep(3000);break;
				}//switch()结束
			}//if(choose ==1)中的while(1)结束

		}//if(choose ==1)结束
		else if (choose == 2)
		{
			int t;
			Contest contest;
			t = contest.input_UI();//选择输入选拔赛or总决赛的界面
			if (t == 0)//选择返回上一届面
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
					case 1:contest.add_information();break;//完善比赛信息
					case 2:contest.display();break;//显示比赛信息
					case 3:contest.statisticsDisplay();break;//显示数据统计结果
					case 4:contest.finalcontestList();break;//显示决赛名单
					case 5:contest.saveKData();break;
					default:cerr << "您输入错误,请重新输入" << endl;Sleep(3000);break;
					}
				}//while(1)结束
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
								default:cerr << "您输入错误,请重新输入" << endl;Sleep(3000);break;
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
			}	//else结束
		}// else if(choose ==2 )结束

	}//while(1)结束
	return 0;
}
