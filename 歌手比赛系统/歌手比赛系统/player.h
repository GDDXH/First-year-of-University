#pragma once
#include"singer.h"
class Player
{
public:
	Player();
	void inputPlayerNumber(int );//�޸ĺ���
	int getPlayerNumber();//���ʺ���
protected:
	int playerNumber;//��������
	vector<Singer> player_infomation;
};