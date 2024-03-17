//am folosit atât surse din laboratoarele anterioare, cât și website-ul menționat: https://products.codeporting.app/convert/ai/python-to-cpp/ (în cazul unor îndoieli)

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> states = {"S1", "S2"};
vector<string> letters = {"A", "B"};
vector<string> exits = {"O1", "O2"};

unordered_map<pair<string, string>, string> tranzitii = {
    {{"S1", "A"}, "S1"},
    {{"S1", "B"}, "S2"},
    {{"S2", "A"}, "S1"},
    {{"S2", "B"}, "S2"}
}

string verifica(string stare, string litera)  {
    if (tranzitii.find({stare, litera}) != tranzitii.end()) {
        stare = tranzitii[{stare, litera}];
        if (stare == states[0]) {
            return exits[0];
        } else {
            return exits[1];
        }
    } else {
        return "Invalid!";
    }
}

int main()
{
    cout << "Starea " + states[0] + " cu litera " + letters[0] + ": " + rezultat(states[0], letters[0]) << endl;
    cout << "Starea " + states[0] + " cu litera " + letters[1] + ": " + rezultat(states[0], letters[1]) << endl;
    cout << "Starea " + states[1] + " cu litera " + letters[0] + ": " + rezultat(states[1], letters[0]) << endl;
    cout << "Starea " + states[1] + " cu litera " + letters[1] + ": " + rezultat(states[1], letters[1]) << endl;
}
