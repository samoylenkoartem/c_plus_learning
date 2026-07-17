#define _CRT_SECURE_NO_WARNINGS
#include "MyVector.h"

int main() {
    try {
        myVector<mySatur> v1(5);
        v1[0] = mySatur(132.5123);
        v1[1] = mySatur(223.5965);
        v1[2] = mySatur(3656.56565);
        v1[3] = mySatur(4345.58034);
        v1[4] = mySatur(52340.50924);

        printf("v1: ");
        v1.print();

        myVector<int> v3(5), v2(5);
        for (int i = 0; i < 5; i++) {
            v2[i] = (i + 1) * 10;
        }
        v2.print();
        for (int i = 0; i < 5; i++) {
            v3[i] = i + 1;
        }
        v3.print();

        myVector<int> v4 = v2 + v3;
        printf("v2 + v3: ");
        v4.print();
        printf("\n");


        myVector<double> v5(3), v6(3);
        v5[0] = 1.5; v5[1] = 2.7; v5[2] = 3.9;
        v6[0] = 0.5; v6[1] = 1.3; v6[2] = 2.1;
        v5.print();
        v6.print();

        myVector<double> v7 = v5 + v6;
        printf("v5 + v6: ");
        v7.print();


        myVector<mySatur> v8(3);
        v8[0] = mySatur(100001.0);
        v8[1] = mySatur(50000.0);
        v8[2] = mySatur(-100001.0);

        printf("\nSaturation: ");
        v8.print();
        myVector<int> v(0);   
        myVector<int> Ar(5);  
        Ar[10] = 10;
        
    }
    catch (const char* message) {
        printf("%s", message);
        exit(1);
    }
    printf("\n");
        return 0;
    }

