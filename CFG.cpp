#include "CFG.h"
#include "ProdState.h"


CFG::CFG() {
    this->variabels = {"BINDIGIT", "S"};
    this->terminals = {"0", "1", "a", "b"};
    this->startState = {"S"};

    /* Creating a new production state, which is a pointer to a production state. */
    auto *p1 = new ProdState("BINDIGIT", {"0"});
    auto *p2 = new ProdState("BINDIGIT", {"1"});
    auto *p3 = new ProdState("S", {""});
    auto *p4 = new ProdState("S", {"a","S", "b", "BINDIGIT"});
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
    for (const auto &T: this->terminals) {
        result += T + ", ";
        loop = true;
    }
    if (!this->terminals.empty()) { // remove last ", " from the for-loop
        result.pop_back();
        result.pop_back();
    }
    result += "}";
    return result; // ex: "T = {0, 1, a, b}
}

string CFG::allVariables() const {
    string result = "V = {";
    bool loop = false;
    for (const auto &V: this->variabels) {
        result += V + ", ";
        loop = true;
    }
    if (!this->variabels.empty()) { // remove last ", " from the for-loop
        result.pop_back();
        result.pop_back();
    }
    result += "}";
    return result; // ex: "V = {V, A, S}
}

string CFG::allProductions() const {
    string result = "P = {\n";
    for (const auto &P: this->productions) {
        result += P->giveProduction() + "\n";
    }
    if (!this->productions.empty()) {
        result.pop_back();
    }
    result += "\n}";
    return result;
}

string CFG::allStartState() const {
    return "S = " + this->startState;
}

CFG::CFG(const string &fname) {
    /**
     * JSON
     */
    ifstream input(fname);
    json j;
    input >> j;

    /**
     * Variables
     */

    vector<string> vbs = j["Variables"];
    vector<string> vb_unsorted;
    for (const auto &vb : vbs){
        vb_unsorted.push_back(vb);
    }
    sort(vb_unsorted.begin(), vb_unsorted.end());
    this->variabels = vb_unsorted;

    /**
     * Terminals
     */
    vector<string> ts_unsorted;
    vector<string> ts = j["Terminals"];
    for (const auto &el: ts) {
        ts_unsorted.push_back(el);
    }
    sort(ts_unsorted.begin(), ts_unsorted.end());
    this->terminals = ts_unsorted;

    /**
     * Productions
     */
//    vector<tuple<map<string, string>, map<string, vector<string>>>> ps = j["Productions"];
//    for (auto el: ps) {
//        string head = get<0>(el)["head"];
//        string fullb = "";
//        vector<string> bdy = get<1>(el)["body"];
//        for (const auto& b : bdy){
//            fullb += b + " ";
//        }
////        for (auto &i : body){
////            fullb += i + " ";
////        }
//        fullb.pop_back();
//        auto *p1 = new ProdState(head, fullb);
//        fullb.clear();
//    }
    vector<ProdState*> pd_unsorted;
    for (auto el : j["Productions"]){
        vector<string> temp;
        for (const auto& el2 : el["body"]){
            temp.push_back(el2);
        }
        if (temp.empty()){
            auto *p1 = new ProdState(el["head"], {""});
            pd_unsorted.push_back(p1);
        } else{
            auto *p1 = new ProdState(el["head"], temp);
            pd_unsorted.push_back(p1);
        }
        temp.clear();
    }
    sort(pd_unsorted.begin(), pd_unsorted.end(), [](ProdState* const & a, ProdState* const & b) -> bool
    {
        return a->getNaa() < b->getNaa();
    }); //define new sort for object.naa
    sort(pd_unsorted.begin(), pd_unsorted.end(), [](ProdState* const & a, ProdState* const & b) -> bool
    {
        return a->getVoor() < b->getVoor();
    }); //define new sort for object.voor

    this->productions = pd_unsorted;
    /**
     * Start symbol
     */
    startState = j["Start"];

}

CFG::~CFG() {
    for (auto &el: productions) {
        delete el;
    }
}
