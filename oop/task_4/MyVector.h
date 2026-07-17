#pragma once
#include "MySatur.h"
#include <iostream>
using namespace std;

template <typename T>
class myVector {
private:
	T* v;
	int sz;
public:
	myVector() {
		sz = 99;
		v = new T[sz];
		if (v == 0) throw "Error:Out of Memory!";
	}
	
	myVector(int s) {
		if (s < 1) throw "Error:Input size is Wrong!";
		sz = s;
		v = new T[sz];
		if (v == 0) throw "Error:Out of Memory!";
	}
	
	
	myVector(const myVector<T>& a){
		sz = a.sz;
		v = new T[sz];
		if (v == 0) throw "Error:Out of Memory!";
		for (int i = 0; i < sz; i++) {
			v[i] = a.v[i];
		}
	}
	
	~myVector() {
		delete[] v;
	}

	
	myVector<T>& operator=(const myVector<T>& a) {
		if (this == &a) return *this;
		delete[] v;
		sz = a.sz;
		v = new T[sz];
		if (v == 0) throw "Error:Out of Memory!";
		for (int i = 0; i < sz; i++) {
			v[i] = a.v[i];
		}
		return *this;
	}
			
	T& operator[](int i) {
		if (i < 0 || i >= sz) throw "Error:Wrong index!";
		return v[i];
	}

	
	myVector<T> operator+(const myVector<T>& a) const {
		if (sz != a.sz) throw "Error:Vectors have different sizes!";
		myVector<T> sum(sz);
		for (int i = 0; i < sz; i++) {
			sum.v[i] = v[i] + a.v[i];
		}
		return sum;
	}


	inline int size() const { return sz; };
	inline T& elem(int i) { return v[i]; };
	inline const T& elem(int i) const { return v[i]; };

	void print() const {
		cout << "Vector(" << sz << "): [";
		for (int i = 0; i < sz; i++) {
			print_elem(v[i]);
			if (i - sz + 1 != 0) cout << ',';
		}
		cout << ']' << endl;
	}
	
	void print_elem(const T& elem) const;
};

template <typename T>
void myVector<T>::print_elem(const T& elem) const {
	cout << elem;
}

template <>
void myVector<mySatur>::print_elem(const mySatur& elem) const {
	elem.print();
}


template <typename T>
myVector<T> operator-(const myVector<T>& a, const myVector<T>& b) {
	if (a.size() != b.size()) throw "Error:Vectors have different sizes!";
	int s = a.size();
	myVector<T> sub(s);
	for (int i = 0; i < s; i++) {
		sub.elem(i) = a.elem(i) - b.elem(i);
	}
	return sub;
}