#include <iostream>
#include "Harta.h"
#include "Om.h"
#include "Robot.h"
#include "Mitic.h"
#include "Potiune.h"
#include "Armura.h"
#include "Arma.h"
#include "Vraja.h"
#include "Item.h"
#define MAXSimulari 1000
#include <stdlib.h>
using namespace std;

int main()
{
    Harta H(20,20);

    /*
        H este harta jocului
        Crearea unui agent se face prin constructorul TipAgent NumeAgent(parametri)
    */
    Vrajitor J("Joana",10,4,100);
    Vrajitor M("Merlin",10,4,10);
    Vrajitor L("Luca",10,4,10);
    Vrajitor T("Tomi",10,4,10);
    Vrajitor G("Gandalf",10,4,10);
    Vrajitor Y("Yuri",10,4,10);
    Vrajitor V("Vrajescu",10,4,10);
    Razboinic E("Enescu",30,2,6);
    Razboinic O("Onu",30,2,1);
    Razboinic A("Arthur",30,2,10);
    Razboinic B("Bogdan",30,2,5);
    Razboinic C("Cuza",30,2,3);
    Razboinic D("Dragos",30,2,3);
    Razboinic F("Florin",30,2,3);
    Ninja S("Sonic",10,10,3);
    Ninja Fa("Fantoma",10,10,3);
    Ninja Xi("Xian",10,10,3);
    Ninja Qi("Qino",10,10,3);
    Ninja Da("Daniel",10,10,3);
    Ninja Ni("Ninja",10,10,3);
    Ninja Io("Io",10,10,3);
    Orc W("Wolf",20,5,5);
    Orc Z("Zalmoxe",20,5,5);
    Orc Be("Bert",20,5,5);
    Orc Ti("Titan",20,5,5);
    Orc Mi("Minotaur",20,5,5);
    Orc Ce("Centaur",20,5,5);
    Orc Or("Orcul",20,5,5);
    Robot Ga("Gadget",10,7);
    Robot Fr("Fred",10,7);
    Robot Ro("Roboton",10,7);
    Robot Rc("RoboCap",10,7);
    Robot Cy("Cyborg",10,7);
    Robot Ex("ExMachina",10,7);
    Robot Te("Terminator",10,7);

    //Creare Efecte penru iteme de tip vraja:
    SchimbViata Sv;
    AtacMagic Foc(10);
    FurtMana Fm;
    //Creare Iteme:
    Vraja Minge("Minge de foc",4,Foc);
    Vraja Fulger("Fulger",3,Foc);
    Vraja Schimb("Schimb viata",9,Sv);
    Vraja Furt("Furt mana",2,Fm);
    Vraja Minge2("Minge de foc",5,Foc);
    Vraja Fulger2("Fulger",5,Foc);
    Vraja Schimb2("Schimb viata",10,Sv);
    Vraja Furt2("Furt mana",2,Fm);
    Scut Co("Coif",5);
    Scut Sc("Scut",6);
    Scut Ar("Armura",10);
    Scut Mar("Mar",1);
    Scut Blindare("Blindare",30);
    Amortizor Og("Oglinda",2);
    Amortizor Per("Perete",1);
    Amortizor Vesta("Vesta",2);
    Amortizor Casca("Casca",4);
    ArmaDeFoc Pis("Pistol",2,10);
    ArmaDeFoc Pus("Pusca",5,5);
    ArmaDeFoc Tun("Tun",20,1);
    ArmaDeFoc Shot("Shotgun",7,2);
    ArmaDeFoc Uzi("Uzi",1,20);
    ArmaDeFoc Bazuca("Bazuca",10,1);
    ArmaAlba Cut("Cutit",5);
    ArmaAlba Bat("Bata",3);
    ArmaAlba Topor("Topor",10);
    Potiune Via("Viata",1);
    Potiune Man("Mana",0,1);
    Potiune Sta("Stamina",0,0,1);
    Potiune Vit("Viteza",0,0,0,1);
    Potiune Via2("Viata",1);
    Potiune Man2("Mana",0,1);
    Potiune Sta2("Stamina",0,0,1);
    Potiune Vit2("Viteza",0,0,0,1);

    //Adaugare iteme:
    H.AdaugaItem(Schimb,1,5);
    H.AdaugaItem(Furt,7,15);
    H.AdaugaItem(Fulger,2,2);
    H.AdaugaItem(Minge,14,19);
    H.AdaugaItem(Blindare,17,5);
    H.AdaugaItem(Mar,5,7);
    H.AdaugaItem(Co,1,6);
    H.AdaugaItem(Sc,20,3);
    H.AdaugaItem(Ar,8,10);
    H.AdaugaItem(Og,4,15);
    H.AdaugaItem(Per,3,2);
    H.AdaugaItem(Vesta,15,8);
    H.AdaugaItem(Casca,3,10);
    H.AdaugaItem(Bat,17,17);
    H.AdaugaItem(Cut,19,16);
    H.AdaugaItem(Topor,1,18);
    H.AdaugaItem(Via,14,15);
    H.AdaugaItem(Man,7,3);
    H.AdaugaItem(Sta,17,8);
    H.AdaugaItem(Vit,6,12);
    H.AdaugaItem(Via2,16,3);
    H.AdaugaItem(Man2,16,16);
    H.AdaugaItem(Sta2,10,1);
    H.AdaugaItem(Vit2,3,19);
    H.AdaugaItem(Pis,11,18);
    H.AdaugaItem(Pus,5,20);
    H.AdaugaItem(Tun,12,2);
    H.AdaugaItem(Shot,11,6);
    H.AdaugaItem(Bazuca,12,8);
    H.AdaugaItem(Uzi,20,14);
    H.AdaugaItem(Minge2,2,5);
    H.AdaugaItem(Fulger2,2,4);
    H.AdaugaItem(Furt2,2,3);
    H.AdaugaItem(Schimb2,1,3);

    //Adaugarea agentilor pe harta:
    H.AdaugaAgent(J,1,4);
    H.AdaugaAgent(M,7,7);
    H.AdaugaAgent(L,1,13);
    H.AdaugaAgent(T,19,7);
    H.AdaugaAgent(G,3,8);
    H.AdaugaAgent(Y,19,13);
    H.AdaugaAgent(V,12,20);
    H.AdaugaAgent(E,9,7);
    H.AdaugaAgent(O,1,14);
    H.AdaugaAgent(A,11,5);
    H.AdaugaAgent(B,11,4);
    H.AdaugaAgent(C,4,2);
    H.AdaugaAgent(D,19,10);
    H.AdaugaAgent(F,12,10);
    H.AdaugaAgent(S,1,1);
    H.AdaugaAgent(Fa,6,14);
    H.AdaugaAgent(Xi,5,12);
    H.AdaugaAgent(Qi,9,18);
    H.AdaugaAgent(Da,10,20);
    H.AdaugaAgent(Ni,1,19);
    H.AdaugaAgent(Io,2,17);
    H.AdaugaAgent(W,13,1);
    H.AdaugaAgent(Z,13,11);
    H.AdaugaAgent(Be,16,2);
    H.AdaugaAgent(Ti,16,10);
    H.AdaugaAgent(Mi,18,4);
    H.AdaugaAgent(Ce,16,19);
    H.AdaugaAgent(Or,18,2);
    H.AdaugaAgent(Ga,3,5);
    H.AdaugaAgent(Fr,10,10);
    H.AdaugaAgent(Ro,11,12);
    H.AdaugaAgent(Rc,14,5);
    H.AdaugaAgent(Cy,10,14);
    H.AdaugaAgent(Ex,5,18);
    H.AdaugaAgent(Te,19,18);

    cout<<"Tastati \"ajutor\" pentru listarea comenzilor\n";
   string s;
   int complet=0;
   int completA=0;
   int completH=0;
   int sim=0;
    do
    {
    if(!complet && !completH && !completA){
    cin>>s;
    if(s=="ajutor"){
        cout<<"harta        - Afisarea hartii\n";
        cout<<"agenti       - Afisare agenti de pe harta\n";
        cout<<"iteme        - Afisare iteme de pe harta\n";
        cout<<"next         - Simularea etapei urmatoare\n";
        cout<<"complet      - Simularea pana la ultima etapa\n";
        cout<<"completHarta - Simularea pana la ultima etapa cu afisare harta\n";
        cout<<"completAgenti- Simularea pana la ultima etapa cu afisare agenti\n";
        cout<<"Se pot introduce si combinatii de forma \"next agenti\" care simuleaza o runda si afiseaza apoi agentii de pe harta\n";
    }
    if(s=="harta")
        H.Afisare();
    if(s=="agenti")
        H.AfisareAgenti();
    if(s=="iteme")
        H.AfisareIteme();
    if(s=="complet")
        complet=1;

    if(s=="completHarta")
        completH=1;
    if(s=="completAgenti")
        completA=1;
    if(s=="next")
        {sim++;
        system("CLS");
        H.Simulare();
        }
    if(s=="stop")break;
    }
    if(completA)
    {
        system("CLS");
        H.AfisareAgenti();
        H.Simulare();
        sim++;
    }
    if(complet)
        H.Simulare(),sim++;
    if(completH)
    {
        system("CLS");
        H.Afisare();
        H.Simulare();
        sim++;
    }

    }while(H.Ramasi()>1  && sim<MAXSimulari);

    cout<<"Supravietuitori:\n";
    H.AfisareAgenti();
}
