#include "ProdState.h"

ProdState::ProdState(const string &voor, const string &na) : voor(voor), na(na) {
    this->voor = voor;
    this->na = na;
}

string ProdState::giveProduction() const{
    return  this->voor + " -> `" + this->na + "`";
}
