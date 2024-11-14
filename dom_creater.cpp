#include "dom_creater.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>

extern DOMNode* root;
using namespace std;

extern int yyparse();
extern void yy_scan_string(const char* str);
extern void yy_delete_buffer(void* buffer);
extern FILE *yyin;
using namespace std;


//function to parse input string
std::mutex dom_mutex;

DOMNode* dom_creater_string(const std::string& input) {
    std::lock_guard<std::mutex> guard(dom_mutex);  // Lock to ensure thread safety
    yy_scan_string(input.c_str());

    DOMNode* parsed_root = nullptr;


    std::thread parsing_thread([&]() {
        yyparse();
        parsed_root = root;
    });


    parsing_thread.join();

    if (parsed_root) {
        std::cout << "Parsed DOM Structure:" << std::endl;
        return parsed_root;
    } else {
        std::cerr << "Error: Root DOM is null!" << std::endl;
        return nullptr;
    }
}

