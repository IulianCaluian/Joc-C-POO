#include "Armura.h"
#include <iostream>
#include <iomanip>
using std::cout;

void Armura::Afisare()const {
    cout<<setw(20)<<left<<nume<<"Protectie: "<<protectie;
}

void Scut::Afisare()const{
    Armura::Afisare();
    cout<<'\n';
}

void Scut::AutoFolosire(Agent* agent){
    agent->viata += protectie;
    terminat=true;
    cout<<agent->Nume()<<" a folosit "<<Nume()<<" +"<<protectie<<" viata\n";
}

void Amortizor::Afisare()const{
    Armura::Afisare();
    cout<<'\n';
}

void Amortizor::AutoFolosire(Agent* agent){
   ;
    /*
    Acest item este folosit in cadrul unui duel pentru apararea agentului atacat.
    */
}
