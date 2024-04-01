//am adăugat și cod pentru a citi de la tastatură un număr de șiruri, generate de funcțiile GenerareE și GenerareI
/*
Avem 10 operații în set: 1. E→I; 2. E→E+E; 3. E→E*E; 4. E→(E); 5. I→a; 6. I→b; 7. I→Ia; 8. I→Ib; 9. I→I0; 10. I→I1. Vrem ca E să devină (a101+b1)*(a1+b), dar prin transformări succesive.
Începem cu E→E*E, se aplică operația a 3-a din set. Pe urmă, conform operației a 4-a, E→(E), și rezultă: E*E→(E)*(E), urmând ca apoi să aplicăm operația a 2-a, unde E→E+E.
Avem (E)*(E)→(E+E)*(E+E). Se aplică prima operație, unde E→I, și dacă E→I, atunci (E+E)*(E+E)→(I+I)*(I+I). Operația a 2-a se aplică și în cazul în care E→I.
Mai departe, (I+I)*(I+I)→(I1+I1)*(I1+b), aplicăm două operații din set: operația 10, unde I→I1 și operația 6, unde I→b.
Rezultă mai departe că (I1+I1)*(I1+b)→(I01+b1)*(a1+b). Aici, aplicăm trei operații: pentru I1→I01 se aplică operația a 9-a, unde I→I0; pentru I1→b1 se aplică operația 6, unde I→b și, mai apoi, operația a 5-a, unde I→a.
După transformările succesive, vom avea (I01+b1)*(a1+b)→(I101+b1)*(a1+b). Operația a 10-a, unde I→I1, se aplică pentru I01→I101. Mai apoi, vom avea (I101+b1)*(a1+b)→(a101+b1)*(a1+b), iar pentru transformarea acestora, se aplică operația a 5-a, unde I→a.
*/

#include <iostream>
using namespace std;

string GenerareE(string expresia_initiala, int numar_maxim_derivari, int numar_derivari)
{
    string expresia_generata = expresia_initiala;
    if (numar_maxim_derivari >= numar_derivari)
    {
        int OperatieSetProductie = rand()%5+1;
        switch (OperatieSetProductie)
        {
            case 1: //E->I
            {
                expresia_generata = "I";
                break;
            }
            case 2: //E->E+E
            {
                expresia_generata = GenerareE("E", numar_maxim_derivari, numar_derivari+2) + "+" + GenerareE("E", numar_maxim_derivari, numar_derivari + 2);
                break;
            }
            case 3: //E->E*E
            {
                expresia_generata = GenerareE("E", numar_maxim_derivari, numar_derivari + 2) + "*" + GenerareE("E", numar_maxim_derivari, numar_derivari + 2);
                break;
            }
            case 4: //E->(E)
            {
                expresia_generata = "(" + GenerareE("E", numar_maxim_derivari, numar_derivari + 1) + ")";
                break;
            }
        }
    }
    else expresia_generata = "I";
    return expresia_generata;
}

string GenerareI(string expresia_initiala, int numar_maxim_derivari, int numar_derivari)
{
    string expresia_generata = expresia_initiala;
    if (numar_maxim_derivari >= numar_derivari)
    {
        int OperatieSetProductie = rand()%7+1;
        switch (OperatieSetProductie)
        {
            case 1: //I->a
            {
                expresia_generata = "a";
                break;
            }
            case 2: //I->b
            {
                expresia_generata = "b";
                break;
            }
            case 3: //I->Ia
            {
                expresia_generata = GenerareI("I", numar_maxim_derivari, numar_derivari+1) + "a";
                break;
            }
            case 4: //I->Ib
            {
                expresia_generata = GenerareI("I", numar_maxim_derivari, numar_derivari + 1) + "b";
                break;
            }
            case 5: //I->I0
            {
                expresia_generata = GenerareI("I", numar_maxim_derivari, numar_derivari + 1) + "0";
                break;
            }
            case 6: //I->I1
            {
                expresia_generata = GenerareI("I", numar_maxim_derivari, numar_derivari + 1) + "1";
                break;
            }
        }
    }
    else
    {
        int OperatieSetProductie = rand()%2+1;
        if (OperatieSetProductie == 1) expresia_generata = "a";
        else expresia_generata = "b";
    }
    return expresia_generata;
}

int main()
{
    srand(time(NULL));
    int numarsiruri; cin>>numarsiruri;
    for (int i = 1; i <= numarsiruri; i++)
    {
        string expresia_generata = GenerareE("E", 5, 1);
        string expresia_generata_finala="";
        for(int j=0; j<expresia_generata.length(); j++)
        {
            if (expresia_generata[j]=='*' || expresia_generata[j] == '+' || expresia_generata[j] == '(' || expresia_generata[j] == ')')
            {
                expresia_generata_finala += expresia_generata[j];
            }
            else
            {
                expresia_generata_finala += GenerareI("I", 5, 1);
            }
        }
        cout<<"\nExpresia generata "<<i<<": "<<expresia_generata_finala;
    }
    
    return 0;
}
