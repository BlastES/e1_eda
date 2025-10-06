//
// Created by davidf on 05/09/2025
//

#ifndef TRANSPORT_H
#define TRANSPORT_H


#include <fstream>
#include <limits>
#include <string>
#include <vector>
#include "eines_csv\eines.h"


using namespace std;

class Transport {
    public: 
        Transport(string nom);
        void afegir(int id, int ordre, string tipusTrajecte, int horaIn, int durada, string comarcaIn, string comarcaFi, int edat, string estudis);
        string obtenirNom() const;
        int obtenirNombrePersones() const;
        double obtenirTempsPromig() const; //Cost lineal
        bool operator==(const Transport& m) const;
    private:
        struct Info{
            int id;
            int ordre;
            string tipusTrajecte;
            int horaIn;
            int durada;
            string comarcaIn;
            string comarcaFi;
            int edat;
            string estudis;
        };
        // Atributs
        string nom;
        vector<Info> dades;
        double durada_total;


};

#endif // TRANSPORT_H
