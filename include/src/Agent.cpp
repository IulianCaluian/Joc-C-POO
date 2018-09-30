#include "Agent.h"
#include "Om.h"
#include "Armura.h"
#include <iostream>
#include <iomanip>
using namespace std;



Agent::Agent(const string & numeAgent, int viataOm):nume(numeAgent)
{
    viata=viataOm;
    nrI=0;   //Initial nu are iteme.
    item=NULL;
};

Agent::~Agent()
{
    delete [] item;
}

void Agent::Afisare()const {
    cout<<setw(15)<<left<<nume<<"Viata: "<<setw(12)<<left<<viata<<' ';
}

void Agent::Updatare(){
    //Functia care sterge itemele folosite si utilizeaza itemele de tip potiune/scut
    int i;
    if(Tip()==Agent::razboinic || Tip()==Agent::ninja)((Om*)this)->stamina=max(0,((Om*)this)->stamina-1);
    for( i=0; i<nrI;)
        {item[i]->AutoFolosire(this);
          if(item[i]->Terminata())
                StergeItem(i);
          else i++;
        }
}

void Agent::AdaugaItem( Item& itemDeAdaugat)
{
    //Functia care adauga un item
    Item ** temp;
    temp = new Item*[nrI+1];
    int i;
    for( i=0 ; i<nrI; i++)
        temp[i]=item[i];
    temp[nrI]=&itemDeAdaugat;
    nrI++;
    delete [] item;
    item = temp;
}

void Agent::StergeItem(int pozItem)
{
    //Functia care sterge un item.
    Item ** temp;
    temp = new Item*[nrI-1];
    int i;
    for( i=0; i<pozItem ; i++)
        temp[i]=item[i];
    for( i=pozItem; i<nrI - 1; i++)
        temp[i]=item[i+1];
    nrI--;
    delete [] item;
    item = temp;

}


Item* Agent::CelMaiBunAtac(Agent* tinta)const{
    //Functia care determina cel mai bun item pentru atac(daca exista)
    int i,poz=-1,maxim=-1;
    for( i=0 ; i<nrI; i++)
        {
            if(item[i]->Dauna(this,tinta) > maxim)
            {
                maxim=item[i]->Dauna(this,tinta);
                poz=i;
            }
        }

    if(poz>=0 && maxim>0)
        return item[poz];
    else
        return NULL;
}

Item* Agent::CelMaiBunAparare()const{
    //Functia care determina cel mai bun amortizor (daca exista)
    int i,poz=-1,maxim=-1;
    for( i=0 ; i<nrI; i++)if(item[i]->Tip()==Item::amortizor)
        if(((Amortizor*)item[i])->protectie > maxim)
        {
            maxim = ((Amortizor*)item[i])->protectie;
            poz=i;
        }
    if(poz>=0)
        return item[poz];
    else
        return NULL;
}

