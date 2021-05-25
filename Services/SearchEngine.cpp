#include "SearchEngine.h"
using namespace std;
std::map<Umeras, Haina, Umeras::UmerasCompare> SearchEngine::cautare(std::map<Umeras, Haina, Umeras::UmerasCompare> haine, std::string nume) {
    std::map<Umeras, Haina, Umeras::UmerasCompare> haineNume;
    for (auto &item : haine)
        if(item.second.getDenumire().find(nume) != std::string::npos)
            haineNume.insert(pair<Umeras,Haina>(item.first, item.second));
    return haineNume;
}

map<Umeras, Haina, Umeras::UmerasCompare> SearchEngine::cautare(map<Umeras, Haina, Umeras::UmerasCompare> haine, PiesaVestimentara piesa) {
    map<Umeras, Haina, Umeras::UmerasCompare> haineTip;
    for (auto &item : haine)
        if(item.second.getPiesaVestimentara() == piesa)
            haineTip.insert(pair<Umeras,Haina>(item.first, item.second));
    return haineTip;
}

map<Umeras, Haina, Umeras::UmerasCompare> SearchEngine::cautare(map<Umeras, Haina, Umeras::UmerasCompare> haine, Culoare culoare) {
    map<Umeras, Haina, Umeras::UmerasCompare> haineCuloare;
    for (auto &item : haine)
        if(item.second.getCuloare() == culoare)
            haineCuloare.insert(pair<Umeras, Haina>(item.first, item.second));
    return haineCuloare;
}

map<Umeras, Haina, Umeras::UmerasCompare> SearchEngine::cautare(map<Umeras, Haina, Umeras::UmerasCompare> haine, Stil stil) {
    map<Umeras, Haina, Umeras::UmerasCompare> haineStil;
    for (auto &item : haine)
        if(item.second.getStil() == stil)
            haineStil.insert(pair<Umeras, Haina>(item.first, item.second));
    return haineStil;
}

map<Umeras, Haina, Umeras::UmerasCompare> SearchEngine::cautare(map<Umeras, Haina, Umeras::UmerasCompare> haine, Material material) {
    map<Umeras, Haina, Umeras::UmerasCompare> haineMaterial;
    for (auto &item : haine)
        if(item.second.getMaterial() == material)
            haineMaterial.insert(pair<Umeras, Haina>(item.first, item.second));
    return haineMaterial;
}