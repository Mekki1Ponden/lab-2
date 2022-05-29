#pragma once

#include <iostream>
#include <windows.h>
#include <ctime>

#ifndef LIST_H
#define LIST_H

struct Item { int data; Item* next; };

class List {
private:
	Item* head_, * tail_;
public:
	List() : head_(nullptr), tail_(nullptr) { }
	List(int, ...);
	List(const List&);

	void random(int = 10, int = -100, int = 100);
	int size() const;
	bool isEmpty() const;
	void pushFront(int);
	void pushBack(int);
	int popFront();
	int popBack();
	int front() const;
	int back() const;
	int* getArray() const;
	void clear();

	friend std::istream& operator>> (std::istream&, List&);
	friend std::ostream& operator<< (std::ostream&, const List&);

	friend bool operator>  (const List& l1, const List& l2) { return (l1.size() > l2.size()); }
	friend bool operator<  (const List& l1, const List& l2) { return (l1.size() < l2.size()); }
	friend bool operator== (const List& l1, const List& l2) { return (l1.size() == l2.size()); }
	friend bool operator!= (const List& l1, const List& l2) { return (l1.size() != l2.size()); }
	friend bool operator>= (const List& l1, const List& l2) { return (l1.size() >= l2.size()); }
	friend bool operator<= (const List& l1, const List& l2) { return (l1.size() <= l2.size()); }

	List& operator++();
	List& operator--();
	List& operator++(int);
	List& operator--(int);

	int operator[](int);
	List operator()(int, int);

	List& operator= (const List&);
	friend List operator+ (const List&, const List&);
	friend List operator- (const List&, const List&);
	friend List operator* (const List&, const List&);
	friend List operator/ (const List&, const List&);

	~List() { clear(); }
};
#endif LIST_H