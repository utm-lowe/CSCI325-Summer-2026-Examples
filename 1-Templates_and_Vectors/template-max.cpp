/**
 * @file template-max.cpp
 * @author Bob Lowe <rlowe8@utm.edu>
 * @brief A demonstration of templates
 * @version 0.1
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>
#include <string>

template <typename T>
T max(T a, T b) 
{
    if(a>b) {
        return a;
    } else {
        return b;
    }
}

int main() 
{
    std::cout << max(3, 7) << std::endl;        // int version
    std::cout << max(3.14, 2.71) << std::endl;  // double version
    std::cout << max<int>(3.14, 2.71) << std::endl;
}