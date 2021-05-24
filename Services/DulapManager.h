#ifndef SMARTDROBE_DULAPMANAGER_H
#define SMARTDROBE_DULAPMANAGER_H
#include "Consumable.h"

class DulapManager {
private:
    Consumable apa;
    Consumable dezinfectant;
    Consumable parfum;
public:
    DulapManager();
    DulapManager(string numeDezinfectant, string numeParfum);
    Consumable& getApa(){return apa;}
    Consumable& getDezinfectant(){return dezinfectant;}
    Consumable& getParfum(){return parfum;}
    void setFull(){apa.setFull(); dezinfectant.setFull(); parfum.setFull();}
    bool spray(Consumable& c);
    void sprayThread(int timer, Consumable& c);
};


#endif //SMARTDROBE_DULAPMANAGER_H
