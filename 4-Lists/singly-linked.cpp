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

};

int main()
{
    SinglyLinkedList<int> l1;

    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_front(0);

    for(auto itr = l1.begin(); itr != l1.end(); itr++) {
        std::cout << *itr << std::endl;
    }
}