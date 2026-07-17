//vector.h
#pragma once
#include "mySatur.h"
class myVector {
protected:
	mySatur* v;
	int sz;
public:
	myVector();
	myVector(int s);
	myVector(const myVector& a);
	~myVector();

	myVector& operator=(const myVector& a);
	mySatur& operator[](int s);
	myVector operator+(const myVector& a) const;

	inline int size() const { return sz; };
	inline mySatur& elem(int i) const { return v[i]; };

	void print() const;
};
void error(const char* p);

myVector operator-(const myVector& a, const myVector& b);
