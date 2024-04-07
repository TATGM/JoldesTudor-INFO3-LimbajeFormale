//Pentru conversia din Python in C++, am folosit: https://products.codeporting.app/convert/ai/python-to-cpp/, dar am adăugat și cod pentru a citi de la tastatură un anumit număr de șiruri și șirurile respective.
#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>

using namespace std;

class AutomataPushdown {
private:
    //stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out), where elements are inserted and extracted only from one end of the container.
    stack<char> stiva;
    //unordered maps are associative containers that store elements formed by the combination of a key value and a mapped value, and which allows for fast retrieval of individual elements based on their keys.
    unordered_map<tuple<string, char, char>, pair<string, char>> tranzitii;
    string stare_initiala;
    string stare_acceptare;

public:
    AutomataPushdown() {
        stiva = stack<char>();
        //make_tuple constructs an object of the appropriate tuple type to contain the elements specified in args.
        //make_pair constructs a pair object with its first element set to x and its second element set to y.
        tranzitii = {
            {make_tuple("q0", '0', ' '), make_pair("q0", '0')},
            {make_tuple("q0", '0', '0'), make_pair("q0", '0')},
            {make_tuple("q0", '1', '0'), make_pair("q1", ' ')},
            {make_tuple("q1", '1', '0'), make_pair("q1", ' ')},
            {make_tuple("q1", ' ', ' '), make_pair("q_accept", ' ')}
        };
        stare_initiala = "q0";
        stare_acceptare = "q_accept";
    }

    bool inserare(string sir_inserat) {
        string stare_curenta = stare_initiala;

    //the char specifier is used for char type deduction.
    //simbol is the type of the element of the sequence represented by sir_inserat, or a reference to that type.
    //sir_inserat represents a suitable sequence or a braced-init-list.
        for (char simbol : sir_inserat) {
            //make_tuple constructs an object of the appropriate tuple type to contain the elements specified in args.
            //dacă stiva este goală, atunci vârful stivei este gol, altfel întoarce valoarea din vârful stivei
            if (tranzitii.find(make_tuple(stare_curenta, simbol, stiva.empty() ? '\0' : stiva.top())) != tranzitii.end()) {
                auto tranzitia = tranzitii[make_tuple(stare_curenta, simbol, stiva.empty() ? '\0' : stiva.top())];
                stare_curenta = tranzitia.first;
                if (tranzitia.second != '\0') {
                    stiva.push(tranzitia.second); //se inserează în stivă valoarea 0 sau 1, în funcție de stare
                } else {
                    if (!stiva.empty()) {
                        stiva.pop(); //dacă stiva este goală, atunci se elimină stiva element cu element
                    }
                }
            } else {
                return false;
            }
        }

        return stare_curenta == stare_acceptare && stiva.empty();
    }
};

void test_pda(string sir_inserat) {
    AutomataPushdown pda;
    if (pda.inserare(sir_inserat)) {
        cout << "Sirul " << sir_inserat << " este acceptat de automata." << endl;
    } else {
        cout << "Sirul " << sir_inserat << " nu este acceptat de automata." << endl;
    }
}

int main() {
    int numar_siruri; string sir_inserat;
    cin>>numar_siruri;
    for(int i=1; i<=numar_siruri; i++)
    {
    cin>>sir_inserat;
    test_pda(sir_inserat);
    }

    return 0;
}
