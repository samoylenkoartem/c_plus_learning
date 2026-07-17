#include "myClass.h"
void myClass::print() {
	printf("%.4f[%d,%d]", c + d / 10000.0, c, abs(d));
}
myClass operator+ (myClass a, myClass b) {
	long long total = (long long)a.c * 10000 + a.d + (long long)b.c * 10000 + b.d;
	int c = total / 10000;
	int d = total % 10000;
	return myClass(c, d);
}
myClass operator- (myClass a, myClass b) {
	long long total = (long long)a.c * 10000 + a.d - ((long long)b.c * 10000 + b.d);
	int c = total / 10000;
	int d = total % 10000;
	return myClass(c, d);
}
myClass operator* (myClass a, myClass b) {
	long long left = (long long)a.c * 10000 + a.d;
	long long right = (long long)b.c * 10000 + b.d;
	long long prod = left * right;
	int c = prod / 10000 / 10000;
	int d = (prod / 10000) % 10000;
	return myClass(c, d);
}
