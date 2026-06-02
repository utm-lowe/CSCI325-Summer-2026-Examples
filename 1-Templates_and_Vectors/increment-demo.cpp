#include <iostream>

int main()
{
    int x=5;

    std::cout << "X before x++ " << x << std::endl;
    std::cout << "x++ " << x++ << std::endl;
    std::cout << "X after x++" << x << std::endl;

    std::cout << "X before ++x " << x << std::endl;
    std::cout << "++x " << ++x << std::endl;
    std::cout << "X after ++x" << x << std::endl;
}