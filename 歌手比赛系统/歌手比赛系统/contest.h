#pragma once
#include"konckout.h"
#include"finalcontest.h"
#include"CLoad.h"
//������
class Contest :public Konckout, public FinalContest, public CLoad
{
public:
	Contest();
	void inputKSinger();//����ѡ����ѡ������
	void inputFSinger();//�������ѡ������
	void add_information();//��������
	string getHost()const;//���ʺ���
	string getSponsor()const;//���ʺ���
	void inputHost(string);//�޸ĺ���
	void inputSponsor(string);//�޸ĺ���
	void display();//��ʾ�������
	void saveKData();//���ѡ������Ϣ
	void saveFData();//���������Ϣ
protected:
	string host;//�����ٰ췽
	string sponsor;//����������
};