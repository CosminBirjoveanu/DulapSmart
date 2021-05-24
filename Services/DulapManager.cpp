#include "DulapManager.h"
#include <thread>
#include <chrono>

DulapManager::DulapManager(string numeDezinfectant, string numeParfum){
    apa.setFull();
    apa.setNume("apa");
    dezinfectant.setFull();
    dezinfectant.setNume(numeDezinfectant);
    parfum.setFull();
    parfum.setNume(numeParfum);
}

bool DulapManager::spray(Consumable& c) {
    if (c.getProcent() > 0) {
        c.spray(2);
        std::cout << "Spray " << c.getNume() << ", " << c.getProcent() << "\n";
        return true;
    }
    return false;
}

void DulapManager::sprayThread(int timer, Consumable& c){
    while (true) {
        if (spray(c))
            std::this_thread::sleep_for(std::chrono::seconds(timer));
        else break;
    }
}