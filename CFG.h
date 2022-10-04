#ifndef OPDRACHT_1_CFG_H
#define OPDRACHT_1_CFG_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ProdState;
class CFG {
private:
    vector<string > terminals;
    vector<string > variabels;
    vector<ProdState* > productions;
    string startState;

    string allTerminals() const;
    string allVariables() const;
    string allProductions() const;
    string allStartState() const;

public:
    CFG();

    void print();
};


#endif //OPDRACHT_1_CFG_H
