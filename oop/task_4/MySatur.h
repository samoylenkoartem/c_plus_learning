//mySatur.h
#pragma once
#include "MyClass.h"
class mySatur : public myClass {
private:
	bool flag;
	void applyLimit() {
		flag = false;
		if (c >= 100000) {
			c = 99999;
			d = 9999;
			flag = true;
		}
		else if (c <= -100000) {
			c = -99999;
			d = -9999;
			flag = true;
		}
	}
public:
	mySatur() : myClass(0.0) {
		applyLimit();
	}
	mySatur(double v) : myClass(v) {
		applyLimit();
	}
	mySatur(int cl, int drb) : myClass(cl, drb) {
		applyLimit();
	}
	mySatur(myClass& a) : myClass(a) {
		applyLimit();
	}
	void print() const;

	mySatur operator+(const mySatur& a) const;
	mySatur operator-(const mySatur& a) const;
	mySatur operator*(const mySatur& a) const;
};

