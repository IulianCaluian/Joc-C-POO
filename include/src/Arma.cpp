#include "Arma.h"
#include <iostream>
#include <iomanip>
using std::cout;

void Arma::Afisare()const{
    cout<<setw(20)<<left<<nume<<"Dauna: "<<setw(10)<<left<<dauna;
}

void ArmaDeFoc::Afisare()const{
    Arma::Afisare();
    cout<<"Munitie: "<<munitie;
    cout<<'\n';
}

void ArmaDeFoc::Folosire(Agent* agent1,Agent* agent2){
    agent2->viata -= dauna;
    munitie --;
    if(munitie==0)terminat=true;
}

void ArmaAlba::Afisare()const{
    Arma::Afisare();
    cout<<'\n';
}

void ArmaAlba::Folosire(Agent* agent1,Agent* agent2){
    agent2->viata -= dauna;
}

