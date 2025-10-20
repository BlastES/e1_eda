#include "Persona.h"

Persona::Persona(){
    id = 0;
    edat = 0;
    estudis = "Buit";
}

Persona::Persona(int id){
    this->id = id;
}

Persona::Persona(int id, int edat, string estudis){
    this->id = id;
    this->edat = edat;
    this->estudis = estudis;
}

Persona::Persona(const Persona& p){
    copia(p);
}

int Persona::getId() const{
    return id;
}

Persona& Persona::operator=(const Persona& p){
    copia(p);
    return *this;
}

bool Persona::operator==(const Persona& p) const{
    return this->id == p.id;
}

bool Persona::operator<(const Persona& p) const{
    return this->id < p.id;
}
void Persona::copia(const Persona& p){
    this->id = p.id;
    this->edat = p.edat;
    this->estudis = p.estudis;
}

