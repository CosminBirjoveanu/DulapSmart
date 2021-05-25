// Created by gionson on 4/4/21.
//

#ifndef SMARTDROBE_SEARCHENGINE_H
#define SMARTDROBE_SEARCHENGINE_H
#include "Haina.h"
#include "HaineManager.h"

class SearchEngine {
public:
    SearchEngine(){};
    std::map<int,Haina> cautare(std::map<int,Haina> haine, std::string nume);
    std::map<int,Haina> cautare(std::map<int,Haina> haine, PiesaVestimentara piesa);
    std::map<int,Haina> cautare(std::map<int,Haina> haine, Culoare culoare);
    std::map<int,Haina> cautare(std::map<int,Haina> haine, Stil stil);
    std::map<int,Haina> cautare(std::map<int,Haina> haine, Material material);
};

#endif //SMARTDROBE_SEARCHENGINE_H


