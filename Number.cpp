#include<iostream>
#include "Number.h"
#include<algorithm>
using namespace std;
Number Number:: operator +(const Number& number) {
	Number new_num;
	delete[]new_num.num;
	int temp = 0;
	int* t= new int[max(number.len, len)+1];
	int* p = new int[len]; int* q = new int[number.len];
	for (int i = 0; i < len; i++)
		p[len - 1 - i] = num[i];
	for (int i = 0; i < number.len; i++)
		q[number.len - 1 - i] = number.num[i];//倒序输入
	for (int i = 0; i < max(number.len, len); i++) {
		if (i < number.len && i < len) {
			*t= (*p + *q+temp) %10;
			int tp=(*p + *q+temp) / 10;
			temp = tp;
			p++; q++; t++;
		}
		else if (i < number.len && i >= len) {
			*t= *q+temp;
			temp = 0;
			t++; q++;
		}
		else {
			*t= *p+temp;
			temp = 0; t++; p++;
		}
	}
	if (number.len == len && temp > 0) {
		*t = temp;
		new_num.len = len + 1;
		new_num.num = new int[len + 1];
	}
	else {
		t--;//t指针停机时指向了未初始化的位置
		new_num.len = max(number.len, len);
		new_num.num = new int[max(number.len, len)];
	}
	for (int i = 0; i < new_num.len; i++) {
		new_num.num[i] = *t;//倒序输入
		t--;
	}
	return new_num;
}
Number Number:: operator *(const Number& number) {
	Number new_num;
	int* p = new int[len]; int* q = new int[number.len];
	int len1 = len, len2 = number.len;
	for (int i = 0; i < len; i++)
		p[i] = num[len - 1 - i];
	for (int i = 0; i < number.len; i++)
		q[i] = number.num[number.len - 1 - i];
	int* ans = new int[len1 + len2];
	for (int i = 0; i < len1 + len2; i++)
		ans[i] = 0;//初始化内存，设为0
	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < len2; j++) {
			ans[i + j ] += p[i] * q[j];
		}
	}//乘法
	for (int i = 0; i < len1 + len2-1; i++) {
		while (ans[i] >= 10) {
			ans[i + 1] += ans[i] / 10;
			ans[i] %= 10;
		}
	}//统一处理进位
	if (num[0] == 0 || number.num[0] == 0)
		return new_num;
	delete []new_num.num;
	if (ans[len1 + len2-1 ] == 0) {
		new_num.len = len1 + len2-1;
		new_num.num = new int[new_num.len];
	}
	else {
		new_num.len = len1 + len2;
		new_num.num = new int[new_num.len];
	}//判断new_num.len
	for (int i = 0; i < new_num.len; i++)
		new_num.num[i] = ans[new_num.len - 1 - i];//倒序输出
	return new_num;
}
bool Number:: operator <(const Number& number) {
	int* p = new int[len]; int* q = new int[number.len];
	for (int i = 0; i < len; i++)
		p[len - 1 - i] = num[i];
	for (int i = 0; i < number.len; i++)
		q[number.len - 1 - i] = number.num[i];
	if (len < number.len)
		return true;
	else if (len > number.len)
		return false;
	for (int i = 0; i < len; i++) {
			if (p[i] < q[i])
				return true;
			else if (p[i] > q[i])
				return false;
	}
	return false;
}
void showNumber(const Number& number) {
	for (int i = 0; i < number.len; i++)
		cout << number.num[i];
	cout << endl;
}
