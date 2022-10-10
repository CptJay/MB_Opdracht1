#ifndef OPDRACHT_1_CFG_H
#define OPDRACHT_1_CFG_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

#include "json.hpp"

using namespace std;
using json = nlohmann::json;

class ProdState;
class CFG {
private:
    vector<string > terminals;
    vector<string > variabels;
    vector<ProdState* > productions;
    string startState;
    vector<string> body;

    string allTerminals() const;
    string allVariables() const;
    string allProductions() const;
    string allStartState() const;

public:
    CFG();
    explicit CFG(const string& fname);
    void print();
    virtual ~CFG();
};


#endif //OPDRACHT_1_CFG_H
