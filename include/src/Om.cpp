#include "Om.h"
#include <iostream>
#include <iomanip>
using std::cout;

void Om::Afisare()const{
    Agent::Afisare();
    cout<<" Raza: "<<setw(10)<<left<<raza;
}

void Razboinic::Afisare()const{
    Om::Afisare();
    cout<<" VitezaAtac: "<<setw(10)<<left<<vitezaAtac<<" Dauna: "<<setw(10)<<left<<dauna<<" Stamina: "<<stamina<<'\n';
}

void Ninja::Afisare()const{
    Om::Afisare();
    cout<<" VitezaAtac: "<<setw(10)<<left<<vitezaAtac<<" Dauna: "<<setw(10)<<left<<dauna<<" Stamina: "<<stamina<<'\n';
}
