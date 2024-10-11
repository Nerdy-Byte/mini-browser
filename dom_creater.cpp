#include "dom_creater.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>

extern DOMNode* root;
using namespace std;

extern int yyparse();
extern FILE *yyin;

DOMNode* dom_creater_main() {

    const char* filename = "../input.html";
    yyin = fopen(filename, "r");

    if (!yyin) {
        cerr << "Error: Could not open file " << filename << endl;
        exit(-1);
    }

    yyparse();

    if (root) {
        cout << "Parsed DOM Structure:" << endl;
        fclose(yyin);
        return root;
    } else {
        cerr << "Error: Root DOM is null!" << endl;
        fclose(yyin);
        return nullptr;
    }
}
