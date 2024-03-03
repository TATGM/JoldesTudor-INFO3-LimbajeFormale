//Pentru conversia din Python in C++, am folosit: https://products.codeporting.app/convert/ai/python-to-cpp/

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
    cout <<"\n";
    }
}

int main()
{
    afiseaza_palindroamele_pana_la_lungimea(10);
    return 0;
}
