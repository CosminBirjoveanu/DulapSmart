// Created by gionson on 4/4/21.
//

#ifndef SMARTDROBE_SEARCHENGINE_H
#define SMARTDROBE_SEARCHENGINE_H
#include "Haina.h"
#include "HaineManager.h"

class SearchEngine {
public:
    SearchEngine(){};
    std::map<Umeras, Haina, Umeras::UmerasCompare> cautare(std::map<Umeras, Haina, Umeras::UmerasCompare> haine, std::string nume);
    std::map<Umeras, Haina, Umeras::UmerasCompare> cautare(std::map<Umeras, Haina, Umeras::UmerasCompare> haine, PiesaVestimentara piesa);
    std::map<Umeras, Haina, Umeras::UmerasCompare> cautare(std::map<Umeras, Haina, Umeras::UmerasCompare> haine, Culoare culoare);
    std::map<Umeras, Haina, Umeras::UmerasCompare> cautare(std::map<Umeras, Haina, Umeras::UmerasCompare> haine, Stil stil);
    std::map<Umeras, Haina, Umeras::UmerasCompare> cautare(std::map<Umeras, Haina, Umeras::UmerasCompare> haine, Material material);
};

#endif //SMARTDROBE_SEARCHENGINE_H


