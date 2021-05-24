//
// Created by alice on 24.05.2021.
//
#include<Umeras.h>
double Umeras::greutateDefault=0.1;
Umeras::Umeras(int idx){
    index=idx;

}
bool Umeras::verificareUmerasGol() const {
    return greutateHaina==greutateDefault;
}
