//
// Created by davidf on 05/09/2025
//

#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <string>

using namespace std;

class Transport {
    public: 
        Transport(string nom);
        void afegir(int id, int ordre, string tipusTrajecte, int horaIn, int durada, string comarcaIn, string comarcaFi, int edat, string estudis);
        string obtenirNom() const;
        int obtenirNombrePersones() const;
        double obtenirTempsPromig() const;
        bool operator==(const Transport& m) const;

    private:
};

#endif // TRANSPORT_H
