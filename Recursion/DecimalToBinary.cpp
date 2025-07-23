#include <iostream>
#include <string>

using namespace std;

string toBinary(int decimal){
    if (decimal < 2)
    {
        return to_string(decimal);
    }

    return toBinary(decimal/2) + to_string(decimal%2);
}


int main(){
    int decimal = 0;
    cin >> decimal;
    cout << toBinary(decimal);
    return 0;
}