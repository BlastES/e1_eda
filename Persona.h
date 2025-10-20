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
        // Pre: --
        // Post: objecte buit
        Persona();

        // Pre: cert
        // Post: this->id = id
        Persona(int id);

        // Pre: cert
        // Post: this->id = id, this->edat = edat, this->estudis = estudis
        Persona(int id, int edat, string estudis);

        Persona(const Persona& p);

        // Pre: cert
        // Post: resultat = this->id
        int getId() const;

        Persona& operator=(const Persona& p);

        // Pre: cert
        // Post: true si this->id = p.id
        bool operator==(const Persona& p) const;

        bool operator<(const Persona& p) const;

    private:
    // Atributs
    int id;
    int edat;
    string estudis;

    void copia(const Persona& p);
    
};

#endif // PERSONA_H
