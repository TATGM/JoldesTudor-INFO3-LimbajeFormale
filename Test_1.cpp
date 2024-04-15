#include <iostream>
#include <vector>
#include <regex>

using namespace std;

vector<string> stari = {"q0", "q1", "q2"};

int main()
{
    string puls,sistolica,diastolica;
    regex semne_vitale("(\\+|-)?[[:digit:]]+");
    while(true)
    {
    cout<<"Introdu valoarea pulsului: ";
    cin>>puls;
    if(regex_match(puls,semne_vitale) && (stoi(puls)>=60 && stoi(puls)<=100))
    cout<<"Puls normal! Stare actuala: q1"<<endl;
    else if(regex_match(puls,semne_vitale))
    cout<<"Pulsul nu este normal! Stare actuala: q1"<<endl;
    else
    cout<<"Valoarea este invalida!"<<endl;
    
    if(puls=="q")
    {
        cout<<"Opreste automatul Moore!"; break;
    }
    
    cin>>sistolica>>diastolica;
    
    if(regex_match(sistolica,semne_vitale) && regex_match(diastolica,semne_vitale) && (stoi(sistolica)>=120 && stoi(sistolica)<=140) && (stoi(diastolica)>=80 && stoi(diastolica)<=90))
    cout<<"Tensiune normala! Stare actuala: q1"<<endl;
    else if(regex_match(sistolica,semne_vitale) && regex_match(diastolica,semne_vitale))
    cout<<"Tensiunea nu este normala! Stare actuala: q1"<<endl;
    else
    cout<<"Valoarea este invalida!"<<endl;
    
    if(sistolica=="q" || diastolica=="q")
    {
        cout<<"Opreste automatul Moore!"; break;
    }
    }
}
