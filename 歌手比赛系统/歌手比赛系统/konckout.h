#pragma once
#include"c_basis.h"
#include"player.h"
//ѡ������
class Konckout:virtual public C_basis, virtual public Player
{
public:
	Konckout();
	void statistics();//����ͳ��
	void statisticsDisplay();//��ʾ����ͳ�ƽ��
	void finalcontestList();//��ʾ��Χ�ܾ�������
protected:

	map<string, int> CollegeStatistics;//ͳ�Ƹ�ѧԺ��������
	map<int, int> AgeStatistics;//ͳ�Ƹ������������
	map<string, int>SexStatistics;//ͳ����Ů��������
	Singer Fsinger[20];//����ѡ��
};