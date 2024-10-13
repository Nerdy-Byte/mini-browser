#include "dom_creater.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <fstream>

extern DOMNode* root;
using namespace std;

extern int yyparse();
extern FILE *yyin;

// size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
//     std::ofstream* outputFile = static_cast<std::ofstream*>(userp);
//     size_t totalSize = size * nmemb;
//     outputFile->write(static_cast<const char*>(contents), totalSize);
//     return totalSize;
// }

// void fetchHTML(const std::string& url, const std::string& filename) {
//     CURL* curl;
//     CURLcode res;
//     std::ofstream outputFile(filename);

//     if (!outputFile) {
//         cerr << "Could not open file: " << filename << endl;
//         return;
//     }

//     curl = curl_easy_init();
//     if (curl) {
//         curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
//         curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
//         curl_easy_setopt(curl, CURLOPT_WRITEDATA, &outputFile);
//         curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
//         res = curl_easy_perform(curl);
//         if (res != CURLE_OK) {
//             cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
//         }
//         curl_easy_cleanup(curl);
//     }

//     outputFile.close();
// }

DOMNode* dom_creater_main(char* filename) {
    // const char* filename = "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/input.html";
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

// DOMNode* fetched_pages() {
//     const std::string url = "http://localhost:8000/sample.html";
//     const std::string filename = "cached_sample.html";

//     fetchHTML(url, filename);
//     cout << "Fetched HTML page and cached as " << filename << endl;

//     yyin = fopen(filename.c_str(), "r");

//     if (!yyin) {
//         cerr << "Error: Could not open file " << filename << endl;
//         return nullptr;
//     }

//     yyparse();

//     if (root) {
//         cout << "Parsed DOM Structure:" << endl;
//         fclose(yyin);
//         return root;
//     } else {
//         cerr << "Error: Root DOM is null!" << endl;
//         fclose(yyin);
//         return nullptr;
//     }
// }
