#include "MySatur.h"
void mySatur::print() const {
	if (flag) printf("*");
	myClass::print();
}
mySatur mySatur::operator+(const mySatur& a) const {
	myClass res = ::operator+(*this, a);
	return mySatur(res);
}
mySatur mySatur::operator-(const mySatur& a) const{
	myClass res = ::operator-(*this, a);
	return mySatur(res);
}
mySatur mySatur::operator*(const mySatur& a) const {
	myClass res = ::operator*(*this, a);
	return mySatur(res);
}

