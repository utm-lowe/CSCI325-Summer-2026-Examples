#include <iostream>
#include <list>
#include <vector>
#include <deque>

int main()
{
    std::vector<int> v;
    std::list<int> l;
    std::deque<int> d;

    std::cout << "Iteration\tVector\t\tList\t\tDeque\t\t" << std::endl;

    for(int i=0; i<20; i++) {
        v.push_back(i);
        l.push_back(i);
        d.push_back(i);

        std::cout << i+1 << "\t\t"
                  << &(v.front()) << "\t"
                  << &(l.front()) << "\t"
                  << &(d.front()) << std::endl;
    }
}