//
// Created by alice on 24.05.2021.
//

#ifndef SMARTDROBE_UMERAS_H
#define SMARTDROBE_UMERAS_H

#include "Haina.h"

class Umeras{
private:
    int index;
    double greutateHaina;
    Haina* haina;

public:
    friend class SearchEngine;
    Umeras(int idx);
    Umeras()=default;
    int getIndex() const {return index;}
    Haina* getHaina()  {return haina;}
    double getGreutate(){return greutateHaina;}
    void setGreutate(double greutate){this->greutateHaina=greutate;}
    void setGreutateDefault(){this->greutateHaina=0;}
    bool verificareUmerasGol() const;
    void setHaina(Haina*);
};

#endif //SMARTDROBE_UMERAS_H
