#define _CRT_SECURE_NO_WARNINGS
#include "mySatur.h"
int main() {
	double a = 1194.4332;
	double b = -1289.3212;

	mySatur integersA(a);
	mySatur integersB(b);

	integersA.print();
	integersB.print();
	printf("\n\n");

	mySatur sum = integersA + integersB;
	mySatur raz = integersA - integersB;
	mySatur prz = integersA * integersB;

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








