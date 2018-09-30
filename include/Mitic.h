#ifndef MITIC_H
#define MITIC_H
#include "Agent.h"

class Mitic : public Agent
{
    /* clasa care sta la baza lui Vrajitor si Orc
    */
friend class Potiune;
friend class Vraja;
friend class FurtMana;

protected:
    const static int vitezaAtac = 1;
    int raza;
    int mana;
public:
    Mitic(const string & numeMitic,int viataMitic,int razaMitic,int manaMitic=10)
    : Agent(numeMitic,viataMitic),raza(razaMitic),mana(manaMitic){};
    virtual ~Mitic(){};
    virtual int Raza() const{return raza;}
    virtual int VitezaAtac()const {return vitezaAtac;}
    virtual tipAgent Tip()const = 0;
    virtual void Afisare() const;
};

class Vrajitor : public Mitic
{   //Vrajitorii sunt puternici daca au vraji si mana necesara sa le foloseasca.
public:
    Vrajitor(const string & numeVrajitor,int viataVrajitor,int razaVrajitor,int manaVrajitor)
    : Mitic(numeVrajitor,viataVrajitor,razaVrajitor,manaVrajitor){};
    virtual ~Vrajitor(){};
    virtual tipAgent Tip()const {return vrajitor;}
    virtual int Dauna()const{return 0;}
    virtual void Afisare() const;
};

class Orc : public Mitic
{
private:
    int dauna; //Orcii nu pot folosi vraji dar au mana si dauna.
public:
    Orc(const string & numeOrc,int viataOrc,int razaOrc,int daunaOrc)
    : Mitic(numeOrc,viataOrc,razaOrc),dauna(daunaOrc){};
    virtual ~Orc(){};
    virtual int Dauna()const{return dauna;}
    virtual tipAgent Tip()const {return orc;}
    virtual void Afisare() const;
};
#endif // MITIC_H
