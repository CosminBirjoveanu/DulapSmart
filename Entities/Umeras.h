//
// Created by alice on 24.05.2021.
//

#ifndef SMARTDROBE_UMERAS_H
#define SMARTDROBE_UMERAS_H
class Umeras{
private:
    static double greutateDefault;
    static int index;
    double greutateHaina;
public:
    Umeras(int idx);
    Umeras()=default;
    int getIndex(){return index;}
    double getGreutate(){return greutateHaina;}
    void setGreutate(double greutate){this->greutateHaina=greutate;}
    bool verificareUmerasGol() const;
};
#endif //SMARTDROBE_UMERAS_H
