#pragma once
#include<iostream>
using namespace std;
class Employee {
public:
	double bs;
	double price;
	Employee* band;
	unsigned int id;
public:
	static unsigned int totalEmployee;
	Employee(unsigned int id, double basicsalary, double price, Employee* bandemployee);
	double getPrice();
	unsigned int getID() const;
	void setBandEmployee(Employee* employee);
	Employee& operator+=(int salemoney);
	virtual double computeSalary();
	virtual void showStatus();
};

class SuperEmployee:public Employee {
public:
	int level;
public:
	SuperEmployee(unsigned int id, double basicsalary, double price,\
		Employee* bandemployee, int level);
	double computeSalary();
	void showStatus();
};

class Manager :public Employee {
public:
	int workyear;
public:
	Manager(int id, double basicsalary, double price, Employee* bandemployee, int workyear);
	double computeSalary();
	void showStatus();
};