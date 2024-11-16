#include "dom_creater.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>

extern DOMNode* root;  ///< External pointer to the root DOM node after parsing
using namespace std;

extern int yyparse();  ///< Function to initiate the parsing process
extern void yy_scan_string(const char* str);  ///< Function to scan a string input for parsing
extern void yy_delete_buffer(void* buffer);  ///< Function to delete the buffer after scanning
extern FILE *yyin;  ///< File pointer for the input stream for parsing
using namespace std;

/**
 * @file dom_creater.cpp
 * @brief This file defines the DOM creation process by parsing an input string into a DOM tree.
 */

/**
 * @brief Mutex to ensure thread safety during DOM creation and parsing.
 */
std::mutex dom_mutex;

/**
 * @brief Parses an input string to create a DOM tree.
 *
 * This function uses the `yy_scan_string` to scan the input string, and `yyparse` to parse it into a DOM tree.
 * Parsing is done in a separate thread to allow asynchronous processing. A lock is applied to ensure thread safety during the DOM creation process.
 *
 * @param input The string to be parsed into a DOM tree.
 * @return A pointer to the root node of the parsed DOM tree, or nullptr if parsing fails.
 */
DOMNode* dom_creater_string(const std::string& input) {
    std::lock_guard<std::mutex> guard(dom_mutex);  ///< Lock to ensure thread safety

    yy_scan_string(input.c_str());  ///< Scan the input string for parsing

    DOMNode* parsed_root = nullptr;  ///< Initialize the root of the DOM

    // Start a new thread to handle parsing
    std::thread parsing_thread([&]() {
        yyparse();  ///< Initiates the parsing process
        parsed_root = root;  ///< Set the parsed root to the external root
    });

    parsing_thread.join();  ///< Wait for the parsing thread to complete

    // Check if parsing was successful
    if (parsed_root) {
        std::cout << "Parsed DOM Structure:" << std::endl;
        return parsed_root;
    } else {
        std::cerr << "Error: Root DOM is null!" << std::endl;
        return nullptr;
    }
}
