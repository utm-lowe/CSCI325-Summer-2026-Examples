#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;

    v.reserve(1000);
    std::cout << "size: " << v.size() << " capacity: " << v.capacity() << std::endl;
}