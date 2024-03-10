//Pentru conversia din Python in C++, am folosit: https://products.codeporting.app/convert/ai/python-to-cpp/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> letters = {"A", "B"};
vector<string> numbers = {"0", "1"};
vector<string> input_strings = {"010", "110", "1001"};

//unordered_map is an associated container that stores elements formed by the combination of a key value and a mapped value.
//pair is used to combine together two values that may be of different data types.
unordered_map<pair<string, string>, string> transitions = {
    {{letters[0], numbers[0]}, letters[1]},
    {{letters[0], numbers[1]}, letters[0]},
    {{letters[1], numbers[0]}, letters[0]},
    {{letters[1], numbers[1]}, letters[1]}
};

string find_final_state(string input) {
    string current_state = letters[0];
    //the char specifier is used for char type deduction.
    //letter is the type of the element of the sequence represented by input, or a reference to that type.
    //input represents a suitable sequence or a braced-init-list.
    for (char letter : input) {
        if (transitions.find({current_state, string(1, letter)}) != transitions.end()) {
            current_state = transitions[{current_state, string(1, letter)}];
        }
    }
    return current_state;
}

int main() {

    for (const string& input : input_strings) {
        cout << find_final_state(input) << "\n";
    }

    return 0;
}
