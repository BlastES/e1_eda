#include "Distancia.h"

Distancia::Distancia(int codi){
    this->codi = codi;
}

Distancia::Distancia(const Distancia& d){
    copia(d);
}

void Distancia::afegir(int id, int ordre, string tipusTrajecte, int horaIn, int durada, string comarcaIn, string comarcaFi, string mitjaPrincipal, int edat, string estudis){
    bool trobat = false;
    list<Transport>::iterator it = transports.begin();
    if(!transports.empty()){
        while(!trobat && it != transports.end()){
            if(it->obtenirNom() == mitjaPrincipal)
                trobat = true;
            else
                it++;
        }
    }
    if(trobat){
        it->afegir(id, ordre, tipusTrajecte, horaIn, durada, comarcaIn, comarcaFi, edat, estudis);
        transports.sort();
    }else{
        transports.push_back(Transport(mitjaPrincipal));
        transports.back().afegir(id, ordre, tipusTrajecte, horaIn, durada, comarcaIn, comarcaFi, edat, estudis);
    }
    pair<map<string, int>::iterator, bool> comprov = trajectes.insert(pair<string, int>(comarcaIn + " - " + comarcaFi, durada));
    // guardem la durada mes llagra de un trajecte determinat si aquest ja exsisteix
    if(!comprov.second && durada > comprov.first->second) comprov.first->second = durada;
    if(durada > trajMesLlarg.second){
        trajMesLlarg = *comprov.first;
    }
}

void Distancia::ordenarLlista(){
    transports.sort();
}

int Distancia::nombreTransports() const{
    return transports.size();
}

vector<pair<string, int>> Distancia::nombrePersonesPerTransport() const{
    vector<pair<string, int>> vec;
    pair<string, int> elem;
    for(Transport it : transports){
        elem.first = it.obtenirNom();
        elem.second = it.obtenirNombrePersones();
        vec.push_back(elem);
    }
    return vec;
}

pair<string, double> Distancia::mesRapid() const{
    pair<string,double> mes_rapid;
    if(!transports.empty()){
        mes_rapid.first = transports.front().obtenirNom();
        mes_rapid.second = transports.front().obtenirTempsPromig();
        for(Transport it : transports){
            if(mes_rapid.second > it.obtenirTempsPromig()){
                mes_rapid.first = it.obtenirNom();
                mes_rapid.second = it.obtenirTempsPromig();
            }
        }
    }else{
        mes_rapid.first = "--";
        mes_rapid.second = 0;
    }
    return mes_rapid;
}

pair<string, double> Distancia::trajecteMesLlarg() const{
    return pair<string, double>(trajMesLlarg.first, double(trajMesLlarg.second));
}

map<string, int> Distancia::llistaTrajectes() const{
    return trajectes;
}

Distancia& Distancia::operator=(const Distancia& d){
    copia(d);
    return *this;
}

void Distancia::copia(const Distancia& d){
    this->codi = d.codi;
    this->transports = d.transports;
    this->trajectes = d.trajectes;
    this->trajMesLlarg = d.trajMesLlarg;
}
