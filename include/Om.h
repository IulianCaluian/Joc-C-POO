#ifndef OM_H
#define OM_H
#include "Agent.h"

class Om : public Agent
{
friend class Potiune;
friend class Agent;
protected:
    int raza;
    int stamina;    //Oamenii obosesc ->dauna va fi stamina% din cea normala.
public:
    Om(const string & numeOm,int viataOm,int razaOm): Agent(numeOm,viataOm),raza(razaOm),stamina(100){};
    virtual ~Om(){};
    virtual int Raza() const{return raza;}
    virtual int VitezaAtac()const = 0;
    virtual tipAgent Tip() const = 0;
    virtual int Dauna()const = 0;
    virtual void Afisare() const;
};


class Razboinic : public Om
{
private:
    int dauna;
    const static int vitezaAtac = 1;
public:
    Razboinic(const string & numeRazboinic,int viataRazboinic, int razaRazboinic,int daunaRazboinic)
    : Om(numeRazboinic,viataRazboinic,razaRazboinic),dauna(daunaRazboinic){};
    virtual ~Razboinic(){};
    virtual int VitezaAtac()const{return vitezaAtac;}
    virtual tipAgent Tip()const{return razboinic;}
    virtual int Dauna()const{return (int)(dauna * stamina/100);}
    virtual void Afisare() const;
};


class Ninja : public Om
{
friend class Potiune;
private:
    const static int dauna = 2; //Toti ninja au aceiasi dauna(mica) insa daca au viteza sunt fatali.
    int vitezaAtac; //Atacuri pe secunda - pote creste cu potiuni de viteza.

public:
    Ninja(const string & numeNinja,int viataNinja, int razaNinja,int vitezaAtacNinja)
    : Om(numeNinja,viataNinja,razaNinja),vitezaAtac(vitezaAtacNinja){};
    virtual ~Ninja(){};
    virtual int VitezaAtac()const {return vitezaAtac;}
    virtual int Dauna()const{return (int)(dauna * stamina/100);}
    virtual tipAgent Tip()const{return ninja;}
    virtual void Afisare() const;
};

#endif // OM_H
