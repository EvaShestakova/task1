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

