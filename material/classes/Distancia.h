//
// Created by davidf on 05/09/2025
//

#ifndef DISTANCIA_H
#define DISTANCIA_H

#include <string>

using namespace std;

class Distancia {
    public: 
        void afegir(int id, int ordre, string tipusTrajecte, int horaIn, int durada, string comarcaIn, string comarcaFi, string mitjaPrincipal, int edat, string estudis);
        int nombreTransports() const;
        CONTENIDOR nombrePersonesPerTransport() const;
        pair<string,double> mesRapid() const;

    private:
};

#endif // DISTANCIA_H
