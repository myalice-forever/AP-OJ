#include<iostream>
#include "SimpleBank.h"
using namespace std;
bool SimpleBank::resize(int count) {
	// ���ݲ�������ԭ����n���˻���չ��count���˻���
// �� count>n ʱ��Ҫ��ԭ�����ݲ��䣬���ݵ����˻�����Ϊ0��������true��ʾִ�гɹ��� ���򷵻�false��ʾ
//ִ��ʧ�ܡ�
	if (count <= len)
		return false;
	for (int i = 0; i < count - len; i++) {
		b.push_back(0);
	}
	return true;
}
bool SimpleBank::rollback(int number) {
	// �ع��������ع� number ���ɹ���ת�ˡ���ȡ�����
// �� number > Ŀǰϵͳ�Ѿ���¼�µ� �ɹ�ת�ˡ������ȡ��������� ʱ����ִ���κβ���������false��
// ���򣬻ع���� number ���ɹ���ת�ˡ������ȡ�����������true��
// ** �ر����� ��ֵ���������� ��Ҳ��Ҫ��������ʷһͬ���� **
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