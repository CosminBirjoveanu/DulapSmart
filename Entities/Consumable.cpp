#include "Consumable.h"

Consumable::Consumable() {
    nume = "";
    cantitate = 0;
}

Consumable::Consumable(string nume, int cantitate) {
    nume = nume;
    cantitate = cantitate;
}

bool Consumable::operator ==(Consumable c){
    return nume==c.nume && cantitate == c.cantitate;
}