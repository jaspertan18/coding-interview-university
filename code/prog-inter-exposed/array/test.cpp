#include <iostream>

using namespace std;

void print(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int *arr1 = new int[5];
    int *arr2 = new int[10];

    for (int i = 0; i < 5; i++)
        arr1[i] = i + 1;

    for (int i = 0; i < 10; i++)
        arr2[i] = i + 1;

    print(arr1, 5);

    delete [] arr1;

    return 0;
}