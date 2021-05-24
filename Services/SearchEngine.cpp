#include "SearchEngine.h"

map<int,Haina> SearchEngine::cautare(map<int,Haina> haine, string nume) {
    map<int,Haina> haineNume;
    for (auto &item : haine)
        if(item.second.getDenumire().find(nume) != std::string::npos)
            haineNume.insert(pair<int,Haina>(item.first, item.second));
    return haineNume;
}

map<int,Haina> SearchEngine::cautare(map<int,Haina> haine, PiesaVestimentara piesa) {
    map<int,Haina> haineTip;
    for (auto &item : haine)
        if(item.second.getPiesaVestimentara() == piesa)
            haineTip.insert(pair<int,Haina>(item.first, item.second));
    return haineTip;
}

map<int,Haina> SearchEngine::cautare(map<int,Haina> haine, Culoare culoare) {
    map<int,Haina> haineCuloare;
    for (auto &item : haine)
        if(item.second.getCuloare() == culoare)
            haineCuloare.insert(pair<int,Haina>(item.first, item.second));
    return haineCuloare;
}

map<int,Haina> SearchEngine::cautare(map<int,Haina> haine, Stil stil) {
    map<int,Haina> haineStil;
    for (auto &item : haine)
        if(item.second.getStil() == stil)
            haineStil.insert(pair<int,Haina>(item.first, item.second));
    return haineStil;
}

map<int,Haina> SearchEngine::cautare(map<int,Haina> haine, Material material) {
    map<int,Haina> haineMaterial;
    for (auto &item : haine)
        if(item.second.getMaterial() == material)
            haineMaterial.insert(pair<int,Haina>(item.first, item.second));
    return haineMaterial;
}