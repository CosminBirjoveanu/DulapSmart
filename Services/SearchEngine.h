// Created by gionson on 4/4/21.
//

#ifndef SMARTDROBE_SEARCHENGINE_H
#define SMARTDROBE_SEARCHENGINE_H
#include "Haina.h"
#include "HaineManager.h"

class SearchEngine {
public:
    SearchEngine(){};
    std::vector <Umeras> cautare (std::vector <Umeras> haine, std::string nume);
    std::vector <Umeras> cautare (std::vector <Umeras> haine, PiesaVestimentara piesa);
    std::vector <Umeras> cautare (std::vector <Umeras> haine, Culoare culoare);
    std::vector <Umeras> cautare (std::vector <Umeras> haine, Stil stil);
    std::vector <Umeras> cautare (std::vector <Umeras> haine, Material material);
};

#endif //SMARTDROBE_SEARCHENGINE_H


