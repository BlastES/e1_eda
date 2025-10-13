#include "Transport.h"
#include <iostream>

Transport::Transport(string nom){
    this->nom = nom;
    durada_total = 0;
}

void Transport::afegir(int id, int ordre, string tipusTrajecte, int horaIn, int durada, string comarcaIn, string comarcaFi, int edat, string estudis){
    Info i;
    i.id = id;
    i.ordre = ordre;
    i.tipusTrajecte = tipusTrajecte;
    i.horaIn = horaIn;
    i.durada = durada;
    i.comarcaIn = comarcaIn;
    i.comarcaFi = comarcaFi;
    i.edat = edat;
    i.estudis = estudis;
    bool trobat = false;
    vector<Persona>::iterator it = persones.begin();
    while(!trobat and it != persones.end()){
        if(*it == Persona(id)) trobat = true;
        else it++;
    }
    if(!trobat){
        persones.push_back(Persona(id, edat, estudis));
    }
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