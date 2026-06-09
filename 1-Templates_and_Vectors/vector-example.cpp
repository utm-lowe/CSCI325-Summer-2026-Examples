#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v;
    
    for(int i=1; i<=100; i++) {
        v.push_back(i*10);
        std::cout << "Size: " << v.size() << " Capacity: " << v.capacity()
                  << std::endl;
        std::cout << "  Start Address: " << &v[0] << " End Address: " << &v[v.size()-1] << std::endl;
    }

    for (auto it=v.begin(); it != v.end(); ++it)
    {
        std::cout << *it << " ";
    } // Output: 10 20 30
    std::cout << std::endl;

    // reverse iterator
    for(auto it=v.rbegin(); it != v.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
