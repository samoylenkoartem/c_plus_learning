#define _CRT_SECURE_NO_WARNINGS
#include "vector.h"

int main() {
	myVector v1;
	v1[0] = mySatur(-100000.5);
	v1[1] = mySatur(100000.3);
	printf("v1: ");
	v1.print();

	myVector v2(5);
	v2[0] = mySatur(1.5);
	v2[1] = mySatur(2.5);
	v2[2] = mySatur(3.5);
	v2[3] = mySatur(4.5);
	v2[4] = mySatur(5.5);
	printf("v2: ");
	v2.print();

	myVector v3(v2);
	printf("v3: ");
	v3.print();

	myVector v4;
	v4 = v2;
	printf("v4: ");
	v4.print();


	myVector v5(3), v6(3);
	v5[0] = mySatur(10.1);
	v5[1] = mySatur(20.2);
	v5[2] = mySatur(30.3);

	v6[0] = mySatur(1.1);
	v6[1] = mySatur(2.2);
	v6[2] = mySatur(3.3);

	myVector v7 = v5 + v6;
	myVector v8 = v5 - v6;

	printf("v5 + v6: ");
	v7.print();
	printf("v5 - v6: ");
	v8.print();

	return 0;
}
	
