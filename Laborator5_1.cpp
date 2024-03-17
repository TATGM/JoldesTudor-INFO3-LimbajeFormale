#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> letters = {"a", "b", "E"};
vector<string> states = {"q0", "q1", "q2", "q3", "q4"};

unordered_map<pair<string, string>, string> tranzitii = {
    {{"a", "q0"}, "q1"},
    {{"a", "q1"}, "q1"},
    {{"E", "q1"}, "q2"},
    {{"b", "q2"}, "q2"},
    {{"b", "q2"}, "q3"},
    {{"a", "q2"}, "q3"},
    {{"a", "q3"}, "q3"},
    {{"b", "q3"}, "q1"},
    {{"E", "q3"}, "q4"}
}

bool verifica(string cuvant) {
    stare_curenta = states[0]
    stare_finala = states[4]
    //the char specifier is used for char type deduction.
    //litera is the type of the element of the sequence represented by cuvant, or a reference to that type.
    //cuvant represents a suitable sequence or a braced-init-list.
    for (char litera : cuvant) {
        if (tranzitii.find({litera, stare_curenta}) != tranzitii.end()) {
            stare_curenta = tranzitii[{letter, stare_curenta}];
            cout << stare_curenta << endl;
        } else {
            cout << "Eroare!" << endl;
        }
    }
    return stare_finala == stare_curenta;
}

int main()
{
    cout << verifica("aEbE") << endl << verifica("abE") << endl;
}
