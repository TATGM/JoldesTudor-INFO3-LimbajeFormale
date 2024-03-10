//Pentru conversia din Python in C++, am folosit: https://products.codeporting.app/convert/ai/python-to-cpp/

#include <iostream>
#include <unordered_map>

using namespace std;

class CoffeeEspressor {
private:
    string current_state;
    string chosen_drink;

public:
    CoffeeEspressor() {
        current_state = "q0";
        chosen_drink = "";
    }

    void choose_drink(string input_drink) {
        //unordered_map is an associated container that stores elements formed by the combination of a key value and a mapped value.
        //pair is used to combine together two values that may be of different data types.
        unordered_map<pair<string, string>, string> transitions = {
            {{"q0", "C"}, "q1"},
            {{"q0", "T"}, "q2"},
            {{"q0", "A"}, "q3"},
            {{"q0", "H"}, "q4"},
            {{"q1", "OK"}, "q4"},
            {{"q2", "OK"}, "q4"},
            {{"q3", "OK"}, "q4"},
            {{"q4", "OK"}, "q0"}
        };

        pair<string, string> key = {current_state, input_drink};

        if (transitions.find(key) != transitions.end()) {
            current_state = transitions[key];
            if (current_state == "q4") {
                finish_order();
            }
        } else {
            cout << "Error!\n";
        }
    }

    void show_current_state() {
        cout << "Current state: " << current_state << "\n";
    }

    void finish_order() {
        cout << "The order for " << chosen_drink << " is complete!\n";
        chosen_drink = "";
    }

    void show_menu() {
        cout << "Meniu:\nC - Cafea\nT - Ceai\nA - Cappuccino\nH - Ciocolata calda\nOK - Confirma comanda\nEXIT - Inchide Automat\n";
    }

    void choose_option(string option) {
        unordered_map<pair<string, string>, string> transitions = {
            {{"q0", "C"}, "q1"},
            {{"q0", "T"}, "q2"},
            {{"q0", "A"}, "q3"},
            {{"q0", "H"}, "q4"},
            {{"q1", "OK"}, "q4"},
            {{"q2", "OK"}, "q4"},
            {{"q3", "OK"}, "q4"},
            {{"q4", "OK"}, "q0"}
        };

        pair<string, string> key = {current_state, option};

        if (transitions.find(key) != transitions.end()) {
            current_state = transitions[key];
            if (current_state == "q4") {
                finish_order();
            }
        } else {
            cout << "Eroare!\n";
        }
    }
};

int main() {
    CoffeeEspressor espressor;

    espressor.show_current_state();
    espressor.show_menu();

    while (true) {
        string option;
        cout << "Choose an option: "; cin >> option;
        option = toupper(option[0]);

        if (option == "EXIT") {
            break;
        }

        espressor.choose_option(option);
        espressor.show_current_state();
    }

    return 0;
}
