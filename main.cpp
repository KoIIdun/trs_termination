#include <iostream>
#include "Term.h"
#include "Trs.h"

using namespace std;
int main() {
    string data;
    Trs trs("test_dickson1.trs");
    Term term("adas(f(x),f(z(x),y))");
    cout << term.isCorrect();
    return 0;
}
