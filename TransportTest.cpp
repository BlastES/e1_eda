#include "Distancia.h"
#include <iostream>
using namespace std;

int main(){
    Transport a("choo choo");
    Distancia b(123);
    a.afegir(123, 2, "alkdsfj", 123123, 123, "alkdjf", "alkjdf", 12, "alkjdsf");
    b.afegir(123456789, 1, "trajecte", 24, 12, "com1", "com2", "coche", 16, "nada");
    cout << b.mesRapid().first << " " << b.mesRapid().second << " " << b.nombrePersonesPerTransport().at(0).first << " " << b.nombrePersonesPerTransport().at(0).second << " " << b.nombreTransports() << endl;
    cout << a.obtenirNom() << " " << a.obtenirNombrePersones() << " " << a.obtenirTempsPromig() << endl;
    int n;
    cin >> n;
    return 0;
}