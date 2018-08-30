//  Alvin Teng
//  Assignment 1

#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    string connectors = "!V^v";
    
    cout << "Enter a WFF: ";
    getline(cin, input);
    
    bool lastWasAlpha = false;
    bool lastWasNot = false;
    bool lastWasConnector = false;
    bool isValid = true;
    
    for (auto c: input){
        
        if (c == ' '){
            continue;
        }
        
        if (connectors.find(c) != string::npos) {
            if (c != '!'){
                if (!lastWasAlpha){
                    isValid = false;
                }
                lastWasConnector = true;
            }
            else {
                if (lastWasAlpha) {
                    isValid = false;
                    break;
                }
                lastWasNot = true;
            }
            lastWasAlpha = false;
        }
        else if (isalpha(c)) {
            if (lastWasAlpha){
                isValid = false;
        }
            lastWasAlpha = true;
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
