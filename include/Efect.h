#ifndef EFECT_H
#define EFECT_H

class Agent;
/*
    Efect este o clasa de baza din care deriva alte clase care sunt efecte de tipuri variate.
    Functia virtuala pura Actiune sta la baza acestei clase - modalitate de actiune a unui efect.
    Dauna - functie care returneaza douna posibila in functia de atacator si atacat.
    Orice vraja contine o referinata catre un efect .
*/
class Efect{
public:
    Efect(){};
    virtual void Actiune(Agent*,Agent*)const=0;
    virtual int Dauna(const Agent*,const Agent*)const=0;
};

class SchimbViata : public Efect
{
public:
    SchimbViata(){};
    virtual void Actiune(Agent*,Agent*)const; //Actiune acestui efect este de a face schimb de viata
    virtual int Dauna(const Agent*,const Agent*)const;
};

class AtacMagic : public Efect
{
private:
    int dauna;
public:
    AtacMagic(int daunaAtac):dauna(daunaAtac){};
    virtual void Actiune(Agent*,Agent*)const; //Actiune acestui efect este de a da dauna
    virtual int Dauna(const Agent* ,const Agent*)const;
};

class FurtMana : public Efect
{
public:
    FurtMana(){};
    virtual void Actiune(Agent*,Agent*)const;   //Actiune acestui efect este de a fura mana
    virtual int Dauna(const Agent*,const Agent*)const;
};


#endif // EFECT_H
