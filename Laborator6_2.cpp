//codul a fost inspirat, dar am modificat, astfel incat sa fie mai simplu la for-uri sau if-uri
/*
Demonstratie matematica:
Limbajul 1: L={(0^(i) 1^(j))|i>j}, w=(0^(i) 1^(j))=x*y*z, astfel incat |y|>0 si |x*y|≤n. Avem x=0^(i), y=1, z=1^(j-1)
Pumping lemma: xy^(k)z, de aici avem x=0^(i), y=1^(k), z=1^(j-1).
Pentru k=0, avem 0^(i)*1*1^(j-1) -> 0^(i)*1^(j)∈L1
Pentru k≠0 (ex. k=i+1), avem 0^(i)*1^(i+1)*1^(j-1) -> 0^(i)*1^(i+j), unde i>i+j fals -> L nu este regular

Limbajul 2: L={(a^i b^j)|i<=j}, w=(a^(i) b^(j))=x*y*z, astfel incat |y|>1 si |x*y|≤n. Avem x=a^(p-1), y=a, z=b^(q)
Pumping lemma: xy^(r)z, de aici avem x=a^(p-1), y=a, z=b^(q).
Pentru r=1, avem a^(p-1)*a*b^(q) -> a^(p)*b^(q)∈L2
Pentru r≠1 (ex. r=q+1), avem a^(p-1)*a^(q+1)*b^(q)=a^(p+q)*b^(q), unde p+q≤q fals -> L nu este regular

Limbajul 3: L={(a^n b^n c^n)|n>0}, w=(a^(n) b^(n) c^(n))=x*y*z, astfel incat |y|>1 si |x*y|≤n. Avem x=a^(p-1), y=a, z=b^(p)*c^(p)
Pumping lemma: xy^(i)z, de aici avem x=a^(p-1), y=a, z=b^(p)*c^(p).
Pentru i=1, avem a^(p-1)*a*b^(p)*c^(p) -> a^(p)*b^(p)*c^(p)∈L3
Pentru i≠1 (ex. i=3), avem a^(p-1)*a^(3)*b^(p)*c^(p)=a^(p+2)*b^(p)*c^(p), unde p+2≤p fals -> L nu este regular

*/

#include <iostream>
using namespace std;

int numar1,numar2;

//L={(0^i 1^j)|i>j} este limbajul 1 dupa care se genereaza sirurile, de fiecare data cand este iteratie(*) este un numar aleator de iteratii
string GenerareSirLimbaj1()
{
    string sirgenerat = "";
    int j = rand()%numar1+1;
    int i = rand()%numar2+(j+1);
    int k;
    for (k = 1; k <= i; k++)
    {
        sirgenerat = sirgenerat + '0';
    }
    for (k = 1; k <= j; k++)
    {
        sirgenerat = sirgenerat + '1';
    }
    return sirgenerat;
}
    
//L={(a^i b^j)|i<=j} este limbajul 2 dupa care se genereaza sirurile, de fiecare data cand este iteratie(*) este un numar aleator de iteratii
string GenerareSirLimbaj2()
{
    string sirgenerat = "";
    int j = rand()%numar1+1;
    int i = rand()%j+1;
    int k;
    for (k = 1; k <= i; k++)
    {
        sirgenerat = sirgenerat + 'a';
    }
    for (k = 1; k <= j; k++)
    {
        sirgenerat = sirgenerat + 'b';
    }
    return sirgenerat;
}

//L={(a^n b^n c^n)|n>0} este limbajul 3 dupa care se genereaza sirurile, de fiecare data cand este iteratie(*) este un numar aleator de iteratii
static string GenerareSirLimbaj3()
{
    string sirgenerat = "";
    int n = rand()%numar1+1;
    int i;
    for (i = 1; i <= n; i++)
    {
        sirgenerat = sirgenerat + 'a';
    }
    for (i = 1; i <= n; i++)
    {
        sirgenerat = sirgenerat + 'b';
    }
    for (i = 1; i <= n; i++)
    {
        sirgenerat = sirgenerat + 'c';
    }
    return sirgenerat;
}

int main()
{
    string sirgenerat;
    int numarsiruri; cin>>numarsiruri;
    cin>>numar1>>numar2;
    for (int i = 1; i <= numarsiruri; i++)
    {
        sirgenerat = GenerareSirLimbaj1();
        cout<<"Sir generat "<<i<<" in Limbajul 1: "<<sirgenerat<<endl;
        sirgenerat = GenerareSirLimbaj2();
        cout<<"Sir generat "<<i<<" in Limbajul 2: "<<sirgenerat<<endl;
        sirgenerat = GenerareSirLimbaj3();
        cout<<"Sir generat "<<i<<" in Limbajul 3: "<<sirgenerat<<endl;
    }
    return 0;
}
