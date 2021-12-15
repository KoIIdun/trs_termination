//
// Created by Stephan on 15.12.2021.
//

#ifndef TRS_COMPLETION_TERM_H
#define TRS_COMPLETION_TERM_H
#include <string>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

class Term {
private:
    static map<string, int> constructorsMap;
    static bool correct;
public:
    static bool isCorrect();
private:
    string_view term;
    vector<Term> arguments;
    string constructor;
    bool isVariable;
public:
    Term();

public:
    Term(string_view strterm);

};



#endif //TRS_COMPLETION_TERM_H
