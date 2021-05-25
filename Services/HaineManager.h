//
// Created by gionson on 4/4/21.
//

#ifndef SMARTDROBE_HAINEMANAGER_H
#define SMARTDROBE_HAINEMANAGER_H
#include "../Entities/Haina.h"
#include"../Entities/Umeras.h"
#define NRUMERASE 20
class HaineManager {
private:
    int nrUmerase;
    map<Umeras,Haina, Umeras::UmerasCompare> haine;
    list<Haina> haineSalvate;
public:
    void setNrUmerase(int nr){nrUmerase=nr;}
    int getNrUmerase(){return nrUmerase;}
    map<Umeras,Haina, Umeras::UmerasCompare> getHaine(){return haine;}
    void setHaine(map<Umeras, Haina, Umeras::UmerasCompare> h){haine.swap(h);}
    void introducereHaina(string denumire, PiesaVestimentara piesa, Culoare cul, Stil stil, Material mat);
    void editareHaina(Haina haina, string denumire, PiesaVestimentara piesa, Culoare cul, Stil stil, Material mat);
    void vizualizareHaina(Haina haina);
    void scoatereHaina(Haina haina);
    void stergereHaina(Haina haina);
    list<Haina> getHaineSalvate(){return haineSalvate;}
    HaineManager( int nr);
    void generareTinuta(float temperatura, bool precipitatii, Stil stil);
    void adaugarePeUmeras(int indice);
};


#endif //SMARTDROBE_HAINEMANAGER_H