#include "Distancia.h"

Distancia::Distancia(int codi){
    this->codi = codi;
    trajMesLlarg = trajectes.begin();
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
    pair<map<string, int>::iterator, bool> comprov = trajectes.insert(pair<string, int>(comarcaIn + " - " + comarcaFi, durada));
    // guardem la durada mes llagra de un trajecte determinat si aquest ja exsisteix
    if(!comprov.second && durada > comprov.first->second) comprov.first->second = durada;
    if(durada > trajMesLlarg->second) trajMesLlarg = comprov.first;
}

void Distancia::ordenar_vec(){
    quick_sort(0, transports.size()-1);
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
    return pair<string, double>(trajMesLlarg->first, double(trajMesLlarg->second));
}

map<string, int> Distancia::llistaTrajectes() const{
    return trajectes;
}

Distancia& Distancia::operator=(const Distancia& d){
    this->codi = d.codi;
    this->transports = d.transports;
    return *this;
}

void Distancia::quick_sort(int esq, int dre){
    int k;
    if(esq<dre){
        particio(esq, dre, k);
        quick_sort(esq, k-1);
        quick_sort(k+1, dre);
    }
}

void Distancia::particio(int esq, int dre, int& pos_pivot){
    int pivot = transports.at(dre).obtenirNombrePersones();
    pos_pivot = esq;
    for(int i = esq; i <= dre-1; i++){
        if(transports.at(i).obtenirNombrePersones() > pivot){
            intercanvi(transports.at(i), transports.at(pos_pivot));
            pos_pivot++;
        }
    }
    intercanvi(transports.at(dre), transports.at(pos_pivot));
}

void Distancia::intercanvi(Transport& x, Transport& y){
    Transport aux = x;
    x = y;
    y = aux;
}
