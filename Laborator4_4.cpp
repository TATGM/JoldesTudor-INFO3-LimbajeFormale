//Codul a fost scris de mine.

#include <iostream>
#include <unordered_map>

using namespace std;

class Automata {
private:
    string current_state;

public:
    Automata() {
        current_state = "q0";
    }

    void show_current_state() {
        cout << "Current state: " << current_state << "\n";
    }

    void choose_option(string option) {
        
    //unordered_map is an associated container that stores elements formed by the combination of a key value and a mapped value.
    //pair is used to combine together two values that may be of different data types.
    unordered_map<pair<string, string>, string> transitions = {
        {{"q0", "0"}, "q0"},
        {{"q0", "0"}, "q1"},
        {{"q0", "0"}, "q2"},
        {{"q0", "1"}, "q1"},
        {{"q0", "1"}, "q2"},
        {{"q0", "2"}, "q2"},
        {{"q1", "1"}, "q1"},
        {{"q1", "1"}, "q2"},
        {{"q1", "2"}, "q2"},
        {{"q2", "2"}, "q2"}
    };

        pair<string, string> key = {current_state, option};

        if (transitions.find(key) != transitions.end()) {
            current_state = transitions[key];
        } else {
            cout << "Eroare!\n";
        }
    }
};

int main() {
    Automata language;

    language.show_current_state();
    
    while (true) {
        string option;
        cout << "Choose an option: "; cin >> option;

        language.choose_option(option);
        language.show_current_state();
    }

    return 0;
}
