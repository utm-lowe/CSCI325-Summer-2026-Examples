#include <iostream>
#include <vector>

template <typename T>
class CircularDeque
{
public:
    CircularDeque() : q(10)
    {
        h=q.size()-1;
        t=0;
        count = 0;
    }

    T& front() 
    {
        return q[h];
    }

    T& back() 
    {
        return q[t];
    }

    void push_back(const T& item)
    {
        // make room 
        reserve(count+1);

        // move the tail back
        t--;
        if(t<0) {
            t += q.size();
        }

        //insert the item
        q[t] = item;
        count++;
    }

    void push_front(const T& item) 
    {
        //make room
        reserve(count+1);

        // move the head
        h = (h+1) % q.size();

        // insert the item
        q[h] = item;

        // update count
        count++;
    }

    void pop_back()
    {
        // move the tail
        t = (t+1) % q.size();

        //update the count
        count--;
    }

    void pop_front()
    {
        // move head back
        h--;
        if(h<0) {
            h+= q.size();
        }

        count--;
    }


    int size() 
    {
        return count;
    }

    bool empty()
    {
        return count == 0;
    }

    T& operator[](int index) 
    {
        return q[(h-index) % q.size()];
    }

    void reserve(int n)
    {
        //TODO: Try to use the [] operator to simplify this operation

        // we have enough room
        if(n <= q.size()) {
            return;
        }

        // preserve the old queue
        std::vector<T> oq(q);
        int oh=h;
        int ot=t;

        // make a bigger queue
        std::vector<T> nq(q.size()*2);

        // reset our container
        q=nq;
        h=q.size()-1;
        t=0;
        count = 0;

        // rebuild the queue
        int i;
        for(i=ot; i!=oh; i=(i+1)%oq.size())
        {
            push_front(oq[i]);
        }
        push_front(oq[i]);
    }
private:
    int h; // head
    int t; // tail
    int count; // number of items in the queue
    std::vector<T> q; // physical queue
};

void buildQueue(CircularDeque<int> &de, int n);
void consumeQueue(CircularDeque<int> &de);
void buildQueueBW(CircularDeque<int> &de, int n);
void consumeQueueBW(CircularDeque<int> &de);

int main()
{
    CircularDeque<int> de;

    std::cout << "Forward" << std::endl;

    buildQueue(de, 5);
    consumeQueue(de);

    buildQueue(de, 5);
    consumeQueue(de);

    buildQueue(de, 5);
    consumeQueue(de);

    buildQueue(de, 10);
    consumeQueue(de);

    buildQueue(de, 20);
    consumeQueue(de);

    buildQueue(de, 200);
    consumeQueue(de);

    std::cout << "Backwards" << std::endl;

    buildQueueBW(de, 5);
    consumeQueueBW(de);

    buildQueueBW(de, 5);
    consumeQueueBW(de);

    buildQueueBW(de, 5);
    consumeQueueBW(de);

    buildQueueBW(de, 10);
    consumeQueueBW(de);

    buildQueueBW(de, 20);
    consumeQueueBW(de);

    buildQueueBW(de, 200);
    consumeQueueBW(de);

    std::cout << "Vector Like Test" << std::endl;
    for(int i=0; i<10; i++) {
        de.push_back(i);
    }

    for(int i=0; i<de.size(); i++) {
        std::cout << de[i] << " ";
    }
    std::cout << std::endl;
}

void buildQueue(CircularDeque<int> &de, int n)
{
    static int item=10;
    for(int i=0; i<n; i++,item+=10) {
        de.push_front(item);
    }
    std::cout << "Enqueued " << n << " items." << std::endl;
}


void consumeQueue(CircularDeque<int> &de)
{
    while(!de.empty()) {
        std::cout << de.back() << " ";
        de.pop_back();
    }
    std::cout << std::endl;
}

void buildQueueBW(CircularDeque<int> &de, int n)
{
    static int item=10;
    for(int i=0; i<n; i++,item+=10) {
        de.push_back(item);
    }
    std::cout << "Enqueued " << n << " items." << std::endl;
}


void consumeQueueBW(CircularDeque<int> &de)
{
    while(!de.empty()) {
        std::cout << de.front() << " ";
        de.pop_front();
    }
    std::cout << std::endl;
}