//
// Created by alice on 24.05.2021.
//

#ifndef SMARTDROBE_UMERAS_H
#define SMARTDROBE_UMERAS_H
class Umeras{
private:
    static double greutateDefault;
    int index;
    double greutateHaina;
public:
    Umeras(int idx);
    Umeras()=default;
    int getIndex(){return index;}
    double getGreutate(){return greutateHaina;}
    void setGreutate(double greutate){this->greutateHaina=greutate;}
    bool verificareUmerasGol() const;
    struct UmerasCompare
    {
        bool operator() (const Umeras& umstg, const Umeras& umdr) const
        {
            return umstg.index < umdr.index;
        }
    };



};
#endif //SMARTDROBE_UMERAS_H
