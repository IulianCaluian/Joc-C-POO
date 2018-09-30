#include "Mitic.h"
#include <iostream>
#include <iomanip>
using std::cout;

//Functii de afisare:

void Mitic::Afisare()const{
    Agent::Afisare();
    cout<<" Raza: "<<setw(10)<<left<<raza<<" VitezaAtac: "<<setw(10)<<left<<vitezaAtac;

}

void Vrajitor::Afisare()const{
    Mitic::Afisare();
    cout<<" Mana: "<<setw(10)<<left<<mana<<'\n';
}

void Orc::Afisare()const{
    Mitic::Afisare();
    cout<<" Dauna: "<<setw(10)<<left<<dauna<<" Mana: "<<setw(10)<<left<<mana<<'\n';
}
