#ifndef HARTA_H
#define HARTA_H
#include "Agent.h"
#include "Item.h"
class Harta
{

    private:
        struct coord{
                int x,y;
            };
        //tip al clasei harta pentru coordonatele obiectelor care apartin hartii.
        int n,m;//n - inaltime m -latimea hartii
        char **a;//memoria pt matricea hartii  va fi alocata dinamic

        int nrA;    //nragenti
        Agent ** agent;
        coord * coordA; //coordonate agenti

        int nrI;    //nriteme
        Item ** item;
        coord * coordI;//coordonate iteme

    public:
        Harta(int,int);
        ~Harta();
        //Functii de interfata:
        int Ramasi()const{return nrA;};
        void Afisare()const;
        void Simulare();  //simularea unei runde
        void AfisareAgenti()const;
        void AfisareIteme()const;
        void AdaugaAgent(Agent&, int, int);
        void AdaugaItem (Item& , int, int);
    private:

        void StergeItem (int) ;
        void StergeAgent(int);
        void Move(int i);       //Mutare agent de pe pozitia i din vectorul agenti
        void Duel(int,int);     //functie care simuleaza o batalie
        bool Atacare(Agent*,Agent*);        //functia prin care a1 ataca pe a2
        bool EliminarePosibila(Agent*,Agent*);  //Functie care testeaza daca a1 il poate elimina pe a2

    };

#endif // HARTA_H
