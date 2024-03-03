//Pentru conversia din Python in C++, am folosit: https://products.codeporting.app/convert/ai/python-to-cpp/

#include <iostream>
#include <string>
using namespace std;

void gramatica2(string S, string X, string Y, string Z, int lungime, string sir_actual = "") {
    if (lungime == 0) {
        cout << sir_actual << " ";
        return;
    }

    if (sir_actual.find(S) != string::npos) {
        gramatica2(X, X, Y, Z, lungime - 1, sir_actual.replace(sir_actual.find(S), 1, "X"));
    } else {
        gramatica2(X, X, Y, Z, lungime - 1, sir_actual + X);
    }

    if (sir_actual.find(Y) != string::npos) {
        gramatica2(Y, X, Y, Z, lungime - 1, sir_actual.replace(sir_actual.find(Y), 1, "2"));
        gramatica2(Y, X, Y, Z, lungime - 1, sir_actual.replace(sir_actual.find(Y), 1, "X"));
    } else {
        gramatica2(Y, X, Y, Z, lungime - 1, sir_actual + "2");
        gramatica2(Y, X, Y, Z, lungime - 1, sir_actual + Y);
    }

    if (sir_actual.find(Z) != string::npos) {
        gramatica2(Z, X, Y, Z, lungime - 1, sir_actual.replace(sir_actual.find(Z), 1, "3"));
        gramatica2(Z, X, Y, Z, lungime - 1, sir_actual.replace(sir_actual.find(Z), 1, "4"));
        gramatica2(Z, X, Y, Z, lungime - 1, sir_actual.replace(sir_actual.find(Z), 1, "X"));
    } else {
        gramatica2(Z, X, Y, Z, lungime - 1, sir_actual + "3");
        gramatica2(Z, X, Y, Z, lungime - 1, sir_actual + "4");
        gramatica2(Z, X, Y, Z, lungime - 1, sir_actual + Z);
    }
}

int main()
{
gramatica2("S", "X", "Y", "Z", 3);
}
