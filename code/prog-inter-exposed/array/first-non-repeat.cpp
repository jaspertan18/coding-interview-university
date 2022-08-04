/**
 * Problem Statement
 * Write an efficient function to find the first nonrepeated character in a string. 
 * For instance, the first nonrepeated character in “total” is ‘o’ and the first nonrepeated character in “teeter” is ‘r’. 
 * Discuss the efficiency of your algorithm.
 * 
 * Implementation
 * Use a HashMap
*/

#include <iostream>
#include <map>

using namespace std;

char firstNonRepeat(string param) {
    char ans = '\0';
    map<char, int> database;

    for (int i = 0; i < param.length(); i++) {
        char currentChar = param[i];

        if (database.find(currentChar) != database.end())
            database[currentChar] += 1;
        else
            database[currentChar] = 1;
    }

    for (map<char, int>::iterator itr = database.begin(); itr != database.end(); itr++) {
        if (itr->second == 1)
            ans = itr->first;
    }
    return ans;
}

int main() {
    string param = "total";
    cout << firstNonRepeat(param) << endl;
    return 0;
}