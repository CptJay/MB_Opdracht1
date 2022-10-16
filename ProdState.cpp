#include "ProdState.h"

ProdState::ProdState(const string &voor, vector<string> naa) : voor(voor), naa(naa) {
    this->voor = voor;
    this->naa = naa;
}

string ProdState::giveProduction() const{
    string naaa = "";


    for (auto el : this->naa){
        naaa += el + " ";
    }
    naaa.pop_back();
    return  "    " + this->voor + " -> `" + naaa + "`";
}

const string &ProdState::getVoor() const {
    return voor;
}

const vector <string> &ProdState::getNaa() const {
    return naa;
}
