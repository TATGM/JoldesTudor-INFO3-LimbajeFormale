//Pentru conversia din Python in C++, am folosit: https://products.codeporting.app/convert/ai/python-to-cpp/

#include <iostream>
#include <string>

using namespace std;

int main() {
    int numar_locuri_parcare,locuri_parcare_goale,locuri_parcare_ocupate;

    cout << "Numarul locurilor de parcare: "; cin >> numar_locuri_parcare;
    
    locuri_parcare_goale = numar_locuri_parcare; locuri_parcare_ocupate = 0;

    string optiune = "";

    while (optiune != "D") {
        cout << "Alege una dintre optiuni:\nA) Parcheaza masina\nB) Elibereaza locul de parcare\nC) Verifica statutul parcarii\nD) OK\n";
        cin >> optiune;

        if (optiune == "A") {
            if (locuri_parcare_goale > 0) {
                locuri_parcare_goale--; locuri_parcare_ocupate++;
                cout << "Masina a fost parcata!\n";
            } else if (locuri_parcare_ocupate == numar_locuri_parcare) {
                cout << "Nu mai sunt locuri de parcare!\n";
            }
        } else if (optiune == "B") {
            if (locuri_parcare_ocupate == 0) {
                cout << "Nu sunt masini in parcare!\n";
            } else {
                locuri_parcare_goale++; locuri_parcare_ocupate--;
                cout << "Am iesit din locul de parcare!\n";
            }
        } else if (optiune == "C") {
            cout << "Numar locuri parcare goale: " << locuri_parcare_goale << "\nNumar locuri parcare ocupate: " << locuri_parcare_ocupate << "\n";
        } else if (optiune == "D") {
            cout << "Gata!" << "\n";
        } else {
            cout << "Optiune invalida!" << "\n";
        }
    }

    return 0;
}
