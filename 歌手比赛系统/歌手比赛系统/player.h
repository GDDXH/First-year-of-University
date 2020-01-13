#pragma once
#include"singer.h"
class Player
{
public:
	Player();
	void inputPlayerNumber(int );//修改函数
	int getPlayerNumber();//访问函数
protected:
	int playerNumber;//比赛人数
	vector<Singer> player_infomation;
};