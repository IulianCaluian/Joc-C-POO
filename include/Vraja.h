#ifndef VRAJA_H
#define VRAJA_H
#include "Item.h"
#include "Efect.h"

class Agent;
class Vraja : public Item
{
friend class Agent;
private:
    int manaNecesara;
    Efect& efect;
    virtual void AutoFolosire(Agent*){};//Nu exista vraji pentru autofolosire.
public:
    virtual void Folosire(Agent*,Agent*);
    bool FolosirePosibila(const Agent*,const Agent*)const;
    virtual bool Terminata()const{return false;}
    virtual int Dauna()const{return 0;}
    virtual int Dauna(const Agent* a1,const Agent* a2)const{
        if( FolosirePosibila(a1,a2) )
            return efect.Dauna(a1,a2);  //Daca putem folosi vraja dauna vrajii este dauna efectului.
        else return 0;
        }
    virtual void Afisare()const;
    Vraja(const string& numeVraja,int manaNecesaraVraja,Efect& efectVraja)
       : Item(numeVraja),manaNecesara(manaNecesaraVraja),efect(efectVraja)/*,efect(efectVraja) */{};
    virtual tipItem Tip()const {return vraja;}
};


#endif // VRAJA_H
