//
// Created by davidf on 05/09/2025
//

#ifndef MOBILITAT_H
#define MOBILITAT_H

#include <string>

using namespace std;

class Mobilitat {
    public:
        Mobilitat();
        int llegirDades(const string& path);
        int nombreTransports(int distancia) const; 
        CONTENIDOR nombrePersonesPerTransport(int distancia) const;
        CONTENIDOR mesRapid() const;

    private:

};


#endif //MOBILITAT_H
