#pragma once
#include"person.h"
//�����Ļ�����Ϣ
class C_basis
{
public:
	C_basis() { name = "δ����";when = "δ����";where = "δ����"; };//���캯��
	void inputWhen(string);
	void inputWhere(string);
	void inputName(string);//�޸ĺ���
	string getName()const;//���ʺ���
protected:
	string name;//��������
	string when;//����ʱ��
	string where;//�����ص�
};