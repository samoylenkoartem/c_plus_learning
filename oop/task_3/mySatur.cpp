//mySatur.cpp
#include "mySatur.h"
void mySatur::print() {
	if (flag) printf("* ");
	myClass::print();
}
mySatur mySatur::operator+(mySatur& a) {
	myClass res = ::operator+(*this, a);
	return mySatur(res);
}
mySatur mySatur::operator-(mySatur& a) {
	myClass res = ::operator-(*this, a);
	return mySatur(res);
}
mySatur mySatur::operator*(mySatur& a) {
	myClass res = ::operator*(*this, a);
	return mySatur(res);
}
