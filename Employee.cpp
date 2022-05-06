#include<iostream>
#include<iomanip>
#include "Employee.h"
using namespace std;
unsigned int Employee::totalEmployee = 0;
Employee::Employee(unsigned int _id, double _basicsalary, double _price, Employee* _bandemployee) {
	id = _id;
	bs = _basicsalary;
	price = _price;
	band = _bandemployee;
	totalEmployee++;
}
double Employee::getPrice() {
	return price;
}
unsigned int Employee::getID() const {
	return id;
}
void Employee::setBandEmployee(Employee* employee) {
	band = employee;
}
Employee& Employee::operator+=(int salemoney) {
	if (salemoney <= 5000 && salemoney >= 0) {
		price += 0.02 * salemoney;
		return *this;
	}
	price += 0.02 * 5000;
	salemoney -= 5000;
	if (salemoney <= 5000) {
		price += salemoney * 0.04;
		return *this;
	}
	price += 5000 * 0.04;
	salemoney -= 5000;
	price += salemoney * 0.08;
	return *this;
}
double Employee::computeSalary() {
	if (!band)
		return price + bs;
	return price + bs + 0.1 * band->price;
}
void Employee::showStatus() {
	if (!band) {
		cout << "ID:" << id << ", basicSalary:" << fixed << setprecision(1) << bs << ", price:" << price << ", bandID:" << -1 << endl;
		return;
	}
	cout << "ID:" << id << ", basicSalary:" << fixed << setprecision(1) << bs << ", price:" << price << ", bandID:" << band->id << endl;

}

SuperEmployee::SuperEmployee(unsigned int id, double basicsalary, double price,Employee* bandemployee, int level):\
Employee(id, basicsalary, price, bandemployee) {
	this->level = level;
}
double SuperEmployee::computeSalary() {
	if (!band) {
		return bs + price + price * level * 0.1;
	}
	return bs + price + 0.1 * band->price + price * level * 0.1;
}
void SuperEmployee::showStatus() {
	std::cout << setiosflags(ios::fixed) << setprecision(1);
	if (!band) {
		cout << "ID:" << id << ", basicSalary:"<< bs << ", price:" << price << ", bandID:" << -1 << ", level:" << level << endl;
		return;
	}
	cout << "ID:" << id << ", basicSalary:" << bs << ", price:" << price << ", bandID:" << band->id << ", level:" << level << endl;

}

Manager::Manager(int id, double basicsalary, double price, Employee* bandemployee, int workyear):\
Employee(id, basicsalary, price, bandemployee) {
	this->workyear = workyear;
}
double Manager::computeSalary() {
	if(!band)
		return bs + price + workyear*300;
	return bs + price + 0.1 * band->price + workyear * 300;
}
void Manager::showStatus() {
	std::cout << setiosflags(ios::fixed) << setprecision(1);
	if (!band) {
		cout << "ID:" << id << ", basicSalary:" << bs << ", price:" << price << ", bandID:" << -1 << ", workYear:" << workyear << endl;
		return;
	}
	cout << "ID:" << id << ", basicSalary:" << bs << ", price:" << price << ", bandID:" << band->id << ", workYear:" << workyear << endl;

}