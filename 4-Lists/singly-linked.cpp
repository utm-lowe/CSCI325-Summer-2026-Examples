#include <iostream>


template <typename T>
class SinglyLinkedList 
{
private:
    struct Node {
        T data;
        Node *next;

        Node() {
            data = T();
            next = nullptr;
        }

        Node(const T& data) {
            this->data = data;
            next = nullptr;
        }
    };

    Node *head; // first node in the list
    Node *tail; // last node in the list

public:
    SinglyLinkedList() 
    {
        head = nullptr;
        tail = nullptr;
    }

    ~SinglyLinkedList()
    {
        Node *cur = head;

        while(cur) {
            Node *next = cur->next;
            delete cur;
            cur = next;
        }
    }

    void push_front(const T& data) 
    {
        // 1.) Construct a new node
        Node *node = new Node(data);

        // 2.) Put the node at the front of the list.
        node->next = head;
        head = node; 

        // handle insertion of the first node
        if(tail == nullptr) {
            tail =  head;
        }
    }

    void push_back(const T& data) 
    {
        // Special case if the list is empty
        if(head == nullptr) {
            push_front(data);
            return;
        }

        // build a new node and attach to the tail
        Node *node = new Node(data);
        node->next = tail->next; // <-- illustration only
        tail->next = node;
        tail = node;
    }

    T& front() 
    {
        return head->data;
    }

    T& back()
    {
        return tail->data;
    }

    bool empty()
    {
        return head == nullptr;
    }

    class iterator 
    {
    public:
        iterator()
        {
            node = nullptr;
        }

        // dereference operator
        T& operator*() 
        {
            return node->data;
        }

        // prefix increment operator
        iterator operator++() 
        {
            if(node != nullptr) {
                node = node->next;
            } 
            return *this;
        }

        // postfix increment operator
        iterator operator++(int) 
        {
            iterator result(node);

            if(node != nullptr) {
                node = node->next;
            }

            return result;
        }

        bool operator==(const iterator &rhs) 
        {
            return node == rhs.node;
        }

        bool operator!=(const iterator &rhs) 
        {
            return not (*this == rhs);
        }

        iterator& operator=(const iterator &rhs) 
        {
            node = rhs.node;
            return *this;
        }
    private:
        iterator(Node *node) {
            this->node = node;
        }
        Node *node;
        friend class SinglyLinkedList<T>;
    };

    // get an iterator the first node
    iterator begin() 
    {
        return iterator(head);
    }

    // get an iterator one past the last node
    iterator end()
    {
        return iterator(nullptr);
    }

    // insert after
    void insertAfter(iterator &itr, const T& data) 
    {
        //detect tail insertion
        if(itr.node == tail) {
            push_back(data);
            return;
        }

        Node *node = new Node(data);
        node->next = itr.node->next;
        itr.node->next = node;
    }

    // delete after
    void deleteAfter(iterator &itr) 
    {
        if(itr.node->next == nullptr) {
            return;
        }

        Node *node = itr.node->next;
        itr.node->next = node->next;
        delete node;
    }

    // remove the first element
    void pop_front()
    {
        Node *node = head;
        head = head->next;
        delete node;

        if(head == nullptr) {
            tail = nullptr;
        }
    }
};

template <typename T>
std::ostream &operator<<(std::ostream &os, SinglyLinkedList<T> &l);

template<typename T>
void sortedInsert(SinglyLinkedList<T> &l, const T& data);

int main()
{
    SinglyLinkedList<int> l1;

    std::cout << l1 << std::endl;

    l1.push_back(1);
    std::cout << l1 << std::endl;

    l1.push_back(2);
    std::cout << l1 << std::endl;

    l1.push_back(3);
    std::cout << l1 << std::endl;

    l1.push_front(0);
    std::cout << l1 << std::endl;

    auto itr=l1.begin();
    itr++;
    l1.insertAfter(itr, 33);
    std::cout << l1 << std::endl;

    itr++;
    l1.deleteAfter(itr);
    std::cout << l1 << std::endl;

    while(!l1.empty()) {
        l1.pop_front();
        std::cout << l1 << std::endl;
    }

    std::cout << "Sorted Insert" << std::endl;
    sortedInsert(l1, 20);
    std::cout << l1 << std::endl;
    sortedInsert(l1, 2);
    std::cout << l1 << std::endl;
    sortedInsert(l1, 30);
    std::cout << l1 << std::endl;
    sortedInsert(l1, 25);
    std::cout << l1 << std::endl;
    sortedInsert(l1, 12);
    std::cout << l1 << std::endl;
    sortedInsert(l1, 0);
    std::cout << l1 << std::endl;
    sortedInsert(l1, 200);
    std::cout << l1 << std::endl;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, SinglyLinkedList<T> &l)
{
    for(auto itr = l.begin(); itr != l.end(); itr++) {
        if(itr != l.begin()) {
            os << "->";
        }
        os << *itr;
    }

    return os;
}

template<typename T>
void sortedInsert(SinglyLinkedList<T> &l, const T& data)
{
    if(l.empty() || data < l.front()) {
        l.push_front(data);
        return;
    }

    //previous iterator and itr chase each other to find the slot
    auto pitr = l.begin();
    auto itr = l.begin();
    itr++;
    while(itr != l.end() and *itr <= data) {
        pitr = itr;
        itr++;
    }

    l.insertAfter(pitr, data);
}