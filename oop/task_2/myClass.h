#pragma once
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
class myClass {
protected:
	int c, d;
public:
	myClass(double v) {
		c = (int)v;
		d = (int)(round((v - c) * 10000));
	}
	myClass(int cl, int drb) {
		c = cl;
		d = drb;
		if (d >= 10000) {
			c += d / 10000;
			d %= 10000;
		}
		else if (d <= -10000) {
			c += d / 10000;
			d = d % 10000;
		}
	};
	friend myClass operator+ (myClass a, myClass b);
	friend myClass operator- (myClass a, myClass b);
	friend myClass operator* (myClass a, myClass b);

	void print();
	int get_value_c() const { return c; };
	int get_value_d() const { return d; };
};
myClass operator+ (myClass a, myClass b);
myClass operator- (myClass a, myClass b);
myClass operator* (myClass a, myClass b);
