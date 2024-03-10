//Pentru conversia din Python in C++, am folosit: https://products.codeporting.app/convert/ai/python-to-cpp/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

bool acceptat(string word) {
    vector<string> states = {"S0", "S1", "S2", "S3"};
    vector<string> letters = {"a", "b"};

    string current_state = states[0];
    string final_state = states[1];

    //unordered_map is an associated container that stores elements formed by the combination of a key value and a mapped value.
    //pair is used to combine together two values that may be of different data types.
    unordered_map<pair<string, string>, string> transitions = {
        {make_pair(states[0], letters[0]), states[2]},
        {make_pair(states[0], letters[1]), states[3]},
        {make_pair(states[2], letters[0]), states[1]},
        {make_pair(states[2], letters[1]), states[2]},
        {make_pair(states[3], letters[0]), states[3]},
        {make_pair(states[3], letters[1]), states[1]}
    };

    //the char specifier is used for char type deduction.
    //letter is the type of the element of the sequence represented by word, or a reference to that type.
    //word represents a suitable sequence or a braced-init-list.
    for(char letter : word) {
        cout << current_state << " " << letter << "\n";
        //make_pair() allows to create a value pair without writing the types explicitly. 
        if(transitions.find(make_pair(current_state, string(1, letter))) != transitions.end()) {
            current_state = transitions[make_pair(current_state, string(1, letter))];
        } else {
            return false;
        }
    }

    return current_state == final_state;
}

int main() {
    vector<string> CapitalLetters = {"S", "A", "B"};
    vector<string> SmallLetters = {"a", "b"};
    unordered_map<string, vector<string>> WordGenerator = {
        {"S", {"aA", "bB"}},
        {"A", {"a", "bA", ""}},
        {"B", {"aB", ""}}
    };

    int numar_cuvinte;
    cout << "Introdu un numar de cuvinte, care vor fi generate: "; cin >> numar_cuvinte;

    vector<string> cuvinte = {"S"};

    //set is a type of associative container in which each element has to be unique because the value of the element identifies it.
    while(set<string>(cuvinte.begin(), cuvinte.end()).size() < numar_cuvinte) {
        vector<string> cuvinte_noi;
        //the string specifier is used for string type deduction.
        //word is the type of the element of the sequence represented by cuvinte, or a reference to that type.
        //cuvinte represents a suitable sequence or a braced-init-list.
        for(string word : cuvinte) {
            for(string SmallLetters : CapitalLetters) {
                for(string str : WordGenerator[SmallLetters]) {
                    cuvinte_noi.push_back(word.replace(word.find(SmallLetters), SmallLetters.length(), str));
                }
            }
        }
        cuvinte = cuvinte_noi;
    }

    set<string> cuvinte_unice(cuvinte.begin(), cuvinte.end());
    
    //the string specifier is used for string type deduction.
    //word is the type of the element of the sequence represented by cuvinte_unice, or a reference to that type.
    //cuvinte_unice represents a suitable sequence or a braced-init-list.
    for(string word : cuvinte_unice) {
        if(acceptat(word)) {
            cout << "Cuvantul '" << word << "' este acceptat\n";
        } else {
            cout << "Cuvantul '" << word << "' este respins\n";
        }
    }

    return 0;
}
