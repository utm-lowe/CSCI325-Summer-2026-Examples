#include <iostream>
#include <vector> 
#include <exception>
#include <algorithm>
#include <iterator>

template <typename T>
void printVector(std::vector<T> &v) {
    std::ostream_iterator<T> out(std::cout, ", ");
    std::cout << "{";
    std::copy(v.begin(), v.end()-1, out);
    std::cout << v.back() << "}" << std::endl;
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