#ifndef AGENT_H
#define AGENT_H
#include <string>
#include "Item.h"
using namespace std;

class Item;

class Agent
{
friend class Harta;
friend class Scut;
friend class Amortizor;
friend class ArmaDeFoc;
friend class ArmaAlba;
friend class Potiune;
friend class Vraja;
friend class SchimbViata;
friend class AtacMagic;

public:
    enum tipAgent{razboinic,ninja,robot,vrajitor,orc};
protected:
    int viata;
    string nume;
    int nrI;
    Item ** item;
public:
    Agent(const string &,int);
    virtual ~Agent();
    //Nume functiilor este semnificativ pentru actiunea functie:
    const string& Nume()const {return nume;}
    const char PrimaLitera()const{return nume[0];}
    virtual tipAgent Tip() const = 0;
    virtual int Raza() const = 0;
    virtual int Dauna()const = 0;
    virtual int VitezaAtac()const = 0;
    virtual void Afisare() const ;
    Item* CelMaiBunAtac(Agent*)const;   //Functia care determina cel mai bun item atac
    Item* CelMaiBunAparare()const;      //Functia care determina cel mai bun item aparare
protected:
    void Updatare();
    void AdaugaItem(Item &);
    void StergeItem(int i);
private:
    //Agentii nu pot fi clonati : In caz de incercare copitere din afara programatorul primeste eroare compilare.
    Agent(const Agent&);
    Agent& operator=(const Agent&);

};
#endif // AGENT_H
