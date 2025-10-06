#include "material\classes\Persona.h"

Persona::Persona(int id){
    this->id = id;
}

Persona::Persona(int id, int edat, string estudis){
    this->id = id;
    this->edat = edat;
    this->estudis = estudis;
}

bool Persona::operator==(const Persona& p) const{
    return this->id == p.id;
}

