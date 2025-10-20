#include "Mobilitat.h"

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
            getline(f, linia);
            n_linies++;
        }
        for(int i = 0; i < 7; i++){
            dist.at(i).ordenar_vec();
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

pair<string, double> Mobilitat::trajecteMesLlarg() const{
    pair<string, double> mesLlarg("", 0);
    for(auto i : dist){
        if(i.trajecteMesLlarg().second > mesLlarg.second) mesLlarg = i.trajecteMesLlarg();
    }
    return mesLlarg;
}

vector<list<string>> Mobilitat::trajectesNous() const{
    vector<list<string>> resultat;
    map<string, int> nous;
    pair<map<string, int>::iterator, bool> act;
    for(int i = 0; i < 7; i++){
        for(auto j : dist.at(i).llistaTrajectes()){
            act = nous.insert(pair<string, int>(j.first, j.second));
            if(act.second) resultat.at(i).push_back(act.first->first);
        }
    }
    return resultat;
}