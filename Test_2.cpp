#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

vector<string> stari = {"q0", "q1", "q2", "q3", "q4"};

unordered_map<pair<string, int>, string> tranzitii = {
    {{"q0", 1}, "q0"},
    {{"q0", 2}, "q1"},
    {{"q0", 3}, "q2"},
    {{"q0", 4}, "q3"},
    {{"q0", 5}, "q4"}
}

string stare_initiala="q0", stare_finala="q4";

int main()
{
    int suma, stare;
    cin>>suma;
    cin>>stare;
    switch(stare) {
        case 1:
        int suma_depusa;
        cout<<"Introdu o suma de depus in cont: "; cin>>suma_depusa;
        suma+=suma_depusa; cout<<suma<<"\n"<<"Stare actuala: q0";
        break;
        
        case 2:
        int suma_retrasa;
        cout<<"Introdu o suma de retras in cont: "; cin>>suma_retrasa;
        suma-=suma_retrasa; cout<<suma<<"\n"<<"Stare actuala: q1";
        break;

        case 3:
        cout<<"Soldul contului este: "<<suma<<"\n"<<"Stare actuala: q2";
        break;

        case 4:
        int suma_cont_1, suma_cont_2, suma_transfer;
        suma_cont_1=suma;
        cin>>suma_cont_2;
        cout<<"Suma contului 1 este "<<suma_cont_1<<". Suma contului 2 este "<<suma_cont_2<<".\n";
        cin>>suma_transfer;
        if(suma_transfer<=suma_cont_1 || suma_transfer<=suma_cont_2)
        { cout<<"Suma contului 1 este "<<suma_cont_1-suma_transfer<<". Suma contului 2 este "<<suma_cont_2+suma_transfer<<". Stare actuala: q3\n";
        if(suma_cont_1<0)
        { cout<<"Contul 1 este gol! Stare actuala: q3"; }
        else if(suma_cont_2<0)
        { cout<<"Contul 2 este gol! Stare actuala: q3"; }
        }
        else if(suma_transfer<=suma_cont_1 || suma_transfer<=suma_cont_2)
        { cout<<"Suma contului 1 este "<<suma_cont_1+suma_transfer<<". Suma contului 2 este "<<suma_cont_2-suma_transfer<<". Stare actuala: q3\n";
        if(suma_cont_1<0)
        { cout<<"Contul 1 este gol! Stare actuala: q3"; }
        else if(suma_cont_2<0)
        { cout<<"Contul 2 este gol! Stare actuala: q3"; }
        }
        break;

        case 5:
        cout<<"Contul este inchis, suma este 0! Stare actuala: q4";
        break;
        
        default: cout<<"Iesire din automat";
    }
}
