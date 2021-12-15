//
// Created by Stephan on 14.12.2021.
//
#include <stdio.h>
#include "Trs.h"
#include <iostream>
#include <fstream>


vector<string> split(const char *str, char c = ' ')
{
    vector<string> result;
    do
    {
        const char *begin = str;
        while(*str != c && *str)
            str++;
        result.push_back(string(begin, str));
    } while (0 != *str++);

    return result;
}

#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)


bool isValidSymbol(char ch){
    return isdigit(ch) || isalpha(ch);
}

bool isParen(char ch){
    return ch == '(' || ch == ')';
}

bool isComma(char ch){
    return ch == ',';
}

bool isValidForRule(char ch){
    return (isValidSymbol(ch) || isParen(ch) || isComma(ch));
}



using namespace std;
Trs::Trs(string filepath) {
    std::ifstream fin(filepath);
    std::string res = "";

    if (fin.fail()){
        printf("Open file failed\n");
    }

    string inputLine;
    string line;
    while (std::getline(fin, inputLine)) {
        line = "";
        for(auto ch : inputLine){
            if (!isspace(ch)){
                line += ch;
            }
        }

        if (line.empty())
            continue;

        res += line;
        inputLines.push_back(line);
    }

    trsstr = res;
    fin.close();
    parseInput();
}


void Trs::parseInput() {
    string line = this->inputLines[0];
    Trs::parseVars(line);
    for(int i = 1; i < inputLines.size(); i ++){
        Trs::parseRule(inputLines[i]);
    }
}

void Trs::parseVars(const string& str) {
    char delim = ',';
    if(str[0] != '[' || str[str.length() - 1] != ']'){
        printf("PANIC\n");
    }

    for (int i = 1; i < str.length() - 1; i++){
        string ident;
        for(; i < str.length()  - 1 && str[i] != delim; i++){
            ///проверка на мусор
            if (!isValidSymbol(str[i])){
                printf("PANIC\n");
            }
            ident += str[i];
        }
        variableNames.push_back(ident);
    }
}

void Trs::parseRule(const string &str) {
    string delim = "->";
    string left;
    string right;
    int i = 0;
    for(; i < str.length(); i++){
        if (str[i] == delim[0])
            break;
        if (!isValidForRule(str[i]))
            printf("PANIC\n");
        left += str[i];
    }
    i++;
    if (i == str.length() || str[i] != delim[1])
        printf("PANIC\n");
    i++;
    for(; i < str.length(); i++){
        if (!isValidForRule(str[i]))
            printf("PANIC\n");
        right += str[i];
    }

    rules.emplace_back(make_pair(Term(left), Term(right)));
}
