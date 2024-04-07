//Pentru conversia din Python in C++, am folosit: https://products.codeporting.app/convert/ai/python-to-cpp/, dar am adăugat și cod pentru a citi de la tastatură un anumit număr de coduri IBAN și codurile respective.
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class ValidatorIBAN {
public:
    ValidatorIBAN() {
        coduri_tara_valide = {
            "AL", "AD", "AT", "AZ", "BH", "BY", "BE", "BA", "BR", "BG",
            "CR", "HR", "CY", "CZ", "DK", "DO", "TL", "EE", "FO", "FI",
            "FR", "GE", "DE", "GI", "GR", "GL", "GT", "HU", "IS", "IQ",
            "IE", "IL", "IT", "JO", "KZ", "XK", "KW", "LV", "LB", "LI",
            "LT", "LU", "MK", "MT", "MR", "MU", "MD", "MC", "ME", "NL",
            "NO", "PK", "PS", "PL", "PT", "QA", "RO", "SM", "SA", "RS",
            "SK", "SI", "ES", "SE", "CH", "TN", "TR", "UA", "AE", "GB",
            "VG"
        };
        lungime_iban = {
            {"AL", 28}, {"AD", 24}, {"AT", 20}, {"AZ", 28}, {"BH", 22}, {"BY", 28},
            {"BE", 16}, {"BA", 20}, {"BR", 29}, {"BG", 22}, {"CR", 21}, {"HR", 21},
            {"CY", 28}, {"CZ", 24}, {"DK", 18}, {"DO", 28}, {"TL", 23}, {"EE", 20},
            {"FO", 18}, {"FI", 18}, {"FR", 27}, {"GE", 22}, {"DE", 22}, {"GI", 23},
            {"GR", 27}, {"GL", 18}, {"GT", 28}, {"HU", 28}, {"IS", 26}, {"IQ", 23},
            {"IE", 22}, {"IL", 23}, {"IT", 27}, {"JO", 30}, {"KZ", 20}, {"XK", 20},
            {"KW", 30}, {"LV", 21}, {"LB", 28}, {"LI", 21}, {"LT", 20}, {"LU", 20},
            {"MK", 19}, {"MT", 31}, {"MR", 27}, {"MU", 30}, {"MD", 24}, {"MC", 27},
            {"ME", 22}, {"NL", 18}, {"NO", 15}, {"PK", 24}, {"PS", 29}, {"PL", 28},
            {"PT", 25}, {"QA", 29}, {"RO", 24}, {"SM", 27}, {"SA", 24}, {"RS", 22},
            {"SK", 24}, {"SI", 19}, {"ES", 24}, {"SE", 24}, {"CH", 21}, {"TN", 24},
            {"TR", 26}, {"UA", 29}, {"AE", 23}, {"GB", 22}, {"VG", 24}
        };
        tranzitii_pda = {
            {{"q0", "A", " "}, {"q1", "A"}},
            {{"q1", "A", "A"}, {"q1", "A"}},
            {{"q1", "B", "A"}, {"q2", "B"}},
            {{"q2", "B", "B"}, {"q2", "B"}},
            {{"q2", "C", "B"}, {"q3", "C"}},
            {{"q3", "C", " "}, {"q4", " "}},
            {{"q4", " ", " "}, {"q_accept", " "}}
        };
        stare_initala = "q0";
        stare_acceptare = "q_accept";
    }

    bool iban_validare(string iban) {
        //erase removes from the vector either a single element (position) or a range of elements ([first,last)).
        //remove transforms the range [first,last) into a range with all the elements that compare equal to val removed, and returns an iterator to the new end of that range.
        iban.erase(remove(iban.begin(), iban.end(), " "), iban.end());
        string cod_tara = iban.substr(0, 2);

        if (coduri_tara_valide.find(cod_tara) == coduri_tara_valide.end()) {
            return false;
        }

        if (iban.length() != lungime_iban[cod_tara]) {
            return false;
        }

        string stare_curenta = stare_initiala;
        vector<string> stiva;

    //the char specifier is used for char type deduction.
    //caracter is the type of the element of the sequence represented by iban, or a reference to that type.
    //iban represents a suitable sequence or a braced-init-list.
        for (char caracter : iban) {
            //vector::back returns a reference to the last element in the vector.
            //dacă stiva este goală, atunci vârful stivei este gol, altfel întoarce valoarea ultimului element din vector
            string stiva_varf = stiva.empty() ? " " : stiva.back();
            if (tranzitii_pda.find({stare_curenta, string(1, caracter), stiva_varf}) != tranzitii_pda.end()) {
                //tie allows a set of objects to act as a tuple, which is especially useful to unpack tuple objects.
                tie(stare_curenta, stiva_varf) = tranzitii_pda[{stare_curenta, string(1, caracter), stiva_varf}];
                if (!stiva_varf.empty()) {
                    stiva.push_back(stiva_varf); //dacă vârful stivei nu este gol, atunci se adaugă un element în vârful stivei
                } else if (!stiva.empty()) {
                    stiva.pop_back(); //dacă stiva nu este goală, atunci se șterg elementele din stivă, unul câte unul
                }
            } else {
                return false;
            }
        }

        return stare_curenta == stare_acceptare && stiva.empty();
    }

private:
    //unordered sets are containers that store unique elements in no particular order, and which allow for fast retrieval of individual elements based on their value.
    unordered_set<string> coduri_tara_valide;
    //unordered maps are associative containers that store elements formed by the combination of a key value and a mapped value, and which allows for fast retrieval of individual elements based on their keys.
    unordered_map<string, int> lungime_iban;
    unordered_map<tuple<string, string, string>, pair<string, string>> tranzitii_pda;
    string stare_initiala;
    string stare_acceptare;
};

void test_iban_validator(string iban) {
    ValidatorIBAN validator;
    if (validator.iban_validare(iban)) {
        cout << "Codul IBAN " << iban << " este valid." << endl;
    } else {
        cout << "Codul IBAN " << iban << " este invalid." << endl;
    }
}

int main() {
    int numar_coduri_IBAN; string cod_IBAN;
    cin>>numar_coduri_IBAN;
    for(int i=1; i<=numar_coduri_IBAN; i++)
    {
    cin>>cod_IBAN;
    test_iban_validator(cod_IBAN);
    }

    return 0;
}
