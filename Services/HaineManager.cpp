//
// Created by gionson on 4/4/21.
//

#include "HaineManager.h"
#include <utility>
#include<bits/stdc++.h>
void HaineManager::introducereHaina(std::string denumire, PiesaVestimentara piesa, Culoare cul, Stil stil, Material mat){
    Haina* haina = new Haina(denumire, piesa, cul, stil, mat);

    bool ok = adaugarePeUmeras(haina);
    if(!ok){
        std::cout<<"Dulapul este deja plin, nu mai exista umerase disponibile\n";
    }
    if(ok) {
        haineSalvate.push_back(haina);
        std::cout<<"Haina a fost adaugata cu succes\n";

    }
}

void HaineManager::introducereHaina(Haina* haina){
    bool ok = adaugarePeUmeras(haina);
    if(!ok){
        std::cout<<"Dulapul este deja plin, nu mai exista umerase disponibile\n";
    }
    if(ok) {
        haineSalvate.push_back(haina);
        std::cout<<"Haina a fost adaugata cu succes\n";

    }
}

void HaineManager::editareHaina(Haina* haina, std::string denumire, PiesaVestimentara piesa, Culoare cul, Stil stil, Material mat){
    haina->setDenumire(denumire);
    haina->setPiesaVestimentara(piesa);
    haina->setCuloare(cul);
    haina->setMaterial(mat);
    haina->setStil(stil);
}
void HaineManager::vizualizareHaina(Haina haina){
    std::cout<<haina.afisare();
}

void HaineManager::stergereHaina(Haina haina){
    // TODO
}

HaineManager::HaineManager( int nr){

    Haina haina_nula;
    for(int i=0;i<nr;i++){
        Umeras umeras(i);
        haine.push_back(umeras);
    }
    this->nrUmerase=nr;
}

/*
 * Generare outfit: temp->geaca da/nu
 * ploaie->geaca da/nu
 * totate hainele tb sa fie disponibile ca sa poata fi selectate
 * select 1 piesa dc exista, altferl sect top si bottom, top cu cele mai putine purtari, bottom asortat cu cele mai putine purtari
 * dc nu exista bottom asortat cu topul, schimam topul
 * geaca asortata cu culorile;
 * */
void HaineManager::generareTinuta(float temperatura, bool precipitatii, Stil stil){

    Haina *h[haine.size()];
    int i=0;
    for ( auto &item :haine){
        if(item.getHaina()!=NULL){
            h[i]=item.getHaina();
            i++;
        }

    }

    std::sort(h, h+i+1, [](Haina *h1, Haina *h2){return h1->getNrPurtari()<h2->getNrPurtari();});
//    for( int j=0;j<i+1;j++)
//        cout<<h[j].afisare()<<'\n';
    Haina* haine_alese[3];
    int nr_haine=0;
    if(precipitatii|| temperatura<20){
        for ( auto haina : h)
            if(haina->getPiesaVestimentara()==jacheta)
                if((temperatura>15 && (haina->getMaterial()==denim || haina->getMaterial()==bumbac ||haina->getMaterial()==poliester ))||
                temperatura<15 && (haina->getMaterial()==fas || haina->getMaterial()==lana )) {
                    haine_alese[nr_haine++] = haina;
                    break;
                }
    }
    bool piesa_gasita=false;
    for (  auto haina :h)
        if(haina->getPiesaVestimentara()==piesaUnica) {
            if (nr_haine == 0 && haina->verificarePotrivire(Alb, stil, temperatura) ||
                nr_haine == 1 && haina->verificarePotrivire(haine_alese[0]->getCuloare(), stil, temperatura)) {
                haine_alese[nr_haine] = haina;
                nr_haine++;
                piesa_gasita = true;
                break;
            }
        }
    if(!piesa_gasita) {
        bool piesa2=false;
        for (auto haina1 :h)
            if(haina1->getPiesaVestimentara()==pantaloni)
                if(nr_haine==0 && haina1->verificarePotrivire(Alb,stil,temperatura) || nr_haine==1 && haina1->verificarePotrivire(haine_alese[0]->getCuloare(),stil,temperatura) ) {
//                    haine_alese[nr_haine] = haina1;
//                    nr_haine++;
                    for (auto haina2 :h)
                    {if(haina2->getPiesaVestimentara()==top)
                        {
                            if((nr_haine==0 && haina2->verificarePotrivire(haina1->getCuloare(),stil,temperatura) )|| (nr_haine==1 && haina2->verificarePotrivire(haine_alese[0]->getCuloare(),stil,temperatura) &&
                               haina2->verificarePotrivire(haina1->getCuloare(),stil,temperatura ))) {
                                haine_alese[nr_haine] = haina1;
                                haina1->setDisponibilitate(false);
                                haina1->setNrPurtari(haina1->getNrPurtari()+1);
                                for ( auto &item :haine){
                                    if(item.getHaina()==haina1)
                                        item.setHaina(NULL);
                                        haina1->incrNrPurtari();
                                        item.setGreutateDefault();
                                        //TODO: item.first.setGreutate(item.first.getGreutateDefault()); umerasul tbuie sa fie constanta ca sa fie cheie pt map, poate apela doar fct const, nu ii pot modifica greutatea!!
                                }
                                nr_haine++;
                                haine_alese[nr_haine] = haina2;
                                haina2->setDisponibilitate(false);
                                haina2->setNrPurtari(haina2->getNrPurtari()+1);
                                nr_haine++;
                                piesa2 = true;
                                break;

                            }
                        }
                    }
                    if(piesa2)
                        break;
                }
    }
    if(nr_haine==0){
        std::cout<<"Nu se poate genera o tinuta";
    }else {
        for (int i = 0; i < nr_haine; i++) {
            std::cout << haine_alese[i]->afisare() << '\n';
        }

    }
}

void HaineManager::scoatereHaina(Haina* haina){
    Haina haina_nula;
    for(auto item:haine){
        Haina* ptr = item.getHaina();
        if(ptr==haina){
            ptr->incrNrPurtari();
            haina->setDisponibilitate(false);
            item.setHaina(NULL);
        }
    }
}
bool HaineManager::adaugarePeUmeras(Haina* haina){

    bool ok=0;
    for (auto x : haine) {
        if (x.verificareUmerasGol()) {
            x.setHaina(haina);
            ok = 1;
            break;
        }
    }

    return ok;
}

//
//void HaineManager::introducereHaina(string denumire, PiesaVestimentara piesa, Culoare cul, Stil stil, Material mat){
//    Haina haina(denumire, piesa, cul, stil, mat);
//    int ok=0;
//    for(int i=1;i<=this->nrUmerase;i++){
//        if(haine.find(i)==haine.end()){
//            haine.insert(pair<int, Haina>(i, haina));
//            ok=1;
//            break;
//        }
//    }
//    if(ok==0){
//        cout<<"Dulapul este deja plin, nu mai exista umerase disponibile";
//    }
//}
//void HaineManager::editareHaina(Haina haina, string denumire, PiesaVestimentara piesa, Culoare cul, Stil stil, Material mat){
//
//    for ( auto &item : haine){
//        if(item.second==haina){
//            item.second.setDenumire(denumire);
//            item.second.setPiesaVestimentara(piesa);
//            item.second.setCuloare(cul);
//            item.second.setStil(stil);
//            item.second.setMaterial(mat);
//        }
//    }
//
//}
//void HaineManager::vizualizareHaina(Haina haina){
//    cout<<haina.afisare();
//}
//void HaineManager::stergereHaina(Haina haina){
//    int idx;
//    for ( auto &item : haine){
//        if(item.second==haina)
//            idx=item.first;
//    }
//    haine.erase(idx);
//}
//HaineManager::HaineManager(map<int,Haina> h, int nr){
//    haine.swap(h);
//    this->nrUmerase=nr;
//}
///*
// * Generare outfit: temp->geaca da/nu
// * ploaie->geaca da/nu
// * totate hainele tb sa fie disponibile ca sa poata fi selectate
// * select 1 piesa dc exista, altferl sect top si bottom, top cu cele mai putine purtari, bottom asortat cu cele mai putine purtari
// * dc nu exista bottom asortat cu topul, schimam topul
// * geaca asortata cu culorile;
// * */
//void HaineManager::generareTinuta(float temperatura, bool precipitatii, Stil stil){
//    //sort(haine.begin(), haine.end(), [](Haina h1, Haina h2){return h1.getNrPurtari()> h2.getNrPurtari();});
//    Haina haine_alese[3];
//    int nr_haine=0;
//    if(precipitatii|| temperatura<20){
//        for ( auto &item :haine)
//            if(item.second.getPiesaVestimentara()==jacheta)
//                if((temperatura>15 && (item.second.getMaterial()==denim || item.second.getMaterial()==bumbac ||item.second.getMaterial()==poliester ))||
//                temperatura<15 && (item.second.getMaterial()==fas || item.second.getMaterial()==lana )) {
//                    haine_alese[nr_haine] = item.second;
//                    nr_haine++;
//                    break;
//                }
//    }
//    bool piesa_gasita=false;
//    for ( auto &item :haine)
//        if(item.second.getPiesaVestimentara()==piesaUnica)
//            if(nr_haine==0 && item.second.verificarePotrivire(Alb,stil,temperatura) || nr_haine==1 && item.second.verificarePotrivire(haine_alese[0].getCuloare(),stil,temperatura) ) {
//                haine_alese[nr_haine] = item.second;
//                nr_haine++;
//                piesa_gasita= true;
//                break;
//            }
//    if(!piesa_gasita)
//    {
//        bool piesa2=false;
//        for ( auto &item1 :haine)
//            if(item1.second.getPiesaVestimentara()==pantaloni)
//                if(nr_haine==0 && item1.second.verificarePotrivire(Alb,stil,temperatura) || nr_haine==1 && item1.second.verificarePotrivire(haine_alese[0].getCuloare(),stil,temperatura) ) {
////                    haine_alese[nr_haine] = item1.second;
////                    nr_haine++;
//                    for ( auto &item2 :haine)
//                    {if(item2.second.getPiesaVestimentara()==top)
//                        {
//                            if((nr_haine==0 && item2.second.verificarePotrivire(item1.second.getCuloare(),stil,temperatura) )|| (nr_haine==1 && item2.second.verificarePotrivire(haine_alese[0].getCuloare(),stil,temperatura) &&
//                               item2.second.verificarePotrivire(item1.second.getCuloare(),stil,temperatura ))) {
//                                haine_alese[nr_haine] = item1.second;
//                                item1.second.setDisponibilitate(false);
//                                item1.second.setNrPurtari(item1.second.getNrPurtari()+1);
//                                nr_haine++;
//                                haine_alese[nr_haine] = item2.second;
//                                item2.second.setDisponibilitate(false);
//                                item2.second.setNrPurtari(item2.second.getNrPurtari()+1);
//                                nr_haine++;
//                                piesa2 = true;
//                                break;
//
//                            }
//                        }
//                    }
//                    if(piesa2)
//                        break;
//
//                }
//    }
//    if(nr_haine==0){
//        cout<<"Nu se poate genera o tinuta";
//    }else {
//        for (int i = 0; i < nr_haine; i++) {
//            cout << haine_alese[i].afisare() << '\n';
//        }
//
//    }
//}