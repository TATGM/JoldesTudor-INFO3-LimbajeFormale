//Pentru conversia din Python in C++, am folosit: https://products.codeporting.app/convert/ai/python-to-cpp/

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <random>

using namespace std;

class LanguageAutomata {
public:
    LanguageAutomata() {
        current_state = "q0";
        final_states = {"q3"};
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
            {{"q3", 'd'}, "q3"},
        };

        pair<string, char> key = {current_state, letter};

        if (transitions.find(key) != transitions.end()) {
            current_state = transitions[key];
        } else {
            cout << "Error!\n";
        }
    }

    bool the_final_state() {
        return final_states.find(current_state) != final_states.end();
    }

private:
    string current_state;
    //An unordered_set is an unordered associative container implemented using a hash table where keys are hashed into indices of a hash table so that the insertion is always randomized.
    unordered_set<string> final_states;
};

string word_generator() {
    vector<char> letters = {'a', 'b', 'c', 'd'};
    //the word shows each chosen letter 2 times
    string word = string(2, letters[rand() % 4]) + string(2, letters[rand() % 4]) + string(2, letters[rand() % 4]);
    return word;
}

int main() {
    LanguageAutomata language;

    for (int i = 0; i < 3; i++) {
        string testing_word = word_generator();
        cout << "Checking the word " << testing_word << ":\n";

        //the char specifier is used for char type deduction.
        //letter is the type of the element of the sequence represented by test_word, or a reference to that type.
        //test_word represents a suitable sequence or a braced-init-list.
        for (char letter : testing_word) {
            language.transition_function(letter);
        }

        if (language.the_final_state() && testing_word.length() <= 6) {
            cout << "The word is in the langauge.\n";
        } else {
            cout << "The word isn't in the langauge.\n";
        }

        cout << "Reseting for the next word...\n";
        language.current_state = "q0";
    }

    return 0;
}
