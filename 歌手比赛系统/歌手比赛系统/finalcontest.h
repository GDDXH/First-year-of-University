#pragma once
#include"c_basis.h"
#include"player.h"
//�ܾ�����
class FinalContest :virtual public C_basis, virtual  public Player
{
public:
	FinalContest();
	void inputTopTensinger();//����ʮ�Ѹ���
	void displayTopTensinger();//��ʾʮ�Ѹ���
	void inputPresenter();//�����ܾ���������
	void inputAudience();//���������
	int getAudience();//���ʺ���
	void inputDepartment();//������벿��
	void inputSpend();//������鿪��
	void displayDS();
protected:
	Singer TopTensinger[10];//ʮ�Ѹ���
	Student Presenter[2];//������
	vector<string>department;//��֯ʮ�Ѹ����ܾ��������ٰ����ز���������
	vector<string>spend;//Ϊ�ٰ�ʮ�Ѹ��ִ����Ŀ���
	int  audience;//����
};