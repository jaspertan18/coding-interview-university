#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

void push_back(Node* &head, int value) {
    Node *p = new Node;
    p->data = value;
    p->next = head;

    head = p;

    delete p;
}

void plusOne(int *num) {
    (*num)++;
}

int main() {
    // Node *head = nullptr;

    // push_back(head, 10);

    // Node *temp = head;
    // do {
    //     cout << temp->data << endl;
    //     temp = temp->next;
    // } while (temp != nullptr);

    int test = 10;
    plusOne(&test);
    cout << test << endl;


    
    return 0;
}