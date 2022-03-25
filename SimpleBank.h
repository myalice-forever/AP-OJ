#pragma once
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
class SimpleBank {
	vector<int> b;
	int len;
	vector<int> p;
	vector<int> q;
	int count;
public:
	SimpleBank(const int* balance, int length) {
		len = length;
		for (int i =0 ;i < len; i++)
			b.push_back(balance[i]);
		count = 0;
	}
	~SimpleBank() {
		;
		}
		// Îö¹¹º¯Êý
	bool transfer(int account1, int account2, int money) {
		if (account1 <= len && account2 <= len) {
			if (b[account1 - 1] >= money) {
				b[account2 - 1] += money;
				b[account1 - 1] -= money;
				count++;
				q.push_back(count);
				q.push_back(account1);
				q.push_back(account2);
				q.push_back(money);
				return true;
			}
		}
		return false;
	}
	bool deposit(int account, int money) {
		if (account <= len) {
			b[account - 1] += money;
			count++;
			p.push_back(count);
			p.push_back(account);
			p.push_back(money);
			return true;
		}
		return false;
	}
	bool withdraw(int account, int money) {
		if (account <= len|| b[account - 1]>=money){
			b[account - 1] -= money;
			count++;
			p.push_back(count);
			p.push_back(account);
			int temp = -money;
			p.push_back(temp);
			return true;
		}
		return false;
	}
	int operator[](int account) const {
		if (account > len&&account<=0)
			return -1;
		return b[account - 1];
	}
	SimpleBank& operator=(const SimpleBank& s) {
		if (&s == this)
			return *this;
		b = s.b;
		p = s.p;
		q = s.q;
		count = s.count;
		len = s.len;
		return *this;
	}
	bool resize(int count);
	bool rollback(int number);
};