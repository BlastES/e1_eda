#include "material\classes\Mobilitat.h"
#include <iostream>
using namespace std;

void titol_opcions(int i){
    switch (i)
    {
    case 1:
        cerr << string('*', 20) << endl;
        cerr << "* 01: Llegir dades *" << endl;
        cerr << string('*', 20) << endl;
        break;
    
    case 2:
        cerr << string('*', 25) << endl;
        cerr << "* 02: Nombre transports *" << endl;
        cerr << string('*', 25) << endl;
        break;
    
    case 3:
        cerr << string('*', 37) << endl;
        cerr << "* 03: Nombre persones per transport *" << endl;
        cerr << string('*', 37) << endl;
        break;
    
    case 4:
        cerr << string('*', 19) << endl;
        cerr << "* 04: Més ràpid *" << endl;
        cerr << string('*', 19) << endl;   
        break;     

    default:
        break;
    }
}

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

void opcio_1(Mobilitat& mob){
    string file_name;
    cin >> file_name;
    int linies_llegides = mob.llegirDades(file_name);
    cout << "Numero de linies: " << linies_llegides << endl;
}

void opcio_2(Mobilitat& mob){
    int codi_distancia;
    cin >> codi_distancia;
    int n_transports = mob.nombreTransports(codi_distancia);
    cout << "Distància ";
    codis_distancia(codi_distancia);
    cout << " ==> " <<n_transports << endl;    
}

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

void opcio_4(Mobilitat& mob){
    vector<pair<string, double>> vec = mob.mesRapid();
    string transport;
    double temps_mig;
    for(int i = 1; i <= 7; i++){
        codis_distancia(i);
        cout << " : " << vec.at(i-1).first << " => " << vec.at(i-1).second << endl;
    }
}

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