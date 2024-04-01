#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Destinatii {
public:
    string nume_destinatie;
    vector<string> interese;
    int buget_cerut;
    string vreme_aleasa;

    Destinatii(string nume_destinatie, vector<string> interese, int buget_cerut, string vreme_aleasa)
        : nume_destinatie(nume_destinatie), interese(interese), buget_cerut(buget_cerut), vreme_aleasa(vreme_aleasa) {}

    void InformatiiDestinatie() {
        cout << "Destinatia: " << nume_destinatie << "\nInterese: ";
        //the auto specifier is used for auto type deduction.
        //interese is the type of the element of the sequence represented by interese, or a reference to that type.
        //interese represents a suitable sequence or a braced-init-list.
        for (auto& interese : interese) {
            cout << interese << ", ";
        }
        cout << "\nBuget necesar: " << buget_cerut << "\nVreme preferata: " << vreme_aleasa << endl;
    }
};

int main() {
    vector<Destinatii> destinations = {
        Destinatii("Statiune la malul marii", {"scufundari", "snorkeling"}, 280, "insorit"),
        Destinatii("Excursie in munti", {"drumetii", "peisaje spectaculoase"}, 400, "racoros"),
        Destinatii("Oras istoric", {"muzee", "monumente"}, 380, "moderat")
    };

    int buget; string vremeDorita;
    cin>>buget>>vremeDorita;
    cout << "Destinatii disponibile in functie de buget si vreme dorita:\n";
        //the auto specifier is used for auto type deduction.
        //destinatie is the type of the element of the sequence represented by destinatii, or a reference to that type.
        //destinatii represents a suitable sequence or a braced-init-list.
    for (auto& destinatie : destinations) {
        if (destinatie.buget_cerut <= buget && destinatie.vreme_aleasa == vremeDorita) {
            destinatie.InformatiiDestinatie();
        } else if (destinatie.buget_cerut > buget) {
            cout<<"Buget insuficient!";
        } else if (destinatie.vreme_aleasa != vremeDorita) {
            cout<<"Vremea introdusa este invalida!";
        }
    } 

    return 0;
}
