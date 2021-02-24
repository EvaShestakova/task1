#include "CVector.h"
#include "Temp.h"

class Temp;

void CVector::Clean() { delete[] v; SetZero(); }
void CVector::SetZero() { v = NULL; n = 0; }

CVector::CVector(const CVector& b) { CopyOnly(b); }

CVector& CVector::operator=(const CVector& b) {
	if (this != &b) {
		Clean(); CopyOnly(b); 
	}
	return *this;
}

CVector::CVector(const double* b, int n) {
	this->n = n;
	v = new double[n];
	for (int i = 0; i < n; i++) v[i] = b[i];
}

void CVector::CopyOnly(const CVector& b) { 
	n = b.n; 
	v = new double[n];
	for (int i = 0; i < n; i++) v[i]=b[i];
}

void CVector::print() {
	for (int i = 0; i < n; i++) printf("%f ", v[i]);
}

int CVector::length()const { return n; }
double* CVector::vector()const{ return v; }

/*CVector CVector::operator+(const CVector& b) {
	if (n > b.n) {
		double* d = new double[n];
		b[n - 1] = 0;
		for (int i = 0; i < n; i++) d[i] = v[i] + b[i];
		CVector* res(d, n);
		delete[] d;
		return res;
	}
	if (n < b.n) {
		double* d = new double[n];
		v[b.n-1] = 0;
		for (int i = 0; i < b.n; i++) d[i] = v[i] + b[i];
		CVector res(d, n);
		delete[] d;
		return res;
	}
	if (n = b.n) {
		double* d = new double[n];
		for (int i = 0; i < n; i++) d[i]=v[i]+b[i];
		CVector res(d,n);
		delete[] d;
		return res;
	}
}
CVector CVector::operator-(const CVector& b) {
	if (n != b.n) {
		printf("Error. Incorrect length\n");
		return *this;
	}
	else {
		double* d = new double[n];
		for (int i = 0; i < n; i++) d[i] = v[i] - b[i];
		CVector res(d, n);
		delete[] d;
		return res;
	}
}*/
double& CVector::operator[](int i) const{
	if (i < 0 || i>=n) {
		printf("Error.Incorrect index\n");
		throw - 4;
	}
	return v[i];
}
double CVector::operator*(const CVector& b) {
	if (n != b.n) {
		printf("Error. Incorrect length\n");
		return 0;
	}
	else {
		double res=0;
		for (int i = 0; i < n; i++) res+=v[i]*b[i];
		return res;
	}
}


Temp CVector::operator[](int i) {
	if (i < 0) {
		throw - 1;
	}
	return Temp(this, i);
}