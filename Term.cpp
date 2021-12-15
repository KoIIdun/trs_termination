//
// Created by Stephan on 15.12.2021.
//

#include "Term.h"
#include <iostream>

bool Term::correct = true;

map<string, int> Term::constructorsMap = map<string, int>({});

Term::Term(string_view strterm){
    term = strterm;
    int constructorIndex = term.find_first_of('(');
    vector<Term> arguments(0);
    if (constructorIndex != -1) {
        constructor = term.substr(0, term.find_first_of('('));

        int bracketcounter = 0;
        int lastvirg = constructorIndex;
        for (int i = constructorIndex + 1; i < term.length(); i++) {
            if (term[i] == '(') {
                bracketcounter++;
            } else if (term[i] == ')') {
                bracketcounter--;
            }
            if ((term[i] == ',' && bracketcounter == 0) || (i == term.length() - 1 && bracketcounter == -1)){
                arguments.push_back(Term(term.substr(lastvirg + 1, i - lastvirg - 1)));
                lastvirg = i;
            }
        }
    } else {
        constructor = strterm;
        isVariable = true;
    }
    if (constructorsMap.count(constructor) != 0) {
        if (constructorsMap[constructor] != arguments.size()) {
            correct = false;
        }
    } else {
        constructorsMap[constructor] = arguments.size();
    }
    //cout << constructor << " " << term << endl;
}

Term::Term() {}

bool Term::isCorrect() {
    return correct;
}