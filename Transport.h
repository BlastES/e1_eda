//
// Created by davidf on 05/09/2025
//

#ifndef TRANSPORT_H
#define TRANSPORT_H


#include <fstream>
#include <limits>
#include <string>
#include <vector>
#include "eines.h"
#include "Persona.h"


using namespace std;

class Transport {
    public:
        // Pre: cert
        // Post: this->nom = nom
        Transport(string nom);

        // Pre: cert
        // Post: variables guardades als respectius espais de info i info guardada a vector dades
        void afegir(int id, int ordre, string tipusTrajecte, int horaIn, int durada, string comarcaIn, string comarcaFi, int edat, string estudis);
        
        // Pre: --
        // Post: resultat = this->nom
        string obtenirNom() const;

        // Pre: --
        // Post: resutlat = tamany vector dades
        int obtenirNombrePersones() const;

        // Pre: --
        // Post: resutlat = temps_total / nombre de persones
        double obtenirTempsPromig() const;

        // Pre: cert
        // Post: true si this->nom = m.nom
        bool operator==(const Transport& m) const;

        // Pre: cert
        // Post: true si this->dades.size() <  m.dades.size()
        bool operator<(const Transport& m) const;

        // Pre: cert
        // Post: true si this->dades.size() <=  m.dades.size()
        bool operator<=(const Transport& m) const;

        // Pre: cert
        // Post: true si this->dades.size() >  m.dades.size()
        bool operator>(const Transport& m) const;

        // Pre: cert
        // Post: true si this->dades.size() >=  m.dades.size()
        bool operator>=(const Transport& m) const;

        // Pre: cert
        // Post: *this és copia de m i resultat = *this
        Transport& operator=(const Transport& m);
        

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
        vector<Persona> persones;
        double durada_total;


};

#endif // TRANSPORT_H
