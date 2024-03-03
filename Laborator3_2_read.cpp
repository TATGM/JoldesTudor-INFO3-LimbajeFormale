//Pentru conversia din Python in C++, am folosit: https://products.codeporting.app/convert/ai/python-to-cpp/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

class LanguageAutomata {
public:
    LanguageAutomata() {
        string current_state = "q0";
        unordered_set<string> final_states = {"q3"};
        int doubles = 0;
        nullptr_t last_letter = nullptr;
    }

    void transition_function(char letter) {
        //unordered_map is an associated container that stores elements formed by the combination of a key value and a mapped value.
        //pair is used to combine together two values that may be of different data types.
        unordered_map<pair<string, char>, string> transitions = {
            {{"q0", 'a'}, "q1"},
            {{"q0", 'b'}, "q0"},
            {{"q0", 'c'}, "q0"},
            {{"q0", 'd'}, "q0"},
            {{"q1", 'a'}, "q1"},
            {{"q1", 'b'}, "q2"},
            {{"q1", 'c'}, "q1"},
            {{"q1", 'd'}, "q1"},
            {{"q2", 'a'}, "q2"},
            {{"q2", 'b'}, "q2"},
            {{"q2", 'c'}, "q2"},
            {{"q2", 'd'}, "q2"},
            {{"q3", 'a'}, "q3"},
            {{"q3", 'b'}, "q3"},
            {{"q3", 'c'}, "q3"},
            {{"q3", 'd'}, "q3"}
        };

        pair<string, char> key = {current_state, letter};

        if (transitions.find(key) != transitions.end()) {
            current_state = transitions[key];
            if (letter == last_letter) {
                doubles++;
                if (doubles == 3) { current_state = "q3"; }
            } else {
                doubles = 1;
            }
            last_letter = letter;
        } else { cout << "Error!\n"; reset(); }
    }

    bool the_final_state() {
        return final_states.count(current_state) && doubles == 3;
    }

    void reset() {
        current_state = "q0";
        doubles = 0;
        nullptr_t last_letter = nullptr;
    }

private:
    string current_state;
    //An unordered_set is an unordered associative container implemented using a hash table where keys are hashed into indices of a hash table so that the insertion is always randomized.
    unordered_set<string> final_states;
    int doubles;
    char last_letter;
};

int main() {
    LanguageAutomata language;

    string test_word;
    cout << "Introduce a word: "; cin >> test_word;
    cout << "Checking the word: " << test_word << ":\n";

    //the char specifier is used for char type deduction.
    //letter is the type of the element of the sequence represented by test_word, or a reference to that type.
    //test_word represents a suitable sequence or a braced-init-list.
    for (char letter : test_word) {
        language.transition_function(letter);
    }

    if (language.the_final_state() && test_word.length() <= 6) {
        cout << "The word is in the language.\n";
    } else {
        cout << "The word isn't in the language.\n";
    }

    cout << "Reseting...\n"; language.reset();

    return 0;
}
