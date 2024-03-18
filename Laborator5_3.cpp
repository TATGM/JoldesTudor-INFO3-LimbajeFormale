//am folosit atât surse din laboratoarele anterioare, cât și website-ul menționat: https://products.codeporting.app/convert/ai/python-to-cpp/ (în cazul unor îndoieli)

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> states = {"Q1", "Q2"};
vector<string> letters = {"X", "Y"};
vector<string> exits = {"O1", "O2"};

unordered_map<pair<string, string>, pair<string, string>> tranzitii = {
    {{"Q1", "X"}, {"Q1", "O1"}},
    {{"Q1", "Y"}, {"Q2", "O2"}},
    {{"Q2", "X"}, {"Q1", "O1"}},
    {{"Q2", "Y"}, {"Q2", "O2"}}
}

string afisare(string stare, string litera) {
	if(tranzitii.find({stare,litera}) != tranzitii.end()) {
		cout<<"Starea "<<stare<<" cu litera "<<litera<<" rezulta: "<< tranzitii[{stare, litera}].first << " si iesirea: " << tranzitii[{stare, litera}].second << endl;
	}
	else
		cout<<"Invalid!"<<endl;
}

int main()
{
    afisare(states[0], letters[0]); afisare(states[0], letters[1]); afisare(states[1], letters[0]); afisare(states[1], letters[1]);
}
