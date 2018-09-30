#include "Vraja.h"
#include "Mitic.h"
#include <iostream>
#include <iomanip>
using std::cout;


void Vraja::Afisare()const{
    cout<<setw(20)<<left<<nume<<"Mana Necesara:"<<manaNecesara<<'\n';
}

void Vraja::Folosire(Agent* agent1,Agent* agent2){
//Functia de folosire.
if(agent1->Tip()==Agent::vrajitor)
    if(((Mitic*)agent1)->mana >= manaNecesara)
    {
        ((Mitic*)agent1)->mana -= manaNecesara;
        efect.Actiune(agent1,agent2);
    }
}

bool Vraja::FolosirePosibila(const Agent* agent1,const Agent* agent2)const{
//Functie care testeaza daca o vraja poate fi folosita.
if(agent1->Tip()==Agent::vrajitor)
    if(((Mitic*)agent1)->mana >= manaNecesara)
        return true;
return false;
}


