#include <iostream>

using namespace std;

int increase(int x) {
    x++;
    return x;
}

int main() {
    const int x = 8;
    cout << increase(x) << endl;


    
    return 0;
}