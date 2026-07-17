#define _CRT_SECURE_NO_WARNINGS
#include "myClass.h"
int main() {
	double a = 1194.4332;
	double b = -1289.3212;

	myClass integersA(a);
	myClass integersB(b);

	integersA.print();
	integersB.print();
	printf("\n\n");

	myClass sum = integersA + integersB;
	myClass raz = integersA - integersB;
	myClass prz = integersA * integersB;

	printf("'+' ");
	sum.print();
	printf("\n");

	printf("'-' ");
	raz.print();
	printf("\n");

	printf("'*' ");
	prz.print();
	printf("\n");

	return 0;
}
