#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "register.hpp"

using namespace std;
const string prec_defn = "PRECONDITIONS";
const string postc_defn = "POSTCONDITIONS";

/*
    Parses a string-represented definition to a regsiter
    @param defn takes in a string containing a variable mapped to a value
    @returns a register containing the value matched to the variable specified
*/
Register parseDefn(string defn) {
    return Register{value: 0};
}

/*
    Determines the set of preconditions defined in the specified file
    @param filename is the string containing the name of the file to be opened
    @param returns a register file representation with the specified definitions prior to program execution
*/
vector<Register> preconditions(string filename) {
    vector<Register> conds;
    ifstream file(filename);
    string line;

    //Ignore lines prior to declaration
    while (getline (file, line) && line != prec_defn) continue;

    //Parse all lines following declaration
    while (getline (file, line) && line != postc_defn) {
        conds.push_back(parseDefn(line));
    }

    return conds;
}

void postconditions(string filename) {
    ifstream file(filename);
    return;
}

int main() {
    vector<Register> results = preconditions("conditions.txt");
    return 0;
}