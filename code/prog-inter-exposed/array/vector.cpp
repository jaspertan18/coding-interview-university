#include <iostream>

using namespace std;

template <class T>

class Vector {
    public:
        Vector(int capacity) {
            curr_size = 0;
            curr_capacity = capacity;
            arr = new T[capacity];
        }
        ~Vector() {
            delete [] arr;
        }

        int size() { return curr_size; }
        int capacity() { return curr_capacity; }
        bool is_empty() {return curr_size == 0; }
        T at(int index) { return arr[index]; }

        void push(T item) {
            if (curr_size == curr_capacity)
                resize(curr_capacity * 2);
            arr[curr_size] = item;
            curr_size++;
        }

        void print() {
            for (int i = 0; i < curr_size; i++)
                cout << arr[i] << " ";
            cout << endl;
        }

        void insert(int index, T item) {
            if (curr_size == curr_capacity)
                resize(curr_capacity * 2);
            
            T *temp_arr = new T[curr_capacity];

            for (int i = 0; i < index; i++)
                temp_arr[i] = arr[i];
            
            temp_arr[index] = item;
            curr_size++;

            for (int i = index; i < curr_capacity; i++)
                temp_arr[i + 1] = arr[i];

            for (int i = 0; i < curr_capacity; i++)
                arr[i] = temp_arr[i];
            
            delete [] temp_arr;
        }

        void prepend(T item) {
            if (curr_size == curr_capacity)
                resize(curr_capacity * 2);
            
            T *temp_arr = new T[curr_capacity];
            temp_arr[0] = item;
            curr_size++;

            for (int i = 0; i < curr_capacity; i++)
                temp_arr[i + 1] = arr[i];
            
            for (int i = 0; i < curr_capacity; i++)
                arr[i] = temp_arr[i];
            
            delete [] temp_arr;
        }

        T pop() {
            T return_elem;
            try {
                if (curr_size == 0)
                    throw out_of_range("Size is zero now!");
                T *temp_arr = new T[curr_size - 1];
                for (int i = 0; i < curr_size - 1; i++)
                    temp_arr[i] = arr[i];

                T return_elem = arr[curr_size - 1];

                for (int i = 0; i < curr_capacity; i++)
                    arr[i] = temp_arr[i];
                
                curr_size--;
                if (curr_size == curr_capacity / 4)
                    resize(curr_capacity / 4);

                delete [] temp_arr;
            }
            catch (out_of_range& e) {
                cerr << e.what();
            }
            return return_elem;
        }

        void removeIndex(int index) {
            try {
                if (index > curr_size)
                    throw out_of_range("Index out of range!");
                T *temp_arr = new T[curr_size - 1];

                for (int i = 0; i < index; i++)
                    temp_arr[i] = arr[i];
                
                for (int i = index; i < curr_capacity; i++)
                    temp_arr[i] = arr[i + 1];
                
                for (int i = 0; i < curr_capacity; i++)
                    arr[i] = temp_arr[i];
                
                curr_size--;
                if (curr_size % 2 == 0 && curr_size == curr_capacity / 2)
                    resize(curr_capacity / 2);

                delete [] temp_arr;
            }
            catch (out_of_range &e) {
                cerr << e.what();
            }
        }
        
        void removeAllItems(T item) {
            try {
                int count = 0;
                T *temp_arr = new T[curr_capacity];

                for (int i = 0; i < curr_size; i++) {
                    if (arr[i] != item)
                        temp_arr[count++] = arr[i];
                }
                
                arr = temp_arr;
                curr_size = count;
                

                delete [] temp_arr;
            }
            catch (out_of_range& e) {
                cerr << e.what();
            }
            
        }
        
        int find(T item) {
            for (int i = 0; i < curr_size; i++) {
                if (arr[i] == item)
                    return i;
            }
            return -1; 
        }


    private:
        int curr_size;
        int curr_capacity;
        T *arr;

        void resize(int new_capacity) {
            T *new_arr = new int[new_capacity];

            for (int i = 0; i < curr_capacity; i++)
                new_arr[i] = arr[i];
            
            arr = new int[new_capacity];
            for (int i = 0; i < new_capacity; i++)
                arr[i] = new_arr[i];
            
            curr_capacity = new_capacity;

            delete [] new_arr;
        }
};

int main() {
    Vector<int> vec1(2);
    vec1.push(1);
    vec1.push(2);
    vec1.prepend(3);
    vec1.insert(2, 6);
    vec1.prepend(9);
    vec1.print();
    cout << vec1.find(6) << endl;

    return 0;
}