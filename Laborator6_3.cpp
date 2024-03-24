//Pentru conversia din Python in C++, am folosit: https://products.codeporting.app/convert/ai/python-to-cpp/, dar am adăugat și cod pentru a citi de la tastatură un anumit număr de șiruri și șirurile respective.

#include <iostream>
#include <regex>
#include <string>

using namespace std;

bool validareCodPostal(string codPostal) {
    //regular expressions for the postal code details.
    regex patternCodPostal("^[1-9][0-9]{4}$");
    //The regex_match function returns indicates whether a source string matches the regular expression.
    return regex_match(codPostal, patternCodPostal);
}

int main() {
    vector<string> coduriPostale;
    string sir="";
    //declar un numar de coduri
    int numarCoduri; cin>>numarCoduri;
    for(int i=1; i<=numarCoduri; i++) {
    //citesc sirurile codurilor
    cin>>sir;
    //adaug un element in vector
    coduriPostale.push_back(sir);
    //the auto specifier is used for auto type deduction.
    //codPostal is the type of the element of the sequence represented by coduriPostale, or a reference to that type.
    //coduriPostale represents a suitable sequence or a braced-init-list.
    for (const auto& codPostal : coduriPostale) {
        //Alphanumerical bool values sets the boolalpha format flag for the str stream.
        //When the boolalpha format flag is set, bool values are inserted/extracted by their textual representation: either true or false, instead of integral values.
        cout << "Cod postal: " << codPostal << ", Valid: " << boolalpha << validareCodPostal(codPostal) << endl;
    }
    }
    return 0;
}
