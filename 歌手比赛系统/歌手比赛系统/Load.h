#pragma once
#include"person.h"
// ��¼����
class Load
{
public:
	static void initialization();//��̬����,����:���ļ��ж���password����ֵ
	static void inputPassword(string);//��̬����,����:�ı�����
	static void Load_UI();//��̬����,����:��¼����
	static int choose_UI();//ѡ����溯��,����:ѡ����Ϣ���� or ������Ϣ����
protected:
	static string password;//��̬��Ա����,��¼����
};
