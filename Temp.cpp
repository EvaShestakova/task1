#include "Temp.h"
#include "CVector.h"
class CVector;

Temp& Temp::operator=(double c) {
	if (i < 0)throw - 3;
	if (i >= v->n) {
		double* q = new double[i + 1];
		for (int j = 0; j < v->n; j++) {
			q[j] = v->v[j];
		}
		for (int j = v->n; j < i; j++) {
			q[j] = 0;
		}
		v->n = i + 1;
		delete[] v->v;
		v->v = q;
	}
	v->v[i] = c;
	return*this;
}
Temp::operator double() {
	if (i < 0)throw - 2;
	if (i >= v->n)return 0;
	return v->v[i];
}