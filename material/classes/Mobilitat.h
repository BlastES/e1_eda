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
        Mobilitat();
        int llegirDades(const string& path);
        int nombreTransports(int distancia) const; 
        vector<pair<string, int>> nombrePersonesPerTransport(int distancia) const;
        vector<pair<string, int>> mesRapid() const;

    private:
        vector<Distancia> dist;
        vector<Persona> persones;

};


#endif //MOBILITAT_H
