#pragma once
#include"c_basis.h"
#include"player.h"
//总决赛类
class FinalContest :virtual public C_basis, virtual  public Player
{
public:
	FinalContest();
	void inputTopTensinger();//读入十佳歌手
	void displayTopTensinger();//显示十佳歌手
	void inputPresenter();//输入总决赛主持人
	void inputAudience();//输入观众数
	int getAudience();//访问函数
	void inputDepartment();//输入参与部门
	void inputSpend();//输入读书开销
	void displayDS();
protected:
	Singer TopTensinger[10];//十佳歌手
	Student Presenter[2];//主持人
	vector<string>department;//组织十佳歌手总决赛大赛举办的相关部门与社团
	vector<string>spend;//为举办十佳歌手大赛的开销
	int  audience;//观众
};