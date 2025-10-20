//
// Created by davidf on 05/09/2025
//

#ifndef DISTANCIA_H
#define DISTANCIA_H

#include <string>
#include <map>
#include "Transport.h"

using namespace std;

class Distancia {
    public:
        // Pre: cert
        // Post: *this->codi = codi
        Distancia(int codi);

        // Pre: cert
        // Post: *this és copia de d
        Distancia(const Distancia& d);

        // Pre: cert
        // Post: informació afegida al respectiu espai del vector transports
        void afegir(int id, int ordre, string tipusTrajecte, int horaIn, int durada, string comarcaIn, string comarcaFi, string mitjaPrincipal, int edat, string estudis);
        
        // Pre: --
        // Post: vector transports ordenat per nombre de viatges de major a menor
        void ordenar_vec();

        // Pre: --
        // Post: resultat = nombre d'elements de transports
        int nombreTransports() const;

        // Pre: --
        // Post: resultat = vector de parelles en la que el primer element de cada espai
        // és el nom del transport i el segon element és el nombre de persones d'aquest transport
        vector<pair<string, int>> nombrePersonesPerTransport() const;

        // Pre: --
        // Post: resutlat = nom del transport amb menor temps mig i el seu temps mig
        pair<string,double> mesRapid() const;

        pair<string, double> trajecteMesLlarg() const;

        map<string, int> llistaTrajectes() const;

        // Pre: cert
        // Post: *this és copia de d i retorna *this
        Distancia& operator=(const Distancia& d);

    private:
        // Atributs
        int codi;
        vector<Transport> transports;
        map<string, int> trajectes; // trajecte, durada
        map<string, int>::iterator trajMesLlarg; // iterador apuntant al trajecte de major durada

        // Pre: cert
        // Post: vector transports ordenat per nombre de persones de major a menor
        void quick_sort(int esq, int dre);
        void particio(int esq, int dre, int& pos_pivot);
        void intercanvi(Transport& x, Transport& y);
};

#endif // DISTANCIA_H
