//
// Created by gionson on 4/4/21.
//

#ifndef SMARTDROBE_HAINEMANAGER_H
#define SMARTDROBE_HAINEMANAGER_H
#include "Haina.cpp"
#include"Umeras.h"
#define NRUMERASE 20
class HaineManager {
private:
    int nrUmerase;
    map<Umeras,Haina, Umeras::UmerasCompare> haine;
public:
    void setNrUmerase(int nr){nrUmerase=nr;}
    int getNrUmerase(){return nrUmerase;}
    map<Umeras,Haina, Umeras::UmerasCompare> getHaine(){return haine;}
    void setHaine(map<Umeras, Haina, Umeras::UmerasCompare> h){haine.swap(h);}
    void introducereHaina(string denumire, PiesaVestimentara piesa, Culoare cul, Stil stil, Material mat);
    void editareHaina(Haina haina, string denumire, PiesaVestimentara piesa, Culoare cul, Stil stil, Material mat);
    void vizualizareHaina(Haina haina);
    void stergereHaina(Haina haina);
    HaineManager( int nr);
    void generareTinuta(float temperatura, bool precipitatii, Stil stil);

};


#endif //SMARTDROBE_HAINEMANAGER_H