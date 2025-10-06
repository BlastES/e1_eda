#include "Transport.h"


Transport::Transport(string nom): nom(nom), durada_total(0){}


void Transport::afegir(int id, int ordre, string tipusTrajecte, int horaIn,  double durada, string comarcaIn, string comarcaFi, int edat, string estudis){
    Info nova_info = {
        id,
        ordre,
        tipusTrajecte,
        horaIn,
        durada,
        comarcaIn,
        comarcaFi,
        edat,
        estudis
    };
    dades.push_back(nova_info);

    durada_total += durada;
}

string Transport::obtenirNom()const{

 return nom;
 }


int Transport::obtenirNombrePersones() const{

return dades.size();
}

double Transport::obtenirTempsPromig()const{

return durada_total/obtenirNombrePersones();
 }

bool Transport::operator==(const Transport& m) const {
    return nom == m.nom;
}





