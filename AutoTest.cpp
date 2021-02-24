#include "CVector.h"
#include "CVectorHori.h"
void AutoTest() {
    double* a = new double[1];
    double* b = new double[1];
    a[0] = 0;
    b[0] = 1;
    CVectorHori A(a, 1);
    CVectorHori B(b, 1);
    CVectorHori C;
    C = A + B;
    if (C.vector()[0] == 1) {
        printf("Autotest passed.\n");
    }
    else {
        printf("Autotest failed.\n");
    }
}