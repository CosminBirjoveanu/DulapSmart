//
// Created by gionson on 4/4/21.
//

#include "Haina.h"
Haina::Haina(string denumire, PiesaVestimentara piesaV, Culoare culoare, Stil stil, Material material){
    this->denumire=denumire;
    this->piesaVestimentara=piesaV;
    this->culoare=culoare;
    this->stil=stil;
    this->material=material;
    this->nrPurtari=0;
    this->disponibil=true;
    this->ultimaScoatere=time(0);

}

bool Haina:: verificarePotrivire(Culoare culoare, Stil stil, float temperatura){
    switch(culoare){
        case Rosu:
            if(this->culoare==Portocaliu || this->culoare ==Mov)
                return false;
            break;
        case Mov:
            if(this->culoare==Portocaliu || this->culoare ==Rosu)
                return false;
            break;
        case Negru:
            if(this->culoare==Bleumarin)
                return false;
            break;
        case Bleumarin:
            if(this->culoare==Negru)
                return false;
            break;
        case Portocaliu:
            if(this->culoare==Rosu || this->culoare ==Mov)
                return false;
            break;
    }

    if(this->stil!=stil)
        return false;

    if(temperatura>20){
        switch(material){
            case fas:
                return false;

            case lana:
                return false;

            case stofa:
                return false;
        }

    }else if(temperatura<15){
        switch(material){
            case in:
                return false;

            case matase:
                return false;

        }
    }
    return true;
}

string Haina::afisare(){
    string str=denumire+" ";
    switch (piesaVestimentara) {
        case jacheta:
            str+="jacheta ";
            break;
        case top:
            str+="top ";
            break;
        case pantaloni:
            str+="pantaloni/fusta ";
            break;
        case piesaUnica:
            str+="o piesa ";
            break;

    }
    switch (culoare) {
        case Alb:
            str+="alb ";
            break;
        case Negru:
            str+="negru ";
            break;
        case Albastru:
            str+="albastru ";
            break;
        case Rosu:
            str+="rosu ";
            break;
        case Verde:
            str+="verde ";
            break;
        case Portocaliu:
            str+="portocaliu ";
            break;
        case Mov:
            str+="mov ";
            break;
        case Bleumarin:
            str+="bleumarin ";
            break;
        case Bej:
            str+="Bej ";
            break;
        case Maro:
            str+="maro ";
            break;
    }


    switch (stil) {
        case casual:
            str+="casual ";
            break;
        case sport:
            str+="sport ";
            break;
        case formal:
            str+="formal ";
            break;
        case business:
            str+="business ";
            break;

    }

    switch (material) {
        case poliester:
            str+="poliester ";
            break;
        case stofa:
            str+="stofa ";
            break;
        case bumbac:
            str+="bumbac ";
            break;
        case denim:
            str+="denim ";
            break;
        case matase:
            str+="matase ";
            break;
        case in:
            str+="in ";
            break;
        case lana:
            str+="lana ";
            break;
        case fas:
            str+="fas ";
            break;
    }
    str+="nr purtari:"+to_string(nrPurtari)+" ";
    disponibil? str+="disponibil ": str+="indisponibil ";
    tm *data = localtime(&ultimaScoatere);
    int luna=(data->tm_mon+1);
    int an=(data->tm_year+1900);
    str+=to_string(data->tm_mday)+" "+to_string(luna)+" "+to_string(an);
    return str;
}
bool Haina::operator ==(Haina h){
    return denumire==h.denumire&& culoare==h.culoare && material==h.material && stil==h.stil && piesaVestimentara==h.piesaVestimentara;
}
//Haina::Haina(string denumire, PiesaVestimentara piesaV, Culoare culoare, Stil stil, Material material){
//    this->denumire=denumire;
//    this->piesaVestimentara=piesaV;
//    this->culoare=culoare;
//    this->stil=stil;
//    this->material=material;
//    this->nrPurtari=0;
//    this->disponibil=true;
//
//}
//
//bool Haina:: verificarePotrivire(Culoare culoare, Stil stil, float temperatura){
//    switch(culoare){
//        case Rosu:
//            if(this->culoare==Portocaliu || this->culoare ==Mov)
//                return false;
//            break;
//        case Mov:
//            if(this->culoare==Portocaliu || this->culoare ==Rosu)
//                return false;
//            break;
//        case Negru:
//            if(this->culoare==Bleumarin)
//                return false;
//            break;
//        case Bleumarin:
//            if(this->culoare==Negru)
//                return false;
//            break;
//        case Portocaliu:
//            if(this->culoare==Rosu || this->culoare ==Mov)
//                return false;
//            break;
//    }
//
//    if(this->stil!=stil)
//        return false;
//
//    if(temperatura>20){
//        switch(material){
//            case fas:
//                return false;
//
//            case lana:
//                return false;
//
//            case stofa:
//                return false;
//        }
//
//    }else if(temperatura<15){
//        switch(material){
//            case in:
//                return false;
//
//            case matase:
//                return false;
//
//        }
//    }
//    return true;
//}
//
//string Haina::afisare(){
//    string str=denumire+" ";
//    switch (piesaVestimentara) {
//        case jacheta:
//            str+="jacheta ";
//            break;
//        case top:
//            str+="top ";
//            break;
//        case pantaloni:
//            str+="pantaloni/fusta ";
//            break;
//        case piesaUnica:
//            str+="o piesa ";
//            break;
//
//    }
//    switch (culoare) {
//        case Alb:
//            str+="alb ";
//            break;
//        case Negru:
//            str+="negru ";
//            break;
//        case Albastru:
//            str+="albastru ";
//            break;
//        case Rosu:
//            str+="rosu ";
//            break;
//        case Verde:
//            str+="verde ";
//            break;
//        case Portocaliu:
//            str+="portocaliu ";
//            break;
//        case Mov:
//            str+="mov ";
//            break;
//        case Bleumarin:
//            str+="bleumarin ";
//            break;
//        case Bej:
//            str+="Bej ";
//            break;
//        case Maro:
//            str+="maro ";
//            break;
//    }
//
//
//        switch (stil) {
//            case casual:
//                str+="casual ";
//                break;
//            case sport:
//                str+="sport ";
//                break;
//            case formal:
//                str+="formal ";
//                break;
//            case business:
//                str+="business ";
//                break;
//
//        }
//
//    switch (material) {
//        case poliester:
//            str+="poliester ";
//            break;
//        case stofa:
//            str+="stofa ";
//            break;
//        case bumbac:
//            str+="bumbac ";
//            break;
//        case denim:
//            str+="denim ";
//            break;
//        case matase:
//            str+="matase ";
//            break;
//        case in:
//            str+="in ";
//            break;
//        case lana:
//            str+="lana ";
//            break;
//        case fas:
//            str+="fas ";
//            break;
//    }
//    str+="nr purtari:"+to_string(nrPurtari)+" ";
//    disponibil? str+="disponibil": str+="indisponibil";
//    return str;
//}
//bool Haina::operator ==(Haina h){
//    return denumire==h.denumire&& culoare==h.culoare && material==h.material && stil==h.stil && piesaVestimentara==h.piesaVestimentara;
//}