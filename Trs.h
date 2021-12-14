#ifndef TRS_COMPLETION_TRS_H
#define TRS_COMPLETION_TRS_H
#include <stdio.h>
#include <conio.h>
#include<string>
#include <vector>
#include "Term.h"


using namespace std;
class Trs {
    private:
        string trsstr;
        vector<string> variableNames;
        vector<pair<Term, Term>> rules;
public:
    Trs(string filename);
};


#endif //TRS_COMPLETION_TRS_H
