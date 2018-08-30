//  Alvin Teng
//  Assignment 1

#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    string connectors = "!V^v->";
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUWXYZ";
    
    cout << "Enter a WFF: ";
    getline(cin, input);
    
    bool lastAlphabet = false;
    bool lastNot = false;
    bool lastConnector = false;
    bool lastDash = false;
    bool isValid = true;
    
    for (auto c: input){
        
        if (c == ' '){
            continue;
        }
        
        if (connectors.find(c) != string::npos) {
            if (c != '!'){
                if (!lastAlphabet && lastDash == false){
                    isValid = false;
                }
                if (c == '-' && lastAlphabet == true) {
                    lastDash = true;
                }
                else if (c == '>' && lastDash == true) {
                    lastConnector = true;
                }
                else if (connectors.find(c) != string::npos) {
                    lastConnector = true;
                }
                else {
                    isValid = false;
                }
                lastConnector = true;
            }
            else {
                if (lastAlphabet) {
                    isValid = false;
                    break;
                }
                lastNot = true;
            }
            lastAlphabet = false;
        }
        else if (alphabet.find(c) != string::npos) {
            if (lastAlphabet){
                isValid = false;
        }
            lastAlphabet = true;
            continue;
        }
        else {
            isValid = false;
            break;
        }
    }
    cout << (isValid ? "Your WFF is valid." : "Your WFF is invalid.") << endl;
    
    return 0;
}
