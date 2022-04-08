#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Robot {
public:
	int x;
	int y;
	int energy;
	int type;
public:
	Robot(int x, int y, int energy);
	virtual ~Robot();
	int move(char direction);
	int fill(int energy);
	virtual void showStatus();
};

class SuperRobot1 :public Robot {
public:
	int z;
	int typee;
public:
	SuperRobot1(int x, int y, int z, int energy);
	~SuperRobot1();
	int move(char direction, int pace);
	int move(char direction);
	int giveEnergy(Robot* robot, int energy);
	void showStatus();
};

class SuperRobot2 :public Robot {
public:
	int z;
	int typeee;
public:
	SuperRobot2(int x, int y, int z, int energy);
	~SuperRobot2();
	int move(char direction);
	int move(int x_d, int y_d, int z_d);
	void showStatus();
};