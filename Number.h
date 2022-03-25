#pragma once
#ifndef NUMBER
#define NUMBER
#include<iostream>
#include<cmath>
using namespace std;
class Number {
	int len;
	int* num;
public:
	Number() {
		len = 1;
		num = new int[1];
		num[0] = 0;
	}
	Number(char* s, int length) {
		len = length;
		num= new int[len];
		for (int i = 0; i < len; i++)
			num[i] = s[i]-'0';
	}
	Number(const Number& number) {
		len = number.len;
		num = new int[len];
		for (int i = 0; i < len; i++)
			num[i] = number.num[i];
	}
	~Number() {
		delete[]num;
		num = nullptr;
	}
	Number operator +(const Number& number);
	Number operator *(const Number& number);
	bool operator <(const Number& number);
	friend void showNumber(const Number& number);
};
#endif