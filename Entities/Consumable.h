#ifndef SMARTDROBE_CONSUMABLE_H
#define SMARTDROBE_CONSUMABLE_H

#include <string>
#include <iostream>
using namespace std;

class Consumable{
private:
    string nume;
    int cantitate;
public:
    Consumable();
    Consumable(string nume, int cantitate);
    string getNume(){return nume;}
    int getProcent(){return cantitate;}
    void setNume(string denumire){nume = denumire;}
    void setProcent(int nr){cantitate = nr;}
    void spray(int nr){cantitate -= nr;}
    void setFull(){cantitate = 100;}
    bool operator ==(Consumable c);
};

#endif //SMARTDROBE_CONSUMABLE_H
