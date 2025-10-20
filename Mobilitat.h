//
// Created by davidf on 05/09/2025
//

#ifndef MOBILITAT_H
#define MOBILITAT_H

#include <string>
#include "Distancia.h"
//#include "Transport.h"
#include "Persona.h"

using namespace std;

class Mobilitat {
    public:
        // Pre: --
        // Post: objecte buit
        Mobilitat();

        // Pre: cert
        // Post: carrega les dades del fitxer csv a dist i persones.
        int llegirDades(const string& path);

        // Pre: 1 <= distancia <= 7
        // Post: retorna el nombre de transports del codi de distancia proporcionat
        int nombreTransports(int distancia) const;
        
        // Pre: 1 <= distancia <= 7
        // Post: retorna un vector de parelles en el que el primer element de cada espai és el nom del
        // transport i el segon element és el nombre de persones d'aquest transport
        vector<pair<string, int>> nombrePersonesPerTransport(int distancia) const;

        // Pre: --
        // Post: retorna un vector de parelles en el que el  primer element de cada espai és el nom del
        // transport amb el menor temps mig del respectiu codi de distancia i el segon element és el temps mig d'aquest transport
        vector<pair<string, double>> mesRapid() const;

        // Pre: --
        // Post: retorna el trajecte de major durada y el tipus de trajecte (comarcaIn - comarcaFi)
        pair<string, double> trajecteMesLlarg() const;

        vector<list<string>> trajectesNous() const;

    private:
        // Atributs
        vector<Distancia> dist; // Necesitem acces directe als diferents codis de distancia
};


#endif //MOBILITAT_H
