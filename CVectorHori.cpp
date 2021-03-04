#include "CVectorHori.h"

int CVectorHori::output(const string FileName)
{
	ofstream fout(FileName,ios_base::app);
	for (int i = 0; i < n; ++i) {
		fout << v[i] << ' ';
	}
	fout << '\n';
	fout.close(); 
    return 0;
}

CVectorHori operator+(const CVector& a, const CVector& b) {
	if (a.n > b.n) {
		double* d = new double[a.n];
		b[a.n - 1] = 0;
		for (int i = 0; i < a.n; i++) d[i] = a.v[i] + b[i];
		CVectorHori res(d, a.n);
		delete[] d;
		return res;
	}
	if (a.n < b.n) {
		double* d = new double[a.n];
		a.v[b.n - 1] = 0;
		for (int i = 0; i < b.n; i++) d[i] = a.v[i] + b[i];
		CVectorHori res(d, a.n);
		delete[] d;
		return res;
	}
	if (a.n == b.n) {
		double* d = new double[a.n];
		for (int i = 0; i < a.n; i++) d[i] = a.v[i] + b[i];
		CVectorHori res(d, a.n);
		delete[] d;
		return res;
	}
}
CVectorHori operator-(const CVector& a, const CVector& b) {
	if (a.n != b.n) {
		printf("Error. Incorrect length\n");
		return a;
	}
	else {
		double* d = new double[a.n];
		for (int i = 0; i < a.n; i++) d[i] = a.v[i] - b[i];
		CVectorHori res(d, a.n);
		delete[] d;
		return res;
	}
}