#include<iostream>
#include<string>
#include<vector>
#include "Robot.h"
using namespace std;
Robot::Robot(int x, int y, int energy) {
	this->x = x;
	this->y = y;
	this->energy = energy;
	type = 0;
}

Robot::~Robot() {
	this->showStatus();
}

int Robot::move(char direction) {
	if (energy <= 0) {
		return 0;
	}
	if (direction == 'E') {
		x += 1;
	}
	else if (direction == 'N') {
		y += 1;
	}
	else if (direction == 'W')
		x -= 1;
	else if (direction == 'S')
		y -= 1;
	energy -= 1;
	return 1;
}

int Robot::fill(int energyy) {
	this->energy += energyy;
	return energyy;
}

void Robot::showStatus() {
	cout << "Type[" << type << "],Energy[" << energy << "],Position[" << x << "," << y << "]\n";
}

SuperRobot1::SuperRobot1(int x, int y, int z, int energy):Robot(x,y,energy) {
	this->z = z;
	this->typee = 1;
}

SuperRobot1::~SuperRobot1() {
	this->showStatus();
}

int SuperRobot1::move(char direction, int pace) {
	if (pace <= 0||energy<=0)
		return 0;
	if (energy >= pace) {
		if (direction == 'E') {
			x += pace;
		}
		else if (direction == 'N') {
			y += pace;
		}
		else if (direction == 'W')
			x -= pace;
		else if (direction == 'S')
			y -= pace;
		else if (direction == 'U')
			z += pace;
		else if (direction == 'D')
			z -= pace;
		energy -= pace;
		return pace;
	}
	else if (energy <= pace) {
		int temp = energy;
		if (direction == 'E') {
			x += energy;
		}
		else if (direction == 'N') {
			y += energy;
		}
		else if (direction == 'W')
			x -= energy;
		else if (direction == 'S')
			y -= energy;
		else if (direction == 'U')
			z += energy;
		else if (direction == 'D')
			z -= energy;
		energy = 0;
		return temp;
	}
}
int SuperRobot1::move(char direction) {
	if (energy <= 0) {
		return 0;
	}
	if (direction == 'E') {
		x += 1;
	}
	else if (direction == 'N') {
		y += 1;
	}
	else if (direction == 'W')
		x -= 1;
	else if (direction == 'S')
		y -= 1;
	energy -= 1;
	return 1;
}

int SuperRobot1::giveEnergy(Robot* robot, int energyy) {
	this->energy -= energyy;
	robot->energy += energyy;
	return energyy;
}
void SuperRobot1::showStatus() {
	cout << "Type[" << typee << "],Energy[" << energy << "],Position[" << x << "," << y <<','<<z<< "]\n";
}


SuperRobot2::SuperRobot2(int x, int y, int z, int energy) :Robot(x,y,energy){
	this->z = z;
	typeee = 2;
}
SuperRobot2::~SuperRobot2() {
	this->showStatus();
}
int SuperRobot2::move(int x_d, int y_d, int z_d) {
	int temp = energy;
	if (energy <= abs(x_d)) {
		if (x_d < 0)
			x -= energy;
		else
			x += energy;
		energy = 0;
		return temp;
	}
	x += x_d;
	energy -= abs(x_d);
	if (energy <= abs(y_d)) {
		if (y_d < 0)
			y -= energy;
		else
			y += energy;
		energy = 0;
		return temp;
	}
	energy -= abs( y_d);
	y += y_d;
	if (energy <= abs(z_d)) {
		if (z_d < 0)
			z -= energy;
		else
			z += energy;
		energy = 0;
		return temp;
	}
	z += z_d;
	energy -=abs( z_d);
	return abs(z_d) + abs(x_d) + abs(y_d);
}
int SuperRobot2::move(char direction) {
	if (energy <= 0) {
		return 0;
	}
	if (direction == 'E') {
		x += 1;
	}
	else if (direction == 'N') {
		y += 1;
	}
	else if (direction == 'W')
		x -= 1;
	else if (direction == 'S')
		y -= 1;
	energy -= 1;
	return 1;
}

void SuperRobot2::showStatus() {
	cout << "Type[" << typeee << "],Energy[" << energy << "],Position[" << x << "," << y << ',' << z << "]\n";
}