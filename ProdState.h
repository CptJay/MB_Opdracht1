#ifndef OPDRACHT_1_PRODSTATE_H
#define OPDRACHT_1_PRODSTATE_H

using namespace std;

#include <vector>
#include "iostream"
#include "string"

class ProdState {
private:
    string voor;
    string na;
    vector<string> naa;
public:
    ProdState(const string &voor, vector<string> naa);
    string giveProduction() const;

    const string &getVoor() const;

    const vector<string> &getNaa() const;
};


#endif //OPDRACHT_1_PRODSTATE_H
