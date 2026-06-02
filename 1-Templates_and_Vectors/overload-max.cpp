/**
 * @file overload-max.cpp
 * @author Bob Lowe 
 * @brief Demonstrating overloading for computing the maximum.
 * @version 0.1
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>

int max(int a, int b) 
{
    if(a > b) {
        return a;
    } else {
        return b;
    }
}

double max(double a, double b) 
{
    if(a > b) {
        return a;
    } else {
        return b;
    }
}


int main()
{
    std::cout << max(3, 7) << std::endl;        // int version
    std::cout << max(3.14, 2.71) << std::endl;  // double version
}