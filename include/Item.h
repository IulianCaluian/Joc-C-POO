#ifndef ITEM_H
#define ITEM_H
#include <string>
#include "Agent.h"
using namespace std;

class Agent;

class Item
{   //Clasa abstracta care sta la baza itemelor.
    // Functiile Folosire si AutoFolosire stau la baza acestei clase.
    // aceste functii avand efecte diferite in functie de tipul itemului care le apeleaza.
protected:
    string nume;

public:
    virtual bool Terminata()const=0;
    virtual void AutoFolosire(Agent*)   =0; //itemul este folosit de agent1 pentru el insuri
    virtual void Folosire(Agent*,Agent*)=0; //itemul este folosit de agent1 impotriva lui agent2
    virtual void Afisare()const=0;
    virtual int Dauna()const=0;
    virtual int Dauna(const Agent* a1,const Agent* a2)const=0;
    enum tipItem {potiune,scut,amortizor,armaDeFoc,armaAlba,vraja};
    Item(const string& numeItem): nume(numeItem){};
    const string& Nume()const {return nume;}
    virtual tipItem Tip()const = 0;
    const char PrimaLitera()const {return nume[0];}
};





#endif // ITEM_H
