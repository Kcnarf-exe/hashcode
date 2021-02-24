#include "StringHandler.h"

vector<string> StringHandler::split(string str, char delimiter) {
    vector<string> internal; 
    stringstream ss(str); // Turn the string into a stream. 
    string tok; 
 
    while(getline(ss, tok, delimiter)) { 
        internal.push_back(tok); 
    } 
 
    return internal; 
}