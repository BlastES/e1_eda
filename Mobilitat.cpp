#include "Mobilitat.h"
#include <iostream>

Mobilitat::Mobilitat(){
    for(int i = 1; i <= 7; i++){
        this->dist.push_back(Distancia(i));
    }
}

int Mobilitat::llegirDades(const string& path){    
    dist.clear();
    for(int i = 1; i <= 7; i++){
        this->dist.push_back(Distancia(i));
    }
    persones.clear();
    ifstream f;
    string linia;
    vector<string> items;
    int n_linies = 0;
    f.open(path);
    if(!f.fail()){
        f.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(f, linia);
        while(!f.eof()){
            items = tokens(linia, ',', true);
            dist.at(stoi(items.at(7))-1).afegir(stoi(items.at(0)), stoi(items.at(2)), items.at(3), stoi(items.at(4))%24, stoi(items.at(6)), items.at(8), items.at(9), items.at(14), stoi(items.at(20)), items.at(22));
            if(stoi(items.at(2)) == 1) persones.push_back(Persona(stoi(items.at(0)), stoi(items.at(20)), items.at(22)));
            n_linies++;
            getline(f, linia);
        }
        for(auto it : dist){
            it.ordenar_list();
        }
    } 
    return n_linies;
}

int Mobilitat::nombreTransports(int distancia) const{
    return dist.at(distancia-1).nombreTransports();
}

vector<pair<string, int>> Mobilitat::nombrePersonesPerTransport(int distancia) const{
    return dist.at(distancia-1).nombrePersonesPerTransport();
}

vector<pair<string, double>> Mobilitat::mesRapid() const{
    vector<pair<string, double>> vec;
    for(auto i : dist){
        vec.push_back(i.mesRapid());
    }
    return vec;
}