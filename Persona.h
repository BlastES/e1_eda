//
// Created by davidf on 05/09/2025
//

#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;

class Persona
{
    public:
        Persona(int id);
        Persona(int id, int edat, string estudis);
        bool operator==(const Persona& p) const;

    private:
    // Atributs
    int id;
    int edat;
    string estudis;
    
};

#endif // PERSONA_H
