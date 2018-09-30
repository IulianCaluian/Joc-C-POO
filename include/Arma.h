#ifndef ARMA_H
#define ARMA_H
#include "Item.h"


class Arma : public Item
{/*
    Clasa abstracta:
        -armele de foc nu sunt arme albe si nici vice-versa ->nu puteam deriva una din alta
            =>am creat aceasta clasa
  */


protected:
    int dauna;
private:
    virtual void AutoFolosire(Agent*){}; //O arma nu se poate folosi asupra unui agent insusi.
public:
    virtual void Folosire(Agent*,Agent*)=0;
    virtual bool Terminata()const = 0;
    virtual int Dauna()const{return dauna;}
    virtual int Dauna(const Agent* a1,const Agent* a2)const{return Dauna();}
    virtual void Afisare()const;
    Arma(const string& numeArma,int daunaArma): Item(numeArma),dauna(daunaArma) {};
    virtual tipItem Tip()const = 0;
};

class ArmaDeFoc : public Arma
{
private:
    int munitie;
    bool terminat;
public:
    virtual void Folosire(Agent*,Agent*);
    virtual void Afisare()const;
    virtual bool Terminata()const{return terminat;}
    virtual int Dauna()const{return munitie>0?dauna:0;}
    virtual int Dauna(const Agent* a1,const Agent* a2)const{return Dauna();}
    ArmaDeFoc(const string& numeArmaDeFoc,int daunaArmaDeFoc,int munitieArmaDeFoc)
        : Arma(numeArmaDeFoc,daunaArmaDeFoc),munitie(munitieArmaDeFoc) {terminat = false;};
    virtual tipItem Tip()const {return armaDeFoc;}
};

class ArmaAlba : public Arma
{
public:
    virtual void Folosire(Agent*,Agent*);
    virtual void Afisare()const;
    virtual bool Terminata()const{return false;}
    ArmaAlba(const string& numeArmaAlba,int daunaArmaAlba): Arma(numeArmaAlba,daunaArmaAlba) {};
    virtual tipItem Tip()const {return armaAlba;}
};
#endif // ARMA_H
