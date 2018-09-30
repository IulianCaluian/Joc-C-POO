#ifndef ARMURA_H
#define ARMURA_H
#include "Item.h"

class Armura : public Item
{
    /*Clasa abstracta din care am derivat
        scut - +protectie la viata celui care foloseste acest item - folosire singulara
        amortizor - scade din dauna primita de la alt agent -folosire permanenta
    */

friend class Agent;
friend class Harta;
protected:
    int protectie;
public:
    Armura(const string& numeArmura,int protectieArmura)
    : Item(numeArmura),protectie(protectieArmura){};
    virtual bool Terminata()const=0;
    virtual int Dauna()const{return 0;}
    virtual int Dauna(const Agent* a1,const Agent* a2)const{return Dauna();}
    virtual void AutoFolosire(Agent*)=0;
    virtual void Afisare()const;
    virtual tipItem Tip()const = 0;
private:
    virtual void Folosire(Agent*,Agent*){return;};//Obiectele de tip armura se pot folosi doar de agentul care le are.
};

class Scut : public Armura
{
private:
    int terminat;
public:
    virtual void AutoFolosire(Agent*);
    virtual void Afisare()const;
    virtual bool Terminata()const{return terminat;}
    Scut(const string& numeScut,int protectieScut): Armura(numeScut,protectieScut){terminat=false;};
    virtual tipItem Tip()const {return scut;}
};

class Amortizor : public Armura
{
public:
    virtual void AutoFolosire(Agent*);
    virtual void Afisare()const;
    virtual bool Terminata()const{return false;}
    Amortizor(const string& numeAmortizor,int protectieAmortizor): Armura(numeAmortizor,protectieAmortizor){};
    virtual tipItem Tip()const {return amortizor;}
};

#endif // ARMURA_H
