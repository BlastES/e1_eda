#include "material\classes\Distancia.h"

Distancia::Distancia(int codi){
    this->codi = codi;
}

void Distancia::afegir(int id, int ordre, string tipusTrajecte, int horaIn, int durada, string comarcaIn, string comarcaFi, string mitjaPrincipal, int edat, string estudis){
    bool trobat = false;
    list<Transport>::iterator it = transports.begin();
    if(!transports.empty()){
        while(!trobat && it != transports.end()){
            if(Transport(mitjaPrincipal) == *it)
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
    transports.sort(criteri_ordenacio);
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

bool Distancia::criteri_ordenacio(const Transport &a, const Transport &b) const{
    if(a.obtenirNombrePersones() > b.obtenirNombrePersones()) return true;
    else if(a.obtenirNombrePersones() < b.obtenirNombrePersones()) return false;
    else return a.obtenirNom() > b.obtenirNom();
}