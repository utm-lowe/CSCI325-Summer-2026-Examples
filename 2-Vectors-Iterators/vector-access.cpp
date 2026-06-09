#include <iostream>
#include <vector> 
#include <exception>

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
    std::vector<int> ar(5); // five element vector

    for(int i=0; i<=5; i++) {
        ar[i] = i;
    }
    printVector(ar);
    std::cout << "size: " << ar.size() << " capacity: " << ar.capacity() << std::endl;


    for(int i=0; i<=5; i++) {
        try {
            ar.at(i) = i;
        } catch(std::out_of_range &e) {
            std::cout << "Oops! Too far!" << std::endl;
        }
    }
    printVector(ar);
    std::cout << "size: " << ar.size() << " capacity: " << ar.capacity() << std::endl;
}