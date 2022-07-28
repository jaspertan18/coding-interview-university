template <class T>

class ListElement {
    public:
        ListElement (const T &value) : next(NULL), data(value) {}
        ~ListElement() {} // this is the destructor

        ListElement *getNext() const {return next;}
        const T& value() const {return data;}
        void setNext(ListElement *elem) {next = elem;}
        void setValue (const T &value) {data = value;}

    private:
        ListElement *next;
        T data;
};