#include "Harta.h"
#include "Armura.h"
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using std::cout;

Harta::Harta(int x,int y){
    n=x;
    m=y;
    a=new char*[n];
    int i,j;

    for( i=0 ; i<n ; i++)
        a[i]=new char[m];

    for (i=0;i<n;i++)
        for( j=0; j<m; j++)
            a[i][j]=0;

    nrA=0;
    agent=NULL;
    coordA=NULL;

    nrI=0;
    item=NULL;
    coordI=NULL;

   srand(time(0));
}

Harta::~Harta(){
    int i;
    for (i=0;i<n;i++)
        delete [] a[i];
    delete [] a;
    delete [] agent;
    delete [] item;
}

void Harta::Afisare()const{
    int i,j;
    //Afisarea hartii:
    for( i=0 ; i<n ; i++)
        for( j=0; j<m ; j++)
            a[i][j]=0;

    for( i=0; i<nrI ; i++)
        a[coordI[i].x][coordI[i].y]=-(i+1);
    for( i=0; i<nrA ; i++)
        a[coordA[i].x][coordA[i].y]=i+1;

    cout<<char(201);
            for(j=0;j<m-1;j++)
                cout<<char(205)<<char(205)<<char(205)<<char(203);
    cout<<char(205)<<char(205)<<char(205)<<char(187);

    for(i=0;i<n;i++)
    {   if(i>0)
            {
            cout<<char(204);
            for(j=0;j<m-1;j++)
                cout<<char(205)<<char(205)<<char(205)<<char(206);

            cout<<char(205)<<char(205)<<char(205)<<char(185);
            }
        cout<<'\n';
        cout<<char(186);
        for(j=0;j<m;j++){
            cout<<' ';
            if(a[i][j]==0)
                cout<<' ';
            else
            if(a[i][j]>0)
            {
                //Este agent:
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 12);
                cout<<agent[a[i][j]-1]->PrimaLitera();
                SetConsoleTextAttribute(hConsole, 7);
            }
            else
            {
                //Este arma:

                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 10);
                cout<<item[-a[i][j]-1]->PrimaLitera();
                SetConsoleTextAttribute(hConsole, 7);


            }

            cout<<' '<<char(186);
            }
        cout<<'\n';
    }


    cout<<char(200);
        for(j=0;j<m-1;j++)
            cout<<char(205)<<char(205)<<char(205)<<char(202);
    cout<<char(205)<<char(205)<<char(205)<<char(188);
    cout<<'\n';

}

void Harta::AdaugaAgent(Agent& agentNou, int pozX, int pozY){
    //Adaug agent pe pozX pozY
    Agent ** temp;
    coord * tempC;
    temp = new Agent* [nrA + 1];
    tempC= new coord  [nrA + 1];

    int i;
    for( i = 0 ; i < nrA ; i++){
        temp[i] = agent[i];
        tempC[i]= coordA[i];
        }
    temp[nrA] = &agentNou;
    tempC[nrA].x=pozX-1;
    tempC[nrA].y=pozY-1;
    nrA++;
    delete [] agent;
    delete [] coordA;
    agent = temp;
    coordA= tempC;
}


void Harta::AdaugaItem(Item& itemNou, int pozX, int pozY){
    //Adaug un item pe pozX pozY
    Item ** temp;
    coord * tempC;
    temp = new Item* [nrI + 1];
    tempC= new coord  [nrI + 1];

    int i;
    for( i = 0 ; i < nrI ; i++){
        temp[i] = item[i];
        tempC[i]= coordI[i];
        }
    temp[nrI] = &itemNou;
    tempC[nrI].x=pozX-1;
    tempC[nrI].y=pozY-1;
    nrI++;
    delete [] item;
    delete [] coordI;
    item = temp;
    coordI= tempC;
}

void Harta::StergeItem(int pozitaItem)
{   //Stergere item de pe harta cand este colecctat
    Item ** temp;
    coord * tempC;
    if(nrI==0)cout<<"Ceva nu e bine!!"<<endl;
    temp = new Item* [nrI - 1];
    tempC= new coord [nrI - 1];

    int i;
    for( i = 0 ; i < pozitaItem ; i++){
        temp[i] = item[i];
        tempC[i]= coordI[i];
        }
    for( i=pozitaItem; i < nrI-1; i++){
        temp[i] = item[i+1];
        tempC[i]= coordI[i+1];
    }


    nrI--;
    delete [] item;
    delete [] coordI;
    item = temp;
    coordI= tempC;
}

void Harta::StergeAgent(int pozitiaAgent)
{
    //Stergerea unui agent cand este eliminat
    Agent ** temp;
    coord * tempC;
    temp = new Agent* [nrA - 1];
    tempC= new coord [nrA - 1];

    int i;
    for( i = 0 ; i < pozitiaAgent ; i++){
        temp[i] = agent[i];
        tempC[i]= coordA[i];
        }
    for( i=pozitiaAgent; i < nrA-1; i++){
        temp[i] = agent[i+1];
        tempC[i]= coordA[i+1];
    }
    nrA--;
    delete [] agent;
    delete [] coordA;
    agent = temp;
    coordA= tempC;
}

void Harta::Move(int i)
{   //Mutarea agentului[i]
    int newx=-1,newy=-1;
    int vrand;
    int st,dr;
    int raza=agent[i]->Raza();
    //Merg la un item daca exista:
    int gasit=0;
    for(int j=0;!gasit && j<nrI; j++)
    {
        if( abs(coordI[j].x -coordA[i].x) <= raza &&
            abs(coordI[j].y -coordA[i].y) <= raza)
            {
            newx=coordI[j].x;
            newy=coordI[j].y;
            gasit=1;
            break;
            }
    }

    //Daca un alt agent s-a mutat pe pozitia agentului curent atunci ramanem aici daca se poate intampla ceva.
    if(!gasit)
        for(int j=0;!gasit && j<nrA; j++)
        if(j!=i)
            {
                if(coordA[j].x == coordA[i].x && coordA[j].y == coordA[i].y &&
                   (EliminarePosibila(agent[i],agent[j]) || EliminarePosibila(agent[j],agent[i]) ) )
                {
                    newx=coordA[i].x;
                    newy=coordA[i].y;
                    gasit=1;
                    break;
                }

            }

    /* Agentul se muta pe pozitia altui agent :

    if(!gasit)
        for(int j=0;!gasit && j<nrA; j++)
        if(i!=j)
        {
            if( abs(coordA[j].x -coordA[i].x) <= raza && abs(coordA[j].y -coordA[i].y) <= raza &&
                 (EliminarePosibila(agent[i],agent[j]) || EliminarePosibila(agent[j],agent[i]))
               )
            {
            newx=coordA[j].x;
            newy=coordA[j].y;
            gasit=1;
            break;
            }
        }
    */
    //Alge o pozitie random:
    if(!gasit)
    do
    {
        st = max(0 , coordA[i].x - raza);
        dr = min( n-1 , coordA[i].x + raza);
        vrand = rand()% ( dr - st + 1);
        newx  = vrand + st ;

        st= max(0 , coordA[i].y - raza);
        dr= min( m-1 , coordA[i].y + raza);
        vrand = rand() % (dr-st+1);
        newy  = vrand + st ;

    }while (newx == coordA[i].x && newy==coordA[i].y);

    //cout<<"Agentul "<<agent[i]->Nume()<<" s-a mutat ("<<coordA[i].x<<","<<coordA[i].y<<") -> ("<<newx<<","<<newy<<")\n";

    //Am gasit un item:
    if(a[newx][newy] < 0)
    {//Il colectam:

        agent[i]->AdaugaItem( *item[ -a[newx][newy] - 1 ]);
        cout<<agent[i]->Nume()<<" a colectat "<< item[ -a[newx][newy] - 1 ] -> Nume()<<" .\n";
        StergeItem( -a[newx][newy] - 1);
        a[newx][newy] = 0;

    }

    coordA[i].x=newx;
    coordA[i].y=newy;

}


void Harta::AfisareAgenti()const
{
    //Afisare agenti de pe harta:
    int i;
    for( i=0; i<nrA; i++)
        {
            cout<<setw(2)<<left<<coordA[i].x<<' '<<setw(2)<<left<<coordA[i].y<<"  ";
            agent[i]->Afisare();
        }
}

void Harta::AfisareIteme()const
{
    //Afisare iteme de pe harta:
    int i;
    for( i=0; i<nrI; i++)
        {
            cout<<setw(2)<<left<<coordI[i].x<<' '<<setw(2)<<left<<coordI[i].y<<"  ";
            item[i]->Afisare();
        }
}

void Harta::Duel(int a1,int a2)
{   int i;
    //Desfasurare unui tur:
    bool ok1 = 1,ok2 = 1;
    while((ok1 || ok2) && agent[a1]->viata > 0 && agent[a2]->viata > 0)
    {//Agent 1 ataca agent 2 cu viteza specifica.
        for(i=1;ok1 && i<=agent[a1]->VitezaAtac();i++)
            ok1 &= Atacare(agent[a1],agent[a2]);
     //Agent 2 ataca agent 1 cu viteza specifica:
        for(i=1;ok2 && i<=agent[a2]->VitezaAtac();i++)
            ok2 &= Atacare(agent[a2],agent[a1]);
        cout<<"\t\t------------------------------------------------------------\n";
    }
}

bool Harta::Atacare(Agent* agent1,Agent* agent2)
{
    //Verificam daca un agent poate scadea viata celuilalt:
    if(!EliminarePosibila(agent1,agent2))return false;
    if(agent2->viata <= 0)return false;

    Item* itemAtac    = agent1->CelMaiBunAtac(agent2);
    Item* itemAparare = agent2->CelMaiBunAparare();
    //Aleg cel mai bun item atac pentru atacator si cel mai bun item aparare agent atacat.

    cout<<"\t\t"<<agent1->Nume()<<" a atacat pe "<<agent2->Nume();
    int initial = agent2->viata;
    if(itemAtac!=NULL)
    {
        cout<<" folosind "<<itemAtac->Nume();
        agent2->viata -= agent1->Dauna();
        itemAtac->Folosire(agent1,agent2);  //Folosesc itemAtac
        if(itemAparare != NULL)
            {
            cout<<". Agent "<<agent2->Nume()<<" s-a protejat cu "<<itemAparare->Nume();
            agent2->viata += min( ((Amortizor*)itemAparare)->protectie,itemAtac->Dauna()+agent1->Dauna());
            //Folosesc item aparare.
            }
    }
        else
    {   //Nu avem item atac:
        agent2->viata -= agent1->Dauna();
        if(itemAparare != NULL)
            {
            cout<<". Agent "<<agent2->Nume()<<" s-a protejat cu "<<itemAparare->Nume();
            agent2->viata += min( ((Amortizor*)itemAparare)->protectie, agent1->Dauna());
            }
    }
    cout<<'\t';
    cout<<"\tViata "<<agent2->Nume()<<": "<<initial<<" -> "<<max(0,agent2->viata)<<'\n';
    return true;
}


void Harta::Simulare()
{   int i,j;

    //Updatari agenti(potiuni/ alte bonusuri / stamina).
    for( i=0 ; i<nrA ; i++)
        agent[i]->Updatare();

    //Mutari agenti:
    for( i=0 ; i<nrA ; i++)
        {
        for( j=0; j<nrI ; j++)
            a[coordI[j].x][coordI[j].y]=-(j+1);
        Move(i);
        }

    i=0;
    //Duele si eliminari:
    while(i < nrA)
    {
        j=i+1;
        while(j < nrA)
        {   if(coordA[i].x != coordA[j].x || coordA[i].y != coordA[j].y ){j++;continue;}
            cout<<"Duel "<<agent[i]->Nume()<<" vs. "<<agent[j]->Nume()<<" :\n";
            Duel(i,j);//Duel intere agent[i] si agent[j]
            if(agent[j]->viata <= 0)
            {
                cout<<"\t"<<agent[j]->Nume()<<" a fost eliminat.\n";
                StergeAgent(j);
            }
            else j++;

            if(agent[i]->viata <= 0)
                break;
        }
        if(agent[i]->viata <= 0)
            {
             cout<<"\t"<<agent[i]->Nume()<<" a fost eliminat.\n";
             StergeAgent(i);
            }
        else i++;
    }

}

bool Harta::EliminarePosibila(Agent* agent1,Agent* agent2)
{   //Functie care verifica daca este posibil ca agent 1 sa elimine agent 2

    Item* itemAtac    = agent1->CelMaiBunAtac(agent2);
    Item* itemAparare = agent2->CelMaiBunAparare();
    //Verificam daca un agent poate scadea viata celuilalt:
    if(itemAtac!=NULL)
    {   //Daca am item atac:
        if(itemAparare!=NULL)
            {//Daca agent2 are amortizor si itemAtac nu e vraja:
            if( itemAtac->Tip() != Item::vraja &&
               ((Amortizor*)itemAparare)->protectie >=
                agent1->Dauna()+itemAtac->Dauna(agent1,agent2))return false;
            }
        else
            if(agent1->Dauna() + itemAtac->Dauna(agent1,agent2) <= 0)return false;
    }

    else
    { //Nu am item atac
       if(itemAparare!=NULL)
        {
        if(((Amortizor*)itemAparare)->protectie >= agent1->Dauna())return false;
        }
      else
        if(agent1->Dauna()<=0)return false;
    }
    return true;
}

