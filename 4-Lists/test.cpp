/**
 * @file test.cpp
 * @author Bob Lowe <rlowe8@utm.edu>
 * @brief A little test program to time various vector and list operations
 * @version 0.1
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "timingFixture.hpp"
#include <chrono>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <random>
#include <ctime>
#include <string>
#include <iterator>

// A few global variables (It's ok. Trust me, I have a PhD)
unsigned int n;
std::mt19937 mt(static_cast<unsigned int>(time(nullptr)));

// function prototypes
template<typename T> void randomPushBack(T& container);
template<typename T> void randomPushFront(T& container);
template<typename T> void randomAccess(T& container);
template<typename T> void containerTest(const std::string& name);


int main(int argc, char **argv)
{
    if(argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <n>" << std::endl;
        return -1;
    }
    n = std::stoi(argv[1]);

    containerTest<std::vector<int>>("Vector");
    containerTest<std::list<int>>("List");

    return 0;
}


/**
 * @brief Insert n elements at the end of the list.
 * 
 * @tparam T 
 * @param container 
 */
template<typename T> 
void randomPushBack(T& container)
{
    std::uniform_int_distribution<int> dist(0, n*10);
    for(int i=0; i<n; i++) {
        container.push_back(dist(mt));
    }
}


/**
 * @brief Insert n elements at the front of the list.
 * 
 * @tparam T 
 * @param container 
 */
template<typename T> void randomPushFront(T& container)
{
    std::uniform_int_distribution<int> dist(0, n*10);
    for(int i=0; i<n; i++) {
        container.insert(container.begin(), dist(mt));
    }
}


/**
 * @brief Access n random elements in the container.
 * 
 * @tparam T 
 * @param container 
 */
template<typename T> void randomAccess(T& container)
{
    std::uniform_int_distribution<int> dist(0, container.size()-1);
    for(int i=0; i<n; i++) {
        auto it = container.begin();
        std::advance(it, dist(mt));
        int x = *it;
    }
}


/**
 * @brief Run the container timing tests for inserting at either end.
 * 
 * @tparam T 
 * @param name 
 */
template<typename T> void containerTest(const std::string& name)
{
    T container;


    auto pushTimer = makeTimingFixture<std::chrono::nanoseconds>(randomPushBack<T>, container);
    auto insertTimer = makeTimingFixture<std::chrono::nanoseconds>(randomPushFront<T>, container);

    std::cout << name << " push_back time: " << pushTimer.average(10) << std::endl;
    std::cout << name << " Insert at front time: " << insertTimer.average(10) << std::endl;

    // populate the container for access testing
    randomPushBack<T>(container);
    auto accessTimer = makeTimingFixture<std::chrono::nanoseconds>(randomAccess<T>, container);
    std::cout << name << " Random access time: " << accessTimer.average(10) << std::endl;
}