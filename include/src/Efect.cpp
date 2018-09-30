#include "Efect.h"
#include "Om.h"
#include "Mitic.h"
#include <iostream>
#include <iomanip>
using std::cout;

void SchimbViata::Actiune(Agent* agent1,Agent* agent2)const
{
    swap(agent1->viata,agent2->viata);
    cout<<'\t'<<agent1->Nume()<<" a schimbat viata cu "<<agent2->Nume()<<'\t';
}

int SchimbViata::Dauna(const Agent* agent1,const Agent* agent2)const
{
    return agent2->viata - agent1->viata;
}

void AtacMagic::Actiune(Agent* agent1,Agent* agent2)const
{
    agent2->viata -= dauna;
}

int AtacMagic::Dauna(const Agent* agent1,const Agent* agent2)const
{
    return dauna;
}

void FurtMana::Actiune(Agent* agent1,Agent* agent2)const{
    if(agent2->Tip() == Agent::orc || agent2->Tip() == Agent::vrajitor) // E agent mitic?
    {
        ((Mitic*)agent1)->mana += ((Mitic*)agent2)->mana ;
        cout<<'\t'<<agent1->Nume()<<" a furat "<<((Mitic*)agent2)->mana<<'\t';
        ((Mitic*)agent2)->mana = 0;
    }
}
int FurtMana::Dauna(const Agent* agent1,const Agent* agent2)const{
    if(agent2->Tip() == Agent::orc || agent2->Tip() == Agent::vrajitor) // E agent mitic?
        if(((Mitic*)agent2)->mana > 0 )return 1; //Dauna mai mult generica -agent 2 in realitate
                                    //nu va primi 1 dauna . Returneaza 1 pentru a marca ca aceasta vraja chiar are un efect
                                    // nu da damage dar fura mana .
    return 0;
}
