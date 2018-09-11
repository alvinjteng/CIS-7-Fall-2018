//  Alvin Teng
//  Assignment 3

#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    string connectors = "!V^v->()"; // Includes all Connectors
    string sConnectors = "!V^v"; // Excludes -> and ()
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUWXYZabcdefghijklmnopqrstuwxyz"; // Includes the alphabet except 'v' and 'V'
    
    cout << "Enter a WFF: "; // Asks user to enter WFF
    getline(cin, input);
    
    bool lastAlphabet = false;
    bool lastNot = false;
    bool lastConnector = false;
    bool lastDash = false;
    bool eLeftP = false;
    bool lastRightP = false;
    bool isValid = true;
    
    for (auto c: input){
        
        if (c == ' '){
            continue;
        }
        
        if (connectors.find(c) != string::npos) {
            if (c != '!'){
                if (!lastAlphabet && !lastDash && c != '(' && !lastRightP) {
                    isValid = false;
                }
                if (c == '-' && lastAlphabet) { // Checks if c was dash and last was an alphabet character
                    lastDash = true;
                }
                else if (c == '>' && lastDash) { // Checks to make sure that is there is a dash that follows the greater than.
                    lastConnector = true;
                    lastDash = false;
                }
                else if (c == '(' && !lastDash) { // Checks for left Parenthetical.
                    eLeftP = true;
                    lastConnector = true;
                }
                else if (c == ')' && !lastDash && eLeftP){ // Checks for an existing left parenthetical.
                    lastRightP = true;
                    eLeftP = false;
                }
                else if (sConnectors.find(c) != string::npos && lastRightP) {
                    lastRightP = false;
                    lastConnector = true;
                }
                else if (sConnectors.find(c) != string::npos) { // Checks c for a connector other than '-' or '>'.
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
