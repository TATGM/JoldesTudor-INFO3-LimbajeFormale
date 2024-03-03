//Pentru conversia din Python in C++, am folosit: https://products.codeporting.app/convert/ai/python-to-cpp/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string generare_sir(int iteratii, int numarator, vector<int> lista_alegeri) {
    if (iteratii <= 0) { return ""; }
    
    int rezultat = lista_alegeri[numarator];
    if (rezultat == 0) { return "a" + generare_sir(iteratii - 1, numarator + 1, lista_alegeri) + "a"; }
    else if (rezultat == 1) { return "b" + generare_sir(iteratii - 1, numarator + 1, lista_alegeri) + "b"; }
    else if (rezultat == 2) { return "a"; }
    else if (rezultat == 3) { return "b"; }
    else { return ""; }
}

int main() {
    vector<string> lista_siruri;
    vector<int> lista_alegeri = {0, 0, 0};
    bool generare = true;

    cout << "Optiunile din regula de productie:\n1: aSa\n2: bSb\n3: a\n4: b\n\n";

    while (generare) {
        cout << "Cazul: " << lista_alegeri[0] + 1 << ", " << lista_alegeri[1] + 1 << ", " << lista_alegeri[2] + 1 << ": ";
        for (int i = 1; i <= 3; i++) {
            lista_siruri.push_back(generare_sir(i, 0, lista_alegeri));
            cout << "Iteratia " << i << ": " << lista_siruri.back() << ", ";
        }
        cout << "\n";

        if (lista_alegeri[2] < 3) { lista_alegeri[2]++; }
        else if (lista_alegeri[1] < 3) { lista_alegeri[1]++; lista_alegeri[2] = 0; }
        else if (lista_alegeri[0] < 3) { lista_alegeri[0]++; lista_alegeri[1] = 0; lista_alegeri[2] = 0; }
        else { generare = false; }
    }

    return 0;
}

//Pentru conversia din Python in C++, am folosit: https://products.codeporting.app/convert/ai/python-to-cpp/

#include <iostream>
#include <string>
using namespace std;

void gramatica1(string S, string A, string B, int lungime, string sir_actual = "") {
    if (lungime == 0) {
        cout << sir_actual <<"\n";
        return;
    }

    if (sir_actual.find(S) != string::npos) {
        gramatica1(A, A, B, lungime - 1, sir_actual.replace(sir_actual.find(S), 1, "B"));
        gramatica1(B, A, B, lungime - 1, sir_actual.replace(sir_actual.find(S), 1, "A"));
    } else {
        gramatica1(A, A, B, lungime - 1, sir_actual + A);
        gramatica1(B, A, B, lungime - 1, sir_actual + B);
    }
}

int main()
{
    gramatica1("S", "A", "B", 6);
}
