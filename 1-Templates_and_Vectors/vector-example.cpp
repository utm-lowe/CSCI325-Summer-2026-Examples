#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v = {2,4,6,8};
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (std::vector<int>::iterator it=v.begin(); it != v.end(); ++it)
    {
        std::cout << *it << " ";
    } // Output: 10 20 30
}
