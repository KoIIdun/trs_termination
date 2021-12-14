//
// Created by Stephan on 14.12.2021.
//
#include <stdio.h>
#include "Trs.h"
#include <iostream>
#include <fstream>
#include <string.h>

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
using namespace std;
Trs::Trs(string filename) {
    ifstream fin("Dickson/" + filename);
    char str [80];
    FILE * pFile;
    string name = "../tests/Dickson/" + filename;
    pFile = fopen(name.c_str(), "r+");
    fscanf (pFile, "[%s]\n", str);
    variableNames = split(str, ',');
    //fscanf (pFile, "%s", str);
    cout << strlen(str);
    fclose (pFile);

}