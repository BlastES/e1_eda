#include "Transport.h"
#include <iostream>

Transport::Transport(string nom){
    this->nom = nom;
    durada_total = 0;
}

void Transport::afegir(int id, int ordre, string tipusTrajecte, int horaIn, int durada, string comarcaIn, string comarcaFi, int edat, string estudis){
    Info i;
    i.persona = Persona(id, edat, estudis);
    i.ordre = ordre;
    i.tipusTrajecte = tipusTrajecte;
    i.horaIn = horaIn;
    i.durada = durada;
    i.trajecte = comarcaIn + " - " + comarcaFi;
    persones.insert(Persona(id, edat, estudis));
    dades.push_back(i);
    durada_total += durada;
}

string Transport::obtenirNom() const{
    return nom;
}

int Transport::obtenirNombrePersones() const{
    return persones.size();
}

double Transport::obtenirTempsPromig() const{
    return durada_total/dades.size();
}

void Transport::ordenarTrajectes(){
    dades.sort(comparacioDurada);
}

bool Transport::operator==(const Transport &m) const{
    return this->nom == m.nom;
}

bool Transport::operator<(const Transport &m) const{
    return dades.size() < m.dades.size();
}

bool Transport::operator<=(const Transport &m) const{
    return dades.size() <= m.dades.size();
}

bool Transport::operator>(const Transport &m) const{
    return dades.size() > m.dades.size();
}

bool Transport::operator>=(const Transport &m) const{
    return dades.size() >= m.dades.size();
}

Transport& Transport::operator=(const Transport& m){
    this->nom = m.nom;
    this->durada_total = m.durada_total;
    this->dades = m.dades;
    this->persones = m.persones;
    return *this;
}

bool Transport::comparacioDurada(const Info& primer, const Info& segon){
    return primer.durada < segon.durada;
}