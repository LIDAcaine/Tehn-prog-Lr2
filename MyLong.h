#pragma once
#include <iostream>

using namespace std;
class myLong
{
	long* value;
public:
	explicit myLong(long a); //конструктор с параметром
	myLong(); //конструктор без параметра
	myLong(const myLong& a); //конструктор копирования
	~myLong(); //деструктор

	myLong& operator --(int);
	myLong& operator --();
	long operator !() const;
	friend myLong& operator ++(myLong& op, int);
	friend myLong& operator ++(myLong& op);
	friend ostream& operator <<(ostream& stream, myLong& a);
};