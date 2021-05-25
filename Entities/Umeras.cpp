//
// Created by alice on 24.05.2021.
//
#include "Umeras.h"
Umeras::Umeras(int idx){
    index=idx;
    haina = NULL;
}
bool Umeras::verificareUmerasGol() const {
    return haina == NULL;
}

void Umeras::setHaina(Haina* haina) {
    this->haina = haina;
}