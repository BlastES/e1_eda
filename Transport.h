//
// Created by davidf on 05/09/2025
//

#ifndef TRANSPORT_H
#define TRANSPORT_H


#include <fstream>
#include <limits>
#include <string>
#include <list>
#include <set>
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
        // Post: llista dades ordenada per durada
        void ordenarTrajectes();

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
            Persona persona;
            int ordre;
            string tipusTrajecte;
            int horaIn;
            int durada;
            string trajecte; // comarcaIn - comarcaFi
        };
        // Atributs
        string nom;

        // Ordenada de menor a major durada
        list<Info> dades; // Necessitem acces directe a l'ultim element de la llista en temps constant i necessitem que estigui ordenat per durada
        set<Persona> persones; // No hi ha duplicats i insercio logaritmica
        double durada_total;

        static bool comparacioDurada(const Info& primer, const Info& segon);


};

#endif // TRANSPORT_H
