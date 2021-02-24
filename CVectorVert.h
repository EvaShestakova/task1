#pragma once
#include "CVector.h"
#include "Temp.h"
class CVectorVert : public CVector
{
public:
	using CVector::operator=;
	CVectorVert() {}
	~CVectorVert() {}
	CVectorVert(const CVector& b) : CVector(b) {}
	CVectorVert(const double* b, int n) :CVector(b, n) {}
	CVectorVert operator+(const CVectorVert& b);
	CVectorVert operator-(const CVectorVert& b);
	int output(const string FileName) override;
};

