#include <iostream>

using namespace std;


int main(int argc, char * argv[])
{
    int n = 10;
    int * ptr = NULL;
    ptr = &n;
    *ptr = 20;

    cout << "ptr: " << ptr << " | *ptr: "<< *ptr << " | n: " << n <<  " | &n: " << &n << "\n";
    return 0;
}