#include "Mobilitat.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Pre: --
// Post: imprimeix per pantalla la capçalera de l'opció escollida
void titol_opcions(int i){
    switch (i)
    {
    case 1:
        cerr << setfill('*') << setw(20) << endl;
        cerr << "* 01: Llegir dades *" << endl;
        cerr << setfill('*') << setw(20) << endl;
        break;
    
    case 2:
        cerr << setfill('*') << setw(25) << endl;
        cerr << "* 02: Nombre transports *" << endl;
        cerr << setfill('*') << setw(25) << endl;
        break;
    
    case 3:
        cerr << setfill('*') << setw(37) << endl;
        cerr << "* 03: Nombre persones per transport *" << endl;
        cerr << setfill('*') << setw(37) << endl;
        break;
    
    case 4:
        cerr << setfill('*') << setw(19) << endl;
        cerr << "* 04: Més ràpid *" << endl;
        cerr << setfill('*') << setw(19) << endl;   
        break;     

    default:
        break;
    }
}

// Pre: --
// Post: Imprimeix per pantalla la representació escrita del codi de distància
void codis_distancia(int i){
    switch (i)
    {
    case 1:
        cout << "Menys de 500 metres";
        break;

    case 2:
        cout << "De 500 a 2.000 metres";
        break;

    case 3:
        cout << "De 2.000 a 5.000 metres";
        break;

    case 4:
        cout << "De 5.000 a 10.000 metres";
        break;
        
    case 5:
        cout << "De 10.000 a 50.000 metres";
        break;

    case 6:
        cout << "De 50.000 a 100.000 metres";
        break;

    case 7:
        cout << "Més de 100.000 metres";
        break;
    
    default:
        break;
    }
}

// Pre: cert
// Post: Llegeix el nom del fitxer i emmagatzema les dades en l'objecte mob
void opcio_1(Mobilitat& mob){
    string file_name;
    cin >> file_name;
    int linies_llegides = mob.llegirDades(file_name);
    cout << "Numero de linies: " << linies_llegides << endl;
}

// Pre: cert
// Post: Donat un codi de distancia, imprimeix la representació escrita del codi de distancia seguida del
// nombre de transports que pertanyen a la distancia indicada
void opcio_2(Mobilitat& mob){
    int codi_distancia;
    cin >> codi_distancia;
    int n_transports = mob.nombreTransports(codi_distancia);
    cout << "Distància ";
    codis_distancia(codi_distancia);
    cout << " ==> " << n_transports << endl;    
}

// Pre: cert
// Post: Donat un codi de distancia, imprimeix la llista de veicles de la distancia indicada
// seguida del nombre de persones de cada mitjà. Ho imprimeix en ordre descendent del nombre de persones
void opcio_3(Mobilitat& mob){
    int codi_distancia;
    cin >> codi_distancia;
    codis_distancia(codi_distancia);
    cout << endl;
    vector<pair<string, int>> vec = mob.nombrePersonesPerTransport(codi_distancia);
    for(int i = 0; i < vec.size(); i++){
        cout << i << " : " << vec.at(i).first << " => " << vec.at(i).second << endl; 
    }
}

// Pre: cert
// Post: imprimeix per cada codi de distancia, el vehicle més ràpid i el temps promig de
// tots els viatges realitzats amb aquest vehicle.
void opcio_4(Mobilitat& mob){
    vector<pair<string, double>> vec = mob.mesRapid();
    for(int i = 1; i <= 7; i++){
        codis_distancia(i);
        cout << " : " << vec.at(i-1).first << " => " << vec.at(i-1).second << endl;
    }
}

// Pre: 1 <= i <= 4
// Post: imprimeix el titol de la operació seleccionada i executa la tasca
void operacions_menu(int i, Mobilitat& mob){
    titol_opcions(i);
    switch (i)
    {
    case 1:
        opcio_1(mob);
        break;
    
    case 2:
        opcio_2(mob);
        break;

    case 3:
        opcio_3(mob);
        break;
    
    case 4:
        opcio_4(mob);
        break;

    default:
        cerr << "Error en les opcions" << endl;
        break;
    }
}

int main(){
    Mobilitat mob;
    int opcio;
    cin >> opcio;
    while(opcio != 0){
        operacions_menu(opcio, mob);
        cin >> opcio;
    }
    return 0;
}