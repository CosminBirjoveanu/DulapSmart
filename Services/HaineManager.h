//
// Created by gionson on 4/4/21.
//

#ifndef SMARTDROBE_HAINEMANAGER_H
#define SMARTDROBE_HAINEMANAGER_H
#include "../Entities/Haina.h"
#include"../Entities/Umeras.h"
#include <bits/stdc++.h>
#define NRUMERASE 20
class HaineManager {
private:
    int nrUmerase;
    std::map<Umeras,Haina, Umeras::UmerasCompare> haine;
    std::list<Haina> haineSalvate;
public:
    void setNrUmerase(int nr){nrUmerase=nr;}
    int getNrUmerase(){return nrUmerase;}
    std::map<Umeras,Haina, Umeras::UmerasCompare> getHaine(){return haine;}
    void setHaine(std::map<Umeras, Haina, Umeras::UmerasCompare> h){haine.swap(h);}
    void introducereHaina(std::string denumire, PiesaVestimentara piesa, Culoare cul, Stil stil, Material mat);
    void editareHaina(Haina haina, std::string denumire, PiesaVestimentara piesa, Culoare cul, Stil stil, Material mat);
    void vizualizareHaina(Haina haina);
    void scoatereHaina(Haina haina);
    void stergereHaina(Haina haina);
    std::list<Haina> getHaineSalvate(){return haineSalvate;}
    HaineManager( int nr);
    void generareTinuta(float temperatura, bool precipitatii, Stil stil);
    void adaugarePeUmeras(int indice);
};


#endif //SMARTDROBE_HAINEMANAGER_H