// Created by gionson on 4/4/21.
//

#ifndef SMARTDROBE_SEARCHENGINE_H
#define SMARTDROBE_SEARCHENGINE_H
#include "Haina.h"
#include "HaineManager.h"

class SearchEngine {
public:
    SearchEngine(){};
    map<int,Haina> cautare(map<int,Haina> haine, string nume);
    map<int,Haina> cautare(map<int,Haina> haine, PiesaVestimentara piesa);
    map<int,Haina> cautare(map<int,Haina> haine, Culoare culoare);
    map<int,Haina> cautare(map<int,Haina> haine, Stil stil);
    map<int,Haina> cautare(map<int,Haina>, Material material);
};

#endif //SMARTDROBE_SEARCHENGINE_H


