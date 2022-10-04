#include "CFG.h"
#include "ProdState.h"


CFG::CFG() {
    this->variabels = {"BINDIGIT", "S"};
    this->terminals = {"0", "1", "a", "b"};
    this->startState = "S";

    /* Creating a new production state, which is a pointer to a production state. */
    auto* p1 = new ProdState("BINDIGIT", "0");
    auto* p2 = new ProdState("BINDIGIT", "1");
    auto* p3 = new ProdState("S", "");
    auto* p4 = new ProdState("S", "a S b BINDIGIT");
    this->productions.push_back(p1);
    this->productions.push_back(p2);
    this->productions.push_back(p3);
    this->productions.push_back(p4);

}

void CFG::print() {
    cout << allVariables() << endl << allTerminals() << endl << allProductions() << endl << allStartState();
}

string CFG::allTerminals() const {
    string result = "T = {";
    bool loop = false;
    for (const auto& T : this->terminals){
        result += T + ", ";
        loop = true;
    }
    if (!this->terminals.empty()){ // remove last ", " from the for-loop
        result.pop_back();
        result.pop_back();
    }
    result += "}";
    return result; // ex: "T = {0, 1, a, b}
}

string CFG::allVariables() const {
    string result = "V = {";
    bool loop = false;
    for (const auto &V : this->variabels){
        result += V + ", ";
        loop = true;
    }
    if (!this->variabels.empty()){ // remove last ", " from the for-loop
        result.pop_back();
        result.pop_back();
    }
    result += "}";
    return result; // ex: "V = {V, A, S}
}

string CFG::allProductions() const {
    string result = "P = {\n";
    for (const auto &P : this->productions){
        result += P->giveProduction() + "\n";
    }
    if (!this->productions.empty()){
        result.pop_back();
    }
    result += "\n}";
    return result;
}

string CFG::allStartState() const{
    return "S = " + this->startState;
}
