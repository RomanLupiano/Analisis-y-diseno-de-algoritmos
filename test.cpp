#include <iostream>

int main() {
    int * ptr = new int;
    *ptr = 10;

    std::cout << ptr << std::endl;

    delete ptr;

    ptr = NULL;

    std::cout << ptr << std::endl;

    return 0;
}
