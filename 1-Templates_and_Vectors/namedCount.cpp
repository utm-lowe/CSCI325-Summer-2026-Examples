/**
 * @file namedCount.cpp
 * @author Robert Lowe <rlowe8@utm.edu>
 * @brief Count using named values.
 * @version 0.1
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>
#include "namedValue.h"

int main()
{
    for(NamedValue<int> i{"Count",0}; i.value() < 10; i=i.value()+1) {
        std::cout << i << std::endl;
    }
}