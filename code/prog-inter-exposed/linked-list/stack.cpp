/**
 * Problem Statement
 * Implement a stack using either a linked list or a dynamic array.
 * 
 * Implementation
 * Stack - LIFO
*/

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

class Stack {
    public:
        Stack(string value) {
            cout << "C'tor invoked" << endl;
            head = nullptr;
            curr_size = 0;
            name = value;
        }

        ~Stack() {
            cout << "Removing " << name << endl;
            while (head != nullptr) {
                Node *remove = head;
                head = head->next;
                delete remove;
            }
        }

        // Stack(const Stack &s1) {
        //     cout << "Copy c'tor invoked" << endl;
        //     head = s1.getHead();
        //     curr_size = s1.size();
        //     name = "Stack 2";
        // }

        Node *getHead() const {
            return head;
        }

        string getName() const {
            return name;
        }

        void push(int value) {
            Node *temp = new Node;
            temp->data = value;
            temp->next = head;

            head = temp;
            curr_size++;
        }

        int pop() {
            Node *temp = head;
            int ans = 0;

            if (temp->next == nullptr) {
                ans = temp->data;
                delete temp;
            }

            else {
                while (temp->next->next != nullptr)
                    temp = temp->next;
                
                Node *remove = temp->next;
                temp->next = nullptr;
                ans = remove->data;
                delete remove;
            }
            
            curr_size--;
            return ans;
        }

        int size() const { return curr_size; }
        bool empty() { return (curr_size == 0); }

    private:
        Node *head;
        int curr_size;
        string name;
};

int main() {
    Stack s1("stack 1");
    // s1.push(1);
    // s1.push(3);
    Stack s2(s1);
    cout << s2.size() << endl;
    s2.push(3);
    cout << s2.size() << endl;
    return 0;
}