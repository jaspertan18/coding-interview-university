/**
 * Problem Statement
 * Write an efficient function that deletes characters from a mutable ASCII string. Your function should take two arguments, str and remove. 
 * Any character existing in remove must be deleted from str. 
 * For example, given a str of "Battle of the Vowels: Hawaii vs. Grozny" and a remove of "aeiou", 
 * the function should transform str to "Bttl f th Vwls: Hw vs. Grzny". 
 * Justify any design decisions you make, and discuss the efficiency of your solution.
 * 
 * Implementation
 * 1. Maintain an array of boolean and for each char in "remove" set flag to true
 * 2. Maintain a new array "ans" with size = "str".length - "remove".length
 * 3. Go through the "str" array and append to "ans" if flag is false
*/

#include <iostream>

using namespace std;

string removeChar(string str, string remove) {
    int allFlag[128]; // ASCII has 128 characters
    string ans;

    for (int i = 0; i < remove.length(); i++)
        allFlag[remove[i]] = 1;

    for (int i = 0; i < str.length(); i++) {
        char currentChar = str[i];

        if (!allFlag[currentChar])
            ans += currentChar;
    }

    return ans;
}

int main() {
    string str = "Battle of the Vowels: Hawaii vs. Grozny";
    string remove = "aeiou";

    cout << removeChar(str, remove) << endl;

    return 0;
}

