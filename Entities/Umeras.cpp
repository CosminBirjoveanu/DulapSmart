//
// Created by alice on 24.05.2021.
//
#include<Umeras.h>
Umeras::Umeras(int idx){
    index=idx;
    greutateDefault=0.1;
}
bool Umeras::verificareUmerasGol() const {
    return greutateHaina==greutateDefault;
}
