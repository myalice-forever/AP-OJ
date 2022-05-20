#pragma once
#include<iostream>
#include<string>
#include<list>
#include<limits.h>
#include<algorithm>
using namespace std;
template<class T>
class Document {
public:
	int fd;
	list<T> items;
public:
	Document(int fd, const Document<T>& doc) {
		this->fd = fd;
		items = list<T>(doc.items);
	}
	Document(int fd, string rawString);
	~Document() {
		;
	}
	void addItem(T item) {
		items.push_back(item);
	}
	void removeItem(int index) {
			if (index >= items.size())
				throw (string)"Index out of bound.";
			typename list<T>::iterator it = items.begin();
			for (int i = 0; i < index; i++)
				it++;
		items.erase(it);
	}
	T& operator[](int index) {
			if (index > items.size())
				throw (string) "Index out of bound.";;
		typename list<T>::iterator it=items.begin();
		for (int i = 0; i < index; i++)
			it++;
		return *it;
	}
	bool operator==(const Document<T>& doc) {
		if (fd != doc.fd)
			return false;
		if (items.size() != doc.items.size())
			return false;
		int flag = 0;
		list<T> sort_this=items;
		list<T> sort_other = doc.items;
		sort_this.sort(); sort_other.sort();
		typename list<T>::iterator it2 = sort_other.begin();
		typename list<T>::iterator it1 = sort_this.begin();
		for (int i = 0; i < items.size(); i++) {
				if (*it1 != *it2)
					return false;
				it1++; it2++;
		}
		return true;
	}
	friend ostream& operator<<(ostream& output, const Document<T>& doc) {
		output << doc.fd << ":[";
		list<T> temp = doc.items;
		typename list<T>::iterator it = temp.begin();
		for (; it != temp.end(); it++) {
			if (it != temp.begin())
				output << "," << *it;
			else
				output << *it;
		}
		output << "]";
		return output;
	}
};
template<>
Document<int>::Document(int fd, string rawString) {
	if (rawString.size() == 0)
		throw (string)"Item cannot be null.";
	this->fd = fd;
	int num = count(rawString.begin(), rawString.end(), ',');
	for (int i = 0; i <= num; i++) {
		int fir = rawString.find(',');
		string temp = rawString.substr(0, fir);
		if(temp.size()==0)
			throw (string)"Item cannot be null.";
		int temp_num = atoi(temp.c_str());
		rawString = rawString.substr(fir + 1, INT_MAX);
		items.push_back(temp_num);
	}
}
template<>
Document<string>::Document(int fd, string rawString) {
	this->fd = fd;
	int num = count(rawString.begin(), rawString.end(), ',');
	for (int i = 0; i <= num; i++) {
		int fir = rawString.find(',');
		string temp = rawString.substr(0, fir);
		if (temp.size() == 0)
			throw (string)"Item cannot be null.";
		rawString = rawString.substr(fir + 1, INT_MAX);
		items.push_back(temp);
	}
}