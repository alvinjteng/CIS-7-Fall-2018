//  Alvin Teng
//  Assignment 3

#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    string connectors = "!V^v->()"; // Includes all Connectors
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUWXYZabcdefghijklmnopqrstuwxyz"; // Includes the alphabet except 'v' and 'V'
    
    cout << "Enter a WFF: "; // Asks user to enter WFF
    getline(cin, input);
    
    bool lastAlphabet = false;
    bool lastNot = false;
    bool lastConnector = false;
    bool lastDash = false;
    bool lastLeftP = false;
    bool lastRightP= false;
    bool isValid = true;
    
    for (auto c: input){
        
        if (c == ' '){
            continue;
        }
        
        if (connectors.find(c) != string::npos) {
            if (c != '!'){
                if (!lastAlphabet && !lastDash && c != '('){
                    isValid = false;
               }
                if (c == '-' && lastAlphabet) { // Checks if c was dash and last was an alphabet character
                    lastDash = true;
                }
                else if (c == '>' && lastDash) { // Checks to make sure that is there is a dash that follows the greater than.
                    lastConnector = true;
                    lastDash = false;
                }
                else if (c == '(' && !lastDash && !lastConnector && !lastLeftP) { // Checks for left Parenthetical, and no consecutive left parenthesis
                    lastLeftP = true;
                }
                else if (c == ')' && !lastConnector && !lastDash && !lastRightP && lastLeftP){
                    lastRightP = true;
                    lastLeftP = false;
                }
                else if (connectors.find(c) != string::npos && !lastLeftP && !lastRightP) { // Checks c for a connector other than '-' or '>'.
                    lastConnector = true;
                }
                else {
                    isValid = false;
                }
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
        else if (alphabet.find(c) != string::npos) { // Checks if c is in the alphabet.
            if (lastAlphabet || lastDash){
                isValid = false;
        }
            lastAlphabet = true;
            lastConnector = false;
            continue;
        }
        else {
            isValid = false;
            break;
        }
    }
    if (!lastAlphabet && !lastRightP) {
        isValid = false;
    }
    cout << (isValid ? "Your WFF is valid." : "Your WFF is invalid.") << endl;
    
    return 0;
}
