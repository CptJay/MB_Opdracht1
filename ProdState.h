#ifndef OPDRACHT_1_PRODSTATE_H
#define OPDRACHT_1_PRODSTATE_H

using namespace std;

#include "iostream"
#include "string"

class ProdState {
private:
    string voor;
    string na;

public:
    ProdState(const string &voor, const string &na);
    string giveProduction() const;
};


#endif //OPDRACHT_1_PRODSTATE_H
