//
// Created by gionson on 4/4/21.
//

#include "HaineManager.h"

void HaineManager::introducereHaina(string denumire, PiesaVestimentara piesa, Culoare cul, Stil stil, Material mat){
    Haina haina(denumire, piesa, cul, stil, mat);
    int ok=0;
    for(int i=1;i<=this->nrUmerase;i++){
        if(haine.find(i)==haine.end()){
            haine.insert(pair<int, Haina>(i, haina));
            ok=1;
            break;
        }
    }
    if(ok==0){
        cout<<"Dulapul este deja plin, nu mai exista umerase disponibile";
    }
}
void HaineManager::editareHaina(Haina haina, string denumire, PiesaVestimentara piesa, Culoare cul, Stil stil, Material mat){

    for ( auto &item : haine){
        if(item.second==haina){
            item.second.setDenumire(denumire);
            item.second.setPiesaVestimentara(piesa);
            item.second.setCuloare(cul);
            item.second.setStil(stil);
            item.second.setMaterial(mat);
        }
    }

}
void HaineManager::vizualizareHaina(Haina haina){
    cout<<haina.afisare();
}
void HaineManager::stergereHaina(Haina haina){
    int idx;
    for ( auto &item : haine){
        if(item.second==haina)
            idx=item.first;
    }
    haine.erase(idx);
}
HaineManager::HaineManager(map<int,Haina> h, int nr){
    haine.swap(h);
    this->nrUmerase=nr;
}