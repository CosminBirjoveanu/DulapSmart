#include "SearchEngine.h"
using namespace std;
std::vector<Umeras> SearchEngine::cautare(std::vector<Umeras> haine, std::string nume) {
    std::vector<Umeras> haineNume;
    for (auto item : haine)
        if((item.haina)->getDenumire().find(nume) != std::string::npos)
            haineNume.push_back(item);
    return haineNume;
}

vector<Umeras> SearchEngine::cautare(vector<Umeras> haine, PiesaVestimentara piesa) {
    vector<Umeras> haineTip;
    for (auto &item : haine)
        if((item.haina)->getPiesaVestimentara() == piesa)
            haineTip.push_back(item);
    return haineTip;
}

vector<Umeras> SearchEngine::cautare(vector<Umeras> haine, Culoare culoare) {
    vector<Umeras> haineCuloare;
    for (auto &item : haine)
        if((item.haina)->getCuloare() == culoare)
            haineCuloare.push_back(item);
    return haineCuloare;
}

vector<Umeras> SearchEngine::cautare(vector<Umeras> haine, Stil stil) {
    vector<Umeras> haineStil;
    for (auto &item : haine)
        if((item.haina)->getStil() == stil)
            haineStil.push_back(item);
    return haineStil;
}

vector<Umeras> SearchEngine::cautare(vector<Umeras> haine, Material material) {
    vector<Umeras> haineMaterial;
    for (auto &item : haine)
        if((item.haina)->getMaterial() == material)
            haineMaterial.push_back(item);
    return haineMaterial;
}