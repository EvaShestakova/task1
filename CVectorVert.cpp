#include "CVectorVert.h"

int CVectorVert::output(const string FileName)
{
	ofstream fout(FileName, ios_base::app);
	for (int i = 0; i < n; ++i) {
		fout << v[i] << '\n';
	}
	fout << '\n';
	fout.close();
	return 0;
}

CVectorVert CVectorVert::operator+(const CVectorVert& b) {
	if (n > b.n) {
		double* d = new double[n];
		b[n - 1] = 0;
		for (int i = 0; i < n; i++) d[i] = v[i] + b[i];
		CVectorVert res(d, n);
		delete[] d;
		return res;
	}
	if (n < b.n) {
		double* d = new double[n];
		v[b.n - 1] = 0;
		for (int i = 0; i < b.n; i++) d[i] = v[i] + b[i];
		CVectorVert res(d, n);
		delete[] d;
		return res;
	}
	if (n = b.n) {
		double* d = new double[n];
		for (int i = 0; i < n; i++) d[i] = v[i] + b[i];
		CVectorVert res(d, n);
		delete[] d;
		return res;
	}
}
CVectorVert CVectorVert::operator-(const CVectorVert& b) {
	if (n != b.n) {
		printf("Error. Incorrect length\n");
		return *this;
	}
	else {
		double* d = new double[n];
		for (int i = 0; i < n; i++) d[i] = v[i] - b[i];
		CVectorVert res(d, n);
		delete[] d;
		return res;
	}
}