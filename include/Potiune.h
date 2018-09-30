#ifndef POTIUNE_H
#define POTIUNE_H
#include "Item.h"

class Potiune : public Item
{
private:
    int plusViata;
    int plusMana;
    int plusStamina;
    int plusVitezaAtac;
    virtual void Folosire(Agent*,Agent*){};
public:
    virtual void AutoFolosire(Agent*);
    virtual bool Terminata()const{return false;}
    virtual int Dauna()const{return 0;}
    virtual int Dauna(const Agent* a1,const Agent* a2)const{return Dauna();} //Potiunile nu dau dauna.
    virtual void Afisare()const;
    Potiune(const string& numePotiune,int plusViataPotiune,int plusManaPotiune=0,int plusStaminaPotiune=0,int plusVitezaAtacPotiune=0)
    : Item(numePotiune),plusViata(plusViataPotiune),plusMana(plusManaPotiune),plusStamina(plusStaminaPotiune),plusVitezaAtac(plusVitezaAtacPotiune){};
    virtual tipItem Tip()const {return potiune;};
};

#endif // POTIUNE_H
