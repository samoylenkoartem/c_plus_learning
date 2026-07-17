#pragma once
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
class myClass {
protected:
	int c, d;
public:
	myClass() {
        c = 0;
        d = 0;
    }
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

	void print() const;
};
myClass operator+ (myClass a, myClass b);
myClass operator- (myClass a, myClass b);
myClass operator* (myClass a, myClass b);

