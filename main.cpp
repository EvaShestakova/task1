#include "CVector.h"
#include "Temp.h"
#include "CVectorHori.h"
#include "CVectorVert.h"
//void AutoTest();



int main() {
    try {
        CVectorHori a;
        CVectorVert c,b;
        a[1] = 3;
        b[1] = 2;
        c = a + b;
        c.print();
       AutoTest();
        ifstream fin("data.txt");
        if (!fin.is_open()) {
            cout << "Error! Cannot open\n";
            return 1;
        }
        char* str = new char[1024];
        char* pch;
        string s;
        int m;
        double d;
        int n = 0;
        while (!fin.eof())
        {
            fin.getline(str, 1024, '\n');
            n++;
        }
        fin.seekg(0, ios_base::beg);
        fin.close();
        fin.open("data.txt");
        if (!fin.is_open()) {
            cout << "Error! Cannot open\n";
            return 1;
        }
        CVector** arr;
        arr = new CVector * [n];
        for (int i = 0; i < n; ++i) {
            fin >> s;
            if (s=="Hori") {
                arr[i] = new CVectorHori;
            }
            if (s == "Vert") {
                arr[i] = new CVectorVert;
            }
            fin >> s;
            arr[i]->SetFileName(s);
            fin >> m;
            arr[i]->Setn(m);
            for (int j = 0; j < m; ++j) {
                fin >> d;
                (*arr[i])[j] = d;
            }
        }
        for (int i = 0; i < n; ++i) {
            arr[i]->output(arr[i]->GetFileName());
        }
        fin.close();
        delete[] str;
        for (int i = 0; i < n; ++i) {
            delete arr[i];
        }
        delete[] arr;
        return 0;
    }
    catch (int err) { printf("error=%d\n", err); }
}
