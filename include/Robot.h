#ifndef ROBOT_H
#define ROBOT_H
#include "Agent.h"

class Robot : public Agent
{
private:
    const static int raza = 4;
    const static int vitezaAtac = 1;
    int dauna;
public:
    Robot(const string & numeRobot,int viataRobot,int daunaRobot): Agent(numeRobot,viataRobot), dauna(daunaRobot){};
    virtual ~Robot(){};
    virtual int Raza() const{return raza;}
    virtual int Dauna()const{return dauna;}
    virtual int VitezaAtac()const {return vitezaAtac;}
    virtual tipAgent Tip()const {return robot;}
    virtual void Afisare() const;
};


#endif // ROBOT_H
