// Alvin Teng
// Assignment 6.cpp

#include <iostream>
using namespace std;
int userInput();
int gcdRecursion(int input1, int input2);

int main() {
    int fNum, sNum, gcd = 0;
    int smallNum, bigNum = 0;
    char quit = 'y';
    
    do {
        fNum = userInput();
        sNum = userInput();
        smallNum = min(fNum, sNum);
        bigNum = max(fNum, sNum);
        
        unsigned long int sTime = clock();
        gcd = gcdRecursion(smallNum, bigNum);
        unsigned long int eTime = clock();
        
        cout << "The greatest common divisor is " << gcd << "." << endl;
        cout << "It took " << (eTime - sTime)/double(CLOCKS_PER_SEC)*1000 << " seconds to complete the recursion." << endl;
        
        cout << "Would you like to run the program again? (y = yes)" << endl;
        cin >> quit;
    } while (quit == 'y');
    
    return 0;
}

int userInput() {
    int num;
    
    cout << "Enter only positive values." << endl;
    do {
    cout << "Enter a number: ";
    cin >> num;
    } while (num < 0);
    
    return num;
}

int gcdRecursion(int input1, int input2) {
    if (input2 == 0)
        return input1;
    return gcdRecursion(input2, input1 % input2);
}
