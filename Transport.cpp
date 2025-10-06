#include "material\classes\Transport.h"

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
    durada_total += durada;
}

string Transport::obtenirNom() const{
    return nom;
}

int Transport::obtenirNombrePersones() const{
    return dades.size();
}

double Transport::obtenirTempsPromig() const{
    return durada_total/dades.size();
}

bool Transport::operator==(const Transport &m) const{
    return this->nom == m.nom;
}