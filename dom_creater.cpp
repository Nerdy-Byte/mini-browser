#include "dom_creater.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>


extern DOMNode* root;
using namespace std;

extern int yyparse();
extern void yy_scan_string(const char* str);
extern void yy_delete_buffer(void* buffer);
extern FILE *yyin;
using namespace std;

//function to parse files
DOMNode* dom_creater_main(char* filename) {
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

//function to parse input string
DOMNode* dom_creater_string(const string& input) {
    yy_scan_string(input.c_str());
    yyparse();
    if (root) {
        cout << "Parsed DOM Structure:" << endl;
        return root;
    } else {
        cerr << "Error: Root DOM is null!" << endl;
        return nullptr;
    }
}


