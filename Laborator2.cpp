//Problema 1

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <Python.h>

using namespace std;

vector<string> genereaza_palindroame(int lungime){
    vector<char> alfabet = {'0', '1', '2'};
    vector<string> palindroame;
    for (auto cuvant : itertools.product(alfabet, lungime / 2 + lungime % 2)) {
        string palindrom = string(cuvant.begin(), cuvant.end()) + string(cuvant.rbegin(), cuvant.rend());
        palindroame.push_back(palindrom);
    }
    return palindroame;
}

void afiseaza_palindroamele_pana_la_lungimea(int lungime_maxima)
{
    for(int lungime=1; lungime<=lungime_maxima; lungime++)
    {
    vector<string> palindroame=genereaza_palindroame(lungime);
    cout << "Palindroame de lungime " << lungime << ": ";
    for (const auto& palindrom : palindroame) {
        cout << palindrom << " ";
    }
    cout << endl;
    }
}

int main()
{
    afiseaza_palindroamele_pana_la_lungimea(10);
    return 0;
}

//Problema 2

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

//Problema 3, Gramatica 1

#include <iostream>
#include <string>
using namespace std;

void gramatica1(string S, string A, string B, int lungime, string sir_actual = "") {
    if (lungime == 0) {
        cout << sir_actual << endl;
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

//Problema 3, Gramatica 2

#include <iostream>
#include <string>
using namespace std;

void gramatica2(string S, string X, string Y, string Z, int length, string current_string = "") {
    if (length == 0) {
        cout << current_string << " ";
        return;
    }

    if (current_string.find(S) != string::npos) {
        gramatica2(X, X, Y, Z, length - 1, current_string.replace(current_string.find(S), 1, "X"));
    } else {
        gramatica2(X, X, Y, Z, length - 1, current_string + X);
    }

    if (current_string.find(Y) != string::npos) {
        gramatica2(Y, X, Y, Z, length - 1, current_string.replace(current_string.find(Y), 1, "2"));
        gramatica2(Y, X, Y, Z, length - 1, current_string.replace(current_string.find(Y), 1, "X"));
    } else {
        gramatica2(Y, X, Y, Z, length - 1, current_string + "2");
        gramatica2(Y, X, Y, Z, length - 1, current_string + Y);
    }

    if (current_string.find(Z) != string::npos) {
        gramatica2(Z, X, Y, Z, length - 1, current_string.replace(current_string.find(Z), 1, "3"));
        gramatica2(Z, X, Y, Z, length - 1, current_string.replace(current_string.find(Z), 1, "4"));
        gramatica2(Z, X, Y, Z, length - 1, current_string.replace(current_string.find(Z), 1, "X"));
    } else {
        gramatica2(Z, X, Y, Z, length - 1, current_string + "3");
        gramatica2(Z, X, Y, Z, length - 1, current_string + "4");
        gramatica2(Z, X, Y, Z, length - 1, current_string + Z);
    }
}

int main()
{
gramatica2("S", "X", "Y", "Z", 3);
}
