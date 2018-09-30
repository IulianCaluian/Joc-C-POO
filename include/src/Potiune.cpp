#include "Potiune.h"
#include "Om.h"
#include "Mitic.h"
#include <iostream>
#include <iomanip>
using std::cout;

void Potiune::Afisare()const{
    cout<<setw(20)<<left<<nume  <<"Viata +"   <<setw(10)<<left<<plusViata
                                <<"Mana +"    <<setw(10)<<left<<plusMana
                                <<"Stamina +" <<setw(10)<<left<<plusStamina <<'\n';
}

void Potiune::AutoFolosire(Agent* agent){
    //Funtia de folosire a potiunii:
    //Tine cont de diferite tipuri de agenti.
    if(agent->Tip()==Agent::robot)return;//Robotii nu pot folosi potiuni.

    agent->viata = min(agent->viata + plusViata,100);
    if(plusViata)
        cout<<agent->Nume()<<" a folosit "<<Nume()<<" +"<<plusViata<<" viata\n";
    if(agent->Tip()==Agent::ninja || agent->Tip()==Agent::razboinic)
        {
        ((Om*)agent)->stamina=min( ((Om*)agent)->stamina+plusStamina , 100);
        if(plusStamina)
            cout<<agent->Nume()<<" a folosit "<<Nume()<<" +"<<plusStamina<<" stamina\n";
        }
    if(agent->Tip()==Agent::vrajitor || agent->Tip()==Agent::orc)
        {
        ((Mitic*)agent)->mana = ((Mitic*)agent)->mana+ plusMana;
        if(plusMana)
            cout<<agent->Nume()<<" a folosit "<<Nume()<<" +"<<plusMana<<" mana\n";
        }
    if(agent->Tip()==Agent::ninja)
    {
        ((Ninja*)agent)->vitezaAtac += plusVitezaAtac;
        if(plusVitezaAtac)
            cout<<agent->Nume()<<" a folosit "<<Nume()<<" +"<<plusVitezaAtac<<" viteza atac\n";

    }
}
