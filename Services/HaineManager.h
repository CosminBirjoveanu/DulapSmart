//
// Created by gionson on 4/4/21.
//

#ifndef SMARTDROBE_HAINEMANAGER_H
#define SMARTDROBE_HAINEMANAGER_H
#include "../Entities/Haina.h"
#include"../Entities/Umeras.h"
#include <bits/stdc++.h>
class HaineManager {
private:
    int nrUmerase;
    std::list<Haina*> haineSalvate;
    std::vector<Umeras> haine;

public:
    std::vector<Umeras> getHaine(){return haine;}
    void introducereHaina(std::string denumire, PiesaVestimentara piesa, Culoare cul, Stil stil, Material mat);
    void editareHaina(Haina* haina, std::string denumire, PiesaVestimentara piesa, Culoare cul, Stil stil, Material mat);
    void vizualizareHaina(Haina haina);
    void scoatereHaina(Haina* haina);
    void stergereHaina(Haina haina);
    std::list<Haina*> getHaineSalvate(){return haineSalvate;}
    HaineManager( int nr);
    void generareTinuta(float temperatura, bool precipitatii, Stil stil);
    bool adaugarePeUmeras(Haina* haina);
};


#endif //SMARTDROBE_HAINEMANAGER_H