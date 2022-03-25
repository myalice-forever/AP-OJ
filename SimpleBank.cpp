#include<iostream>
#include "SimpleBank.h"
using namespace std;
bool SimpleBank::resize(int count) {
	// 扩容操作。将原来的n个账户拓展到count个账户。
// 当 count>n 时，要求原有数据不变，扩容的新账户余额均为0，并返回true表示执行成功。 否则返回false表示
//执行失败。
	if (count <= len)
		return false;
	for (int i = 0; i < count - len; i++) {
		b.push_back(0);
	}
	return true;
}
bool SimpleBank::rollback(int number) {
	// 回滚操作。回滚 number 个成功的转账、存款、取款操作
// 当 number > 目前系统已经记录下的 成功转账、存款与取款操作总数 时，不执行任何操作并返回false。
// 否则，回滚最近 number 个成功的转账、存款与取款操作并返回true。
// ** 特别提醒 赋值操作符重载 中也需要将操作历史一同复制 **
	if (number > count) {
		return false;
	}
	for (; number > 0; number--, count--) {
		int flag = 0;
		for (int i = 0; i < p.size();i+=3) {
			if (p[i] == count) {
				b[p[i + 1]-1] -= p[i + 2];
				p[i] = -1;
				flag = 1;
				p.pop_back();
				p.pop_back();
				p.pop_back();
			}
		}
		for (int i = 0; i < q.size()&&flag==0; i+=4) {
			if (q[i] == count) {
				b[q[i + 1]-1] += q[i + 3];
				b[q[i + 2]-1] -= q[i + 3];
				q[i] = -1;
				flag = 1;
				q.pop_back();
				q.pop_back();
				q.pop_back();
				q.pop_back();
			}
		}
	}
	return true;
}