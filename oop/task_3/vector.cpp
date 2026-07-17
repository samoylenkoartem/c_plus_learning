//vector.cpp
#include "vector.h"
myVector::myVector() {
	sz = 99;
	v = new mySatur[sz];
	if (v == 0) error("Error:Out of memory!");
}

myVector::myVector(int s) {
	if (s < 1) error("Error:Input size is Wrong");
	sz = s;
	v = new mySatur[sz];
	if (v == 0) error("Error:Out of memory!");
}

myVector::~myVector() { delete[] v; };

myVector::myVector(const myVector& a) {
	sz = a.size();
	v = new mySatur[sz];
	if (v == 0) error("Error:Out of memory!");
	for (int i = 0; i < sz; i++) {
		elem(i) = a.elem(i);
	}
}

myVector& myVector::operator=(const myVector& a) {
	if (this != &a) {
		if (sz == a.sz) {
			for (int i = 0; i < sz; i++) {
				elem(i) = a.elem(i);
			}
		}
		else {
			delete[]v;
			sz = a.size();
			v = new mySatur[sz];
			if (v == 0) error("Error:Out of memory!");
			for (int i = 0; i < sz; i++) {
				elem(i) = a.elem(i);
			}
		}
	}
	return *this;
}

mySatur& myVector::operator[](int i) {
	if (i < 0 || i >= sz)error("Error:Wrong Index");
	return v[i];
}
myVector myVector::operator+(const myVector& a) const {
	if (sz != a.sz) error("Error:Vectors have different sizes");
	myVector sum(sz);
	for (int i = 0; i < sz; i++) {
		sum.elem(i) = elem(i) + a.elem(i);
	}
	return sum;
}

myVector operator-(const myVector& a, const myVector& b) {
	if (a.size() != b.size()) error("Error:Vectors have different sizes");
	int s = a.size();
	myVector sub(s);
	for (int i = 0; i < s; i++) {
		sub.elem(i) = a.elem(i) - b.elem(i);
	}
	return sub;
}

void myVector::print() const {
	printf("Vector(size = %d): [", sz);
	for (int i = 0; i < sz; i++) {
		elem(i).print();
		if (i - sz + 1 != 0) printf(",");
	}
	printf("]\n");
}
void error(const char* p) {
	printf("%s", p);
}
