#include "Robot.h"
#include <iostream>
#include <iomanip>
using std::cout;

void Robot::Afisare()const{
    Agent::Afisare();
    cout<<" Raza: "<<setw(10)<<left<<raza<<" VitezaAtac: "
                   <<setw(10)<<left<<vitezaAtac<<" Dauna: "
                   <<setw(10)<<left<<dauna<<'\n';
}
