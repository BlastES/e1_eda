#include "Distancia.h"
#include <iostream>

Distancia::Distancia(int codi){
    this->codi = codi;
}

Distancia::Distancia(const Distancia& d){
    this->codi = d.codi;
    this->transports = d.transports;
}

void Distancia::afegir(int id, int ordre, string tipusTrajecte, int horaIn, int durada, string comarcaIn, string comarcaFi, string mitjaPrincipal, int edat, string estudis){
    bool trobat = false;
    vector<Transport>::iterator it = transports.begin();
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
    }else{
        transports.push_back(Transport(mitjaPrincipal));
        transports.back().afegir(id, ordre, tipusTrajecte, horaIn, durada, comarcaIn, comarcaFi, edat, estudis);
    }
}

void Distancia::ordenar_list(){
    int n = transports.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (transports[j] > transports[j + 1])
                swap(transports[j], transports[j + 1]);
        }
    }
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

Distancia& Distancia::operator=(const Distancia& d){
    this->codi = d.codi;
    this->transports = d.transports;
    return *this;
}

