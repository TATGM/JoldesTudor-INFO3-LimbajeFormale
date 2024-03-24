//codul a fost inspirat, dar am modificat, astfel incat sa fie mai simplu la for-uri sau if-uri
/*
Demonstratie matematica:
(1+00*1)+(1+00*1)(0+10*1)*(0+10*1)=0*1(0+10*1)*
Initializam P=(1+00*1) și R=(0+10*1), de aici P+PR*R=0*1R*.
Daca R*R=R, atunci P+PR*=P(E+R*)=PR*
(1+00*1)R*=0*1R* -> (1+00*1)R*=(1+0*1)R* -> (E+0*)1R*=0*1R*=0*1R*
*/

#include <iostream>

using namespace std;

string GenerareSir()
{
    string sirgenerat="";
    for (int i = 1; i <= (rand()%6+1); i++)
    {
        sirgenerat = sirgenerat + '0';
    }
    sirgenerat = sirgenerat + '1';
    for (int i = 1; i <= (rand()%6+1); i++)
    {
        if ((rand()%3) == 0)
        {
            sirgenerat = sirgenerat + '0';
        }
        else
        {
            sirgenerat = sirgenerat + '1';
            for (int i = 1; i <= (rand()%6+1); i++)
            {
                sirgenerat = sirgenerat + '0';
            }
            sirgenerat = sirgenerat + '1';
        }
    }
    return sirgenerat;
}

int main()
{
    
    //citesc un numar de siruri
    int numarSiruri; cin>>numarSiruri;
    //se genereaza sirurile
    for (int i=1; i<=numarSiruri; i++)
    {
        string sirgenerat = GenerareSir();
        //0*1(0+10*1)* expresia regulata dupa care generez sirurile
        //De fiecare data cand este iteratie(*) este un numar aleator de iteratii
        cout<<"Sirul generat "<<i<<": "<<sirgenerat<<endl;
    }
}
