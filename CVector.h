#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Temp;
void AutoTest();
class CVectorHori;

class CVector {
protected:
	double* v;
	int n;
	string filename;
public:
	virtual int output(const string FileName) = 0;
	void SetFileName(const string s) { filename = s; };
	const string GetFileName() { return filename; };

	CVector() { SetZero(); }
	~CVector() { Clean(); }
	void Clean();
	void SetZero();
	CVector(const CVector& b);
	CVector(const double* b, int n);
	CVector& operator=(const CVector& b);
	void CopyOnly(const CVector& b);
	void print();
	int length()const;
	void Setn(int m) { Clean(); n = m; v = new double[n];}
	double* vector()const;
	//CVector operator+(const CVector& b);
	//CVector operator-(const CVector& b);
	double& operator[](int i) const;
	double operator*(const CVector& b);
	Temp operator[](int i);
	friend class Temp;
	friend CVectorHori operator+(const CVector& a, const CVector& b);
	friend CVectorHori operator-(const CVector& a, const CVector& b);
};
