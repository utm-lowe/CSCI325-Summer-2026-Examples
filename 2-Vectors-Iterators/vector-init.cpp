#include <iostream>
#include <vector>
#include <string>

template <typename T>
void printVector(std::vector<T> &v) {
    bool first=true;
    std::cout << "{";
    //foreach loop 
    //loop over any STL container (any iterator interface)
    for(T& o : v) {
        if(not first) {
            std::cout << ", ";
        } else {
            first = false;
        }
        std::cout << o;
    }
    std::cout << "}" << std::endl;
}


int main()
{
    std::vector<int> e;
    std::vector<int> five(5);
    std::vector<std::string> s(3);
    std::vector<int> answer(10, 42);
    std::vector<double> initD{1.5, 2.6, 3.7};

    std::cout << "e: ";
    printVector(e);

    std::cout << "five: ";
    printVector(five);

    std::cout << "s: ";
    printVector(s);

    std::cout << "answer: ";
    printVector(answer);

    std::cout << "initD: ";
    printVector(initD);
}