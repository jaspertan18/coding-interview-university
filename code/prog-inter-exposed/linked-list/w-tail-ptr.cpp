#include <iostream>

using namespace std;

template <class T>


class LinkedList {
    struct Node {
        Node *next;
        T node_data;
    };

    public:
        LinkedList() {
            head = nullptr;
            curr_size = 0;
        }

        ~LinkedList() {
            while (head != nullptr) {
                Node *temp = head;
                head = head->next;
                delete temp;
            }
        }


        int size() { return curr_size; }
        bool empty() { return (curr_size == 0); }
        void print_list() {
            Node *temp = head;

            while (temp != nullptr) {
                if (temp->next != nullptr)
                    cout << temp->node_data << "->";
                else
                    cout << temp->node_data << endl;
                temp = temp->next;
            }
        }
        T value_at(int index) {
            int count = 0;
            Node *temp = head;

            while (count++ != index) {
                if (temp->next != nullptr)
                    temp = temp->next;
                else {
                    cout << "Index out of bounds!" << endl;
                    break;
                }
            }

            return temp->node_data;
        }
        void push_front(T value) {
            Node *new_node = new Node;
            new_node->node_data = value;
            new_node->next = head;

            head = new_node;
            curr_size++;

        }
        T pop_front() {
            T return_elem;
            if (curr_size > 0) {
                return_elem = head->node_data;
                Node *temp = head;
                head = head->next;
                curr_size--;
                delete temp;
            }
            else 
                cout << "List is empty!" << endl;
            return return_elem;

        }
        void push_back(T value) {
            Node *new_node = new Node;
            new_node->node_data = value;
            new_node->next = nullptr;

            if (curr_size == 0)
                head = new_node;
            else {
                Node *temp = head;
                while (temp->next != nullptr)
                    temp = temp->next;
                temp->next = new_node;
            }

            curr_size++;
        }
        T pop_back() {
            T return_elem;
            if (curr_size == 1) {
                return_elem = head->node_data;
                head = nullptr;
                curr_size--;
            }
            else {
                Node *temp = head;
                while (temp->next->next != nullptr)
                    temp = temp->next;
                Node *remove = temp->next;
                return_elem = remove->node_data;
                temp->next = nullptr;
                delete remove;
                curr_size--;
            }
            return return_elem;
        }
        T front() {
            return head->node_data;
        }
        T back() {
            Node *temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            return temp->node_data;
        }
        void insert(int index, T value) {
            int count = 1;
            Node *temp = head;
            while (count++ != index)
                temp = temp->next;
            
            Node *new_node = new Node;
            new_node->node_data = value;
            new_node->next = temp->next;
            temp->next = new_node;
            
            curr_size++;
        }
        void erase(int index) {
            int count = 1;
            Node *temp = head;

            while (count++ != index)
                temp = temp->next;

            Node *remove = temp->next;
            temp->next = nullptr;
            delete remove;

            curr_size--; 
        }
        T value_n_from_end(int n) {
            int pos = curr_size - n;
            int count = 0;

            Node *temp = head;
            while (count++ != pos)
                temp = temp->next;
            
            return temp->node_data;
        }
        void reverse() {
            Node *temp = head;
            Node *new_head = nullptr;

            while (temp != nullptr) {
                temp = temp->next;
                head->next = new_head;
                new_head = head;
                head = temp;
            }
            head = new_head;
        }
        void remove_value(T value) {
            
            if (head->node_data == value) {
                Node *remove = head;
                head = head->next;
                delete remove;
            }

            else {
                Node *temp = head;

                while (temp->next->node_data != value)
                    temp = temp->next;
                
                Node *remove = temp->next;
                temp->next = remove->next;
                delete remove;
            }

            curr_size--;

        }

    private:
        Node *head;
        int curr_size;
};

int main() {
    LinkedList<int> list;
    list.push_back(7);
    list.push_back(5);
    list.push_back(3);
    list.push_back(1);
    list.push_back(10);
    list.push_back(9);

    list.print_list();
    list.reverse();
    list.print_list();
    list.remove_value(7);
    list.print_list();
    
    return 0;
}