//
// Created by davidf on 05/09/2025
//

#ifndef DISTANCIA_H
#define DISTANCIA_H

#include <string>
#include <list>
#include "Transport.h"

using namespace std;

class Distancia {
    public:
        Distancia(int codi);
        Distancia(const Distancia& d);
        void afegir(int id, int ordre, string tipusTrajecte, int horaIn, int durada, string comarcaIn, string comarcaFi, string mitjaPrincipal, int edat, string estudis);
        void ordenar_list();
        int nombreTransports() const;
        vector<pair<string, int>> nombrePersonesPerTransport() const;
        pair<string,double> mesRapid() const;
        Distancia& operator=(const Distancia& d);

    private:
        // Atributs
        int codi;
        vector<Transport> transports;
};

#endif // DISTANCIA_H
